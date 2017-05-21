/***************************************************************************************
 ARCHIVO:	granja.c
 AUTOR:		[z] Zomax
 FECHA:		26-12-2001
 COMENTARIOS:	La casa del granjero
 ***************************************************************************************/

#include "path.h"

inherit SIM_ROOM;
#include RHOEPRESO

int encendida;

string fchimenea()
{
	string msg;
	if (encendida) msg="Es una chimenea de hierro negra y algo antigua, pero que sigue\n"
  	"funcionando como el primer d�a. Est� encendida.\n";
  	else msg="Es una chimenea de hierro negra y algo antigua, pero que sigue\n"
  	"funcionando como el primer d�a. Est� apagada.\n";
return msg;
}

reset(){
  ::reset();
  if (CHRONOS->QueryEstacion()==1 || CHRONOS->QueryEstacion()==4) encendida=1;
  else encendida=0;
}


create () {
  ::create();

  SetIndoors(1);
  SetIntBright(50);
  SetLocate("Koek");
  SetIntShort("la casa del granjero");
  SetIntSmell("No hueles nada especial.\n");
  SetIntLong(W("Est�s en la casa del granjero. Es una casa de madera que parece muy "
  	"acogedora. En una de las paredes hay una gran chimenea con algo de le�a al "
  	"lado y un atizador para remover las brasas.\n"));
  AddDetail(({"pared","paredes"}),W("Son de madera muy bien conservada. Una de ellas est� "
  	"dividida en dos por una chimenea.\n"));
  AddDetail(({"chimenea","hueco"}),SF(fchimenea));
  AddDetail(({"le�a","lenya"}),W("Sea la estaci�n que sea siempre hay un poco de le�a al "
  	"lado de la chimenea, por si acaso.\n"));
  AddDetail(({"cenizas","brasas"}),W("Hay algunas cenizas y brasas algo calientes en el "
  	"hueco de la chimenea.\n"));
  carcel=(RHOEHAB("koek/granja/camino_00"));
  AddExit("sur",RHOEHAB("koek/granja/camino_00"));
  AddItem(RHOEVAR("koek/granja/atizador"),2,1);
  AddRoomCmd("matar","fmatar");
  AddRoomCmd("robar","frobar");
  AddRoomCmd("confesar","fconfesar");
  AddRoomCmd("entregarse","fentregarse");
  AddRoomCmd("coger","fcoger");
  AddRoomCmd("apagar","fapagar");
  AddRoomCmd("encender","fencender");
  if (CHRONOS->QueryEstacion()==1 || CHRONOS->QueryEstacion()==4) encendida=1;
  else encendida=0;
}

int fapagar(string str)
{
	if (str=="chimenea")
	{
		if (!encendida)
		{
			write("No puedes apagar la chimenea, ya lo est�.\n");
			say(W(CATP+" se dispon�a a apagar la chimenea, pero se "
			"da cuenta de que ya lo estaba.\n"),TP);
			return 1;
		}
		else
		{
			if (CHRONOS->QueryEstacion()==1 || CHRONOS->QueryEstacion()==4)
			{
				write(W("Apagas la chimenea. La casa se enfr�a "
				"r�pidamente. Ahora hace mucho fr�o.\n"));
				say(W(CATP+" apaga la chimenea. Tienes fr�o.\n"),TP);
				encendida=0;
				return 1;
			}
			else
			{
				write(W("Apagas la chimenea porque ahora no hace "
				"nada de falta. Esto empieza a airearse y no hace "
				"ya tanto calor, s�lo el t�pico de esta �poca.\n"));
				say(W(CATP+" apagar la chimenea porque ahora no hace "
				"nada de fr�o, de hecho hace demasiado calor aqu� dentro.\n"));
				encendida=1;
				return 1;
			}
		}
	}
	else
	{
		notify_fail("�Apagar qu�?\n");
		return 1;
	}
return 0;
}

int fencender(string str)
{
	if (str=="chimenea")
	{
		if (encendida)
		{
			write("No puedes encender la chimenea, ya lo est�.\n");
			say(W(CATP+" se dispon�a a encender la chimenea, pero se "
			"da cuenta de que ya lo estaba.\n"),TP);
			return 1;
		}
		else
		{
			if (CHRONOS->QueryEstacion()==1 || CHRONOS->QueryEstacion()==4)
			{
				write(W("Enciendes la chimenea. La casa se calienta "
				"r�pidamente. Ahora se est� mejor.\n"));
				say(W(CATP+" enciende la chimenea. Ahora hace menos "
				"fr�o.\n"),TP);
				encendida=1;
				return 1;
			}
			else
			{
				write(W("Enciendes la chimenea aunque ahora no hace "
				"nada de falta. Hace mucho calor.\n"));
				say(W(CATP+" enciende la chimenea a pesar de que no hace "
				"nada de fr�o. Ahora hace demasiado calor aqu� dentro.\n"));
				encendida=1;
				return 1;
			}
		}
	}
	else
	{
		notify_fail("�Encender qu�?\n");
		return 1;
	}
return 0;
}

int fcoger(string str)
{
	if (str=="atizador" && !present("atizador",TO))
	{
		write(W("Vaya, parece que alguien se te ha adelantado. Mejor "
			"espera un rato a ver si lo devuelven.\n"));
		return 1;
	}
	else if (str=="cenizas" || str=="ceniza" || str=="brasas" || str=="brasa")
	{
		if (encendida)
		{
			write(W("Intentas coger "+str+", pero la chimenea est� "
			"encendida y te quemas.\n"));
			say(W(CATP+" intenta coger "+str+", pero la chimenea est� "
			"encendida y se quema.\n"),TP);
			if (TP->QueryHP()<=10)
			{
				object brasas;
				brasas=clone_object(RHOEVAR("koek/granja/brasas"));
				brasas->move(TP,M_SILENT);
				return 1;
			}
			else
			{
				TP->AddHP(-10);
				return 1;
			}
		}
		else
		{
			write(W("Piensas en coger "+str+", pero como lo �nico que "
			"conseguir�as es mancharte m�s a�n, desistes.\n"));
			return 1;
		}
	}
return 0;
}
