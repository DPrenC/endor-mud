/* Kenton.SIMAURIA '/d/kenton/comun/otros/boliche.c'
O=O=O=O=O=O=O=O=O=O=O=O=O=O=O=O=O=O=O=O=O=O=O=O=O=O=O=O=O=O=O=O=O=O=O=O
I   boliche.c   Un boliche de cristal azul.                           I
O---------------------------------------------------------------------O
I   [o] Okkita@Simauria                                               I
O---------------------------------------------------------------------O
I   Creacion.............. 10/02/99  [o] Objeto chorra para la bolsa  I
O   Ultima modificacion... 10/02/98      de algun kender.             O
I                                                                     I
O=O=O=O=O=O=O=O=O=O=O=O=O=O=O=O=O=O=O=O=O=O=O=O=O=O=O=O=O=O=O=O=O=O=O=O
*/

#include "./path.h"
inherit THING;

create() {
        ::create();
        SetIds(({"boliche"}));
        SetAds(({"un","de","cristal","azul"}));
        SetValue(50);
        SetWeight(5);
        SetShort("un boliche");
        SetLong(
"Es un boliche de cristal azul.\n");
}
