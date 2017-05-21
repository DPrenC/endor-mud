/***************************************************************************************
 ARCHIVO:	c_lec_botella_leche.c
 AUTOR:		[z] Zomax
 FECHA:		26-10-2001
 COMENTARIOS:	Una botella de leche.
 ***************************************************************************************/

#include "path.h"
#include <properties.h>

inherit DRINK;


create () {
 ::create();

 Set_Drink_Name("leche");
 SetFoodMsg1("Um... buenísima... ahora tienes menos sed.");
 SetFoodMsg2("se bebe una botella entera de leche.");
 SetFoodAlc(0);
 SetFoodHeal(10);
 SetShort("una botella de leche");
 SetLong(W(
 "Es una botella de leche blanca como la nieve y de un aspecto inmejorable, parece del "
 "día.\n"));
 SetIds(({"leche","botella de leche"}));
 Set_Vessel_Name("botella");
 Set_Vessel_Value(10);
 Set_Vessel_Weight(500);
 Set_Vessel_Volume(200);
 Set_Vessel_Gender(GENDER_FEMALE);
 AddId(({"leche","botella de leche"}));
}