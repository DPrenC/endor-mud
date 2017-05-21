/* Casco de cáscara de huevo de Wyvelt
   Theuzifan, 23-03-00
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

  if (env && !env->QueryIndoors()) return 15;
  return 10;
}

create()
{
  ::create();
 SetStandard(AT_CASCO, 1, P_SIZE_MEDIUM, M_ESPECIAL);
  SetShort("una casco de Wyvelt");
  SetLong(W("Es una bonto y resistente casco hecho con la cáscara de un huevo "
  	"de Wyvelt. Tán sólo ese material puede darle esa dureza con "
  	"esa ligereza.\n"));
  SetIds(({"casco", "casco de wyvelt"}));
  SetValue(150000);
  SetAPperQP(100);
  Set(P_GENDER, GENDER_FEMALE);
}
