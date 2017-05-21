/*
DESCRIPCION  : Sendero de los Cráneos al sur de Zarkam.
FICHERO      : /d/akallab/comun/habitacion/akallab/zarkam/cc_01.c
MODIFICACION : 11-08-97 [Angor@Simauria] Creacion.
               05-10-98 [Angor@Simauria] Varias modificaciones
               29-10-98 [Chaos] Modificada una salida
--------------------------------------------------------------------------------
*/

#include "./path.h"
#include <moving.h>


inherit ROOM;

create() {
  ::create();
  SetIntShort("el sendero de los Cráneos al sur de Zarkam.");
  SetIntLong(
     "Estas en algun punto del Sendero de los Cráneos. El Sendero asciende suavemente "
     "hacia una loma al norte de aqui donde se encuentra la ciudad fortificada de "
     "Zarkam. Al sur de aqui se observas un cruce en el Sendero en el que se separa "
     "un camino hacia el este de la via principal, probablemente hacia los campos de "
     "cultivo que se encuentran en el fondo del valle. El paisaje es austero, y el "
     "viento sopla con fuerza desde el sudeste.\n");

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

 AddExit("nordeste",Z_CAMINO("cc_02"));
 AddExit("sur",Z_CAMINO("cc_00"));//para que el portal funcione
}
