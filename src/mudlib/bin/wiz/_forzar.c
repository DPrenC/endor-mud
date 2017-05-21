/* SIMAURIA '/bin/wiz/_forzar.c'
   =============================
*/
#include <sounds.h>

int main( string str )
{
  string *words, what;
  object towhom;

  if (!sizeof(str)) {
    return notify_fail("Forzar jugador acción\n");
  }
  words = explode(str," ");
  if (sizeof(words) < 2) {
    return notify_fail("Forzar jugador acción\n");
  }
  what = implode(words[1..sizeof(words)-1]," ");
  if (!(towhom = find_object(lower_case(words[0])))) {
    return notify_fail("Esa criatura no existe.\n");
  }
  if (query_wiz_level(towhom)>=query_wiz_level(TP) || (query_wiz_level(towhom)>=query_wiz_level(TP) && TP->QueryRealName()!="orome"))
  {
    return notify_fail("Sería un acto del mismísimo Melkor usar tu Poder sobre otro Ainu.\n");
  }
  write(command(what, towhom)?"Grandes son tus poderes sobre los simples mortales.\n":"Tu Poder no alcanza para eso.\n");
  return 1;

}
