/***************************************************************************************
 ARCHIVO:	plata1.c
 AUTOR:		Riberales
 FECHA:		13/10/05
 Descripci�n: Un trozo peque�o de plata.
 ***************************************************************************************/

#include "path.h"
#include <properties.h>


inherit THING;



public void create ()
{
  ::create();

  SetShort("un peque�o trozo de plata");
  SetLong("Es un peque�o fragmento de plata, extraido de las minas enanas "
            "de Kha-annu. No es que sea una gran pieza, pero un buen valor "
            "tendr�.\n");
    SetIds(({"plata","trozo de plata","trozo peque�o de plata","mineral"}));
    SetMaterial(M_PLATA);
    SetWeight(125+random(75));
    SetValue(QueryWeight()*6);
}
