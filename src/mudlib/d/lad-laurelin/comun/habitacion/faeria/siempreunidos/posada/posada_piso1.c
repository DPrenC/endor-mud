/***
Fichero: posada_piso1.c
Autor: kastwey@simauria
Descripci�n: Primer piso de la posada.
Creaci�n: 05/12/2004
***/

#include "path.h"
#include <moving.h>

inherit STD_FAERIA("posada_base_faeria");

int ir_hab1();

create()
{
    ::create();
    SetIntShort("el primer piso de la posada");
    SetIntLong(W("Te encuentras en el primer piso de la posada.\n"
    "Hacia el oeste se extiende un pasillo, y hacia el norte tienes la puerta de una de las habitaciones.\n"));
    SetOficina(HAB_PUESTO("posada/posada_escaleras"));
    SetIndoors(1);
    SetIntBright(25);
    AddDetail(({"norte", "puerta"}), W("Es una puerta que conduce a una de las habitaciones de la posada.\n"
    "Te acercas, y en ella puedes ver un cartel en el que se lee: Habitaci�n 1.\n"));
    AddExit("oeste", HAB_PUESTO("posada/posada_pasillo1"));
    AddExit("abajo", HAB_PUESTO("posada/posada_escaleras"));
    AddExit("norte", SF(ir_hab1));
}

int ir_hab1()
{
    if (!present("llave_posada_faeria_1", TP)) return notify_fail(W("Intentas abrir la puerta, pero est� cerrada con llave.\n"
    "Si lo que quieres es alquilar una habitaci�n, quiz�s deber�as dec�rselo antes al posadero.\n"));
    if (TP->move(HAB_PUESTO("posada/posada_hab1"), M_SPECIAL, ({"abre la puerta con ayuda de su llave y entra en la habitaci�n cerrando tras de s�", "Entra en la habitaci�n y vuelve a cerrar", "Con ayuda de la llave, consigues abrir la puerta y entras en la habitaci�n cerrando tras de ti"})) != ME_OK)
	{
	    if (TP->Fighting()) return notify_fail("No puedes dejar este lugar.\n");
	else
	    return notify_fail("Por alguna raz�n no puedes entrar en la habitaci�n. Consulta con un wizard.\n");
    }
    return 1;
}