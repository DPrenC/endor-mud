/*
 * Archivo std para la Avenida de Lad-Laurelin.
 * Creado por : Nemesis
 * Fecha : 4-Nov-98
 * Comentarios : Supongo que esta parte la hizo Saavik.
 *               No me extranya que suspendieras INS:
 *               'En la programacion orientada a objetos, los objetos son VAGOS.
 *               Hacen las menos cosas posibles!' Vicente Pelechano.
 *               Si es que no te enteras.
 *               Si no la hizo Saavik, pues me da igual.
 *               Al responsable: para la proxima ya lo sabes: te creas un
 *               archivito estandar y heredas de ahi todo lo que quieras que
 *               hagan tus habitaciones...
 */

#include "../path.h"

inherit SIM_ROOM;

create () {
  ::create();

SetLocate("Simauria Capital");
SetIntShort("la avenida Lad-Laurelin");
SetIntLong("Estas en la populosa Avenida de Lad-Laurelin.\n"
);
SetIndoors(0);
SetIntNoise("El bullicio de la gente y del mercado lo llenan todo\n");

SetIntSmell("Diversos olores flotan en el ambiente: verduras, sudor, comida rapida...\n");

AddDetail(
({"avenida","avenida de Lad-Laurelin","calle","Avenida de Lad-Laurelin",
  "avenida de lad-laurelin","avenida de ladlaurelin","avenida de Lad-laurelin",
  "avenida de lad","avenida de lad-Laurelin" }),
"Es una de las 4 avenidas principales de Simauria. Se llama asi porque lleva "
"directamente a la Puerta de Lad-Laurelin. Distingues a mucha gente moviendose "
"en todas direcciones, yendo a sus negocios o simplemente paseando.\n");
AddDetail(({"gente"}),
"Practicamente todos son humanos. Cada cual va a la suya y no parecen tener "
"tiempo que perder en conversaciones inutiles.\n");
AddDetail(({"tiendas"}),
"Aqui estan las tiendas principales de Simauria. Gentes de todo el Reino vienen "
"aqui para comprar mercancias exoticas y de la mejor calidad.\n");

}
