/*
DESCRIPCION  : Campos de cultivo.
FICHERO      : /d/akallab/comun/habitacion/akallab/zarkam/campos/campo_13.c
MODIFICACION : 19-03-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit Z_CAMPOS("campo");

create() {
  ::create();
  AddExit("norte",Z_CAMPOS("campo_10"));
  AddExit("oeste",Z_CAMPOS("campo_12"));
}
