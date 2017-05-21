/***************************************************************************************
 ARCHIVO:	habitacion_01.c
 AUTOR:		[z] Zomax
 FECHA:		04-01-2002
 COMENTARIOS:	Habitaci�n este 01
 ***************************************************************************************/

#include "path.h"
#include <moving.h>

inherit SIM_ROOM;

int arcon,dinero,llave;
object money,llavec;

string farcon()
{
	string desc;
	desc="Es un gran arc�n de madera algo vieja con refuerzos de hierro. No "
	     "tiene ning�n tipo de cierre especial salvo una pesada tapa.";
	if (!arcon)
		return W(desc+" Est� cerrado.\n");
	else if (arcon && (dinero || llave))
		return W(desc+" Est� abierto y parece que hay algo dentro.\n");
	else if (arcon && !dinero && !llave)
		return W(desc+" Est� abierto y vac�o.\n");
}

string fmirar()
{
	if (!arcon) return "No puedes mirar dentro del arc�n porque est� cerrado.\n";
	else if (dinero && !llave) return "Parece que hay algo de dinero dentro del arc�n.\n";
	else if (!dinero && llave) return "Parece que hay una llave dentro del arc�n.\n";
	else if (dinero && llave) return "Parece que hay algo de dinero y una llave dentro del arc�n.\n";
	else return "No hay nada dentro del arc�n.\n";
}

string fdinero()
{
	if (!arcon) return "El arc�n est� cerrado, no puedes ver dentro de �l.\n";
	else if (dinero) return W("Miras el dinero. Puedes ver que hay "+money->QueryShort()+".\n");
}

string fllave()
{
	if (!arcon) return "El arc�n est� cerrado, no puedes ver dentro de �l.\n";
	else if (llave) return "Miras la llave, pero no parece gran cosa.\n";
}

create () {
  ::create();

  SetIndoors(1);
  SetIntBright(60);
  SetLocate("Seri-Solderteg, planta baja, ala este");
  SetIntNoise("Hay un silencio absoluto.\n");
  SetIntSmell(W("Huele a incienso y otras hierbas que se queman en ofrendas por "
  	"todo el templo.\n"));
  SetIntShort("una habitaci�n");
  SetIntLong(W("Est�s en una de las habitaciones de los aprendices del templo. Es algo "
  	"peque�a y muy simple, pero lo suficiente como para poder dormir en condiciones. "
  	"Adem�s de la cama puedes ver un arc�n a los pi�s que sirve de improvisado armario.\n"));
  AddDetail(({"cama","colch�n","colchon"}),W("Pegada a una de las paredes de la habitaci�n "
  	"hay una cama de madera oscura con un colch�n hecho de paja.\n"));
  AddDetail(({"arcon","arc�n"}),SF(farcon));
  AddDetail(({"suelo"}),"El suelo es de roca gris. Est� muy limpio y algo fr�o.\n");
  AddDetail(({"techo"}),W("El techo est� hecho del mismo tipo de roca que el suelo, "
  	"una gris no muy atractiva, pero sin duda resistente.\n"));
  AddDetail(({"pared","paredes"}),W("Las paredes est�n hechas de roca gris. No hay "
  	"nada que las decore y que de algo de alegr�a al lugar.\n"));
  AddDetail(({"dinero de arc�n","dinero de arcon"}),SF(fdinero));
  AddDetail(({"llave de arc�n","llave de arcon"}),SF(fllave));
  AddDetail(({"dentro de arc�n","dentro de arcon"}),SF(fmirar));
  AddRoomCmd("coger","fcoger");
  AddRoomCmd("abrir","fabrir");
  AddRoomCmd("cerrar","fcerrar");
  arcon=0;
  money=clone_object("/obj/money");
  money->AdjustMoney(20+random(10),"oro");
  dinero=1;
  llave=1;
  AddExit("norte",RHOEHAB("seri/piso00/este/pasillo_08"));
  if (!random(2)) AddItem(RHOEPNJ("seri/aprendiz"),REFRESH_DESTRUCT,1);
}

reset(){
  ::reset();
  dinero=1;
  llave=1;
  arcon=0;
  money=clone_object("/obj/money");
  money->AdjustMoney(20+random(10),"oro");
}

int fcoger(string str)
{

	if(str=="llave" || str=="llave de arcon" || str=="llave de arc�n")
	{
		if (llave && arcon)
		{
			write("Coges una llave del arc�n.\n");
			say(W(CATP+" coge algo del arc�n.\n"),TP);
			money->move(TP,M_NOCHECK);
			llave=0;
			return 1;
		}
	}
	else if(str=="dinero" || str=="dinero de arcon" || str=="dinero de arc�n")
	{
		if (dinero && arcon)
		{
			write("Coges algo de dinero del arc�n.\n");
			say(W(CATP+" coge algo de dinero del arc�n.\n"),TP);
			money->move(TP,M_NOCHECK);
			dinero=0;
			return 1;
		}
	}
	else if (str=="arcon" || str=="arc�n")
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
	if (str=="arcon" || str=="arc�n")
	{
		if (arcon)
		{
			write("No puedes abrir el arc�n porque ya est� abierto.\n");
			return 1;
		}
		else
		{
			write(W("Como el arc�n no tiene ning�n tipo de cerradura "
				"abres el arc�n con mucha facilidad.\n"));
			say(W(CATP+" abre el arc�n con mucha facilidad, ya que no "
				"tienen ninguna cerradura.\n"),TP);
			arcon=1;
			return 1;
		}
	}
}

int fcerrar(string str)
{
	if (str=="arcon" || str=="arc�n")
	{
		if (arcon)
		{
			write("Cierras el arc�n con cuidado de no hacer ruido.\n");
			say(W(CATP+" cierra el arc�n con cuidado de no hacer ruido.\n"),TP);
			arcon=0;
			return 1;
		}
		else
		{
			write("No puedes cerrar el arc�n porque ya est� cerrado.\n");
			return 1;
		}
	}
}
