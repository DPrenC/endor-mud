/*
DESCRIPCION  : pnj estandar de Akallab
               Se hereda el pnj estandard y se annyaden las ampliaciones
               que se consideren necesarias.
FICHERO      : /d/akallab/std/pnj_base.c
MODIFICACION :
18-02-00 [Angor@Simauria] Creacion
*/

#include <living.h>
#include <combat.h>
#include <properties.h>
inherit NPC;

create() {
  ::create();
 SetStandard("pnj","pnj",0,GENDER_MALE);
  SetShort("un pnj a medio hacer");

  Set("pnj_zona",1);  //atrapado en su zona de territorio
}
