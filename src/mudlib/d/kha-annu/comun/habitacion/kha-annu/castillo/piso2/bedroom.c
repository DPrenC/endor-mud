/* Castillo Kha-annu.
 *   [I] Izet@Simauria.
 *   Creacion: 16 Oct, 1997
 *   Ultima modificacion: 1 May, 1998.
 */

#include "./path.h"
#include <properties.h>
#include <door.h>
#include <materials.h>

inherit KHA_ROOM;

create() {
  ::create();
  SetIntShort("el dormitorio de Belthain, Rey de los Enanos");
  SetIntLong(
"Has entrado en el dormitorio de Belthain. Esta es una enorme habitacion "
"decorada con los muebles mas lujosos que hayas visto. Donde quiera que "
"mires puedes ver el lujo que invade todo el castillo, comenzando por la "
"impresionante cama y los hermosos armarios embellecidos con finas lineas "
"de oro.\n");

  SetIndoors(1);

  SetIntBright(100);

    AddExit("oeste",PISO2+"piso2_12");
    AddDoor("oeste","la puerta del pasillo",
        "Es una magnífica puerta de madera finamente labrada, adornada con "
            "soberbias tallas de oro.\n",
        ({"puerta","puerta del pasillo","puerta del pasillo","puerta de madera"}), GENDER_FEMALE,
        ([P_MATERIAL:M_MADERA,P_DOOR_STATE:DOOR_CLOSED]));
    AddDetail("cama",
"La cama esta hecha de madera y adornada con diamantes y mithril. Al "
"reflectarse la luz sobre ella, un arcoiris brilla por toda la estancia.\n");

  AddDetail("armarios",
"Estos armarios estan hechos de ebano y decorados con finisimas lineas de "
"oro.\n");

   AddItem(MONS+"sirviente",REFRESH_DESTRUCT,2);
}
