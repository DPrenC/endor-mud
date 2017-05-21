/* SIMAURIA '/secure/daemons/magicd.c'
   ===================================
   [k] Khelben@simauria
   [w] Woo@simauria
   [h] Nyh@Simauria

   20-10-98 [k] Creación de este archivo.
   04-04-99 [w] Reestructurado para el nuevo sistema de magia.
   06-04-99 [w] Añadido QueryFileSpell() que devuelve el fichero
                correspondiente a ese hechizo sin ".c"
                Pasadas las comprobaciones de si se puede realizar
                mágia o no en la habitación a "spellbase".
   07-04-99 [w] Eliminadas las partes que no vamos a usar y retocado
                el código para la nueva ubicación de los hechizos.
   12-04-99 [w] Quito la comprobación antigua de si tenias aprendido
                el hechizo ya que ahora está en spellbase.c
   17-08-99 [w] Generardb ahora es Generardb, realmente ya era,pero en
                algún lugar aún no se habia enterao.
   18-08-99 [w] Chup, chup.. ahora el info solo funciona en caso de que
                hayas memorizado el hechizo, en caso contrario no va.
                ¿Por qué? pues porque no tiene sentido que sepas como
                funciona y que hace un hechizo que no has visto nunca.
   07-09-99 [w] ¿Y por qué los wizs tenemos que tener restringida la info? :)
   22-06-03 [m] No dejo titere con cabeza. Modifico lo que me rota, como me rota
   		y porque me rota.
   ??-07-05 [h] Hago que deje de grabar la db como minimo hasta q retoque los
                permisos de escritura
*/

#include <properties.h>
#include <magicd.h>
#include <gremios.h>
#include <magia.h>
#include "/secure/daemons.h"
#include <wizlevels.h>

#define NO_SAVE_DB // Comentar para grabar la db en MAGICD_FILE

string log_last_save;			/* Ultima vez que se grabo un log */
int spell_db_last_load,espera;		/* Fecha de la ultima actualizacion de la bd */
mapping spell_db, escuela_db, guilds;	/* Base de datos de conjuros */
string *long_names, *short_names; 	/* Nombres largos y cortos de los conjuros */
static int primera = 1;			/* Primera vez que cargamos el magicd en memoria */


void md_log(string s) {
/* Este procedimiento graba mensajes en el fichero de logs del magicd
   Solo en el primer evento del dia escribira la fecha, de ahi la variable
   aux y el codigo del principio					    */

  string aux;

   aux=ctime()[4..9];
   if (!log_last_save || log_last_save != aux || !file_size(MAGICD_LOG_FILE)) {
     log_last_save = aux;
     write_file(MAGICD_LOG_FILE, sprintf("\n%s\n",ctime()));
   }
   write_file(MAGICD_LOG_FILE, s+"\n");
}

/****************************************************************************/

int md_report(string type, string s) {
/* Este procedimiento graba en un registro los feedback de los usuarios
   Utiliza el mismo fichero para todos los tipos de reports.                */

   write_file(MAGICD_REPORTS_FILE, sprintf("[%-4s] (%s) %-10s : %s\n",
                  type, ctime()[4..9], TP->Query(P_REALNAME), s));
   printf("Gracias por tu colaboración\n");
   return 1;
}

/****************************************************************************/

