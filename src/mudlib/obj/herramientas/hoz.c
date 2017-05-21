/* Fichero: hoz.c 
Autor: Aulë
Fecha: 13/09/2014
Descripción: hoz genérica para desbrozar matorrales, despejar caminos. .*/
#include <combat.h>
#include <properties.h>

inherit WEAPON;

create()
{
 ::create();
 SetStandard(WT_IMPROVISADA,3,P_SIZE_LARGE,M_HIERRO);
 SetDamType(DT_SLASH);
 SetShort("una hoz");
AddAdjective(({"de", "hierro"}));
 AddId(({"hoz", "herramienta"}));
    SetLong(
    "Ésta herramienta suele utilizarse para desbrozar matorrales o podar setos. Está "
    "formada por un mango de madera aplanado y una hoja cuya último tercio se curva "
    "hacia dentro. El filo se localiza en la parte cóncava de la hoja mientras que en la "
    "parte no cortante hay un pequeño gancho que se curva hacia adelante para atrapar o "
    "apartar la maleza y las cañas permitiendo un uso de la hoz más cómodo.\n");
        SetWeight(1800);
        

SetNumberHands(2);
}