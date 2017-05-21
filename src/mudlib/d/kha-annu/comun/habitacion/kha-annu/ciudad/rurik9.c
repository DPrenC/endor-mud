#include "./path.h"

inherit KHA_ROOM;
create() {
   ::create();

   SetIntShort("la calle Rurik.");
   SetIntLong(
"Estas en la parte norte de la calle del Gran Rurik. Hacia el sur puedes "
"divisar las bovedas de las Escuelas de Metalurgia e Ingenieria, mientras que, "
"hacia el este, un portal conduce al interior de una tienda en cuyo escaparate "
"ves objetos diversos. La entrada de la tienda esta iluminada con dos antorchas "
"y hay un letrero colgando que pone 'Herreria del Buen Zanul'.\n");
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
   AddDetail( ({"tienda","escaparate","herreria","entrada","portal"}),
"A tu derecha esta la entrada a la 'Herreria del Buen Zanul'. Parece ser una "
"tienda de armas por encargo en la Escuela de Ingenieria y fabricadas con los "
"metales de la Escuela de Metalurgia. Seguro que son bastante caras.\n");
   AddDetail( ({"escuela de metalurgia","gran escuela de ingenieria",
	        "escuela metalurgia","Gran Escuela de Metalurgia"}),
"La Gran Escuela de Metalurgia se alza hacia el norte. Parece estar fabricada "
"en metal, o quiza solo este recubierta de este material. Es una construccion "
"de dos plantas y no destacaria por su majestusidad sino pareciera estar hecha "
"de metal.\n");
   AddDetail( ({"farola","farolas"}),
"Son unas farolas de unos cuatro metros hechas de hierro puro, su mision es "
"la iluminacion de toda la ciudad\n");
   AddDetail( ({"antorcha","antorchas"}),
"Las antorchas son muy extranyas, no desprenden llamas. Mas bien parecen dos "
"trozos de madera con una extranya sustancia azul en la parte superior que "
"desprende la luz e ilumina la entrada a la tienda.\n");
   AddItem(MONS+"paseante",REFRESH_DESTRUCT,1);
   AddExit("norte",CIUDAD+"rurik10");
   AddExit("sur",CIUDAD+"rurik8");
   AddExit("este",TIENDAS+"tienda1");
}