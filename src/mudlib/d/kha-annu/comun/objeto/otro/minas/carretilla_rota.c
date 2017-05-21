/***************************************************************************************
 ARCHIVO:	carretilla_rota.c
 AUTOR:		Riberales
 FECHA:		30/04/06
 Descripción: Una carretilla en las rota e inútil.
 ***************************************************************************************/

#include "path.h"


inherit THING;



public void create ()
{
    ::create();

    SetShort("una carretilla rota");
    SetLong("Es una caja de madera, con una rueda enganchada a ella a través"
              " de un eje, y unos mangos en el otro extremo para levantarla "
              "y transportar el mineral con mayor facilidad. Observas que la "
              "rueda está doblada y la caja tiene un gran agujero. Parece ser "
              "que se le ha debido romper a alguien.\n");

    SetIds(({"carretilla","carretilla rota"}));
    SetWeight(10000);
    SetNoGet("Esa carretilla ya es inservible, no vale la pena cogerla.\n");

}


