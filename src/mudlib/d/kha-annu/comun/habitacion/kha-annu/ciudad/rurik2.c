#include "./path.h"

inherit KHA_ROOM;
create() {
   ::create();

   SetIntShort("la calle Rurik.");
   SetIntLong(
"Estas en la calle Rurik, justo ante la Ilustrisima Escuela de Ingenieria de "
"la ciudad. La entrada a este edificio se encuentra a tu derecha. Un poco "
"mas al norte se alza la Gran Escuela de Metalurgia de Kha-annu donde se "
"investigan los nuevos metales que aparecen en las tierras de Simauria y "
"las posibles aleaciones entre ellos. Las farolas iluminan la calle de norte "
"a sur.\n");
   SetIntBright(80);
   SetIndoors(1);
   AddDetail("escuela","?Cual de las dos escuelas deseas examinar?\n");
   AddDetail( ({"escuela de metalurgia","gran escuela de metalurgia",
	        "escuela metalurgia","Escuela de Metalurgia",
	        "Gran Escuela de Metalurgia"}),
"La Gran Escuela de Metalurgia esta un poco al norte de donde te encuentras.\n"
"El edificio se alza majestuoso sobre las construcciones a su alrededor.\n"
"Parece estar fabricado en metal, o quiza solo este recubierto de este "
"material. Es una construccion de dos plantas y no destacaria por su "
"majestusidad sino pareciera estar hecha de puro hierro.\n");
   AddDetail( ({"escuela de ingenieria","ilustrisima escuela de ingenieria",
	        "escuela ingenieria","Ilustrisima Escuela de Ingenieria"}),
"La Ilustrisima Escuela de Ingenieria se alza justamente donde estas.\n"
"Esta fabricada en marmol y adornada con grandes estatuas del mismo "
"material... es una verdadera obra de arte.\n");
   AddDetail( ({"farola","farolas"}),
"Son unas farolas de unos cuatro metros hechas de hierro puro, su mision es "
"la iluminacion de toda la ciudad\n");
   AddExit("norte",CIUDAD+"rurik3");
   AddExit("sur",CIUDAD+"rurik1_1");
   AddExit("este",INGE+"entrada");
}