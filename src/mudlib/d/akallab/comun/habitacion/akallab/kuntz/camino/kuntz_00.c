/*
DESCRIPCION  : Enlace del desfiladero con la senda de los Cráneos .
FICHERO      : /d/akallab/comun/rooms/akallab/kuntz/kuntz_00.c
MODIFICACION : 21-05-98 [Morogth]
               08-10-98 [Angor@Simauria] Rehecha
			   03-02-00 [Angor@Simauria] Modificaciones varias
----------------------------------------------------------------------------
*/

#include "path.h"
#include AK_MACRO
inherit ROOM;

#define DESTINO Z_CAMINO("cc_16")
#include FILTRO_PNJ_ZONA

//#define MARCA_PNJ_ZONA "pnj_zona"

create() {
  ::create();
  SetIntShort("el desfiladero de Kuntz");
  SetIntLong(
    "Te encuentras en el lugar en el que el Sendero de los Cráneos se adentra en el "
    "desfiladero de Kuntz. Este angosto paso avanza encajonado entre montanyas "
    "atravesando la cordillera de Kova. A tu alrededor se alzan imponentes picos "
    "cubiertos de nieves perpetuas y profundas gargantas cuyo fondo apenas si "
    "adivinas. Un viento helado viento aulla con fuerza al cruzar el desfiladero.\n");

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

 SetIntNoise("El viento aulla con fuerza.\n");
 SetIntSmell("El aire esta enrarecido por la altura.\n");
 SetLocate("desfiladero de Kuntz");
 SetIndoors(0);
 AddExit("norte",K_CAMINO("kuntz_01"));
 AddExit("sudeste",SF(FiltroPnjZona));
}
