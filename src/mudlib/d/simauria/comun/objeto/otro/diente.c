/* Kenton.SIMAURIA '/d/kenton/comun/otros/diente.c'

O=O=O=O=O=O=O=O=O=O=O=O=O=O=O=O=O=O=O=O=O=O=O=O=O=O=O=O=O=O=O=O=O=O=O=O

I   diente.c   Un diente (de tiburon).                                I

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

        SetIds(({"diente"}));

        SetAds(({"un","de","tiburon"}));

        SetValue(50);

        SetWeight(2);

        SetShort("un diente");

        SetLong(

"Es un diente aserrado. Tiene forma conica y mide unos 5 centimetros\n"

"de largo.\n");

  SetExtra(
"Hmm..., al fijarte mejor te da la impresion de que se trata de un\n"
"diente de tiburon.\n");


}

