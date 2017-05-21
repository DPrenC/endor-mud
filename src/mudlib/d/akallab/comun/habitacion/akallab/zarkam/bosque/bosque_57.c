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
  SetIntShort("un claro en el bosque");
  SetIntLong(
  "A tu alrededor se extiende un paisaje desolado, vegetacion quemada o talada, "
  "utiles de batalla desperdigados por el suelo, cráneos aplastados, esqueletos "
  "mutilados o cuidadosamente empalados en un simbolo amenazante. Sin ninguna "
  "duda, largo tiempo atras, aqui hubo feroces y encarnizadas batallas. El  "
  "resultado de las mismas ha sido una zona del bosque destrozada y decenas de "
  "cadaveres en muestra de la suerte que corrieron los vencidos.\n");
  AddDetail(({"vegetacion","arboles","arbol"}),
  "Toda la vegetacion de la zona ha sido arrasada, quemada o talada. Aun asi "
  "en algunos lugares han vuelto a aparecer nuevos brotes verdes.\n");
  AddDetail(({"cuerpos","cadaveres","esqueletos"}),
  "Bastantes son los cuerpos, ya despojados de su carne, que pueblan este claro "
  "en el bosque. En su tiempo sirvieron de alimento a los animales carronyeros, "
  "ahora no sirven absolutamente para nada. Algunos incluso han sido empalados "
  "en muestra de la supremacia de la raza vencedora.\n");
  AddDetail(({"utiles","armas",""}),
  "Inutiles instrumentos de guerra, como viejas espadas o corroidas armaduras, "
  "llenan el suelo de tu alrededor. Ni siquiera los saqueadores se han dignado "
  "en recogerlos.\n");
  AddExit("sur",Z_BOSQUE("bosque_48"));
  AddExit("suroeste",Z_BOSQUE("bosque_47"));
  AddExit("sudeste",Z_BOSQUE("bosque_49"));
  AddExit("este",Z_BOSQUE("bosque_58"));
  AddExit("noroeste",Z_BOSQUE("bosque_62"));
  AddItem(PNJ("animal/lobo"),REFRESH_DESTRUCT);
  SetIndoors(0);
  SetIntSmell("Dado que la zona es abierta, el aire es limpio y no se ha corrompido.\n");
  SetIntNoise("No oyes nada, ni siquiera los animales se acercan a este lugar.\n");
  SetLocate("bosque de Zarkam");
}
