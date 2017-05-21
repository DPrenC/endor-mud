/******************************************************************
Fichero: cueva_base.c
Autor: kastwey
Creación: 18/11/2007
Descripción: La base para las cuevas de gorat. Aquí se pone el sonidillo y demás.
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
    
    
