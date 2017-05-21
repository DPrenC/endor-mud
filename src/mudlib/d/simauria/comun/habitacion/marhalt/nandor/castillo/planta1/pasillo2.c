/****************************************************************************
Fichero: pasillo2.c
Autor: Ratwor
Fecha: 01/01/2008
Descripci�n: El pasillo de la planta baja de la torre del homenaje.
****************************************************************************/

#include "./path.h"

inherit SIM_ROOM;

create(){
    ::create();
SetIntBright(30);
SetIntShort("un ancho pasillo");
    SetIntLong("Est�s en un amplio pasillo enlosado y de techo alto que recorre la "
    "planta baja de la torre del homenaje. Grandes antorchas colocadas en soportes de "
    "bronce iluminan la zona. En la pared sur hay colgado un retrato a tama�o natural.\n");
    AddDetail("antorchas", "Antorchas de gran tama�o permanentemente encendidas.\n");
    AddDetail("soportes", "Antiguos soportes de bronce con el escudo de los Dhes-Bl�in "
    "grabado.\n");
    AddDetail(({"pared", "paredes"}), "La piedra de las paredes est� cuidadosamente "
    "pulida, ofreciendo un aspecto menos tosco que la cara exterior del muro de la torre.\n");
    AddDetail(({"suelo", "emlosado", "losas"}), "El suelo de la torre est� hecho de "
    "losas cuadradas bien pulidas y perfectamente encajadas, denotando la importancia "
    "del edificio en el que habita la nobleza.\n");
    AddDetail("retrato", "Es el retrato de una noble dama vestida de blanco. El rostro "
    "de altos p�mulos est� enmarcado por  largo cabello azabache recogido en una diadema "
    "de plata. Su belleza queda acentuada por la profunda tristeza que expresan sus ojos "
    "de un gris acerado.\n");
    AddExit("oeste", "./pasillo3");
    AddExit("este", "./pasillo1");
    SetLocate("el castillo de Nandor");
}


