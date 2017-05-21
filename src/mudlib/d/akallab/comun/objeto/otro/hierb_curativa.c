/*
Nombre:         hierb_curativa.c
Localizacion: 	Bosque de Zarkam.
Comentario:	Recupera 15 puntos de vida.
*/

#include <herbs.h>

inherit HERB;

create()
{
    ::create();
    SetShort("unas hierbas verdes");
    SetLong("Un matojo de frescas y verdes hierbas.\n");
    SetIds(({"hierba","hierbas","matojo"}));
    SetAds(({"verdes","frescas"}));
    SetSmell("No huelen a nada en especial.\n");
    SetWeight(50);
    SetType("hierba");
    SetClass(HERB_CLASS_HEALING);
    SetPower(15);
    SetValue(QueryPowerNumber());
}
