/***************************************************************************************
 ARCHIVO:	entrada.c
 AUTOR:		[z] Zomax
 FECHA:		26-12-2001
 COMENTARIOS:	Entrada a la posada del pueblo
 MODIFICACION:  18-04-2003 Añado viales nuevos y mochila
 		11-05-2003 Quito linea para nuevo driver 3.2.9 (mixed carcel;)
 ***************************************************************************************/

#include <wizlevels.h>
#include "path.h"

inherit SHOP;
#include RHOEPRESO

mixed ficheros;

void fcosas(string tienda)
{
	int i;
	ficheros=get_dir(RHOEVAR("koek/comercio/"+tienda+"/*.c"));
 	for (i=sizeof(ficheros);i--;)
 	{
 		AddArticle(RHOEVAR("koek/comercio/"+tienda+"/"+ficheros[i]),REFRESH_REMOVE,5);
 	}
}

int fentrar_banyo()
{
	if (!present("vale para baño",TP))
	{
		if (living(present("tirkas",TO)))
		{
			notify_fail(W("Tirkas te corta el paso y dice con voz seria: "
			"Para poder disfutar de nuestros servicios tienes que abonarlos "
			"aquí comprando el vale.\n"));
			return 0;
		}
		else
		{
			notify_fail("No puedes entrar allí, nadie te atiende.\n");
			return 0;
		}
	}
	else
	{
		write(W("Tirkas te coge el vale para un baño y te invita a pasar "
			"al baño.\n"));
		say(W(CATP+" le da un vale a Tirkas y éste le invita a pasar hacia "
			"el baño.\n"));
		present("vale para baño",TP)->remove();
		TP->move(RHOEHAB("koek/posada/banyo"),M_GO);
		return 1;
	}
}

int fentrar_dormitorio()
{
	if (!present("vale para dormir",TP))
	{
		if (living(present("tirkas",TO)))
		{
			notify_fail(W("Tirkas te corta el paso y dice con voz seria: "
			"Para poder disfutar de nuestros servicios tienes que abonarlos "
			"aquí comprando el vale.\n"));
			return 0;
		}
		else
		{
			notify_fail("No puedes entrar allí, nadie te atiende.\n");
			return 0;
		}
	}
	else
	{
		write(W("Tirkas te coge el vale para dormir y te invita a pasar "
			"al dormitorio.\n"));
		say(W(CATP+" le da un vale a Tirkas y éste le invita a pasar hacia "
			"el dormitorio.\n"));
		present("vale para dormir",TP)->remove();
		TP->move(RHOEHAB("koek/posada/dormir"),M_GO);
		return 1;
	}
}

create () {
 ::create();

  SetIndoors(1);
  SetIntBright(40);
  SetLocate("Koek");
  SetIntShort("la posada de Seri");
  SetIntSmell("Huele a comida... pero parece que viene del norte.\n");
  SetIntNoise("No oyes nada extraño.\n");
  SetIntLong(W("Esta es la posada del pueblo, también conocida como 'Posada de Seri'. "
  	"Es un negocio muy bien montado para atender a los peregrinos que vienen durante "
  	"todo el año a Koek a visitar el templo. Ofrece varios servicios durante todo el "
  	"día. También tiene montada una pequeña tiendecita con accesorios que vende "
  	"a buen precio.\n"));

  AddDetail(({"suelo"}),"El suelo, hecho de tablones de madera muy limpios.\n");
  AddDetail(({"pared","paredes"}),"Son de madera y no les ves nada especial.\n");
  AddDetail(({"techo"}),"El techo es un simple conjunto de tablones de madera.\n");

  carcel=(RHOEHAB("koek/calles/folker_09"));
  AddExit("norte",RHOEHAB("koek/posada/comedor"));
  AddExit("sur",RHOEHAB("koek/calles/folker_09"));
  AddExit("nordeste",SF(fentrar_banyo));
  AddExit("noroeste",SF(fentrar_dormitorio));
    SetCloseTime(({}));
  AddRoomCmd("matar","fmatar");
  AddRoomCmd("robar","frobar");
  AddRoomCmd("confesar","fconfesar");
  AddRoomCmd("entregarse","fentregarse");
  AddRoomCmd("almacen","falmacen");
  fcosas("posada");
  AddArticle("/obj/sunglasses",REFRESH_REMOVE,d2());
  AddArticle("/obj/torch",REFRESH_REMOVE,3+random(2));
  AddArticle("/obj/oil_bottle",REFRESH_REMOVE,2+random(2));
    AddArticle("/obj/lighter", REFRESH_REMOVE,d2());
  AddArticle("/obj/bandage",REFRESH_REMOVE,d10());
  AddArticle("/obj/cuerda",REFRESH_REMOVE,1);
  AddArticle("/obj/mochila",REFRESH_REMOVE,d4());
  AddArticle("/obj/vial",REFRESH_REMOVE,5+random(2));
  AddArticle("/obj/vialm",REFRESH_REMOVE,5+random(2));
  AddArticle("/obj/vialv",REFRESH_REMOVE,5+random(2));
  AddArticle("/obj/candle", REFRESH_REMOVE,d3());
  SetShopkeeper(RHOEPNJ("koek/posada/tirkas"));
  RemoveDustbin();
  HideExit("almacen",1);
}

int CheckTrade(object ob)
{
	if ((ob->QueryWeaponType() && ob->QueryShort()!="un espejo") || ob->QueryArmourType() || ob->QueryFood() || ob->QueryThing())
		return 0;
	return 1;
}

int falmacen(string str)
{
	if(!IS_LEARNER(TP))
	{
		write("El almacen está cerrado, no puedes pasar.\n");
		return 1;
	}

}

int QueryEntrarPatrullero()
{
	return 1;
}
