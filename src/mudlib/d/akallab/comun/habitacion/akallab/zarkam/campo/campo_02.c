/*
DESCRIPCION  : Campos de cultivo.
FICHERO      : /d/akallab/comun/habitacion/akallab/zarkam/campos/campo_02.c
MODIFICACION : 19-03-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit Z_CAMPOS("campo");

create() {
  ::create();
  AddExit("sur",Z_CAMPOS("campo_04"));
  AddExit("este",Z_CAMPOS("campo_03"));
  AddItem(PNJ("esclavo"), REFRESH_DESTRUCT,1);
}
