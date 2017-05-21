/* Coraza de cáscara de huevo de Wyvelt
   Theuzifan, 30-09-99
*/

inherit ARMOUR;
#include <materials.h>
#include "path.h"
#include <combat.h>
#include <properties.h>

int QueryAC()
{
  object env, env2;

  env2=env=environment();
  while(env2)
  {
    env=env2;
    env2=environment(env2);
  }

  if (env && !env->QueryIndoors()) return 25;
  return 20;
}

create()
{
  ::create();
 SetStandard(AT_CORAZA, 1, P_SIZE_MEDIUM, M_ESPECIAL);
  SetShort("una coraza de Wyvelt");
  SetLong(W("Es una coraza muy especial hecha con la cáscara de un huevo "
  	"de Wyvelt. Tán sólo ese material puede darle esa dureza con "
  	"esa ligereza.\n"));
  SetIds(({"coraza", "coraza de wyvelt"}));
  SetValue(200000);
  SetAPperQP(100);
  Set(P_GENDER, GENDER_FEMALE);
}
