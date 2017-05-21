/*una capa, parte del equipo básico de Endor*/


#include <properties.h>
#include <combat.h>
inherit ARMOUR;
create(){
::create();
SetStandard(AT_MANTO, 0, P_SIZE_GENERIC, M_TELA);
SetShort("una capa");
SetLong(
"Es una capade gruesa tela vasta sin teñir y exenta de todo bordado.\n"
"Cerrándose a la altura de uno de los hombros con un broche, cae por la espalda hastalos talones sin estorbar el movimiento de las extremidades.\n"
"Utilizada para resguardarse de las bajas temperaturas  en climas fríos, puede tener "
"también la función de adorno o camuflaje.\n");
SetIds(({"capa","ropa"}));
SetAds(({"de","tela"}));
Set(P_GENDER,GENDER_FEMALE);
Set(P_NUMBER,NUMBER_SINGULAR);

}