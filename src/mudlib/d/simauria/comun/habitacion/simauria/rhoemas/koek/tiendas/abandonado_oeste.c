/***************************************************************************************
 ARCHIVO:	abandonado_oeste.c
 AUTOR:		[z] Zomax
 FECHA:		28-10-2001
 COMENTARIOS:	Local abandonado.
 MODIFICACION:  22-04-2003 A�ado las cartas de los presos para el Quest. Solo pueden
 		encontrarlas quienes est�n haciendo la version de quest que corresponde
 		as� que ojito que no hay bugs (o eso se pretende) no vale darselas al
 		player de turno que te dice que no rula...
 ***************************************************************************************/

#include "path.h"
#include <moving.h>

inherit SIM_ROOM;

int carta_int;
mixed carcel;

public string ftablones()
{
	mapping quest=TP->QueryAttribute("DraegoQuest");

	if (quest && member(quest,"libro") && quest["libro",0]==3)
	{
		return W("Los tablones de madera est�n podridos y ves alguno que "
		"otro rajado. Uno en particular llama tu atenci�n porque al pasar "
		"por encima se mueve. Quiz�s pudieras moverlo o levantarlo.\n");
	}
	else return "Est�n en muy mal estado, todos podridos.\n";
}

public int fcartas(string str)
{
	object cartas;
	mapping quest=TP->QueryAttribute("DraegoQuest");

	if (quest && member(quest,"libro") && quest["libro",0]==3)
		quest+=(["libro":4]);
	if (quest && member(quest,"libro") && quest["libro",0]==4)
	{
		if (carta_int)
		{
			write(W("Mueves uno de los tablones y encuentras tal y como te dijo "
			"Rakon las cartas que su maestro le envia desde su retiro. Sin dudarlo "
			"un segundo coges una y dejas el tabl�n en su sitio.\n"));
			cartas=clone_object(RHOEVAR("koek/varios/carta_maestro"));
			cartas->move(TP,M_NOCHECK);
			carta_int=0;
			return 1;
		}
		else
		{
			write(W("Parece que alguien se te ha adelantado. Quiz�s sea un "
			"alma caritativa y devuelva lo que sea a su lugar. Tendr�s que esperar.\n"));
			return 1;
		}
	}
	else return 0;
}

create () {
 ::create();

  SetIndoors(1);
  SetIntBright(40);
  SetLocate("Koek");
  SetIntShort("un local abandonado");
  SetIntSmell("Huele a humedad y madera podrida.\n");
  SetIntNoise("No oyes nada especial salvo los crujidos del suelo al andar.\n");
  SetIntLong(W("Est�s en lo que en su d�a fue un pr�spero negocio, pero que "
 	"no se sabe por qu� cerr� sus puertas. Es un local abandonado "
 	"completamente vac�o lleno de polvo.\n"));
  AddDetail(({"polvo"}),"Es lo �nico que queda en este sitio.\n");
  AddDetail(({"humedad"}),W("Las paredes y el suelo, hechos de madera, "
 	"est�n muy deterioradas, y puedes ver manchas de humedad.\n"));
  AddDetail(({"suelo"}),W("El suelo, hecho de tablones de madera en bastante "
 	"mal estado, cruje a tu paso.\n"));
  AddDetail(({"madera"}),"Est� toda podrida.\n");
  AddDetail(({"pared","paredes"}),W("Est�n llenas de manchas de humedad y "
 	"madera en mal estado.\n"));
  AddDetail(({"techo"}),W("El techo es un simple conjunto de tablones de "
 	"madera muy muy deteriorados.\n"));
  AddDetail(({"tablon","tabl�n","tablones"}),SF(ftablones));
  AddDetail(({"decoraci�n"}),"No ves ning�n tipo de decoraci�n en ning�n sitio.\n");
  AddExit("este",RHOEHAB("koek/calles/kadhu_00"));
  carcel=(RHOEHAB("koek/calles/kadhu_00"));
  AddRoomCmd("matar","fmatar");
  AddRoomCmd("robar","frobar");
  AddRoomCmd("confesar","fconfesar");
  AddRoomCmd("entregarse","fentregarse");
  AddRoomCmd("mover","fcartas");
  AddRoomCmd("levantar","fcartas");
  carta_int=1;
}

reset(){
  ::reset();
  carta_int=1;
}