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
     "El camino continua avanzando por el interior de este denso e inquietante bosque. "
     "En el suelo ves claras las marcas dejadas por los carros cargados de madera que "
     "van de la serreria a la ciudad de Zarkam. Observas como se abre un claro en el "
     "bosque al oeste de aqui. Al noroeste de aqui ves una extranya construccion de "
     "madera sobre un gran arbol. El camino avanza desde el sudeste hacia el norte.\n");

  AddDetail(({"arbol","arboles","cabanya","construccion"}),
     "De entre todos los arboles, el que mas te llama la atencion es uno que se "
     "encuentra situado al noroeste de tu posicion y en el que, al parecer, hay una "
     "construccion de madera en su copa.\n");

  AddDetail(({"marcas"}),
     "Son profundos surcos en el suelo del camino dejados por las carretas.\n");

  SetIntNoise("Oyes crujir las ramas bajo tus pies.\n");
  SetIntSmell("El olor a naturaleza es omnipresente.\n");
  SetLocate("bosque de Zarkam");
  SetIndoors(0);

  AddExit("norte",Z_BOSQUE("bosque_41"));
  AddExit("este",Z_BOSQUE("bosque_32"));
  AddExit("sudeste",Z_BOSQUE("bosque_22"));
  AddExit("oeste",Z_BOSQUE("bosque_30"));
  AddExit("noroeste",Z_BOSQUE("bosque_40"));
  AddItem(PNJ("animal/oso"),REFRESH_DESTRUCT);
}
