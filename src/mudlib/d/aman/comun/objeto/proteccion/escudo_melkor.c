/*
Fichero: escudo_melkor.c
Autor: Aul�
Fecha: 07/01/2015
Descripci�n: el escudo  de Morgoth.
*/

#include <properties.h>
#include <combat.h>
inherit ARMOUR;
create(){
::create();
SetStandard(AT_ESCUDO, 5, P_SIZE_LARGE, M_ESPECIAL);
SetShort("el escudo de hierro sombr�o");
SetLong(
"Este enorme escudo de hierro es totalmente negro y ninguna insignia lo adorna.\n"
"No obstante, un gran poder oscuro reside en �l, pues echa una larga sombra sobre todo "
"aquello que tiene delante, provocando la desesperanza en el coraz�n de cualquiera "
"que se vea tocado por su influencia.\n");
SetIds(({"escudo",  "escudo_melkor", "armadura"}));
SetAds(({"de","hierro", "oscuro", "negro", "sombrio", "sombr�o"}));
Set(P_GENDER,GENDER_MALE);
Set(P_NUMBER,NUMBER_SINGULAR);
  SetValue(3000000);
  SetMagic(1);
 Set(P_NOSELL,"La sombra proyectada por este escudo disuadir�a a cualquiera de negociar con �l.\n");
}