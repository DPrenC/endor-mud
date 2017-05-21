#include "./path.h"
#include <colours.h>
#include <properties.h>
#include <materials.h>
inherit KHA_ROOM;

create() {
   ::create();
   SetIntShort("la calle Rurik.");
   SetIntLong(
"Estas en la calle Rurik. Al norte quedan las Escuelas de Ingenieria y de "
"Metalurgia. Un murmullo de gente te hace mirar hacia el este, y ves la "
"famosa taberna del 'pequeño dragon azul' donde se reunen los aventureros a narrar "
"y cantar sus aventuras.\n");
   SetIntBright(80);
   SetIndoors(1);
   AddDetail("escuela","?Cual de las dos escuelas deseas examinar?\n");
   AddDetail( ({"escuela de metalurgia","gran escuela de metalurgia",
	        "escuela metalurgia","Escuela de Metalurgia",
	        "Gran Escuela de Metalurgia"}),
"La Gran Escuela de Metalurgia esta un poco al norte de donde te encuentras.\n"
"Parece estar fabricada en metal, o quiza solo este recubierta de este "
"material. Es una construccion de dos plantas y no destacaria por su "
"majestusidad sino pareciera estar hecha de puro hierro.\n");
   AddDetail( ({"escuela de ingenieria","ilustrisima escuela de ingenieria",
	        "escuela ingenieria","Ilustrisima Escuela de Ingenieria"}),
"La Ilustrisima Escuela de Ingenieria se encuentra un poco al sur de donde "
"te encuentras. Esta fabricada en marmol y adornada con grandes estatuas del "
"mismo material... es una verdadera obra de arte.\n");
   AddDetail( ({"farola","farolas"}),
"Son unas farolas de unos cuatro metros hechas de un metal oscuro, su mision "
"es la iluminacion de toda la ciudad\n");
   AddDetail( ({"casa","este"}),
"Es una lujosa vivienda particular.\n");

    AddExit("norte",CIUDAD+"rurik1");
    AddExit("sur",CIUDAD+"rurik_a");
    AddExit("este",TIENDAS+"taberna");
    AddDoor("este","la puerta de la taberna",
        "Es una enorme puerta de madera tallada.\n",
        ({"puerta","puerta este","puerta de taberna","puerta de la taberna","puerta de madera"}),GENDER_FEMALE,
        ([P_MATERIAL:M_MADERA,P_DOOR_STATE:DOOR_CLOSED]));
}
