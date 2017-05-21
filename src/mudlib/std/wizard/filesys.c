/**
 * SIMAURIA '/std/player/filesys.c'
 */

//----------------------------------------------------------------------------

#include <config.h>
#include <wizlevels.h>
#include <colours.h>
#include <search.h>
#include <properties.h>
#include <daemons.h>
#include <prompt.h>
#include <sounds.h>
//----------------------------------------------------------------------------

#define TP_NAME     TP->QueryName()
#define TP_RNAME    TP->QueryRealName()
#define TP_INVIS    TP->QueryInvis()

#define USAGE(cond,txt) if (cond) { return notify_fail(txt); }
#define SECURE(val)     if (!TP || TP != TO) return(val);
#define SECURE3(val)    if (!TP || TP != TO ||!check_previous()) return(val);
#define SECURE2(val) \
  if (!TP || TP != TO || TI != TO || !check_previous()) return(val);

#define NAME  0
#define PATH  1
#define BASE  2
#define SIZE  3
#define PSIZE 4
#define BSIZE 5

#define FILE_NA   -1
#define FILE_DIR  -2
#define FILE_WILD -3

//----------------------------------------------------------------------------

public varargs mixed Query(string str); // std/base

varargs int more(string fname, int quiet, int chunk);
varargs int type(string cmd, string fname, int chunk);
int ls(string cmd, string fname);
string cd(string newpath);
varargs string is_file(mixed thing, string suffix);
string is_dir(string name);
varargs string get_path(string fname, int noaliases, mixed usr);

static string exp_fname(string fname);

#undef F_ALIAS

//----------------------------------------------------------------------------
#ifdef F_ALIAS
private mapping faliases = ([]);
#endif

private nosave string currentdir = "/";
private nosave string *path =({});		   /* El path donde buscar los comandos */
private nosave string *sfile =({});
private nosave string acmd;
private nosave mixed *srcd =({});
private nosave mixed *dstd =({});
private nosave int adone;
private nosave int atodo;

//----------------------------------------------------------------------------

public string SetCurrentDir(string path) { return currentdir = path; }
public string QueryCurrentDir()          { return currentdir; }

public string *SetPath(string *p) {
//   if (((string) PO) != BIND) return(0);
   return path = pointerp(p) ? filter(p, SF(stringp)) :({});
}

public string *QueryPath() { return path; }

public string *AddPath(string str) {
    if (!str) return QueryPath();
    if (member(path, str)==-1) path +=({ str });
    return QueryPath();
}

public string *RemovePath(string str) {
    if (!str) return QueryPath();
    if (member(path, str)!=-1) path -=({ str });
    return QueryPath();
}

#ifdef F_ALIAS
public mapping SetFAliases(mapping m) { return faliases=mappingp(m)?m:([]); }
public mapping QueryFAliases()        { return faliases; }
#endif

static int check_previous() {
    int i;
    object o;
    for (i = 0; o = previous_object(i); i++) if (o != TO) return 0;
    return 1;
}

/*----------------------------------------------------------
 * [Woo] Nueva funcion que sustituye al cat implementado
 *       dentro del driver. Devuelve exactamente lo mismo
 *       que cat pero teniendo en cuenta los tty del jugador
 *       imprime los colores, en bold o sin colores.
 *----------------------------------------------------------*/
// [Nyh] Cuando implementemos el uso de terminal_colours sera innecesaria

public int wcat(string path, int start, int number) {
    string texto;
    int i, j;

    if (TP->QueryTTY()=="ansi") return cat(path, start, number);

    if (TP->QueryTTY()=="dumb" || TP->QueryTTY()=="vt100") {
        j=0;
        for (i = start; i < start+number; i++) {
            if (!texto = read_file(path, i, 1))
                return j; // Si es 0 es que start ha sido mal dado.
            else {
                j++;
                write(texto);
            }
        }
     return j; // Devuelve el numero de lineas leidas satisfactoriamente.
    }

    return cat(path,start,number);
}

