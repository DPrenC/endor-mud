/***************************************************************************************
 ARCHIVO:	cofradia.c
 AUTOR:		[z] Zomax
 FECHA:		07-01-2002
 COMENTARIOS:	Cofradía de pescadores
 MODIFICACION:  11-05-2003 Quito linea para nuevo driver 3.2.9 (mixed carcel;)
 ***************************************************************************************/

#include <wizlevels.h>
#include "path.h"

inherit SHOP;
#include RHOEPRESO

#define SAVE_HERE DOMAINLOGPATH "simauria/concurso_pesca_koek"

mixed ficheros;
mapping records;

void fcosas(string tienda)
{
	int i;
	ficheros=get_dir(RHOEVAR("koek/comercio/"+tienda+"/*.c"));
 	for (i=0;i<sizeof(ficheros);i++)
 	{
 		AddArticle(RHOEVAR("koek/comercio/"+tienda+"/"+ficheros[i]),REFRESH_REMOVE,5);
 	}
}

string fcartel()
{
	restore_object(SAVE_HERE);
	return( "   *-------------------------------------------------------*\n"
		"               [52mII GRAN CONCURSO DE PESCA DE KOEK[0m\n"
		"\n"
		"             Pesca un pez mayor que los que tenemos\n"
		"            registrados y gana un maravilloso premio.\n"
		"\n"
		"                  Los actuales ganadores son:\n"
		"\n"
		"                 [36mPrimero: "+capitalize(records[0,0])+", "+records[0,1]+" gramos.  [0m\n"
		"                 [36mSegundo: "+capitalize(records[1,0])+", "+records[1,1]+" gramos.  [0m\n"
		"                 [36mTercero: "+capitalize(records[2,0])+", "+records[2,1]+" gramos.  [0m\n"
		"\n"
		"        El ganador de la primera edición fue [36mBlaise[0m con\n"
		"                  un pez GIGANTE de 3437 grs.\n"
		"   *-------------------------------------------------------*\n");
}

