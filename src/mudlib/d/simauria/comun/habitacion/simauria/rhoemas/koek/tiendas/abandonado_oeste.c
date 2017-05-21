/***************************************************************************************
 ARCHIVO:	abandonado_oeste.c
 AUTOR:		[z] Zomax
 FECHA:		28-10-2001
 COMENTARIOS:	Local abandonado.
 MODIFICACION:  22-04-2003 Añado las cartas de los presos para el Quest. Solo pueden
 		encontrarlas quienes estén haciendo la version de quest que corresponde
 		así que ojito que no hay bugs (o eso se pretende) no vale darselas al
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
		return W("Los tablones de madera están podridos y ves alguno que "
		"otro rajado. Uno en particular llama tu atención porque al pasar "
		"por encima se mueve. Quizás pudieras moverlo o levantarlo.\n");
	}
	else return "Están en muy mal estado, todos podridos.\n";
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
			"un segundo coges una y dejas el tablón en su sitio.\n"));
			cartas=clone_object(RHOEVAR("koek/varios/carta_maestro"));
			cartas->move(TP,M_NOCHECK);
			carta_int=0;
			return 1;
		}
		else
		{
			write(W("Parece que alguien se te ha adelantado. Quizás sea un "
			"alma caritativa y devuelva lo que sea a su lugar. Tendrás que esperar.\n"));
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
  SetIntLong(W("Estás en lo que en su día fue un próspero negocio, pero que "
 	"no se sabe por qué cerró sus puertas. Es un local abandonado "
 	"completamente vacío lleno de polvo.\n"));
  AddDetail(({"polvo"}),"Es lo único que queda en este sitio.\n");
  AddDetail(({"humedad"}),W("Las paredes y el suelo, hechos de madera, "
 	"están muy deterioradas, y puedes ver manchas de humedad.\n"));
  AddDetail(({"suelo"}),W("El suelo, hecho de tablones de madera en bastante "
 	"mal estado, cruje a tu paso.\n"));
  AddDetail(({"madera"}),"Está toda podrida.\n");
  AddDetail(({"pared","paredes"}),W("Están llenas de manchas de humedad y "
 	"madera en mal estado.\n"));
  AddDetail(({"techo"}),W("El techo es un simple conjunto de tablones de "
 	"madera muy muy deteriorados.\n"));
  AddDetail(({"tablon","tablón","tablones"}),SF(ftablones));
  AddDetail(({"decoración"}),"No ves ningún tipo de decoración en ningún sitio.\n");
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