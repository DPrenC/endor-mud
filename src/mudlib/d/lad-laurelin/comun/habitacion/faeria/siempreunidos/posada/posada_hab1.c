/***
Fichero: posada_hab1.c
Autor: kastwey
Descripci�n: Dormitorio 1 de la posada.
Creaci�n: 05/12/2004
***/

#include "path.h"
#include <properties.h>
#include <moving.h>

inherit STD_FAERIA("posada_base_faeria");

int ir_pasillo();

create()
{
    ::create();
    SetIntShort("un dormitorio de la posada");
    SetIntLong(W("Te encuentras en la habitaci�n 1 de la posada de Siempreunidos.\n"
    "La habitaci�n no es muy grande, aunque resulta confortable.\n"
    "Al fondo puedes ver una cama, una peque�a mesita, y pegado a una de las paredes un gran armario.\n"));
    SetOficina(HAB_PUESTO("posada/posada_piso1"));
    SetIndoors(1);
    SetIntBright(25);
    AddDetail(({"cama", "clecho"}), "Es una cama bastante grande, en la que sin duda podr�an dormir m�s de una persona. Por lo mullido de el colch�n, tiene pinta de ser muy c�moda para dormir.\n");
    AddDetail(({"mesa", "mesilla", "mesita"}), "Es una peque�a mesita, ideal para dejar junto a la cama las cosas que queramos tener a mano cuando despertemos.\n");
    AddItem("/obj/chest", REFRESH_HOME, ([
    P_SHORT:"un armario",
    P_LONG:"Es un armario enorme, que casi llega hasta el techo de la habitaci�n. Est� hecho de alg�n tipo de metal que eres incapaz de identificar. Seguro que ahi dentro te cabe m�s ropa de la que jam�s podr�as necesitar.\n",
    P_MAX_WEIGHT:10000,
    P_IDS:({"armario", "mueble"}),
    "NoTake":1,
    P_SIZE:P_SIZE_LARGE,
    "Key":0]), 1);
    AddExit("sur", SF(ir_pasillo));
}

int ir_pasillo()
{
    if (TP->move(HAB_PUESTO("posada/posada_piso1"), M_SPECIAL, ({"abre la puerta, sale de la habitaci�n y cierra tras de s�", "sale de la habitaci�n cerrando a su espalda", "Abres la puerta, sales de la habitaci�n y vuelves a cerrar.\n", "cadena4", "cadena5", "cadena6"})) != ME_OK)
	{
	    if (TP->Fighting()) return notify_fail("No puedes dejar este lugar.\n");
	else
	    return notify_fail("Por alguna raz�n no puedes salir de la habitaci�n. Consulta con un wizard.\n");
    }
    return 1;
}
int allow_enter(int method, mixed extra)
// aqu� controlo si alguien puede entrar a la room
// si no es un wiz y no es el propietario... como que no
{
    if (!query_wiz_level(PO) && method == M_TELEPORT || (method == M_SILENT && extra = 0) && !present("llave_posada_faeria_1", PO))
    // lo ziento.. no erez digno de entrar aqui...
    {
        return write ("No te est� permitido ir a este lugar.\nEsta es una habitaci�n privada.\n"), ME_NO_ENTER;
    }
    else
    {
        return ::allow_enter(method, extra);
    }
}