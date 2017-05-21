/****************************************************************************
Fichero: /d/simauria/comun/habitacion/sherek/aldea/casas/bodega05.c
Autor: Lug y Yalin
Fecha: 22/08/2006
Descripci�n: Despacho de la bodega.
****************************************************************************/

#include "path.h"
inherit SHERALD("ceroom");

create()
{
    ::create();
    SetIntShort("el despacho de la bodega");
    SetIntLong("Aqu� es donde se realizan las transacciones, se cargan los "
        "carros, o las carretillas, para llevar el vino a la abad�a, a la "
        "taberna o a vender en otros pueblos.\nUna rampa baja a los "
        "almacenes, permitiendo sacar los barriles, bien en carretilla o "
        "haci�ndolos rodar.\nAl fondo hay algunos carritos de mano, y sobre "
        "una repisa en la pared, a modo de mesa, puedes ver un libro de "
        "cuentas, con una pluma y el tintero.\n");
    SetIntSmell("Predomina el olor a vino y madera, aunque con sutiles "
        "toques de metal y papel.\n");
    SetIntNoise("Oyes el rumor de la vecina calle.\n");
    AddDetail(({"libro","pergamino","pergaminos"}), "No es m�s que un fajo de "
        "pergaminos toscamente cosidos.\n");
    AddDetail(("pluma"), "Es una pluma de ganso afilada en el extremo, que "
        "se usa para escribir.\n");
    AddDetail(("tintero"), "Es un peque�o vaso lleno de tinta, donde se moja "
        "la pluma para escribir.\n");
    AddDetail(("tinta"), "Es un l�quido negro, muy negro.\n");
    AddDetail(({"carrito","carrito de mano","carritos","carritos de mano"}),
        "Los carritos son planchas de madera, con una rueda en cada v�rtice, "
        "y con dos varas sobresaliendo de uno de sus lados cortos, lo que "
        "permite inclinarlos hacia adelante o hacia atr�s, seg�n si van a "
        "subir o bajar cargados.\n");
    AddExit("este", SHERALD("calles/callejuela01"));
    AddExit("abajo", SHERALD("casas/bodega04"));
}
