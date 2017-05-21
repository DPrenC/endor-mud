/***************************************************************************************
 ARCHIVO:	habitacion_01.c
 AUTOR:		[z] Zomax
 FECHA:		04-01-2002
 COMENTARIOS:	Habitación este 01
 ***************************************************************************************/

#include "path.h"
#include <moving.h>

inherit SIM_ROOM;

int arcon,dinero,llave;
object money,llavec;

string farcon()
{
	string desc;
	desc="Es un gran arcón de madera algo vieja con refuerzos de hierro. No "
	     "tiene ningún tipo de cierre especial salvo una pesada tapa.";
	if (!arcon)
		return W(desc+" Está cerrado.\n");
	else if (arcon && (dinero || llave))
		return W(desc+" Está abierto y parece que hay algo dentro.\n");
	else if (arcon && !dinero && !llave)
		return W(desc+" Está abierto y vacío.\n");
}

string fmirar()
{
	if (!arcon) return "No puedes mirar dentro del arcón porque está cerrado.\n";
	else if (dinero && !llave) return "Parece que hay algo de dinero dentro del arcón.\n";
	else if (!dinero && llave) return "Parece que hay una llave dentro del arcón.\n";
	else if (dinero && llave) return "Parece que hay algo de dinero y una llave dentro del arcón.\n";
	else return "No hay nada dentro del arcón.\n";
}

string fdinero()
{
	if (!arcon) return "El arcón está cerrado, no puedes ver dentro de él.\n";
	else if (dinero) return W("Miras el dinero. Puedes ver que hay "+money->QueryShort()+".\n");
}

string fllave()
{
	if (!arcon) return "El arcón está cerrado, no puedes ver dentro de él.\n";
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
  SetIntShort("una habitación");
  SetIntLong(W("Estás en una de las habitaciones de los aprendices del templo. Es algo "
  	"pequeña y muy simple, pero lo suficiente como para poder dormir en condiciones. "
  	"Además de la cama puedes ver un arcón a los piés que sirve de improvisado armario.\n"));
  AddDetail(({"cama","colchón","colchon"}),W("Pegada a una de las paredes de la habitación "
  	"hay una cama de madera oscura con un colchón hecho de paja.\n"));
  AddDetail(({"arcon","arcón"}),SF(farcon));
  AddDetail(({"suelo"}),"El suelo es de roca gris. Está muy limpio y algo frío.\n");
  AddDetail(({"techo"}),W("El techo está hecho del mismo tipo de roca que el suelo, "
  	"una gris no muy atractiva, pero sin duda resistente.\n"));
  AddDetail(({"pared","paredes"}),W("Las paredes están hechas de roca gris. No hay "
  	"nada que las decore y que de algo de alegría al lugar.\n"));
  AddDetail(({"dinero de arcón","dinero de arcon"}),SF(fdinero));
  AddDetail(({"llave de arcón","llave de arcon"}),SF(fllave));
  AddDetail(({"dentro de arcón","dentro de arcon"}),SF(fmirar));
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

	if(str=="llave" || str=="llave de arcon" || str=="llave de arcón")
	{
		if (llave && arcon)
		{
			write("Coges una llave del arcón.\n");
			say(W(CATP+" coge algo del arcón.\n"),TP);
			money->move(TP,M_NOCHECK);
			llave=0;
			return 1;
		}
	}
	else if(str=="dinero" || str=="dinero de arcon" || str=="dinero de arcón")
	{
		if (dinero && arcon)
		{
			write("Coges algo de dinero del arcón.\n");
			say(W(CATP+" coge algo de dinero del arcón.\n"),TP);
			money->move(TP,M_NOCHECK);
			dinero=0;
			return 1;
		}
	}
	else if (str=="arcon" || str=="arcón")
	{
		write("Es demasiado pesado, no puedes cogerlo.\n");
		return 1;
	}
	else if (str=="cama")
	{
		write(W("No puedes coger la cama, aún siendo bastante simple es demasiado "
			"pesada para llevarla.\n"));
		return 1;
	}
}

int fabrir(string str)
{
	if (str=="arcon" || str=="arcón")
	{
		if (arcon)
		{
			write("No puedes abrir el arcón porque ya está abierto.\n");
			return 1;
		}
		else
		{
			write(W("Como el arcón no tiene ningún tipo de cerradura "
				"abres el arcón con mucha facilidad.\n"));
			say(W(CATP+" abre el arcón con mucha facilidad, ya que no "
				"tienen ninguna cerradura.\n"),TP);
			arcon=1;
			return 1;
		}
	}
}

int fcerrar(string str)
{
	if (str=="arcon" || str=="arcón")
	{
		if (arcon)
		{
			write("Cierras el arcón con cuidado de no hacer ruido.\n");
			say(W(CATP+" cierra el arcón con cuidado de no hacer ruido.\n"),TP);
			arcon=0;
			return 1;
		}
		else
		{
			write("No puedes cerrar el arcón porque ya está cerrado.\n");
			return 1;
		}
	}
}
