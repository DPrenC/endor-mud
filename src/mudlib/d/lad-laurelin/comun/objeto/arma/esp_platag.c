/*
DESCRIPCION    : espada de plata
FICHERO        : /d/lad-laurelin/comun/objeto/esp_plata.c
CREACION       : Alura.
U.MODIFICACION : 15-2-00
*/

#include <combat.h>
#include <properties.h>

inherit WEAPON;

create() {
  ::create();
  SetStandard(WT_ESPADA, 7, P_SIZE_LARGE, M_PLATA);
  SetAds(({"plateada","brillante"}));   //adjetivos
  SetShort("una espada");               //descripcion corta
  SetLong(
  "Es un espadon muy bello que tiene un fulgor especial en la hoja.\n");
  SetWeight(7000);              //peso en gramos
  SetValue(8000);               //precio
  SetDamType(DT_SLASH);         //tipo de danyo
  SetResetQuality(100); //calidad, estado 1-100
}