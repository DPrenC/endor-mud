/* **************************************************************** */
/* *                                                              * */
/* *         ARCHIVO:sendero21.c                                  * */
/* *         AUTOR: [a] Articman                                  * */
/* *         MODIFICADO: 3/02/02 Creación                         * */
/* **************************************************************** */
#include "path.h"
#include <colours.h>
inherit SIM_ROOM;

create()
{
    ::create();
    SetIntShort("el camino hacia Gundistyr");
    SetIntLong("Estás en una fría montaña, sobre un camino de tierra húmeda rodeado a los "
        "lados por altos pinos. El camino asciende hacia el norte y desciende hacia el "
        "suroeste uniendo el bosque de Nandor con la vieja torre de Gundistyr.\n");
    SetIndoors(0);
    AddDetail(({"camino","tierra","camino de tierra"}),"El camino es de color marrón oscuro "
        "debido a la tierra húmeda. Algunas piedras están dispersas por él.\n");
    AddDetail(({"pino","pinos","lados"}),"En los laterales del camino se alzan unos enormes "
        "pinos que forman un frondoso bosque por el cual no puedes adentrarte.\n");
    SetIntNoise("Escuchas una suave brisa.\n");
    SetIntSmell("Respiras profundamente y te llega el agradable olor de la naturaleza.\n");
    AddExit("norte","camino05");
    AddExit("suroeste","camino03");
}
