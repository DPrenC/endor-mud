/***************************************************************************************
 ARCHIVO:	espada_zendak_vieja.c
 AUTOR:		[z] Zomax
 FECHA:		20-12-2001
 COMENTARIOS:	Espada de Zendak, cuando la encuentran, hecha polvo
 MODIFICACION:  18-03-2003 Cambio Size de Generico a Normal por ser espada humana y por
 		           el nuevo sistema de inventario.
 ***************************************************************************************/

#include "path.h"
#include <properties.h>
#include <combat.h>
#include <materials.h>

inherit WEAPON;

create(){
  ::create();

  SetStandard(WT_ESPADA,1,P_SIZE_MEDIUM,M_HIERRO);
  SetWeight(5500);
  SetValue(0);
  SetNumberHands(1);
  Set(P_GENDER,GENERO_FEMENINO);
  Set(P_NUMBER,NUMERO_SINGULAR);
  Set(P_NOSELL, 1);
  Set(P_NOBUY, 1);
  SetIds(({"espada","espada de zendak","espada de Zendak","espada de Zendak muy oxidada"}));
  SetShort("la espada de Zendak muy oxidada");
  SetLong(W("Esta es la legendaria espada que empuñaba el famoso guerrero Zendak "
  	"en sus combates frente a las criaturas que amenazaban Koek. Es muy "
  	"pesada, y sólo alguien de extraordinaria fueza podría manejarla sin ningún reparo. "
  	"Tiene unas extrañas muescas a ambos lados del filo, que parece que lleven "
  	"la cuenta de los enemigos aniquilados con ella. Tiene un aspecto realmente "
  	"triste, llena de óxido y desperfectos. Quizás un experto herrero experto "
  	"en las técnicas de este valle pueda arreglarla. No está en condiciones de "
  	"dársela a nadie más.\n"));
}

public varargs mixed ChkEquip(object wielder, object weapon, int flags)
{
	if (weapon!=TO) return EQ_OK;
	return "Desistes de tu idea. Esta espada sin duda conoció tiempos mejores, pero ahora no está en estado de ser usada.\n";
}
