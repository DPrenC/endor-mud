
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
  Set(P_INT_SHORT, "balcón del nidito de Mirill y Parsifal");
  Set(P_INT_LONG,
    W("Estás en el exterior del nidito de Mirill de Parsifal. Es un balcón alargado "
    "que discurre todo a lo largo del muro, que disfruta de una maravillosa vista "
    "de la mitad de Simauria. La otra mitad la puedes ver desde el otro lado del "
    "balcón. "
    "Las descripciones hacia el norte, sur, este y oeste las debe poner Mirill que "
    "es el que sabe cómo está distribuido el mundo. Parsi es capaz de poner Goldhai "
    "en la dirección de Kha-annu, pues no tiene ni la más remota idea de dónde está "
    "Goldhai, así que esto lo deja para su prometido. "
    "\n"));

  AddDetail(
         ({"Kenton",
"Flenton"}),
         " "
         " "
         "\n");

  AddDetail(
         ({"Kha-annu"}),
         " "
         " "
	     " "
         " "
	 "\n");

  AddDetail(
         ({"Goldhai"}),
         " "
         " "
         " "
         " "
         "\n");

  AddDetail(
         ({"Limbo"}),
         " "
         " "
         "\n");

  AddDetail(
         ({"Gwddnolyd"}),
         " "
         " "
         " "
	 "\n");

  AddDetail(

         ({"Lad-laurelin"}),
         " "
         " "
	     " "
	     " "
         "\n");

  SetIntBright(40);
  SetIndoors(1);

  AddExit("balcon","nido5");
}
