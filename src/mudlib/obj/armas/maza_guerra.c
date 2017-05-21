/*  Fichero: maza_guerra.c */

#include <combat.h>
#include <properties.h>

inherit WEAPON;

create() {
  ::create();
  SetStandard(WT_MAZA, 7, P_SIZE_GENERIC, M_HIERRO);
  SetShort("Una maza de guerra");
  SetLong(
"Se trata de un arma pesada y muy contundente. El mango, circundado por bandas met�licas "
"a trechos y rematado por una contera as� mismo met�lica con un peque�o aro que sirve "
"para colgarla del cintur�n, es relativamente corto y va engros�ndose hacia el "
"extremo rematado por una gruesa bola de hierro con diversos sobresalientes c�nicos que "
"cubren su superficie.El peso del arma se distribuye hacia la cabeza y sus potentes "
"golpes a corta distancia pueden partir armaduras y huesos con relativa facilidad.\n"
"Aunque tosca, este arma es efectiva y muy utilizada por Orcos y Enanos, adem�s de otras "
"razas humanas poco civilizadas.\n");
}