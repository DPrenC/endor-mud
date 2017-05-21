/********************************************
*    Nombre: cueva01.c			    *
*    Localizacion: Cueva de los Trolls      *
*    Realizada por : Cajun, el ejecutor     *
*    Creado : 19-10-99                      *
*    Modificado: 20-10-99                   *
*********************************************/


#include "./path.h"
#include <properties.h>

inherit MARHCUEVA("cueva_base");

create () {
    ::create();
    SetIntShort("la entrada a una cueva");
    SetIntLong("La gruta se abre paso hacia el interior de la montaña como una garganta "
    "de lobo hambriento, bajando por una escarpada rampa natural llena de piedras "
    "sueltas, agujeros y grietas iregulares.\n  Las paredes de gélida roca gotean agua "
    "por todas partes y el frío y la humedad se apoderan de tus huesos.\n");
    SetIntSmell("Huele a humedad y basura.\n");
    AddDetail(({"pared","humedad","agua"}), "La humedad que cae por las "
    "paredes ayuda a que proliferen todo tipo de hongos.\n");
    AddDetail(({"rampa", "rampa natural"}), "Es una peligrosa rampa que lleva a un "
    "nivel inferior de la gruta.\n");
    AddExit("sur", "./cueva00");
    AddExit("abajo", "./cueva02");
}
