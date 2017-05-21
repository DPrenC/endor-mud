/* fichero: latigo.c */
#include <combat.h>
#include <properties.h>

inherit WEAPON;


create() {
  ::create();
  SetStandard(WT_LATIGO, 3, P_SIZE_GENERIC, M_CUERO);
  SetAds(({"un","flexible"}));
  SetIds(({"arma","latigo", "L�TIGO"}));
  SetShort("un l�tigo");
  SetLong(
  "Este l�tigo est� formado por un mango de madera tallada de unos treinta "
  "cent�metros de longitud del que parte un cuerpo flexible hecho de largas tiras de "
  "cuero trenzado. La punta est� rematada por una peque�a esfera met�lica para "
  "proporcionar peso y contundencia a los golpes.\n");
}