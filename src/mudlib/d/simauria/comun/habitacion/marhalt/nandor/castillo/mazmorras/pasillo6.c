/****************************************************************************
Fichero: pasillo6.c
Autor: Ratwor
Fecha: 30/12/2007
Descripción: En el pasillo de las mazmorras del castillo.
****************************************************************************/

#include "./path.h"
#include <sounds.h>
#include <door.h>
#include <materials.h>
#include <properties.h>

inherit CASTILLO("mazmorras/mazmorras_base");
create () {
    ::create();
    SetIntLong(
    "Te encuentras en un oscuro pasadizo, donde  Apenas puedes ver nada. En la penumbra "
    "se adivinan tres puertas: al norte, al sur y al oeste.\n");
    AddExit("norte","./celda5");
    AddExit("sur","./celda6");
    AddExit("este","./pasillo5");
    AddExit("oeste","./celda7");
    AddDoor("norte", "la puerta de una celda",
    "Es una puerta metálica, pertenece a la  celda número 5.\n",
    ({"puerta", "puerta metálica", "puerta metalica", "puerta 5", "puerta del norte"}),
    ([P_DOOR_OPEN_SOUND: SND_SUCESOS("abrir_metalica"),
P_DOOR_CLOSE_SOUND: SND_SUCESOS("cerrar_metalica"), P_MATERIAL : M_HIERRO]));
    AddDoor("sur", "la puerta de una celda",
    "Es una puerta metálica, pertenece a la  celda número 6.\n",
    ({"puerta", "puerta metálica", "puerta metalica", "puerta 6", "puerta del sur"}),
    ([P_DOOR_OPEN_SOUND: SND_SUCESOS("abrir_metalica"),
    P_DOOR_CLOSE_SOUND: SND_SUCESOS("cerrar_metalica"), P_MATERIAL : M_HIERRO]));
    AddDoor("oeste", "la puerta de una celda",
    "Es una puerta metálica, pertenece a la  celda número 7.\n",
    ({"puerta", "puerta metálica", "puerta metalica", "puerta 7", "puerta del oeste"}),
    ([P_DOOR_OPEN_SOUND: SND_SUCESOS("abrir_metalica"),
P_DOOR_CLOSE_SOUND: SND_SUCESOS("cerrar_metalica"), P_MATERIAL : M_HIERRO]));
}