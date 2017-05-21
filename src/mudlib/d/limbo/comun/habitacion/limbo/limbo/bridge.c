/****************************************************************************
Fichero base para el puente de limbo
****************************************************************************/

#include <sounds.h>

inherit ROOM;

create()
{
    ::create();
    SetSoundEnvironment(SND_AMBIENTES("olas"), 10);
}
    
