/* una capucha, parte del equipo b�sico de Endor*/


#include <properties.h>
#include <combat.h>
inherit ARMOUR;
create(){
::create();
SetStandard(AT_CAPUCHA, 0, P_SIZE_GENERIC, M_TELA);
    SetShort("una capucha");
SetLong(
"Es una capucha de tela vasta, sin te�ir y embreada para impermeabilizarla.\n"
Cubre holgadamente la cabeza y el cuello, y mediante unos finos cordones de cuero "
"cosidos en el borde delantero puede ajustarse para ensombrecer u ocultar el rostro.\n"
"Suele utilizarse m�s en climas fr�os para resguardarse de las bajas temperaturas, "
"aunque tambi�n suele cumplir funciones de camuflaje u ocultamiento.\n"
"Utilizada por ambos sexos de numerosas razas y culturas, a veces forma parte de un "
"manto o capa a la que va unida.\n");
SetIds(({"capucha","ropa"}));
SetAds(({"de","tela"}));
Set(P_GENDER,GENDER_FEMALE);
Set(P_NUMBER,NUMBER_SINGULAR);

}