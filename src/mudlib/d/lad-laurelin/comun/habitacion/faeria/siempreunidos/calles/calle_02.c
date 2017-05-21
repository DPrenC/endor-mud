/***
Fichero: calle_02.c
Autor: kastwey@simauria
Descripci�n: Calle principal de Siempreunidos. Hab 2.
Creaci�n: 03/12/2004
***/

#include "path.h"

inherit STD_FAERIA("hab_siempreunidos");


create()
{
    ::create();
    SetIntShort("la calle principal del pueblo de Siempreunidos");
    SetIntLong(W("Te encuentras en mitad de la calle que cruza Siempreunidos de sur a norte.\n"
    "Hacia el oeste puedes ver lo que parece la oficina del guardia del pueblo, y hacia el norte y el sur contin�a la calle.\n"));
    SetOficina(HAB_PUESTO("puesto_guardias/puesto_guardias"));
    AddExit("oeste", HAB_PUESTO("puesto_guardias/puesto_guardias"));
    AddExit("sur", HAB_PUESTO("calles/calle_01"));
    AddExit("norte", HAB_PUESTO("calles/calle_03"));
    AddDetail(({"oficina", "oeste"}), W("Se trata de una construcci�n de madera tosca, como todas las que has podido ver en este pueblo.\n"
    "Este edificio parece el m�s alto del lugar, y en su fachada ondea la bandera �lfica.\n"));
    SetOutdoors(1);
}