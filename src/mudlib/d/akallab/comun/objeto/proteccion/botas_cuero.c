/*
DESCRIPCION : botas de cuero normales
FICHERO     : /d/akallab/comun/objeto/proteccion/botas_cuero.c
MODIFICACION: 30-11-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

inherit ARMOUR;
#include <properties.h>
#include <combat.h>

create(){
  if (::create()) return 1;
  SetStandard(AT_BOOTS,0, P_SIZE_MEDIUM, M_CUERO);
  SetShort("unas botas de cuero normales");
  SetLong(
    "Son unas botas de cuero del tipo mas corriente. Tienen una gruesa suela y\n"
    "cubren casi hasta la rodilla. No poseen adornos ni son un trabajo muy fino,\n"
    "pero cumplen bien su cometido.\n");

  SetIds(({"botas","botas de cuero"}));
  Set(P_NUMBER,1);//Plural
  Set(P_MATERIAL,M_CUERO);
  SetResetQuality(100);
  SetSize(P_SIZE_MEDIUM);
  SetWeight(1000);
  SetValue(250); // 250 (por ser cuero) x 1 (kg) =  250 monedas de cobre
}