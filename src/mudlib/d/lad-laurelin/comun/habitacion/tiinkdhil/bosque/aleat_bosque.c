#include "path.h"
inherit TBOSQUE("std_bosque");

//[l] funcion q oculta algunas salidas para que los jugatas tengan que rastrearpri
int salidas_cmd (){
	int perc, n, i, j, anim;
	object room, ob;
	mixed *ie, *ve;
	object *cont;
	ie=m_indices(QueryExits());
	//ve=m_values(QueryExits());
	j=random(sizeof(ie));
	for (i=0;i<j;i++){
		HideExit(ie[i],1);
	}
	return 0;
	
}

create(){
  string w;
  ::create();
  
  switch (random(19)) {
    case  0: w="Estás en una parte del bosque donde la gran cantidad de "
	     "vegetación te hace difícil el camino.\n";
	  break;

    case  1: w="Estás rodeado por una exhuberante vegetación. Las raices "
	     "de los árboles y arbustos se entrecruzan como pueden por entre el "
	     "suelo.\n";
	  break;

    case  2: w="Los grandes árboles y arbustos te rodean en "
	     "todas las direcciones posibles, dejandote algun que otro lugar "
	     "libre por donde poder colarte.\n";
	  break;

    case  3: w="Aunque no hay ninguna senda, hay ciertas zonas hacia las "
	     "que puedes avanzar a pesar de la espesura del bosque.\n";
	  break;

    case  4: w="Esta zona no esta demasiado transitada, a juzgar por las "
	     "pocas huellas de civilizacion que encuentras.\n";
	  break;

    case  5: w="Por alli por donde no hay arbustos puedes ver alguna que "
	     "otra huella de pequeños (y no tan pequeños) animales que habitan "
	     "por la zona.\n";
	  break;

    case  6: w="Este bosque es un claro ejemplo de lugar donde puedes "
	     "perderte con total facilidad.\n";
	  break;

    case  7: w="Las ramas de los árboles se cierran sobre tu cabeza, de una "
	     "manera que te recuerdan dedos entrelazados.\n";
	  break;

    case  8: w="Un suelo lleno de ramas caidas, hojas y pequeñas piedras, "
	     "asi como un techo natural formado por las frondosas ramas de los "
	     "árboles, son el único paisaje que puedes contemplar.\n";
	  break;

    case  9: w="No es nada aconsejable permanecer en lugares como este, "
	     "nadie sabe que se puede esconder tras los arbustos, las frondosas "
	     "ramas, o todavia peor, nadie sabe a que bestia te podrias encontrar.\n";
	  break;

    case 10: w="Grandes arboles forman este bosque. Por suerte, en esta zona "
	     "estan lo suficientemente separados como para que no impidan la "
	     "entrada del sol, de lo contrario sus copas no te dejarian "
	     "distinguir si es de noche o de dia.\n";
	 break;

    case 11: w="El bosque es mas denso y cerrado por aqui, para avanzar tienes "
	     "que evitar e ir apartando cientos de ramas, asi como sortear algun "
	     "que otro peñasco.\n";
	 break;

    case 12: w="Las ramas de los arboles se entrecruzan sobre tu cabeza protegiendote "
	     "de las posibles inclemencias del tiempo, aunque, por otra parte, no "
	     "contribuyen a la iluminación del bosque.\n";
	 break;

    case 13: w="El bosque es realmente denso, te encuentras rodeado de arboles que te "
	     "impiden el paso en muchas direcciones. Solo en algunos lugares por la "
	     "poca proximidad de unos arboles con otros o por las caprichosas formas "
	     "que estos adoptan serias capaz de pasar.\n";
	 break;

    case 14: w="La vegetación de este punto del bosque es más viva, aunque no sabes si "
	     "solo te lo parece a ti al no hallarte rodeado de los tetricos árboles "
	     "que forman el bosque.\n";
	 break;

    case 15: w="Algunos árboles se retuercen sobre sí mismo, otros forman extraños arcos "
	     "curvos. Estos árboles deben ser obra de la madre Naturaleza, pero a pesar "
	     "de sus formas, al menos puedes pasar entre ellos.\n";
	 break;

    case 16: w="Un suelo lleno de ramas caidas, hojas y pequeñas piedras, asi como un "
	     "techo natural formado por las frondosas ramas de los árboles, son el único "
	     "paisaje que puedes contemplar.\n";
	 break;

    case 17: w="El paisaje comienza a ser demasiado monotono, árboles y mas árboles, "
	     "hojas, ramas caidas, piedras y mas cosas. En este bosque es realmente "
	     "facil perder la orientación.\n";
	 break;

    case 18: w="Los grandes árboles te rodean produciendote una sensacion de protección "
	     "asi como algo de temor. En este oscuro bosque, habitan diversos tipos de "
	       "animales, algunos no muy amigables con los forasteros.\n";
	 break;
  }
  w=w+"Sientes como si el bosque estuviera vivo y los arboles se movieran solos\n"; 
	  
  SetIntLong(W(w));
  SetIntShort("un bosque frondoso");
  SetIntNoise("Escuchas el sonido de la naturaleza.\n");
  SetIntSmell("Huele a naturaleza.\n"); 
  SetLocate("el bosque de Tiinkdhil");
  AddDetail(({"huella", "huellas"}), "Son las huellas de pequeños animales.\n");
  AddDetail(({"rama", "ramas"}), "Las ramas se juntan por encima de tu cabeza.\n");
  SetIndoors(0);
}


