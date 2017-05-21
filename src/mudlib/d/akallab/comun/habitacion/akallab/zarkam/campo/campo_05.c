/*
DESCRIPCION  : Campos de cultivo.
FICHERO      : /d/akallab/comun/habitacion/akallab/zarkam/campos/campo_05.c
MODIFICACION : 19-03-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit Z_CAMPOS("campo");

create() {
  ::create();
  AddExit("norte",Z_CAMPOS("campo_03"));
  AddExit("este",Z_CAMPOS("campo_06"));
  AddExit("sur",Z_CAMPOS("campo_09"));
  AddExit("oeste",Z_CAMPOS("campo_04"));
  AddItem(PNJ("esclavo"), REFRESH_DESTRUCT,2);
}
