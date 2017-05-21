/***************************************************************************************
 ARCHIVO:	mithril1.c
 AUTOR:		Riberales
 FECHA:		13/10/05
 Descripción: Un trozo pequeño de mt.
 ***************************************************************************************/

#include "path.h"
#include <properties.h>


inherit THING;



public void create ()
{
  ::create();

  SetShort("un trozo pequeño de mithril");
  SetLong("Es un pedazo de mithril, sacado de las minas enanas "
            "de Kha-annu. Aunque es bastante pequeño, el mithril es el mineral"
            " más preciado y seguro que sacarás un buen pico de su venta.\n");
    SetIds(({"mithril","trozo de mithril","trozo pequeño de mithril","mineral"}));
    SetMaterial(M_MITHRIL);
    SetWeight(125+random(75));
    SetValue(QueryWeight()*250);
}
