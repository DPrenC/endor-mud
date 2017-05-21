/* Coded by Yandros to AURORA MUD.
   Modificado por [i] Izet@Simauria, 29-Sep-1997.
11/05/2007, [Y] (Yalin): a�ado una fuente.
*/

#include "path.h"
#include <sounds.h>
inherit KHA_ROOM;

create()
{
    ::create();
    SetIntShort("el jard�n de Estatuas del Castillo");
    SetIntLong("Este es el precioso jard�n del Castillo de Kha-annu. Colocadas "
        "a lo largo del jard�n ves unas estatuas incre�blemente talladas. "
        "Todas ellas est�n ordenadas de una manera muy extra�a... Parece "
        "como si te vigilaran, pero son solo imaginaciones.\nEn el centro se "
        "alza una imponente fuente.\n");
    SetIntBright(70);
    AddItem(OTRO("fuente"));
    AddExit("norte",CIUDAD+"avcastle6");
    AddExit("sur",PISO1+"patio1");
    AddDetail(({"jardin","jard�n"}),"Es un encantador jard�n, ser�a "
        "maravilloso un peque�o paseo perdi�ndose en la distancia.\nHay un "
        "hermoso bosquecillo y peque�as grutas.\n");
    AddDetail(({"estatua","estatuas"}),"Parecen hasta tener vida. "
        "Es incre�ble lo que se puede hacer hoy en d�a.\n");
    AddDetail(({"talla","tallas"}),"Son dibujos abstractos...\n");
    AddDetail(({"pilar","pilares"}),"Son grandes cilindros de m�rmol repletos "
        "de florituras.\n");
    AddDetail(({"floritura","florituras"}),"Pues son..., florituras, �qu� "
        "quieres que te diga?\n");
    SetSoundEnvironment(SND_AMBIENTES("agua_fuente"));
}
