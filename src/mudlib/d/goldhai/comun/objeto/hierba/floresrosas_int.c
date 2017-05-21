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

  SetIds(({"flor","flores","flores rosas"}));
  SetShort("unas flores rosas");
  SetLong("Son unas extrañas flores de color rosa palido.\n");

  SetSmell("Huelen como las fresas.\n");
  Set(P_GENDER,GENERO_FEMENINO);
  Set(P_NUMBER,NUMERO_PLURAL);
  SetWeight(50);
  SetClass(HERB_CLASS_TOXIC);
  SetPower(30+random(150));
  SetValue(QueryPowerNumber());
}


