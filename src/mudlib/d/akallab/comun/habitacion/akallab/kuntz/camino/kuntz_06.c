/*
DESCRIPCION  : Desfiladero de Kuntz.
FICHERO      : /d/akallab/comun/habitacion/akallab/kuntz/kuntz_06.c
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
     "El Sendero de los Cráneos continua avanzando a traves del desfiladero de Kuntz. "
      "Al este de aqui observas la profunda sima que da nombre al desfiladero y a la "
      "que se dirije este camino. La vision de las nieves perpetuas que cubren los "
      "picos de las altas montanyas que te rodean es impresionante.\n");

  AddDetail(({"nieves","nieve","picos","pico"}),
     "La nieve que se encuentra en los picos son nieves perpetuas de una blancura "
      "extraordinaria.\n");

  AddDetail("sima",
     "Es una profunda grieta que se abre paso entre las altas montanyas de esta "
     "cordillera. Mirar a su profundo fondo, donde se encuentra un río de aguas "
     "turbulentas, desde aqui da vertigo. En su parte mas estrecha, se ha construido "
     "un puente que permite cruzarla.\n");

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
     "como advertencia a cualquiera que pretenda enfrentarse al imperio orco... ");

  SetIntNoise("El viento aulla entre los desfiladeros.\n");
  SetIntSmell("El aire esta enrarecido por la altura.\n");
  SetLocate("desfiladero de Kuntz");
  SetIndoors(0);

  AddExit("oeste",K_CAMINO("kuntz_07"));
  AddExit("sudeste",K_CAMINO("kuntz_05"));

  AddItem(PNJ("animal/aguila"),REFRESH_DESTRUCT,1+random(2));
}
