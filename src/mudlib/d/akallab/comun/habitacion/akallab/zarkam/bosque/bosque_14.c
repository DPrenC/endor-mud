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
 SetIntShort("una zona menos frondosa del bosque");
  SetIntLong(
    "Te encuentras entre arboles, arbustos y matojos, aunque esta no es una zona muy "
    "poblada. Los pocos arboles que puedes ver no son suficientes para tapar por "
    "completo el cielo. Una hilera de rocas y un pequenyo desnivel te impiden el paso "
    "hacia el norte y hacia el sur, formando una especie de camino de este a oeste, "
    "que tal vez fue utilizado antanyo.\n");

  AddDetail(({"arbol","arboles","copas"}),
    "Grandes arboles forman este bosque. Aunque en esta zona hay mas bien pocos.\n");

  AddDetail(({"piedras","piedra","roca","rocas"}),
    "Al sur ves una fila de piedras, grandes y pequenyas. Sobre todo grandes "
    "que te impide el paso.\n");

  AddDetail(({"desnivel"}),
    "Al norte hay un pequenyo desnivel de tierra, no es muy alto, pero la tierra "
    "esta suelta y cualquier intento de subir por el es inutil.\n");

  SetIntNoise("Se oye rumor agua proviniente del este.\n");
  SetIntSmell("El aire esta humedo.\n");
  SetLocate("bosque de Zarkam");
  SetIndoors(0);

  AddExit("este",Z_BOSQUE("bosque_15"));
  AddExit("oeste",Z_BOSQUE("bosque_13"));

  AddItem(PNJ("animal/liebre"),REFRESH_DESTRUCT);
}
