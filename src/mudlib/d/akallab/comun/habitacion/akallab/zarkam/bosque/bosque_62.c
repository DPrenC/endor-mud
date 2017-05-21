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
  SetIntShort("un claro en el bosque");
  SetIntLong(
  "Te encuentras en una zona del bosque en la que la cordillera de Kova te "
  "rodea por el norte. Aqui tambien hay senyales de lucha, y el numero de "
  "cadaveres es considerablemente superior. Posiblemente quedaron arrinconados en "
  "este lugar y ante la imposibilidad de escapar debido a las montanyas fueron "
  "ejecutados sin piedad. "
  "Grandes rocas te impiden el paso hacia el oeste, parece que provienen de un "
  "reciente derrumbamiento, tal vez alguien lo provoco para ocultar algo...\n");
  AddDetail(({"rocas","piedras"}),
  "Al oeste ves grandes rocas que te impiden el paso. Por la posicion que estas "
  "adoptan deduces que han caido desde una zona mas alta, en las montanyas.\n");
  AddDetail(({"cadaveres","cuerpos","esqueletos"}),
  "Aqui hay muchos mas esqueletos, parece ser que los hicieron recular hasta este "
  "lugar y aqui les dieron muerte.\n");
  AddDetail(({"cordillera","Kova","montanya"}),
  "Te encuentras rodeado por las montanyas que forman la cordillera de Kova, es "
  "imposible avanzar hacia el norte ya que las montanyas parecen inexpugnables.\n");
  AddExit("sudeste",Z_BOSQUE("bosque_57"));
  SetIndoors(0);
  SetIntSmell("El aire es ligeramente frio.\n");
  SetIntNoise("Oyes extranyos ruidos provenientes del oeste.\n");
  SetLocate("bosque de Zarkam");
}
