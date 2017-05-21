/*
lenyo.c
creado por orome 20/10/2014
DESCRIPCION  : un trozo de le�o para usarlo en hogueras o carpinter�a, hereda de quemable para ser usado en hogueras.
*/

#include <properties.h>

inherit "/obj/otros/quemable";

create()
{
    ::create();
    SetTipoArbol("�rbol");
    SetShort("un le�o de "+QueryTipoArbol());
    SetLong("Es un pedazo de madera de "+QueryTipoArbol()+" de forma irregular. Es �til "
    "para alimentar hogueras pero a partir de �l tal vez puedan tallarse objetos �tiles "
    "si se tienen los conocimientos adecuados.\n");
    SetIds(({"le�o","lenyo","quemable","madera"}));

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

