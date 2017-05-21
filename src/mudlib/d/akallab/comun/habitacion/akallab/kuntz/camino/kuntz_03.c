/*
DESCRIPCION  : Puente en el desfiladero de kuntz .
FICHERO      : /d/akallab/comun/habitacion/akallab/kuntz/kuntz_03.c
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
 SetIntShort("el puente sobre la sima");
  SetIntLong(
      "Te encuentras en el lugar en el que el Sendero de los Cráneos se encuentra con "
      "la sima de Kuntz. El puente que ves ante ti te permite cruzar esta profunda sima "
      "proseguir el camino. El puente esta construido con una solida estructura de "
      "y madera, pero debido a las duras condiciones climaticas, algunas de sus partes "
      "ya necesitan una reparacion.\n");

  AddDetail("sima",
      "Es una profunda grieta que se abre paso entre las altas montanyas de esta "
      "cordillera. Mirar a su profundo fondo, donde se encuentra un río de aguas "
      "turbulentas, desde aqui da vertigo. En su parte mas estrecha, se ha construido "
      "un puente que permite cruzarla.\n");

  AddDetail("puente",
      "El puente permite que el Sendero de los Cráneos pueda cruzar la profunda sima de "
      "Kuntz. Esta formado por una estructura de aleacion de hierro solidamente anclada "
      "a los bordes de los acantilados que forman la sima sobre la que descansan los "
      "gruesos tablones de madera que forman el piso. Es una obra de ingenieria de "
      "vital importancia para los orcos que lo reparan periodicamente. Debido a las "
      "duras condiciones climatologicas algunas de sus partes ya requieren reparacion.\n");

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

 SetIntNoise("El puente cruje por el empije del fuerte viento.\n");
 SetIntSmell("El aire esta enrarecido por la altura.\n");
 SetLocate("desfiladero de Kuntz");
 SetIndoors(0);
 AddExit("noroeste",K_CAMINO("kuntz_04"));
 AddExit("este",K_CAMINO("kuntz_02"));

 AddItem(PNJ("k_cueva/merodeador"),REFRESH_DESTRUCT,1);
}
