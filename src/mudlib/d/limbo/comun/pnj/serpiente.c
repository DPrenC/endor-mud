/*
DESCRIPCION  : serpiente para el parque de novatos, ahora es culebra :-p
FICHERO      : /d/limbo/comun/pnj/serpiente.c
MODIFICACION : 08-08-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "./path.h"
inherit NPC;

create() {
  ::create();
  SetStandard("una culebra","culebra",([ GC_TORPE: 1]),GENDER_FEMALE);
  SetShort("una culebra");
  SetLong("Es una culebra de color verde oscuro que te mira fijamente. No te fies...\n");
  SetIds(({"culebra","serpiente","reptil"}));
  SetSize(P_SIZE_SMALL);
  SetMaxHP(10+(QueryLevel()-1)*5);
  SetHP(QueryMaxHP());
  SetInt(1);
  SetHands(({ ({"colmillos",TD_PENETRACION,1}) }));
  SetNoGet(0);
  SetWeight(1000);
  SetGoChance(30);
}

