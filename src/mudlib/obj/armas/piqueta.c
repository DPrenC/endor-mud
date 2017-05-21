/* fichero: piqueta.c */

#include <combat.h>
#include <properties.h>

inherit WEAPON;

create()
{
 ::create();
 SetStandard(WT_PICO,6,P_SIZE_GENERIC,M_HIERRO);
 SetWeight(2000);
 SetShort("Una piqueta");
 SetIds(({"pico","piqueta","pico ligero"}));
 SetNumberHands(1);
 SetLong("Es un pico de pequeño tamaño y menos pesado de lo habitual, útil para "
 "manejar con una sola mano. El mango de madera sustenta una barra de hierro curva con "
 "ambos extremos más afinados. Pese a ser algo más ligera que las versiones a dos manos, "
 "esta piqueta, bien manejada, puede causar heridas muy graves.\n");
}