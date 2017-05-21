/*
Fichero: camisola_cuero.c
Autor: aule
Fecha: 30/01/2015
Descripción: una camisa de cuero para el herrero de Bree
*/


#include <properties.h>
#include <combat.h>
inherit ARMOUR;
create(){
::create();
SetStandard(AT_TUNICA, 1, P_SIZE_LARGE, M_CUERO);
SetShort("una camisola de cuero");
SetLong(
"Es una prenda parecida a una camisa, confeccionada con cuero fino aunque envejecido y "
"algo ajado por el uso. Se cierra por delante con unos toscos botones de latón y las "
"mangas, que se ensanchan a partir del hombro hasta la muñeca, van envueltas y sujetas "
"en los extremos con unas cinchas de cuero que las ajustan al brazo e impiden que cuelgen.\n");
SetIds(({"camisa", "camisola", "ropa"}));
SetAds(({"de","cuero"}));
Set(P_GENDER,GENDER_FEMALE);
Set(P_NUMBER,NUMBER_SINGULAR);

}