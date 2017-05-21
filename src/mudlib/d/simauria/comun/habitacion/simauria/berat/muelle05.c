/*
DESCRIPCION  : Continuacion del muelle del puerto
FICHERO      : /d/siamuria/comun/habitacion/simauria/berat/muelle05.c
MODIFICACION : 05-11-99 [Jorus@Simauria] Creacion.
[Ratwor] 02/07/2010 Añado estivadores y corrijo textos y sangrado.
--------------------------------------------------------------------------------
*/

#include "./path.h"
#include <door.h>
#include <properties.h>
#include <nightday.h>


inherit SIM_ROOM;

create() {
    ::create();
    SetIntShort("un muelle de carga");
    SetIntLong("Estás en uno de los tramos del muelle de Berat, el cual continúa de "
    "este a oeste.\n En esta parte te encuentras en la entrada de una de las tabernas "
    "del pueblo, la famosa 'Rosa de los Vientos', la más prestigiosa y tranquila de "
    "la zona.\n");
    AddDetail(({"letrero","cartel"}),"Mejor lo lees.\n");
    AddReadMsg(({"cartel", "letrero"}),
    "El cartel pone:\n"
    "Posada 'La Rosa de los Vientos'.\n");

    AddDetail(({"muelle","el muelle"}),"El muelle está hecho de madera, parece bastante "
    "viejo pero sólido.\n");
    AddDetail(({"taberna"}),
    "La taberna está situada junto a los muelles de atraque de los barcos, un lugar "
    "muy concurrido.\n");
    AddDetail(({"mar", "agua", "el mar"}),"Te sientes empequeñecido ante la inmensidad "
    "del océano.\n");

    SetIntNoise("Escuchas el griterío de fondo de la posada del oeste. También puedes oír "
    "el golpear de las olas contra el muelle.\n");
    SetIntSmell("Huele a agua de mar.\n");
    SetLocate("Berat");
    SetIndoors(0);

    AddExit("oeste","./muelle04");
    AddExit("este","./muelle06");
    AddExit("norte","./taberna2");
    AddDoor("norte", "la puerta de la taberna",
    "Esa puerta sale al muelle del puerto.\n",
    ({"puerta", "puerta del muelle", "puerta del sur"}),
    ([P_DOOR_CLOSE_TIME : ND_NIGHT]));
    AddItem(PNJ("simauria/berat/ciuda1"), REFRESH_DESTRUCT,d2());
    if (d2()==1) AddItem(PNJ("simauria/berat/estivador"), REFRESH_DESTRUCT);
    if (d2()==1) AddItem(PNJ("simauria/berat/estivador"), REFRESH_DESTRUCT);
}

