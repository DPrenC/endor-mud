
#include "./path.h"
#define LOCATE "Algun lugar del norte de Marhalt"
inherit SIM_ROOM;

create ()
{
    ::create();
    SetLocate(LOCATE);
    SetIntShort("una sala subterr�nea");
    SetIntLong(
    "Est�s en un oscuro y fr�o t�nel, donde hay un mont�n de paja en un rinc�n. "
    "El t�nel comienza hacia el nordeste, y cerca del techo se puede ver un agujero.\n");
    SetIntBright(5);
    AddDetail(({"mont�n de paja", "monton de paja", "paja"}),
    "Es un mont�n de abundante paja, parece que alguien ha ca�do ah� recientemente...\n");
    AddDetail("agujero", "Es un agujero que est� all� arriba, casi en el techo, te "
    "ser�a imposible alcanzarlo.\n");
    AddExit("nordeste","./pasadizo00");
}
