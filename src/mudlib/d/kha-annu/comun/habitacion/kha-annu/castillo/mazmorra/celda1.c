/* celda1.c
Archivo de: Gorthem, El forjador
Email: jorcama@eui.upv.es
Creacion: 10.02.98
Modificacion: 25.02.98 */

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
        "apetecer�a vivir aqu�.\n");
    SetIndoors(1);
    SetIntBright(10);
    SetIntNoise("No oyes nada.\n");
    SetIntSmell("Yo de ti no oler�a.\n");
    AddDetail(({"reja"}),"Puedes ver el pasillo atrav�s de ella.\n");
    AddDetail(({"cama","camastro"}),"Es un caj�n de madera relleno de paja, no parece muy "
        "c�modo.\n");
    AddExit("sur","./3pas");
    AddDoor("sur","la puerta del pasillo",
        "Es una puerta de hierro que tiene una peque�a reja.\n",
        ({"puerta","puerta de pasillo","puerta del pasillo"}),
        ([P_DOOR_TRANSPARENCY:1,P_MATERIAL:M_HIERRO, P_DOOR_OPEN_SOUND:SND_SUCESOS("abrir_metalica"),
            P_DOOR_CLOSE_SOUND: SND_SUCESOS("cerrar_metalica")]));
    SetLocate("las mazmorras");
}
