/*
fichero para que hereden las playas de limbo
*/

#include <sounds.h>

inherit ROOM;

create()
{
    ::create();
    SetSoundEnvironment(SND_AMBIENTES("olas"));
}
