/**************************************************************************/
/*                                                                        */
/*  Casa 3 Norte creado por Cheto para la aldea de Nandor                 */
/* [ch] Cheto                                                             */
/*  [k] Kintups                                                           */
/*                                                                        */
/* [ch] ??? 02 Jun 1997 --- Creaci�n.                                     */
/*  [k] Mon 13 Nov 2000 --- Revisados los textos y a�adidos los W()       */
/*                                                                        */
/**************************************************************************/

#include "./path.h"

inherit SIM_ROOM;
create() {
  ::create();
  SetLocate("Aldea de Nandor");
  SetIntShort("una casa abandonada");
  SetIntLong(W(
    "Est�s en una casa abandonada, lo �nico que queda en la casa es su "
    "ruinoso techo, as� como sus paredes agrietadas y llenas de marcas "
    "de carb�n.\n" ));
  AddDetail(({"marca","marcas"}), "Tonto Quien Lo Lea\n" );
  SetIndoors(1);
  SetIntBright(30);
  AddExit("sur","../calle3");
}