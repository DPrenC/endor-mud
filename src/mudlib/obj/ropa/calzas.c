/*Unas calzas, parte del equipo básico de Endor*/
#include <properties.h>
#include <combat.h>
inherit ARMOUR;
create(){
::create();
SetStandard(AT_PANTALONES, 0, P_SIZE_GENERIC, M_TELA);
    SetShort("unas calzas");
SetLong(
"Son unas calzas de paño grueso, vasto y sin teñir que cubren las piernas y el pie y "
"llegan hasta la cintura.\n"
"Es una prenda ceñida, formada por dos piezas, una por cada pierna, que en la parte "
"superior y en la entrepierna se unen y sujetan con una serie de finas tiras de cuero "
"flexible que se ajustan en los ojales dispuestos en la otra pieza.\n"
"Bandas verticales de cuero blando rematan las costuras en la parte exterior de la pierna.\n"
"Utilizada por ambos sexos de distintas culturas, es la prenda para las piernas más "
"común en el norte de la Tierra Media.\n");
SetIds(({"calzas","ropa", "calza"}));
SetAds(({"largas","vastas"}));
Set(P_NUMBER,NUMBER_PLURAL);
Set(P_GENDER,GENDER_FEMALE);
}