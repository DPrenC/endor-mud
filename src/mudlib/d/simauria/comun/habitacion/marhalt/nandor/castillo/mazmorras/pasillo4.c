/****************************************************************************
Fichero: pasillo4.c
Autor: Ratwor
Fecha: 30/12/2007
Descripción: El pasillo de las mazmorras del castillo.
****************************************************************************/

#include "./path.h"
#include <sounds.h>
#include <door.h>
#include <properties.h>
#include <materials.h>
inherit CASTILLO("mazmorras/mazmorras_base");
create () {
    ::create();
    SetIntLong(
    "Te encuentras en un oscuro pasadizo, donde Apenas puedes ver nada. En la penumbra "
    "se adivinan dos puertas al norte y al sur.\n");

    AddExit("norte","./celda1");
    AddExit("sur","./celda2");
    AddExit("este","./pasillo3");
    AddExit("oeste","./pasillo5");
    AddDoor("norte", "la puerta de una celda",
    "Es una puerta metálica, pertenece a la  celda número 1.\n",
    ({"puerta", "puerta metálica", "puerta metalica", "puerta 1", "puerta del norte"}),
    ([P_DOOR_OPEN_SOUND: SND_SUCESOS("abrir_metalica"),
    P_DOOR_CLOSE_SOUND: SND_SUCESOS("cerrar_metalica"), P_MATERIAL : M_HIERRO]));
    AddDoor("sur", "la puerta de una celda",
    "Es una puerta metálica, pertenece a la  celda número 2.\n",
    ({"puerta", "puerta metálica", "puerta metalica", "puerta 2", "puerta del sur"}),
    ([P_DOOR_OPEN_SOUND: SND_SUCESOS("abrir_metalica"),
    P_DOOR_CLOSE_SOUND: SND_SUCESOS("cerrar_metalica"), P_MATERIAL : M_HIERRO]));
}