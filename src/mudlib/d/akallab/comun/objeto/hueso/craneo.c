/*
DESCRIPCION  : Un craneo
FICHERO      : /d/comun/objeto/hueso/craneo.c
MODIFICACION : 10-08-97 [angor] Creacion.
*/

#include "path.h"
inherit HUESO_DIR("std_hueso");

public create()
{
  ::create();
  SetTipoHueso("craneo");
  SetSexo(1);
  SetRazaHueso("humano");
  SetWC(random(2));
  SetAdjetivo("blanco");
  SetLong("Este es "+QueryShort()+".\n" //
  "Su duenyo no tendra nunca mas dolores de cabeza.\n");
  SetPesoHueso(500,100);
  SetValorHueso(40,10);
  AddId("craneo");
  AddId("calavera");
}
