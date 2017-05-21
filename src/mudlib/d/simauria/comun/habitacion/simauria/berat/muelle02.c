/*
DESCRIPCION  : Continuacion del muelle del puerto
FICHERO      : /d/siamuria/comun/habitacion/simauria/berat/muelle02.c
MODIFICACION : 05-11-99 [Jorus@Simauria] Creacion.
[Ratwor] 02/07/2010 A�ado estivadores y arrreglo textos y sangrado.
--------------------------------------------------------------------------------
*/

#include "./path.h"
inherit SIM_ROOM;
create() {
    ::create();
    SetIntShort("un muelle de carga");
    SetLocate("Berat");
    SetIndoors(0);
    SetIntLong("Te encuentras en el puerto de Berat, donde contin�a el incesante "
    "movimiento de mercanc�as, tanto de d�a como de noche.\n Hacia el oeste se "
    "acaba el puerto por llegar a uno de los extremos del muelle, mientras que "
    "hacia el este contin�a la vida portuaria.\n");

    SetIntNoise("Se escucha el tranquilizador sonido del agua del puerto en movimiento.\n");
    SetIntSmell("Huele al salitre del mar.\n");
    AddDetail(({"muelle","el muelle"}),"El muelle esta hecho de madera, parece "
    "bastante viejo pero s�lido.\n");
    AddDetail(({"mar", "agua", "el mar"}),"Te sientes empeque�ecido ante la inmensidad "
    "del oc�ano.\n");
    AddExit("oeste","./muelle01");
    AddExit("este","./muelle03");
    if (d2()==1) AddItem(PNJ("simauria/berat/estivador"), REFRESH_DESTRUCT);
    if (d2()==1) AddItem(PNJ("simauria/berat/estivador"), REFRESH_DESTRUCT);
}