static void add_filesys_commands() {
    SECURE(0);
    if (IS_LEARNER(TO)) {
        add_action("fman",    "man");
        add_action("fmore",   "more");
        add_action("ftype",   "type");
        add_action("ftype",   "cat");
        add_action("ftype",   "tail");
        add_action("fls",     "ls");
        add_action("fls",     "lls");
        add_action("fls",     "fchk");
        add_action("fpwd",    "pwd");
        add_action("fcd",     "cd");
#ifdef F_ALIAS
        add_action("falias",  "falias");
#endif
        cd(0);
    }
}

public int fmore(string str) {
    USAGE(!str || str == "?", "more <fichero>\n  Visualiza el fichero <fichero> por páginas.\n");
    more(str, Query(P_INVIS), TO->QueryPageSize());
    return 1;
}

public int ftype(string str) {
    if (!str || str == "?") {
        switch (query_verb()) {
            case "cat":
                return notify_fail("cat <fichero>\n"
                            "  Visualiza la cabecera del fichero <fichero>.\n");
                break;
            case "tail":
                return notify_fail("tail <fichero>\n"
                            "  Visualiza el final del fichero <fichero>.\n");
                break;
            default:
                return notify_fail("type <fichero>\n"
                            "  Visualiza el fichero <fichero>.\n");
        }
    }

    return type(query_verb(), str, TO->QueryPageSize());
}

#define MANDIRS ({ "driver", "efun", "lfun", "obj", "misc", \
                   "sefun", "std", "conceptos", "master", "estandares"})
#define DOCDIR  "/doc/wizards/LPC/"

public int fman(string str) {
  string *found, *mandirs = MANDIRS;
  string docdir = DOCDIR, failstr, manfile, alt;
  int success = 0, i;

  if (!str || str == "?") {
   printf("manual <tema>\nLos principales temas son:\n");
   printf("%-78#s\n", implode(mandirs, "\n"));
   return 1;
  }

  if ((i = member(mandirs, str)) > -1) {
    write("----- Contenido del directorio: "+docdir+mandirs[i]+" -----\n");
    ls("ls", docdir+str);
    return 1;
  }

  alt = lower_case(str);
  if (alt[0..1] == "p_")
    alt = alt[2..];
  while(-1 !=(i = strstr(alt, "/p_")))
    alt = alt[0..i]+alt[i+3..];
  while(-1 !=(i = member(alt, '_')))
    alt = alt[0..i-1]+alt[i+1..];

  found =({});
  mandirs =({ "" }) + mandirs;
  for (i = 0; i < sizeof(mandirs); i++) {
    manfile = docdir+mandirs[i]+"/"+str;
    if (   file_size(manfile) > 0
        || file_size(manfile+".doc") > 0
       )
      found += mandirs[i..i];
    if (str != alt)
    {
      manfile = docdir+mandirs[i]+"/"+alt;
      if (   file_size(manfile) > 0
          || file_size(manfile+".doc") > 0
         )
        found += mandirs[i..i];
    }
  }
  if (!sizeof(found)) {
    notify_fail("No existe documentación sobre: "+str+".\n");
    return 0;
  }
  if (sizeof(found) > 1)
    write("Encontrados "+sizeof(found)+" documentos: "+implode(found, "/, ")+"/.\n\n");

  manfile = docdir+found[0]+"/"+str;
  if (file_size(manfile) > 0)
    more(manfile);
  else if (file_size(manfile+".doc") > 0)
    more(manfile+".doc");
  else if (str != alt)
  {
    manfile = docdir+found[0]+"/"+alt;
    if (file_size(manfile) > 0)
      more(manfile);
    else if (file_size(manfile+".doc") > 0)
      more(manfile+".doc");
  }

  return 1;
}

