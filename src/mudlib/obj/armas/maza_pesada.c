/* Fichero: maza_pesada.c */


#include <combat.h>
#include <properties.h>

inherit WEAPON;

create()
{
 ::create();
 SetStandard(WT_MAZA_PESADA,12,P_SIZE_GENERIC,M_HIERRO);
 SetShort("una maza a dos manos");
 SetLong(
 "Esta gran maza de guerra tiene un largo mango metálico forrado por tiras de fina "
 "cuerda de esparto. La gruesa contera del mango sirve para golpear de revés, mientras que "
 "la enorme cabeza de hierro con forma redondeada y cubierta por numerosos "
 "sobresalientes cónicos se sitúa en la parte más gruesa del mango.\n"
 "Es un arma poderosa y bien manejada es capaz de golpes demoledores que una armadura "
 "difícilmente puede paliar. Enanos, orcos y algunas culturas de bárbaros humanos usan "
 "estas armas con gran habilidad.\n");
}