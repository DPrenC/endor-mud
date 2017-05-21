#include "./path.h"
#include <properties.h>
#include <door.h>
#include <sounds.h>

inherit KHA_ROOM;

create()
{
    ::create();
    SetIntShort("una celda");
    SetIntLong("La celda no es gran cosa, tiene un camastro al fondo y una escupidera. No te "
        "apetecería vivir aquí.\n");
    SetIndoors(1);
    SetIntBright(10);
    SetIntNoise("No oyes nada.\n");
    SetIntSmell("Yo de ti no olería.\n");
    AddItem(MONS+"gigante",REFRESH_DESTRUCT,1);
    AddExit("oeste","./17pas");
    AddDoor("oeste","la puerta del pasillo",
        "Es una puerta de hierro completamente lisa.\n",
        ({"puerta","puerta de pasillo","puerta del pasillo"}), "cdpnmpgs",
        ([P_DOOR_STATE:DOOR_CLOSED,P_DOOR_LOCK_STATE:DOOR_LOCKED,P_MATERIAL:M_HIERRO,
            P_DOOR_OPEN_SOUND:SND_SUCESOS("abrir_metalica"),P_DOOR_CLOSE_SOUND: SND_SUCESOS("cerrar_metalica")]));
    SetLocate("las mazmorras");
}
