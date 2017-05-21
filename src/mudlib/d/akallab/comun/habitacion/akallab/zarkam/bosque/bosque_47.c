/*
DESCRIPCION  : Bosque al nordeste de Zarkam.
FICHERO      : /d/akallab/comun/habitacion/akallab/zarkam/bosque/bosque_47.c
MODIFICACION : 13-04-98 [Elric@Simauria] Creacion
               10-10-98 [Angor@Simauria] Varias modificaciones
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit ROOM;

create() {
  ::create();
  SetIntShort("el interior del bosque");
  SetIntLong(
    "La espesa arboleda te hace dificil ver el cielo. No sabrias distinguir si en "
    "estos momentos es de dia o de noche. El suelo esta lleno de ramas, hojas y "
    "guijarros que crujen bajo tus pies. Este bosque es un mal lugar para los "
    "viajeros que se despistan del camino, ya que esta plagado de animales que no "
    "durarian en comerte los higados. "
    "Al nordeste los arboles comienzan a abrirse para dar lugar a lo que parece un "
    "claro.\n");

  AddDetail(({"ramas","hojas","guijarros"}),
    "Todo el suelo esta cubierto por ramas, hojas y guijarros formando un espeso "
    "manto que cruje bajo tus pies al pisarlo.\n");

  AddDetail(({"arboles","arbol"}),
    "Los grandes arboles que forman el bosque, te impiden ver el exterior. Asi es "
    "muy facil perder la nocion del tiempo.\n");

  AddDetail(({"claro"}),
    "En la lejania, al nordeste, los arboles empiezan a separarse; parece que hay "
    "un claro.\n");

  SetIntSmell("El olor es agradable.\n");
  SetIntNoise("Oyes como el viento mece las ramas de los arboles.\n");
  SetLocate("bosque de Zarkam");
  SetIndoors(1);
  SetIntBright(0);

    AddExit("nordeste",Z_BOSQUE("bosque_57"));
    AddExit("sur",Z_BOSQUE("bosque_37"));
    AddExit("sudeste",Z_BOSQUE("bosque_38"));
    AddItem(PNJ("animal/liebre"),REFRESH_DESTRUCT);
    AddItem(PNJ("z_valle/gadline"),REFRESH_DESTRUCT);
}
