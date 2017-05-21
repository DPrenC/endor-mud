/***************************************************************************************
 ARCHIVO:	centro.c
 AUTOR:		[z] Zomax
 FECHA:		30-11-2001
 COMENTARIOS:	Centro de la cárcel
 ***************************************************************************************/

#include "path.h"
#include <moving.h>
#include <properties.h>

inherit SIM_ROOM;

object guard,preso;
mixed destino,*ruta;
string registro;
int paso;

create () {
  ::create();

  SetIndoors(1);
  SetIntBright(30);
  SetLocate("Koek");
  SetIntShort("el interior de la cárcel");
  SetIntLong(W("Estás en el interior de la cárcel de Koek, no parece tan malo "
  	"después de todo. Hay una pequeña mesa de trabajo con un registro de gente "
  	"que ha sido capturada 'con las manos en la masa'.\n"));
  AddDetail(({"mesa"}),W("Es una pequeña mesa de madera donde el carcelero suele "
  	"trabajar con todos los papeles.\n"));
  AddDetail(({"registro"}),"Es el registro de entrada de la cárcel.\n");
  AddDetail(({"papeles","papel","papeleo"}),W("Desafortunadamente para el carcelero "
  	"este trabajo requiere de muchas horas de papeleo.\n"));
  AddReadMsg(({"registro"}),W("Um... decides no cotillear en papeles ajenos... hacer "
  	"eso, y más en la cárcel, puede ser perjudicial para tu integridad física.\n"));
  AddExit("oeste",RHOEHAB("koek/carcel/entrada"));
  AddItem(RHOEPNJ("koek/carcel/carcelero"),1,1);
  AddRoomCmd("matar","fmatar");
  AddRoomCmd("robar","frobar");
  AddRoomCmd("confesar","fconfesar");
  AddRoomCmd("entregarse","fentregarse");
}

int fpapeleo(object guard, object preso, mixed destino, mixed *ruta, int paso)
{
	mixed calabozo;
	if (!guard || guard->QueryEnemies()!=({}) || !living(guard))
	{
		if (present("grilletes",preso))
		{
			tell_object(preso,W("En un momento de descuido del "
			+guard->QueryShort()+" te quitas los grilletes.\n"));
			tell_room(destino,W(CATP+" aprovecha un descuido del "
			+guard->QueryShort()+" y se quita los grilletes.\n"));
			present("grilletes",preso)->remove();
		}
		return 1;
	}
	else if(preso)
	{
		switch(random(5))
		{
			case 0: calabozo=RHOEHAB("koek/carcel/calabozo_00"); break;
			case 1: calabozo=RHOEHAB("koek/carcel/calabozo_01"); break;
			case 2: calabozo=RHOEHAB("koek/carcel/calabozo_02"); break;
			case 3: calabozo=RHOEHAB("koek/carcel/calabozo_03"); break;
			case 4: calabozo=RHOEHAB("koek/carcel/calabozo_04"); break;
			default:calabozo=RHOEHAB("koek/carcel/calabozo_00"); break;
		}
		tell_object(preso,W("[36m"+capitalize(guard->QueryShort())+" "
		"termina el papeleo, te quita los grilletes y te encierra en el calabozo.[0m\n"));
		preso->move(calabozo,M_SILENT);
		preso->LookAfterMove();
		tell_room(calabozo,W("[50m"+capitalize(guard->QueryShort())+" encierra "
		"a "+capitalize(preso->QueryRealName())+" en este calabozo.[0m\n"),({preso}));
		tell_room(TO,(W("[50m"+capitalize(guard->QueryShort())+" termina "
		"el papeleo, le quita los grilletes a "+capitalize(preso->QueryRealName())+" "
		"y le encierra.[0m\n")),({preso}));
		if (present("grilletes",preso))	present("grilletes",preso)->remove();
		return 1;
	}
}

int fpreso(object guard, object preso, mixed destino, mixed *ruta, int paso)
{
	if (guard->QueryEnemies()!=({}) || !living(guard))
	{
		if (present("grilletes",preso))
		{
			tell_object(preso,W("En un momento de descuido de "
			"tu captor te quitas los grilletes.\n"));
			tell_room(destino,W(CATP+" aprovecha un descuido de su "
			"captor y se quita los grilletes.\n"));
			present("grilletes",preso)->remove();
		}
		return 1;
	}
	else if(preso)
	{
		ruta[paso]=destino;
		guard->move(destino,M_SILENT);
		preso->move(destino,M_SILENT);
		preso->LookAfterMove();
		tell_room(destino,W(capitalize(preso->QueryRealName())+" llega "
		"escoltad"+AO+" por "+guard->QueryShort()+".\n"),({preso}));
		tell_object(preso,W("[36m"+capitalize(guard->QueryShort())+" "
		"firma en el registro y prepara el papeleo mientras esperas.[0m\n"));
		tell_room(destino,(W(capitalize(guard->QueryShort())+" firma "
		"en el registro, prepara el papeleo mientras "+capitalize(preso->QueryRealName())+
		" espera.\n")),({preso}));
		call_out("fpapeleo",3,guard,preso,destino,ruta,paso);
		while(paso>0)
		{
			tell_room(ruta[paso],W(capitalize(guard->QueryShort())+" se marcha.\n"),({preso}));
			paso --;
			tell_room(ruta[paso],W(capitalize(guard->QueryShort())+" regresa tras dejar a "+
			capitalize(preso->QueryRealName())+" en la cárcel.\n"),({preso}));
			guard->move(ruta[paso],M_SILENT);
		}
		return 1;
	}
}

