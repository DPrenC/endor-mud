/*
DESCRIPCION  : Continuacion del muelle del puerto
FICHERO      : /d/simauria/comun/habitacion/simauria/berat/muelle04.c
MODIFICACION : 05-11-99 [Jorus@Simauria] Creacion.
[Ratwor] 02/07/2010 A�ado estivadores y corrijo textos y sangrado.
--------------------------------------------------------------------------------
*/

#include "./path.h"
inherit SIM_ROOM;
create() {
    ::create();
    SetIntShort("un muelle de carga");
    SetIntLong("Te encuentras en el muelle del gran puerto de Berat. Aqu� es constante "
    "el flujo de mercanc�as y por tanto de trabajadores del puerto.\n Esta zona "
    "es significativa para los marinos debido a las cercanas tabernas.\n");
    SetIndoors(0);
    SetIntNoise("Se escucha el t�pico sonido de puerto de mercanc�as, produciendo una "
    "curiosa armon�a al mezclarse con el sonido de las olas azotando el muelle.\n");
    SetIntSmell("Huele a mar.\n");
    SetLocate("Berat");
    AddDetail(({"muelle","el muelle"}),"El muelle est� hecho de madera, es bastante "
    "viejo pero s�lido.\n");
    AddDetail(({"agua", "mar","el mar"}),"Te sientes empeque�ecido ante la inmensidad "
    "del oc�ano.\n");
    AddExit("oeste","./muelle03");
    AddExit("este","./muelle05");
    AddItem(PNJ("simauria/berat/marino"), REFRESH_DESTRUCT);
    if (d2()==1) AddItem(PNJ("simauria/berat/estivador"), REFRESH_DESTRUCT);
    if (d2()==1) AddItem(PNJ("simauria/berat/estivador"), REFRESH_DESTRUCT);
}

