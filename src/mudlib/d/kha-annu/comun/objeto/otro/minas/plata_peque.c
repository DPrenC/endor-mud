/***************************************************************************************
 ARCHIVO:	plata1.c
 AUTOR:		Riberales
 FECHA:		13/10/05
 Descripción: Un trozo pequeño de plata.
 ***************************************************************************************/

#include "path.h"
#include <properties.h>


inherit THING;



public void create ()
{
  ::create();

  SetShort("un pequeño trozo de plata");
  SetLong("Es un pequeño fragmento de plata, extraido de las minas enanas "
            "de Kha-annu. No es que sea una gran pieza, pero un buen valor "
            "tendrá.\n");
    SetIds(({"plata","trozo de plata","trozo pequeño de plata","mineral"}));
    SetMaterial(M_PLATA);
    SetWeight(125+random(75));
    SetValue(QueryWeight()*6);
}
