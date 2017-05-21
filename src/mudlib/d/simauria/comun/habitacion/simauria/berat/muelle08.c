/*
DESCRIPCION  : Continuacion del muelle del puerto
FICHERO      : /d/siamuria/comun/habitacion/simauria/berat/muelle08.c
MODIFICACION : 05-11-99 [Jorus@Simauria] Creacion.
[Ratwor] 02/07/2010 A�ado estivadores y corrijo textos y sangrado.
--------------------------------------------------------------------------------
*/

#include "./path.h"
inherit SIM_ROOM;
create() {
    ::create();
    SetIntShort("un muelle de carga");
    SetIntLong("Est�s en uno de los muelles de carga del puerto de Berat. Puedes ver multitud de "
    "cajas, fardos y rollos de cuerda apilados en orden esperando ser conducidos "
    "a los almacenes donde esperar�n el momento de ser transportados a los mercados "
    "del interior para ser vendidos. Varios barcos est�n siendo descargados en "
    "este momento con la ayuda de grandes m�quinas y los esfuerzos de numerosos "
    "estibadores.\n");

    SetIntNoise("En el aire se mezclan los gritos de los estibadores con el chirrido"
            "de las m�quinas y el suave sonido de las olas y los chillidos de las"
            "aves marinas.\n");
    SetIntSmell("Huele a mar.\n");
    SetLocate("Berat");
    SetIndoors(0);
    AddDetail(({"muelle","el muelle"}),"El muelle est� hecho de madera, parece "
    "bastante viejo pero s�lido.\n");
    AddDetail(({"cajas","fardos","mercanc�as"}),"Esperan su turno para ser enviados a "
    "los mercados del interior.\n");
    AddDetail(({"rollos","rollos de cuerda"}),"Se trata de una cuerda gruesa y fuerte, "
    "ideal para tareas duras.\n");
    AddDetail("almacenes","Son grandes edificios de madera que sin duda est�n llenos "
    "de mercanc�as procedentes de todo el mundo.\n");
    AddDetail("barcos","Enormes barcos atracan aqu� de d�a y de noche, trayendo "
    "mercanc�as procedentes de todos los confines del mundo.\n");
    AddDetail(({"m�quinas","grandes m�quinas","maquinas","grandes maquinas"}),
    "Mediante una ingeniosa combinaci�n de cuerdas, poleas y esfuerzo muscular,"
    " estas m�quinas permiten extraer de los barcos las cargas m�s pesadas con "
    "el m�nimo esfuerzo.\n");
    AddDetail("estibadores","Numerosas cuadrillas de estibadores descargan los "
    "fardos menos voluminosos y los depositan en el muelle, donde otros se encargar�n "
    "de introducirlos en los almacenes.\n");
    AddDetail(({"mar", "agua", "el mar"}),"Te sientes empeque�ecido ante la inmensidad "
    "del oc�ano.\n");
    AddExit("oeste","./muelle07");
    if (d2()==1) AddItem(PNJ("simauria/berat/estivador"), REFRESH_DESTRUCT);
    if (d2()==1) AddItem(PNJ("simauria/berat/estivador"), REFRESH_DESTRUCT);
    if (d2()==1) AddItem(PNJ("simauria/berat/estivador"), REFRESH_DESTRUCT);
}

