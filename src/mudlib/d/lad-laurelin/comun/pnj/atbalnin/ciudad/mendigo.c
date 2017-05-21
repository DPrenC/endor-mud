#include <rooms.h>
#include <properties.h>
#include "path.h"

inherit NPC;

create()
{
  ::create();

  SetStandard("un mendigo", "humano", 4, GENDER_MALE);
  SetShort("un mendigo");
  SetLong(
  "Es un andrajoso mendigo. Sus ropas hace tiempo que dejaron de serlo para\n"
  "pasar a ser trapos sucios y rotos. Las barbas le llegan m�s o menos a\n"
  "la mitad del escu�lido pecho, y se podr�a decir que no est�n demasiado\n"
  "cuidadas. Y el olor mejor lo dejamos. �Que esperabas? Es un mendigo.\n");
  AddId("mendigo");

  InitChats(1,({
   "El mendigo se levanta del suelo. Un poquito despu�s, se vuelve a sentar.\n",
   "El mendigo se rasca la barba, y luego se mira la mano con expresi�n de sorpresa.\n",
   "El mendigo se hurga la nariz con mucha pasi�n...\n",
   "Un mendigo: Caridad para los pobres...\n",
   "Un mendigo: Algo para comer.\n",
  }));
}

