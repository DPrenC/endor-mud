/*
DESCRIPCION  : Desfiladero estrecho al borde de la sima.
FICHERO      : /d/akallab/comun/rooms/akallab/kuntz/kuntz_04.c
MODIFICACION : 21-10-98 [Morgoth]
               08-10-98 [Angor@Simauria] Rehecha
			   03-02-00 [Angor@Simauria] Modificaciones varias
----------------------------------------------------------------------------
*/

#include "path.h"
#include AK_MACRO
inherit ROOM;

#define DESTINO K_CUEVA("galeria01")
#include FILTRO_PNJ_ZONA

create() {
  ::create();
 SetIntShort("la entrada a la zona troll");
  SetIntLong(
     "El Sendero de los Cráneos continua avanzando junto al borde de la profunda sima "
      "de Kuntz. Observas que al sudeste de aqui se ha construido un puente que permite "
      "cruzarla. Junto a la pared rocosa que flanquea el camino hay unos arbustos que "
      "parecen haber sido removidos recientemente.\n");

  AddDetail(({"arbustos","arbusto"}),
     "Junto a la pared rocosa que se halla junto al camino crecen unos arbustos "
     "espinosos. Algo te ha llamado la atencion en ellos y ahora que los miras con "
     "atencion te das cuenta de que algunos estan en una posicion un poco extranya, "
     "como si alguien los hubiese colocado ahi para ocultar algo. Los mueves un poco y "
     "descubres que ocultan la entrada a una cueva al oeste. Huele a troll...\n");

  AddDetail("sima",
     "Es una profunda grieta que se abre paso entre las altas montanyas de esta "
      "cordillera. Mirar a su profundo fondo, donde se encuentra un río de aguas "
      "turbulentas, desde aqui da vertigo. En su parte mas estrecha, se ha construido "
      "un puente que permite cruzarla.\n");

  AddDetail("puente",
      "Queda al sudeste de aqui y permite cruzar la profunda sima. Deberas acercarte "
      "mas si quieres verlo mejor.\n");

  AddDetail(({"desfiladero","kuntz","Kuntz","cordillera","Kova","kova"}),
     "La cordillera montanyosa de Kova separa el valle de Zarkam del de Akallab. Esta "
     "formada por altas montanyas cubiertas de nieves perpetuas. La unica forma "
     "razonable para atravesarla es a traves del desfiladero de Kuntz, un paso "
     "que avanza a traves de profundas grietas y peligrosas simas siendo ademas una "
     "zona donde se suelen esconder grupos de troll.\n");

  AddDetail(({"Sendero","sendero","Sendero de los Cráneos","sendero de los cráneos"}),
     "El Sendero de los Cráneos es la mas importante via de comunicacion en la "
     "peninsula orca que recorre de norte a sur serpenteando a traves de altas "
     "cordilleras y profundos acantilados. Los esclavos capturados por los orcos en la "
     "guerra han sido obligados a construirlo para mayor gloria del Emperador orco. "
     "Los huesos de aquellos que han dejado su vida en esta construccion se mezclan "
     "con el pavimento y sus cráneos estan clavados en altos postes junto al camino "
     "como advertencia a cualquiera que pretenda enfrentarse al imperio orco...\n");

 SetIntNoise("El viento aulla entre los desfiladeros.\n");
 SetIntSmell("Huele.... a troll!!.\n");
 SetLocate("desfiladero de Kuntz");
 SetIndoors(0);
 AddExit("nordeste",K_CAMINO("kuntz_05"));
 AddExit("sudeste",K_CAMINO("kuntz_03"));
 AddExit("oeste",SF(FiltroPnjZona));
 HideExit("oeste",1);
}
