/***************************************************************************************
 ARCHIVO:	altare.c
 AUTOR:		[z] Zomax
 FECHA:		10-01-2002
 COMENTARIOS:	Uno de los altares del templo
 ***************************************************************************************/

#include "path.h"

inherit SIM_ROOM;

create () {
  ::create();

  SetIndoors(1);
  SetIntBright(60);
  SetLocate("Seri-Solderteg, tercer piso");
  SetIntShort("un altar");
  SetIntSmell("Huele a incienso y otras hierbas que se queman en ofrendas por todo el templo.\n");
  SetIntNoise("Hay un silencio absoluto.\n");
  SetIntLong(W("Estás en uno de los dos altares privados del adalid y sus más fieles "
  	"colaboradores. Es casi seguro que tu sola presencia aquí se entiende como "
  	"una profanación que se castiga con la muerte. Puedes ver el típico altar "
  	"de mármol con una gran losa rectangular donde hacen las ofrendas. En este "
  	"caso, debe ser por algún tipo de rango, la losa es de color azul turquesa.\n"));

  AddDetail(({"altar"}),W("Es un maravilloso altar muy bien adornado con alfombras a "
  	"su alrededor y una gran losa blanca en medio donde se realizan las ofrendas.\n"));
  AddDetail(({"tapiz","tapices"}),W("No consigues fijarte en uno solo, hay demasiados "
  	"colgados por todas partes, a cada cual más complejo y a la vez precioso.\n"));
  AddDetail(({"losa","marmol","mármol","hueco"}),W("Una enorme y pesada losa de mármol "
  	"azul turquesa en el centro de la habitación. Justo en el mismo centro de la losa "
  	"hay un pequeño hueco donde se quema incienso.\n"));
  AddDetail(({"pared","paredes"}),W("Las paredes están hechas de piedra y tienen unos "
  	"bonitos tapices que las adornan con gran acierto. No parece el mismo templo, en "
  	"comparación con los pasillos.\n"));
  AddDetail(({"suelo","techo"}),W("Está hecho de piedras formando dibujos muy extraños en el "
  	"centro.\n"));
  AddDetail(({"dibujos extranyos","dibujos extraños","dibujos","dibujo","dibujo extraño","dibujo extranyo"}),W(
  	"El suelo forma extraños dibujos en el centro de la sala. Parece que sólo decorativos.\n"));
  AddRoomCmd("quemar","fquemar");
  AddRoomCmd("rezar","frezar");
  AddItem(RHOEPNJ("seri/maestro_rezando"),REFRESH_DESTRUCT,1+random(2));
  AddExit("sur",RHOEHAB("seri/piso03/pasillo_07"));
}

int fquemar(string str)
{
	if (str=="incienso" && present("incienso",TP))
	{
		write(W("Quemas un poco de incienso en el altar para purificar tu alma. "
			"Te sientes mejor contigo mism"+AO+"\n"));
		say(W(CATP+" quema un poco de incienso en el altar.\n"));
		present("incienso",TP)->fmenos();
		if (TP->QuerySP()<(TP->QueryMaxSP())-5)
			TP->AddSP(5);
		else TP->SetSP(TP->QueryMaxSP());
		return 1;
	}
	else if (str=="incienso" && !present("incienso",TP))
	{
		notify_fail("No tienes incienso para quemar.\n");
		return 0;
	}
	else
	{
		notify_fail("¿Quemar <qué>?\n");
		return 0;
	}
}

int frezar(string str)
{
	write("Rezas una corta oración a la diosa Xaenetia.\n");
	say(W(CATP+" reza una corta oración a la diosa Xaenetia.\n"),TP);
	return 1;
}
