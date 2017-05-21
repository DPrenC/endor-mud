/*
DESCRIPCION  : Campos de cultivo.
FICHERO      : /d/akallab/comun/habitacion/akallab/zarkam/campos/campo_09.c
MODIFICACION : 19-03-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit Z_CAMPOS("campo");

create() {
  object obj;
  ::create();
  AddExit("norte",Z_CAMPOS("campo_05"));
  AddExit("este",Z_CAMPOS("huerta_01"));
  AddExit("sur",Z_CAMPOS("campo_11"));
  AddExit("oeste",Z_CAMPOS("campo_08"));
  obj=clone_object(PNJ("guardia_esclavos"));
  obj->SetAgressive(0);
  obj->SetGoChance(50);
  obj->move(TO);
}