create () {
  ::create();

  SetIndoors(1);
  SetIntBright(50);
  SetLocate("Koek");
  SetIntShort("la cofradía de pescadores");
  SetIntSmell("Huele un poco a humedad y ha pescado, pero no demasiado.\n");
  SetIntNoise("No oyes nada especial.\n");
  SetIntLong(W("Estás en la cofradía de pescadores, un lugar de reunión de "
  	"pescadores y aprovisionamientos de aparejos de pesca. Aquí puedes "
  	"encontrar varios objetos útiles para pescar con garantías. Hay un "
  	"cartel muy grande sobre el concurso de pesca, deberías leerlo.\n"));
  AddDetail(({"cartel","gran cartel"}),W("Hay un gran cartel que anuncia el concurso de pesca, "
  	"deberías leerlo.\n"));
  AddDetail(({"cama"}),"Es una cama dura e incómoda... no tiene buena pinta.\n");
  AddDetail(({"polvo"}),"Parece que el polvo es el único habitante de la casa.\n");
  carcel=(RHOEHAB("koek/calles/folker_02"));
  AddExit("norte",RHOEHAB("koek/calles/folker_02"));
    SetLastDest(RHOEHAB("koek/calles/folker_02"));
    SetNotifyExits("norte");
  AddRoomCmd("matar","fmatar");
  AddRoomCmd("robar","frobar");
  AddRoomCmd("confesar","fconfesar");
  AddRoomCmd("entregarse","fentregarse");
  AddRoomCmd("almacen","falmacen");
  AddRoomCmd("dar","fdar");
  fcosas("cofradia");
  SetShopkeeper(RHOEPNJ("koek/muelle/froeker"));
  RemoveDustbin();
  HideExit("almacen",1);
  AddReadMsg(({"cartel","gran cartel"}),SF(fcartel));
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

int ftasar(string pescado,int peso, object player, object pez)
{
	object oro,plata,cobre;
	restore_object(SAVE_HERE);
	write(W("Froeker dice: Este "+pescado[3..]+" pesa "+peso+" gramos.\n"));
	say(W("Froeker dice: Este "+pescado[3..]+" pesa "+peso+" gramos.\n"),player);
	if (widthof(records)==0)
		records=([0:"zomax";1;"un ridículo pez",1:"hawke";1;"un ridículo pez",2:"gekko";1;"un ridículo pez"]);
	if (records[2,1]>=peso)
	{
		write(W("Froeker dice: Lo siento "+capitalize(player->QueryRealName())+", pero "
			"no has conseguido batir el record.\n"));
		say(W("Froeker dice: Lo siento "+capitalize(player->QueryRealName())+", pero "
			"no has conseguido batir el record.\n"),player);
	}
	else if (records[1,1]>=peso)
	{
		write(W("Froeker dice: Lo siento "+capitalize(player->QueryRealName())+", pero "
			"no has conseguido batir el record, aunque eres nuestro tercer clasificado, "
			"sigue así.\nFroeker te da un poco de cobre como premio de consolación.\n"));
		say(W("Froeker dice: Lo siento "+capitalize(player->QueryRealName())+", pero "
			"no has conseguido batir el record, aunque eres nuestro tercer clasificado, "
			"sigue así, casi lo tienes.\nFroeker le da algo a "+capitalize(player->QueryRealName())+""
			"como premio de consolación.\n"),player);
		cobre=clone_object(RHOEVAR("koek/muelle/cobre"));
		cobre->move(player,M_SILENT);
		records[2,0]=player->QueryRealName();
		records[2,1]=peso;
		records[2,2]=pez->QueryShort();
		save_object(SAVE_HERE);
	}
	else if (records[0,1]>=peso)
	{
		write(W("Froeker dice: Lo siento "+capitalize(player->QueryRealName())+", pero "
			"no has conseguido batir el record, aunque eres nuestro segundo clasificado, "
			"sigue así.\nFroeker te da algo de plata como premio de consolación.\n"));
		say(W("Froeker dice: Lo siento "+capitalize(player->QueryRealName())+", pero "
			"no has conseguido batir el record, aunque eres nuestro segundo clasificado, "
			"sigue así, casi lo tienes.\nFroeker le da algo a "+capitalize(player->QueryRealName())+""
			"como premio de consolación.\n"),player);
		plata=clone_object(RHOEVAR("koek/muelle/plata"));
		plata->move(player,M_SILENT);
		records[2,0]=records[1,0];
		records[2,1]=records[1,1];
		records[2,2]=records[1,2];
		records[1,0]=player->QueryRealName();
		records[1,1]=peso;
		records[1,2]=pez->QueryShort();
		save_object(SAVE_HERE);
	}
	else
	{
		write(W("Froeker dice: ¡Enhorabuena "+capitalize(player->QueryRealName())+"! ¡Eres "
			"nuestro ganador!.\nFroeker te da una pepita de oro como premio.\n"));
		say(W("Froeker dice: ¡Enhorabuena "+capitalize(player->QueryRealName())+"! ¡Eres "
			"nuestro ganador!.\nFroeker le da algo a "+capitalize(player->QueryRealName())+""
			"como recompensa.\n"),player);
		oro=clone_object(RHOEVAR("koek/muelle/oro"));
		oro->move(player,M_SILENT);
		records[2,0]=records[1,0];
		records[2,1]=records[1,1];
		records[2,2]=records[1,2];
		records[1,0]=records[0,0];
		records[1,1]=records[0,1];
		records[1,2]=records[0,2];
		records[0,0]=player->QueryRealName();
		records[0,1]=peso;
		records[0,2]=pez->QueryShort();
		save_object(SAVE_HERE);
	}
	pez->remove();
	return 1;
}

int fdar(string str)
{
	string cosa1, cosa2,pescado;
	object pez,cofrade,player;
	int peso;
	player=TP;
	pez=present("pescado de concurso",TP);
	cofrade=present("froeker",environment(TP));
        if (!str || (sscanf(str,"%s a %s", cosa1, cosa2) != 2))
        {
        	write("¿Dar <qué> a <quién>?\n");
        	return 1;
        }
	else if (pez && cofrade && pez->id(cosa1) && cofrade->id(cosa2))
	{
		if (living(cofrade))
		{
			write(W("Le das un pez a Froeker para tasarlo en concurso. Froeker "
				"lo mira de arriba a abajo y lo pesa.\n"));
			peso=pez->QueryWeight();
			pescado=pez->QueryShort();
			ftasar(pescado,peso,player,pez);
			return 1;
		}
		else
		{
			write(W("Froeker no está en condiciones de recibir nada. Mejor rezas "
				"por su alma.\n"));
			return 1;
		}
	}
}
