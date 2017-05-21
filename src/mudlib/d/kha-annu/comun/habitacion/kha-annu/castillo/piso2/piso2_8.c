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
  SetIntShort("un pasillo. Segundo piso del castillo.");
  SetIntLong("\
Te encuentras en la parte mas al este del castillo Kha-annu. Ves puertas "
"hacia el este y hacia el oeste que parecen ser de habitaciones. Todo aqui "
"rebosa lujuria y elegancia entremezclados con algo tetrico y oscuro.\n");
  SetIntBright(70);

    AddExit("norte",PISO2+"piso2_7");
    AddExit("sur",PISO2+"piso2_9");
    AddExit("oeste",PISO2+"room3");
    AddExit("este",PISO2+"room4");
    AddDoor("oeste","la puerta de la habitación de invitados",
        "Es una puerta de madera, ricamente labrada.\n",
        ({"puerta","puerta oeste","puerta de madera"}),GENDER_FEMALE,
        ([P_MATERIAL:M_MADERA,P_DOOR_STATE:DOOR_CLOSED]));
    AddDoor("este","la puerta de la habitación de invitados",
        "Es una puerta de madera, adornada con paneles de cristal.\n",
        ({"puerta","puerta este","puerta de cristal"}),GENDER_FEMALE,
        ([P_MATERIAL:M_MADERA,P_DOOR_STATE:DOOR_CLOSED]));

  AddDetail("suelo","Puedes ver el reflejo de las lamparas sobre el suelo\n");
  AddDetail( ({"lampara","lamparas"}),
"Ves lamparas de diamante que cuelgan del techo y que despiden una luz "
"azulada.\n");
  AddDetail(({"paredes","pared",}),
"Al fijarte bien notas que las paredes, realmente, estan hechas de oro!\n");
  AddDetail(({"escalera","escaleras","sur"}),
 "Las escaleras se encuentran algo hacia el sur.\n");

  AddItem(MONS+"guardia",REFRESH_DESTRUCT,1);
}