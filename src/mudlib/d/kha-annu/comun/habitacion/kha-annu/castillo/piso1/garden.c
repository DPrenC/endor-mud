/* Coded by Yandros to AURORA MUD.
   Modificado por [i] Izet@Simauria, 29-Sep-1997.
11/05/2007, [Y] (Yalin): añado una fuente.
*/

#include "path.h"
#include <sounds.h>
inherit KHA_ROOM;

create()
{
    ::create();
    SetIntShort("el jardín de Estatuas del Castillo");
    SetIntLong("Este es el precioso jardín del Castillo de Kha-annu. Colocadas "
        "a lo largo del jardín ves unas estatuas increíblemente talladas. "
        "Todas ellas están ordenadas de una manera muy extraña... Parece "
        "como si te vigilaran, pero son solo imaginaciones.\nEn el centro se "
        "alza una imponente fuente.\n");
    SetIntBright(70);
    AddItem(OTRO("fuente"));
    AddExit("norte",CIUDAD+"avcastle6");
    AddExit("sur",PISO1+"patio1");
    AddDetail(({"jardin","jardín"}),"Es un encantador jardín, sería "
        "maravilloso un pequeño paseo perdiéndose en la distancia.\nHay un "
        "hermoso bosquecillo y pequeñas grutas.\n");
    AddDetail(({"estatua","estatuas"}),"Parecen hasta tener vida. "
        "Es increíble lo que se puede hacer hoy en día.\n");
    AddDetail(({"talla","tallas"}),"Son dibujos abstractos...\n");
    AddDetail(({"pilar","pilares"}),"Son grandes cilindros de mármol repletos "
        "de florituras.\n");
    AddDetail(({"floritura","florituras"}),"Pues son..., florituras, ¿qué "
        "quieres que te diga?\n");
    SetSoundEnvironment(SND_AMBIENTES("agua_fuente"));
}
