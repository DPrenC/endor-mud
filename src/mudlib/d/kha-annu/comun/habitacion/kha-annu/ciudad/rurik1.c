#include "./path.h"

inherit KHA_ROOM;
create() {
   ::create();

   SetIntShort("la calle Rurik.");
   SetIntLong(
"Te encuentras en el cruce entre la avenida Grimly y la calle del Gran Rurik.\n"
"Gran Rurik es la calle cultural de la ciudad. Hacia el norte puedes ver dos "
"grandes edificios; el mas cercano es la Ilustrisima Escuela de Ingenieria "
"de Kha-annu donde se estudian los disenyos en el arte de la herreria y los "
"artefactos enanos y mas al norte divisas la Gran Escuela de Metalurgia de "
"Kha-annu en donde se investigan los metales existentes en las tierras de "
"Simauria. A lo largo de las calles unas grandes farolas se encargan de dar "
"luz a este recondito lugar.\n");
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
"La Ilustrisima Escuela de Ingenieria esta un poco al norte de donde estas.\n"
"Esta fabricada en marmol y adornada con grandes estatuas del mismo "
"material... es una verdadera obra de arte.\n");
   AddDetail( ({"farola","farolas"}),
"Son unas farolas de unos cuatro metros hechas de hierro puro, su mision es "
"la iluminacion de toda la ciudad\n");
   AddExit("norte",CIUDAD+"rurik1_1");
   AddExit("sur",CIUDAD+"rurik");
   AddExit("este",CIUDAD+"grimly1");
}