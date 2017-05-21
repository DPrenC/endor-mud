/*
DESCRIPCION  : Dentro de ua casa
FICHERO      : /d/simauria/comun/habitacion/simauria/berat/hab3_1.c
MODIFICACION : 05-11-99 [Jorus@Simauria] Creaci�n.
[Maler]
--------------------------------------------------------------------------------
*/
#include "./path.h"
inherit SIM_ROOM;

create() {
    ::create();
    SetLocate("berat");
    SetIntShort("la planta baja de una casa");
    SetIntLong("Est�s en la planta baja de la casa, ciertamente est� algo desordenada,.\n "
    " La habitaci�n es amplia y bien iluminada, puedes ver una estanter�a "
    "llena de libros, una mesa de madera y un mont�n de cosas por el suelo. "
    "al fondo ves las escaleras que suben al segundo piso de la casa.\n");
    SetIntNoise("Lo �nico que escuchas es el distante rumor del mar.\n");
    SetIntSmell("Como cabe esperar, todo est� impregnado con un olor a mar.\n");
    SetIntBright(30);

    AddDetail(({"estanteria","estanter�a","libros"}),"Los libros que est�n en la estanter�a "
    "parecen viejos y gastados,ser� mejor no tocarlos por si alguno se deshace en tus manos.\n");

    AddDetail(({"mesa","mesa de madera"}),"La mesa de madera est� hecha de un solo tronco"
    " cortado longitudinalmente, parece robusta y est� limpia.\n");

    AddDetail(({"escaleras","escaleras de madera"}),"Las escaleras que suben "
    "al segundo piso son bastante inclinadas, podr�an ser peligrosas para alguien "
    "borracho.\n");

    AddExit("sur","./ctab2");
    AddExit("arriba","./hab3_2");
    AddDoor("sur", "la puerta de la calle");
}
