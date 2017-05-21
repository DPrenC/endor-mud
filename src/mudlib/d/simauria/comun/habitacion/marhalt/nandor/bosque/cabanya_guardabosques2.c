/****************************************************************************
Fichero: cabanya_guardabosques2.c
Autor: Ratwor
Fecha: 03/02/2007
Descripci�n: La parte interna de la caba�a del guardabosques.
****************************************************************************/

#include "./path.h"

inherit SIM_ROOM;

create()
{
    ::create();
    SetLocate("bosque de Marhalt");
    SetIntShort("el interior de la caba�a del guardabosques");
    SetIntLong("Te encuentras en el interior de la caba�a de Malgdher el guardabosques"
        ", es una peque�a construcci�n simple y r�stica de madera de roble, donde "
        "poco mobiliario se puede apreciar, quiz� lo �nico que llame la atenci�n de "
        "la estancia sea la estanter�a de una de las paredes con unas curiosas "
        "figurillas.\n");
    SetIntBright(25);
    SetIntNoise("Escuchas la fauna del bosque que suena fuera de la caba�a.\n");
    SetIntSmell("Huele a madera y algunas hierbas.\n");
    AddDetail(({"mobiliario", "mesa", "silla", "camastro"}),
        "Tan s�lo adornan la estancia una silla, una mesa y un camastro.\n");
    AddDetail(({"pared", "paredes", "suelo", "techo"}), "De madera, claro.\n");
    AddDetail(({"figuritas","figuras", "figuras de madera", "figuritas de madera",
    "estanter�as", "estanterias", "estanteria", "estanter�a"}),
        "Sobre las estanter�as puedes observar distintas figuras de madera de distintos "
        "tama�os que representan personajes m�ticos o reales. Seguramente han sido "
        "talladas por el guardabosques y puestas all� como elemento decorativo"
        ", para contrarrestar un poco la sobriedad del lugar.\n");
    AddExit("fuera","./cabanya_guardabosques1");
    AddItem(PNJ("marhalt/malgdher"),REFRESH_DESTRUCT,1);
    AddItem(PNJ("gorat/sobrino"),REFRESH_DESTRUCT,1);
}

