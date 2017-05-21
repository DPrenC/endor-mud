/*
DESCRIPCION  : Campos de cultivo.
FICHERO      : /d/akallab/comun/habitacion/akallab/zarkam/campos/campo_06.c
MODIFICACION : 19-03-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit Z_CAMPOS("campo");

create() {
  ::create();
  AddExit("norte",Z_CAMPOS("c_camp09"));
  AddExit("este",Z_CAMPOS("huerta_02"));
  AddExit("sur",Z_CAMPOS("huerta_01"));
  AddExit("oeste",Z_CAMPOS("campo_05"));
}
