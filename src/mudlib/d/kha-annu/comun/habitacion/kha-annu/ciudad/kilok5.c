#include "./path.h"

inherit KHA_ROOM;

create() {
   ::create();

   SetIntShort("la calle Kilok");
   SetIntLong(
"Te encuentras en frente de la herborister�a de la ciudad. Al norte y al sur contin�a "
"esta calle: al sur hacia el cruce con la avenida Grimly, y al norte hacia el puente que "
"cruza el r�o Gaut-Kilok.\n");

  AddDetail(({"panaderia","tienda de pan", "panader�a"}),
"Desde aqu� solo puedes percibir el olor que sale de ella.\n");
  AddDetail(({"herbolario","tienda de hierbas", "herborister�a", "herboristeria"}),
"No puedes examinarla con mucho detalle, pero no parece demasiado grande.\n");
    SetIntBright(80);
    SetIndoors(1);
    SetIntSmell("Hay un delicioso olor a harina en el ambiente, mezclado con un aroma a especias.\n");
    AddExit("norte",CIUDAD+"kilok6");
    AddExit("sur",CIUDAD+"kilok4");
    AddExit("oeste",CIUDAD+"tiendas/tienda5");
    AddExit("este",CIUDAD+"tiendas/banco");


  SetLocate("Kha-annu");
}
