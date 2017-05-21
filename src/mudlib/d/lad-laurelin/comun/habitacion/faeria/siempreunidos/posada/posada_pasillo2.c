/***
Fichero: posada_pasillo2.c
Autor: kastwey@simauria
Descripción: Pasillo de la posada de Siempreunidos.
***/

#include "path.h"
#include <moving.h>

inherit STD_FAERIA("posada_base_faeria");

int ir_hab3();

create()
{
    ::create();
    SetIntShort("el pasillo de la posada");
    SetIntLong(W("Te encuentras al final de un pasillo en la primera planta de la posada de Siempreunidos.\n"
    "Al este se extiende el pasillo, y al norte puedes ver la puerta de la habitación 3.\n"));
    SetOficina(HAB_PUESTO("posada/posada_pasillo1"));
    SetIndoors(1);
    SetIntBright(25);
    AddDetail(({"norte", "puerta"}), W("Es una puerta que conduce a una de las habitaciones de la posada.\n"
    "Te acercas, y en ella puedes ver un cartel en el que se lee: Habitación 3.\n"));
    AddExit("este", HAB_PUESTO("posada/posada_pasillo1"));
    AddExit("norte", SF(ir_hab3));
}

int ir_hab3()
{
    if (!present("llave_posada_faeria_3", TP)) return notify_fail(W("Intentas abrir la puerta, pero está cerrada con llave.\n"
    "Si lo que quieres es alquilar una habitación, quizás deberías decírselo antes al posadero.\n"));
    if (TP->move(HAB_PUESTO("posada/posada_hab3"), M_SPECIAL, ({"abre la puerta con ayuda de su llave y entra en la habitación cerrando tras de sí", "Entra en la habitación y vuelve a cerrar", "Con ayuda de la llave, consigues abrir la puerta y entras en la habitación cerrando tras de ti"})) != ME_OK)
	{
	    if (TP->Fighting()) return notify_fail("No puedes dejar este lugar.\n");
	else
	    return notify_fail("Por alguna razón no puedes entrar en la habitación. Consulta con un wizard.\n");
    }
    return 1;
}