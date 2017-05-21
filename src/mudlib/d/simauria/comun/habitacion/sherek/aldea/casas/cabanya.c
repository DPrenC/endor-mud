/****************************************************************************
Fichero: /d/simauria/comun/habitacion/sherek/aldea/casas/cabaña.c
Autor: Lug y Yalin
Fecha: 13/01/2007
Descripción: Base para las cabañas de la aldea.
****************************************************************************/

#include "path.h"
inherit SHERALD("ceroom");

create ()
{
    ::create();
    SetIntShort("una pobre cabaña aldeana");
    SetIntLong("Estás dentro de una de las cabañas de la aldea de Sloch. Es "
        "un habitáculo nminimalista ya que las gentes que aquí viven casi no "
        "deben tener recurso alguno. Los muebles se limitan a un jergón y un "
        "par de sillas.\n");
    SetIntNoise("Escuchas, apagados, los sonidos de la calle.\n");
    SetIntSmell("Huele a humo, la chimenea no debe tirar bien.\n");
    SetIntBright(20);
    AddDetail(({"mueble","muebles","sillas"}), "Solamente ves un par de "
        "sillas desvencijadas y un jergón.\n");
    AddDetail(({"cama", "jergón"}), "Es un colchón de paja.\n");
    AddDetail(({"techo"}), "Está construido  de cañas entretejidas con un "
        "agujero en el centro para que salgan los humos.\n");
    AddDetail(({"paredes", "pared"}), "Son de troncos sin desbastar y mal "
        "encajados entre sí.\n");
    AddDetail(({"suelo"}), "El suelo es de tierra.\n");
    AddDetail(({"chimenea", "hogar"}), "Es, simplemente, un lugar en el "
        "suelo en el centro de la estancia.\n");
}
