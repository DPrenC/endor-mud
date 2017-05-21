/***************************************************************************************
 ARCHIVO:	alcaldia.c
 AUTOR:		[z] Zomax
 FECHA:		17-12-2001
 COMENTARIOS:	Alcald�a, planta baja
 ***************************************************************************************/

#include "path.h"

#include <nightday.h>
inherit SCHEDULER_ROOM;
#include RHOEPRESO

create () {
  ::create();

  SetIndoors(1);
  SetIntBright(50);
  SetLocate("Koek");
  SetIntShort("la alcald�a");
  SetIntSmell("No hueles nada especial.\n");
  SetIntNoise("No oyes nada especial.\n");
  SetIntLong("Est�s en la alcald�a de Koek. Aqu� se dedican a organizar los "
  	"asuntos del pueblo, y justo arriba est� el despacho del alcalde, al que "
  	"no se puede acceder sin cita previa. A los lados hay un par de ventanillas "
  	"que suelen estar atendidas por funcionarios, y una peque�a mesita con una "
  	"silla donde se sienta el conserje.\n");
  AddDetail(({"ventanilla","ventanillas"}),"Un par de semic�rculos de cristal se "
  	"abren de entre las paredes. Son las ventanillas donde los funcionarios de "
  	"Koek atienden al p�blico. Parece que suelen estar cerradas todo el tiempo. "
  	"Aqu� no hay mucha gente que pida cosas por ventanilla.\n");
  AddDetail(({"mesa","silla"}),"Hay una mesa de madera de tama�o medio con una silla "
  	"nada m�s entrar, donde se sienta el conserje.\n");
  carcel=(RHOEHAB("koek/calles/cendaf_03.c"));
  AddExit("oeste",RHOEHAB("koek/calles/cendaf_03.c"));
  AddExit("arriba",RHOEHAB("koek/varios/alcaldia_arriba.c"));
    SetLastDest(RHOEHAB("koek/calles/cendaf_03.c"));
    SetNotifyExits("oeste");
    SetAssociatedRooms("./alcaldia_arriba");
    SetSchedulerID("conserje");
    SetCloseTime(({ND_PREFALL, ND_FALL, ND_PRENIGHT, ND_NIGHT, ND_PREDAWN, ND_DAWN, ND_SUNRISE}));
  AddRoomCmd("dar","fdar");
  AddRoomCmd("leer","fleer");
  AddRoomCmd("matar","fmatar");
  AddRoomCmd("robar","frobar");
  AddRoomCmd("confesar","fconfesar");
  AddRoomCmd("entregarse","fentregarse");
  AddItem(RHOEPNJ("koek/varios/frown.c"),REFRESH_DESTRUCT,1);
  AddItem(RHOEPNJ("koek/varios/guardia.c"),REFRESH_DESTRUCT,1);
  AddItem(RHOEPNJ("koek/varios/guardia.c"),REFRESH_DESTRUCT,1);
}


public int fdar(string str)
{
	mapping quest=TP->QueryAttribute("DraegoQuest");
	string titulo;
	object libro;

	if (!str) return 0;
	else str=lower_case(str);
	if (!present("frown",TO) || !living(present("frown",TO))) return 0;
	if (quest && member(quest,"copa") && member(quest,"libro"))
			libro = present(to_string(quest["libro"]),TP);
	if (libro && (str==to_string(quest["libro"])+" a frown" || str==to_string(quest["libro"])+" a conserje" ||
			(str == "libro a frown" )||(str == "libro a conserje")))	{
			libro->remove();
			write("Le das un libro a Frown.\nFrown dice: �As� que te lo ha recomendado Arik? Pues habr� "
			"que echarle un vistazo... gracias por traerme algo de lectura... me aburr�a mucho.\nFrown se "
			"pone a ojear el libro mientras te abre los archivos para que puedas leerlos.\n");
			present("frown",TO)->SetLeyendo(1);
		return 1;
	}
}

public int fleer(string str)
{
	mapping quest=TP->QueryAttribute("DraegoQuest");
	object frown=present("frown",TO);

	if (!str) return 0;
	else str=lower_case(str);
	if (str && (str=="archivos" || str=="archivo"))
	{
		if (living(frown) && frown->QueryLeyendo() && quest && member(quest,"copa") && quest["copa",0]==3)
		{
			write("Empiezas a ojear los archivos...\n");
			say(CATP+" ojea los archivos del ayuntamiento...\n");
			write("Empiezas a leer lentamente los archivos en busca de la hermana perdida de "
			"Fowla, Shiran. Seg�n su ficha en su adolescencia fue arrestada por varios altercados "
			"despu�s de visitar la taberna de la posada pero no lees nada m�s interesante. Parece "
			"como si se la hubiera tragado la tierra desde entonces.\n");
			frown->SetLeyendo(0);
			quest+=(["copa":4]);
			quest-=(["libro"]);
			return 1;
		}
		else
		{
			write("Los archivos est�n cerrados. Si no convences al conserje para que te "
			"deje leerlos mucho me temo que no conseguir�s acertarte a ellos.\n");
			return 1;
		}
	}
}
