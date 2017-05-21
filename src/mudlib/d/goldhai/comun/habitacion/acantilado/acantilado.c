/****************************************************************************
Fichero acantilado base para los acantilados de goldhai
****************************************************************************/

#include <sounds.h>
#include "path.h"
inherit GROOM;

create()
{
    ::create();
    SetSoundEnvironment(SND_AMBIENTES("olas"), 10);
}
