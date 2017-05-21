/*
DESCRIPCION  : Una tibia
FICHERO      : /d/comun/objeto/hueso/tibia.c
MODIFICACION : 10-08-97 [angor] Creacion.
*/

#include "path.h"
inherit HUESO_DIR("std_hueso");

public create()
{
  ::create();
  SetTipoHueso("tibia");
  SetSexo(2);
  SetAdjetivo("blanca");
  SetRazaHueso("orco");
  SetWC(6+random(2));
  SetLong("Esta es "+QueryShort()+".\n");
  SetPesoHueso(2000,500);
  SetValorHueso(100,20);
}
