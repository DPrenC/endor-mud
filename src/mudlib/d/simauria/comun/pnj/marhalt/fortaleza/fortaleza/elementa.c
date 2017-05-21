#include <living.h>
#include <properties.h>
#include "./path.h"
#include <gremios.h>

inherit NPC;

private object pOwner;

public object SetOwner(object ob) { return pOwner = ob; }
public object QueryOwner() { return pOwner; }

public int EsAmigo(object victim)
{
    if (!victim || !pOwner) return 0;
    return !member(pOwner->QueryEnemies() || ({}), victim) >= 0;
    return 1;
}

create() {
  ::create();
 SetStandard("un elemental de fuego","frirel",([GC_LUCHADOR: 25]),GENDER_NEUTER);
  AddId("elemental");
  AddId("elemental de fuego");
  SetNoGet(1);
  Set(P_NOBUY,1);
  SetFriendFunction(SF(EsAmigo));
  SetAggressive(2);
  call_out("destruir", 180);
}

public void destruir()
{
  DropHeart(HEART_USER);
  DropHeart(HEART_HEAL);
  tell_room(environment(),"Un elemental huye y desaparece.\n");	remove();
}
