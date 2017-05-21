/****************************************************************************
Fichero: anillo_noble.c
Autor: Ratwor
Fecha: 27/07/2008
Descripci�n: un anillo familiar para el noble de Nandor.
****************************************************************************/


#include <properties.h>
#include <combat.h>
#include <materials.h>
inherit ARMOUR;
create() {
    ::create();
    SetStandard(AT_ANILLO, 0, P_SIZE_LARGE, M_HIERRO);
    AddAdjective(({"de hierro", "tosco", "feo", "viejo"}));
    AddId(({"anillo", "sello", "anillo_noble"}));
    SetShort("un tosco anillo");
    SetLong("Es un tosco anillo de hierro oxidado. Su forma cuadrada apenas supera "
    "la media pulgada, tiene distintas muescas en los bordes y un extra�o dibujo "
    "grabado bastante deteriorado por el paso de los a�os.\n");
    SetResetQuality(95);
    SetWeight(50);
    AddSubDetail("muescas", "Son distintas muescas que tiene repartidas por los cuatro "
    "lados del anillo. No parecen ser producidas por el uso ni el paso del tiempo "
    "sino que forman parte de la pieza.\n");
    AddSubDetail(({"extra�o dibujo", "dibujo", "dibujo grabado"}), "Est� muy desgastado "
    "y no se puede apreciar muy bien de qu� se trata, es posible que en su tiempo "
    "fuese una figura humana.\n");
}
