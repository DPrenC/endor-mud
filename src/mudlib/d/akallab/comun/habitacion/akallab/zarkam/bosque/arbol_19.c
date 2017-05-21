/*
DESCRIPCION  : Bosque
FICHERO      : /d/akallab/comun/habitacion/akallab/zarkam/bosque/arbol_??.c
MODIFICACION : ??-??-?? [Elric@Simauria] Creacion
               10-10-98 [Angor@Simauria] Varias modificaciones
--------------------------------------------------------------------------------
*/
#include "path.h"
inherit ROOM;

create() {
  ::create();
  SetIntShort("la copa del árbol");
  SetIntLong(
    "Estas en lo mas alto de un arbol, desde aqui tienes una buena vision del "
    "resto del bosque, puedes ver como cientos de frondosos arboles crecen "
    "hacia el norte hasta encontrarse con la cordillera de Kova. Gracias a tu "
    "posicion privilegiada divisas al nordeste lo que te parece una cabanya. "
    "Tambien al norte, pero antes de llegar a las montanyas ves un claro en el "
    "bosque, en el que no parece crecer ningun arbol.\n");

  AddDetail(({"cordillera","kova"}),
    "Tienes una magnifica vista de la cordillera de Kova, ves las altas montanyas "
    "del norte extendiendose de oeste a este e impidiendo el crecimiento del "
    "bosque en esa direccion.\n");

  AddDetail(({"cabanya"}),
    "No lo puedes afirmar con seguridad, pero parece que al nordeste, en un claro, "
    "hay una especie de cabanya.\n");

  AddDetail(({"claro"}),
    "No muy lejos de la zona en la que te encuentras, al norte, se extiende un "
    "claro despoblado totalmente de arboles. Aunque no lo distingues bien, parece "
    "que los arboles han sido talados.\n");

  SetIntNoise("El aire silba entre las hojas.\n");
  SetIntSmell("Uele a Naturaleza.\n");
  SetLocate("bosque de Zarkam");
  SetIndoors(0);

  AddExit("abajo",Z_BOSQUE("bosque_19"));

  AddItem(PNJ("animal/aguila"),REFRESH_HOME);
}



















