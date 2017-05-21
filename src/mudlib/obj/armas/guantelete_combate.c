/* Fichero: guantelete-combate.c */


#include <combat.h>
#include <properties.h>

inherit WEAPON;

create()
{
 ::create();
 SetStandard(WT_GUANTELETE,6,P_SIZE_GENERIC,M_HIERRO);
 SetShort("un guantelete de combate");
 SetLong(
 "Este guantelete est� hecho con varias placas de hierro sobre una superficie de cuero "
 "endurecido. Sobre su dorso y en los nudillos hay unas protuberancias c�nicas que "
 "tienen el objeto de maximizar la potencia y el da�o de sus golpes.\n"
 "Estas crueles armas de combate cuerpo a cuerpo son muy apreciadas por criaturas "
 "crueles y bestiales como los orcos, Uruk-hai e incluso algunos clanes Enanos.\n"
 "Quiz�s no sean mortales pero pueden ser demoledoras a corta distancia.\n");
 }