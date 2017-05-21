/*

    Nombre      : bancoEnalel
    Zona        : Poblado de Enalel
    Autor       : Tyflos
    Fecha       : 09/01/2005
    Descripción : Banco de Enalel

*/

#include "./path.h"
#include <sounds.h>
#include <door.h>
#include <scheduler.h>

inherit BANK;

create(){
    ::create();

    SetIntBright(50);
    SetLocate("Poblado de Enalel");
    SetBankName("enalel");
    SetIntShort("el banco de Enalel");
    SetIntLong("Estás en la oficina del banco de Enalel. Las nobles y "
    "rústicas maderas se mezclan con el duro acero para formar la estructura "
    "del edificio. La salida hacia la calle de las cosechas se encuentra hacia "
    "el sur.\n");

    SetKeeper(ENALPNJ"otros/filpus",REFRESH_DESTRUCT);
    AddItem(ENALPNJ"guardias/sargento",REFRESH_DESTRUCT,1);
    AddExit("sur",ENALHAB"poblado/calles/calle17");
    SetLastDest(ENALHAB"poblado/calles/calle17");
    SetNotifyExits("sur");
    AddDoor("sur", "la puerta de salida",
    "La puerta para salir a la calle de las cosechas.\n",
    ({"puerta", "puerta de salida", "puerta de la calle", "puerta del sur"}),
    ([P_DOOR_OPEN_SOUND: SND_SUCESOS("abrir_puerta_campanillas"),
    P_DOOR_CLOSE_SOUND: SND_SUCESOS("abrir_puerta_campanillas"),
    P_DOOR_CLOSE_TIME : S_CLOSED_AT_NIGHT]));
}