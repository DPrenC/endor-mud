/*una capa, parte del equipo b�sico de Endor*/


#include <properties.h>
#include <combat.h>
inherit ARMOUR;
create(){
::create();
SetStandard(AT_MANTO, 0, P_SIZE_GENERIC, M_TELA);
SetShort("una capa");
SetLong(
"Es una capade gruesa tela vasta sin te�ir y exenta de todo bordado.\n"
"Cerr�ndose a la altura de uno de los hombros con un broche, cae por la espalda hastalos talones sin estorbar el movimiento de las extremidades.\n"
"Utilizada para resguardarse de las bajas temperaturas  en climas fr�os, puede tener "
"tambi�n la funci�n de adorno o camuflaje.\n");
SetIds(({"capa","ropa"}));
SetAds(({"de","tela"}));
Set(P_GENDER,GENDER_FEMALE);
Set(P_NUMBER,NUMBER_SINGULAR);

}