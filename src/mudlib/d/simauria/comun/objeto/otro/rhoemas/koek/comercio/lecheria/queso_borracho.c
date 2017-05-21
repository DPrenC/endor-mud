/***************************************************************************************
 ARCHIVO:	c_lec_queso_borracho.c
 AUTOR:		[z] Zomax
 FECHA:		27-10-2001
 COMENTARIOS:	Un queso 'especial'.
 ***************************************************************************************/

#include "path.h"
#include <properties.h>

inherit FOOD;


create () {
 ::create();

 SetFoodKind("food");
 SetFoodMsgs("Te comes un poco de queso borracho.\n");
 SetFoodStuff(20);
 SetFoodHeal(50);
 SetFoodAlc(100);

 SetShort("un queso borracho");
 SetLong(W(
 "Es un queso blanco normal y corriente pero que ha estado sumergido en algún tipo "
 "de bebida alcohólica durante mucho mucho tiempo... Huele muy fuerte, y puede tumbar un "
 "caballo.\n"));
 SetSmell("Huele a la taberna de Cored. Te trae buenos recuerdos.\n");
 SetIds(({"queso","queso borracho"}));
 Set(P_GENDER,GENERO_MASCULINO);
 Set(P_NUMBER,NUMERO_SINGULAR);
 Set(P_SIZE,P_SIZE_GENERIC);
 SetWeight(150);
 SetValue(1000);
}