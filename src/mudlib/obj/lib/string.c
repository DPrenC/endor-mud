/**
 * SIMAURIA '/obj/lib/string.c'
 */

#include <config.h>
#include <wizlevels.h>
#include <properties.h>
#include <lpctypes.h>
#include <colours.h> // Para el tratamiento de colores
#include "/obj/lib/string.h"

#define MYFILE STR

#pragma strict_types
#pragma save_types

/*-------------------------------------------------------------------------
** string mkstr (int len, void|string pattern)
**
**  Returns a string of length <len> made out of <pattern>, or of spaces if
**  <pattern> is not defined.
*/

varargs string mkstr (int len, string pattern) {
  string rc;
  int actlen;

  if (len <= 0) return "";
  if (!pattern) pattern = "          ";
  rc = pattern;
  actlen = strlen(pattern);
  while (actlen < len) rc += rc, actlen *= 2;
  return rc[0..len-1];
}

/*-------------------------------------------------------------------------
** string ladjust (string str, int len, void|string pattern)
**
** Returns <str> adjusted to length <len> by repeatedly adding <pattern>
** (or spaces if <pattern> isn't given) to its tail. If <str> is longer than
** <len>, it remains unchanged.
*/

varargs string ladjust (string str, int len, string pattern) {
  int actlen;

  if (!str || len <= 0) return 0;
  if ( (actlen = strlen(tcfstr(str))) >= len) return str;
  return str+mkstr(len-actlen, pattern);
}

/*-------------------------------------------------------------------------
** string ladjcut (string str, int len, void|string pattern)
**
** Returns <str> adjusted to length <len> by repeatedly adding <pattern>
** (or spaces if <pattern> isn't given) to its tail if <str> is too short,
** or by removing extraneous characters from the tail if <str> is too long.
*/

varargs string ladjcut (string str, int len, string pattern) {
  int actlen;

  if (!str || len <= 0) return 0;
  if ( (actlen = strlen(tcfstr(str))) <= len) return str+mkstr(len-actlen, pattern);
  return str[0..len-1];
}

/*-------------------------------------------------------------------------
** string radjust (string str, int len, void|string pattern)
**
** Returns <str> adjusted to length <len> by repeatedly adding <pattern>
** (or spaces if <pattern> isn't given) to its head. If <str> is longer than
** <len>, it remains unchanged.
*/

varargs string radjust (string str, int len, string pattern) {
  int actlen;

  if (!str || len <= 0) return 0;
  if ( (actlen = strlen(tcfstr(str))) >= len) return str;
  return mkstr(len-actlen, pattern)+str;
}

/*-------------------------------------------------------------------------
** string radjcut (string str, int len, void|string pattern)
**
** Returns <str> adjusted to length <len> by repeatedly adding <pattern>
** (or spaces if <pattern> isn't given) to its head if <str> is too short,
** or by removing extraneous characters from the head if <str> is too long.
*/

varargs string radjcut (string str, int len, string pattern) {
  int actlen;

  if (!str || len <= 0) return 0;
  if ( (actlen = strlen(tcfstr(str))) <= len) return mkstr(len-actlen, pattern)+str;
  return str[<len..<1];
}

/*-------------------------------------------------------------------------
** string cadjust (string str, int len, void|string pattern)
**
** Returns <str> centered to length <len> by repeatedly adding <pattern>
** (or spaces if <pattern> isn't given).
** If <str> is longer than <len>, it remains unchanged.
*/

varargs string cadjust (string str, int len, string pattern) {
  int actlen;

  if (!str || len <= 0) return 0;
  if ( (actlen = strlen(tcfstr(str))) >= len) return str;
  return mkstr((len-=actlen)/2, pattern)+str+mkstr((len+1)/2, pattern);
}

