/* Fichero: cimitarra.c */


#include <combat.h>
#include <properties.h>

inherit WEAPON;
create() {
::create();

SetStandard(WT_CIMITARRA,6,P_SIZE_GENERIC,M_HIERRO);
SetShort("una cimitarra");
SetLong("Es un arma de un solo filo, cuya larga hoja permanece recta hasta el último "
"tercio, donde se curva poco a poco hacia arriba. El  reverso del filo "
"es plano, propio para atizar golpes. La hoja es algo más gruesa que las de lasd "
"espadas comunes y la empuñadura tiene el gabilán superior curvado hacia adelante para "
"atrapar las hojas enemigas, mientras que el inferior se curva un poco hacia la "
"empuñadura para guarnecer la mano. Está envuelta en tiras de cuero superpuestas que "
"facilitan el agarre. La cimitarra es usada por muchos pueblos del sur y este de la "
"Tierra Media y resulta más cómoda para luchar montado.\n");
SetIds(({"arma","cimitarra"}));
SetAds(({"curva", "de", "hierro"}));
}