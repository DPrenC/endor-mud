/*
DESCRIPCION  : Camino desde el Sendero de los Ccraneos hasta el bosque
FICHERO      : /d/akallab/comun/habitacion/akallab/zarkam/c_bosque00.c
MODIFICACION : 25/11/97 Jotuna
               15/03/98 [Angor@Simauria] Rehecha
               06-10-98 [Angor@Simauria] Varias modificaciones
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit ROOM;

create() {
  ::create();
  SetIntShort("el camino hacia el bosque");
  SetIntLong(
     "Te encuentras en un camino que se desvia del Sendero de los Cráneos y cruza el "
     "valle hacia un gran bosque cercano que queda al este. Al suroeste puedes divisar "
     "la ciudad fortificada de Zarkam. El camino serpentea siguiendo el cauce del río "
     "Kuneii y, al otro lado, puedes ver a lo lejos enormes campos de cultivo "
     "protegidos en el fondo del valle del fuerte viento que sopla.\n");

  AddDetail(({"Sendero","sendero","Sendero de los Cráneos","sendero de los cráneos"}),
     "El Sendero de los Cráneos es la mas importante via de comunicacion en la "
     "peninsula orca que recorre de norte a sur serpenteando a traves de altas "
     "cordilleras y profundos acantilados. Los esclavos capturados por los orcos en la "
     "guerra han sido obligados a construirlo para mayor gloria del Emperador orco. "
     "Los huesos de aquellos que han dejado su vida en esta construccion se mezclan "
     "con el pavimento y sus cráneos estan clavados en altos postes junto al camino "
     "como advertencia a cualquiera que pretenda enfrentarse al imperio orco...\n");

  AddDetail(({"camino","senda"}),
     "El camino donde te encuentras se cruza con el Sendero de los Cráneos un poco mas "
     "al oeste. Parece que no se tomaron muchas molestias en hacer esta senda, es un "
     "camino de tierra mal marcado. Algo de vegetacion que ha crecido gracias a la "
     "humedad del río hace mas mejora la triste imagen que presenta. Mucho mas al este "
     "ves que el camino se pierde en un denso bosque.\n");

  AddDetail(({"río","Kuneii","kuneii", "cauce"}),
     "Ves que el camino sigue el cauce del río Kuneii que continua hacia el este. Mas "
     "adelante se desvia al sur alejandose del bosque al que conduce esta senda, lo "
     "cual parece ser un mal presagio. Desde aqui puedes ver algunos peces que emergen "
     "a la superficie del río cerca de la orilla, como si la curiosidad les llevara a "
     "a seguir tus movimientos y saber lo que haces.\n");

  AddDetail(({"bosque", "arboleda", "bosque del este"}),
     "Desde aqui no puedes ver mucho del bosque. Lo que si puedes apreciar es que se "
     "engulle el sendero que pisas entre una densa y oscura vegetacion.\n");

  AddDetail(({"ciudad","ciudad fortificada","Zarkam","zarkam"}),
     "En medio del valle y sobre una loma se alza la ciudad fortificada de Zarkam. Es "
     "una poblacion de mediano tamanyo que se halla totalmente rodeado por una alta "
     "muralla de piedra. Desde el exterior, lo unico que se puedes ver de la ciudad es "
     "una alta torre que se alza sobre la muralla y en la que siempre hay vigias por "
     "si aparecen enemigos. Seguro que vigilan tus movimientos desde que entraste en "
     "este valle... No hay duda que esta gente esta acostumbrada a la guerra.\n");

  SetIntNoise("Oyes el suave susurrar del correr del agua del río.\n");
  SetIntSmell("Hmm.. tu zapato huele mal, has debido pisar algo.\n");
  SetLocate("valle de Zarkam");
  SetIndoors(0);
  AddExit("oeste",Z_CAMINO("cc_13"));
  AddExit("este",Z_CAMINO("c_bosque01"));
}
