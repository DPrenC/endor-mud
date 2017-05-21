/* Castillo Kha-annu.
 *   [I] Izet@Simauria.
 *   Creacion: 16 Oct, 1997
 *   Ultima modificacion: 1 May, 1998.
 */

#include "path.h"
inherit KHA_ROOM;
create() {
  ::create();
  SetIntShort("el balcón de las Habitaciones Reales");
  SetIntLong(
"Te encuentras en el inmenso balcon de las habitaciones del Rey Belthain de Kha-annu.\n"
"Es un extranyo lugar... la punta del castillo sobresale de la montanya de Kha-annu.\n"
"Desde aqui logras ver toda la ladera sur, y a traves de un desfiladero logras divisar "
"un camino serpenteante.\n"
   );

  AddExit("norte",PISO2+"piso2_12");

  AddDetail( ({"ladera","montanya"}),
             "Es la parte sur de la ladera, solo eso.\n"
             );
  AddDetail("camino","Parece ser el camino que conduce hacia Kenton.\n");
}