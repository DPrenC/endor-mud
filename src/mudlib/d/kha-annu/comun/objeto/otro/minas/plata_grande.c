/***************************************************************************************
 ARCHIVO:	plata2.c
 AUTOR:		Riberales
 FECHA:		13/10/05
 Descripci�n: Un trozo grande de plata.
 ***************************************************************************************/

#include "path.h"
#include <properties.h>


inherit THING;



public void create ()
{
  ::create();

  SetShort("un gran trozo de plata");
  SetLong("Es un pedazo de plata, extraido de las minas enanas "
            "de Kha-annu. Tiene un buen tama�o, con lo que su valor ser� "
            "considerable.\n");
    SetIds(({"plata","trozo de plata","trozo grande de plata","mineral"}));

    SetWeight(400+random(150));
    SetMaterial(M_PLATA);
    SetValue(QueryWeight()*6);
}