public int fls(string str) {
    if (str == "?") {
        switch (query_verb()) {
            case "lls":
                notify_fail( "lls [<fich-dir]\n  Visualiza más informacion "
                    "sobre <fich-dir>(o directorio actual).\n"
                    "  Se permiten comodines como '*'.\n"
                );
                break;
            case "fchk":
                notify_fail( "fchk [<fdir>]\n  Visualiza tamaño y tipo de "
                    "<fich-dir>(o directorio actual).\n  Se permiten "
                    "comodines, entonces fchk funcionaría igual que lls.\n"
                );
                break;
            default:
                notify_fail( "ls [<fich-dir>]\n  Visualiza información sobre "
                    "<fich-dir>(o el directorio actual).\n"
                    "  Los directorios aparecen con un '/' al final del "
                    "nombre.\n  Se permiten comodines como '*'.\n"
                );
        }
        return 0;
    }

    ls(query_verb(), str);
    return 1;
}

#ifdef F_ALIAS
public int falias(string arg) {
  string alias, xp;

  USAGE(arg == "?",
 "falias <alias> <fichero>\n"
 "  Establece <alias> como el alias del fichero <fichero> de tal forma que\n"
 "  si 'npc' fuera el alias de '/std/npc', 'more npc' visualizaria '/std/npc'.\n"
 "falias <alias>\n"
 "  Borra el alias de fichero <alias>.\n"
 "falias\n"
 "  Visualizaria todos los alias de fichero existentes.\n"
        );

    if (arg && sscanf(arg, "%s %s", alias, xp) == 2) {
        USAGE( sizeof(explode(alias, "/")) != 1,
               "El alias '"+alias+"' no es válido.\n");
        USAGE( sizeof(explode(xp, " ")) != 1,
               "El fichero del alias '"+xp+"' no es válido.\n");
        m_add(faliases, alias, xp = exp_fname(xp));
        write("Establecido el alias '"+alias+"' como '"+xp+"'.\n");
    }
    else if (arg) {
        if (!faliases[arg]) write("No existe ese alias de fichero.\n");
        else {
            m_delete(faliases, arg);
            write("'"+arg+"' borrado.\n");
        }
    }
    else {
        string *idx = m_indices(faliases);
        int i = sizeof(idx);
        write("Existen "+i+" alias.\n");
        for (; i--; ) {
            write(" '"+STR->ladjust(""+idx[i]+"'", 15)+" ="
                  " '"+faliases[idx[i]]+"'\n");
        }
    }
    return 1;
}
#endif

public int fpwd() {
    write(QueryCurrentDir() + "\n");
    return 1;
}

public int fcd(string str) {
    string name, olddir;

    USAGE(str == "?",
        "cd <nuevo_dir>\n  Cambia el directorio actual por <nuevo_dir>.\n"
        "cd @\n  Cambia el directorio actual por el directorio que contiene\n"
        "  la habitacion donde nos encontramos.\n"
         );
    olddir = QueryCurrentDir();
    name = cd(str);
    if (name != olddir && file_size(name+"/.leeme") > 0) cat(name+"/.leeme");
    if (name != olddir) play_sound(TP, SND_SUCESOS("cambiar_dir"));
    return 1;
}

string stime(int date) {
  string cdate, rc;
  cdate = ctime(date);
  rc = cdate[8..9]+"-"+cdate[4..6]+"-"+cdate[20..23]+" "+cdate[11..18];
  return rc;
}

static string exp_fname(string fname) {
#ifdef F_ALIAS
//    dtell("nyh",sprintf("%O->exp_fname(%O)\nfaliases = %O\n",TO, fname, faliases));
    if (!fname || !strlen(fname)) return fname;
    return implode(filter(explode(fname, "/"),(: faliases[$1]||$1 :) ),"/");
#else
    return fname;
#endif
}

varargs string basepath(string fname, int what) {
  int i;
  for (i = strlen(fname); i--;) {
    if (fname[i] == '/') {
      if (!what) return fname[..i];
      else return fname[(i+1)..];
    }
  }
  if (!what) return "/";
  else return "";
}


