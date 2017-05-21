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
   "Es una sencilla daga constitu�da por una hoja de doble filo recto que hacia el "
   "�ltimo tercio de la misma se estrecha hasta terminar en una aguzada punta.\n"
   "Posee una empu�adura cil�ndrica envuelta en tiras de cuero entrelazado, con pomo "
   "met�lico y gabilanes sencillos que se curvan en �ngulo recto hacia la punta del "
   "arma para detener los ataques enemigos. Un arma corta, f�cil de ocultar y �til para "
   "tajar o apu�alar y que puede ser utilizada como herramienta improvisada.\n");
  
  }