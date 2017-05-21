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
  SetShort("nidito de Mirill y Parsifal");
  Set(P_INT_LONG,
    (W("Este es el que será el nidito de casados de Mirill y Parsifal. Parece que aún "
    "lo están arreglando, porque todavía no se han casado. Te sientes muy cómodo "
    "aquí; te recuerda vagamente a alguna casa que has conocido y en la que te has "
    "sentido muy a gusto. La luz entra a raudales por las enormes ventanas. "
    "Te fijas en un sofá verde, con aspecto de haber sido testigo de más de una "
    "siesta antológica, una enorme mesa de madera de sequoia, gemela de la que "
    "Parsifal tiene en su pisito de soltera, y unos cuantos ordenadores colocados "
    "de cualquier manera en los sitios más inverosímiles. Delante de cada uno "
    "de ellos hay unos cómodos butacones forrados de cuero. "
    "De pronto, te apetece sentarte y descansar un rato."
    "\n")));

  AddDetail(
         ({"ordenadores","ordenador"}),
         W("Puedes apreciar que se trata de unos aparatos de enorme potencial. Quizá "
         "es mejor no saber a qué están conectados, y mucho mejor no tocarlos. "
         "\n"));

  AddDetail(
         ({"mesa","mueble"}),
         W("Es una hermosa mesa de madera de sequoia. Por encima tiene desperdigados "
         "bastantes papeles, planos, mapas y cartas, y unos cuantos ceniceros de "+
	 "jade llenos de envolturas de chicle y papelitos. Mejor no tocar nada."
         "\n"));

  AddDetail(
         ({"ventana","ventanas","ventanal"}),
         W("A través de las ventanas puedes ver casi todo Simauria. A tus pies se "
         "extiende el Limbo. Un poco más allá, entre bruma, puedes adivinar los "
         "bosques de Simauria, y, muy a lo lejos, más allá del mar, las dos islas "
         "que forman el pequeño dominio de Gwddnolyd. "
         "\n"));

  AddDetail(
         ({"butacón","butacon","butacones"}),
         W("Son unos cómodos butacones giratorios tapizados en cuero negro. Parecen "
         "bastante utilizados."
         "\n"));

  AddDetail(
         ({"sofa","sillón","sillon","sofá"}),
         W("Es un sofá verde nuevecito, pero con aspecto de haber servido de escenario "
         "para amodorradas siestas. Aunque te apetecería probarlo, no te atreves sin "
         "el permiso de sus propietarios.\n"));

//  AddItem("murcibl", REFRESH_REMOVE,1);

  SetIntBright(40);
  SetIndoors(1);

  AddExit("dormitorio","nido2");
  AddExit("cocina","nido3");
  AddExit("Parsifal","/players/parsifal/workroom");
  AddExit("Mirill","/players/mirill/workroom");
  AddExit("Gwddnolyd","/d/gwddnolyd/comun/habitacion/laberinto/lab1");
}
