/* Fichero: hoz_mano.c 
Autor: Aul�
Fecha: 13/09/2014
Descripci�n: hoz de mano gen�rica para cortar el trigo u otras plantas productivas de poca altura.*/
#include <combat.h>
#include <properties.h>

inherit WEAPON;

create()
{
 ::create();
 SetStandard(WT_IMPROVISADA,2,P_SIZE_LARGE,M_HIERRO);
 SetDamType(DT_SLASH);
 SetShort("una hoz de mano");
AddAdjective(({"de", "hierro"}));
 AddId(({"hoz", "hoz de mano", "herramienta"}));
    SetLong(
    "La hoz de mano es una larga hoja curva que casi forma las tres cuartas partes de un "
    "c�rculo con el filo en la parte interior. Esta hoja va encajada en un corto mango "
    "de madera. Habitualmente es usada para segar el trigo.\n");
        SetWeight(1100);
        
}