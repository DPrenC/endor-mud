/***************************************************************************************
 ARCHIVO:	c_pan_centeno.c
 AUTOR:		[z] Zomax
 FECHA:		23-10-2001
 COMENTARIOS:	Una hogaza de pan de centeno.
 ***************************************************************************************/

#include "path.h"
#include <properties.h>

inherit FOOD;


create () {
 ::create();

 SetFoodKind("food");
 SetFoodMsgs("Te comes un poco de pan de centeno y tienes menos hambre.\n");
 SetFoodStuff(30);
 SetFoodHeal(20);
 SetShort("un pan de centeno");
 SetLong(W(
 "Es una hogaza de pan de centeno con forma alargada hecha por la panadería de Jens en Koek. "
 "Es un pan un tanto oscuro, con pequeñas motas de centeno entre la masa. Parece estar muy "
 "bueno, aunque es uno de los panes mas baratos de Jens.\n"));
 AddSubDetail(({"motas"}),"Deben ser semillas de centeno.\n");
 SetIds(({"pan","hogaza","pan de centeno"}));
 Set(P_GENDER,GENERO_MASCULINO);
 Set(P_NUMBER,NUMERO_SINGULAR);
 Set(P_SIZE,P_SIZE_GENERIC);
 SetWeight(250);
 SetValue(50);

}