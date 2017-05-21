/***
Fichero: posada_pasillo1.c
Autor: kastwey@simauria
Descripci�n: Pasillo de la posada de Siempreunidos.
***/

#include "path.h"
#include <moving.h>

inherit STD_FAERIA("posada_base_faeria");

int ir_hab2();

create()
{
    ::create();
    SetIntShort("el pasillo de la posada");
    SetIntLong(W("Te encuentras en un pasillo, en la primera planta de la posada de Siempreunidos.\n"
    "Al este puedes ver la escalera que te permite bajar hasta el primer piso, y al norte la habitaci�n 2.\n"
    "Al oeste contin�a el pasillo.\n"));
    SetOficina(HAB_PUESTO("posada/posada_piso1"));
    SetIndoors(1);
    SetIntBright(25);
    AddDetail(({"norte", "puerta"}), W("Es una puerta que conduce a una de las habitaciones de la posada.\n"
    "Te acercas, y en ella puedes ver un cartel en el que se lee: Habitaci�n 2.\n"));
    AddExit("este", HAB_PUESTO("posada/posada_piso1"));
    AddExit("oeste", HAB_PUESTO("posada/posada_pasillo2"));
    AddExit("norte", SF(ir_hab2));
}

int ir_hab2()
{
    if (!present("llave_posada_faeria_2", TP)) return notify_fail(W("Intentas abrir la puerta, pero est� cerrada con llave.\n"
    "Si lo que quieres es alquilar una habitaci�n, quiz�s deber�as dec�rselo antes al posadero.\n"));
    if (TP->move(HAB_PUESTO("posada/posada_hab2"), M_SPECIAL, ({"abre la puerta con ayuda de su llave y entra en la habitaci�n cerrando tras de s�", "Entra en la habitaci�n y vuelve a cerrar", "Con ayuda de la llave, consigues abrir la puerta y entras en la habitaci�n cerrando tras de ti"})) != ME_OK)
	{
	    if (TP->Fighting()) return notify_fail("No puedes dejar este lugar.\n");
	else
	    return notify_fail("Por alguna raz�n no puedes entrar en la habitaci�n. Consulta con un wizard.\n");
    }
    return 1;
}