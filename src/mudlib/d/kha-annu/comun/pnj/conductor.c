/* Este es el que conduce */
/* [Woo] Modificado */

#include "path.h"
#include <properties.h>

inherit NPC;

create()
{
 ::create();
 SetStandard("cochero tuerto","humano",30,GENDER_MALE);
 SetIds( ({"humano","tuerto","cochero"}) );
 SetShort("el Cochero Tuerto");
 SetLong(
"Este es el conductor de la diligencia. Es un humano, no muy agraciado\n"
"fisicamente. Su ojo izquierdo esta cubierto por un parche, y parece que\n"
"le faltan unos cuantos dientes. Conduce la diligencia desde Kha-annu hasta\n"
"Nandor.\n");
  SetAlign(0);
}
