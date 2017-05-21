/*
DESCRIPCION  : Continuacion del muelle del puerto
FICHERO      : /d/simauria/comun/habitacion/simauria/berat/muelle04.c
MODIFICACION : 05-11-99 [Jorus@Simauria] Creacion.
[Ratwor] 02/07/2010 Añado estivadores y corrijo textos y sangrado.
--------------------------------------------------------------------------------
*/

#include "./path.h"
inherit SIM_ROOM;
create() {
    ::create();
    SetIntShort("un muelle de carga");
    SetIntLong("Te encuentras en el muelle del gran puerto de Berat. Aquí es constante "
    "el flujo de mercancías y por tanto de trabajadores del puerto.\n Esta zona "
    "es significativa para los marinos debido a las cercanas tabernas.\n");
    SetIndoors(0);
    SetIntNoise("Se escucha el típico sonido de puerto de mercancías, produciendo una "
    "curiosa armonía al mezclarse con el sonido de las olas azotando el muelle.\n");
    SetIntSmell("Huele a mar.\n");
    SetLocate("Berat");
    AddDetail(({"muelle","el muelle"}),"El muelle está hecho de madera, es bastante "
    "viejo pero sólido.\n");
    AddDetail(({"agua", "mar","el mar"}),"Te sientes empequeñecido ante la inmensidad "
    "del océano.\n");
    AddExit("oeste","./muelle03");
    AddExit("este","./muelle05");
    AddItem(PNJ("simauria/berat/marino"), REFRESH_DESTRUCT);
    if (d2()==1) AddItem(PNJ("simauria/berat/estivador"), REFRESH_DESTRUCT);
    if (d2()==1) AddItem(PNJ("simauria/berat/estivador"), REFRESH_DESTRUCT);
}

