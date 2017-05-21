/* **************************************************************** */
/* *                                                              * */
/* *         ARCHIVO:sendero19.c                                  * */
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
        "rodeado a los lados por altos pinos. El camino es relativamente llano, aunque parece "
        "que asciende ligeramente hacia el nordeste, donde se encuentra la torre de Gundistyr. "
        "Al suroeste cruza el camino que une la aldea de Nandor con los dominios de Sherek, "
        "muy lejos, al nordeste de estas tierras.\n");
    SetIndoors(0);
    AddDetail(({"camino","tierra","camino de tierra"}),"El camino es de color marr�n oscuro "
        "debido a la tierra h�meda. Algunas piedras est�n dispersas por �l.\n");
    AddDetail(({"pino","pinos","lados"}),"En los laterales del camino se alzan unos enormes "
        "pinos que forman un frondoso bosque por el cual no puedes adentrarte.\n");
    SetIntNoise("Escuchas una suave brisa.\n");
    SetIntSmell("Respiras profundamente y te llega el agradable olor de la naturaleza.\n");
    AddExit("nordeste","camino02");
    AddExit("suroeste",CNSH("camino11"));
}