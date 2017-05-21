/* Fichero: sierra.c 
Autor: Aulë
Fecha: 13/09/2014
Descripción: una sierra para partir árboles, serrar tablas, vigas, etc.
.*/
#include <combat.h>
#include <properties.h>

inherit WEAPON;

create()
{
 ::create();
 SetStandard(WT_IMPROVISADA,3,P_SIZE_LARGE,M_ACERO);
 SetDamType(DT_SLASH);
 SetShort("una sierra");
AddAdjective(({"de", "ACERO"}));
 AddId(({"sierra", "herramienta"}));
    SetLong(
    "Es una sierra grande para tronzar troncos o cortar con gran precisión tablas y otros "
    "productos derivados de la madera. Consta de un mango de madera arqueado hacia abajo, "
    " con espacio suficiente para ambas manos, y una larga hoja rematada por una doble "
    "hilera de afilados dientes.\n");
        SetWeight(1000);
        

SetNumberHands(2);
}