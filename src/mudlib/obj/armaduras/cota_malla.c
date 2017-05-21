/*una cota de malla, parte del equipo básico de Endor*/
#include <properties.h>
#include <combat.h>
inherit ARMOUR;
create(){
::create();
SetStandard(AT_CORAZA, 6, P_SIZE_GENERIC, M_HIERRO);
    SetShort("una cota de malla");
SetLong(
"Es una cota de malla de anillos de hierro remachado sobre una base de cuero blando, "
"que cae holgadamente hasta la mitad de los muslos.\n"
"Posee unas cortas mangas que se ensanchan hacia el codo para facilitar los movimientos, "
"y en el borde inferior cuenta con unas aberturas en la parte delantera y trasera con idéntico objetivo.\n"
"De aspecto algo pobre pero funcional, esta armadura es ideal para guerreros y "
"aventureros que no cuenten con muchos recursos y ofrece una protección aceptable en combate.\n");
SetIds(({"cota","armadura", "malla", "malla"}));
SetAds(({"de", "hierro"}));
Set(P_NUMBER,NUMBER_SINGULAR);
Set(P_GENDER,GENDER_FEMALE);
}