/* Fichero: tenazas.c 
Autor: Aulë
Fecha: 13/09/2014
Descripción: tenazas de fragua genéricas para manejar metales candentes y lingotes de 
mineral recién fundidos.*/
#include <combat.h>
#include <properties.h>

inherit WEAPON;

create()
{
 ::create();
 SetStandard(WT_IMPROVISADA,1,P_SIZE_GENERIC,M_HIERRO, GENERO_FEMENINO);
 SetShort("unas tenazas de forja");
AddAdjective(({"de", "hierro"}));
 AddId(({"tenazas_fragua","tenazas", "tenaza", "herramienta"}));
    SetLong(
    "Estas grandes y pesadas tenazas están formadas por dos piezas de hierro unidas por "
    "un grueso tornillo sobre el que ambas giran. La parte anterior de cada pieza es una "
    "larga barra metálica que oficia de mango mientras que la parte inferior tiene forma "
    "de gancho ancho y plano. Sirviéndose de estas tenazas pueden manejarse lingotes o "
    "piezas de metal al rojo sin peligro de sufrir quemaduras.\n");
        SetWeight(1900);
        Set(P_NUMBER, NUMERO_PLURAL);
        
}