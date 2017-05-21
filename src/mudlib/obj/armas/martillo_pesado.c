/* Fichero: martillo_pesado.c */

#include <combat.h>
#include <properties.h>

inherit WEAPON;

create()
{
 ::create();
 SetStandard(WT_MARTILLO_PESADO,12,P_SIZE_GENERIC,M_HIERRO);
 SetShort("un gran martillo de guerra");
   SetLong(
   "Este gran martillo de guerra tiene un largo mango met�lico envuelto en tiras "
   "entrecruzadas de cuero y posee un extremo algo m�s grueso para golpear de rev�s o "
   "apoyarlo en el suelo. La gran cabeza de hierro es maciza y cil�ndrica, permiti�ndo "
   "golpear en ambos sentidos.\n"
   "Los grandes martillos de guerra son una de las armas preferidas por los Enanos, "
   "raza recia y fuerte donde las haya, aunque algunos individuos de otras razas tambi�n "
   "han aprendido a utilizarlas con buenos resultados. Un arma muy destructiva en "
   "cuerpo a cuerpo, contra la que incluso las armaduras m�s pesadas poco pueden hacer.\n");
  }