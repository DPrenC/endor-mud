/********************
Archivo: pala.c
Autor: Lug y Yalin
Fecha: 15/08/2007
Descripci�n: cintur�n para negociar el pergamino con Gaena
********************/
#include "path.h"
#include <properties.h>
#include <combat.h>
#include <materials.h>
inherit ARMOUR;

create()
{
    ::create();
    SetStandard(AT_CINTURON,0,P_SIZE_GENERIC,M_CUERO);
    SetShort("un cintur�n de piel");
    AddId(({"cintur�n","cinturon","cintur�n de piel","cinturon de piel","cinturon_gaena"}));
    SetLong("Es un precioso cintur�n de cuero, hecho con la piel de una serpiente pit�n real. "
        "Presenta unos bonitos contrastes de color, en una gama de negros, crema, amarillos y "
        "blancos.\nAdmiras su hechura y acabado, y empiezas a entender la fama del artesano "
        "que lo hizo.\n");
    SetWeight(250);
    SetValue(500);
    Set(P_NOSELL,1);
}
    