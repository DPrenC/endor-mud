/****************************************************************************
Fichero: /d/simauria/comun/habitacion/sherek/aldea/casas/caba�a.c
Autor: Lug y Yalin
Fecha: 13/01/2007
Descripci�n: Base para las caba�as de la aldea.
****************************************************************************/

#include "path.h"
inherit SHERALD("ceroom");

create ()
{
    ::create();
    SetIntShort("una pobre caba�a aldeana");
    SetIntLong("Est�s dentro de una de las caba�as de la aldea de Sloch. Es "
        "un habit�culo nminimalista ya que las gentes que aqu� viven casi no "
        "deben tener recurso alguno. Los muebles se limitan a un jerg�n y un "
        "par de sillas.\n");
    SetIntNoise("Escuchas, apagados, los sonidos de la calle.\n");
    SetIntSmell("Huele a humo, la chimenea no debe tirar bien.\n");
    SetIntBright(20);
    AddDetail(({"mueble","muebles","sillas"}), "Solamente ves un par de "
        "sillas desvencijadas y un jerg�n.\n");
    AddDetail(({"cama", "jerg�n"}), "Es un colch�n de paja.\n");
    AddDetail(({"techo"}), "Est� construido  de ca�as entretejidas con un "
        "agujero en el centro para que salgan los humos.\n");
    AddDetail(({"paredes", "pared"}), "Son de troncos sin desbastar y mal "
        "encajados entre s�.\n");
    AddDetail(({"suelo"}), "El suelo es de tierra.\n");
    AddDetail(({"chimenea", "hogar"}), "Es, simplemente, un lugar en el "
        "suelo en el centro de la estancia.\n");
}
