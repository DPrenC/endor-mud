/* Fichero: horca.c 
Autor: Aul�
Fecha: 13/09/2014
Descripci�n: horca gen�rica para voltear el trigo, recoger paladas de hierba, etc.*/
#include <combat.h>
#include <properties.h>

inherit WEAPON;

create()
{
 ::create();
 SetStandard(WT_IMPROVISADA, 3,P_SIZE_LARGE,M_HIERRO);
 SetDamType(DT_PIERCE);
  SetShort("una horca");
AddAdjective(({"de", "hierro"}));
 AddId(({"horca","tridente",  "herramienta"}));
    SetLong(
    "La horca es una herramienta para recoger el heno, la hierba o vegetaci�n de otro "
    "tipo. Consta de un largo mango de madera con una cabeza dotada de  tres p�as "
    "alineadas y curvadas ligeramente hacia arriba.\n");
        SetWeight(2100);
        SetNumberHands(2);
        
        
}