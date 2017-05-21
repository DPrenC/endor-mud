/* Fichero: espada_sinda.c */


#include <combat.h>
#include <properties.h>

inherit WEAPON;

create()
{
 ::create();
 SetStandard(WT_ESPADA_SINDA,13,P_SIZE_LARGE,M_ACERO);
 SetShort("una hespada sinda");
 SetLong(
 "Esta espada es una verdadera obra de orfebrer�a. El mango, de lisa madera suave y "
 "blanca, es ligeramente curvo, est� rematado por un pomo de metal plateado que respeta "
 "la forma del mango y no posee guarda alguna. La elegante hoja es ligeramente m�s "
 "ancha que la de una espada, tiene un solo filo y se curva elegantemente hacia abajo y "
 "luego hacia arriba, terminando en una aguzada punta. Todas estas curvaturas son muy "
 "leves y dan al conjunto del arma una estructura sinuosa y esbelta. Un par de leves "
 "sobresalientes en la parte del filo y en el anverso de la hoja, curvados hacia la "
 "punta, son la �nica defensa ante las hojas enemigas, pues esta espada incide en la "
 "agilidad de su portador m�s que en la capacidad de parar golpes recios. El acero "
 "espejado de la hoja brilla con un lev�simo tono plateado y tiene algunos caracteres y "
 "diversos signos con forma de espiral cincelados sobre su inmaculada superficie.\n"
 "Estas espadas fueron las utilizadas por los antiguos Elfos Grises o Sindar en los "
 "tiempos antiguos y desde entonces se han extendido mucho entre los dem�s pueblos "
 "�lficos en su decadencia, cre�ndose distintas versiones de tama�os y formas variadas.\n"
 "Solo los Elfos son lo bastante h�biles como para utilizar este arma con fiabilidad.\n");
 }