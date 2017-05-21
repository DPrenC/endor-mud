/***************************************************************************************
 ARCHIVO:	vela.c
 AUTOR:		[k] Korsario
 FECHA:		10-02-1999
 COMENTARIOS:	Una vela
 ***************************************************************************************/

#include <properties.h>

inherit THING;

int apagada;

create(){
  ::create();
  Set(P_GENDER,GENERO_FEMENINO);
  Set(P_NUMBER,NUMERO_SINGULAR);
  SetIds(({"vela"}));
  SetAds(({"blanca"}));
  SetWeight(50);
  SetValue(3);

  SetShort("una piedra verde");
  SetLong("Es una vela de cera de color blanco. Esta usada y algo "
  	"gastada. Está apagada. La han usado recientemente.\n");
}

init(){
  ::init();

  add_action("fencender","encender");
  add_action("fapagar","apagar");
}

int fencender(string str)
{
	int aux;
	if (str=="vela" && !apagada)
  	{
		write("La vela ya estaba encendida.\n");
		return 1;
     	}
    	else if (str=="vela" && apagada)
    	{
    		apagada=0;
    		write("Enciendes la vela.\n");
    		say(CATP+" enciende una vela.\n");
		aux =(TP->environment())->QueryLight();
		(TP->environment())->SetLight(aux+10);
		SetLong("Es una vela de cera de color blanco. Está "
		"encendida, te llama la atención la bonita luz azul que "
		"desprende.\n");
		return 1;
	}
}

int fapagar(string str)
{
	if (str=="vela" && apagada)
	{
		write("La vela ya estaba apagada.\n");
		return 1;
	}
	else if (str=="vela" && !apagada)
	{
		write("Apagas la vela.\n");
		say(CATP+" apaga una vela.\n");
		apagada=1;
		SetLight(1);
		SetLong("Es una vela de cera de color blanco. Está "
		"usada y algo gastada. Está apagada. La han usado "
		"recientemente.\n");
		return 1;
	}
}
