
#include <properties.h>
#include "./path.h"
#include <sounds.h>

inherit SIM_ROOM;

create() {
    ::create();

    SetIntShort("la sala de trofeos");
    SetIntLong(
    "Las paredes de la estancia están repletas de trofeos de caza abatidos por "
    "un gran cazador.\n Un gran espejo descansa sobre una chimenea que se mantiene "
    "encendida todo el año.\n Dos grandes lamparas de cristal cuelgan del techo. "
    "En la pared sur hay un gran arco de piedra que da acceso al pasillo.\n");
    SetIntBright(45);
    AddDetail("trofeos",
    "Hay de todo: ciervos, jabalíes, rebecos,...\n");
    AddDetail(({"lámparas", "lamparas"}),
    "Están talladas imitando formas animales.\n");
    AddExit("sur", "./pasillo6");
    SetLocate("el castillo de Nandor");
    SetSoundEnvironment(SND_AMBIENTES("chimenea"));
}