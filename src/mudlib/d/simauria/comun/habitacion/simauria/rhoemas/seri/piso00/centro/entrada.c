/***************************************************************************************
 ARCHIVO:	entrada.c
 AUTOR:		[z] Zomax
 FECHA:		27-12-2001
 COMENTARIOS:	Entrada del templo
 ***************************************************************************************/

#include "path.h"

inherit SIM_ROOM;

create () {
  ::create();

  SetIndoors(1);
  SetIntBright(60);
  SetLocate("Seri-Solderteg, planta baja");
  SetIntShort("la entrada del Templo");
  SetIntSmell("Huele a incienso y otras hierbas que se queman en ofrendas por todo el templo.\n");
  SetIntNoise("Hay un silencio absoluto.\n");
  SetIntLong(W("Estás en la entrada del Templo de Seri-Solderteg. Desde aquí ves partir "
  	"varios pasillos que recorren todo este piso. Por el norte discurre el pasillo "
  	"central y hacia el este y el oeste dos pasillos accesorios. Aquí la decoración "
  	"es muy ostentosa, con tapices relatando la historia del Templo y su fundación. "
  	"Además puedes ver un pequeño altar donde los peregrinos purifican su alma y "
  	"así no profanar este sagrado lugar. Aunque te parece que son supersticiones "
  	"para sacar algo de dinero.\n"));

  AddDetail(({"pasillo","pasillos"}),W("Tienes unos cuantos a elegir: norte, este y oeste. "
  	"Todos parecen igual de interesantes.\n"));
  AddDetail(({"decoración","decoracion","tapiz","tapices"}),W("Puedes ver muchos tapices "
  	"históricos, pero sobre todo te llama uno la atención. Cuenta la historia de cómo "
  	"se fundó el templo, o eso hacia según un cartel que tiene bajo, ahora está completamente "
  	"desgarrado y casi no se distingue nada.\n"));
  AddDetail(({"cartel"}),W("Bajo un tapiz muy deteriorado hay un cartel con algo escrito. "
  	"Quizás puedas leerlo.\n"));
  AddDetail(({"altar"}),W("Hay un pequeño altar donde se puede quemar incienso para "
  	"purificar tu alma y si quieres dejar unas monedas también.\n"));
  AddReadMsg(({"cartel"}),W("Este tapiz fue confeccionado al acabar de construir el templo. "
  	"Representa el esfuerzo y las vidas que se perdieron para conquistar el valle.\n"));
  AddDetail(({"pared","paredes"}),W("Las paredes están hechas de piedra y tienen unos "
  	"bonitos tapices que las adornan con gran acierto.\n"));
  AddDetail(({"suelo","techo"}),W("Está hecho de piedras formando dibujos muy extraños en el "
  	"centro.\n"));
  AddDetail(({"dibujos extranyos","dibujos extraños","dibujos","dibujo","dibujo extraño","dibujo extranyo"}),W(
  	"El suelo forma extraños dibujos en el centro de la sala. Parece que sólo decorativos.\n"));
  AddRoomCmd("quemar","fquemar");
  AddRoomCmd("rezar","frezar");
  AddItem(RHOEPNJ("seri/peregrino"),REFRESH_DESTRUCT,2+random(6));
  AddExit("norte",RHOEHAB("seri/piso00/centro/pasillo_00"));
  AddExit("salir",RHOEHAB("koek/calles/templo_00"));
  AddExit("este",RHOEHAB("seri/piso00/este/pasillo_00"));
  AddExit("oeste",RHOEHAB("seri/piso00/oeste/pasillo_00"));
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
