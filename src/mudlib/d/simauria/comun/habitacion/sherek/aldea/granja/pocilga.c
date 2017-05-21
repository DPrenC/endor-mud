/* Archivo:         pocilga.C
* Descripción:      pocilga de la granja de la aldea de Sloch.
* Autor: Lug y Yalin.
* Fecha: 18/05/2006
*/

#include "path.h"
inherit SHERALD("ceroom");

create()
{
    ::create();
    SetIntShort("una pocilga en la granja de la aldea de Sloch");
    SetIntLong("Estás en un cobertizo donde se guardan y crían algunos "
        "cerdos que, en el invierno, serán sacrificados y convertidos en "
        "diferentes viandas para la abadía de Sherek.\nHay unas pequeñas "
        "divisiones de madera que forman unos cubículos donde se encierra a "
        "los cochinos. Junto a las paredes hay también unos receptáculos "
        "donde se da el alimento a los animales.\n");
    SetIntSmell("¡puaj!, ¡verdaderamente se nota que aquí habitan muchos cerdos!\n");
    SetIntNoise("Escuchas los gruñidos de los animales.\n");
    SetIndoors(1);
    AddDetail(({"pared","paredes"}), "Están hechas de gruesos maderos sin "
        "desbastar.\n");
    AddDetail(({"techo"}), "Está construido de cañas y paja de las que "
        "cuelgan las telarañas.\n");
    AddDetail(({"telaraña","telarañas","telas de araña"}),"Pues eso, ves por "
        "los rincones las telas que han tejido las arañas, en este lugar y, "
        "teniendo en cuenta a quiénes lo habitan, suele haber mucho insecto.\n");
    AddItem(PNJ("sherek/aldea/cerdo"),REFRESH_DESTRUCT,6);
    AddExit("norte", SHERALD("granja/granja05"));
    AddItem(PNJ("sherek/aldea/aldeanog"),REFRESH_DESTRUCT,2);
}
