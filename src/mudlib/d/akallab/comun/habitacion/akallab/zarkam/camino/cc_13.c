/*
DESCRIPCION  : Cruce del Sendero de los Cráneos y camino al bosque.
FICHERO      : /d/akallab/comun/rooms/akallab/zarkam/camino/cc_13.c
MODIFICACION : 04-20-97 [Angor@Simauria] Creacion.
               06-10-98 [Angor@Simauria] Varias modificaciones
--------------------------------------------------------------------------------
*/

#include "./path.h"
inherit ROOM;

create() {
  ::create();
  SetIntShort("el cruce del camino del bosque y el Sendero de los Cráneos");
  SetIntLong(
     "Te encuentras sobre un bajo puente de piedra que permite que Sendero de los "
     "Cráneos atraviese el río Kuneii. Junto al extremo norte del puente, se halla un "
     "cruce en el Sendero del cual parte un camino de tierra que avanza hacia el este "
     "y que parece conducir hacia el bosque que hay al este del valle y los campos de "
     "cultivo al sudeste.\n");

  AddDetail(({"puente","puente de piedra"}),
     "Es un puente bajo pero ancho hecho con bloques de piedra. Permite que el Sendero "
     "de los Cráneos cruce el río Kuneii.\n");

  AddDetail(({"Sendero","sendero","Sendero de los Cráneos","sendero de los cráneos"}),
     "El Sendero de los Cráneos es la mas importante via de comunicacion en la "
     "peninsula orca que recorre de norte a sur serpenteando a traves de altas "
     "cordilleras y profundos acantilados. Los esclavos capturados por los orcos en la "
     "guerra han sido obligados a construirlo para mayor gloria del Emperador orco. "
     "Los huesos de aquellos que han dejado su vida en esta construccion se mezclan "
     "con el pavimento y sus cráneos estan clavados en altos postes junto al camino "
     "como advertencia a cualquiera que pretenda enfrentarse al imperio orco...\n");

 AddDetail(({"río","Kuneii","río Kuneii","kuneii"}),
     "El río Kuneii nace en las montanyas que se encuentran al oeste del valle de "
     "de Zarkam y avanza hacia el este atravesando el valle. Sus aguas son frias y "
     "algo turbias.\n");

 SetIntNoise("Oyes el rumor del agua del río y el viento a lo lejos.\n");
 SetIntSmell("Hmm.. el aire es mas bien frio por la altura.\n");
 SetLocate("valle de Zarkam");
 SetIndoors(0);
 AddExit("suroeste",Z_CAMINO("cc_12"));
 AddExit("norte",Z_CAMINO("cc_14"));
 AddExit("este",Z_CAMINO("c_bosque00"));
 AddItem(HERBS("hierba"), REFRESH_REMOVE);
}
