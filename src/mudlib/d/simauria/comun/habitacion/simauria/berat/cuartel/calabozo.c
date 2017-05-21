/****************************************************************************
Fichero: calabozo.c
Autor: Dharkus
Fecha: 20/04/2010
Descripci�n: Un calabozo para el cuartel de Berat
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
    SetIntShort("el calabozo de Berat");
    SetIntLong("Este es el calabozo de Berat.\n Es una sala cuadrada muy poco "
    "iluminada, donde la guardia suele encerrar a los posibles malhechores que "
    "deambulen por la zona y sean pillados en delito.\n La decoraci�n es apenas "
    "existente; s�lo un peque�o ventanuco por donde entra la d�bil luz, y las manchas "
    "de humedad que se pueden contemplar en las paredes, es apreciable a primer golpe "
    "de vista.\n Al fondo se observa un inc�modo camastro de paja, donde maldormir "
    "si la estancia aqu� fuera prolongada.\n");
    AddDetail("ventanuco", "Es una peque�a ventana que apenas deja entrar la luz "
    "exterior.\n Mirando por ella, puedes observar parte del puerto de Berat.\n");
    AddDetail(({"camastro","cama"}),"Se trata de un murete con un hueco donde "
    "hay un mont�n de paja formando una yacija.\n");
    SetIntNoise("Apenas se puede escuchar los t�picos sonidos del puerto.\n");
    SetIntSmell("Hueles a humedad.\n");
    SetIntBright(20);
    AddExit("oeste", "./rellano1");
    AddDoor("oeste", "una puerta met�lica","Una vieja puerta met�lica para cerrar "
    "el calabozo.\n", ({"puerta", "puerta met�lica", "puerta metalica",
      "puerta del oeste", "puerta del calabozo"}),
      ([P_DOOR_OPEN_SOUND: SND_SUCESOS("abrir_metalica"),
    P_DOOR_CLOSE_SOUND: SND_SUCESOS("cerrar_metalica"),
    P_DOOR_STATE:DOOR_CLOSED, P_DOOR_LOCK_STATE:DOOR_LOCKED,
    P_MATERIAL : M_HIERRO]), "llave_calabozo_berat");
    AddItem(PNJ("simauria/berat/preso"),REFRESH_DESTRUCT);
}
