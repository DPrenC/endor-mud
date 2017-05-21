#include "./path.h"
#include <properties.h>
#include <door.h>
#include <sounds.h>


inherit KHA_ROOM;

create()
{
    ::create();
    SetIntShort("una celda");
    SetIntLong("La celda no es gran cosa, tiene un camastro al fondo y una escupidera. No hay "
        "nada más, solo roca desnuda.\n");
    SetIndoors(1);
    SetIntBright(10);
    SetIntNoise("No oyes nada.\n");
    SetIntSmell("Olorcillo a humedad...\n");
    AddExit("este","./7pas");
    AddDoor("este","la puerta del pasillo",
        "Es una puerta de hierro, muy parecida al resto, pero no tiene rejas.\n",
        ({"puerta","puerta de pasillo","puerta del pasillo"}),
        ([P_MATERIAL:M_HIERRO, P_DOOR_OPEN_SOUND:SND_SUCESOS("abrir_metalica"),
            P_DOOR_CLOSE_SOUND: SND_SUCESOS("cerrar_metalica")]));
    AddItem(MONS+"ladron",REFRESH_DESTRUCT,1);
    SetLocate("las mazmorras");
}
