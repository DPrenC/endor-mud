/****************************************************************************
Fichero: galeria2.c
Autor: Lug y Yalin
Fecha: 26/06/2007
Descripci�n: galer�a subterr�nea en el bosque de Morak.
****************************************************************************/

#include "path.h"
inherit ROOM;

create()
{
    ::create();
    SetLocate("el valle de Azzor");
    SetIntShort("una galer�a subterr�nea");
    SetIntLong("Est�s en medio de una galer�a subterr�nea. La galer�a no es "
        "m�s que un estrecho pasadizo excavado en la roca viva de la monta�a, "
        "sin que aciertes a comprender muy bien por qui�n y para qu�.\nLa "
        "agobiante estrechez del pasaje, unido al enrarecimiento del aire, "
        "hacen que �ste sea un ambiente opresivo. No te sientes muy a gusto "
        "aqu�.\n");
    AddDetail(({"suelo","pared","paredes"}),"Las paredes y el suelo no son "
        "m�s que la roca que constituye esta monta�a.\n");
    AddDetail(({"roca","granito"}),"Es granito, puro granito, nada "
        "m�s que eso.\n");
    SetIndoors(1);
    SetIntBright(0);
    ForbidAllMagic("Inexplicablemente, tu magia ha desaparecido.\n");
    AddExit("abajo",BOSQUE_MORAK("galeria3"));
    AddExit("sur",BOSQUE_MORAK("galeria"));
}
