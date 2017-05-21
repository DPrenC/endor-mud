/* Fichero: hacha_khazad.c */


#include <combat.h>
#include <properties.h>

inherit WEAPON;

create()
{
 ::create();
 SetStandard(WT_HACHA_KHAZAD,12,P_SIZE_MEDIUM,M_ACERO);
 SetShort("un hacha Khazad");
 SetLong(
 "El hacha que observas es un arma robusta a la par que hermosa. El mango medianamente "
 "largo forjado en acero y envuelto a trechos en cuero negro presenta signos y motivos "
 "cuadrangulares grabados a lo largo de su extensión. Una contera del mismo material lo "
 "remata con inscripciones en lengua Khuzdul. La cabeza del arma, si bien no tan pesada "
 "como otras hachas dobles a dos manos, es recia y tiene una punta cónica que sobresale "
 "entre ambos filos, que se extienden adelante y atrás para ofrecer una mayor superficie "
 "de corte. Su ligereza, equilibrio y maniobrabilidad la hacen idónea para ser empuñada "
 "a una o dos manos, según lo desee su portador. Las hachas khazad son una de las armas "
 "más usadas por los enanos puesto que les permiten combinarlas con un escudo o "
 "blandirlas a dos manos. Nadie como un enano podría manejar este arma.\n");
 }