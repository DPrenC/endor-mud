/**
 * SIMAURIA '/bi/mortal/_charset.c'
 */

#include <properties.h>
#include <colours.h>

int charset() {
  if (TP->Query(P_CHARSET)==USASCII) TP->Set(P_CHARSET, EXTENDED);
  else TP->Set(P_CHARSET, USASCII);
  write("Has cambiado tu juego de caracteres a " + TC_CYAN +
        (TP->Query(P_CHARSET)==1 ? "latin1"
                                 : TP->Query(P_CHARSET)==2 ? "us-ascii"
                                                           : "desconocido"
        ) + TC_NORMAL + ".\n");
  return 1;
}
