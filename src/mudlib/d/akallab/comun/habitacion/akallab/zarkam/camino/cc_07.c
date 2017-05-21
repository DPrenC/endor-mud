/*
DESCRIPCION  : Sendero de los Cráneos al sur de Zarkam.
FICHERO      : /d/akallab/comun/habitacion/akallab/zarkam/cc_07.c
MODIFICACION : 12-08-97 [Angor@Simauria] Creacion.
               05-10-98 [Angor@Simauria] Varias modificaciones
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit ROOM;

create() {
  ::create();
  SetIntShort("el sendero de los Cráneos al sur de Zarkam");
  SetIntLong(
     "Estas en algun punto del Sendero de los Cráneos. Hacia el nordeste, el Sendero "
     "desciende adentrandose en un valle, que desde aqui comienzas ya a ver, en el que "
     "debe encontrarse la ciudad de Zarkam. Hacia el sur, el camino presenta empinadas "
     "cuestas al ascender hacia el paso de la Garganta de Sharg entre las montanyas. "
     "El sendero rodea aqui el gran penyasco del Diente de Sharg que se queda al este.\n");

  AddDetail(({"diente","Diente","Diente de Sharg","diente de sharg"}),
     "Es una gran penya que se encuentra junto al camino hacia el sur de aqui. En "
     "alguna epoca debio desprenderse de las altas montanyas de Sharg que se "
     "encuentran al sur y rodo hacia el valle.\n");

  AddDetail(({"Sendero","sendero","Sendero de los Cráneos","sendero de los cráneos"}),
     "El Sendero de los Cráneos es la mas importante via de comunicacion en la "
     "peninsula orca que recorre de norte a sur serpenteando a traves de altas "
     "cordilleras y profundos acantilados. Los esclavos capturados por los orcos en la "
     "guerra han sido obligados a construirlo para mayor gloria del Emperador orco. "
     "Los huesos de aquellos que han dejado su vida en esta construccion se mezclan "
     "con el pavimento y sus cráneos estan clavados en altos postes junto al camino "
     "como advertencia a cualquiera que pretenda enfrentarse al imperio orco...\n");

  AddDetail(({"ciudad","ciudad fortificada","Zarkam","zarkam"}),
     "En medio del valle y sobre una loma se alza la ciudad fortificada de Zarkam. Es "
     "una poblacion de mediano tamanyo que se halla totalmente rodeado por una alta "
     "muralla de piedra. Desde el exterior, lo unico que se puedes ver de la ciudad es "
     "una alta torre que se alza sobre la muralla y en la que siempre hay vigias por "
     "si aparecen enemigos. Seguro que vigilan tus movimientos desde que entraste en "
     "este valle... No hay duda que esta gente esta acostumbrada a la guerra.\n");

  AddDetail(({"garganta","garganta de sharg","Garganta","Garganta de Sharg"}),
     "La Garganta de Sharg es el nombre que recibe el paso a traves de las montanyas "
     "de Sharg que se encuentran al sur de aqui. Este paso avanza a traves de las "
     "profundas grietas y peligrosos acantilados de estas montanyas siendo el unico "
     "camino viable para ir hacia el sur. Es un lugar peligroso: emboscadas de trolls "
     "y desprendimientos son hechos frecuentes.\n");

 SetIntNoise("Oyes el aullido del fuerte viento a traves de los desfiladeros.\n");
 SetIntSmell("Hmm.. el aire es mas bien frio por la altura.\n");
 SetLocate("valle de Zarkam");
 SetIndoors(0);
 AddExit("nordeste",Z_CAMINO("cc_06"));
 AddExit("sur",Z_CAMINO("cc_08"));
 AddItem(HERBS("hierba_saciante"), REFRESH_REMOVE);
}
