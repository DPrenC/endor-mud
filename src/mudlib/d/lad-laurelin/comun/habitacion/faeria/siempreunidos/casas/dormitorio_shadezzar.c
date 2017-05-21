/***
Fichero: dormitorio_shadezzar.c
Autor: kastwey@simauria
Descripci�n: el dormitorio de Shadezzar
Creaci�n: 07/12/2004
***/

#include "path.h"
#include <properties.h>

inherit STD_FAERIA("hab_siempreunidos");

create()
{
    ::create();
    SetIntShort("un dormitorio");
    SetIntLong(W("Te encuentras en el dormitorio de Shadezzar.\n"
    "Es un cuarto m�s bien peque�o y con una decoraci�n un tanto austera.\n"
    "Una silla, un armario, una mesilla y una cama completa el mobiliario de la habitaci�n.\n"
    "Al este puedes ver la sala principal de la casa.\n"));
    SetOficina(HAB_PUESTO("casas/casa_shadezzar"));
    SetIndoors(1);
    SetIntBright(25);
    AddDetail(({"cama", "camastro"}), "Es una cama r�stica pero funcional... Cuatro patas met�licas y una plancha encima, sirve de apoyo a un colch�n que parece de lana.\n");
    AddDetail("silla", "Es una silla que nada m�s de mirarla ya te sientes inc�modo. Parece estar llena de bustos por todos lados... Quiz�s aqu� castiga Shadezzar a los maleantes de la zona, sent�ndolos un ratito en la silla.\n");
    AddDetail(({"mesa", "mesita", "mesilla"}), "Es una peque�a mesita situada al lado de la cama.\n");
    AddItem("/obj/chest", REFRESH_HOME,
        ([
            P_SHORT:"un armario",
            P_LONG:"Es un armario donde supones que Shadezzar guardar� la ropa.\n",
            P_IDS:({"armario", "mueble"}),
            P_SIZE:P_SIZE_MEDIUM,
            P_MAX_WEIGHT:90000,
            P_NOGET:1,
            P_NOTAKE:1,
            "Key":"cerrado_de_por_vida"
        ]), 1);
    AddExit("este", HAB_PUESTO("casas/casa_shadezzar"));
}