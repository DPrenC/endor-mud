
#include <rooms.h>

#include <properties.h>
#include "path.h"

inherit ROOM;
create(){
  ::create();
  SetIndoors(1);
  SetIntBright(50);
  SetLocate("bosqueDehim");
  SetIntSmell("Huele a rancio.\n");
  SetIntShort("una cabaña abandonada");
  SetIntLong("Te encuentras en una pequeña cabaña construida burdamente con roca. "
  		"En sus paredes hay grandes boquetes que han producido desprendimientos "
  		"de piedras. Hay una mesa rota volcada en el suelo y una cama. Las "
  		"telarañas cubren el resto de muebles que están parcialmente destruidos.\n");
  AddDetail(({"mesa"}),"Parece que era una mesa para comer.\n");
  AddDetail(({"cama"}),"No tiene sábanas y es pequeña y humilde.\n");

  AddItem(ALUOBJ("comida/baya"));
  AddItem(ALUOBJ("comida/baya"));

  AddExit("norte",ALULAGO("bosque/bosque3"));
  AddExit("sur",ALULAGO("bosque/bosque15"));
  AddExit("este",ALULAGO("bosque/bosque10"));
  AddExit("oeste",ALULAGO("bosque/bosque8"));
}