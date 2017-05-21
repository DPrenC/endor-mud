#include "./path.h"
#include <properties.h>
#include <materials.h>
#include <sounds.h>
inherit KHA_ROOM;


create()
{
    ::create();
    SetIntShort("La sala de Guardia");
    SetIntLong("Ésta es la sala de guardia, la antesala a las mazmorras. Ves una mesa y un par "
        "de sillas de madera, donde los guardias hacen su vigilancia. Hay también un pequeño "
        "camastro. Al fondo ves una enorme puerta reforzada que probablemente conduzca hacia "
        "las celdas.\n");
    SetIntBright(100);
    SetIntSmell("Huele un poco a humedad pero se puede respirar.\n");
    SetIntNoise("Hay un silencio absoluto.\n");
    SetIndoors(1);    
    AddDetail(({"mesa","mesa de guardias"}),"Es una mesa de piedra sin nada en especial. "
        "Estaban jugando con unas cartas.\n");
    AddDetail(({"cartas"}),"Una baraja enana.\n");
    AddExit("sur","./1entrada");
    AddExit("norte","./3pas");
    AddDoor("norte","la puerta de las mazmorras",
        "Es una gran puerta de hierro reforzada.\n",
        ({"puerta","puerta reforzada","puerta de mazmorras","puerta de las mazmorras"}),2,
        ([P_MATERIAL:M_HIERRO, P_DOOR_OPEN_SOUND:SND_SUCESOS("abrir_metalica"),
            P_DOOR_CLOSE_SOUND: SND_SUCESOS("cerrar_metalica")]));
    AddItem(MONS+"mazguar.c",REFRESH_DESTRUCT,2);
    SetLocate("mazmorra");
}

