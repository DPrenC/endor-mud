/***************************************************************************************
 ARCHIVO:	canya.c
 AUTOR:		[z] Zomax
 FECHA:		20-12-2001
 COMENTARIOS:	Una caña de pescar
 ***************************************************************************************/

#include "path.h"
#include <properties.h>
#include <moving.h>

inherit WEAPON;
int cebo,sedal,pescando;

create () {
 ::create();

 SetShort("una caña de pescar");
 SetLong(W("Es una caña de pescar de lo más simple. Tiene una pequeña rama con "
 	"unos hilos al final del anzuelo para no tener que usar cebo vivo, y poder "
 	"pescar aunque no tengas.\n"));
 AddSubDetail(({"rama"}),"Es algo así como una vara de madera rectay sin nudos.\n");
 AddSubDetail(({"hilo","hilos"}),"El sedal, ni más ni menos.\n");
 AddSubDetail(({"anzuelo"}),"El anzuelo es una varilla de metal doblado y acabado en punta.\n");
 SetIds(({"caña","canya","caña de pescar","canya de pescar"}));
 Set(P_GENDER,GENERO_FEMENINO);
 Set(P_NUMBER,NUMERO_SINGULAR);
 Set(P_SIZE,P_SIZE_GENERIC);
 SetNumberHands(2);
 SetWC(1);
 SetValue(2500);
 SetWeaponType("CsVara");
 SetMaterial(M_MADERA);
 cebo=0;
 sedal=1;
 pescando=0;
}

init(){
  ::init();
  add_action("freparar","reparar");
  add_action("freparar","arreglar");
  add_action("fcebar","cebar");
  add_action("fpescar","pescar");
}

int fcebar(string str)
{
	object canya, cebo;
	canya=TO;
        cebo=present("cebo",TP);
        if (canya->id(str))
        {
        	if (cebo)
        	{
        		write("Con mucho cuidado pones un poco de cebo en la caña.\n");
        		say(W(CATP+" ceba la caña para poder pescar.\n"),TP);
        		cebo->fmenos();
        		canya->SetCebo(1);
        		return 1;
        	}
        	else
        	{
        		notify_fail("No tienes el cebo apropiado para esta caña.\n");
        		return 0;
        	}
        }
        else
        {
        	notify_fail("¿Cebar <qué>?\n");
        	return 0;
        }
}

int freparar(string str)
{
	object canya, sedal;
	canya=TO;
        sedal=present("sedal",TP);
        if (canya->id(str))
        {
        	if (sedal)
        	{
        		write(W("Reparas la caña con el sedal nuevo. Ahora está "
        			"como nueva.\n"));
			say(W(CATP+" repara su caña con un sedal nuevo.\n"),TP);
			canya->SetSedal(1);
			sedal->remove();
			return 1;
        	}
        	else
        	{
        		write("No tienes sedal con el que reparar la caña.\n");
        		return 1;
        	}
        }
}

int fespada()
{
	object espada;
	espada=clone_object(RHOEWEA("koek/varios/espada_zendak_vieja"));
	espada->move(TP,M_SILENT);
	write(W("Has pescado algo. Quitas las algas que la cubren y ¡es una espada "
		"vieja!, pero parece algo especial... Quizás un experto herrero pueda "
		"hacer algo con ella.\n"));
	say(W(CATP+" ha pescado algo... con cuidado le quita las algas que cubren la "
		"pieza y descubre una espada algo vieja pero muy rara.\n"),TP);
	pescando=0;
	return 1;
}

int fnada()
{
	write(W("Levantas la caña y examinas el anzuelo que está tristemente solitario "
		"salvo por el cebo que aún conserva.\n"));
	say(W(CATP+" levanta la caña y su anzuelo sólo sostiene un poco de cebo. "
		"Tiene la mirada un tanto frustrada.\n"),TP);
	pescando=0;
	return 1;
}