/*-------------------------------------------------------------------------
** string cadjcut (string str, int len, void|string pattern)
**
** Returns <str> centered to length <len> by repeatedly adding <pattern>
** (or spaces if <pattern> isn't given) if <str> is too short, or by
** removing extraneous characters from its tail if <str> is too long.
*/

varargs string cadjcut (string str, int len, string pattern) {
  int actlen;

  if (!str || len <= 0) return 0;
  if ( (actlen = strlen(tcfstr(str))) <= len)
    return mkstr((len-=actlen)/2, pattern)+str+mkstr((len+1)/2, pattern);
  return str[0..len-1];
}

/*-------------------------------------------------------------------------
** string string_replace (string str, string old, string new)
**
** Replace in <str> all occurences of <old> by <new>.
*/

string string_replace (string str, string old, string new) {
  int len;
  string back;

  if (!str || !old || !new) return str;
  else if (str == old) return new;
  else if ( strlen(str) < (len = strlen(old)) ) return str;
  back = implode(explode(str, old), new);
/*
  if (str[0..len-1] == old) back = new + back;
  if (str[<len..<1] == old) back = back + new;
*/
  return back;
}

/*----------------------------------------------------------------------
** int string_compare (str1, str2)
**
** Return if str1 is lexicographically greater than str2.
** This fun is meant mainly for use by sort_strings().
*/

int string_compare (string str1, string str2) {
  return str1 > str2;
}

/*----------------------------------------------------------------------
** string *sort_strings (string *strs, void|string|closure compare_fun)
**
** Sort an array <strs> of strings by using <compare_fun> (default is
** the lib's "string_compare") and return the sorted array.
** <compare_fun> should be of type  int (string, string) and return
** nonzero if the first string is 'greater' than the second.
*/

varargs string *sort_strings (string *strs, mixed compare_fun) {
  if (!strs) return 0;
  if (!compare_fun) compare_fun = SF(>);
  return sort_array (strs, compare_fun);
}

/*-------------------------------------------------------------------------
** string *break_string (string str, int len)
**
** Break <str> into parts of length <len> and return an array of these
** parts.
*/

string *break_string (string str, int len) {
  int i, m;
  string *parts;

  parts = ({});
  if (!(str && (len > 0))) return 0;
  if ((m = strlen(str)) <= len) return ({ str });
  for (i = 0; i < m; i += len) parts += ({ str[i..i+len-1] });
  return parts;
}

/*-------------------------------------------------------------------------
** string *break_line (string str, void|int len, void|string prefix)
**
** Clips a <text> (w/o newlines!) wordwise down to a linelength <len>
** (default 78) and return the array of the resulting lines.
** Any additional line is prefixed with <prefix>.
** If a single word itself is longer than <len>, it will be splitted as
** as well.
*/

varargs string *break_line (string str, int len, string prefix) {
  int i, j, k, s, plen;
  string *strs, *words, *text, pfix;

  words = ({});
  text = ({});
  if (!len) len = 78;
  if (!prefix) prefix = "";
  plen = strlen(prefix);
  pfix = "";
  if (!(str && (len > 0))) return 0;
  plen = strlen(prefix);
  strs = explode(". "+str+" .", " ");
  for (i=1, s=sizeof(strs)-1; i < s; i++)
    words += break_string (strs[i], len);
  s = sizeof(words);
  for (i=0, j=0, k=0; j < s; j++) {
    k += strlen(words[j]);
    if (k+j-i <= len) continue;
    text += ({ pfix+implode(words[i..j-1], " ") });
    if (!i) pfix = prefix;
    k = plen+strlen (words[i=j]);
  }
  return text + ({ pfix+implode(words[i..j-1], " ") });
}

/*-------------------------------------------------------------------------
** string wrap(string str,void|int length,void|int lspace)
** Adds newlines to a string, if one part of the string is
** longer than <length>-<lspace> chars. <lspace> spaces will
** be added in front of the line. This is except for the first
** line. This line will have <length> chars and start in the
** first column.
*/

