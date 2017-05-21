/***************************************************************************************
 ARCHIVO:	hierro2.c
 AUTOR:		Riberales
 FECHA:		13/10/05
 Descripci�n: Un gran trozo de hierro.
 ***************************************************************************************/

#include "path.h"
#include <properties.h>


inherit THING;



public void create ()
{
  ::create();

    SetShort("un gran trozo de mena de hierro");
    SetLong("Es un gran trozo de mena de hierro, de donde luego se saca el "
            "hierro propiamente dicho. Est� sacado de las minas de Kha-annu. "
            "Tiene un tama�o bastante grande, lo que te hace pensar que si lo "
            "empe�as puedes sacar un generoso pu�ado de monedas.\n");
    SetIds(({"hierro","gran pedazo de hierro","mineral","magnetita","mena",
             "mena grande","mena ferrica","mena f�rrica"}));

    SetMaterial(M_HIERRO);
    SetWeight(400+random(250));
    SetValue(QueryWeight()*2);

}
