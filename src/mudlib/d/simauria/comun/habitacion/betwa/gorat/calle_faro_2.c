// 07-06-08 [Angor] Creacion

#include "./path.h"
inherit GORAT("room_base.c");

create () {
    ::create();
    replace_program();
    SetIntShort("el sendero al faro de Gorat");
    SetIntLong(
"El sendero al faro de Gorat se va empinando a medida que te acercas a la "
"cumbre de la colina y dejas atrás el pueblo. La hierba crece larga en la "
"ladera entre las rocas y se agita con la brisa.\n");

  AddDetail(({"hierba"}),
"La hierba es alta y espigada. Crece por todas partes.\n");

    AddExit("suroeste", GORAT("calle_faro_1") );
    AddExit("norte", GORAT("calle_faro_3") );
}
