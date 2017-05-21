/* Castillo Kha-annu.
 *   [I] Izet@Simauria.
 *   Creacion: 16 Oct, 1997
 *   Ultima modificacion: 1 May, 1998.
 */

#include "path.h"
#include <properties.h>
#include <materials.h>

inherit KHA_ROOM;

create() {
   ::create();
  SetIntShort("el segundo piso");
  SetIntLong(
"Estas en el segundo piso del castillo de Kha-annu. Hacia el este y el "
"oeste ves sendas puertas que parecen ser habitaciones, posiblemente "
"dedicadas al descanso de algunos de los sirvientes. Del techo cuelgan "
"unas preciosas lamparas de diamantes, y tu calzado resbala por el lujoso "
"suelo de marmol.\n");
  SetIntBright(70);

    AddExit("norte",PISO2+"piso2_3");
    AddExit("sur",PISO2+"piso2_1");
    AddExit("este",PISO2+"room1");
    AddExit("oeste",PISO2+"room2");
    AddDoor("este","la puerta de la habitación de invitados",
        "Es una puerta de madera decorada en oro.\n",
        ({"puerta","puerta este","puerta de oro"}),GENDER_FEMALE,
        ([P_MATERIAL:M_MADERA,P_DOOR_STATE:DOOR_CLOSED]));
    AddDoor("oeste","la puerta de la habitación de invitados",
        "Es una puerta de madera, ricamente labrada.\n",
        ({"puerta","puerta oeste","puerta de madera"}),2,
        ([P_MATERIAL:M_MADERA,P_DOOR_STATE:DOOR_CLOSED]));
    AddDetail(({"lampara","lamparas","lampara de diamantes",
              "lamparas de diamantes",}),
"Las lamparas del techo estan hechas con diamantes engarzados entre si. De "
"ellas fluyen luces de todos los colores en toda la estancia.\n");
  AddDetail("suelo","Ves tu propio reflejo en el suelo junto con el juego de "
"            luces que crean las lamparas del techo.\n");
  AddDetail(({"paredes","pared",}),
"Son paredes de pura roca tallada, cubiertas de finas lineas de oro.\n");
  AddDetail(({"habitacion","habitaciones"}),
"No puedes ver que hay dentro desde aqui, quiza si entraras en ellas...!");
}