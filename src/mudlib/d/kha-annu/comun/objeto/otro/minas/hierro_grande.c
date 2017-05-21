/***************************************************************************************
 ARCHIVO:	hierro2.c
 AUTOR:		Riberales
 FECHA:		13/10/05
 Descripción: Un gran trozo de hierro.
 ***************************************************************************************/

#include "path.h"
#include <properties.h>


inherit THING;



public void create ()
{
  ::create();

    SetShort("un gran trozo de mena de hierro");
    SetLong("Es un gran trozo de mena de hierro, de donde luego se saca el "
            "hierro propiamente dicho. Está sacado de las minas de Kha-annu. "
            "Tiene un tamaño bastante grande, lo que te hace pensar que si lo "
            "empeñas puedes sacar un generoso puñado de monedas.\n");
    SetIds(({"hierro","gran pedazo de hierro","mineral","magnetita","mena",
             "mena grande","mena ferrica","mena férrica"}));

    SetMaterial(M_HIERRO);
    SetWeight(400+random(250));
    SetValue(QueryWeight()*2);

}
