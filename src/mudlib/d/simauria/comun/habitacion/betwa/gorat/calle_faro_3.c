// 07-06-08 [Angor] Creacion

#include "./path.h"
inherit GORAT("room_base.c");

create () {
    ::create();
    replace_program();
    SetIntShort("el sendero al faro de Gorat");
    SetIntLong(
"El sendero gira aqu� bruscamente mientras asciende camino del faro. Desde "
"aqu� tienes una buena vista de la desembocadura del r�o Gudagora al norte "
"al alcanzar el gran golfo de Betria. La brisa mece la hierba que crece por "
"todas partes. Las primera casas del pueblo de Gorat quedan al suroeste.\n");

  AddDetail(({"hierba"}),
"La hierba es alta y espigada. Crece por todas partes.\n");

    AddExit("sueste", GORAT("plaza_1") );
    AddExit("sur", GORAT("calle_faro_2") );
}
