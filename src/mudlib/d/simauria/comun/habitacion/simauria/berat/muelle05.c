/*
DESCRIPCION  : Continuacion del muelle del puerto
FICHERO      : /d/siamuria/comun/habitacion/simauria/berat/muelle05.c
MODIFICACION : 05-11-99 [Jorus@Simauria] Creacion.
[Ratwor] 02/07/2010 A�ado estivadores y corrijo textos y sangrado.
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
    SetIntLong("Est�s en uno de los tramos del muelle de Berat, el cual contin�a de "
    "este a oeste.\n En esta parte te encuentras en la entrada de una de las tabernas "
    "del pueblo, la famosa 'Rosa de los Vientos', la m�s prestigiosa y tranquila de "
    "la zona.\n");
    AddDetail(({"letrero","cartel"}),"Mejor lo lees.\n");
    AddReadMsg(({"cartel", "letrero"}),
    "El cartel pone:\n"
    "Posada 'La Rosa de los Vientos'.\n");

    AddDetail(({"muelle","el muelle"}),"El muelle est� hecho de madera, parece bastante "
    "viejo pero s�lido.\n");
    AddDetail(({"taberna"}),
    "La taberna est� situada junto a los muelles de atraque de los barcos, un lugar "
    "muy concurrido.\n");
    AddDetail(({"mar", "agua", "el mar"}),"Te sientes empeque�ecido ante la inmensidad "
    "del oc�ano.\n");

    SetIntNoise("Escuchas el griter�o de fondo de la posada del oeste. Tambi�n puedes o�r "
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

