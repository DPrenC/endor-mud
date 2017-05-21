/***************************************************************************************
 ARCHIVO:	pescado.c
 AUTOR:		[z] Zomax
 FECHA:		07-01-2002
 COMENTARIOS:	Los peces que se pescan
 ***************************************************************************************/

#include "path.h"
#include <properties.h>

inherit FOOD;

create () {
 ::create();

 SetFoodKind("food");
 SetFoodMsgs("Comes un poco de pescado. Está muy bueno.\n");
 SetFoodStuff(10);
 SetFoodHeal(10);
 Set(P_GENDER,GENERO_MASCULINO);
 Set(P_NUMBER,NUMERO_SINGULAR);
 Set(P_SIZE,P_SIZE_GENERIC);
 SetIds(({"pez","pescado","pescado de concurso"}));
 switch(random(1000))
 {
 	case 0 .. 200:
 		SetShort("un ridículo pez");
 		SetLong(W("Es un pez muy muy pequeño. Lo mejor que puedes hacer "
 			"es devolverlo al lago, aunque dado el aspecto que tiene "
 			"ya casi es mejor organizarle un funeral.\n"));
 		SetWeight(50+random(50));
 		break;

 	case 201 .. 400:
 		SetShort("un pez algo pequeño");
 		SetLong(W("Es un pez más bien pequeño, aunque quizás se podría hacer "
 			"algo con él.\n"));
 		SetWeight(150+random(100));
 		break;

 	case 401 .. 600:
 		SetShort("un pez mediano");
 		SetLong(W("Es un pez normal. Tiene un buen tamaño, parecido a los "
 			"que venden en la pescadería.\n"));
 		SetWeight(300+random(500));
 		break;

 	case 601 .. 800:
 		SetShort("un gran pez");
 		SetLong(W("Es una pieza realmente envidiable. Tiene unas dimensiones "
 			"que hacen que el resto de pescadores te envidien.\n"));
 		SetWeight(800+random(200));
 		break;

 	case 801 .. 970:
 		SetShort("un enorme pez");
 		SetLong("Observas con orgullo la pieza de un enorme pez.\n");
 		SetWeight(1000+random(500));
 		break;

 	case 971 .. 999:
 		SetShort("un pez GIGANTE");
 		SetLong("Es el pez más grande que has visto en tu vida. Sobran los comentarios.\n");
 		SetWeight(1500+random(2000));
 		break;
 	default:
 		SetShort("un pececillo");
 		SetLong("Esto no es un pez... es mas una cría. Pobrecillo.\n");
 		SetWeight(100);
 		break;
 }
}

private int SetWeight(int peso)
{
	return ::SetWeight(peso);
}
