#include "./path.h"
#include <properties.h>
#include <materials.h>
#include <sounds.h>


inherit KHA_ROOM;

create()
{
    ::create();
    SetIntShort("el pasillo de las celdas");
    SetIntLong("Te encuentras en un pasillo que va de este a oeste.\nAl norte hay una puerta de "
        "lo que parece una celda. Los muros est�n perfectamente tallados.\nPuedes ver que hay "
        "m�s puertas en el pasillo.\n");
    SetIndoors(1);
    SetIntBright(10);
    SetIntNoise("Oyes unos quejidos que vienen de la parte este.\n");
    SetIntSmell("Huele a cerrado, el aire esta algo viciado\n");
    AddDetail(({"reja"}),"Atrav�s de la reja ves que hay una habitaci�n, pero el fondo y lo "
        "que hay en ella esta en penumbras.\n");
    AddDetail(({"muro","muros"}),"Los muros como siempre son de una calidad envidiable, �c�mo "
        "se nota que son enanos! Puedes distinguir una especie de runas.\n");
    AddDetail(({"runas"}),"Distingues unas runas en las piedras pero su antig�edad y su "
        "desgaste las hace ininteligibles.\n");
    AddExit("norte","./celda1");
    AddExit("sur","./2guardia");
    AddExit("este","./22pas");
    AddExit("oeste","./4pas");
    AddDoor("sur","la puerta del puesto de guardias",
        "Es una puerta de hierro que tiene una peque�a reja.\n",
        ({"puerta","puerta reforzada","puerta de guardias","puerta sur",
        "puerta de puesto","puerta de puesto de guardias"}),
        ([P_MATERIAL:M_HIERRO, P_DOOR_OPEN_SOUND:SND_SUCESOS("abrir_metalica"),
            P_DOOR_CLOSE_SOUND: SND_SUCESOS("cerrar_metalica")]));
    AddDoor("norte","la puerta de la celda",
        "Es una puerta de hierro que tiene una peque�a reja.\n",
        ({"puerta","puerta norte","puerta de celda","puerta de la celda","puerta con reja"}),2,
        ([P_DOOR_TRANSPARENCY:1,P_MATERIAL:M_HIERRO, P_DOOR_OPEN_SOUND:SND_SUCESOS("abrir_metalica"),
            P_DOOR_CLOSE_SOUND: SND_SUCESOS("cerrar_metalica")]));
    SetLocate("las mazmorras");
}
