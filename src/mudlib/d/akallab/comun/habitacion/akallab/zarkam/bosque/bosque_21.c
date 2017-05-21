/*
DESCRIPCION  : Bosque al nordeste de Zarkam.
FICHERO      : /d/akallab/comun/habitacion/akallab/zarkam/bosque/bosque_??.c
MODIFICACION : 13-04-98 [Elric@Simauria] Creacion
               10-10-98 [Angor@Simauria] Varias modificaciones
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit ROOM;

create() {
  ::create();
  SetIntShort("el camino interior");
  SetIntLong(
"Este camino transcurre por el interior del bosque, entre arboles, maleza "
"y arbustos. Esta formado de tierra y puedes aprecias en el unas debiles "
"huellas que, deduces, han sido provocadas por un carro. "
"El camino transcurre desde el sudoeste al este, tal vez seria aconsejable "
"no salirte de el.\n");
  SetIndoors(0);
  AddExit("sur",Z_BOSQUE("bosque_12"));
  AddExit("este",Z_BOSQUE("bosque_22"));
  AddExit("oeste",Z_BOSQUE("bosque_20"));
  AddExit("suroeste",Z_BOSQUE("bosque_11"));

  AddDetail(({"arbol","arboles"}),
  "Grandes arboles forman este bosque. Por suerte, en esta zona estan lo "
  "suficientemente separados como para que no impidan la entrada del sol, "
  "de lo contrario sus copas no te dejarian distinguir si es de noche o de "
  "dia.\n");
  AddDetail(({"camino"}),
  "Ves como un camino se interna entre los arboles. Se trata de un camino "
  "de tierra que parece haber sido utilizado no hace mucho tiempo.\n");
  AddDetail(({"huellas","ruedas"}),
  "Te arrodillas para contemplar las huellas. Son muy tenues, aunque no logras "
  "diferenciar si es obra natural o si han sido borradas deliberadamente.\n");
  AddDetail(({"maleza","arbustos"}),
  "Lo tipico de un bosque, muchas hojas verdes, algunos pinchos, ramas y "
  "nada interesante que te llame la atencion.\n");
  SetIntNoise("Oyes el cantico de los pajaros.\n");
  SetIntSmell("El aire esta limpio y fragante...\n");
  SetLocate("bosque de Zarkam");
}
