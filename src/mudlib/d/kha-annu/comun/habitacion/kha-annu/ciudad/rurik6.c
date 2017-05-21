#include "./path.h"

inherit KHA_ROOM;
create() {
   ::create();

   SetIntShort("la calle Rurik.");
   SetIntLong(
"Te encuentras en la calle del Gran Rurik justo enfrente de la Gran Escuela de "
"Metalurgia de Kha-annu. La entrada a este edificio se encuentra a tu derecha.\n"
"Un poco mas hacia el sur ves la fachada de la Escuela de Metalurgia de la "
"ciudad en donde se estudian los nuevos metales y aleaciones entre estos. Unas "
"grandes farolas iluminan toda la calle de norte a sur.\n");
   SetIntBright(80);
   SetIndoors(1);
   AddDetail("escuela","?Cual de las dos escuelas deseas examinar?\n");
   AddDetail( ({"escuela de ingenieria","ilustrisima escuela de ingenieria",
	        "escuela ingenieria","Escuela de Ingenieria",
	        "Ilustrisima Escuela de Ingenieria"}),
"La Gran Escuela de Metalurgia se encuentra al sur de donde te encuentras.\n"
"El edificio se alza majestuoso sobre las construcciones a su alrededor.\n"
"Esta fabricado en marmol y adornado con grandes estatuas del mismo material; "
"es una verdadera obra de arte.\n");
   AddDetail( ({"entrada","derecha"}),
	     "A tu derecha esta la entrada a la Escuela de Metalurgia.\n");
   AddDetail( ({"escuela de metalurgia","gran escuela de ingenieria",
	        "escuela metalurgia","Gran Escuela de Metalurgia"}),
"La Gran Escuela de Metalurgia se alza justo ante ti. Parece estar fabricada "
"en metal, o quiza solo este recubierta de este material. Es una construccion "
"de dos plantas y no destacaria por su majestusidad sino pareciera estar hecha "
"de metal.\n");
   AddDetail( ({"farola","farolas"}),
"Son unas farolas de unos cuatro metros hechas de hierro puro, su mision es "
"la iluminacion de toda la ciudad\n");
   AddExit("norte",CIUDAD+"rurik7");
   AddExit("sur",CIUDAD+"rurik5");
   AddExit("este",META+"entradam");
}