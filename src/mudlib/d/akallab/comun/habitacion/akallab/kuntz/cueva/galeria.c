/*
DESCRIPCION  : galeria tipo para la zona troll
FICHERO      : /d/akallab/comun/habitacion/akallab/kuntz/cueva/galeria.c
MODIFICACION : 03-11-99 [Angor@Simauria] Creacion
*/

#include "./path.h"
#include AK_MACRO
#include "../sys/galeria.h"

inherit ROOM;

/*#define TIPOGAL 3
#define GAL_RANDOM 0
#define GAL_NORMAL 1
#define GAL_HUMEDA 2
#define GAL_NORMAL_CRUCE 2*/

void HazDescr(int tipo, int desc){

  if (tipo==0) tipo=random(TIPOGAL)+1;
  switch(tipo) {
  case GAL_NORMAL:{
      if ((desc==0)||(desc<0)||(desc>2)) desc=random(4);
      switch(desc){
      case 0:{
            SetIntLong("Esta galeria continua su avance por el interior de la "
                "tierra. El ambiente es seco y polvoriento y el aire esta un poco "
                "viciado. En algunos lugares de las paredes se observan "
                "restos de posibles vetas de mineral entre los pilares.\n");break;}
      case 1:{
            SetIntLong("El aire seco y viciado de esta galeria te reseca la "
                "garganta a medida que avanzas por ella. En esta zona de la "
                "galeria el techo es bastante bajo y has de andar con cuidado "
				"para no golpearte con algun saliente.\n");break;}
		    AddDetail(({"techo"}),
		        "Es bastante bajo, ten cuidado de no golpearte con el.\n");
      case 2:{
            SetIntLong("En esta zona la galeria por la que avanzas se ensancha "
			    "siguiendo la forma de la roca. Un aire seco y viciado te reseca "
				"la garganta y te hace desear estar en cualquier otro lugar.\n");break;}
		    AddDetail(({"galeria"}),
		        "Aqui es mas ancha que en otros lugares.\n");
      case 3:{
            SetIntLong("Solo el eco de tus pasos te acompanya a medida que "
                "avanzas por esta solitaria galeria. El aire es seco y "
				"polvoriento, lo que dificulta la respiracion. Observas "
                "algunas piedras en el suelo posiblemente desprendidas del "
				"techo.\n");break;}
      }
      AddDetail(({"vetas","paredes"}),
         "En algunos lugares de las paredes se observan restos de "
         "posibles vetas de mineral, cosa bastante comun en estas tierras "
		 "donde los orcos llevan anyos explotandodo la mineria. Las vetas "
		 "son capas de mineral o metal que se hallan entre las grietas de "
		 "la roca que forma las montanyas bajo las que te hallas.\n");
      AddDetail(({"piedras"}),
         "Son solo unos trozos de roca sin valor. Se debieron caer de "
         "alguno de los salientes del techo de la galeria, tal vez por "
		 "el desgaste del tiempo o por algun movimiento sismico.\n");

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
  SetIntShort("una galería en el interior de la tierra");
  HazDescr(GAL_NORMAL,0);
  SetLocate("cavernas Troll en Kuntz");
  SetIndoors(1);
  SetIntBright(0);
}

