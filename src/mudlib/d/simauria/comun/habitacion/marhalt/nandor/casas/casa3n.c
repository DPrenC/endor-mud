/**************************************************************************/
/*                                                                        */
/*  Casa 3 Norte creado por Cheto para la aldea de Nandor                 */
/* [ch] Cheto                                                             */
/*  [k] Kintups                                                           */
/*                                                                        */
/* [ch] ??? 02 Jun 1997 --- Creación.                                     */
/*  [k] Mon 13 Nov 2000 --- Revisados los textos y añadidos los W()       */
/*                                                                        */
/**************************************************************************/

#include "./path.h"

inherit SIM_ROOM;
create() {
  ::create();
  SetLocate("Aldea de Nandor");
  SetIntShort("una casa abandonada");
  SetIntLong(W(
    "Estás en una casa abandonada, lo único que queda en la casa es su "
    "ruinoso techo, así como sus paredes agrietadas y llenas de marcas "
    "de carbón.\n" ));
  AddDetail(({"marca","marcas"}), "Tonto Quien Lo Lea\n" );
  SetIndoors(1);
  SetIntBright(30);
  AddExit("sur","../calle3");
}