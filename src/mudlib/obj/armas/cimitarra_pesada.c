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
 "Se trata de una pesada cimitarra con la curva hoja una cuarta m�s larga de lo habitual.\n"
 "Su �nico filo termina en una punta aguzada que puede causar grandes destrozos.\n"
 "La empu�adura envuelta en cuero es amplia para permitir blandir el arma a dos manos y "
 "los gabilones est�n bifurcados en forma de Y ofreciendo mayor protecci�n contra las hojas "
 "enemigas. El pomo de hierro termina en punta.\n"
 "Estas cimitarras solo se pueden empu�ar a dos manos, pues son pesadas y necesitan de "
 "toda la fuerza posible. Orcos, Uruk-hai y las culturas n�men�reanas ca�das aprecian "
 "mucho estas poderosas cimitarras.\n");
 }