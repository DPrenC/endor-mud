/*
DESCRIPCION  : Campos de cultivo.
FICHERO      : /d/akallab/comun/habitacion/akallab/zarkam/campos/campo_07.c
MODIFICACION : 19-03-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit Z_CAMPOS("campo");

create() {
  ::create();
  AddExit("norte",Z_CAMPOS("huerta_06"));
  AddExit("oeste",Z_CAMPOS("c_camp05"));
  AddItem(PNJ("esclavo"), REFRESH_DESTRUCT,1);
}
