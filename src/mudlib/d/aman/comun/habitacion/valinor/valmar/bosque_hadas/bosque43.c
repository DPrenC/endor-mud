/*****************************************************************************************
 ARCHIVO:       bosque43.c
 AUTOR:         Ztico
 FECHA:         26-04-2005
 DESCRIPCIÓN:   Bosque de las Hadas.
 COMENTARIOS:
*****************************************************************************************/

#include "./path.h"

inherit BASE_HADAS;

create()
{
    if(::create()) return 1;

    SetIntShort("un pasillo de la cueva");
    SetIntLong("Pese a ser una cueva subterránea, la claridad lo inunda todo y parece "
        "provenir de todas partes. Cerca del techo, flotando, hay una esfera azulada "
        "que oscila de un lado a otro de la estancia.\n");
    AddDetail(({"esfera", "esfera azulada"}), "Observas la esfera atentamente y ves "
        "que en su interior se arremolina una nube de humo de color añil, tras la "
        "cual puedes distinguir a duras penas la silueta de un algo.\n");
    AddDetail(({"humo", "nube de humo"}), "Gira en espirales y toma diversas formas "
        "cada cual más rara que la anterior.\n");
    AddDetail(({"silueta", "algo", "un algo"}), "Te fijas con más detenimiento y te "
        "das cuenta de que es un algo normal y corriente.\n");
    SetIndoors(1);
    SetIntBright(20);
    AddExit("norte", HAB_BOSQUE_HADAS("bosque48.c"));
    AddExit("sureste", HAB_BOSQUE_HADAS("bosque40.c"));
}
