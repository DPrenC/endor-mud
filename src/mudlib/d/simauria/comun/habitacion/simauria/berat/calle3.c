/*
DESCRIPCION  : calle
FICHERO      : /d/simauria/comun/habitacion/simauria/berat/calle3.c
MODIFICACION : 28-10-99 [icaro@simauria]creacion
                        [Nem] Revisado y corregido
--------------------------------------------------------------------------------
*/
#include "./path.h"
inherit SIM_ROOM;

create() {
    ::create();
    SetLocate("Berat");
    SetIntShort("una callejuela");
    SetIntLong("Estás en una callejuela que une la calle principal, "
    "al oeste, con la calle Koldar al este. Es una calle estrecha y "
    "sombría pero no parece peligrosa. Al sur esta la entrada trasera "
    "del templo de Berat.\n");
    SetIndoors(0);
    SetIntNoise("Escuchas el murmullo de un riachuelo.\n");
    AddDetail(({"rio", "río", "riachuelo"}),"Es uno de los riachuelos que forman el "
    "delta en el que se encuentra Berat. La calle coincide con el recodo "
    "del riachuelo.\n");
    AddExit("este","./ckol4");
    AddExit("sur","./ermita");
    AddExit("oeste","./cprin6");
    AddDoor("sur", "la puerta trasera del templo ",
    "Es una simple puerta para entrar al templo.\n",
    ({"puerta", "puerta del templo", "puerta trasera", "puerta del sur",
    "puerta trasera del templo"}));
}
