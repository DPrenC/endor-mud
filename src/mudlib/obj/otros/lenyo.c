/*
lenyo.c
creado por orome 20/10/2014
DESCRIPCION  : un trozo de leño para usarlo en hogueras o carpintería, hereda de quemable para ser usado en hogueras.
*/

#include <properties.h>

inherit "/obj/otros/quemable";

create()
{
    ::create();
    SetTipoArbol("árbol");
    SetShort("un leño de "+QueryTipoArbol());
    SetLong("Es un pedazo de madera de "+QueryTipoArbol()+" de forma irregular. Es útil "
    "para alimentar hogueras pero a partir de él tal vez puedan tallarse objetos útiles "
    "si se tienen los conocimientos adecuados.\n");
    SetIds(({"leño","lenyo","quemable","madera"}));

    SetWeight(5000);
    SetValue(300);
    Set(P_GENDER,GENDER_MALE);
    Set(P_SIZE,P_SIZE_SMALL);
    SetQuemable(1);
    SetCombustion(QueryWeight());
            }


init()
{
    ::init();
    }

