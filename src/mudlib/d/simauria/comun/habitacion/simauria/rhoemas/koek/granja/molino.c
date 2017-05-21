/***************************************************************************************
 ARCHIVO:	molino.c
 AUTOR:		[z] Zomax
 FECHA:		24-12-2001	¡Feliz Nochebuena!
 COMENTARIOS:	El molino de Koek
 ***************************************************************************************/

#include "path.h"

inherit SIM_ROOM;
#include RHOEPRESO

create () {
  ::create();

  SetIndoors(1);
  SetIntBright(50);
  SetLocate("Koek");
  SetIntShort("el molino");
  SetIntSmell("No hueles nada especial.\n");
  SetIntLong(W("Este es el molino. Aquí el agua del río que discurre al oeste acciona "
  	"unos mecanismos que hacen girar una gran piedra que muele el grano. En una de "
  	"las esquinas hay unos cuantos sacos, con los que se recoge el grano molido. Parece "
  	"que este molino es de uso exclusivo para los habitantes de Koek.\n"));
  AddDetail(({"piedra","gran piedra"}),W("Es una gran piedra lisa que gira gracias al "
  	"la rueda movida por el agua. Sirve para moler el grano.\n"));
  AddDetail(({"rueda"}),W("Desde aquí no puedes verla, pero supones que está medio sumergida "
  	"en el río, para que la haga girar.\n"));
  AddDetail(({"esquina"}),"En la esquina hay varios sacos viejos.\n");
  AddDetail(({"saco","sacos"}),"Hay unos cuantos sacos viejos y rotos en una esquina.\n");
  carcel=(RHOEHAB("koek/calles/folker_00"));
  AddExit("este",RHOEHAB("koek/calles/folker_00"));
  AddRoomCmd("matar","fmatar");
  AddRoomCmd("robar","frobar");
  AddRoomCmd("confesar","fconfesar");
  AddRoomCmd("entregarse","fentregarse");
  AddRoomCmd("moler","fmoler");
  AddRoomCmd("coger","fcoger");
}

init(){
  ::init();
  if (CHRONOS->QueryEstacion()==1)
  	SetIntNoise("Parece que la rueda no gira, el río debe estar congelado.\n");
  else SetIntNoise("Oyes el ruido del agua que mueve el molino.\n");
}

int fcoger(string str)
{
	if (str=="saco" || str=="sacos")
	{
		write(W("Piensas en coger un saco, pero ves que están todos rotos y "
			"desistes.\n"));
		return 1;
	}
return 0;
}

int fmoler(string str)
{
	write(W("No puedes accionar el mecanismo, es de uso exclusivo para los habitantes "
		"de Koek, y sólo ellos saben activarlo.\n"));
	return 1;
}

int QueryEntrarPatrullero()
{
	return 1;
}