public varargs string wrap(string text, int length, int lspace) {
  return terminal_colour(text, 0, length, lspace);
}

/*-------------------------------------------------------------------------
** string lit_string (string str)
**
** Replace any control characters (tab, \, newline, CR) in <str> by their
** LPC-notation (\t, \\,\n, \r) and return the result.
*/

string lit_string (string str) {
  str = string_replace (str, "\\", "\\\\");
  str = string_replace (str, "\n", "\\n");
  str = string_replace (str, "\r", "\\r");
  str = string_replace (str, "\t", "\\t");
  return string_replace (str, "\"", "\\\"");
}

/*-------------------------------------------------------------------------
** string mixed_to_string (mixed value, void|int depth)
**
** Makes a string in LPC-notation from any value.
** Arrays are expanded in <depth>-1 recursions.
** <depth> == 0 expands any depth.
*/

varargs string mixed_to_string(mixed mix, int lvl)
{
  int i, j, s, t;
  string str;
  mixed *keys;

  switch(typeof(mix))
    {
     default:
     case T_INVALID:
      return "<invalid>";
     case T_LVALUE:
      return "&"+mixed_to_string(mix, lvl-1);
     case T_NUMBER:
     case T_FLOAT:
      return to_string(mix);
     case T_STRING:
      return "\""+lit_string(mix)+"\"";
     case T_POINTER:
      if (!sizeof(mix)) return "({ })";
      if (lvl==1) return "({...})";
      return "({"+implode(map(mix,SF(mixed_to_string), //'
				    lvl?lvl--:0),",")+"})";
     case T_OBJECT:
      return "["+object_name((object)mix)+"]";
     case T_CLOSURE:
     case T_SYMBOL:
      return sprintf("%O", mix);
     case T_QUOTED_ARRAY:
      return "'"+mixed_to_string(funcall(lambda(0, mix)), lvl-1);
     case T_MAPPING:
      if (!s=sizeof(keys=m_indices(mix)))
        return "([ ])";
      if (lvl==1) return "([...])";
      t=get_type_info(mix, 1);
      str="([";
      for(i=0;i<s;i++)
        {
	  str+=mixed_to_string(keys[i],lvl?lvl-1:0);
	  if(t)
            {
	      str+=":"+mixed_to_string(mix[keys[i],0],lvl?lvl-1:0);
	      for(j=1;j<t;j++)
	        str+=";"+mixed_to_string(mix[keys[i],j],lvl?lvl-1:0);
	    }
	  if(i<s-1) str+=",";
	}
      return str+"])";
    }
  return "...";
}

/*-------------------------------------------------------------------------
** string stime (int date, void|int fmt)
**
** Like cdate() this converts a numeric date into a string, but in a more
** european manner: 'Mon 15-Jun-1992 20:00:00'
** 'fmt' specifies which parts appear:
**    SD_WDAY  : day of the week
**    SD_DATE  : the date itself
**    SD_SDATE : the date itself, but w/o the century
**    SD_TIME  : the time
** fmt==0 defaults to (SD_WDAY | SD_DATE | SD_TIme) == SD_FULL
*/

varargs string stime (int date, int fmt) {
  string cdate, rc;
  if (!fmt) fmt = SD_FULL;
  if (fmt & SD_DATE && fmt & SD_SDATE) fmt ^= SD_SDATE;
  cdate = ctime(date);
  rc = "";
  if (SD_WDAY & fmt) {
    rc = cdate[0..2];
    if (fmt & (SD_DATE | SD_TIME | SD_SDATE)) rc += " ";
  }
  if (SD_DATE & fmt) {
    rc = rc+cdate[8..9]+"-"+cdate[4..6]+"-"+cdate[20..23];
    if (fmt & SD_TIME) rc += " ";
  }
  if (SD_SDATE & fmt) {
    rc = rc+cdate[8..9]+"-"+cdate[4..6]+"-"+cdate[22..23];
    if (fmt & SD_TIME) rc += " ";
  }
  if (SD_TIME & fmt) rc = rc+cdate[11..18];
  return rc;
}

