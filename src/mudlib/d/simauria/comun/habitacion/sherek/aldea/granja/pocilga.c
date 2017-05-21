/* Archivo:         pocilga.C
* Descripci�n:      pocilga de la granja de la aldea de Sloch.
* Autor: Lug y Yalin.
* Fecha: 18/05/2006
*/

#include "path.h"
inherit SHERALD("ceroom");

create()
{
    ::create();
    SetIntShort("una pocilga en la granja de la aldea de Sloch");
    SetIntLong("Est�s en un cobertizo donde se guardan y cr�an algunos "
        "cerdos que, en el invierno, ser�n sacrificados y convertidos en "
        "diferentes viandas para la abad�a de Sherek.\nHay unas peque�as "
        "divisiones de madera que forman unos cub�culos donde se encierra a "
        "los cochinos. Junto a las paredes hay tambi�n unos recept�culos "
        "donde se da el alimento a los animales.\n");
    SetIntSmell("�puaj!, �verdaderamente se nota que aqu� habitan muchos cerdos!\n");
    SetIntNoise("Escuchas los gru�idos de los animales.\n");
    SetIndoors(1);
    AddDetail(({"pared","paredes"}), "Est�n hechas de gruesos maderos sin "
        "desbastar.\n");
    AddDetail(({"techo"}), "Est� construido de ca�as y paja de las que "
        "cuelgan las telara�as.\n");
    AddDetail(({"telara�a","telara�as","telas de ara�a"}),"Pues eso, ves por "
        "los rincones las telas que han tejido las ara�as, en este lugar y, "
        "teniendo en cuenta a qui�nes lo habitan, suele haber mucho insecto.\n");
    AddItem(PNJ("sherek/aldea/cerdo"),REFRESH_DESTRUCT,6);
    AddExit("norte", SHERALD("granja/granja05"));
    AddItem(PNJ("sherek/aldea/aldeanog"),REFRESH_DESTRUCT,2);
}
