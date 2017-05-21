/*
DESCRIPCION  : Rodor, el propietario de la fonda el "Viejo Pescador"
FICHERO      : /d/limbo/comun/pnj/rodor.c
MODIFICACION : 15-09-98 [Angor@Simauria]Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit NPC;

create() {
  ::create();
  SetStandard("Rodor","humano",5,GENDER_MALE);
  SetShort("Rodor, el propietario de la fonda el 'Viejo Pescador'");
  SetLong(
 "Rodor es el anciano humano propietario de la fonda el 'Viejo Pescador'. Lleva la\n"
 "típica vestimenta que lo identifica como un miembro de los dioses, una larga\n"
 "túnica blanca recorrida por una ancha banda roja vertical. Rodor un tipo alegre\n"
 "y tranquilo que se toma su tiempo para charlar con sus clientes.\n");

  SetGoChance(0);

  SetAlign(500);
  SetAC(5);
  SetMaxHP(70);
  SetHP(70);

  SetIds(({"rodor"}));
  AddId("posadero");
  AddId("propietario");
  AddId("humano");

  InitChats(3,({
// --------------------------------------------------------------------------------
  "Rodor te dice: 'Si quieres ver la lista de las comidas, mira el menú'.\n",
  "Un cliente dice: '¡Rodor, esto estaba muy bueno, trae otro de lo mismo!'.\n",
  "Rodor se va hacia una mesa al fondo de la fonda.\n",
  "Rodor le dice a un cliente: '¡Marchando su comida!'\n",
  "Rodor se para a charlar un momento con un cliente.\n",
  "Rodor te dice: 'Tras elegir tu comida, simplemente pídela y te la serviré'.\n",
  "Rodor entra en la cocina y al momento sale cargado con varias fuentes y jarras'.\n",
  "Un cliente grita: '¡Hey Rodor, a ver cuando vienes a atender aquí de una vez!'\n" }) );
}
