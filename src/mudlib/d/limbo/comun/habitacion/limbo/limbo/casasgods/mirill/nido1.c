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
    (W("Este es el que ser� el nidito de casados de Mirill y Parsifal. Parece que a�n "
    "lo est�n arreglando, porque todav�a no se han casado. Te sientes muy c�modo "
    "aqu�; te recuerda vagamente a alguna casa que has conocido y en la que te has "
    "sentido muy a gusto. La luz entra a raudales por las enormes ventanas. "
    "Te fijas en un sof� verde, con aspecto de haber sido testigo de m�s de una "
    "siesta antol�gica, una enorme mesa de madera de sequoia, gemela de la que "
    "Parsifal tiene en su pisito de soltera, y unos cuantos ordenadores colocados "
    "de cualquier manera en los sitios m�s inveros�miles. Delante de cada uno "
    "de ellos hay unos c�modos butacones forrados de cuero. "
    "De pronto, te apetece sentarte y descansar un rato."
    "\n")));

  AddDetail(
         ({"ordenadores","ordenador"}),
         W("Puedes apreciar que se trata de unos aparatos de enorme potencial. Quiz� "
         "es mejor no saber a qu� est�n conectados, y mucho mejor no tocarlos. "
         "\n"));

  AddDetail(
         ({"mesa","mueble"}),
         W("Es una hermosa mesa de madera de sequoia. Por encima tiene desperdigados "
         "bastantes papeles, planos, mapas y cartas, y unos cuantos ceniceros de "+
	 "jade llenos de envolturas de chicle y papelitos. Mejor no tocar nada."
         "\n"));

  AddDetail(
         ({"ventana","ventanas","ventanal"}),
         W("A trav�s de las ventanas puedes ver casi todo Simauria. A tus pies se "
         "extiende el Limbo. Un poco m�s all�, entre bruma, puedes adivinar los "
         "bosques de Simauria, y, muy a lo lejos, m�s all� del mar, las dos islas "
         "que forman el peque�o dominio de Gwddnolyd. "
         "\n"));

  AddDetail(
         ({"butac�n","butacon","butacones"}),
         W("Son unos c�modos butacones giratorios tapizados en cuero negro. Parecen "
         "bastante utilizados."
         "\n"));

  AddDetail(
         ({"sofa","sill�n","sillon","sof�"}),
         W("Es un sof� verde nuevecito, pero con aspecto de haber servido de escenario "
         "para amodorradas siestas. Aunque te apetecer�a probarlo, no te atreves sin "
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
