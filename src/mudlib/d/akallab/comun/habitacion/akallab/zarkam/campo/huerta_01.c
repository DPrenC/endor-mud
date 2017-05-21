/*
DESCRIPCION  : Campos de cultivo.
FICHERO      : /d/akallab/comun/habitacion/akallab/zarkam/campo/huerta_01.c
MODIFICACION : 20-03-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit Z_CAMPOS("huerta");

create() {
  ::create();
  AddExit("sur",Z_CAMPOS("huerta_00"));
  AddExit("oeste",Z_CAMPOS("campo_09"));
  AddExit("norte",Z_CAMPOS("campo_06"));
  AddExit("nordeste",Z_CAMPOS("huerta_02"));
  AddItem(PNJ("esclavo"), REFRESH_DESTRUCT,2);
}
