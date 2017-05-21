/*****************************************************************************
 AUTOR:		orome
 DETALLES:	posada abandonada
 *****************************************************************************/

#include "./path.h"
#include <door.h>
#include <sounds.h>
#include <properties.h>
#include <materials.h>

inherit ROOM;

create() {
    ::create();

    SetLocate("una posada abandonada");
    SetIntShort("un cuarto trastero");
    SetIntLong("Est�s en un oscuro cuarto que sirve de trastero para el viejo "
    "anciano de la familia. Aqu� guarda tanto objetos maravillosos como cosas "
    "inservibles.\n En el suelo hay una trampilla para salir de aqu�.\n");
    SetIntSmell("El aroma a manzanas se mezcla con el olor a polvo.\n");
    AddExit("abajo","./biblioteca");
    AddDoor("abajo", "una trampilla",
    "Es una peque�a trampilla para bajar a una planta inferior.\n",
    ({"trampilla", "abajo"}),
    ([P_DOOR_OPEN_SOUND: SND_SUCESOS("abrir_puerta_pequena"),
    P_DOOR_CLOSE_SOUND: SND_SUCESOS("cerrar_puerta_pequena")]));
}
