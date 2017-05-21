#include "path.h"
inherit GROOM;

create()
{
  ::create();
  SetIntShort("la torre Noroeste");
  SetLongWrap(
    "Pasas por debajo de un gran arco que une el puerto con la ciudad "
    "de Glucksfall. Hay una escalera de piedra a tu lado que conduce a lo "
    "que parece ser el primer piso de la torre situada encima de ti. Puedes "
    "o bien dirigirte hacia la ciudad en el Oeste o bien hacia el puerto en "
    "dirección opuesta."
    );
  SetIndoors(1);
  SetIntBright(50);
 AddDetail(({"escalinata","escalera","escaleras"}),
"Ves una escalera construida de piedra que asciende en forma de caracol junto\n\
a las paredes de la torre.\n");

  AddExit("noroeste","calle11");
  AddExit("oeste","calle10");
  AddExit("este","muelle");
  AddExit("arriba","piso1_15");
  SetLocate("Glucksfall");
}
