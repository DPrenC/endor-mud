/*=============================================================*
 |            << GOLDHAI.Hierba [w] Woo@simauria >>            |
 *=============================================================*
 |               Creacion.............. 17-11-98               |
 |               Ultima Modificacion... 17-11-98               |
 |                                                             |
 *=============================================================*/

#include "./path.h"
#include <properties.h>


#include <herbs.h>

inherit HERB;

create() {
  ::create();

  SetIds(({"flor","flores","flores amarillas"}));
  SetShort("unas flores amarillas");
  SetLong("Son unas extrañas flores de color amarillo.\n");

  Set(P_GENDER,GENERO_FEMENINO);
  Set(P_NUMBER,NUMERO_PLURAL);
  SetSmell("No huelen a nada especial.\n");
  SetWeight(50);
  SetClass(HERB_CLASS_POISONOUS);
  SetPower(50+random(200));
  SetValue(25);
}


