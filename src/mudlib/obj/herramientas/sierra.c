/* Fichero: sierra.c 
Autor: Aul�
Fecha: 13/09/2014
Descripci�n: una sierra para partir �rboles, serrar tablas, vigas, etc.
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
    "Es una sierra grande para tronzar troncos o cortar con gran precisi�n tablas y otros "
    "productos derivados de la madera. Consta de un mango de madera arqueado hacia abajo, "
    " con espacio suficiente para ambas manos, y una larga hoja rematada por una doble "
    "hilera de afilados dientes.\n");
        SetWeight(1000);
        

SetNumberHands(2);
}