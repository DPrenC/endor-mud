/*
DESCRIPCION  : Campos de cultivo.
FICHERO      : /d/akallab/comun/habitacion/akallab/zarkam/campos/campo_01.c
MODIFICACION : 19-03-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit Z_CAMPOS("campo");

create() {
  ::create();
  AddExit("oeste",Z_CAMPOS("c_camp07"));
  AddExit("sur",Z_CAMPOS("c_camp06"));
  AddExit("este",Z_CAMPOS("huerta_03"));
  AddItem(PNJ("esclavo"), REFRESH_DESTRUCT,1);
}
