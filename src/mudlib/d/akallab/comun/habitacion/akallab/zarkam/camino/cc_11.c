/*
DESCRIPCION  : Cruce del Sendero de los Cráneos y camino a la mina.
FICHERO      : /d/akallab/comun/rooms/akallab/zarkam/camino/cc_11.c
MODIFICACION : 20-05-97 [Angor@Simauria] Creacion.
               06-10-98 [Angor@Simauria] Varias modificaciones
--------------------------------------------------------------------------------
*/

#include "./path.h"
inherit ROOM;

create() {
  object portal;

  ::create();
  SetIntShort("un cruce en el Sendero de los Cráneos");
  SetIntLong(
     "Has llegado a un cruce en el Sendero de los Cráneos. En este punto del Sendero "
     "se separa de el un camino de tierra que avanza hacia el oeste ascendiendo entre "
     "montanyas hacia la vieja mina como indica un viejo tablon clavado en un poste "
     "que hay junto al cruce. La ciudad fortificada de Zarkam se divisa en una loma "
     "al sur de aqui hacia la que asciende el Sendero. El paisaje es austero, y el "
     "viento es frio y desagadable.\n");

  AddDetail(({"poste","tablon","poste con letreros"}),
     "Junto al cruce hay un poste indicador en el que alguien clavo un viejo tablon a "
     "modo de letrero indicador. Indica que el camino de tierra que parte hacia el "
     "oeste de aqui se dirige a las minas que los orcos tienen en la parte alta de "
     "estas montanyas.\n");

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
 AddExit("sur",Z_CAMINO("cc_10"));
 AddExit("norte",Z_CAMINO("cc_12"));
 AddExit("oeste",Z_CAMINO("c_mina00"));

 portal=clone_object("obj/monolito");
 portal->SetRaza("gigante");
 portal->move(TO);

}
