/*
DESCRIPCION  : galeria tipo de la mina
FICHERO      : /d/akallab/comun/habitacion/akallab/zarkam/minas/std/galeria.c
MODIFICACION : 05-08-98 [Angor@Simauria] Creacion
*/

#include "./path.h"
#include AK_MACRO
#include "./galeria.h"

inherit AK_ROOM;

/*#define TIPOGAL 3
#define GAL_RANDOM 0
#define GAL_NORMAL 1
#define GAL_HUMEDA 2
#define GAL_NORMAL_CRUCE 2*/

void HazDescr(int tipo, int desc){

  if (tipo==0) tipo=random(TIPOGAL)+1;
  switch(tipo) {
  case GAL_NORMAL:{
      if ((desc==0)||(desc<0)||(desc>2)) desc=random(3);
      switch(desc){
      case 0:{
            SetIntLong("Esta galeria continua su avance por el interior de la "
                "mina. El ambiente es seco y polvoriento y el aire esta un poco "
                "viciado. En algunos lugares de las paredes aun se observan "
                "restos de vetas de mineral entre los pilares y traviesas de "
                "madera que soportan el techo de la galeria. Avanzas tratando "
                "de no tropezar con los railes de las vagonetas.\n");break;}
      case 1:{
            SetIntLong("El aire seco y viciado de esta galeria te reseca la "
                "garganta a medida que avanzas por ella. En esta zona de la "
                "galeria los pilares que sostienen el peso de la roca no "
                "parecen muy resistentes y sim embargo aun aguantan. Avanzas "
                "junto a los railes de las vagonetas.\n");break;}
      case 2:{
            SetIntLong("Solo el eco de tus pasos te acompanya a medida que "
                "avanzas por esta solitaria galeria de la mina. El aire es "
                "seco y polvoriento, lo que dificulta la respiracion. Observas "
                "que junto a los railes hay algunas piedras que, probablemnte, "
                "se hayan caido de las vagonetas cuando se extrae mineral de la "
                "mina.\n");break;}
      }
      AddDetail(({"railes"}),
         "Son largas vigas de hierro sobre las que se desplazan las vagonetas "
         "con las que se extrae el mineral de las minas.\n");
      AddDetail(({"vetas","paredes"}),
         "En algunos lugares de las paredes aun se observan restos de las "
         "vetas de mineral que contenia esta galeria. Las vetas son capas "
         "de mineral o metal que se hallan entre las grietas de la roca "
         "que forma la montanya en la que esta excavada esta mina.\n");
      AddDetail(({"pilares","traviesas"}),
         "Los pilares son gruesos troncos de madera colocados "
         "verticalmente junto a las paredes de la galeria. Sobre ellos "
         "y colocados de forma horizontal estan las traviesas, gruesos "
         "listones de madera que a modo de vigas aguantan el peso del "
         "techo de la galeria.\n");
      AddDetail(({"piedras"}),
         "Son solo unos trozos de roca sin valor. Se debieron caer de "
         "alguna de las vagonetas cuando transportaba el mineral "
         "extraido al exterior de la mina.\n");
      SetIntNoise("Oyes el eco de tus pasos.\n");
      SetIntSmell("Huele a tierra reseca.\n");
      break;}
 case GAL_HUMEDA:{
      SetIntNoise("Oyes el eco de tus pasos y el gotear del agua desde el techo.\n");
      SetIntSmell("Huele a tierra humeda.\n");
      break;}
 }

return;
}


create() {
  ::create();
  SetIntShort("una galería de la mina");
  HazDescr(GAL_NORMAL,0);
  SetLocate("minas de Zarkam");
  SetIndoors(1);
  SetIntBright(0);
}
