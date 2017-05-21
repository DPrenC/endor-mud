/****************************************************************************
Fichero: rellano1.c
Autor: Dharkus
Fecha: 27/04/2010
Descripción: Un rellano en el cuartel de Berat
****************************************************************************/


#include "./path.h"
#include <door.h>
#include <sounds.h>
#include <properties.h>
inherit ROOM;

create()
{
    ::create();
    SetLocate("Berat");
    SetIntShort("un rellano en el cuartel de Berat");
    SetIntLong("Es un rellano que contiene las escaleras para subir al piso superior.\n "
    "Al este está la puerta que conduce al calabozo, y al oeste el cuartel.\n");
    AddDetail("escaleras","Son unas escaleras de madera que suben a la planta superior"
    " del cuartel.\n");
    SetIntNoise("Escuchas el sonido de los guardias deambulando por la zona.\n");
    SetIntBright(20);
    AddExit("este", "./calabozo");
    AddExit("oeste", "./cuartel");
    AddExit("arriba", "./rellano2");
    AddDoor("este", "la puerta del calabozo",
    "Una vieja puerta metálica para cerrar el calabozo.\n",
    ({"puerta", "puerta metálica", "puerta metalica", "puerta del este", "puerta del calabozo"}),
    ([P_DOOR_OPEN_SOUND: SND_SUCESOS("abrir_metalica"),
    P_DOOR_STATE:DOOR_CLOSED, P_DOOR_LOCK_STATE:DOOR_LOCKED,
    P_DOOR_CLOSE_SOUND: SND_SUCESOS("cerrar_metalica"), P_MATERIAL : M_HIERRO]), 
    "llave_calabozo_berat");
}
