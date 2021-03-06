/*
DESCRIPCION  : Desfiladero estrecho al borde de la sima.
FICHERO      : /d/akallab/comun/habitacion/akallab/kuntz/kuntz_05.c
MODIFICACION : 21-10-98 [Morgoth]
               08-10-98 [Angor@Simauria] Rehecha
			   03-02-00 [Angor@Simauria] Modificaciones varias
----------------------------------------------------------------------------

*/

#include "path.h"
#include AK_MACRO
inherit ROOM;

create() {
  ::create();
 SetIntShort("el desfiladero de Kuntz");
  SetIntLong(
     "Te encuentras en el Sendero de los Cr�neos junto al borde de la sima de Kuntz. "
      "El Sendero avanza aqui junto al borde de esta profunda sima que divide en dos "
      "esta cordillera. Lejos al sudeste divisas un puente que permite cruzar la sima, "
      "y hacia el noroeste el Sendero se aleja poco a poco de ella. Un viento helado "
      "que aulla entre los acantilados es la unica companyia.\n");

  AddDetail("puente",
      "Queda al sudeste de aqui y permite cruzar la profunda sima. Deberas acercarte "
      "mas si quieres verlo mejor.\n");

  AddDetail("sima",
     "Es una profunda grieta que se abre paso entre las altas montanyas de esta "
     "cordillera. Mirar a su profundo fondo, donde se encuentra un r�o de aguas "
     "turbulentas, desde aqui da vertigo. En su parte mas estrecha, se ha construido "
     "un puente que permite cruzarla.\n");

  AddDetail(({"desfiladero","kuntz","Kuntz","cordillera","Kova","kova"}),
     "La cordillera montanyosa de Kova separa el valle de Zarkam del de Akallab. Esta "
     "formada por altas montanyas cubiertas de nieves perpetuas. La unica forma "
     "razonable para atravesarla es a traves del desfiladero de Kuntz, un paso "
     "que avanza a traves de profundas grietas y peligrosas simas siendo ademas una "
     "zona donde se suelen esconder grupos de troll.\n");

  AddDetail(({"Sendero","sendero","Sendero de los Cr�neos","sendero de los cr�neos"}),
     "El Sendero de los Cr�neos es la mas importante via de comunicacion en la "
     "peninsula orca que recorre de norte a sur serpenteando a traves de altas "
     "cordilleras y profundos acantilados. Los esclavos capturados por los orcos en la "
     "guerra han sido obligados a construirlo para mayor gloria del Emperador orco. "
     "Los huesos de aquellos que han dejado su vida en esta construccion se mezclan "
     "con el pavimento y sus cr�neos estan clavados en altos postes junto al camino "
     "como advertencia a cualquiera que pretenda enfrentarse al imperio orco...\n");

  SetIntNoise("El viento aulla entre los desfiladeros.\n");
  SetIntSmell("El aire esta enrarecido por la altura.\n");
  SetLocate("desfiladero de Kuntz");
  SetIndoors(0);

  AddExit("noroeste",K_CAMINO("kuntz_06"));
  AddExit("suroeste",K_CAMINO("kuntz_04"));

  AddItem(PNJ("k_cueva/merodeador"),REFRESH_DESTRUCT,1);
}
