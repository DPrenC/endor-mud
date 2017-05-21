/******************************************************************
Fichero: cueva_base.c
Autor: kastwey
Creaci�n: 18/11/2007
Descripci�n: La base para las cuevas de gorat. Aqu� se pone el sonidillo y dem�s.
****************************************************************************/

#include "./path.h"
#include <sounds.h>

inherit SIM_ROOM;

create()
{
    ::create();
    SetLocate("cueva de los trolls");
    SetSoundEnvironment(SND_AMBIENTES("gotas"), 50);
}
    
    
