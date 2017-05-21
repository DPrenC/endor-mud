/*
DESCRIPCION  : Campos de cultivo.
FICHERO      : /d/akallab/comun/habitacion/akallab/zarkam/campos/campo_11.c
MODIFICACION : 19-03-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit Z_CAMPOS("campo");

create() {
  ::create();
  AddExit("norte",Z_CAMPOS("campo_09"));
  AddExit("este",Z_CAMPOS("huerta_00"));
  AddItem(PNJ("esclavo"), REFRESH_DESTRUCT,3);
}
