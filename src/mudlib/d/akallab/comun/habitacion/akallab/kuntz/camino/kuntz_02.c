/*
DESCRIPCION  : Puente en el desfiladero de kuntz .
FICHERO      : /d/akallab/comun/habitacion/akallab/kuntz/kuntz_02.c
MODIFICACION : 21-05-98 [Morgoth]
               08-10-98 [Angor@Simauria] Rehecha
			   03-02-00 [Angor@Simauria] Modificaciones varias
----------------------------------------------------------------------------
*/

#include "path.h"
#include AK_MACRO
inherit ROOM;

create() {
  ::create();
  SetIntShort("el extremo del puente sobre la sima");
  SetIntLong(
      "Te encuentras en un extremo del puente construido sobre con la profunda sima de "
      "Kuntz. Gracias a este puente, el Sendero de los Cr�neos puede sortear este "
      "obstaculo y proseguir su camino a lo largo de los territorios orcos. El puente "
      "esta construido con madera resistente y ha sido reforzado con una aleacion de "
      "hierro forjada por los herreros de Zarkam, pero debido a las duras condiciones "
      "climaticas, algunas de sus partes ya necesitan una reparacion.\n");

  AddDetail("sima",
      "Es una profunda grieta que se abre paso entre las altas montanyas de esta "
      "cordillera. Mirar a su profundo fondo, donde se encuentra un r�o de aguas "
      "turbulentas, desde aqui da vertigo. En su parte mas estrecha, se ha construido "
      "un puente que permite cruzarla.\n");

  AddDetail("puente",
      "El puente permite que el Sendero de los Cr�neos pueda cruzar la profunda sima de "
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

  AddDetail(({"Sendero","sendero","Sendero de los Cr�neos","sendero de los cr�neos"}),
     "El Sendero de los Cr�neos es la mas importante via de comunicacion en la "
     "peninsula orca que recorre de norte a sur serpenteando a traves de altas "
     "cordilleras y profundos acantilados. Los esclavos capturados por los orcos en la "
     "guerra han sido obligados a construirlo para mayor gloria del Emperador orco. "
     "Los huesos de aquellos que han dejado su vida en esta construccion se mezclan "
     "con el pavimento y sus cr�neos estan clavados en altos postes junto al camino "
     "como advertencia a cualquiera que pretenda enfrentarse al imperio orco...\n");

 SetIntNoise("El puente cruje ante el envite del fuerte viento.\n");
 SetIntSmell("Hueles las plantas aromaticas que crecen junto al puente.\n");
 SetLocate("desfiladero de Kuntz");
 SetIndoors(0);
 AddExit("oeste",K_CAMINO("kuntz_03"));
 AddExit("sudeste",K_CAMINO("kuntz_01"));
 AddItem(HERBS("hierba_curativa"), REFRESH_REMOVE);
}
