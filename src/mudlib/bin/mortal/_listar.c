/* SIMAURIA '/bin/mortal/_listar.c'
   ===============================
   [N] Nyh@simauria

   10-06-03 [h] Creación
*/
#include <skills.h>
#include <gremios.h>

int main(string str) {
  string str1, str2;

seteuid(getuid());
  if (!str) return notify_fail("¿Listar qué?\n");
//write(sprintf("str=%O\n",str));

  if (sscanf(str=lower_case(str),"%s %s",str1,str2)!=2) {
    str1=str;
    str2=TP->QueryGuild();
  }
  if (str1!="habilidades")  return notify_fail("¿Listar qué?\n");

//write(sprintf("str=%O\nstr1=%O\nstr2=%O\nstr2=%O\nstr2=%O\n",str,str1,str2,str2[..<2],(str2[..<2])[..<2]));
// Explico el if de abajo... como los gremios estan en singular, por si alguno
// los mete en plural les quito 1 o 2 letras y compruebo si existe, simple
  while (str2!="") {
    if (VALIDA_GREMIO(str2)) break;
    str2= str2[..<2];
//    write(""+str2+"\n");
  }

  if (!(str1=GUILD->ListSkills(str2))) return notify_fail("¿Listar habilidades de qué gremio?\n");
  STR->smore(str1,TP->QueryPageSize());
  return 1;
}
