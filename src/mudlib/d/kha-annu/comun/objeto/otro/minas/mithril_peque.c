/***************************************************************************************
 ARCHIVO:	mithril1.c
 AUTOR:		Riberales
 FECHA:		13/10/05
 Descripci�n: Un trozo peque�o de mt.
 ***************************************************************************************/

#include "path.h"
#include <properties.h>


inherit THING;



public void create ()
{
  ::create();

  SetShort("un trozo peque�o de mithril");
  SetLong("Es un pedazo de mithril, sacado de las minas enanas "
            "de Kha-annu. Aunque es bastante peque�o, el mithril es el mineral"
            " m�s preciado y seguro que sacar�s un buen pico de su venta.\n");
    SetIds(({"mithril","trozo de mithril","trozo peque�o de mithril","mineral"}));
    SetMaterial(M_MITHRIL);
    SetWeight(125+random(75));
    SetValue(QueryWeight()*250);
}