int md_build_spell_db() {
/* Esta funcion construye la base de datos de conjuros, donde almacenamos
   el nombre largo del conjuro, el nombre corto, y otros datos para calculos
   estadisticos
   Se pueden optimizar algunas cosas, simplificar codigo, etc.. pero no
   tengo muchas ganas, ni tiempo				           */

   string file, *path, current_path, *filelist, long, short;
   int ok,error,i,j,k;
   string escuela;

   ok=0;
   error=0;
   long_names = ({});
   short_names = ({});
   spell_db = ([]);
   guilds = ([]);
   escuela_db = ([]);
   //MAGICD_SAVER->create();
   // [w] Ahora solo busca en los directorios esenciales.
   path =  ({ MAGICD_SPELL_DIR + "general/" });
   path += ({ MAGICD_SPELL_DIR + "esencia/" });
   path += ({ MAGICD_SPELL_DIR + "canalizacion/" });
   path += ({ MAGICD_SPELL_DIR + "mentalismo/" });
   path += ({ MAGICD_SPELL_DIR + "abjuracion/" });
   path += ({ MAGICD_SPELL_DIR + "adivinacion/" });
   path += ({ MAGICD_SPELL_DIR + "transmutacion/" });
   path += ({ MAGICD_SPELL_DIR + "conjuracion/" });
   path += ({ MAGICD_SPELL_DIR + "encantamiento/" });
   path += ({ MAGICD_SPELL_DIR + "evocacion/" });
   path += ({ MAGICD_SPELL_DIR + "ilusion/" });
   path += ({ MAGICD_SPELL_DIR + "nigromancia/" });
   while (sizeof(path))
   { /* Cogemos el primer directorio para mirar */
       current_path = path[0];
       path -= ({ current_path });
       sscanf(current_path, MAGICD_SPELL_DIR"%s/", escuela);
       //if (find_object("maler")) tell_object(find_object("maler"),sprintf("escuela=%O, escuela_db=%O.\n",escuela,escuela_db));
       /* Obtenemos la lista de ficheros del directorio */
       // [Nyh] En teoría no es necesario remover cvs ni svn porque ya lo quita el get_dir
       // sobrecargado, pero bueno, no cuesta nada.
       if (filelist = get_dir(current_path+"*", 1)) filelist -= ({ ".", "..", "CVS", ".svn"});
       while (sizeof(filelist))
       { /* Cogemos el primer fichero */
            file = filelist[0];
            filelist -= ({ file });

            short = file[0..<3];	/* Nos quedamos solo con el nombre (sin el '.c' */
            file=current_path+file;
            long = lower_case(file->QuerySpellName());
            long_names+=({ long });
            short_names+=({ short });
            spell_db += ([ long : short ]);
            if(!escuela_db[escuela]) escuela_db[escuela]=({});
            if(member(escuela_db[escuela], long)==-1)
            escuela_db[escuela] += ({long});
            for(j=0;j<sizeof(GC_LEGALES);j++)
            {
                //if (find_object("maler")) tell_object(find_object("maler"),sprintf("lista de gremios=%O,j=%i.\n",file->QueryCastLevel(GC_LEGALES[j]),j));
                //if(!guilds[GC_LEGALES[j]]) guilds[GC_LEGALES[j]]=([]);
                if(file->QueryCastLevel(GC_LEGALES[j])!=100)
                {
	                if(!guilds[GC_LEGALES[j]]) guilds[GC_LEGALES[j]]=([]);
	                guilds[GC_LEGALES[j]]+=([file->QuerySpellName():file->QueryCastLevel(GC_LEGALES[j])]);
                }
            }
            ok++;
        }
    }

   spell_db_last_load = time();
#ifndef NO_SAVE_DB
   save_object(MAGICD_FILE);
#endif
   if (error) printf("  se produjeron %d errores\n",error);
         else printf("  no se produjeron errores\n");
   printf("Ok.\n");

   return 1;
}

/****************************************************************************/

void md_check_db() {
/* Comprueba el estado de la base de datos de conjuros */
    if (primera)
    {
        primera = 0;
#ifndef NO_SAVE_DB
        if (!restore_object(MAGICD_FILE) || !spell_db || !sizeof(spell_db) )
#else
        if (!spell_db || !sizeof(spell_db) )
#endif
        {
            printf("Generando BD\n");
            md_build_spell_db();
            spell_db_last_load = time();
#ifndef NO_SAVE_DB
            save_object(MAGICD_FILE);
#endif
            return;
        }
    }
}

/****************************************************************************/

