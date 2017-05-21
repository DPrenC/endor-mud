/*   ratagig.c
     Descripcion: Rata gigante para las alcantarillas de Simauria City,
     Creada por : Nemesis
     Fecha :
        Modificado por Nyh
*/
#include <living.h>
#include <combat.h>
#include <moving.h>
#include <properties.h>

inherit NPC;

create() {
  ::create();
 SetStandard("una rata gigante","rata", 6, GENDER_FEMALE);
  SetShort("una rata gigante");
  SetLong(
  "Es una monstruosa rata que vive en las alcantarillas. Ha crecido de forma\n"
  "impresionante hasta alcanzar casi 2 metros de largo. Estas ante uno de los\n"
  "principales depredadores de este lugar.\n");
  AddId(({"rata"}));
  SetAds(({"enorme","gigantesca","peluda"}));
  SetSize(P_SIZE_MEDIUM);
  SetWeight(50000);
  SetAlign(0);
  InitChats(10,({
	"La rata te mira amenazadora.\n",
	"La rata te ensenya sus afilados dientes amarillos.\n",
	"Los ojos rojizos de la rata brillan amenazadoramente.\n",
	"La rata roe un hueso.\n"
	  }));
  InitAChats(10,({
	"La rata se lanza contra tus ojos!\n"
  }));
}