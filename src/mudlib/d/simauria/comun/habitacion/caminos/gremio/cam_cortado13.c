/****************************************************************************
Fichero: cam_cortado13.c
Autor: Ratwor
Fecha: 19/08/2007
Descripción: El camino entre montañas que se dirije a la cueva de los trolls.
****************************************************************************/


#include "./path.h"
#include <properties.h>
inherit CAMINOS "/gremio/cam_cortado_base";
create(){
    ::create();
    SetLocate("desfiladero de Marhalt");
    SetIntShort("un lugar lleno de rocas");
    SetIntLong("  En este sitio, los flancos de la montaña parecen haberse derrumbado "
    "por algún temblor, y el recodo del desfiladero está lleno de grandes peñas "
    "amontonadas sin orden ni concierto unas sobre otras.\n Al mirar hacia arriba se "
    "puede ver, que ni aún contando con herramientas de escalada, se podría llegar "
    "al borde superior del cañón. Pues aquí las paredes, aunque mas bajas que en el "
    "resto del desfiladero, siguen siendo muy altas y escarpadas.\n");
    AddDetail(({"roca", "rocas", "piedra", "piedras", "peña", "peñas"}),
    " Grandes bloques irregulares de piedra gris y pequeños cantos rodados que se "
    "amontonan unos sobre otros en precario equilibrio.\n");
    AddExit("noroeste", "./cam_cortado12");

}
