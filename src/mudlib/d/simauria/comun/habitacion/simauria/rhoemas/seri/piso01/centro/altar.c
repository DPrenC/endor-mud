/***************************************************************************************
 ARCHIVO:	altar.c
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
  SetLocate("Seri-Solderteg, primer piso");
  SetIntShort("un altar");
  SetIntSmell("Huele a incienso y otras hierbas que se queman en ofrendas por todo el templo.\n");
  SetIntNoise("Hay un silencio absoluto.\n");
  SetIntLong(W("Te encuentras en uno de los numerosos altares del templo de Seri-Solderteg, "
  	"dedicado a la diosa Xaenetia. Aqu� rinden culto los disc�pulos en privado alejados "
  	"del tumulto que presentan los altares p�blicos la planta baja del templo. Como en "
  	"el resto de altares hay una gran losa blanca don una hendidura en el centro donde "
  	"se realizan las ofrendas a la diosa.\n"));
  
  AddDetail(({"altar"}),W("Es un maravilloso altar muy bien adornado con alfombras a "
  	"su alrededor y una gran losa blanca en medio donde se realizan las ofrendas.\n"));
  AddDetail(({"tapiz","tapices"}),W("No consigues fijarte en uno solo, hay demasiados, a "
  	"cada cual m�s complicado y a la vez precioso.\n"));
  AddDetail(({"alfombra","alfombras"}),W("Al igual que los tapices puedes ver varias "
  	"alfombras individuales en el suelo para que los preregrinos recen sobre ellas.\n"));
  AddDetail(({"losa","marmol","m�rmol","hueco","hendidura"}),W("Una enorme y pesada losa de m�rmol "
  	"blanco en el centro de la habitaci�n. Justo en el mismo centro de la losa "
  	"hay un peque�o hueco donde se quema incienso.\n"));
  AddDetail(({"pared","paredes"}),W("Las paredes est�n hechas de piedra y tienen unos "
  	"bonitos tapices que las adornan con gran acierto. No parece el mismo templo, en "
  	"comparaci�n con los pasillos de este piso.\n"));
  AddDetail(({"suelo","techo"}),W("Est� hecho de piedras formando dibujos muy extra�os en el "
  	"centro.\n"));
  AddDetail(({"dibujos extranyos","dibujos extra�os","dibujos","dibujo","dibujo extra�o","dibujo extranyo"}),W(
  	"El suelo forma extra�os dibujos en el centro de la sala. Parece que s�lo decorativos.\n"));
  AddRoomCmd("quemar","fquemar");
  AddRoomCmd("rezar","frezar");
  AddItem(RHOEPNJ("seri/discipulo_rezando"),1,3+random(4));
  AddExit("norte",RHOEHAB("seri/piso01/centro/pasillo_00")); 
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
		notify_fail("�Quemar <qu�>?\n");
		return 0;
	}
}

int frezar(string str)
{
	write("Rezas una corta oraci�n a la diosa Xaenetia.\n");
	say(W(CATP+" reza una corta oraci�n a la diosa Xaenetia.\n"),TP);
	return 1;
}