/*-------------------------------------------------------------------------
** int smore (mixed text, void|int chunk,object ob, string fun)
**
**   Mores the <text> to the player in chunks of <chunk> lines.
**   Default for <chunk> is 16 lines per page or the player's pagesize.
**   <text> may be one single string, each line terminated by a\n,
**   or an string-array containing the lines.
**   The more accepts following commands:
**
**   ENTER / i  : pagina siguiente.
**   a          : pagina anterior.
**   p          : ir a la primera pagina.
**   u          : ir a la ultima pagina.
**   <linea>    : ir a la linea <linea>.
**   /<cadena>  : avanza hasta encontrar la cadena <cadena>.
**   /          : repite la ultima busqueda.
**   e          : reescribe la pagina actual.
**   ?          : visualiza esta ayuda.
**   s          : sale del listado.
**
**    After the text was mored the function fun in object ob is called
**    by call_other(ob, fun)
**
** void smore_prompt (int firstline, int lastline, int maxline)
**
**   Print the prompt for smore. <firstline>, <lastline> specify the
**   printed page, <maxline> the highest line-no
**
** void smore_help (int chunksize)
**
**   Print the list of commands available at the prompt.
*/

void smore_prompt (int firstline, int lastline, int maxline) {
  write("=== Listado: Lineas "+firstline+".."+lastline+" de "+maxline
       +" [ENTER/I,a,p,u,e,s,/<cadena>,<linea>. Escribe ? para ayuda]\n"
       );
}

void smore_help (int chunksize) {
  write ( "Comandos permitidos:\n"
        + "  ENTER     : pagina siguiente.\n"
        + "  a         : pagina anterior.\n"
        + "  p         : ir a la primera pagina.\n"
        + "  u         : ir a la ultima pagina.\n"
        + "  <linea>   : ir a la linea <linea>.\n"
        + "  /<cadena> : avanza hasta encontrar la cadena <cadena>.\n"
        + "  /         : repite la ultima busqueda.\n"
        + "  e         : reescribe la pagina actual.\n"
        + "  ?         : visualiza esta ayuda.\n"
        + "  s         : sale del listado.\n"
        + "El tamaño de pagina es de "+chunksize+" lineas.\n"
        );
}


varargs int smore (mixed text, int chunk, object ob, string fun, int end) {
  int line;
  mixed *data;

  if (!text) return 0;

  data = allocate(SMORE_DATASIZE);
  data[SMORE_OBJECT] = ob; data[SMORE_FUN] = fun;
  data[SMORE_END] = end;
  data[SMORE_CHUNK] = chunk ? chunk:(int)TP->Query(P_PAGESIZE);
  if (!data[SMORE_CHUNK])
    data[SMORE_CHUNK] = 16;
  if (!pointerp(text))
  {
    data[SMORE_TEXT] = explode((string) text, "\n");
    if (text[<1] == '\n')
      data[SMORE_TEXT] = data[SMORE_TEXT][0..<2];
  }
  else
    data[SMORE_TEXT] = (string *) text;
  if (!(data[SMORE_SIZE] = sizeof(data[SMORE_TEXT])))
    return 0;
  if (data[SMORE_SIZE] <= data[SMORE_CHUNK])
    {
      write (implode(data[SMORE_TEXT], "\n")+"\n");
      if (objectp(data[SMORE_OBJECT]) && stringp (data[SMORE_FUN]))
        call_other(data[SMORE_OBJECT], data[SMORE_FUN]);
      return 1;
    }
  data[SMORE_PRINTALL] = 0;
  data[SMORE_LINE] = 1;
  data[SMORE_REGEXP] = 0;
  write (implode(data[SMORE_TEXT][data[SMORE_LINE]-1..data[SMORE_LINE]+data[SMORE_CHUNK]-2], "\n")+"\n");
  line = data[SMORE_LINE]+data[SMORE_CHUNK]-1;
  line = (line > data[SMORE_SIZE]) ? data[SMORE_SIZE] : line;
  smore_prompt (data[SMORE_LINE], line, data[SMORE_SIZE]);
  input_to("_even_smore");
  TP->Set("_SMore_"+object_name(TO), data);
  return 1;
}

