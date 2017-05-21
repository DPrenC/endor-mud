/**************************************************************************/
/*                                                                        */
/*  [k] Kintups                                                           */
/*                                                                        */
/*  [k] Sun 19 Nov 2000 --- Revisados los textos y añadidos los W()       */
/*                                                                        */
/**************************************************************************/

#include "./path.h"
#include <moving.h>


#define LOCATE "Algun lugar del norte de Marhalt"
inherit SIM_ROOM;

haz_sur()
{
  tell_room(MARH("nandor/sendero8"),
    TP->QueryName()+" sale de entre el maizal.\n");
  write("Sigilosamente sales a la luz...\n.... ¡Y apareces en medio de un maizal!\n");
  TP->move(MARH("nandor/sendero8"),M_GO,"sur");
  tell_room(MARH("nandor/castillo/tunel/sal4"),
    TP->QueryName()+" sale del túnel.\n");
  return 1;
}

create()
{
  ::create();
  SetLocate(LOCATE);
  SetIntShort("la salida de un túnel");
  SetIntLong(
    "Estás en un oscuro y frío túnel. Sin embargo, ves una luz hacia el Sur.\n");
  SetIntBright(25);
  AddDetail(({"luz","luz al final del túnel","sur"}),
    "Si! Seguro que lleva hacia la salida!!!\n");
  AddExit("sur",SF(haz_sur));
  AddExit("norte","./pasadizo55");
}
