/* Kenton.SIMAURIA '/d/kenton/comun/otros/cabmar.c'

O=O=O=O=O=O=O=O=O=O=O=O=O=O=O=O=O=O=O=O=O=O=O=O=O=O=O=O=O=O=O=O=O=O=O=O

I   cabmar.c   Un caballito de mar disecado.                          I

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

        SetIds(({"caballito"}));

        SetAds(({"un","de","mar","disecado"}));

        SetValue(100);

        SetWeight(5);

        SetShort("un caballito de mar");

        SetLong(

"Es un caballito de mar disecado.\n");

}

