//[Maler]
#include "./path.h"
inherit SIM_ROOM;
create() {
    ::create();
    SetLocate("Berat");
    SetIntShort("un puente de Berat");
    SetIntLong("Estás en el puente de acceso a Berat, es un puente de "
    "piedra muy estrecho, por el que únicamente pasa la gente a pie, es "
    "un puente resistente y seguro, permite cruzar uno de los riachuelos "
    "que rodean Berat. Al oeste esta la calle Koldar , y al este "
    "uno de los caminos de simauria.\n");
    SetIndoors(0);
    SetIntNoise("Escuchas el murmullo del río.\n");
    SetIntSmell("Huele a hierba fresca.\n");
    AddDetail("puente","Este puente permite cruzar uno de los riachuelos del"
    " delta que bordean el pueblo de Berat.\n");
    AddDetail(({"río","rio","riachuelo"}),"Es un riachuelo, poco caudaloso, típico"
    " de un delta.\n");
    AddExit("este","./cons2");
    AddExit("oeste","./ckol2");
}
