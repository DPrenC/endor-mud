
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
  Set(P_INT_SHORT, "ba�o del nidito de Mirill y Parsifal");
  Set(P_INT_LONG,
    W("Te encuentras en un hermoso y lujoso ba�o, con todas las comodidades que te "
    "puedas imaginar. En mitad de la habitaci�n hay un fant�stico jacuzzi, en el "
    "que si quieres meterte tienes que subir unos escalones. Hay una cabina de  "
    "ducha, un lavabo y un servicio, adem�s. Las paredes son de m�rmol, y unas "
    "altas columnas sujetan el techo. Te recuerda vagamente a las termas de unos "
    "ba�os turcos. Una puerta parece llevar a un cuarto de sauna. "
    "La luz entra por las enormes ventanas. Parece que a Mirill y a Parsifal les "
    "gusta bastante la luz y tienen poco temor de que les vean. "+

  "\n"));

  AddDetail(
         ({"lavabo"}),
         "Es un lavabo blanco. �Nunca hab�as visto uno? "
         "\n");

  AddDetail(
         ({"servicio","water","inodoro","vater","taza"}),
         "Es una taza de water. �Sabes para qu� sirve? �Y c�mo se utiliza? "
	 "\n");

  AddDetail(
         ({"ventana","ventanas","ventanal"}),
         "Ves que esta ventana da al lado opuesto de las de los otros cuartos. "
         "Desde aqu� puedes ver las monta�as de Kha-annu, tierra de enanos, y "
         "los inquietantes bosques de Kenton. Muy lejos, se adivina el mar. "
         "\n");

  AddDetail(
         ({"jacuzzi","ba�era","banyera"}),
         "Es un hermoso jacuzzi blanco, en lo alto de unos pocos escalones. Quiz� "
         "los propietarios no ver�an demasiado bien que te metieras en �l con todo "+
	 "el polvo del camino sobre el cuerpo. "
         "\n");

  AddDetail(
         ({"ducha","cabina"}),
         "Es una ducha con una historiada grifer�a. Aunque algo te dice que si te "
         "apetece ducharte, es mejor que busques otro lugar para hacerlo. "+
	 "\n");

  AddDetail(
         ({"columnas","columna"}),
         "Son unas hermosas columnas de m�rmol que sujetan el techo. "
         "\n");


  SetIntBright(40);
  SetIndoors(1);

  AddExit("sauna","nido6");
  AddExit("dormitorio","nido2");
}
