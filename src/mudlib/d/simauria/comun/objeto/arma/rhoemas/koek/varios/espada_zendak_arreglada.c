/***************************************************************************************
 ARCHIVO:	espada_zendak_arreglada.c
 AUTOR:		[z] Zomax
 FECHA:		20-12-2001
 COMENTARIOS:	Espada de Zendak
 MODIFICACION:  18-03-2003 Cambio el peso para que el nuevo sistema de inventario no la
 		           haga desaparecer cuando se complete el quest.
		18-03-2003 Cambio Size de Generico a Normal por ser espada humana y por
 		           el nuevo sistema de inventario.

 ***************************************************************************************/

#include "path.h"
#include <properties.h>
#include <combat.h>
#include <materials.h>

inherit WEAPON;

create(){
  ::create();

  SetStandard(WT_ESPADA,6,P_SIZE_MEDIUM,M_HIERRO);
  SetWeight(5500);
  SetValue(0);
  SetNumberHands(1);
  Set(P_WP_PER_QP,25);
  Set(P_GENDER,GENERO_FEMENINO);
  Set(P_NUMBER,NUMERO_SINGULAR);
  Set(P_NOSELL, 1);
  Set(P_NOBUY, 1);
  SetIds(({"espada","la espada de Zendak","espada arreglada"}));
  SetShort("la espada de Zendak");
  SetLong(W("Esta es la legendaria espada que empuñaba el famoso guerrero Zendak "
  	"en sus combates frente a las criaturas que amenazaban Koek. Es muy "
  	"pesada, y sólo alguien de extraordinaria fuerza podría manejarla sin ningún reparo. "
  	"Tiene unas extrañas muescas a ambos lados del filo, que parece que lleven "
  	"la cuenta de los enemigos aniquilados con ella. Notas como a veces "
  	"tiembla tu mano al empuñarla, como si tuviera vida propia.\n"));
}

public varargs mixed ChkEquip(object wielder, object weapon, int flags)
{
	int i;
	object *cosas;
	
	if (weapon!=TO) return EQ_OK;
	  
	cosas=deep_inventory(wielder);
	for (i=0;i<sizeof(cosas);i++)
	{
		if (cosas[i]->QueryEquipped()==wielder && cosas[i]->QueryShort()=="la espada de Zendak")
		{
			return "Nadie logrará empuñar dos espadas de este calibre. Son demasiado poderosas.\n";
		}
	}
	if (!wielder->QueryIsPlayer()) return EQ_OK;
	return ::ChkEquip(wielder, weapon, flags);
}
