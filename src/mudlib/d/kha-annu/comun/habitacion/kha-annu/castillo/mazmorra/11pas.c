#include "./path.h"
#include <properties.h>
#include <materials.h>
#include <sounds.h>

inherit KHA_ROOM;

create()
{
    ::create();
    SetIntShort("el pasillo de las celdas");
    SetIntLong("Has llegado a la conclusión de que estás en una mazmorra.\nHay otra celda al "
        "norte, como en todos los corredores.\n");
    SetIndoors(1);
    SetIntBright(10);
    SetIntNoise("No oyes nada en especial.\n");
    SetIntSmell("Aquí no huele a nada.\n");
    AddDetail(({"muro","muros"}),"Los muros son sólidos, muy sólidos, y están perfectamente "
        "construidos.\nEn esta sección parece que hay un pequeño grabado.\n");
    AddDetail(({"grabado"}),"Representa unos enanos cavando en la roca, "
        "probablemente hacían la mazmorra.\n");
    AddDetail(({"reja"}),"A través de la reja, ves una celda.\n");
    AddExit("este",("12pas"));
     AddExit("oeste",("10esqui"));
    AddExit("norte","./celda7");
    AddDoor("norte","la puerta de la celda",
        "Es una puerta de hierro totalmente lisa.\n",
        ({"puerta","puerta de celda","puerta de la celda"}),2,
        ([P_MATERIAL:M_HIERRO, P_DOOR_OPEN_SOUND:SND_SUCESOS("abrir_metalica"),
            P_DOOR_CLOSE_SOUND: SND_SUCESOS("cerrar_metalica")]));
    SetLocate("las mazmorras");
}
