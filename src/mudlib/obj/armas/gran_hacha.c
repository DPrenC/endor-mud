/* FICHERO: GRAN_HACHA.C */

#include <combat.h>
#include <properties.h>

inherit WEAPON;

create() {
  ::create();
  SetStandard(WT_HACHA_PESADA, 12, P_SIZE_GENERIC, M_HIERRO);
  SetShort("un hacha de guerra a dos manos");
  SetLong(
"Es un hacha a dos manos con un largo mango de madera reforzado por bandas met�licas y "
"una contera de hierro en el extremo. La pesada hoja posee un filo que se alarga en los "
"extremos para presentar una mayor superficie de corte y para atrapar y arrebatar las "
"armas enemigas. En la parte delantera tiene una corta punta c�nica que tambi�n "
"puede ser utilizada en forma ofensiva.\n"
"Las hachas a dos manos son armas mort�feras y gozan de gran popularidad entre las razas "
"m�s recias como Enanos u Orcos. Son muy utilizadas por las culturas humanas m�s "
"b�rbaras y f�sicamente m�s dotadas como los be�rnidas, aunque tienen la contrapartida de "
"restar agilidad al guerrero y no permiten combinarlas con un escudo.\n");
}