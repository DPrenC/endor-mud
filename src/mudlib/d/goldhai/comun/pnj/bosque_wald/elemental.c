/*********************************************************/
//		"elemental"
//	El mismo elemental de los conjuradores, copiado
//	tal cual
//		12-12-01: Kodex-> copia
//		12-12-01: Kodex-> última modificación
/*********************************************************/

inherit NPC;
#include <living.h>
#include <properties.h>

create()
{
  ::create();
 SetStandard("un elemental de fuego","frirel",35,GENDER_NEUTER);
  AddId("elemental");
  AddId("elemental de fuego");
  SetNoGet(1);
  SetAggressive(1);
}

