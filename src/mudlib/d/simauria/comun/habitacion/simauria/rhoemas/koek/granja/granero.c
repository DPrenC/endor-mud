/***************************************************************************************
 ARCHIVO:	granero.c
 AUTOR:		[z] Zomax
 FECHA:		24-12-2001	¡Feliz Nochebuena!
 COMENTARIOS:	El granero
 ***************************************************************************************/

#include "path.h"

inherit SIM_ROOM;
#include RHOEPRESO

int grano,tonel;

reset(){
  ::reset();
  grano=1;
  tonel=0;
}

string fmirar(string str)
{
	string msg;
	if (tonel && grano)
	{
		say(W(CATP+" mira un tonel.\n"));
		msg="Puedes ver algo de grano en el fondo del tonel, parece trigo.\n";
	}
	else if (tonel && !grano)
	{
		say(W(CATP+" mira un tonel.\n"));
		msg="Parece que aquí había algo... pero alguien se lo ha llevado.\n";
	}
	else
	{
		say(W(CATP+" mira un tonel.\n"));
		msg="No ves ningún tonel que llame tu atención\n";
	}
return msg;
}

create () {
  ::create();

  SetIndoors(1);
  SetIntBright(50);
  SetLocate("Koek");
  SetIntShort("un granero");
  SetIntSmell("Hueles a diferentes cereales.\n");
  SetIntNoise("No oyes nada especial.\n");
  SetIntLong(W("Este es el granero del pueblo. Aquí se guarda parte de las cosechas "
  	"para el duro invierno o en caso de sequía. Hay unos grandes toneles de madera "
  	"cerrados donde se guarda el grano y otros abiertos en espera de ser llenados.\n"));
  AddDetail(({"toneles","toneles abiertos","toneles cerrados"}),W("A lo largo y ancho "
  	"del granero hay toneles cerrados que ya tienen grano dentro y otros abiertos "
  	"para ser rellenados lo antes posible.\n"));
  AddDetail(({"suelo","techo","paredes","pared"}),W("Todo el grabero está hecho de madera "
  	"bien conservada, para que los cambios de temperatura no echen a perder el grano.\n"));
  AddDetail(({"tonel","tonel abierto"}),SF(fmirar));
  carcel=(RHOEHAB("koek/calles/folker_00"));
  AddExit("sur",RHOEHAB("koek/calles/folker_00"));
  AddRoomCmd("matar","fmatar");
  AddRoomCmd("robar","frobar");
  AddRoomCmd("confesar","fconfesar");
  AddRoomCmd("entregarse","fentregarse");
  AddRoomCmd("coger","fcoger");
  AddRoomCmd("abrir","fabrir");
  grano=1;
  tonel=0;
}

int fabrir(string str)
{
	if (tonel==0)
	{
		int fza,prob;
		fza=TP->QueryStr();
		if ((50-fza)>1)
		{
			prob=random(50-fza);
		}
		else
		{
			prob=1;
		}
		switch(prob)
		{
			case 1:  write(W("Todos los toneles están demasiado cerrados, pero "
				 "te fijas en uno en especial que parece ser fácil de abrir. "
				 "Con mucho esfuerzo lo abres.\n"));
				 say(W(CATP+" abre uno de los toneles cerrados.\n"),TP);
				 tonel=1;
				 break;
			default: write(W("Intentas abrir uno de los toneles cerrados, pero no "
				 "lo consigues... quizás si fueras más fuerte o probaras otra "
				 "vez... Ahora estás muy cansad"+AO+".\n"));
				 say(W(CATP+" intenta abrir uno de los toneles cerrados, pero "
				 "no lo consigue. Tiene aspecto de estar muy cansad"+AO+".\n"),TP);
				 TP->SetTP(0);
				 break;
		}
		return 1;
	}
	else
	{
		write(W("Todos los toneles están demasiado bien cerrados para poder "
			 "ser abiertos. Hay uno en especial que parecía ser fácil de "
			 "abrir, pero alguien se te ha adelantado y lo ha forzado.\n"));
			 return 1;
	}
return 0;
}

int fcoger(string str)
{
	if (str=="tonel" || str=="toneles" || str=="barril" || str=="barriles" || str=="tonel abierto" || str=="toneles abiertos" || str=="tonel cerrado" || str=="toneles cerrados")
	{
		write(W("¿Los toneles pesan demasiado para que puedas llevarte ni siquiera "
			"uno.\n"));
		return 1;
	}
	else if (tonel && grano && (str=="grano" || str=="trigo"))
	{
		object trigo;
		write("Coges el trigo que habia en el tonel abierto.\n");
		say(W(CATP+" coge algo de trigo del tonel abierto.\n"),TP);
		trigo=clone_object(RHOEVAR("koek/granja/trigo"));
		trigo->move(TP,M_SILENT);
        	grano=0;
        	return 1;
        }
return 0;
}

int QueryEntrarPatrullero()
{
	return 1;
}
