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
 "Esta gran maza de guerra tiene un largo mango met�lico forrado por tiras de fina "
 "cuerda de esparto. La gruesa contera del mango sirve para golpear de rev�s, mientras que "
 "la enorme cabeza de hierro con forma redondeada y cubierta por numerosos "
 "sobresalientes c�nicos se sit�a en la parte m�s gruesa del mango.\n"
 "Es un arma poderosa y bien manejada es capaz de golpes demoledores que una armadura "
 "dif�cilmente puede paliar. Enanos, orcos y algunas culturas de b�rbaros humanos usan "
 "estas armas con gran habilidad.\n");
}