#include "./path.h"
#include <properties.h>

inherit THING;

create () {
   ::create();
      SetShort("una piedra sagrada");
      SetLong(
"Ves una simple piedra con un grabado que representa el simbolo sagrado de "
"las Espadas Silbantes de Kha-annu. Desprende un extranyo brillo magico justo "
"donde esta el dibujo.\n");
      SetIds( ({"deseo","piedra"}) );
      AddAdjective( ({"una","sagrada"}) );
      Set(P_NODROP,1);
      Set(P_NOGIVE,1);
      Set(P_NOBUY,1);
      Set(P_MAGIC,1);
      Set(P_AUTOOBJECT,1);
      Set(P_NOSELL,1);
      SetWeight(0);
}
