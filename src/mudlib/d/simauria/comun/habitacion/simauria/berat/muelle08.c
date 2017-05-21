/*
DESCRIPCION  : Continuacion del muelle del puerto
FICHERO      : /d/siamuria/comun/habitacion/simauria/berat/muelle08.c
MODIFICACION : 05-11-99 [Jorus@Simauria] Creacion.
[Ratwor] 02/07/2010 Añado estivadores y corrijo textos y sangrado.
--------------------------------------------------------------------------------
*/

#include "./path.h"
inherit SIM_ROOM;
create() {
    ::create();
    SetIntShort("un muelle de carga");
    SetIntLong("Estás en uno de los muelles de carga del puerto de Berat. Puedes ver multitud de "
    "cajas, fardos y rollos de cuerda apilados en orden esperando ser conducidos "
    "a los almacenes donde esperarán el momento de ser transportados a los mercados "
    "del interior para ser vendidos. Varios barcos están siendo descargados en "
    "este momento con la ayuda de grandes máquinas y los esfuerzos de numerosos "
    "estibadores.\n");

    SetIntNoise("En el aire se mezclan los gritos de los estibadores con el chirrido"
            "de las máquinas y el suave sonido de las olas y los chillidos de las"
            "aves marinas.\n");
    SetIntSmell("Huele a mar.\n");
    SetLocate("Berat");
    SetIndoors(0);
    AddDetail(({"muelle","el muelle"}),"El muelle está hecho de madera, parece "
    "bastante viejo pero sólido.\n");
    AddDetail(({"cajas","fardos","mercancías"}),"Esperan su turno para ser enviados a "
    "los mercados del interior.\n");
    AddDetail(({"rollos","rollos de cuerda"}),"Se trata de una cuerda gruesa y fuerte, "
    "ideal para tareas duras.\n");
    AddDetail("almacenes","Son grandes edificios de madera que sin duda están llenos "
    "de mercancías procedentes de todo el mundo.\n");
    AddDetail("barcos","Enormes barcos atracan aquí de día y de noche, trayendo "
    "mercancías procedentes de todos los confines del mundo.\n");
    AddDetail(({"máquinas","grandes máquinas","maquinas","grandes maquinas"}),
    "Mediante una ingeniosa combinación de cuerdas, poleas y esfuerzo muscular,"
    " estas máquinas permiten extraer de los barcos las cargas más pesadas con "
    "el mínimo esfuerzo.\n");
    AddDetail("estibadores","Numerosas cuadrillas de estibadores descargan los "
    "fardos menos voluminosos y los depositan en el muelle, donde otros se encargarán "
    "de introducirlos en los almacenes.\n");
    AddDetail(({"mar", "agua", "el mar"}),"Te sientes empequeñecido ante la inmensidad "
    "del océano.\n");
    AddExit("oeste","./muelle07");
    if (d2()==1) AddItem(PNJ("simauria/berat/estivador"), REFRESH_DESTRUCT);
    if (d2()==1) AddItem(PNJ("simauria/berat/estivador"), REFRESH_DESTRUCT);
    if (d2()==1) AddItem(PNJ("simauria/berat/estivador"), REFRESH_DESTRUCT);
}

