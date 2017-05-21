#include "./path.h"

inherit KHA_ROOM;
create() {
   ::create();

   SetIntShort("la calle Rurik.");
   SetIntLong(
"Te encuentras en la zona noroeste de Kha-annu justo en el cruce entre las "
"calles Gran Rurik y Antharax. La calle del Gran Rurik es la zona cultural de "
"la ciudad y la calle Antharax es la parte comercial. En Antharax podras "
"encontrar todo lo necesiario para equiparte en pos de la aventura. Hacia el "
"sur ves las dos grandes Escuelas de Ingenieria y Metalurgia. Las grandes "
"farolas de gas pueblan los extremos de las calles.\n");
   SetIntBright(80);
   SetIndoors(1);
   AddDetail("escuela","?Cual de las dos escuelas deseas examinar?\n");
   AddDetail( ({"escuela de metalurgia","gran escuela de metalurgia",
	        "escuela metalurgia","Escuela de Metalurgia",
	        "Gran Escuela de Metalurgia"}),
"La Gran Escuela de Metalurgia esta hacia el sur de donde te encuentras.\n"
"Parece estar fabricada en metal, o quiza solo este recubierta de este "
"material. Es una construccion de dos plantas y no destacaria por su "
"majestusidad sino pareciera estar hecha de puro hierro.\n");
   AddDetail( ({"escuela de ingenieria","ilustrisima escuela de ingenieria",
	        "escuela ingenieria","Ilustrisima Escuela de Ingenieria"}),
"La Ilustrisima Escuela de Ingenieria se encuentra hacia el sur de donde "
"te encuentras. Esta fabricada en marmol y adornada con grandes estatuas del "
"mismo material... es una verdadera obra de arte.\n");
   AddDetail( ({"farola","farolas"}),
"Son unas farolas de unos cuatro metros hechas de un metal oscuro, su mision "
"es la de iluminacion de toda la ciudad.\n");

   AddExit("sur",CIUDAD+"rurik9");
   AddExit("este",CIUDAD+"antha1");
}