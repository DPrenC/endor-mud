/* Fichero: pico_minero.c 
Autor: Aulë
Fecha: 13/09/2014
Descripción: pico genérico para mineros tamaño humano*/


#include <combat.h>
#include <properties.h>

inherit WEAPON;

create()
{
 ::create();
 SetStandard(WT_PICO,3,P_SIZE_LARGE,M_HIERRO);
 SetShort("un pico de minero");
 AddId(({"pico", "pico_minero", "herramienta"}));
 SetNumberHands(2);
 SetLong(
 "El pico es una herramienta pesada que requiere gran esfuerzo. Consta de un grueso "
 "mango de recia madera con una cabeza de hierro con forma de arco. A partir del mango, "
 "ambos extremos de la cabeza se van estrechando y curvando hacia atrás hasta terminar en "
 "una punta cónica. Esta herramienta suele utilizarse para trabajar la roca o arrancar "
 "minerales de todo tipo.\n");
}