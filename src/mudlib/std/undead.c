/** std/undead.c
 *  ============
 */

#include <properties.h> // P_...

inherit NPC;

public int SetStunned(int i)    { return ::SetStunned(0); }

create() {
  ::create();
  if (!clonep()) return;
  SetStandard("un no-muerto","no-muerto", 1,GENDER_NEUTER);
  SetIds(({"no-muerto"})); // Uno de los ids DEBE ser el tipo de no-muerto
  SetAds(({"un","feo","horrible"}));
  SetShort("un no-muerto");
  SetLong(
  "Es un ser de ultratumba. Murió, pero como puedes ver, sigue en un estado\n"
  "de no-vida. Sin duda es muy peligroso.\n");
}
