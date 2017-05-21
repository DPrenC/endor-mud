/*    Realizada por : Cajun, el ejecutor
      Creado : 22-10-98
      Modificado por Nyh
*/

#include <rooms.h>
#include <properties.h>

inherit NPC;

create() {
  ::create();
  SetStandard("una mariposa","mariposa",1,GENDER_FEMALE);
  SetShort("una mariposa juguetona");
  SetLong(
"Una pequenya mariposa vuela a tu alrededor. Posandose sobre algunas flores.\n");
  SetWeight(2);
  SetAlign(0);
}
