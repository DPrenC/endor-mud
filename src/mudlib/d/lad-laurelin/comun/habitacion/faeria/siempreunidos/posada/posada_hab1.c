/***
Fichero: posada_hab1.c
Autor: kastwey
Descripción: Dormitorio 1 de la posada.
Creación: 05/12/2004
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
    SetIntLong(W("Te encuentras en la habitación 1 de la posada de Siempreunidos.\n"
    "La habitación no es muy grande, aunque resulta confortable.\n"
    "Al fondo puedes ver una cama, una pequeña mesita, y pegado a una de las paredes un gran armario.\n"));
    SetOficina(HAB_PUESTO("posada/posada_piso1"));
    SetIndoors(1);
    SetIntBright(25);
    AddDetail(({"cama", "clecho"}), "Es una cama bastante grande, en la que sin duda podrían dormir más de una persona. Por lo mullido de el colchón, tiene pinta de ser muy cómoda para dormir.\n");
    AddDetail(({"mesa", "mesilla", "mesita"}), "Es una pequeña mesita, ideal para dejar junto a la cama las cosas que queramos tener a mano cuando despertemos.\n");
    AddItem("/obj/chest", REFRESH_HOME, ([
    P_SHORT:"un armario",
    P_LONG:"Es un armario enorme, que casi llega hasta el techo de la habitación. Está hecho de algún tipo de metal que eres incapaz de identificar. Seguro que ahi dentro te cabe más ropa de la que jamás podrías necesitar.\n",
    P_MAX_WEIGHT:10000,
    P_IDS:({"armario", "mueble"}),
    "NoTake":1,
    P_SIZE:P_SIZE_LARGE,
    "Key":0]), 1);
    AddExit("sur", SF(ir_pasillo));
}

int ir_pasillo()
{
    if (TP->move(HAB_PUESTO("posada/posada_piso1"), M_SPECIAL, ({"abre la puerta, sale de la habitación y cierra tras de sí", "sale de la habitación cerrando a su espalda", "Abres la puerta, sales de la habitación y vuelves a cerrar.\n", "cadena4", "cadena5", "cadena6"})) != ME_OK)
	{
	    if (TP->Fighting()) return notify_fail("No puedes dejar este lugar.\n");
	else
	    return notify_fail("Por alguna razón no puedes salir de la habitación. Consulta con un wizard.\n");
    }
    return 1;
}
int allow_enter(int method, mixed extra)
// aquí controlo si alguien puede entrar a la room
// si no es un wiz y no es el propietario... como que no
{
    if (!query_wiz_level(PO) && method == M_TELEPORT || (method == M_SILENT && extra = 0) && !present("llave_posada_faeria_1", PO))
    // lo ziento.. no erez digno de entrar aqui...
    {
        return write ("No te está permitido ir a este lugar.\nEsta es una habitación privada.\n"), ME_NO_ENTER;
    }
    else
    {
        return ::allow_enter(method, extra);
    }
}