/*
DESCRIPCION  : un guardia troll (callado)
FICHERO      : /d/akallab/comun/pnj/k_cueva/guardia2.c
MODIFICACION : 24-11-99 [Angor@Simauria] Creacion
*/

#include "path.h"
#include <gremios.h>


inherit PNJ("k_cueva/guardia");

create() {
  ::create();
 SetLevel(25);
  SetStr(30);
  SetInt(10);
  SetCon(20);
  SetDex(30);
  SetAC(12);
  SetAggressive(1);
  SetAttackChance(1000);
  SetGoChance(0);
  SetGuild(GC_LUCHADOR);
  InitChats(8,({}));
}
