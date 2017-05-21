/*
DESCRIPCION  : Campos de cultivo.
FICHERO      : /d/akallab/comun/habitacion/akallab/zarkam/campos/campo_12.c
MODIFICACION : 19-03-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit Z_CAMPOS("campo");

create() {
  ::create();
  AddExit("norte",Z_CAMPOS("huerta_05"));
  AddExit("este",Z_CAMPOS("campo_13"));
  AddExit("sur",Z_CAMPOS("campo_15"));
  AddExit("oeste",Z_CAMPOS("huerta_04"));
  AddItem(PNJ("esclavo"), REFRESH_DESTRUCT,1);
}
