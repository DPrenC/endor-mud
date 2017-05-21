/*    caimanp.c
	  Creado por : Nemesis
	  Fecha : 29-Dic-97
	  Descripcion : Mama caiman que esta por las alcantarillas.
	  Modificado por Nyh
*/
#include <living.h>
#include <combat.h>
#include <moving.h>
#include <gremios.h>

inherit NPC;

create() {
  ::create();
 SetStandard("un caim�n","cocodrilo",([ GC_LUCHADOR: 12 ]), GENDER_FEMALE);
  SetShort("mam� caim�n");
  SetLong(
"Es un caiman adulto. Mide mas de 3 metros de largo y esta cubierto de gruesas\n"
"escamas. Parece que ha perdido algo...\n");
  AddId(({"caiman","caim�n"}));
  SetAds(({"enorme","mama"}));
  SetAlign(0);
}