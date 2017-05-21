/***************************************************************************************
 ARCHIVO:	altaro.c
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
  SetIntLong(W("Te encuentras en uno de los dos altares privados del adalid y sus "
  	"más allegados. Puedes ver que aquí el altar es también muy grande y con la "
  	"losa azul turquesa. Sin duda no eres bienvenido, y desde luego estás "
  	"profanando este lugar de oración con tu presencia. Aquí también ves tapices "
  	"como en el resto de los altares, eso si, de mayor calidad.\n"));

  AddDetail(({"altar"}),W("En medio de la sala hay un altar de mármol azul turquesa donde "
  	"los maestros más allegados al adalid y el propio Kaleband recitan sus oraciones y "
  	"hacen ofrendas a la diosa Xaenetia.\n"));
  AddDetail(({"tapiz","tapices","escenas"}),W("Son unos tapices de muy buena artesanía "
  	"que representan a la diosa en varias situaciones épicas. Son todos de muy buena "
  	"calidad y a cada cual mejor.\n"));
  AddDetail(({"losa","marmol","mármol","hueco","hendidura"}),W("Encima del altar hay una "
  	"enorme losa de mármol amarillo donde se quema el incienso para ofrecerse a Xaenetia.\n"));
  AddDetail(({"pared","paredes"}),W("Las paredes de esta habitación, a pesar de estar "
  	"hechas de la misma roca gris que el resto del templo, están adornadas con "
  	"una gran variedad de tapices de infinitos colores que las hacen irreconocibles.\n"));
  AddDetail(({"suelo","techo"}),W("Está hecho de piedras formando dibujos muy extraños en el "
  	"centro.\n"));
  AddDetail(({"dibujos extranyos","dibujos extraños","dibujos","dibujo","dibujo extraño","dibujo extranyo"}),W(
  	"El suelo forma extraños dibujos en el centro de la sala. Parece que sólo decorativos.\n"));
  AddRoomCmd("quemar","fquemar");
  AddRoomCmd("rezar","frezar");
  AddItem(RHOEPNJ("seri/maestro_rezando"),REFRESH_DESTRUCT,1+random(2));
  AddExit("sur",RHOEHAB("seri/piso03/pasillo_05"));
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
