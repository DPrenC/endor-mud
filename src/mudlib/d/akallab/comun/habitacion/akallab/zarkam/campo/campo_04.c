/*
DESCRIPCION  : Campos de cultivo.
FICHERO      : /d/akallab/comun/habitacion/akallab/zarkam/campos/campo_04.c
MODIFICACION : 19-03-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit Z_CAMPOS("campo");

create() {
  ::create();
  AddExit("norte",Z_CAMPOS("campo_02"));
  AddExit("este",Z_CAMPOS("campo_05"));
  AddExit("sur",Z_CAMPOS("campo_08"));
}
