/***************************************************************************************
 ARCHIVO:	hierro1.c
 AUTOR:		Riberales
 FECHA:		13/10/05
 Descripción: Un trozo pequeño de hierro.
 ***************************************************************************************/

#include "path.h"
#include <properties.h>


inherit THING;



public void create ()
{
  ::create();

    SetShort("un trozo pequeño de mena de hierro");
    SetLong("Es un pequeño fragmento de mena de hierro, extraido de las minas "
            "enanas de Kha-annu. No es que sea una gran pieza, pero su valor "
            "tendrá, pues de aquí se saca el hierro para armas y armaduras.\n");
    SetIds(({"hierro","trozo de hierro","trozo pequeño de hierro","magnetita",
             "mena","mena pequeña","mena pequenya","mena férrica","mena "
             "ferrica","mineral"}));

    SetMaterial(M_HIERRO);
    SetWeight(125+random(100));
    SetValue(QueryWeight()*2);
}
