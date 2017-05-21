/****************************************************************************
Fichero: patio22.c
Autor: Ratwor
Fecha: 28/12/2007
Descripción: El patio de armas del castillo.
****************************************************************************/

#include "./path.h"

inherit CASTILLO("patio/patio_base");

create(){
    ::create();
    SetIntLong(QueryIntLong()+
    "Esta parte del patio forma un pequeño callejon entre la pared del cobertizo de las "
    "pajareras y las murallas. El pavimento aparece algo descuidado, con algunos "
    "hierbajos sobresaliendo entre las piedras.\n"
    "Hacia el oeste el patio de armas se ensancha, mientras que hacia el sureste una "
    "pequeña abertura practicada en la parte baja de la muralla conduce al interior de "
    "la torre de la Dama.\n");
    AddDetail("hierbajos", "Unos tímidos hierbajos que crecen en los resquicios del "
    "pavimento denunciando el descuido de los habitantes del castillo.\n");
    AddDetail("abertura", "Oradada de forma bastante tosca, una baja abertura en la "
    "piedra conduce a un corto pasadizo que da a la torre de la Dama.\n");
    AddDetail(({"cobertizo", "pajareras", "pajareras"}), "El cobertizo de las pajareras "
    "es un recinto con paredes de adobe y techo de pizarra cuya parte frontal es una "
    "delgada valla de alambre que proporciona luz a las aves de su interior.\n");
    AddExit("oeste", "./patio21");
    AddExit("sudeste", CASTILLO("murallas/pasadizo3"));
}


