/*
DESCRIPCION  : Sendero de los Cráneos al sur de Zarkam.
FICHERO      : /d/akallab/comun/habitacion/akallab/zarkam/cc_06.c
MODIFICACION : 12-08-97 [Angor@Simauria] Creacion.
               09-11-98 [Angor@Simauria] Varias modificaciones
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit ROOM;

static int abierto, encontrado;

reset() { ::reset(); abierto=0; encontrado=0;}

int mover_cmd(string str) {
  if ((str!="arbusto")&&(str!="arbustos")) return 0;
  if (!abierto) {
      write("Mueves los arbustos y descubres que ocultaban un agujero en la roca. Ahora "
            "puedes mirar en su interior.\n");
      abierto=1; return 1; }
  else {
      write("Vuelves a dejar los arbustos es su posicion original tapando asi el el agujero.\n");
      abierto=0; return 1; }
}

mirar_agujero() {
  object ob;

  if (!abierto) return "No ves ningun agujero\n";
  if (encontrado) return "El agujero en la roca esta vacio.\n";
  encontrado=1;

/*  return "Encuentras algo que parece un orco muerto. No, un momento, no es un cadaver, "
         "parece un orco pero en realidad es ... un disfraz de orco. Puede ser muy util en "
         "esta zona hostil, asi que lo coges.\n";*/

  ob=clone_object(OTRO("salvoconducto_Zarkam"));
  if (ob) {
      ob->move(TP);
      call_out("reset",300);
      return "Encuentras unos papeles ocultos en el agujero.\n";
      }
  else return "Error al clonar. Avisa a un wizard.\n";
}


create() {
  ::create();
  SetIntShort("el sendero de los Cráneos al sur de Zarkam");
  SetIntLong(
     "Sigues en el Sendero de los Cráneos, que avanza por el valle hacia la ciudad "
     "fortificada de Zarkam que observas lejos al norte. El Sendero se vuelve aqui "
     "mas empinado a medida que asciende hacia el suroeste para poder rodear el "
     "Diente de Sharg que queda justo al sur de aqui. Junto al camino hay unos "
     "arbustos que parecen haber sido removidos recientemente.\n");

  AddDetail(({"arbustos","arbusto"}),
     "Junto al pie de la penya del Diente de Sharg crecen unos arbustos espinosos. "
     "Algo te ha llamado la atencion en ellos y ahora que los miras con atencion te "
     "das cuenta de que algunos estan en una posicion un poco extranya, como si "
     "alguien los hubiese colocado ahi para ocultar algo. Tal vez moviendolos un "
     "poco...\n");

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

 AddDetail("agujero",SF(mirar_agujero));

 SetIntNoise("Oyes el aullido del fuerte viento a traves de los desfiladeros.\n");
 SetIntSmell("Hmm.. el aire es mas bien frio por la altura.\n");
 SetLocate("valle de Zarkam");
 SetIndoors(0);

 AddExit("suroeste",Z_CAMINO("cc_07"));
 AddExit("norte",Z_CAMINO("cc_05"));

 AddRoomCmd("mover",SF(mover_cmd));

 reset();
}
