/****************************************************************************
Fichero: cabanya_guardabosques2.c
Autor: Ratwor
Fecha: 03/02/2007
Descripción: La parte interna de la cabaña del guardabosques.
****************************************************************************/

#include "./path.h"

inherit SIM_ROOM;

create()
{
    ::create();
    SetLocate("bosque de Marhalt");
    SetIntShort("el interior de la cabaña del guardabosques");
    SetIntLong("Te encuentras en el interior de la cabaña de Malgdher el guardabosques"
        ", es una pequeña construcción simple y rústica de madera de roble, donde "
        "poco mobiliario se puede apreciar, quizá lo único que llame la atención de "
        "la estancia sea la estantería de una de las paredes con unas curiosas "
        "figurillas.\n");
    SetIntBright(25);
    SetIntNoise("Escuchas la fauna del bosque que suena fuera de la cabaña.\n");
    SetIntSmell("Huele a madera y algunas hierbas.\n");
    AddDetail(({"mobiliario", "mesa", "silla", "camastro"}),
        "Tan sólo adornan la estancia una silla, una mesa y un camastro.\n");
    AddDetail(({"pared", "paredes", "suelo", "techo"}), "De madera, claro.\n");
    AddDetail(({"figuritas","figuras", "figuras de madera", "figuritas de madera",
    "estanterías", "estanterias", "estanteria", "estantería"}),
        "Sobre las estanterías puedes observar distintas figuras de madera de distintos "
        "tamaños que representan personajes míticos o reales. Seguramente han sido "
        "talladas por el guardabosques y puestas allí como elemento decorativo"
        ", para contrarrestar un poco la sobriedad del lugar.\n");
    AddExit("fuera","./cabanya_guardabosques1");
    AddItem(PNJ("marhalt/malgdher"),REFRESH_DESTRUCT,1);
    AddItem(PNJ("gorat/sobrino"),REFRESH_DESTRUCT,1);
}

