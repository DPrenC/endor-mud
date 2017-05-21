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
  SetIds(({"flor","flores","flores blancas"}));
  SetShort("unas flores blancas");
  SetLong("Son unas extrañas flores de color blanco.\n");
  Set(P_GENDER,GENERO_FEMENINO);
  Set(P_NUMBER,NUMERO_PLURAL);
  SetSmell("No sabes porque pero su olor te recuerda al tomillo.\n");
  SetWeight(50);
  SetClass(HERB_CLASS_MAGIC);
  SetPower(10+random(10));
  SetValue(35);
}