varargs mixed *parse_fname(string src, object pl) {
  mixed *ret;
  string foo, bar;
  int size;
  if (!pl) pl = TP;
  ret = allocate(6);
  src =(string) pl->get_path(src, 0, pl);
  if (sscanf(src, "%s*%s", foo, bar)) {
    ret[PATH] = basepath(src, 0);
    ret[BASE] = basepath(src, 1);
    ret[NAME] = src;
    if (sscanf(ret[PATH], "%s*%s", foo, bar)) size = FILE_NA;
    else size = file_size(ret[PATH]);
    ret[PSIZE] = size;
    ret[SIZE] =(size != FILE_NA) ? FILE_WILD : FILE_NA;
  }
  else {
    size = file_size(src);
    if (size >= 0) {
      ret[NAME] = src;
      ret[PATH] = basepath(src, 0);
      ret[BASE] = basepath(src, 1);
      ret[PSIZE] = FILE_DIR;
      ret[BSIZE] = size;
      ret[SIZE] = size;
    }
    else {
      if (size == FILE_DIR) ret[PATH] = src+(src!="/" ? "/" : "");
      else ret[PATH] = src;
      ret[BASE] = "";
      ret[NAME] = ret[PATH];
      ret[PSIZE] = size;
      ret[SIZE] = size;
    }
  }
  return ret;
}


varargs string *get_flist(mixed *fdsc, int mode) {
  string *flist;
  string dir, pat;
  int i, msk;
  if (fdsc[SIZE] == FILE_NA) return 0;
  if (fdsc[SIZE] >= 0) return({ fdsc[BASE] });
  dir = fdsc[PATH]; pat = fdsc[BASE];
  if (!mode) mode = 1;
  if (fdsc[SIZE] == FILE_DIR) { /* Make sure, that complete dir is listed */
    dir = fdsc[PATH]; pat = "*";
    while(  (flist =(mode<0?get_dir_ext(dir+pat):get_dir(dir+pat,mode)))
           && sizeof(flist) == 1 && flist[0] == pat
          )
      pat += "*";
  } else flist =(mode < 0 ? get_dir_ext(dir+pat) : get_dir(dir+pat,mode));
  if (!flist) flist =({ });
  if (mode > 0) {
     msk = !!(mode & 1) + !!(mode & 2) + !!(mode & 4) + !!(mode & 8);
     if (msk != 1) {
       if (i =(sizeof(flist) % msk))
	 flist = flist[0..sizeof(flist)-(1+i)];
     }
     else if (!flist[sizeof(flist)-1])
       flist = flist[0..sizeof(flist)-2];
  }
  return flist;
}


varargs string f_name(mixed arg, int pointc) {
  string name, foo, bar;
  if (objectp(arg)) name = object_name(arg); else name = arg;
  if (sscanf(name, "%s#%s", foo, bar)) return name = foo;
  if (pointc && !sscanf(name, "%s.c", foo)) name += ".c";
  return name;
}

varargs string get_path(string fname, int noaliases, mixed usr) {
  string name;
  if (intp(usr)) {
    if (!usr) name = (string) TP_RNAME;
    else name = 0;
  }
  else if (stringp(usr)) name = usr;
  else if (objectp(usr)) name = (string) usr->QueryRealName();
  else name = 0;
  if (!noaliases) fname = exp_fname(fname);
  return (string) MASTER->make_path_absolute(fname, name);
}


varargs string is_file(mixed thing, string suffix) {
  string newpath;

  if (objectp(thing)) newpath = f_name(thing, 0);
  else newpath = exp_fname(thing);
  if (!suffix) suffix = "";
  if (newpath != "" && file_size(newpath+suffix) < 0)  return 0;
  return get_path(newpath, 1);
}

string is_dir(string name) {
  string newpath;

  newpath = exp_fname(name);
  if (newpath != "" && file_size(newpath) != -2)  return 0;
  return get_path(newpath, 1);
}

static string more_file;
static int more_line;
static object more_pl;
static int more_chunk;
static int mquiet;
static string more_regexp;

