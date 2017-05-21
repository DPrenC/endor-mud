/***************************************************************************************
 ARCHIVO:	pantano.c
 AUTOR:		[k] Korsario
 FECHA:		03-05-1998
 COMENTARIOS:	Base del pantano de la muerte, reunificado por [z] Zomax
 ***************************************************************************************/

#include "path.h"

inherit ROOM;

create(){
  ::create();

  SetIndoors(0);
  SetLocate("pantano de la muerte");
  SetIntNoise("Escuchas un ruido extraño detrás de ti, como si algo se acercase.\n");
  SetIntSmell("No huele muy bien aquí. Huele a agua estancada.\n");

  SetIntShort("el pantano de la muerte");
  switch(random(4))
  {
  	case 0:	SetIntLong("Este es el pantano de la muerte. EstÁs totalmente "
  		"rodeado de maleza, árboles y agua estancada por todos lados. Los "
  		"árboles forman una bóveda cerrada que impide saber incluso si es "
  		"dedía o es denoche, hay una oscuridad terrorífica. El paisaje es "
  		"tan parecido y contínuo que es muy fácil perderse y es tan fácil "
  		"encontrar la salida como la propia muerte.\n");
  		break;
  	case 1:	SetIntLong("Este es el pantano de la muerte. Estás totalmente "
  		"rodeado de maleza, árboles y agua estancada por todos lados. Los "
  		"árboles forman una bóveda cerrada que impide saber incluso si es "
  		"dedia o es denoche, hay una oscuridad terrorífica. El suelo parece "
  		"mas fanagoso en esta zona.\n");
  		break;
  	case 2:	SetIntLong("Este es el pantano de la muerte. Estás totalmente "
  		"rodeado de maleza, árboles y agua estancada por todos lados. Los "
  		"árboles forman una bóveda cerrada que impide saber incluso si es "
  		"dedía o es denoche, hay una oscuridad terrorífica. El paisaje es "
  		"tan parecido y contínuo que es muy fácil perderse. Algunos de los "
  		"árboles parecen tener vida y estar observandote.\n");
  		break;
  	default:SetIntLong("Este es el pantano de la muerte. Estás totalmente "
  		"rodeado de maleza, árboles y agua estancada por todos lados. Los "
  		"árboles forman una bóveda cerrada que impide saber incluso si es "
  		"dedía o es denoche. Una niebla fantasmagórica se arrastra entre "
  		"los troncos y oculta el suelo y la maleza baja. El paisaje es tan "
  		"parecido y contínuo que es muy fácil perderse.\n");
  		break;
  }

  AddDetail(({"maleza"}),"Hay una gran variedad de arbustos y malas hierbas que "
  	"dificultan el paso y te impiden ver más allá de unos metros.\n");
  AddDetail(({"arboles","árboles","arbol","árbol","boveda","bóveda"}),"Los árboles "
  	"forman una bóveda cerrada que es tan espesa que no sabrías decir si es dedía "
  	"o denoche.\n");

  AddRoomCmd("orientarse","forientarse");
}

string msg(int numero)
{
	switch(numero)
	{
		case 0:	return "norte";		break;
		case 1:	return "nordeste";	break;
		case 2:	return "noroeste";	break;
		case 3:	return "sur";		break;
		case 4:	return "sudeste";	break;
		case 5:	return "suroeste";	break;
		case 6:	return "este";		break;
		case 7:	return "oeste";		break;
	}
	return "";
}

