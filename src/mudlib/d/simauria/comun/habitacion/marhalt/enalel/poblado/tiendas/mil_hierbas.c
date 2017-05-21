/*

    Nombre      : tiendaMilHierbas
    Zona        : Poblado de Enalel
    Autor       : Tyflos
    Fecha       : 09/01/2005
    Descripci�n : tienda de hierbas m�gicas y semillas
                  El encargado de la tienda est� esperando a su patr�n, que se encuentra fuera.

*/

#include "./path.h"
#include <sounds.h>
#include <door.h>
#include <scheduler.h>
inherit SHOP;

create() {
    ::create();

    SetIntBright(30);
    SetLocate("Poblado de Enalel");
    SetIntShort("la tienda de las mil hierbas");
    SetIntLong("Est�s en la tienda conocida como las mil hierbas. Es una "
    "herborister�a peque�a repleta de botes, cajas y cuencos. La salida de "
    "la tienda est� hacia el sur.\n");
    SetIntNoise("Sonidos de burbujeos y respiraciones llenan la estancia.\n");
    SetIntSmell("Fuertes olores de todo tipo hacen que te cueste respirar.\n");
    SetShopkeeper(ENALPNJ"tenderos/rilkus");
    AddDetail(({"hierba","hierbas","bote","botes","cuenco","cuencos"}),"Si "
    "quieres saber lo que se vende aqu�, pide la lista de productos.\n");
    RemoveExit("almacen");
    AddExit("sur",ENALHAB"poblado/calles/calle04");
    AddDoor("sur", "la puerta de salida",
    "La puerta para salir a la calle del comercio.\n",
    ({"puerta", "puerta del sur", "puerta de salida", "puerta de la calle"}),
    ([P_DOOR_OPEN_SOUND: SND_SUCESOS("abrir_puerta_campanillas"),
P_DOOR_CLOSE_SOUND: SND_SUCESOS("abrir_puerta_campanillas"), P_DOOR_CLOSE_TIME : S_CLOSED_AT_NIGHT]));
    SetLastDest(ENALHAB"poblado/calles/calle04");
    SetNotifyExits("sur");

    AddArticle("/obj/herb",REFRESH_REMOVE,1);
}
