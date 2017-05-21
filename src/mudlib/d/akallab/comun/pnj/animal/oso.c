/*
DESCRIPCION  : un oso para los bosques
FICHERO      : /d/akallab/comun/pnj/animal/oso.c
MODIFICACION : 18-02-00 [Angor@Simauria] Creacion
*/

#include "path.h"
#include AK_MACRO
#include "oso_base.h"
inherit PNJ("animal/oso_base");

create() {
  SetTipo(-1); //random
  SetClase(OSO);
  ::create();
}
