/**
 * /torrewiz/sotano/center.c
 */

#include "path.h"
inherit ROOM;

create() {
    ::create();

    SetIntShort("el sótano en la Torre de la Magia");
    SetIntLong(
"Te encuentras en el salon de Aprendices de Wizard. Todo esta muy solitario "
"pero parece bastante confortable. "
"La habitación está iluminada por una luz cálida y a lo largo de las paredes "
"ves tapices y escudos para relajarse observando el bello arte en la isla. "
"Puedes ver varias puertas, la más grande, al Norte, conduce al dormitorio, "
"las otras tres llevan a distintos talleres en los que los learners realizan "
"sus pruebas. Una escalera en el centro asciende a la entrada de la torre.\n");

    SetIntBright(70);
    SetIndoors(1);

    AddDetail("tapiz","tapices","Wao, cuantos tapices, no puedes ni decidir a cual mirar.\n");

    AddExit("arriba",TORRE("hall"));

    AddExit("norte", TORRE("sotano/dormitory"));
    AddExit("este",  TORRE("sotano/east_workshop"));
    AddExit("sur",   TORRE("sotano/south_workshop"));
    AddExit("oeste", TORRE("sotano/west_workshop"));
}