int fapresar(string str)
{
	if(living(present("carcelero"))) 	guard=(present("carcelero"));
	else if(living(present("patrullero"))) 	guard=(present("patrullero"));
	else if(living(present("guardia"))) 	guard=(present("guardia"));
	if(guard)
	{
		object grilletes;
		destino=TO;
		preso=TP;
		preso->SetCombatDelay(0);
		if (preso->Query(P_IS_FOLLOWER)) preso->Set(P_IS_FOLLOWER,FOLLOW_NO);
		guard->SetCombatDelay(0);
		write(W("[36m"+capitalize(guard->QueryShort())+" te dice: ¡Uis mira! "
		"¡Un amable ciudadano que se presta voluntario para inspeccionar "
		"los calabozos! Así tendrás tiempo de pensar en lo que intentabas "
		"hacer.[0m\nEn seguida notas como te coloca unos grilletes que te "
		"impiden escaparte.\n"));
		say(W("[36m"+capitalize(guard->QueryShort())+" le recrimina su "
		"acción a "+CATP+" con ironía, le apresa y le pone unos grilletes.[0m\n"),TP);
		grilletes=clone_object(RHOEVAR("koek/carcel/grilletes"));
		grilletes->move(TP,M_NOCHECK);
		if (environment(preso)) grilletes->fsalidas(environment(preso));
		call_out("fpapeleo",2,guard,preso,destino,ruta,paso);
		return 1;
	}
}

int fcarcel(string str)
{
	int nivel,guardias;
	object guarda,*presentes;
	if(living(present("carcelero")))	guarda=(present("carcelero"));
	else if(living(present("patrullero")))	guarda=(present("patrullero"));
	else if(living(present("guardia")))	guarda=(present("guardia"));
	else return 0;
	    if (guarda->QueryLevel()>=TP->QueryLevel())
	{
		if(guarda->QueryShort()=="un patrullero")
			guarda->SetGoChance(0);
		fapresar(str);
		return 1;
	}
	else
	{
		int i;
		nivel=(guarda->QueryLevel()-5);
		presentes=all_inventory(TO);
		for (i=0;i<sizeof(presentes);i++)
		{
			if(presentes[i]->QueryShort()=="el carcelero" || presentes[i]->QueryShort()=="un guardia" || presentes[i]->QueryShort()=="un patrullero")
				nivel=nivel+5;
		}
		if (nivel>=TP->QueryLevel())
		{
			fapresar(str);
			return 1;
		}
	}
return 0;
}

int fmatar(string str)
{
	if (living(present(str,TO)))
	{
		write(W("Intentas matar a "+present(str,TO)->QueryShort()+"...\n"));
		say(W(CATP+" intenta matar a "+present(str,TO)->QueryShort()+"...\n"),TP);
		if (fcarcel(str)) return 1;
	}
return 0;
}

int frobar(string str)
{
	string aquien;
        if (str)
        {
        	if (sscanf(str,"a %s",aquien) == 1)
        	{
        		if (living(present(aquien,TO)))
			{
				write(W("Intentas robar a "+present(aquien,TO)->QueryShort()+"...\n"));
				say(W(CATP+" intenta robar a "+present(aquien,TO)->QueryShort()+"...\n"),TP);
				if (fcarcel(str)) return 1;
			}
        	}
        }
return 0;
}

int fconfesar(string str)
{
	if(living(present("carcelero")) || living(present("patrullero")) || living(present("guardia")))
	{
		write("Confiesas un terrible crimen y te entregas.\n");
		say(W(CATP+" confiesa un terrible crimen y se entrega.\n"),TP);
		fapresar(str);
		return 1;
	}
	else
	{
		write(W("Quieres confesar un crimen, pero ahora no hay ningún "
		" defensor de la ley para hacer eso.\n"));
		say(W(CATP+" quiere confesar un crimen, pero ahora no hay ningún "
		" defensor de la ley para hacer eso.\n"),TP);
		return 1;
	}
return 0;
}

int fentregarse(string str)
{
	if(living(present("carcelero")) || living(present("patrullero")) || living(present("guardia")))
	{
		write("Te entregas para ser juzgado por tus terribles crímenes.\n");
		say(W(CATP+" se entrega para ser juzgado por sus terribles crímenes.\n"),TP);
		fapresar(str);
		return 1;
	}
	else
	{
		write(W("Quieres entregarte, pero ahora no hay ningún "
		" defensor de la ley para hacer eso.\n"));
		say(W(CATP+" quiere entregarse, pero ahora no hay ningún "
		" defensor de la ley para hacer eso.\n"),TP);
		return 1;
	}
return 0;
}
