/*
DESCRIPCION  : Campos de cultivo.
FICHERO      : /d/akallab/comun/habitacion/akallab/zarkam/campo/huerta_04.c
MODIFICACION : 20-03-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit Z_CAMPOS("huerta");

create() {
  object obj;
  ::create();
  AddExit("nordeste",Z_CAMPOS("huerta_05"));
  AddExit("este",Z_CAMPOS("campo_12"));
  AddExit("sur",Z_CAMPOS("campo_14"));
  obj=clone_object(PNJ("guardia_esclavos"));
  obj->SetAgressive(0);
  obj->SetGoChance(50);
  obj->move(TO);

}