static more_prompt(int m_line, int m_chunk) {
  write("=== Listado: Lineas "+m_line+".."+(m_line+m_chunk-1)
       +" [ENTER / i,a,p,u,e,s,/<cadena>,<linea>. Escribe ? para ayuda] ");
}

varargs int more(string fname, int quiet, int chunk) {
  int nline;
  if (!chunk) chunk = TO->QueryPageSize();
  if (!fname) fname = ".";
  fname = get_path(fname, 0, TP);
  if (file_size(fname) < 0) {
    write("No existe el fichero "+fname+".\n"); return 0;
  }
  if (IS_LEARNER(TP))
    write("--- "+fname+"("+file_size(fname)+" Bytes) ---\n");
  if (!read_file(fname, chunk+1, 1)) { /* Short files may be cat'ed */
    wcat(fname, 1, chunk);
    return 1;
  }
  mquiet = quiet;
  more_regexp = 0;
  more_pl = TP;
  more_file = fname; more_line = 1; more_chunk = chunk;
  if ((nline = wcat(more_file, more_line, more_chunk)) == 0) {
    write("¡No existe ese fichero!\n");
    return 0;
  }
  if (!quiet)
    if (!(TP_INVIS))
    {
      say(TP_NAME+" contempla una realidad muy diferente.\n");
      play_sound(environment(), SND_SUCESOS("ver_codigo"));
    }

  more_prompt(more_line, nline);
  input_to("even_more");
  return 1;
}

static even_more(str) {
  int nline, display;
  string foo;
  display = 0;
  if (str == "e") display = 1; /* do nothing but redisplay */
  else if (str == "" ||str == "i")
    more_line += more_chunk, display = 1;
  else if (str == "s") { write("== Ok.\n"); return; }
  else if (str == "a")
    more_line -= more_chunk, display = 1;
  else if (str == "p")
    more_line = 1, display = 1;
  else if (str == "u") {
    write("..espera..\n"); skip_to_end_of_more(); return;
  }
  else if (str[0] == '/') {
    if (strlen(str) < 2 && strlen(more_regexp || "") < 1)
      write("No se realizó ninguna búsqueda anteriormente.\n");
    else
    {
      if (strlen(str) > 1)
        more_regexp = str[2..];
      if (!regexp(({"dummy"}), more_regexp)) {
         write("*** Expresión incorrecta.\n");
        more_regexp = 0;
      }
      else {
        nline = more_line+more_chunk;
        write("..buscando cadena..\n");
        while(  (foo = read_file(more_file, nline++, 1))
               && !sizeof(regexp(({foo}), more_regexp)));
        if (foo) {
          more_line = nline-1;
          display=1;
        }
        else
          write("*** Cadena no encontrada.\n");
      }
    }
  }
  else if (str == "?")
    write( "Comandos permitidos:\n"
          + "  ENTER/ i  : página siguiente,\n"
          + "  a         : página anterior.\n"
          + "  p         : ir a la primera página.\n"
          + "  u         : ir a la ultima página.\n"
          + "  <linea>   : ir a la línea <línea>.\n"
          + "  /<cadena> : avanza hasta encontrar la cadena <cadena>.\n"
          + "  /         : repite la ultima busqueda.\n"
          + "  e         : reescribe la pagina actual.\n"
          + "  ?         : visualiza esta ayuda.\n"
          + "  s         : sale del listado.\n"
          + "El tamaño de página es de "+more_chunk+" líneas.\n"
          );
  else if (sscanf(str, "%d", nline) == 1) more_line = nline, display = 1;
  if (more_line < 1) more_line = 1;
  if (display &&(nline = wcat(more_file, more_line, more_chunk)) == 0) {
    more_file = 0;
    write("=== Fin del texto\n");
    if (!mquiet)
    if (!(TP_INVIS))
      say(more_pl->QueryName()+" vuelve a mirar en esta realidad.\n");
    return;
  }
  more_prompt(more_line, nline);
  input_to("even_more");
  return;
}


