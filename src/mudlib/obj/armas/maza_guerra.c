/*  Fichero: maza_guerra.c */

#include <combat.h>
#include <properties.h>

inherit WEAPON;

create() {
  ::create();
  SetStandard(WT_MAZA, 7, P_SIZE_GENERIC, M_HIERRO);
  SetShort("Una maza de guerra");
  SetLong(
"Se trata de un arma pesada y muy contundente. El mango, circundado por bandas metálicas "
"a trechos y rematado por una contera así mismo metálica con un pequeño aro que sirve "
"para colgarla del cinturón, es relativamente corto y va engrosándose hacia el "
"extremo rematado por una gruesa bola de hierro con diversos sobresalientes cónicos que "
"cubren su superficie.El peso del arma se distribuye hacia la cabeza y sus potentes "
"golpes a corta distancia pueden partir armaduras y huesos con relativa facilidad.\n"
"Aunque tosca, este arma es efectiva y muy utilizada por Orcos y Enanos, además de otras "
"razas humanas poco civilizadas.\n");
}