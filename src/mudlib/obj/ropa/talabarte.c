/*un talabarte  para colgar armas y escudos a la espalda, parte del equipo básipo  del mud.*/
#include <properties.h>
#include <combat.h>
inherit ARMOUR;
create(){
::create();
    SetStandard(AT_TALABARTE, 0, P_SIZE_GENERIC, M_CUERO);
SetShort("un talabarte de cuero");
SetLong(
"Es un talabarte conformado por dos gruesas correas de cuero curtido sin teñir que se "
"entrecruzan en pecho y espalda, pasando sobre los hombros y por las caderas.\n"
"Se ajustan al cuerpo mediante unas hebillas de bronce y unos orificios practicados a "
"intervalos regulares en el cuero.\n"
"En la parte trasera se localizan una serie de hebillas y tiras de cuero en las que se "
"puede sujetar un arma a dos manos o un escudo.\n"
"Muy utilizado por guerreros, aventureros o exploradores, permite mayor libertad de "
"movimientos sin el estorbo que podrían suponer objetos tan engorrosos como grandes "
"armas o escudos.\n");
SetIds(({"talabarte","ropa", "talabarte de cuero"}));
SetAds(({"de","cuero"}));
Set(P_GENDER,GENDER_MALE);
Set(P_NUMBER,NUMBER_SINGULAR);

}