/* Fichero: azada.c 
Autor: Aulë
Fecha: 13/09/2014
Descripción: azada genérica*/
#include <combat.h>
#include <properties.h>

inherit WEAPON;

create()
{
 ::create();
 SetStandard(WT_AZADON,3,P_SIZE_LARGE,M_HIERRO);
 SetShort("una azada");
AddAdjective(({"de", "hierro"}));
 AddId(({"azadon","azadón", "azada", "herramienta"}));
    SetLong("Es una hoja triangular de hierro, unida por la parte más estrecha a un recio mango de "
    "madera alisada.\n"
    "Se usa para cavar de forma superficial, "
        "y especialmente para airear las raíces de las plantas removiendo o ahuecando la tierra.\n");
        SetWeight(1900);
        
}