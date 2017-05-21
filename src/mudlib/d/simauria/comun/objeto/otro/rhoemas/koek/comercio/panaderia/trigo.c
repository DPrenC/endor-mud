/***************************************************************************************
 ARCHIVO:	c_pan_trigo.c
 AUTOR:		[z] Zomax
 FECHA:		23-10-2001
 COMENTARIOS:	Una hogaza de pan de trigo.
 ***************************************************************************************/

#include "path.h"
#include <properties.h>

inherit FOOD;


create () {
 ::create();

 SetFoodKind("food");
 SetFoodMsgs("Te comes un poco de pan de trigo y tienes menos hambre.\n");
 SetFoodStuff(30);
 SetFoodHeal(40);
 SetShort("un pan de trigo");
 SetLong(W(
 "Es una hogaza de pan de trigo con forma redonda hecha por la panadería de Jens en Koek. "
 "Es un pan muy tierno y blanco que elaboran con el mejor trigo de Koek. A simple vista "
 "parece un pan muy sabroso.\n"));
 SetIds(({"pan","hogaza","pan de trigo"}));
 Set(P_GENDER,GENERO_MASCULINO);
 Set(P_NUMBER,NUMERO_SINGULAR);
 Set(P_SIZE,P_SIZE_GENERIC);
 SetWeight(250);
 SetValue(100);

}