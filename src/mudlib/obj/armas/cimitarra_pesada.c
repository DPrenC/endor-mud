/* Fichero: cimitarra_pesada.c */


#include <combat.h>
#include <properties.h>

inherit WEAPON;

create()
{
 ::create();
 SetStandard(WT_CIMITARRA_PESADA,10,P_SIZE_LARGE,M_HIERRO);
 SetShort("una cimitarra a dos manos");
 SetLong(
 "Se trata de una pesada cimitarra con la curva hoja una cuarta más larga de lo habitual.\n"
 "Su único filo termina en una punta aguzada que puede causar grandes destrozos.\n"
 "La empuñadura envuelta en cuero es amplia para permitir blandir el arma a dos manos y "
 "los gabilones están bifurcados en forma de Y ofreciendo mayor protección contra las hojas "
 "enemigas. El pomo de hierro termina en punta.\n"
 "Estas cimitarras solo se pueden empuñar a dos manos, pues son pesadas y necesitan de "
 "toda la fuerza posible. Orcos, Uruk-hai y las culturas númenóreanas caídas aprecian "
 "mucho estas poderosas cimitarras.\n");
 }