/****************************************************************************
Fichero: espada_ancha.c
Autor: Ratwor
Fecha: 25/11/2007
parte del equipo de los guardias del castillo.
****************************************************************************/

#include <properties.h>
#include <combat.h>
inherit WEAPON;
create()
{
    ::create();
    SetStandard(WT_ESPADA, 7, P_SIZE_LARGE, M_HIERRO);
    SetShort("una espada ancha");
    SetLong("La espada ancha se diferencia de la larga en que su hoja tiene mayor anchura "
    "y grosor, con lo cual se consigue un arma de filo mas resistente y pesada manejada"
    " para propinar tajos a corta distancia. La empuñadura es muy sencilla, de pomo apenas"
    " mas grueso que la espiga. Los gabilanes, que se engrosan de la cruz hacia los"
    " extremos, son rectos y de forma cuadrangular.\n"
    "No hace falta esforzarse para ver que es un arma barata, además, su propietario no "
    "le presta demasiados cuidados ya que la hoja aparece opacada y el "
    "filo tiene algunas mellas.\n");
    AddId(({"espada", "ancha", "arma", "espada ancha"}));
    Set(P_GENDER, GENDER_FEMALE);
    SetWeight(1900);
    SetNumberHands(1);
}
