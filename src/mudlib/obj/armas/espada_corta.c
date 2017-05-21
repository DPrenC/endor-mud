/* Fichero: espada_corta.c */


#include <combat.h>
#include <properties.h>

inherit WEAPON;


create()
{
 ::create();
 SetStandard(WT_ESPADA_CORTA,5,P_SIZE_GENERIC,M_HIERRO);
 SetShort("una espada corta");
 SetLong(
 "Es una espada corta y ligera. Su hoja de doble filo se va estrechando hasta terminar "
 "en una punta aguzada y la sencilla empuñadura envuelta en cuero para facilitar el "
 "agarre, está provista de un pomo trapezoidal y gabilanes de hierro de extremos, algo "
 "más gruesos, curvados hacia la punta del arma.\n"
 "Las espadas cortas son armas muy útiles en combate cuerpo a cuerpo y lugares estrechos "
 "o en distancias muy cortas y su ligereza y maniobrabilidad las hacen ser el arma "
 "preferida de las razas de complexión menuda.\n");
}