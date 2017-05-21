/*
DESCRIPCION    : espada de plata
FICHERO        : esp_platag.c
CREACION       : Alura.
U.MODIFICACION : 10-11-01 [Bomber] Le meto mas peso y valor
                 Realmente, este es un archivo distinto, asi que no se trata de una modificacion
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
  SetWeight(QueryWeight()*2);//Doblo peso
  SetValue(QueryValue()*4);//Cuadruplico valor
  SetDamType(DT_SLASH);         //tipo de danyo
  SetResetQuality(100); //calidad, estado 1-100
}