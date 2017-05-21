/*  Fichero: martillo_guerra.c */

#include <combat.h>
#include <properties.h>

inherit WEAPON;

create() {
  ::create();
  SetStandard(WT_MARTILLO, 7, P_SIZE_GENERIC, M_HIERRO);
  SetShort("Un martillo de guerra");
  SetLong(
  "Este martillo de guerra tiene un recio mango de madera forrado de cuero curtido y "
  "rematado por una contera metálica en la que encaja su extremo. La cabeza del arma es "
  "un lingote de hierro rectangular que permite golpear con ambas partes. El extremo del "
  "mango que sobresale por delante está cubierto de una corta punta cónica metálica.\n"
  "Los martillos de guerra son armas contundentes que permiten su uso junto con un "
  "escudo. Son muy apreciados por los distintos clanes de Enanos de la Tierra Media.\n");
}