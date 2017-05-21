
/*
 FECHA: 30/4/99
 AUTOR: Parsifal
 DESCRIPCION: Primera prueba del nidito de Limbo :)
*/


#include <properties.h>

inherit ROOM;

create () {
  ::create();
  Set(P_INT_SHORT, "el nidito de Mirill y Parsifal");
  Set(P_INT_LONG,
    "Estás en "
    " "
    " "
    " "
    " "
    " "
    " "
    " "
    " "
    " "
    "\n");
  AddDetail(
         ({"",""}),
         " "
         " "

      "\n");

  AddDetail(
         ({"","",""}),
         " "
         " "
	 " "
         " "
	 "\n");

  AddDetail(
         ({"ventana","ventanas","ventanal"}),
         "A través de las ventanas puedes ver casi todo Simauria. A tus pies se "
         "extiende el Limbo. Un poco más allá, entre bruma, puedes adivinar los "
         "bosques de Simauria, y, muy a lo lejos, más allá del mar, las dos islas "
         "que forman el pequeño dominio de Gwddnolyd. "
         "\n");

  AddDetail(
         ({"",""}),
         " "
         " "
         "\n");

  AddDetail(
         ({""}),
         " "
         " "
         " "
	 "\n");

  AddDetail(
         ({"","",""}),
         " "
         " "
	 " "
	 " "
         "\n");

  SetIntBright(40);
  SetIndoors(1);

  AddExit("salon","nido1");
  AddExit("baño","nido4");
  AddExit("balcon","nido5");
}
