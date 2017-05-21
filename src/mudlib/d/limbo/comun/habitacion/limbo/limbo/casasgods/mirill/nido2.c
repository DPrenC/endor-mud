
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
  Set(P_INT_SHORT, "dormitorio del nidito de Mirill y Parsifal");
  Set(P_INT_LONG,
    W("Estás en el dormitorio de Mirill y Parsifal. Quizá no deberías estar aquí sin "
    "el permiso de alguno de los dos... Ves una cama del tamaño de un ring de pelea "
    "de kainoaks, hecha aunque algo revuelta, como si alguien se hubiera tumbado  "
    "sobre ella. Observas que la habitación es enorme. "
    "Hay además una estantería llena de trastos y una enorme y cálida alfombra. Un "
    "ordenador en un rincón tiene el salvapantallas activado. Por todas partes hay "
    "multitud de detalles muy personales... Sabes que si tocas algo, el Apocalipsis "
    "caerá sobre ti... "
    "La luz entra por los enormes ventanales, inundando todo de color. Ves que el  "
    "ventanal puede utilizarse como puerta hacia un hermoso balcón. "
    "\n"));
  AddDetail(
         ({"ordenadores","ordenador"}),
         "Puedes apreciar que se trata de unos aparatos de enorme potencial. Quizá "
         "es mejor no saber a qué están conectados, y mucho mejor no tocarlos. "
         "\n");

  AddDetail(
         ({"estantería","mueble","estanteria"}),
         "Dispuestos desordenadamente por la estantería puedes ver varias fotos de "
         "gente que quizá conozcas. Hay además multitud de diskettes, libros de todos "+
	 "los tamaños, colores y formas, unos cuantos relojes parados y varios botes "
         "llenos de bolígrafos sin tinta. "+
	 "\n");

  AddDetail(
         ({"ventana","ventanas","ventanal"}),
         "A través de las ventanas puedes ver casi todo Simauria. A tus pies se "
         "extiende el Limbo. Un poco más allá, entre bruma, puedes adivinar los "
         "bosques de Simauria, y, muy a lo lejos, más allá del mar, las dos islas "
         "que forman el pequeño dominio de Gwddnolyd. "
         "\n");

  AddDetail(
         ({"cama","catre"}),
         "Es una enorme y resistente cama de madera. Parece capaz de albergar a un "
         "regimiento entero... Tiene aspecto de ser cómoda y calentita. "
         "\n");

  AddDetail(
         ({"alfombra"}),
         "Es una enorme alfombra persa que llega casi de pared a pared. En el tejido "
         "puedes ver un símbolo que te resulta familiar: el murciélago blanco, el "
         "sello de Parsifal. "+
	 "\n");

  AddDetail(
         ({"fotos","foto","retrato"}),
         "Hay varias fotos... Parsifal y Mirill en Goldhai; Mirill en las obras de la "
         "catedral de Simauria con Khelben y Data; Parsifal con Greywolf y Usul en las "+
	 "obras del laberinto de Gwddnolyd y una de Parsifal con una dedicatoria para "+
	 "Mirill. Tiene una letra tan horrible que no puedes leerla. "
         "\n");

  SetIntBright(40);
  SetIndoors(1);

  AddExit("salon","nido1");
  AddExit("banyo","nido4");
  AddExit("balcon","nido5");
}
