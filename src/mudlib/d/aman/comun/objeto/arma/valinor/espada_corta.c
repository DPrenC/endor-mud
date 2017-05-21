/****************************************************************************
Fichero: espada_corta.c
Autor: Aule
Fecha: 15/04/2012
Descripción: Una espada corta de acero
****************************************************************************/

#include <properties.h>
#include <combat.h>
inherit WEAPON;
create()
{
    ::create();
    SetStandard(WT_ESPADA, 7, P_SIZE_MEDIUM, M_ACERO);
    SetShort("una espada corta");
    SetLong("Es una sencilla espada corta cuya hoja de acero de doble filo "
                "se estrecha rápidamente para terminar en una aguzada punta.\n  La "
                "empuñadura  de extremo redondeado no posee  ningún adorno ni grabado "
                "y  está recubierta de tiras de cuero para facilitar la sujección."
                " Los extremos de los gabilanes  se curvan  en ángulo recto hacia "
                "la punta del arma.\n Es un arma perfecta para lanzar rápidas "
                "cuchilladas y apuñalar al enemigo, se suele utilizar como arma "
                "secundaria en los combates, o mientras se esgrime otra arma con la "
                "mano contraria.\n");
    AddId(({"espada"}));
    AddAdjective(({"corta"}));
    Set(P_GENDER, GENDER_FEMALE);
    SetWeight(1500);
    SetNumberHands(1);
}