void fsalidas()
{
	int num;
	num=random(8);
	switch(random(100))
	{
		case 5:
			AddExit("norte",FLENHAB+"pantano/pantano_0"+random(10)+".c");
			AddExit("nordeste",FLENHAB+"pantano/pantano_0"+random(10)+".c");
			AddExit("noroeste",FLENHAB+"pantano/pantano_0"+random(10)+".c");
			AddExit("sur",FLENHAB+"pantano/pantano_0"+random(10)+".c");
			AddExit("sudeste",FLENHAB+"pantano/pantano_0"+random(10)+".c");
			AddExit("suroeste",FLENHAB+"pantano/pantano_0"+random(10)+".c");
			AddExit("este",FLENHAB+"pantano/pantano_0"+random(10)+".c");
			AddExit("oeste",FLENHAB+"pantano/pantano_0"+random(10)+".c");
			switch(num)
			{
				case 0:	AddExit("norte",FLENHAB+"pantano/templo_00");		break;
				case 1:	AddExit("nordeste",FLENHAB+"pantano/templo_00");	break;
				case 2:	AddExit("noroeste",FLENHAB+"pantano/templo_00");	break;
				case 3:	AddExit("sur",FLENHAB+"pantano/templo_00");		break;
				case 4:	AddExit("sudeste",FLENHAB+"pantano/templo_00");	break;
				case 5:	AddExit("suroeste",FLENHAB+"pantano/templo_00");	break;
				case 6:	AddExit("este",FLENHAB+"pantano/templo_00");		break;
				default:AddExit("oeste",FLENHAB+"pantano/templo_00");		break;
			}
			break;
		case 55..60:
			AddExit("norte",FLENHAB+"pantano/pantano_0"+random(10)+".c");
			AddExit("nordeste",FLENHAB+"pantano/pantano_0"+random(10)+".c");
			AddExit("noroeste",FLENHAB+"pantano/pantano_0"+random(10)+".c");
			AddExit("sur",FLENHAB+"pantano/pantano_0"+random(10)+".c");
			AddExit("sudeste",FLENHAB+"pantano/pantano_0"+random(10)+".c");
			AddExit("suroeste",FLENHAB+"pantano/pantano_0"+random(10)+".c");
			AddExit("este",FLENHAB+"pantano/pantano_0"+random(10)+".c");
			AddExit("oeste",FLENHAB+"pantano/pantano_0"+random(10)+".c");
			switch(num)
			{
				case 0:	AddExit("norte",FLENHAB+"pantano/lago");	break;
				case 1:	AddExit("nordeste",FLENHAB+"pantano/lago");	break;
				case 2:	AddExit("noroeste",FLENHAB+"pantano/lago");	break;
				case 3:	AddExit("sur",FLENHAB+"pantano/lago");	break;
				case 4:	AddExit("sudeste",FLENHAB+"pantano/lago");	break;
				case 5:	AddExit("suroeste",FLENHAB+"pantano/lago");	break;
				case 6:	AddExit("este",FLENHAB+"pantano/lago");	break;
				default:AddExit("oeste",FLENHAB+"pantano/lago");	break;
			}
			break;
		case 65..70:
			AddExit("norte",FLENHAB+"pantano/pantano_0"+random(10)+".c");
			AddExit("nordeste",FLENHAB+"pantano/pantano_0"+random(10)+".c");
			AddExit("noroeste",FLENHAB+"pantano/pantano_0"+random(10)+".c");
			AddExit("sur",FLENHAB+"pantano/pantano_0"+random(10)+".c");
			AddExit("sudeste",FLENHAB+"pantano/pantano_0"+random(10)+".c");
			AddExit("suroeste",FLENHAB+"pantano/pantano_0"+random(10)+".c");
			AddExit("este",FLENHAB+"pantano/pantano_0"+random(10)+".c");
			AddExit("oeste",FLENHAB+"pantano/pantano_0"+random(10)+".c");
			switch(num)
			{
				case 0:	AddExit("norte",FLENHAB+"pantano/arenas_0"+random(10)+".c");	break;
				case 1:	AddExit("nordeste",FLENHAB+"pantano/arenas_0"+random(10)+".c");	break;
				case 2:	AddExit("noroeste",FLENHAB+"pantano/arenas_0"+random(10)+".c");	break;
				case 3:	AddExit("sur",FLENHAB+"pantano/arenas_0"+random(10)+".c");	break;
				case 4:	AddExit("sudeste",FLENHAB+"pantano/arenas_0"+random(10)+".c");	break;
				case 5:	AddExit("suroeste",FLENHAB+"pantano/arenas_0"+random(10)+".c");	break;
				case 6:	AddExit("este",FLENHAB+"pantano/arenas_0"+random(10)+".c");	break;
				case 7:	AddExit("oeste",FLENHAB+"pantano/arenas_0"+random(10)+".c");	break;
			}
			break;
		default:	AddExit("norte",FLENHAB+"pantano/pantano_0"+random(10)+".c");
				AddExit("nordeste",FLENHAB+"pantano/pantano_0"+random(10)+".c");
				AddExit("noroeste",FLENHAB+"pantano/pantano_0"+random(10)+".c");
				AddExit("sur",FLENHAB+"pantano/pantano_0"+random(10)+".c");
				AddExit("sudeste",FLENHAB+"pantano/pantano_0"+random(10)+".c");
				AddExit("suroeste",FLENHAB+"pantano/pantano_0"+random(10)+".c");
				AddExit("este",FLENHAB+"pantano/pantano_0"+random(10)+".c");
				AddExit("oeste",FLENHAB+"pantano/pantano_0"+random(10)+".c");
			break;
	}
}

