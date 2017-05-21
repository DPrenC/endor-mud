/*

    Nombre      : salaReunionesAyuntamientoEnalel
    Zona        : Poblado de Enalel
    Autor       : Tyflos
    Fecha       : 09/01/2005
    Descripción : Sala de reuniones del ayuntamiento

*/

#include "./path.h"
inherit SCHEDULER_ROOM;

create() {
    ::create();

    SetIntBright(50);
    SetLocate("Poblado de Enalel");
    SetIntShort("la sala de reuniones");
    SetIntLong("Estás en una enorme sala de paredes de madera acondicionada "
    "para la celebración de reuniones y discursos. Las sillas ocupan la mayor "
    "parte de las disposiciones de la sala dejando una zona libre en el centro "
    "para los oradores. Una escalera da paso a la parte inferior del edificio.\n");
    SetIntSmell("Un leve aroma a manzanas se percibe por todas partes.\n");
    AddDetail(({"silla","sillas"}),"Son unas simples sillas de madera sujetas al suelo "
    "de la sala.\n");
    AddExit("abajo",ENALHAB"poblado/varios/ayuntamiento");
    AddItem(ENALPNJ"ancianos/fhangos",REFRESH_DESTRUCT);
    AddItem(ENALPNJ"ancianos/bolge",REFRESH_DESTRUCT);
    SetMainRoom("./ayuntamiento");
    SetLastDest(ENALHAB"poblado/calles/calle06");
    SetNotifyExits(({}));
}
