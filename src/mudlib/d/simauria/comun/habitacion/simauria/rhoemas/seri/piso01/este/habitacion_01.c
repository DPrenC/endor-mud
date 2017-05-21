/***************************************************************************************
 ARCHIVO:	habitacion_01.c
 AUTOR:		[z] Zomax
 FECHA:		13-01-2002
 COMENTARIOS:	Habitaci�n este 01.
 MODIFICACION:  21-04-2003 Cambio cosas... el clonar del dinero en concreto.
 ***************************************************************************************/

#include "path.h"
#include <moving.h>

inherit SIM_ROOM;

int armario,dinero,llave;
object llavec;

string farmario()
{
	string desc;
	desc="Es un gran armario de madera algo vieja con refuerzos de hierro. No "
	     "tiene ning�n tipo de cierre especial salvo una pesada tapa.";
	if (!armario)
		return W(desc+" Est� cerrado.\n");
	else if (armario && (dinero || llave))
		return W(desc+" Est� abierto y parece que hay algo dentro.\n");
	else if (armario && !dinero && !llave)
		return W(desc+" Est� abierto y vac�o.\n");
}

string fmirar()
{
	if (!armario) return "No puedes mirar dentro del armario porque est� cerrado.\n";
	else if (dinero && !llave) return "Parece que hay algo de dinero dentro del armario.\n";
	else if (!dinero && llave) return "Parece que hay una llave dentro del armario.\n";
	else if (dinero && llave) return "Parece que hay algo de dinero y una llave dentro del armario.\n";
	else return "No hay nada dentro del armario.\n";
}

string fdinero()
{
	if (!armario) return "El armario est� cerrado, no puedes ver dentro de �l.\n";
	else if (dinero) return "Miras el dinero. Puedes ver que hay algo de dinero.\n";
}

string fllave()
{
	if (!armario) return "El armario est� cerrado, no puedes ver dentro de �l.\n";
	else if (llave) return "Miras la llave, pero no parece gran cosa.\n";
}

create () {
  ::create();

  SetIndoors(1);
  SetIntBright(60);
  SetLocate("Seri-Solderteg, primer piso, ala este");
  SetIntNoise("Hay un silencio absoluto.\n");
  SetIntSmell(W("Huele a incienso y otras hierbas que se queman en ofrendas por "
  	"todo el templo.\n"));
  SetIntShort("una habitaci�n");
  SetIntLong(W("Est�s en una de las habitaciones de los disc�pulos del templo. Es algo "
  	"peque�a y muy simple, pero lo suficiente como para poder dormir en condiciones. "
  	"Adem�s de la cama puedes ver un armario a los pi�s que sirve de improvisado armario.\n"));
  AddDetail(({"cama","colch�n","colchon"}),W("Pegada a una de las paredes de la habitaci�n "
  	"hay una cama de madera oscura con un colch�n hecho de paja.\n"));
  AddDetail(({"armario","armario"}),SF(farmario));
  AddDetail(({"suelo"}),"El suelo es de roca gris. Est� muy limpio y algo fr�o.\n");
  AddDetail(({"techo"}),W("El techo est� hecho del mismo tipo de roca que el suelo, "
  	"una gris no muy atractiva, pero sin duda resistente.\n"));
  AddDetail(({"pared","paredes"}),W("Las paredes est�n hechas de roca gris. No hay "
  	"nada que las decore y que de algo de alegr�a al lugar.\n"));
  AddDetail(({"dinero de armario","dinero de armario"}),SF(fdinero));
  AddDetail(({"llave de armario","llave de armario"}),SF(fllave));
  AddDetail(({"dentro de armario","dentro de armario"}),SF(fmirar));
  AddRoomCmd("coger","fcoger");
  AddRoomCmd("abrir","fabrir");
  AddRoomCmd("cerrar","fcerrar");
  armario=0;
  dinero=1;
  llave=1;
  AddExit("oeste",RHOEHAB("seri/piso01/este/pasillo_01"));
  if (!random(2)) AddItem(RHOEPNJ("seri/discipulo"),REFRESH_DESTRUCT,1);
}

reset(){
  ::reset();
  dinero=1;
  llave=1;
  armario=0;
}

int fcoger(string str)
{
	object money;
	if(str=="llave" || str=="llave de armario")
	{
		if (llave && armario)
		{
			write("Coges una llave del armario.\n");
			say(W(CATP+" coge algo del armario.\n"),TP);
			money=clone_object("/obj/money");
			money->AdjustMoney(20+random(10),"oro");
			money->move(TP,M_SILENT);
			llave=0;
			return 1;
		}
	}
	else if(str=="dinero" || str=="dinero de armario")
	{
		if (dinero && armario)
		{
			write("Coges algo de dinero del armario.\n");
			say(W(CATP+" coge algo de dinero del armario.\n"),TP);
			money=clone_object("/obj/money");
			money->AdjustMoney(20+random(10),"oro");
			money->move(TP,M_SILENT);
			dinero=0;
			return 1;
		}
	}
	else if (str=="armario")
	{
		write("Es demasiado pesado, no puedes cogerlo.\n");
		return 1;
	}
	else if (str=="cama")
	{
		write(W("No puedes coger la cama, a�n siendo bastante simple es demasiado "
			"pesada para llevarla.\n"));
		return 1;
	}
}

int fabrir(string str)
{
	if (str=="armario")
	{
		if (armario)
		{
			write("No puedes abrir el armario porque ya est� abierto.\n");
			return 1;
		}
		else
		{
			write(W("Como el armario no tiene ning�n tipo de cerradura "
				"abres el armario con mucha facilidad.\n"));
			say(W(CATP+" abre el armario con mucha facilidad, ya que no "
				"tienen ninguna cerradura.\n"),TP);
			armario=1;
			return 1;
		}
	}
}

int fcerrar(string str)
{
	if (str=="armario")
	{
		if (armario)
		{
			write("Cierras el armario con cuidado de no hacer ruido.\n");
			say(W(CATP+" cierra el armario con cuidado de no hacer ruido.\n"),TP);
			armario=0;
			return 1;
		}
		else
		{
			write("No puedes cerrar el armario porque ya est� cerrado.\n");
			return 1;
		}
	}
}
