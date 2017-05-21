/***************************************************************************************
 ARCHIVO:		preso.c
 AUTOR:		[z] Zomax
 FECHA:		30-11-2001
 COMENTARIOS:	Funciones que te llevan a la cárcel.
 MODIFICACION: 24-04-2003 Repaso de código, quito lo que sobra.
 ***************************************************************************************/

// [Nyh] por dios... mira q hacer esto un include, pa matar a alguien
// al menos añado el #idndef #define #endif para q no pete si se añade varias veces

#ifndef _PRESO_H_
#define _PRESO_H_

#include "path.h"
#include <moving.h>
#include <properties.h>

object guard,preso;
mixed destino,carcel,*ruta;
int paso;

public mixed QueryCarcel()
{
	return carcel;
}

public int fpreso_bucle(object guard, object preso, mixed destino, mixed *ruta, int paso)
{
	if (!guard || guard->QueryEnemies()!=({}) || !living(guard))
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
	destino->fpreso(guard,preso,destino,ruta,paso);
	return 1;
}

public int fpreso(object guard, object preso, mixed destino, mixed *ruta, int paso)
{
	if(preso && living(preso))
	{
		ruta[paso]=destino;
		paso++;
		tell_object(preso,W("[37m"+capitalize(guard->QueryShort())+" sigue su "
		"camino hacia la cárcel sin soltarte. [0m\n"));
		tell_room(destino,W(capitalize(preso->QueryRealName())+" llega "
		"escoltad"+AO+" por "+guard->QueryShort()+".\n"),({preso}));
		if (paso-2!=0)
			tell_room(ruta[paso-2],W(capitalize(preso->QueryRealName())+" y "
			""+guard->QueryShort()+" continúan su camino hacia la cárcel.\n"),({preso}));
		guard->move(destino,M_SILENT);
		preso->move(destino,M_SILENT);
		preso->LookAfterMove();
		if (environment(preso))
			present("grilletes",preso)->fsalidas(environment(preso));
		destino=(environment(guard))->QueryCarcel();
		call_out("fpreso_bucle",2,guard,preso,destino,ruta,paso);
		return 1;
	}
	else return 1;
}

public int fapresar(string str)
{
	guard=0;
	if(living(present("carcelero")))	guard=(present("carcelero"));
	else if(living(present("patrullero")))	guard=(present("patrullero"));
	else if(living(present("guardia")))	guard=(present("guardia"));
	if(guard)
	{
		object grilletes;
		preso=TP;
		preso->SetCombatDelay(0);
		guard->SetCombatDelay(0);
		if (preso->Query(P_IS_FOLLOWER)) preso->Set(P_IS_FOLLOWER,FOLLOW_NO);
		write(W("[36m"+capitalize(guard->QueryShort())+" te dice: ¡Uis mira! "
		"¡Un amable ciudadano que se presta voluntario para inspeccionar "
		"los calabozos! Así tendrás tiempo de pensar en lo que intentabas "
		"hacer.[0m\n"
		"En seguida notas como te coloca unos grilletes que te impiden escaparte.\n"));
		say(W("[36m"+capitalize(guard->QueryShort())+" le recrimina su "
		"acción a "+CATP+" con ironía, le apresa, le pone unos grilletes "
		"y salen camino a la cárcel.[0m\n"),TP);
		grilletes=clone_object(RHOEVAR("koek/carcel/grilletes"));
		grilletes->move(TP,M_NOCHECK);
		if (environment(preso)) grilletes->fsalidas(environment(preso));
		destino=TO->QueryCarcel();
		paso=0;
		ruta=allocate(100);
		ruta[paso]=TO;
		paso++;
		call_out("fpreso_bucle",2,guard,preso,destino,ruta,paso);
		return 1;
	}
}

public int fcarcel(string str)
{
	int nivel,guardias;
	object guarda,*presentes;
	if(living(present("carcelero"))) 	guarda=(present("carcelero"));
	else if(living(present("patrullero")))	guarda=(present("patrullero"));
	else if(living(present("guardia")))	guarda=(present("guardia"));
	if (guarda)
	{
		if (guarda->QueryLevel()>=TP->QueryLevel())
		{
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
	}
    return 0;
}

public int fmatar(string str)
{
	if (str && (living(present(str,TO))))
	{
		write(W("Intentas matar a "+present(str,TO)->QueryShort()+"...\n"));
		say(W(CATP+" intenta matar a "+present(str,TO)->QueryShort()+"...\n"),TP);
		if (fcarcel(str)) return 1;
	}
    return 0;
}

public int frobar(string str)
{
	string aquien;
        if (str && sscanf(str,"a %s",aquien) == 1)
        {
        	if (living(present(aquien,TO)))
		{
			write(W("Intentas robar a "+present(aquien,TO)->QueryShort()+"...\n"));
			say(W(CATP+" intenta robar a "+present(aquien,TO)->QueryShort()+"...\n"),TP);
			if (fcarcel(str)) return 1;
    		  }
    }
    return 0;
}

public int fconfesar(string str)
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

public int fentregarse(string str)
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

#endif
