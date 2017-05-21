// 07-06-08 [Angor] Creacion

#include "./path.h"
inherit GORAT("room_base.c");

create () {
    ::create();
    replace_program();
    SetIntShort("la plaza principal de Gorat");
    SetIntLong(
"La calle del rio comienza en esta esquina de la plaza principal de Gorat y "
"desciende hacia el este hasta la salida del pueblo. Por ella sube la brisa "
"encajonada entre las casas. Una fuente mana alegremente en el extremo "
"suroeste de la plaza.\n");

 AddDetail(({"fuente"}),
"La fuente está al otro extremo de la plaza al suroeste de aquí.\n");

 //AddExit("norte", GORAT("casa3a") );
 AddExit("sur", GORAT("casa2a") );
 AddExit("oeste", GORAT("plaza_1") );
 AddExit("suroeste", GORAT("plaza_2") );
 AddExit("este", GORAT("calle_rio_1") );

 SetIntNoise("La fuente mana alegremente.\n");
 SetIntSmell("Alguien debe estar cocinando en una de las casas cercanas.\n");
}