skip_to_end_of_more() {
  string foo;
  int step, nline;

  step = 0;
  while((foo = read_file(more_file, more_line, more_chunk)) && foo != "") {
    more_line += more_chunk; step++;
    if (step >= 50) {
      tell_object(more_pl, ".. Línea "+more_line+" ..\n");
      call_out("skip_to_end_of_more", 0);
      return;
    }
  }
  more_line -= more_chunk;
  if (more_line < 1) more_line = 1;
  if ((nline = cat(more_file, more_line, more_chunk)) == 0) {
    more_file = 0;
    write("=== Fin del texto\n");
    if (!mquiet)
    if (!(TP_INVIS))
      say(more_pl->QueryName()+" vuelve a mirar en esta realidad.\n");
    return;
  }
  more_prompt(more_line, nline);
  input_to("even_more");
}

varargs int type(string cmd, string fname, int chunk) {
  int mline, rc;
  if (!chunk) chunk = TO->QueryPageSize();

  if (cmd != "cat" && cmd != "type" && cmd != "tail") {
    write("Parametro ilegal 'cmd "+cmd+"' para filesys::type().\n");
    return 0;
  }
  if (!fname) fname = ".";
  fname = get_path(fname, 0, TP);
  if (file_size(fname) < 0) {
    write("No existe el fichero "+fname+".\n"); return 0;
  }
  write("--- "+fname+"("+file_size(fname)+" Bytes) ---\n");

  switch (cmd) {
    case "type":
        mline = 2;
        if (!cat(fname, 1, 1)) { write("¡No existe ese fichero!\n"); return 0; }
        while(cat(fname, mline, chunk)) mline+=chunk;
        break;
    case "cat":
        if (!cat(fname)) { write("¡No existe ese fichero!\n"); return 0; }
        break;
    case "tail":
        if (!tail(fname)) { write("¡No existe ese fichero!\n"); return 0; }
        break;
  }

  return 1;
}

_do_ls_part();

int ls(string cmd, string fname) {
  int date, mode, i;

  if (cmd != "ls" && cmd != "lls" && cmd != "fchk") {
    write("Párametro ilegal cmd '"+cmd+"' para ls().\n");
    return 0;
  }

  if (!fname) fname = ".";
  acmd = cmd;
  srcd = parse_fname(fname, TP);

  if (srcd[SIZE] == FILE_NA) {
    write("Nombre ilegal '"+srcd[NAME]+"'\n");
    return 0;
  }

  if (srcd[SIZE] >= 0) {
    write(srcd[NAME]+" : "+srcd[SIZE]+" Bytes   ");
    if ((date = file_date(srcd[NAME])) >= 0)
      write(stime(date));
    else write("???");
    write("\n");
    return 1;
  }

  switch (cmd) {
    case "ls":   mode = -1; break;
    case "lls":  mode = 7; break;
    case "fchk": mode = 0; break;
  }
  sfile = get_flist(srcd, mode);

  if (srcd[SIZE] == FILE_DIR && acmd == "fchk") {
    write(srcd[NAME]+" : ");
    if (cmd != "lls") write(""+sizeof(sfile));
    else write(""+(sizeof(sfile)/3));
    write(" files   ");
    if ((date = file_date(srcd[NAME])) >= 0)
      write(stime(date));
    else write("???");
    write("\n");
    return 1;
  }

  if (acmd == "fchk") {
    sfile = get_flist(srcd, 7);
    acmd = "lls";
  }

  atodo = sizeof(sfile);
  if (!atodo) {
    if (srcd[SIZE] == FILE_WILD) write(srcd[NAME]+": Error.\n");
    else write("El directorio "+srcd[NAME]+" está vacío.\n");
    return 0;
  }

  adone = 0;
  _do_ls_part();
  return 1;
}

