
/*
 FECHA: 30/4/99
 AUTOR: Parsifal
 DESCRIPCION: Primera prueba del nidito de Limbo :)
*/


#include <rooms.h>
#include <stdrooms.h>
#include <properties.h>

inherit ROOM;


create () {
  ::create();
  Set(P_INT_SHORT, "cocina del nidito de Mirill y Parsifal");
  Set(P_INT_LONG,
    W("Estás en la cocina del nidito de Mirill y Parsifal. A pesar de ser enorme y "
    "de parecer bastante acogedora, no parece que se utilice mucho...  Caes en la "
    "cuenta de que los Dioses comen bastante poco, pues al ser inmortales no se "
    "preocupan de cosas tan terrenales como la comida, y que las Ladies, aparte de "
    "ser igualmente inmortales, tienen que cuidar la línea... "
    "Ves que hay unos cuantos muebles colgados de la pared, una cocina y una nevera, "
    "como en cualquier cocina. Hay además una mesa rodeada de unas cuantas sillas. "
    "Como el resto del nidito, tiene amplios ventanales que te permiten ver Simauria "
    "en todo su esplendor. Desde aquí también puedes salir al balcón. "
    "\n"));

  AddDetail(
         ({"nevera","frigorifico","frigorífico"}),
         "Es una nevera enorme y blanca, como una nevera cualquiera. Parece un poco "
         "desatendida. "
         "\n");

  AddDetail(
         ({"mesa","sillas","silla","mueble","muebles"}),
         "Es una mesa de madera normal y corriente, con seis sillas de la misma "
         "madera alrededor. Sobre la mesa y las sillas hay algunos papeles tirados "+
	 "sin orden ni concierto,con cosas escritas. "+
	 "\n");

  AddDetail(
         ({"ventana","ventanas","ventanal"}),
         "A través de las ventanas puedes ver casi todo Simauria. A tus pies se "
         "extiende el Limbo. Un poco más allá, entre bruma, puedes adivinar los "
         "bosques de Simauria, y, muy a lo lejos, más allá del mar, las dos islas "
         "que forman el pequeño dominio de Gwddnolyd. "+

"\n");

  AddDetail(
         ({"papel","papeles"}),
         "Ves algunas notas escritas con la letra de Parsifal, absolutamente incomprensibles "
         "y otras, con letra de Mirill, con listas de nombres geográficos. "
         "\n");


  SetIntBright(40);
  SetIndoors(1);

  AddExit("salon","nido1");
  AddExit("balcon","nido5");
}
