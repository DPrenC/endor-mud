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

  SetIntShort("el segundo piso del castillo");
  SetIntLong(
"Te encuentras al final del pasillo. Hay salidas en las cuatro direcciones, "
"parecen las habitaciones reales, aunque no podrias asegurarlo. Algo hacia "
"el norte se encuentra el salon del trono, y hacia el sur ves el balcon que "
"da a los jardines del castillo.\n");
  SetIntBright(100);

    AddExit("sur",PISO2+"wbalcon");
    AddExit("norte",PISO2+"piso2_11");
    AddExit("este",PISO2+"bedroom");
    AddExit("oeste",PISO2+"bath");
    AddDoor("este","la puerta del dormitorio del rey",
        "Es una lujosísima puerta de madera, cubierta artísticamente de mithril.\n",
        ({"puerta","puerta este","puerta de mithril","puerta de dormitorio",
        "puerta del dormitorio"}),GENDER_FEMALE,
        ([P_MATERIAL:M_MADERA,P_DOOR_STATE:DOOR_CLOSED]));
    AddDoor("oeste","la puerta de los reales baños",
        "Es una preciosa puerta de madera, decorada lujosamente con diamantes.\n",
        ({"puerta","puerta oeste","puerta de diamantes","puerta de banyos",
        "puerta de baños","puerta de los banyos","puerta de los baños"}),GENDER_FEMALE,
        ([P_MATERIAL:M_MADERA,P_DOOR_STATE:DOOR_CLOSED]));
AddDetail(({"lampara","lamparas","lampara de diamantes",
              "lamparas de diamantes",}),
"Las lamparas del techo estan hechas con diamantes engarzados entre si. De "
"ellas fluyen luces de todos los colores en toda la estanacia.\n");
  AddDetail("suelo","Ves tu propio reflejo en el suelo junto con el juego de "
"            luces que crean las lamparas del techo.\n");
  AddDetail(({"paredes","pared",}),
"Son paredes de pura roca tallada, cubiertas de finas lineas de oro.\n");
  AddDetail("puertas","Son simples puertas.\n");

}