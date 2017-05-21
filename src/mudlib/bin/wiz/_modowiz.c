/* SIMAURIA '/bin/wiz/_modowiz.c'
   ==============================
   [w] Woo@simauria

   31-03-99 [w] Traspaso desde el player.c.
*/

#include <properties.h>


int main( string str )
{
  if (!str) {
    if (TP->Query(P_NOWIZ))
      write("Modowiz(tm) está desactivado; actuando como jugador.\n");
    else
      write("Modowiz(tm) está activado; actuando como wizard.\n");
    return 1;
  }
  if (str == "no") {
    write("Desactivando Modowiz(tm)...\n");
    TP->Set(P_NOWIZ, 1);
    return 1;
  }
  if (str == "si" || str == "sí") {
    write("Activando Modowiz(tm).\n");
    TP->Set(P_NOWIZ, 0);
    return 1;
  }
  return notify_fail("Uso: modowiz [si | no]\n"),0;
}
