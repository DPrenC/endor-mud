/*
DESCRIPCION  : Sendero de los Cráneos al sur de Zarkam.
FICHERO      : /d/akallab/comun/habitacion/akallab/zarkam/cc_02.c
MODIFICACION : 11-08-97 [Angor@Simauria] Creacion.
               05-10-98 [Angor@Simauria] Varias modificaciones
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit ROOM;

create() {
  ::create();
  SetIntShort("el sendero de los Cráneos al sur de Zarkam");
  SetIntLong(
     "El sendero de los Cráneos continua aqui hacia la ciudad de Zarkam que se "
     "encuentra al norte. El camino desciende suavemente hacia el suroeste donde, a "
     "lo lejos, se aprecia un cruce con un camino que viene del este. Junto al camino "
     "se alza un alto poste en el que se hallan insertados varios cráneos y en cuyo "
     "extremo ondea una alargada bandera negra, simbolo del imperio orco. El viento "
     "sopla con fuerza desde el sureste\n");

  AddDetail(({"poste","bandera","poste con cráneos"}),
     "Ya lo habias visto antes a lo largo del Sendero de los Cráneos. Los orcos "
     "empalan los cráneos de sus esclavos de guerra muertos mientras eran obligados a "
     "construir el Sendero. La bandera que ondea bajo el fuerte viento es un alargado "
     "trozo de tela negra sin ningun simbolo grabado en ella, austera y temible como "
     "los propios orcos. Le recuerda a cualquiera claramente de quien es la tierra "
     "que se esta pisando y a que atenerse.\n");

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

 SetIntNoise("Oyes el aullido del fuerte viento a traves de los desfiladeros.\n");
 SetIntSmell("Hmm.. el aire es mas bien frio por la altura.\n");
 SetLocate("valle de Zarkam");
 SetIndoors(0);

 AddExit("norte",Z_CAMINO("cc_04"));
 AddExit("suroeste",Z_CAMINO("cc_01"));
}
