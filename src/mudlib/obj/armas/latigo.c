/* fichero: latigo.c */
#include <combat.h>
#include <properties.h>

inherit WEAPON;


create() {
  ::create();
  SetStandard(WT_LATIGO, 3, P_SIZE_GENERIC, M_CUERO);
  SetAds(({"un","flexible"}));
  SetIds(({"arma","latigo", "LÁTIGO"}));
  SetShort("un látigo");
  SetLong(
  "Este látigo está formado por un mango de madera tallada de unos treinta "
  "centímetros de longitud del que parte un cuerpo flexible hecho de largas tiras de "
  "cuero trenzado. La punta está rematada por una pequeña esfera metálica para "
  "proporcionar peso y contundencia a los golpes.\n");
}