int _even_smore (string str) {
  int nline, display, line;
  mixed *data;
  string foo;

  data = (mixed *)TP->Query("_SMore_"+object_name(TO));
  if (!pointerp(data) || sizeof(data) != SMORE_DATASIZE)
    throw("SMore data corrupted.\n");
  display = 0;
  if (str == "e")
    display = 1;  /* no hace nada pero revisualiza la pagina actual */
  else if (str == "" ||str == "i")
    data[SMORE_LINE] += data[SMORE_CHUNK], display = 1;
  else if (str == "as")
    {
      data[SMORE_LINE] += data[SMORE_CHUNK];
      display = 1;
      data[SMORE_PRINTALL] = 1;
      if (data[SMORE_CHUNK] < 40)
        data[SMORE_CHUNK] = 40;
    }
  else if (str == "s")
    {
      write("=== Ok.\n");
      if (objectp(data[SMORE_OBJECT]) && stringp (data[SMORE_FUN]))
        call_other(data[SMORE_OBJECT], data[SMORE_FUN]);
      TP->Set("_SMore_"+object_name(TO), 0);
      return 1;
    }
  else if (str == "a")
    data[SMORE_LINE] -= data[SMORE_CHUNK], display = 1;
  else if (str == "p")
    data[SMORE_LINE] = 1, display = 1;
  else if (str == "u")
    data[SMORE_LINE] = data[SMORE_SIZE] - data[SMORE_CHUNK] + 1, display = 1;
  else if (str == "?")
    smore_help(data[SMORE_CHUNK]);
  else if (str[0] == '/')
    {
      string rexp;
      rexp = data[SMORE_REGEXP];
      if (strlen(str) < 2 && (!rexp || strlen(rexp) < 1))
        write("No se realizo ninguna busqueda antes.\n");
      else
      {
        if (strlen(str) > 1)
          rexp = str[2..];
        if (!regexp(({"dummy"}), rexp))
        {
          write("*** Expresion incorrecta.\n");
          rexp = 0;
        }
        else
        {
          data[SMORE_REGEXP] = rexp;
          nline = data[SMORE_LINE]+data[SMORE_CHUNK]-1;
          write("..buscando cadena..\n");
          while (   nline < data[SMORE_SIZE]
                 && !sizeof(regexp( data[SMORE_TEXT][nline..nline], rexp)))
            nline++;
          ;
          if (nline < data[SMORE_SIZE])
          {
            data[SMORE_LINE] = nline+1;
            display=1;
          }
          else
            write("*** Cadena no encontrada.\n");
        }
      }
    }
  else if (sscanf(str, "%d", nline) == 1)
    data[SMORE_LINE] = nline, display = 1;
  if (data[SMORE_LINE] < 1) data[SMORE_LINE] = 1;
  if (display)
    {
      if (data[SMORE_LINE] <= data[SMORE_SIZE])
        write (implode(data[SMORE_TEXT][data[SMORE_LINE]-1..data[SMORE_LINE]+data[SMORE_CHUNK]-2]
	      , "\n")+"\n");
    if ((   data[SMORE_END]
         && (data[SMORE_LINE] + data[SMORE_CHUNK] > data[SMORE_SIZE]))
        || (data[SMORE_LINE] > data[SMORE_SIZE]))
      {
        data[SMORE_TEXT] = 0;
        write("=== EOT\n");
        if (objectp(data[SMORE_OBJECT]) && stringp (data[SMORE_FUN]))
	  call_other(data[SMORE_OBJECT], data[SMORE_FUN]);
        TP->Set("_SMore_"+object_name(TO), 0);
        return 1;
      }
  }
  line = data[SMORE_LINE]+data[SMORE_CHUNK]-1;
  line = (line > data[SMORE_SIZE]) ? data[SMORE_SIZE] : line;
  if (!data[SMORE_PRINTALL])
    {
      smore_prompt (data[SMORE_LINE], line, data[SMORE_SIZE]);
      input_to("_even_smore");
    }
  else
    call_out("_even_smore", 0, "p");
  TP->Set("_SMore_"+object_name(TO), data);
  return 0;
}

