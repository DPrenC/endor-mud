/*
DESCRIPCION  : Campos de cultivo.
FICHERO      : /d/akallab/comun/habitacion/akallab/zarkam/campo/huerta_06.c
MODIFICACION : 20-03-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit Z_CAMPOS("huerta");

create() {
  ::create();
  AddExit("suroeste",Z_CAMPOS("c_camp05"));
  AddExit("sur",Z_CAMPOS("campo_07"));
}
