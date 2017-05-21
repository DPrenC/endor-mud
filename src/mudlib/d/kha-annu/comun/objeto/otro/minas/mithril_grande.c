/***************************************************************************************
 ARCHIVO:	mithril12c
 AUTOR:		Riberales
 FECHA:		13/10/05
 Descripci�n: Un gran trozo de mithril.
 ***************************************************************************************/

#include "path.h"
#include <properties.h>


inherit THING;



public void create ()
{
  ::create();

  SetShort("un gran fragmento de mithril");
  SetLong("Es un fragmento de mithril, sacado de las minas enanas de "
            "Kha-annu. Ves su gran tama�o y no alcanzas a presumir cu�nto "
            "pueden darte por �l.\n");
    SetIds(({"mithril","trozo de mithril","trozo grande de mithril","mineral"}));
    SetMaterial(M_MITHRIL);
    SetWeight(350+random(200));
    SetValue(QueryWeight()*250);
}
