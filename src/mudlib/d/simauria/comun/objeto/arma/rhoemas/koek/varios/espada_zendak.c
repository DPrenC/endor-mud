/***************************************************************************************
 ARCHIVO:	espada_zendak.c
 AUTOR:		[z] Zomax
 FECHA:		20-12-2001
 COMENTARIOS:	Espada de Zendak
 MODIFICACION:  18-03-2003 Cambio Size de Generico a Normal por ser espada humana y por
 		           el nuevo sistema de inventario.
 		26-04-2003 Pongo comprobaciones de str en valorar y vender o petaba.
 ***************************************************************************************/

#include <wizlevels.h>
#include "path.h"
#include <properties.h>
#include <combat.h>
#include <materials.h>
#include <moving.h>

inherit WEAPON;

create(){
  ::create();

  SetStandard(WT_ESPADA,14,P_SIZE_MEDIUM,M_HIERRO);
  SetWeight(QueryWeight()-500);
  Set(P_NOSELL, 1);
  SetNumberHands(1);
  Set(P_GENDER,GENERO_FEMENINO);
  Set(P_NUMBER,NUMERO_SINGULAR);
  SetIds(({"espada","legendaria espada Zendak"}));
  SetShort("la legendaria espada Zendak");
  SetLong(W("Esta es la legendaria espada que empu�aba el famoso guerrero Zendak "
  	"en sus combates frente a las criaturas que amenazaban Koek. Es muy "
  	"pesada, y s�lo alguien de extraordinaria fuerza podr�a manejarla sin ning�n reparo. "
  	"Tiene unas extra�as muescas a ambos lados del filo, que parece que lleven "
  	"la cuenta de los enemigos aniquilados con ella. Notas como a veces "
  	"tiembla tu mano al empu�arla, como si tuviera vida propia y eligiera a quien "
  	"debe empu�arla. No te conviene enga�arla.\n"));

}

init(){
  ::init();

  add_action("fvender","vender");
  add_action("fvalorar","valorar");
}

public varargs mixed ChkEquip(object wielder, object weapon, int flags)
{
	int i;
	object *cosas;
	
	if (weapon!=TO) return EQ_OK;
	  
	cosas=deep_inventory(wielder);
	for (i=0;i<sizeof(cosas);i++)
	{
		if (cosas[i]->QueryEquipped()==wielder && cosas[i]->id("legendaria espada Zendak"))
		{
			return "Nadie lograr� empu�ar dos espadas de este calibre. Son demasiado poderosas.\n";
		}
	}
	
	if (IS_WIZARD(wielder) || !wielder->QueryIsPlayer())
		return ::ChkEquip(wielder, weapon, flags);
	else if (wielder->QueryStr()<10)
		return "S�lo alguien con una gran fuerza lograr�a controlar su poder.\n";
	else if (wielder->QueryDex()<15)
		return "No eres lo suficientemente expert"+AO+" como para manejarla. Quiz�s en un futuro, qui�n sabe.\n";
	else if (wielder->QueryAttribute("KillGorgona") && wielder->QueryAttribute("EspadaZendak"))
    return ::ChkEquip(wielder, weapon, flags);
  else
  {
  		write("La espada se desintegra en tu mano, parece que no eres dign"+AO+" de ella y has "
  			"intentado enga�arla.\n");
  		say("La legendaria espada que llevaba "+CATP+" se desintegra en una terrible explosi�n.\n", wielder);
  		SetDieMsg("#jug# ha muerto al intentar enga�ar a "+TO->QueryShort()+".");
  		if (wielder->QueryHP()>=100) wielder->AddHP(-100);
  		else wielder->Die();
  		call_out("remove",1,TO);
  		return "Eso ha sido un grave error.\n";
  }
  // Paso de ver q tendria q devolver aqui... supongo  nunca se llegara,
  // aunque sea muy feo si es asi, matar a quien lo hizo
}

int fvender(string str)
{
	if (str && lower_case(str)=="legendaria espada zendak" && present(str,TP) && present(str,TP)==TO && environment(TP) && environment(TP)->QueryShopkeeper() && !TO->QueryEquipped())
	{
		object dinero;
		write("Vendes la legendaria espada Zendak y recibes 100 mithriles.\n");
		say(W(CATP+" vende la legendaria espada Zendak.\n"));
		dinero=clone_object("/obj/money");
		dinero->AdjustMoney(100,"mithril");
		dinero->move(TP,M_SILENT);
		TO->remove();
		return 1;
	}
    return 0;
}

int fvalorar(string str)
{
	if (str && present(str,TP) && present(str,TP)==TO && environment(TP) && environment(TP)->QueryShopkeeper())
	{
		write("Te dar� 100 mithriles por la legendaria espada Zendak.\n");
		return 1;
	}
    return 0;
}
