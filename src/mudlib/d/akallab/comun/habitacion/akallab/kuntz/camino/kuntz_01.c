/*
DESCRIPCION  : Enlace del desfiladero con la senda de los Cráneos .
FICHERO      : /d/akallab/comun/habitacion/akallab/kuntz/kuntz_01.c
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
  SetIntShort("el desfiladero de Kuntz");
  SetIntLong(
    "El Sendero de los Cráneos continua avanzando por el desfiladero de Kuntz. Desde "
    "aqui ya puedes ver al noroeste la profunda sima que da nombre al desfiladero y "
    "el puente que permite cruzar sobre ella. En lo alto del cielo, ves varias "
    "aguilas volando en circulos sobre el desfiladero. El viento es muy frio.\n");

  AddDetail(({"aguilas"}),
    "Ves a varias aguilas volando en el cielo, perece como si estuvieran buscando "
    "alguna presa. Ojala no te consideren un bocado apatecible.\n");

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

 SetIntNoise("El viento sopla con fuerza.\n");
 SetIntSmell("El aire esta enrarecido por la altura.\n");
 SetLocate("desfiladero de Kuntz");
 SetIndoors(0);
 AddExit("noroeste",K_CAMINO("kuntz_02"));
 AddExit("sur",K_CAMINO("kuntz_00"));
 AddItem(PNJ("animal/aguila"),REFRESH_DESTRUCT,2);
}
