
/* Kenton.SIMAURIA '/d/kenton/comun/otros/pluma.c'
O=O=O=O=O=O=O=O=O=O=O=O=O=O=O=O=O=O=O=O=O=O=O=O=O=O=O=O=O=O=O=O=O=O=O=O
I   pluma.c    Una pluma de la cola de un pavo real.                  I
O---------------------------------------------------------------------O
I   [o] Okkita@Simauria                                               I
O---------------------------------------------------------------------O
I   Creacion.............. 04/02/99  [o] Objeto chorra para la bolsa  I
O   Ultima modificacion... 04/02/98      de algun kender.             O
I                                                                     I
O=O=O=O=O=O=O=O=O=O=O=O=O=O=O=O=O=O=O=O=O=O=O=O=O=O=O=O=O=O=O=O=O=O=O=O
*/

#include <properties.h>
inherit THING;

create() {
        ::create();
        SetIds(({"pluma"}));
        SetAds(({"una","multicolor","pluma","de pavo","real"}));
        SetValue(3);
        Set(P_GENDER, GENDER_FEMALE);
        SetWeight(5);
        SetShort("una pluma");
        SetLong(
"Es una multicolor pluma de la cola de un pavo real.\n");
}
