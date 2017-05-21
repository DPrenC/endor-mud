/*
DESCRIPCION  : Desfiladero de Kuntz.
FICHERO      : /d/akallab/comun/rooms/akallab/kuntz/camino/kuntz_06.c
MODIFICACION : 21-10-98 [Morgoth]
               08-10-98 [Angor@Simauria] Rehecha
               03-02-99 [Angor@Simauria] Retoques varios
----------------------------------------------------------------------------
*/

#include "path.h"
#include AK_MACRO
inherit ROOM;

create() {
  ::create();
  SetIntShort("el desfiladero de Kuntz");
  SetIntLong(
     "El valle por cuyo fondo transcurre el Sendero de los Cráneos se "
	   "estrecha en esta zona dada la gran pendiente de las montanyas. Un "
	   "poco mas adelante hacia el noroeste, el Sendero se haya bloqueado "
	   "por una mole de hielo y rocas. Un alud ha sido probablemente la "
	   "causa de este derrumbamiento que bloquea al camino.\n");

  AddDetail(({"rocas","desprendimiento"}),
     "El camino hacia el noroeste esta bloqueado por un inmenso monton de hielo y "
     "rocas. Lo mas probable es se haya producido un alud de nieve procedente de las "
     "altas cumbres arrastrando todo lo que ha encontrado a su paso hasta llegar al "
     "fondo del desfiladero.\n");

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
  SetIntSmell("El aire esta enrarecido por la altura.\n");
  SetLocate("desfiladero de Kuntz");
  SetIndoors(0);
  AddExit("este",K_CAMINO("kuntz_06"));
  //AddExit("noroeste",A_CAMINO(""));
}
