#include "./path.h"
#include <properties.h>
#include <materials.h>
#include <sounds.h>

inherit KHA_ROOM;

create()
{
    ::create();
    SetIntShort("el pasillo de las celdas");
    SetIntLong("El pasillo llega hasta otra puerta que queda al norte.\nEl pasillo tiene "
        "siempre un aspecto similar, la talla enana es impecable.\nHay un cartel sobre la "
        "puerta.\n");
    SetIndoors(1);    
    SetIntBright(10);
    SetIntNoise("Oyes ruidos que vienen de la puerta.\n");
    SetIntSmell("Huele muy mal, apesta.\n");
    AddDetail(({"muro","muros"}),"Un robusto muro de piedra. Éste tiene unas pequeñas tallas.\n");
    AddDetail(({"reja"}),"Está tapada, no puedes ver nada, hay un cartel.\n");
    AddDetail(({"talla","tallas"}),"Ves una escena de una batalla de enanos y orcos luchando "
        "despiadadamente, sin duda parte de la historia de Kha-annu.\n");
    AddExit("este","./3pas");
    AddExit("oeste","./5pas");
    AddExit("norte","./celda2");
    AddDoor("norte","la puerta de la celda",
        "Es una puerta de hierro que tiene una pequenya reja.\n",
        ({"puerta","puerta de celda","puerta de la celda"}),2,
        ([P_MATERIAL:M_HIERRO, P_DOOR_OPEN_SOUND:SND_SUCESOS("abrir_metalica"),
            P_DOOR_CLOSE_SOUND: SND_SUCESOS("cerrar_metalica")]));
    AddReadMsg(({"cartel"}),"Lees en el cartel:\nCuidado. Celda de orcos.\n"); 
    SetLocate("las mazmorras");
}
