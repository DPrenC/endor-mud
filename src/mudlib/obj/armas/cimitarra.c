/* Fichero: cimitarra.c */


#include <combat.h>
#include <properties.h>

inherit WEAPON;
create() {
::create();

SetStandard(WT_CIMITARRA,6,P_SIZE_GENERIC,M_HIERRO);
SetShort("una cimitarra");
SetLong("Es un arma de un solo filo, cuya larga hoja permanece recta hasta el �ltimo "
"tercio, donde se curva poco a poco hacia arriba. El  reverso del filo "
"es plano, propio para atizar golpes. La hoja es algo m�s gruesa que las de lasd "
"espadas comunes y la empu�adura tiene el gabil�n superior curvado hacia adelante para "
"atrapar las hojas enemigas, mientras que el inferior se curva un poco hacia la "
"empu�adura para guarnecer la mano. Est� envuelta en tiras de cuero superpuestas que "
"facilitan el agarre. La cimitarra es usada por muchos pueblos del sur y este de la "
"Tierra Media y resulta m�s c�moda para luchar montado.\n");
SetIds(({"arma","cimitarra"}));
SetAds(({"curva", "de", "hierro"}));
}