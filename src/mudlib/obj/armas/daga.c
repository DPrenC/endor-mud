/*fichero: daga.c */

#include <combat.h>
#include <properties.h>

inherit WEAPON;



void create()
{

 ::create();
 SetStandard(WT_DAGA,4,P_SIZE_GENERIC,M_ACERO);
  SetShort("una daga");
 SetIds(({"daga", "arma"}));
   SetLong(
   "Es una sencilla daga constituída por una hoja de doble filo recto que hacia el "
   "último tercio de la misma se estrecha hasta terminar en una aguzada punta.\n"
   "Posee una empuñadura cilíndrica envuelta en tiras de cuero entrelazado, con pomo "
   "metálico y gabilanes sencillos que se curvan en ángulo recto hacia la punta del "
   "arma para detener los ataques enemigos. Un arma corta, fácil de ocultar y útil para "
   "tajar o apuñalar y que puede ser utilizada como herramienta improvisada.\n");
  
  }