int md_usage() {
/* Esta funcion muestra el mensaje de uso del comando 'magia'		    */
   printf("Uso: %s 'conjuro'\n", MAGICD_VERB);
   printf("Uso: %s <opcion> <argumentos>\n", MAGICD_VERB);
   printf("donde <opcion> puede ser:\n");
   printf(sprintf("   %-10s para obtener información de conjuros\n",MAGICD_INFOVERB));
   printf(sprintf("   %-10s para notificar errores\n",MAGICD_BUGVERB));
   printf(sprintf("   %-10s para sugerir ideas\n",MAGICD_IDEAVERB));

   if (IS_WIZARD(TP))
   {
       printf("\n");
       printf("   generarbd  para reconstruir la base de datos de conjuros\n");
       printf("   bd         para mostrar la base de datos de conjuros\n");
   }

   return 1;
}

/****************************************************************************/

int exists(string str) {
string s1, s2;

    if(strstr(str, "..") != -1) return 0;
    if(file_size(str) < 0) return 0;
    else return 1;
}

/****************************************************************************/

private string md_queryspellshortname(string spell) {
/* Esta funcion obtiene a partir del nombre del conjuro (nombre largo)
   el nombre del fichero en el que esta implementado el conjuro
   (nombre corto)                                                           */

string *largo, *corto;
int i,j;

   if (!spell || spell=="") return 0;
   spell = lower_case(spell);
   i=member(long_names, spell);
   if ( i>= 0) return short_names[i];
   return 0;
}

/****************************************************************************/

string md_queryfilename(string spell) {
/* Esta funcion se encarga de buscar la localizacion dentro de los directorios
   de conjuros, del conjuro que vamos a lanzar.
   Despues se calculan los posibles directorios donde buscar, desde el mas
   restrictivo (conjuros del propio gremio) hata el mas general (conjuros
   base). Se ejecuta el primer conjuro que se encuentra.                  */

string fichero, *path;
int i,j;

   if (!spell) return 0;

   path = ({});
   path += ({ MAGICD_SPELL_DIR + "canalizacion/" });
   path += ({ MAGICD_SPELL_DIR + "esencia/" });
   path += ({ MAGICD_SPELL_DIR + "mentalismo/" });
   path += ({ MAGICD_SPELL_DIR + "general/" });
   path += ({ MAGICD_SPELL_DIR + "abjuracion/" });
   path += ({ MAGICD_SPELL_DIR + "adivinacion/" });
   path += ({ MAGICD_SPELL_DIR + "transmutacion/" });
   path += ({ MAGICD_SPELL_DIR + "conjuracion/" });
   path += ({ MAGICD_SPELL_DIR + "encantamiento/" });
   path += ({ MAGICD_SPELL_DIR + "evocacion/" });
   path += ({ MAGICD_SPELL_DIR + "ilusion/" });
   path += ({ MAGICD_SPELL_DIR + "nigromancia/" });
   j=sizeof(path);

   spell = spell + ".c";
   for( i=0; i<j; i++) {
     fichero = path[i] + spell;
     if(exists( fichero ))
          return fichero;
    }
    return 0;
}

/****************************************************************************/

