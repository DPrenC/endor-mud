#include "./path.h"

inherit KHA_ROOM;
create() {
   ::create();

   SetIntShort("la calle Rurik.");
   SetIntLong(
"Estas en el cruce entre la calle del Gran Rurik y la calle de Baldur. La "
"calle del Gran Rurik es la parte cultural de Kha-annu y la calle de Baldur es "
"la zona de aprendizaje de los enanos. Hacia el norte ves las dos grandes "
"Escuelas de Ingenieria y Metalurgia, mientras que hacia el este se situan "
"los gremios de esta gran ciudad.\n");
   SetIntBright(80);
   SetIndoors(1);
   AddDetail("escuela","?Cual de las dos escuelas deseas examinar?\n");
   AddDetail( ({"escuela de metalurgia","gran escuela de metalurgia",
	        "escuela metalurgia","Escuela de Metalurgia",
	        "Gran Escuela de Metalurgia"}),
"La Gran Escuela de Metalurgia esta hacia el norte de donde te encuentras.\n"
"Parece estar fabricada en metal, o quiza solo este recubierta de este "
"material. Es una construccion de dos plantas y no destacaria por su "
"majestusidad sino pareciera estar hecha de puro hierro.\n");
   AddDetail( ({"escuela de ingenieria","ilustrisima escuela de ingenieria",
	        "escuela ingenieria","Ilustrisima Escuela de Ingenieria"}),
"La Ilustrisima Escuela de Ingenieria se encuentra hacia el norte de donde "
"te encuentras. Esta fabricada en marmol y adornada con grandes estatuas del "
"mismo material... es una verdadera obra de arte.\n");
   AddDetail( ({"farola","farolas"}),
"Son unas farolas de unos cuatro metros hechas de un metal oscuro, su mision "
"es la iluminacion de toda la ciudad\n");

   AddItem(MONS+"paseante",REFRESH_DESTRUCT,1);
   AddExit("norte",CIUDAD+"rurik");
   AddExit("este",CIUDAD+"baldur1");
/*
   AddDoor("vivienda","este",VIVIENDAS+"casa1","porton",
           "Es un gran porton de madera.\n",1,0);
*/
}