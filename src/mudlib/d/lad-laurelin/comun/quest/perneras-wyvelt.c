/* Perneras de c�scara de huevo de Wyvelt
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

  if (env && !env->QueryIndoors()) return 25;
  return 20;
}

create()
{
  ::create();
 SetStandard(AT_PANTALONES, 1, P_SIZE_MEDIUM, M_ESPECIAL);
  SetShort("unas perneras de Wyvelt");
  SetLong(W("Son unas perneras hechas con la c�scara de un huevo "
  	"de Wyvelt y labradas h�bilmente. T�n s�lo ese material "
  	"puede darle esa dureza con una ligereza y flexibilidad "
  	"tan extremas. Sientes c�mo su dureza y resistencia cambia "
  	"en funci�n del lugar donde est�. Si estas al aire libre "
  	"tiene m�yor dureza\n"));
  SetIds(({"pernera", "perneras", "pernera de wyvelt", "perneras de wyvelt"}));
  SetValue(150000);
  SetWeight(8000);
  SetAPperQP(100);
  Set(P_GENDER, GENDER_FEMALE);
}
