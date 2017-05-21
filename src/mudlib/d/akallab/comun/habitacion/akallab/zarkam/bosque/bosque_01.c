/*
DESCRIPCION  : Bosque
FICHERO      : /d/akallab/comun/habitacion/akallab/zarkam/bosque/bosque_01.c
MODIFICACION : ??-??-?? [Elric@Simauria] Creacion
               10-10-98 [Angor@Simauria] Varias modificaciones
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit ROOM;

create() {
  ::create();
  SetIntShort("la entrada al bosque");
  SetIntLong(
     "Estas en la entrada del bosque que se halla al nordeste del valle de Zarkam. El "
     "bosque se extiende desde este lugar hasta las lejanas montanyas. Frente a ti se "
     "alzan arboles desafiantes entre los que avanza un tortuoso camino de tierra. Al "
     "Al suroeste el camino se aleja del bosque.\n");

  AddDetail(({"arbol","arboles"}),
     "Grandes arboles forman este bosque. Por suerte, en esta zona estan lo "
     "suficientemente separados como para que no impidan la entrada del sol, de lo "
     "contrario sus copas no te dejarian distinguir si es de noche o de dia.\n");

  AddDetail(({"camino"}),
     "Ves como un camino se interna entre los arboles. Se trata de un camino "
     "de tierra que parece haber sido utilizado no hace mucho tiempo.\n");

  SetIntNoise("Oyes el cantico de los pajaros.\n");
  SetIntSmell("El aire esta limpio y fragante...\n");
  SetLocate("bosque de Zarkam");
  SetIndoors(0);
  AddExit("nordeste",Z_BOSQUE("bosque_10"));
  AddExit("noroeste",Z_BOSQUE("bosque_08"));
  AddExit("suroeste",Z_CAMINO("c_bosque05"));
}
