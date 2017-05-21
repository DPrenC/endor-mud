/*
DESCRIPCION  : Dentro de ua casa
FICHERO      : /d/simauria/comun/habitacion/simauria/berat/hab3_1.c
MODIFICACION : 05-11-99 [Jorus@Simauria] Creación.
[Maler]
--------------------------------------------------------------------------------
*/
#include "./path.h"
inherit SIM_ROOM;

create() {
    ::create();
    SetLocate("berat");
    SetIntShort("la planta baja de una casa");
    SetIntLong("Estás en la planta baja de la casa, ciertamente está algo desordenada,.\n "
    " La habitación es amplia y bien iluminada, puedes ver una estantería "
    "llena de libros, una mesa de madera y un montón de cosas por el suelo. "
    "al fondo ves las escaleras que suben al segundo piso de la casa.\n");
    SetIntNoise("Lo único que escuchas es el distante rumor del mar.\n");
    SetIntSmell("Como cabe esperar, todo está impregnado con un olor a mar.\n");
    SetIntBright(30);

    AddDetail(({"estanteria","estantería","libros"}),"Los libros que están en la estantería "
    "parecen viejos y gastados,será mejor no tocarlos por si alguno se deshace en tus manos.\n");

    AddDetail(({"mesa","mesa de madera"}),"La mesa de madera está hecha de un solo tronco"
    " cortado longitudinalmente, parece robusta y está limpia.\n");

    AddDetail(({"escaleras","escaleras de madera"}),"Las escaleras que suben "
    "al segundo piso son bastante inclinadas, podrían ser peligrosas para alguien "
    "borracho.\n");

    AddExit("sur","./ctab2");
    AddExit("arriba","./hab3_2");
    AddDoor("sur", "la puerta de la calle");
}
