/*un faj�n, parte del equipo b�sipo  del mud.*/
#include <properties.h>
#include <combat.h>
inherit ARMOUR;
create(){
::create();
    SetStandard(AT_CINTURON, 0, P_SIZE_GENERIC, M_TELA);
SetShort("un faj�n de tela vasta");
SetLong(
"Se trata de una simple banda de fuerte tela vasta y sin te�ir que se ci�e al talle, "
"anudando sus extremos y dejando caer el sobrante por delante.\n"
"Habitualmente utilizado por las mujeres de distintas culturas, en muchas ocasiones est� "
"hecho de ricas telas y sirve para ajustar la ropa holgada al cuerpo.\n");
SetIds(({"faj�n","ropa", "fajin de tela", "faj�n"}));
SetAds(({"de","tela"}));
Set(P_GENDER,GENDER_MALE);
Set(P_NUMBER,NUMBER_singular);

}