int md_cast(object caster, string str) {
/* Funcion principal de lanzamiento de conjuros
   Se encarga de obtener de la linea de comandos el nombre del conjuro y
   sus argumentos. El conjuro DEBE escribirse entre comillas simples (')
   ya que sino no es posible separar el conjuro de sus parametros
   Esta funcion tambien comprueba que el lanzador conozca el conjuro y de
   si es posible o no lanzarlo en el entorno actual del lanzador           */

int res,ws;
string fichero, spell, args;
object ob;

   /* Incluyo un '@' para indicar el final del comando, simplificara algunos
      problemas de 'parsear' el comando                                      */

   if (!str || str == "")
   {
        return notify_fail(sprintf("Uso: %s %s 'nombre conjuro'\n",MAGICD_VERB,MAGICD_CASTVERB));
   }

   str=str+" @";
   res=sscanf(str || "", "'%s' %s @", spell, args);
   switch(res) {
     case 0: spell=str; args=""; break;
     case 1: if (spell[0]=='\'') spell=str[1..<2]; args=""; break;
   }

   if (!sizeof(spell)) {
        return notify_fail(sprintf("Uso: %s %s 'nombre conjuro'\n",MAGICD_VERB,MAGICD_CASTVERB));
   }

   spell = lower_case(spell);

   /* Localizamos el fichero que corresponde a este conjuro */
   fichero = md_queryspellshortname(spell);
   if (! (fichero=md_queryfilename(fichero)) ) return notify_fail("Ese conjuro no existe\n");
   
   if (fichero->QuerySpellType() >= TD_MAGICO)
   {
     string uso;
     mixed objetivo;
     uso = fichero->QuerySpellUse();
     if (uso && sscanf(args, regreplace(uso, "<objetivo>", "%s", 0), objetivo) && (objetivo = present(objetivo, environment(TP)))
         && query_once_interactive(objetivo))
     {
       if (objetivo != TP)
       {
         log_file("TRY_PK", ctime() + ": " + TNREAL + " intentó usar el conjuro " +
                  fichero->QuerySpellName() + " contra " + NREAL(objetivo) + ".\n");
         return notify_fail("La luchah entre jugadores no está actualmente permitida.\n");
       }
     }
     else if (!uso ||uso == "")
     // no hay objetivo
     {
       object *jugadores = filter(all_inventory(environment(TP)), SF(query_once_interactive)) - ({TP});
       if (sizeof(jugadores) && !query_wiz_level(TP))
       {
       string *nombres = map(jugadores, (:NREAL($1):));
         log_file("TRY_PK", ctime() + ": " + TNREAL + " intentó usar el conjuro " +
                  fichero->QuerySpellName() + " contra " +
                  implode(nombres[..<2], ", ") + (sizeof(nombres[..<2]) ? " y " : "") + nombres[<1] + ".\n");
         return notify_fail("La luchah entre jugadores no está actualmente permitida.\n");
       }
     }
   }
   return (call_other(fichero, "main", caster, args));

}


/****************************************************************************/

int md_info(string str) {
string fichero;

   if (!str || str == "" || !sscanf(str,"'%s'",str) )
   {
       return notify_fail(sprintf("Uso: %s %s 'nombre conjuro'\n",MAGICD_VERB,MAGICD_INFOVERB));
   }

   if (!TP->HasSpell(lower_case(str)) && !IS_LEARNER(TP))
       return notify_fail("No tienes memorizado ningún conjuro con ese nombre.\n");
   if (!( fichero=md_queryfilename(md_queryspellshortname(str))) )
   {
       return notify_fail(sprintf("El conjuro '%s' no existe\n",str));
   }
   fichero->info();
   return 1;
}


/****************************************************************************/

public string QueryFileSpell(string hechizo)
{
 string fichero;

 seteuid(getuid());
 md_check_db();

 fichero = md_queryspellshortname(hechizo);
 if (!( fichero=md_queryfilename(fichero)) ) return 0;
 return fichero[0..<3];
}

/****************************************************************************/

int main (object caster, string str) {
string verb, rest;

   if (!str) return md_usage();

   if (sscanf(str, "%s %s", verb, rest) != 2) verb=str;
   if (!rest) rest="";

   seteuid(getuid());

   /* Comprobamos el estado de la base de datos */
   md_check_db();

   switch (verb) {
      case MAGICD_CASTVERB : return md_cast(caster, rest); break;
      case MAGICD_INFOVERB : return md_info(rest); break;
      case "bug":  return md_report("BUG", rest); break;
      case "idea": return md_report("IDEA", rest); break;
      case "generarbd" :
            if (IS_WIZARD(TP)) return md_build_spell_db();
      case "bd"  :
            if (IS_WIZARD(TP)) return printf("%O\n", spell_db), 1;
      default : return md_cast(caster,verb+" "+rest);
   }
   return 1;
}

void espera(object caster, string args, string fichero)
{
    caster->Set("P_LANZANDO",0);
    caster->SetCombatDelay(0);
    call_other(fichero, "main", caster, args);
}