int fpierde(object canya)
{
	write(W("Notas un fuerte tirón. Parece que la caña se te ha enredado en algún "
		"tipo de algas en el fondo del lago. En un intento por desengancharla se "
		"te rompe el sedal.\n"));
	say(W(CATP+" hace unos fuertes movimientos como si algo hubiera picado, pero algo "
		"raro pasa, porque parece que ha roto el sedal de la caña.\n"),TP);
	canya->SetSedal(0);
	canya->SetCebo(0);
	pescando=0;
	return 1;
}

int fpescado(object canya)
{
	object pescado;
	write(W("Observas como la caña se mueve mientras está en el agua. Parece que "
		"has pescado un pez. Sin dudarlo tiras del sedal con curiosidad.\n"));
	say(W("Parece que "+CATP+" ha pescado un pez. Ves como tira del sedal con "
		"tanta rapidez como curiosidad.\n"));
	pescado=clone_object(RHOEVAR("koek/muelle/pescado"));
	pescado->move(TP,M_SILENT);
	pescando=0;
	canya->SetCebo(0);
	return 1;
}

int fzapato(object canya)
{
	object zapato;
	write(W("Observas como el sedal se hunde en el lago mientras te preguntas de qué "
		"tamaño será el pez que has pescado. Tiras con suavidad y descubres que "
		"has pescado... ¡UN ZAPATO!.\nVaya... deberían escribir un libro sobre "
		"ésto.\n"));
	say(W(CATP+" observa atentamente como su caña se hunde en el lago y tira rápidamente "
		"del sedal. Tiene la cara descompuesta, ha pescado un magnífico... zapato.\n"));
	zapato=clone_object(RHOEVAR("koek/muelle/zapato"));
	zapato->move(TP,M_SILENT);
	pescando=0;
	canya->SetCebo(0);
	return 1;
}

int fpescar(string str)
{
	if (!str && !pescando && environment(TP) && environment(TP)->QueryPescar())
	{
		object canya;
		int pesca;
		canya=TO;
		if (canya)
		{
			if (canya->QueryEquipped()==TP)
			{
				if (environment(TP)->QueryHielo())
				{
					notify_fail(W("El lago está helado, deberías hacer algo "
						"al respecto antes de tirar la caña.\n"));
					return 0;
				}
				else if (!canya->QuerySedal())
				{
					notify_fail(W("El sedal de la canya está roto, "
						"deberías repararlo.\n"));
					return 0;
				}
				else if (!canya->QueryCebo())
				{
					notify_fail(W("Tendrás que poner algo de cebo, los "
						"peces no son tontos.\n"));
					return 0;
				}
				else
				{
					write(W("Lanzas la caña al lago y esperas "
						"pacientemente a que piquen.\n"));
					say(W(CATP+" lanza la caña al lago y espera "
						"a que piquen.\n"),TP);
					switch(random(100))
					{
						case 10..20:	call_out("fpierde",3,canya);
								break;
						case 30..40:    call_out("fzapato",3,canya);
								break;
						case 50:	call_out("fespada",3);
								break;
						case 60..70:    call_out("fpescado",3,canya);
								break;
						case 80..90:    call_out("fpierde",3,canya);
								break;
						default:	call_out("fnada",3);
								break;
					}
					pescando=1;
					return 1;
				}
			}
			else
			{
				notify_fail("Deberías empuñar la caña de pescar primero.\n");
				return 0;
			}
		}
		else
		{
			notify_fail("Primero deberías de hacerte con una caña para pescar.\n");
			return 0;
		}
	}
	else if (str)
	{
		notify_fail("No creo que puedas elegir lo que vas a pescar.\n");
		return 0;
	}
	else if (pescando)
	{
		notify_fail("Ya estás pescando, paciencia.\n");
		return 0;
	}
	else if (environment(TP) && !environment(TP)->QueryPescar())
	{
		notify_fail(W("Este no parece un buen sitio para pescar con esta caña, "
			"prueba en otro lugar.\n"));
		return 0;
	}
}

int QueryCebo()
{
	return cebo;
}

int QuerySedal()
{
	return sedal;
}

int SetCebo(int valor)
{
	return cebo=valor;
}

int SetSedal(int valor)
{
	return sedal=valor;
}
