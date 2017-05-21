/*
DESCRIPCION  : Campos de cultivo.
FICHERO      : /d/akallab/comun/habitacion/akallab/zarkam/campos/campo_03.c
MODIFICACION : 19-03-98 [Angor@Simauria] Creacion
               27-10-99 [Woo] Añadido un pergamino
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit Z_CAMPOS("campo");

create() {
  ::create();
  AddExit("oeste",Z_CAMPOS("campo_02"));
  AddExit("sur",Z_CAMPOS("campo_05"));
  AddExit("este",Z_CAMPOS("c_camp09"));
  AddItem("/guilds/conjuradores/pergamino/pergamino_oscuridad",REFRESH_REMOVE);
}
