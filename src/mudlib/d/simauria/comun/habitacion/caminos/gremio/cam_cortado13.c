/****************************************************************************
Fichero: cam_cortado13.c
Autor: Ratwor
Fecha: 19/08/2007
Descripci�n: El camino entre monta�as que se dirije a la cueva de los trolls.
****************************************************************************/


#include "./path.h"
#include <properties.h>
inherit CAMINOS "/gremio/cam_cortado_base";
create(){
    ::create();
    SetLocate("desfiladero de Marhalt");
    SetIntShort("un lugar lleno de rocas");
    SetIntLong("  En este sitio, los flancos de la monta�a parecen haberse derrumbado "
    "por alg�n temblor, y el recodo del desfiladero est� lleno de grandes pe�as "
    "amontonadas sin orden ni concierto unas sobre otras.\n Al mirar hacia arriba se "
    "puede ver, que ni a�n contando con herramientas de escalada, se podr�a llegar "
    "al borde superior del ca��n. Pues aqu� las paredes, aunque mas bajas que en el "
    "resto del desfiladero, siguen siendo muy altas y escarpadas.\n");
    AddDetail(({"roca", "rocas", "piedra", "piedras", "pe�a", "pe�as"}),
    " Grandes bloques irregulares de piedra gris y peque�os cantos rodados que se "
    "amontonan unos sobre otros en precario equilibrio.\n");
    AddExit("noroeste", "./cam_cortado12");

}
