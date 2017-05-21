/****************************************************************************
Fichero: /guilds/kisalas/obj/mortero.c
Autor: Yalin
Fecha: 28/01/2008 19:11
Descripción: Mortero para preparar el ungüento.
****************************************************************************/

#include "path.h"
inherit THING;

create()
{
    ::create();
    SetShort("un mortero de piedra");
    SetLong("Es una vasija cilíndrica, hecha de piedra, con el fondo en forma de casquete "
        "esférico. Tallados en su superficie, ves dibujados unos extraños monstruos y "
        "símbolos.\nLa mano, igualmente de piedra, está sujeta al mortero con una cuerda, para "
        "evitar perderlo.\nMuy apropiado para preparar pociones y ungüentos.\n");
    AddSubDetail(({"mazo","mazo de piedra","mano","mano de piedra"}),"Es la mano del mortero. "
        "Consiste en un pequeño cilindro de piedra, redondeado en uno de los extremos, y "
        "afinado al otro extremo para cogerlo cómodamente y machacar lo que sea que se ha "
        "puesto en el mortero.\n");
    AddSubDetail(({"simbolos","símbolos","monstruos","dibujo","dibujos"}),"Grabados por toda "
        "la superficie del mortero, puedes ver dibujados unos monstruos que jamás viste, y que "
        "tal vez nunca existieron, y unos extraños símbolos que no te dicen absolutamente nada.\n");
    AddId(({"mortero","mortero de piedra","vasija","vasija de piedra","balsamo_mortero"}));
    SetWeight(400);
    SetValue(1000);
}
