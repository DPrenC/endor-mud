/*
DESCRIPCION  : Campos de cultivo.
FICHERO      : /d/akallab/comun/habitacion/akallab/zarkam/campo/huerta_00.c
MODIFICACION : 20-03-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit Z_CAMPOS("huerta");

create() {
  ::create();
  AddExit("norte",Z_CAMPOS("huerta_01"));
  AddExit("oeste",Z_CAMPOS("campo_11"));
}