_do_ls_part() {
  string line, name, foo, text;
  int i, last, size, part, ix, ahalf, date;

  if (!adone) {
    if (acmd != "ls") tell_object(TP, "\n");
    tell_object(TP, "--- "+srcd[NAME]+"(");
    if (acmd != "lls") tell_object(TP, ""+sizeof(sfile));
    else tell_object(TP, ""+(sizeof(sfile)/3));
    if (srcd[SIZE] == FILE_WILD) tell_object(TP, "");
    else tell_object(TP, " entradas");
    tell_object(TP, ") ---\n");
  }

  text="";
  line = "";
  part = atodo - adone;
  ahalf =(atodo+1)/2;
  for (i = adone; i < adone+part; i++) {
    if (acmd == "ls") {
      name = sfile[i];
      last =(i%4==3);
      name=(name[strlen(name)-2..strlen(name)-1]==".c"?TC_GREEN+STR->ladjust(name[0..18], 19)+TC_NORMAL:
          (name[strlen(name)-1]==42?TC_BOLD+TC_GREEN+STR->ladjust(name[0..18], 19)+TC_NORMAL:
          (name[strlen(name)-1]==47?TC_CYAN+STR->ladjust(name[0..18], 19)+TC_NORMAL:
          (name[strlen(name)-2..strlen(name)-1]==".h"?TC_YELLOW+STR->ladjust(name[0..18], 19)
            +TC_NORMAL:STR->ladjust(name[0..18], 19)))))
           +(last?"\n":" ");

    }
    if (acmd == "lls") {
      last = 1;
      name = sfile[i];
      size = sfile[++i];
      if (size < 0) { foo = "       -"; name += "/"; }
      else foo = STR->radjust(size+"",8);
      if ((date = sfile[++i]) >= 0)
        foo = stime(date) + foo;
      else foo = "- "+foo;
      name = STR->radjust(foo,30)+" "+
          (name[strlen(name)-2..strlen(name)-1]==".c"?TC_GREEN+name+TC_NORMAL:
          (name[strlen(name)-1]==47?TC_CYAN+name+TC_NORMAL:
          (name[strlen(name)-2..strlen(name)-1]==".h"?TC_YELLOW+name+TC_NORMAL:name)))+"\n";
    }
    line += name;
    if (TP->QueryTTY()=="dumb" || TP->QueryTTY()=="vt100") {
     line=string_replace(line,TC_GREEN,"");
     line=string_replace(line,TC_YELLOW,"");
     line=string_replace(line,TC_CYAN,"");
     line=string_replace(line,TC_NORMAL,"");
    }
    if (last) { text+=line; line = ""; }
  }
  if (!last) text+=line+"\n";
  STR->smore(text, TO->QueryPageSize());
  adone += part;
}

string cd(string path) {
  string newpath;

  if (!path) path = "/";
  if (path == "@") {
    if (!environment()) {
      write("No estás en ningun lado.\n");
      return currentdir;
    }
    path = implode(explode(object_name(environment()), "/")[0..<2], "/");
  }
  if (path == "..") {
    newpath = implode(explode(currentdir, "/")[..<2], "/");
    if (!sizeof(newpath)) newpath = "/";
  }
  else newpath = is_dir(path = get_path(path));

  if (!newpath) {
    if (is_file(path)) write(path+": Es un fichero.\n");
    else write(path+": No existe ese directorio.\n");
  }
  else {
    write(newpath+"\n");
    currentdir = newpath;
  }

  if (IS_LEARNER(TO) && TO->QueryPrompt() == PR_WIZ_PROMPT) {
  	string blue, normal;
  	switch (TO->QueryTTY()) {
  		case "ansi":
  			blue = TC_BOLD + TC_BLUE;
  			normal = TC_NORMAL + TC_CNORMAL;
  			break;
  		case "vt100":
  			blue = TC_BOLD;
  			normal = TC_NORMAL;
  			break;
  		default:
  			blue = normal = "";
  	}
 	set_prompt(blue + currentdir + normal + "> ");
  }
  return currentdir;
}
