/****************************************************************************
Fichero: /guilds/kisalas/obj/mortero.c
Autor: Yalin
Fecha: 28/01/2008 19:11
Descripci�n: Mortero para preparar el ung�ento.
****************************************************************************/

#include "path.h"
inherit THING;

create()
{
    ::create();
    SetShort("un mortero de piedra");
    SetLong("Es una vasija cil�ndrica, hecha de piedra, con el fondo en forma de casquete "
        "esf�rico. Tallados en su superficie, ves dibujados unos extra�os monstruos y "
        "s�mbolos.\nLa mano, igualmente de piedra, est� sujeta al mortero con una cuerda, para "
        "evitar perderlo.\nMuy apropiado para preparar pociones y ung�entos.\n");
    AddSubDetail(({"mazo","mazo de piedra","mano","mano de piedra"}),"Es la mano del mortero. "
        "Consiste en un peque�o cilindro de piedra, redondeado en uno de los extremos, y "
        "afinado al otro extremo para cogerlo c�modamente y machacar lo que sea que se ha "
        "puesto en el mortero.\n");
    AddSubDetail(({"simbolos","s�mbolos","monstruos","dibujo","dibujos"}),"Grabados por toda "
        "la superficie del mortero, puedes ver dibujados unos monstruos que jam�s viste, y que "
        "tal vez nunca existieron, y unos extra�os s�mbolos que no te dicen absolutamente nada.\n");
    AddId(({"mortero","mortero de piedra","vasija","vasija de piedra","balsamo_mortero"}));
    SetWeight(400);
    SetValue(1000);
}
