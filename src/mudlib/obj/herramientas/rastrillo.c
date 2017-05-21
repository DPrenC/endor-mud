/* Fichero: rastrillo.c 
Autor: Aul�
Fecha: 13/09/2014
Descripci�n: rastrillo para amontonar vegetaci�n, hierba, tierra...
*/
#include <properties.h>
#include <materials.h>
#include <combat.h>
inherit WEAPON;

create()
{
    ::create();
    SetStandard(WT_IMPROVISADA,1,P_SIZE_LARGE,M_HIERRO,GENERO_MASCULINO);
    SetShort("un rastrillo");
    SetLong(
    "Es una herramienta formada por un largo mango de madera que sustenta una tira de "
    "hierro perpendicular de la que surgen una hilera de dientes muy juntos y algo "
    "curvados hacia atr�s. Se usa para apartar la tierra, hojas o vegetaci�n rascando el "
    "terreno con los dientes o para formar montones.\n");
    AddId(({"rastrillo", "herramienta"}));
    SetNumberHands(2);
    SetWeight(1000);
    
}
