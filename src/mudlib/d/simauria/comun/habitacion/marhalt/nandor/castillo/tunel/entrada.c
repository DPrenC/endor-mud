
#include "./path.h"
#define LOCATE "Algun lugar del norte de Marhalt"
inherit SIM_ROOM;

create ()
{
    ::create();
    SetLocate(LOCATE);
    SetIntShort("una sala subterránea");
    SetIntLong(
    "Estás en un oscuro y frío túnel, donde hay un montón de paja en un rincón. "
    "El túnel comienza hacia el nordeste, y cerca del techo se puede ver un agujero.\n");
    SetIntBright(5);
    AddDetail(({"montón de paja", "monton de paja", "paja"}),
    "Es un montón de abundante paja, parece que alguien ha caído ahí recientemente...\n");
    AddDetail("agujero", "Es un agujero que está allí arriba, casi en el techo, te "
    "sería imposible alcanzarlo.\n");
    AddExit("nordeste","./pasadizo00");
}
