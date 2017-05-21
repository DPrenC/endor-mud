/* **************************************************************** */
/* *                                                              * */
/* *         ARCHIVO:sendero20.c                                  * */
/* *         AUTOR: [a] Articman                                  * */
/* *         MODIFICADO: 3/02/02 Creaci�n                         * */
/* **************************************************************** */

#include "path.h"
#include <colours.h>
inherit SIM_ROOM;

create()
{
    ::create();
    SetIntShort("el camino hacia Gundistyr");
    SetIntLong("Est�s en la falda de una fr�a monta�a, sobre un camino de tierra h�meda "
        "rodeado a los lados por altos pinos. El camino asciende hacia el nordeste y desciende "
        "hacia el oeste uniendo el bosque de Nandor con la vieja torre de Gundistyr. Hacia "
        "el sur, muy a lo lejos, divisas las altas monta�as pertenecientes al reino de "
        "Kha-Annu.\n");
    SetIndoors(0);
    AddDetail(({"monta�as","sur"}),"Hacia el sur, en el horizonte, divisas unas altas monta�as "
        "que forman parte del reino de Kha-Annu.\n");
    AddDetail(({"camino","tierra","camino de tierra"}),"El camino es de color marr�n oscuro "
        "debido a la tierra h�meda. Algunas piedras est�n dispersas por �l.\n");
    AddDetail(({"pino","pinos","lados"}),"En los laterales del camino se alzan unos enormes "
        "pinos que forman un frondoso bosque por el cual no puedes adentrarte.\n");
    SetIntNoise("Escuchas una suave brisa.\n");
    SetIntSmell("Respiras profundamente y te llega el agradable olor de la naturaleza.\n");
    AddExit("oeste","camino02");
    AddExit("nordeste","camino04");
}
