/*
Fichero: corona_melkor.c
Autor: Aulë
Fecha: 07/01/2015
Descripción: la corona de Morgoth.
*/

#include <properties.h>
#include <combat.h>
inherit ARMOUR;
create(){
::create();
SetStandard(AT_TIARA, 1, P_SIZE_LARGE, M_ESPECIAL);
SetShort("la corona de hierro de Angband");
SetLong(
"Esta enorme y pesada corona de oscuro hierro retorcido y aguzadas aristas fue "
"forjada por Morgoth a su retorno de Valinor como signo de su señorío sobre la "
"Tierra Media. Observas tres huecos circulares donde encajaban los silmarils que Melkor "
"engarzó antaño.\n");
SetIds(({"corona",  "corona_melkor", "ropa"}));
SetAds(({"de","hierro", "oscura", "negra"}));
Set(P_GENDER,GENDER_FEMALE);
Set(P_NUMBER,NUMBER_SINGULAR);
  SetValue(3000000);
  SetMagic(1);
 Set(P_NOSELL,"Cualquiera huiría ante la sola posibilidad de que le intentaran vender esta corona.\n");
}