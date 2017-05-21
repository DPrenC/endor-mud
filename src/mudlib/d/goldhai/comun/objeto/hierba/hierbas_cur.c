/*=============================================================*
 |            << GOLDHAI.Hierba [w] Woo@simauria >>            |
 *=============================================================*
 |               Creacion.............. 18-11-98               |
 |               Ultima Modificacion... 18-11-98               |
 |                                                             |
 *=============================================================*/

#include "./path.h"
#include <properties.h>


#include <herbs.h>

inherit HERB;

create() {
  ::create();

  SetIds(({"hierba","hierbas","hierbajos"}));
  SetShort("unas hierbas extrañas");
  SetLong("Son unas hierbas con un color entre verde y amarillo.\n");
  Set(P_GENDER,GENERO_FEMENINO);
  Set(P_NUMBER,NUMERO_PLURAL);
  SetSmell("Su olor te recuerda a unas hierbas que tomabas hace tiempo.\n");
  SetWeight(45);
  SetClass(HERB_CLASS_HEALING);
  SetPower(15+random(100));
  SetValue(QueryPowerNumber());
}


