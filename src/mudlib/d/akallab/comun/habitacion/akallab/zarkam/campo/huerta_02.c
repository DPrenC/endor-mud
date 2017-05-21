/*
DESCRIPCION  : Campos de cultivo.
FICHERO      : /d/akallab/comun/habitacion/akallab/zarkam/campo/huerta_02.c
MODIFICACION : 20-03-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit Z_CAMPOS("huerta");

create() {
  ::create();
  AddExit("suroeste",Z_CAMPOS("huerta_01"));
  AddExit("oeste",Z_CAMPOS("campo_06"));
  AddExit("norte",Z_CAMPOS("c_camp08"));
  AddExit("nordeste",Z_CAMPOS("c_camp06"));
  AddItem(PNJ("esclavo"), REFRESH_DESTRUCT,1);
}
