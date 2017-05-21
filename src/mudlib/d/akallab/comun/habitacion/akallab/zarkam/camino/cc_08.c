/*
DESCRIPCION  : Sendero de los Cráneos al sur de Zarkam.
FICHERO      : /d/akallab/comun/habitacion/akallab/zarkam/cc_08.c
MODIFICACION : 14-08-97 [Angor@Simauria] Creacion.
               05-10-98 [Angor@Simauria] Varias modificaciones
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit ROOM;

create() {
  ::create();
  SetIntShort("el sendero de los Cráneos al sur de Zarkam");
  SetIntLong(
     "En este punto el Sendero de los Cráneos abandona el valle de Zarkam, que queda "
     "al norte, y se adentra en la cordillera montanyosa del sur hacia el desfiladero "
     "de la Garganta de Sharg. Este desfiladero es un lugar peligroso en el que las "
     "emboscadas son frecuentes y son pocos los que se aventuran a ir en solitario. Un "
     "viento helado aulla al atravesar los angostos desfiladeros del sur. Hace poco se "
     "producido un desprendimiento de rocas y el camino hacia el sur esta bloqueado.\n");

  AddDetail(({"rocas","desprendimiento"}),
     "El camino hacia el sur esta bloqueado por un inmenso monton de rocas. Lo mas "
     "probable es que estas se hallan desprendido debido a las ultimas lluvias. Tal "
     "y como estan las cosas, mientras los orcos no lo despejen, el acceso a los "
     "territorios del sur por esta via es por ahora impracticable.\n");

  AddDetail(({"Sendero","sendero","Sendero de los Cráneos","sendero de los cráneos"}),
     "El Sendero de los Cráneos es la mas importante via de comunicacion en la "
     "peninsula orca que recorre de norte a sur serpenteando a traves de altas "
     "cordilleras y profundos acantilados. Los esclavos capturados por los orcos en la "
     "guerra han sido obligados a construirlo para mayor gloria del Emperador orco. "
     "Los huesos de aquellos que han dejado su vida en esta construccion se mezclan "
     "con el pavimento y sus cráneos estan clavados en altos postes junto al camino "
     "como advertencia a cualquiera que pretenda enfrentarse al imperio orco...\n");

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
 AddExit("norte",Z_CAMINO("cc_07"));
 //AddExit("sur",SHARG("sharg_00"));
}
