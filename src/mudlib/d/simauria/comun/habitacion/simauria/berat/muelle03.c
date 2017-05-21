/*
DESCRIPCION  : Continuacion del muelle del puerto
FICHERO      : /d/siamuria/comun/habitacion/simauria/berat/muelle03.c
MODIFICACION : 05-11-99 [Jorus@Simauria] Creacion.
[Ratwor] 02/07/2010 Añado estivadores y corrijo textos y sangrado.
--------------------------------------------------------------------------------
*/

#include "./path.h"
inherit SIM_ROOM;
create() {
    ::create();
      SetIntShort("un muelle de carga");
      SetIntLong("Estás en el puerto de Berat, donde el muelle transcurre de este a "
      "oeste.\n Al norte puedes ver la entrada a una taberna, podrías entrar a tomar "
      "un trago si no tienes prisa por coger un barco.\n  En la pared puedes ver "
    "un cartel roñoso.\n");
    AddDetail(({"letrero", "cartel"}),"Mejor lo lees.\n");
    AddDetail(({"taberna"}),
    "La taberna está situada junto a los muelles de atraque de los barcos. Un lugar "
    "muy concurrido por lo que se puede escuchar el bullicio de dentro.\n");
    AddReadMsg(({"letrero", "cartel","cartel roñoso"}),
    "El cartel pone:\n"
    "Posada del Pirata Cojo.\n");
    AddDetail(({"muelle","el muelle"}),"El muelle está hecho de madera, parece "
    "bastante viejo pero sólido.\n");
    AddDetail(({"mar", "agua","el mar"}),"Te sientes empequeñecido ante la inmensidad "
    "del océano.\n");
    SetIntNoise("Oyes a las olas chocar contra el muelle mezclado con el ruído "
    "humano de la taberna.\n");
    SetIntSmell("Huele a agua de mar.\n");
    SetLocate("Berat");
    SetIndoors(0);

    AddExit("oeste","./muelle02");
    AddExit("este","./muelle04");
    AddExit("norte","./taberna1");
    AddDoor("norte", "la puerta de la taberna",
        "La puerta trasera de la taberna.\n",
    ({"puerta", "puerta del norte", "puerta trasera", "puerta de la taberna"}));
    if (d2()==1) AddItem(PNJ("simauria/berat/estivador"), REFRESH_DESTRUCT);
    if (d2()==1) AddItem(PNJ("simauria/berat/estivador"), REFRESH_DESTRUCT);
}