int forientarse(object player)
{
	if (!player) player=TP;
	if(present("anillo azúl",TP))
	{
		string templo,arenas,salida;
		mapping salidas;
		salidas=TO->QueryExits();
		if (member(salidas,"norte"))
		{
			if (salidas["norte",0]==FLENHAB+"pantano/lago")		salida="norte";
			if (salidas["norte",0]==FLENHAB+"pantano/arenas_00")		arenas="norte";
			if (salidas["norte",0]==FLENHAB+"pantano/arenas_01")		arenas="norte";
			if (salidas["norte",0]==FLENHAB+"pantano/arenas_02")		arenas="norte";
			if (salidas["norte",0]==FLENHAB+"pantano/arenas_03")		arenas="norte";
			if (salidas["norte",0]==FLENHAB+"pantano/arenas_04")		arenas="norte";
			if (salidas["norte",0]==FLENHAB+"pantano/arenas_05")		arenas="norte";
			if (salidas["norte",0]==FLENHAB+"pantano/arenas_06")		arenas="norte";
			if (salidas["norte",0]==FLENHAB+"pantano/arenas_07")		arenas="norte";
			if (salidas["norte",0]==FLENHAB+"pantano/arenas_08")		arenas="norte";
			if (salidas["norte",0]==FLENHAB+"pantano/arenas_09")		arenas="norte";
			if (salidas["norte",0]==FLENHAB+"pantano/templo_00")		templo="norte";
		}
		if (member(salidas,"sur"))
		{
			if (salidas["sur",0]==FLENHAB+"pantano/lago")			salida="sur";
			if (salidas["sur",0]==FLENHAB+"pantano/arenas_00")		arenas="sur";
			if (salidas["sur",0]==FLENHAB+"pantano/arenas_01")		arenas="sur";
			if (salidas["sur",0]==FLENHAB+"pantano/arenas_02")		arenas="sur";
			if (salidas["sur",0]==FLENHAB+"pantano/arenas_03")		arenas="sur";
			if (salidas["sur",0]==FLENHAB+"pantano/arenas_04")		arenas="sur";
			if (salidas["sur",0]==FLENHAB+"pantano/arenas_05")		arenas="sur";
			if (salidas["sur",0]==FLENHAB+"pantano/arenas_06")		arenas="sur";
			if (salidas["sur",0]==FLENHAB+"pantano/arenas_07")		arenas="sur";
			if (salidas["sur",0]==FLENHAB+"pantano/arenas_08")		arenas="sur";
			if (salidas["sur",0]==FLENHAB+"pantano/arenas_09")		arenas="sur";
			if (salidas["sur",0]==FLENHAB+"pantano/templo_00")		templo="sur";
		}
		if (member(salidas,"este"))
		{
			if (salidas["este",0]==FLENHAB+"pantano/lago")		salida="este";
			if (salidas["este",0]==FLENHAB+"pantano/arenas_00")		arenas="este";
			if (salidas["este",0]==FLENHAB+"pantano/arenas_01")		arenas="este";
			if (salidas["este",0]==FLENHAB+"pantano/arenas_02")		arenas="este";
			if (salidas["este",0]==FLENHAB+"pantano/arenas_03")		arenas="este";
			if (salidas["este",0]==FLENHAB+"pantano/arenas_04")		arenas="este";
			if (salidas["este",0]==FLENHAB+"pantano/arenas_05")		arenas="este";
			if (salidas["este",0]==FLENHAB+"pantano/arenas_06")		arenas="este";
			if (salidas["este",0]==FLENHAB+"pantano/arenas_07")		arenas="este";
			if (salidas["este",0]==FLENHAB+"pantano/arenas_08")		arenas="este";
			if (salidas["este",0]==FLENHAB+"pantano/arenas_09")		arenas="este";
			if (salidas["este",0]==FLENHAB+"pantano/templo_00")		templo="este";
		}
		if (member(salidas,"oeste"))
		{
			if (salidas["oeste",0]==FLENHAB+"pantano/lago")		salida="oeste";
			if (salidas["oeste",0]==FLENHAB+"pantano/arenas_00")		arenas="oeste";
			if (salidas["oeste",0]==FLENHAB+"pantano/arenas_01")		arenas="oeste";
			if (salidas["oeste",0]==FLENHAB+"pantano/arenas_02")		arenas="oeste";
			if (salidas["oeste",0]==FLENHAB+"pantano/arenas_03")		arenas="oeste";
			if (salidas["oeste",0]==FLENHAB+"pantano/arenas_04")		arenas="oeste";
			if (salidas["oeste",0]==FLENHAB+"pantano/arenas_05")		arenas="oeste";
			if (salidas["oeste",0]==FLENHAB+"pantano/arenas_06")		arenas="oeste";
			if (salidas["oeste",0]==FLENHAB+"pantano/arenas_07")		arenas="oeste";
			if (salidas["oeste",0]==FLENHAB+"pantano/arenas_08")		arenas="oeste";
			if (salidas["oeste",0]==FLENHAB+"pantano/arenas_09")		arenas="oeste";
			if (salidas["oeste",0]==FLENHAB+"pantano/templo_00")		templo="oeste";
		}
		if (member(salidas,"nordeste"))
		{
			if (salidas["nordeste",0]==FLENHAB+"pantano/lago")		salida="nordeste";
			if (salidas["nordeste",0]==FLENHAB+"pantano/arenas_00")	arenas="nordeste";
			if (salidas["nordeste",0]==FLENHAB+"pantano/arenas_01")	arenas="nordeste";
			if (salidas["nordeste",0]==FLENHAB+"pantano/arenas_02")	arenas="nordeste";
			if (salidas["nordeste",0]==FLENHAB+"pantano/arenas_03")	arenas="nordeste";
			if (salidas["nordeste",0]==FLENHAB+"pantano/arenas_04")	arenas="nordeste";
			if (salidas["nordeste",0]==FLENHAB+"pantano/arenas_05")	arenas="nordeste";
			if (salidas["nordeste",0]==FLENHAB+"pantano/arenas_06")	arenas="nordeste";
			if (salidas["nordeste",0]==FLENHAB+"pantano/arenas_07")	arenas="nordeste";
			if (salidas["nordeste",0]==FLENHAB+"pantano/arenas_08")	arenas="nordeste";
			if (salidas["nordeste",0]==FLENHAB+"pantano/arenas_09")	arenas="nordeste";
			if (salidas["nordeste",0]==FLENHAB+"pantano/templo_00")	templo="nordeste";
		}
		if (member(salidas,"noroeste"))
		{
			if (salidas["noroeste",0]==FLENHAB+"pantano/lago")		salida="noroeste";
			if (salidas["noroeste",0]==FLENHAB+"pantano/arenas_00")	arenas="noroeste";
			if (salidas["noroeste",0]==FLENHAB+"pantano/arenas_01")	arenas="noroeste";
			if (salidas["noroeste",0]==FLENHAB+"pantano/arenas_02")	arenas="noroeste";
			if (salidas["noroeste",0]==FLENHAB+"pantano/arenas_03")	arenas="noroeste";
			if (salidas["noroeste",0]==FLENHAB+"pantano/arenas_04")	arenas="noroeste";
			if (salidas["noroeste",0]==FLENHAB+"pantano/arenas_05")	arenas="noroeste";
			if (salidas["noroeste",0]==FLENHAB+"pantano/arenas_06")	arenas="noroeste";
			if (salidas["noroeste",0]==FLENHAB+"pantano/arenas_07")	arenas="noroeste";
			if (salidas["noroeste",0]==FLENHAB+"pantano/arenas_08")	arenas="noroeste";
			if (salidas["noroeste",0]==FLENHAB+"pantano/arenas_09")	arenas="noroeste";
			if (salidas["noroeste",0]==FLENHAB+"pantano/templo_00")	templo="noroeste";
		}
		if (member(salidas,"sudeste"))
		{
			if (salidas["sudeste",0]==FLENHAB+"pantano/lago")		salida="sudeste";
			if (salidas["sudeste",0]==FLENHAB+"pantano/arenas_00")	arenas="sudeste";
			if (salidas["sudeste",0]==FLENHAB+"pantano/arenas_01")	arenas="sudeste";
			if (salidas["sudeste",0]==FLENHAB+"pantano/arenas_02")	arenas="sudeste";
			if (salidas["sudeste",0]==FLENHAB+"pantano/arenas_03")	arenas="sudeste";
			if (salidas["sudeste",0]==FLENHAB+"pantano/arenas_04")	arenas="sudeste";
			if (salidas["sudeste",0]==FLENHAB+"pantano/arenas_05")	arenas="sudeste";
			if (salidas["sudeste",0]==FLENHAB+"pantano/arenas_06")	arenas="sudeste";
			if (salidas["sudeste",0]==FLENHAB+"pantano/arenas_07")	arenas="sudeste";
			if (salidas["sudeste",0]==FLENHAB+"pantano/arenas_08")	arenas="sudeste";
			if (salidas["sudeste",0]==FLENHAB+"pantano/arenas_09")	arenas="sudeste";
			if (salidas["sudeste",0]==FLENHAB+"pantano/templo_00")	templo="sudeste";
		}
		if (member(salidas,"suroeste"))
		{
			if (salidas["suroeste",0]==FLENHAB+"pantano/lago")		salida="suroeste";
			if (salidas["suroeste",0]==FLENHAB+"pantano/arenas_00")	arenas="suroeste";
			if (salidas["suroeste",0]==FLENHAB+"pantano/arenas_01")	arenas="suroeste";
			if (salidas["suroeste",0]==FLENHAB+"pantano/arenas_02")	arenas="suroeste";
			if (salidas["suroeste",0]==FLENHAB+"pantano/arenas_03")	arenas="suroeste";
			if (salidas["suroeste",0]==FLENHAB+"pantano/arenas_04")	arenas="suroeste";
			if (salidas["suroeste",0]==FLENHAB+"pantano/arenas_05")	arenas="suroeste";
			if (salidas["suroeste",0]==FLENHAB+"pantano/arenas_06")	arenas="suroeste";
			if (salidas["suroeste",0]==FLENHAB+"pantano/arenas_07")	arenas="suroeste";
			if (salidas["suroeste",0]==FLENHAB+"pantano/arenas_08")	arenas="suroeste";
			if (salidas["suroeste",0]==FLENHAB+"pantano/arenas_09")	arenas="suroeste";
			if (salidas["suroeste",0]==FLENHAB+"pantano/templo_00")	templo="suroeste";
		}
		if (salida)
			tell_object(player,"El anillo azúl se ilumina un instante y una enigmática voz "
			"te indica que la salida del pantano está al "+salida+".\n");
		if (arenas)
			tell_object(player,"El anillo azúl se ilumina un instante y una enigmática voz "
			"te advierte que hay arenas movedizas al "+arenas+".\n");
		if (templo)
			tell_object(player,"El anillo azúl se ilumina un instante y una enigmática voz "
			"te indica que hay algún tipo de edificación al "+templo+".\n");
		if(!salida && !arenas && !templo)
		{
			notify_fail("El anillo no te dice nada.\n");
			return 0;
		}
		salida=0;
		arenas=0;
		templo=0;
		return 1;
	}
	else
	{
		notify_fail("No puedes orientarte sol"+AO+". Quizás necesitarías algo "
		"que te ayudara.\n");
		return 0;
	}
}

public void notify_enter(mixed from,int method,mixed extra)
{
	fsalidas();
	return (::notify_enter(from,method,extra));
}
