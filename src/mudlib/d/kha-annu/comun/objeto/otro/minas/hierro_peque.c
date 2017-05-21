/***************************************************************************************
 ARCHIVO:	hierro1.c
 AUTOR:		Riberales
 FECHA:		13/10/05
 Descripci�n: Un trozo peque�o de hierro.
 ***************************************************************************************/

#include "path.h"
#include <properties.h>


inherit THING;



public void create ()
{
  ::create();

    SetShort("un trozo peque�o de mena de hierro");
    SetLong("Es un peque�o fragmento de mena de hierro, extraido de las minas "
            "enanas de Kha-annu. No es que sea una gran pieza, pero su valor "
            "tendr�, pues de aqu� se saca el hierro para armas y armaduras.\n");
    SetIds(({"hierro","trozo de hierro","trozo peque�o de hierro","magnetita",
             "mena","mena peque�a","mena pequenya","mena f�rrica","mena "
             "ferrica","mineral"}));

    SetMaterial(M_HIERRO);
    SetWeight(125+random(100));
    SetValue(QueryWeight()*2);
}
