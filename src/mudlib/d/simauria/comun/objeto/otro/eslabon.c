/* Kenton.SIMAURIA '/d/kenton/comun/otros/eslabon.c'

O=O=O=O=O=O=O=O=O=O=O=O=O=O=O=O=O=O=O=O=O=O=O=O=O=O=O=O=O=O=O=O=O=O=O=O

I   eslabon.c   Un eslabon de una cadena.                             I

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

        SetIds(({"eslabon"}));

        SetAds(({"un","de","cadena"}));

        SetValue(10);

        SetWeight(50);

        SetShort("un eslabon");

        SetLong(

"Es un eslabon de una cadena. Le falta el resto de la cadena, pero\n"

"es un buen comienzo.\n");

        ExaLong("Hmm..., este eslabon no tiene marcas de desgaste... no parece haber\n"
        "sido nunca parte de una cadena.\n");

}

