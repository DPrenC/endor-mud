/*
DESCRIPCION  : Campos de cultivo.
FICHERO      : /d/akallab/comun/habitacion/akallab/zarkam/campos/campo_10.c
MODIFICACION : 19-03-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit Z_CAMPOS("campo");

create() {
  ::create();
  AddExit("norte",Z_CAMPOS("c_camp05"));
  AddExit("sur",Z_CAMPOS("campo_13"));
  AddExit("oeste",Z_CAMPOS("huerta_05"));
  AddItem(PNJ("esclavo"), REFRESH_DESTRUCT,2);
}
