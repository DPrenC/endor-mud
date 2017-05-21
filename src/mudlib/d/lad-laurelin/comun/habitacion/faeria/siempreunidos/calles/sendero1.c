/***
Fichero: sendero1.c
Autor: kastwey@simauria
Descripción: Sendero para entrar al pueblo de Siempreunidos.
Creación: 17/12/2004
***/

#include "path.h"

inherit STD_FAERIA("hab_siempreunidos");

create()
{
    ::create();
    SetIntShort("un sendero en el bosque");
    SetIntLong(W("Te encuentras en un estrecho sendero en mitad del bosque de Atbalnin.\n"
    "Hacia el norte, el sendero se ensancha, mientras que al sur se hace totalmente invisible confundiéndose con el bosque.\n"));
    SetIntSmell("Huele a naturaleza.\n");
    SetIntNoise("Escuchas el sonido de la naturaleza.\n");
    SetOutdoors(1);
    AddExit("sur","/d/lad-laurelin/comun/habitacion/atbalnin/bosque/bosque24");
    AddExit("norte",HAB_PUESTO("calles/sendero2"));
}
  