/* Fichero: azada.c 
Autor: Aul�
Fecha: 13/09/2014
Descripci�n: azada gen�rica*/
#include <combat.h>
#include <properties.h>

inherit WEAPON;

create()
{
 ::create();
 SetStandard(WT_AZADON,3,P_SIZE_LARGE,M_HIERRO);
 SetShort("una azada");
AddAdjective(({"de", "hierro"}));
 AddId(({"azadon","azad�n", "azada", "herramienta"}));
    SetLong("Es una hoja triangular de hierro, unida por la parte m�s estrecha a un recio mango de "
    "madera alisada.\n"
    "Se usa para cavar de forma superficial, "
        "y especialmente para airear las ra�ces de las plantas removiendo o ahuecando la tierra.\n");
        SetWeight(1900);
        
}