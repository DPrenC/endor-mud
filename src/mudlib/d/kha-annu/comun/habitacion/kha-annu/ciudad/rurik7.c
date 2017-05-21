#include "./path.h"

inherit KHA_ROOM;
create() {
   ::create();

   SetIntShort("la calle Rurik.");
   SetIntLong(
"Estas en la calle del Gran Rurik cerca del noroeste de la ciudad. Las "
"Escuelas de Metalurgia e Ingenieria quedan ya hacia el sur. Unas enormes "
"y negras farolas de gas iluminan esta calle.\n");
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
"La Ilustrisima Escuela de Ingenieria se encuentra bastante al sur de donde "
"te encuentras. Esta fabricada en marmol y adornada con grandes estatuas del "
"mismo material... es una verdadera obra de arte.\n");
   AddDetail( ({"farola","farolas"}),
"Son unas farolas de unos cuatro metros hechas de un metal oscuro, su mision "
"es la iluminacion de toda la ciudad\n");
   AddExit("norte",CIUDAD+"rurik8");
   AddExit("sur",CIUDAD+"rurik6");
}