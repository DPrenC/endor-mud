/*
DESCRIPCION : establo de la posada
FICHERO     : /d/akallab/comun/habitacion/akallab/zarkam/posada/establo.c
MODIFICACION: 15-10-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
#include "./posada.h"
inherit ROOM;

create() {
  ::create();
  SetIntShort("el pasillo de la posada");
  SetIntLong(
     "Te encuentras en el establo de la posada "+POS_NOM+". Es una especie de "
     "gran cobertizo donde los huespedes de la posada pueden dejar sus monturas. El "
     "suelo esta cubierto de una gruesa capa de paja que se cambia regularmente. El "
     "edificio de la posada queda al sur y al norte hay una gran puerta de madera "
     "permite salir al exterior.\n");

  AddDetail(({"posada"}),"El edificio de la posada queda al sur del establo.\n");
  AddDetail(({"paja","suelo"}),
    "Todo el suelo del establo esta cubierto de una gruesa capa de paja. El posadero "
    "limpia regularmente el establo cada pocos dias y renueva la paja. De esta forma "
    "esta limpio de los excrementos que dejan los animales.\n");

  SetIntNoise("Oyes a los caballos relinchar.\n");
  SetIntSmell("Hmm.. huele a comida.\n");
  SetLocate("ciudad de Zarkam");
  SetIndoors(1);
  SetIntBright(50);

  AddItem(PNJ("animal/caballo"), REFRESH_DESTRUCT, 2);
  AddExit("norte",Z_CIUDAD("calle_29"));
  AddExit("sur",Z_POSADA("pasillo00"));
}
