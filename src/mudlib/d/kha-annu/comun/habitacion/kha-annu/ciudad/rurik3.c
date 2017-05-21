#include "./path.h"

inherit KHA_ROOM;
create() {
   ::create();

   SetIntShort("la calle Rurik.");
   SetIntLong(
"Te encuentras en la calle del Gran rurik. Un poco hacia el norte ves el "
"enorme edificio de la Gran Escuela de Metalurgia de Kha-annu; y hacia el "
"queda la preciosa fachada de la Escuela de Ingenieria. A ambos lados de "
"la calle unos grandes faroles iluminan todo el paseo.\n");
   SetIntBright(80);
   SetIndoors(1);
   AddDetail("escuela","?Cual de las dos escuelas deseas examinar?\n");
   AddDetail( ({"escuela de ingenieria","ilustrisima escuela de ingenieria",
	        "escuela ingenieria","Escuela de Ingenieria",
	        "Ilustrisima Escuela de Ingenieria"}),
"La Gran Escuela de Ingenieria se encuentra al sur de donde te encuentras.\n"
"El edificio se alza majestuoso sobre las construcciones a su alrededor.\n"
"Esta fabricado en marmol y adornado con grandes estatuas del mismo material; "
"es una verdadera obra de arte.\n");
   AddDetail( ({"escuela de metalurgia","gran escuela de ingenieria",
	        "escuela metalurgia","Gran Escuela de Metalurgia"}),
"La Gran Escuela de Metalurgia se alza hacia el norte. Parece estar fabricada "
"en metal, o quiza solo este recubierta de este material. Es una construccion "
"de dos plantas y no destacaria por su majestusidad sino pareciera estar hecha "
"de puto hierro.\n");
   AddDetail( ({"farola","farolas"}),
"Son unas farolas de unos cuatro metros hechas de hierro puro, su mision es "
"la iluminacion de toda la ciudad\n");
   AddExit("norte",CIUDAD+"rurik4");
    AddExit("sur",CIUDAD+"rurik2");
}