#include <rooms.h>
#include <properties.h>
#include "path.h"

inherit NPC;

create()
{
  ::create();

  SetStandard("Lainor", "elfo", 8, GENDER_MALE);
  SetLong(
  "Lainor es un elfo bastante alto. El pelo blanco le llega mas o menos hasta\n"
  "los hombros, y alrededor del cuello lleva un pesado medallon.\n");
  SetIds(({"lainor", "anciano"}));

  InitChats(1,({
   "Lainor se rasca la cabeza.\n",
   "Lainor levanta la vista al cielo y mira hacia arriba.\n",
   "Lainor te mira. Tiene una mirada intensa.\n"
  }));
}

