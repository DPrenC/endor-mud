/****************************************************************************
Fichero: galeria2.c
Autor: Lug y Yalin
Fecha: 26/06/2007
Descripción: galería subterránea en el bosque de Morak.
****************************************************************************/

#include "path.h"
inherit ROOM;

create()
{
    ::create();
    SetLocate("el valle de Azzor");
    SetIntShort("una galería subterránea");
    SetIntLong("Estás en medio de una galería subterránea. La galería no es "
        "más que un estrecho pasadizo excavado en la roca viva de la montaña, "
        "sin que aciertes a comprender muy bien por quién y para qué.\nLa "
        "agobiante estrechez del pasaje, unido al enrarecimiento del aire, "
        "hacen que éste sea un ambiente opresivo. No te sientes muy a gusto "
        "aquí.\n");
    AddDetail(({"suelo","pared","paredes"}),"Las paredes y el suelo no son "
        "más que la roca que constituye esta montaña.\n");
    AddDetail(({"roca","granito"}),"Es granito, puro granito, nada "
        "más que eso.\n");
    SetIndoors(1);
    SetIntBright(0);
    ForbidAllMagic("Inexplicablemente, tu magia ha desaparecido.\n");
    AddExit("abajo",BOSQUE_MORAK("galeria3"));
    AddExit("sur",BOSQUE_MORAK("galeria"));
}
