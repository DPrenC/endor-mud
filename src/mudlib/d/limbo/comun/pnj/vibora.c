/*
DESCRIPCION  : vibora para el parque de novatos
FICHERO      : /d/limbo/comun/pnj/vibora.c
MODIFICACION : 10-08-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "./path.h"
inherit NPC;

create() {
  ::create();
  SetStandard("una vibora","serpiente",([ GC_TORPE: 4]),GENDER_FEMALE);
  SetShort("una vibora negra");
  SetLong(
"Es una vibora de color oscuro, casi negro. No es muy grande, pero te mira al\n"
"tiempo que olisquea el aire con una lengua bífida de color púrpura. Crees que\n"
"esta serpiente debe ser bastante peligrosa...\n");
  SetIds(({"serpiente","vibora","reptil"}));
  SetSize(P_SIZE_SMALL);
  SetAggressive(1);
  SetMaxHP(10+(QueryLevel()-1)*5);
  SetHP(QueryMaxHP());
  SetInt(1);
  SetStr(QueryStr()-2);
  SetDex(QueryDex()+2);
  SetHands(({ ({"colmillos",TD_PENETRACION,5}) }));
  SetNoGet(0);
  SetWeight(1000);
  SetGoChance(35);
}

