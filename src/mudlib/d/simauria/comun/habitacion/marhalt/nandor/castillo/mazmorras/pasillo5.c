/****************************************************************************
Fichero: pasillo5.c
Autor: Ratwor
Fecha: 30/12/2007
Descripción: En el pasillo de las mazmorras.
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
    "se adivinan dos puertas al norte y al sur.\n");
    AddExit("norte","./celda3");
    AddExit("sur","./celda4");
    AddExit("este","./pasillo4");
    AddExit("oeste","./pasillo6");
    AddDoor("norte", "la puerta de una celda",
    "Es una puerta metálica, pertenece a la  celda número 3.\n",
    ({"puerta", "puerta metálica", "puerta metalica", "puerta 3", "puerta del norte"}),
    ([P_DOOR_OPEN_SOUND: SND_SUCESOS("abrir_metalica"),
    P_DOOR_CLOSE_SOUND: SND_SUCESOS("cerrar_metalica"), P_MATERIAL : M_HIERRO]));
    AddDoor("sur", "la puerta de una celda",
    "Es una puerta metálica, pertenece a la  celda número 4.\n",
    ({"puerta", "puerta metálica", "puerta metalica", "puerta 4", "puerta del sur"}),
    ([P_DOOR_OPEN_SOUND: SND_SUCESOS("abrir_metalica"),
    P_DOOR_CLOSE_SOUND: SND_SUCESOS("cerrar_metalica"), P_MATERIAL : M_HIERRO]));

}