public string now()
{
    string *fecha = explode(ctime(), " ");
    return fecha[2] + "-" + (member(({"Jan", "Feb",  "Mar",  "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"}), fecha[1]) + 1) + "-" + fecha[<1];
}

/* [woo] Convierte la hora a sistema español.
 *       !arg o arg=0  'Lun 12 Ene 12:57:20 1999'
 *       arg=1         'Lunes 12 de Enero de 1999 [12:57:20]
 *       Si le pasas una fecha con ctime pues la castellanizará.
 *       La forma de hacerlo sería la siguiente:
 *              etime(0||1,ctime()) hora actual
 *              etime(0||1,"Tue Mar  9 13:14:34 1999")
 */
varargs string etime(int arg, string vctime)
{
 string fecha,date;

 if (vctime) date=vctime;
 else date=ctime(time());
 fecha="";
 switch(date[0..2])
 {
  case "Mon": if (arg) fecha+="Lunes";     else fecha+="Lun"; break;
  case "Tue": if (arg) fecha+="Martes";    else fecha+="Mar"; break;
  case "Wed": if (arg) fecha+="Miércoles"; else fecha+="Mie"; break;
  case "Thu": if (arg) fecha+="Jueves";     else fecha+="Jue"; break;
  case "Fri": if (arg) fecha+="Viernes";   else fecha+="Vie"; break;
  case "Sat": if (arg) fecha+="Sábado";    else fecha+="Sab"; break;
  case "Sun": if (arg) fecha+="Domingo";   else fecha+="Dom"; break;
  default: if (arg) fecha+="Ni puta idea";   else fecha+="Npi"; break;;
 }

 fecha+=" "+date[8..9]+" ";
 if (arg) fecha+="de ";

 switch(date[4..6])
 {
  case "Jan": if (arg) fecha+="Enero";     else fecha+="Ene"; break;
  case "Feb": if (arg) fecha+="Febrero";   else fecha+="Feb"; break;
  case "Mar": if (arg) fecha+="Marzo";     else fecha+="Mar"; break;
  case "Apr": if (arg) fecha+="Abril";     else fecha+="Abr"; break;
  case "May": if (arg) fecha+="Mayo";      else fecha+="May"; break;
  case "Jun": if (arg) fecha+="Junio";     else fecha+="Jun"; break;
  case "Jul": if (arg) fecha+="Julio";     else fecha+="Jul"; break;
  case "Aug": if (arg) fecha+="Agosto";    else fecha+="Ago"; break;
  case "Sep": if (arg) fecha+="Septiembre";else fecha+="Sep"; break;
  case "Oct": if (arg) fecha+="Octubre";   else fecha+="Oct"; break;
  case "Nov": if (arg) fecha+="Noviembre"; else fecha+="Nov"; break;
  case "Dec": if (arg) fecha+="Diciembre"; else fecha+="Dic"; break;
  default: if (arg) fecha+="Ni puta idea";     else fecha+="Npi";
 }

 if (arg)
  fecha+=" de "+date[20..23]+" ["+date[11..18]+"]";
 else
  fecha+=" "+date[11..18]+" "+date[20..23];
 return fecha;
}

varargs string RemoveColors(mixed text)
{
  return terminal_colour(text, ([0:""]));
}

/***************************************************************************/
