/*
DESCRIPCION  : Bosque al nordeste de Zarkam.
FICHERO      : /d/akallab/comun/habitacion/akallab/zarkam/bosque/bosque_??.c
MODIFICACION : 13-04-98 [Elric@Simauria] Creacion
               10-10-98 [Angor@Simauria] Varias modificaciones
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit ROOM;

create() {
  ::create();
  SetIntShort("el interior del bosque");
  SetIntLong(
"Ramas y guijarros crujen bajo tus pies con cada paso que das, por mas que lo "
"intentas te es imposible avanzar a traves del bosque sin hacer ningun ruido, "
"pero no es solo el ruido de tus pisadas lo que te preocupa, tambien lo hacen "
"los extranyos aullidos que oyes de vez en cuando. "
"Al este ves un gran arbol con una extranya construccion de madera en su copa, "
"parece una pequenya cabanya o una torreta de vigilancia.\n");
  SetIndoors(1);
  SetIntBright(10);
  AddExit("este",Z_BOSQUE("bosque_40"));
  AddExit("sur",Z_BOSQUE("bosque_29"));
  AddExit("oeste",Z_BOSQUE("bosque_38"));
  AddExit("nordeste",Z_BOSQUE("bosque_50"));
  AddExit("norte",Z_BOSQUE("bosque_49"));
  AddDetail(({"arbol","arboles"}),
  "De entre todos los arboles, el que mas te llama la atencion es uno que se "
  "encuentra situado al norte de tu posicion y en el que, al parecer, hay una "
  "construccion de madera en su copa.\n");
  AddDetail(({"guijarros","ramas"}),
  "El suelo esta repleto de guijarros, ramas y hojas, que producen lo que parece "
  "un estruendoso ruido en el silencio del bosque, solo alterado por el aullido de "
  "alguna bestia.\n");
  SetIntNoise("Oyes crujir las ramas bajo tus pies.\n");
  SetIntSmell("Ueles a Naturaleza.\n");
  SetLocate("bosque de Zarkam");
}
