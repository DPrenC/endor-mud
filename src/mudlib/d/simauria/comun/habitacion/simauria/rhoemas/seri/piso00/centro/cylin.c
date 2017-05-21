/***************************************************************************************
 ARCHIVO:	cylin.c
 AUTOR:		[z] Zomax
 FECHA:		27-12-2001
 COMENTARIOS:	Entrada al bosque Cylin
 ***************************************************************************************/

#include "path.h"
#include <properties.h>
#include <moving.h>

inherit SIM_ROOM;

int fnorte()
{
	write("La puerta está cerrada, no puedes pasar.\n");
	return 1;
}

int fpuerta(string str)
{
	int i;
	object *gente;
	if(str=="puerta")
	{
		if (present("llave de seri-solderteg",TP))
		{
			if (present("llave de seri-solderteg",TP)->id("llave de cylin") && TP->QueryAttribute("Cylin"))
			{
				write(W("Abres la puerta con una llave y pasas corriendo "
				"antes de que se cierre de un portazo.\n"));
				say(W(CATP+" abre la puerta con una llave y pasa corriendo "
				"antes de que se cierre de un portazo.\n"),TP);
				TP->SetAttribute("Cylin",0);
				gente=TP->QueryFollowers();
				if (gente)
					for(i=0;i<sizeof(gente);i++)
					{
						if (gente[i] && gente[i]->QueryIsPlayer())
						{
							if (gente[i]->Query(P_IS_FOLLOWER))
								gente[i]->Set(P_IS_FOLLOWER,FOLLOW_NO);
							gente-=({gente[i]});
						}
					}
				TP->move(RHOEHAB("cylin/bosque_291"),M_SILENT);
				TP->LookAfterMove();
				return 1;
			}
			else
			{
				write(W("Pruebas a abrir la puerta con una llave, pero "
				"parece que no encaja bien. Al sacarla se te resbala "
				"y cae por el desagüe, perdiéndose.\n"));
				say(W(CATP+" prueba a abrir la puerta con una llave, "
				"pero parece que no encaja bien y al sacarla se le resbala "
				"y cae por el desagüe, perdiéndose.\n"),TP);
				present("llave de seri-solderteg",TP)->remove();
				return 1;
			}
		}
		else
		{
			write("No tienes ninguna llave que pueda abrir esta puerta.\n");
			return 1;
		}
	}
}

int fembestir(string str)
{
	if (str=="puerta")
	{
		if (TP->QueryHP()<=50)
		{
			object brecha;
			write(W("Te dispones a embestir la puerta... coges carrerilla "
			"y... BOOOOOOOOOOOOOOOOOOOMMMMMMM.\n"));
			say(W(CATP+" se dispone a embestir la puerta... coge carrerilla "
			"y.... BOOOOOOOOOOOOOOOOOOOMMMMMMM.\n"),TP);
			tell_room(RHOEHAB("cylin/bosque_291"),W("Oyes un "
			"golpe seco en la puerta que viene de la otra parte.\n"),({TP}));
			brecha=clone_object(RHOEVAR("koek/carcel/brecha"));
			brecha->move(TP,M_SILENT);
		}
		else
		{
			TP->AddHP(-50);
			write(W("Te dispones a embestir la puerta... coges "
			"carrerilla y... BOOOOOOOOOOOOOOOOOOOMMMMMMM un golpe "
			"seco en tu cuerpo te deja hecho polvo... te encuentras mal.\n"));
			say(W(CATP+" se dispone a embestir la puerta... coge "
			"carrerilla y... BOOOOOOOOOOOOOOOOOOOMMMMMMM un golpe "
			"seco en su cuerpo le deja hecho polvo... tiene mala "
			"pinta.\n"),TP);
			tell_room(RHOEHAB("cylin/bosque_291"),W("Oyes un "
			"golpe seco en la puerta que viene de la otra parte.\n"),({TP}));
		}
		return 1;
	}
}

create () {
  ::create();

  SetIndoors(1);
  SetIntBright(60);
  SetLocate("Seri-Solderteg, planta baja");
  SetIntNoise("Hay un silencio absoluto.\n");
  SetIntSmell("Huele a incienso y otras hierbas que se queman en ofrendas por todo el templo.\n");
  SetIntShort("un pasillo");
  SetIntLong(W("Estas en una gran sala justo delante de una enorme puerta con dibujos "
  	"muy extraños. Es una puerta de algún tipo de metal extraño fuertemente cerrada "
  	"que necesita algún tipo de llave o mecanismo para ser abierta, o eso parece por "
  	"la cerradura que tiene. Parece que lleva a algún sitio muy importante o peligroso.\n"));
  AddDetail(({"puerta"}),"Una enorme puerta tapa la entrada hacia el norte.\n");
  AddRoomCmd("abrir","fpuerta");
  AddRoomCmd("embestir","fembestir");
  AddExit("sur",RHOEHAB("seri/piso00/centro/pasillo_05"));
  AddExit("norte",SF(fnorte));
  HideExit("norte",1);
}
