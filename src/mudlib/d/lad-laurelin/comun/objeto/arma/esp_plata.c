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
  SetAds(({"plateada","brillante"}));	//adjetivos
  SetIds(({"espada","espadon","el"})); //identificativos
  SetShort("una espada");		//descripcion corta
  SetLong(
  "Es un espadon muy bello que tiene un fulgor especial en la hoja.\n");
  SetWC(10);		//danyo
  SetWeight(7000);		//peso en gramos	
  SetValue(5000);		//precio
  SetDamType(DT_SLASH);		//tipo de danyo
  SetWeaponType(WT_ESPADA);	//tipo de arma
  SetSize(P_SIZE_MEDIUM); //tamanyo
  SetResetQuality(100);	//calidad, estado 1-100
  SetMaterial(M_PLATA);
}
