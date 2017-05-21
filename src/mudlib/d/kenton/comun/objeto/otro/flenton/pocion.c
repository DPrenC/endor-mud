/***************************************************************************************
 ARCHIVO:	pocion.c
 AUTOR:		[k] Korsario
 FECHA:		10-02-1999
 COMENTARIOS:	Una poción
 ***************************************************************************************/

#include "path.h"
#include <properties.h>

inherit THING;

create(){
  ::create();
  Set(P_GENDER,GENERO_FEMENINO);
  Set(P_NUMBER,NUMERO_SINGULAR);
  SetIds(({"pocion","poción","poción shaman"}));
  SetValue(10);
  SetWeight(10);

  SetShort("una poción de colorines");
  SetLong("Ves un frasco de cristal que contiene un líquido que cambia de "
  	"color a cada instante. Es muy bonito. No tiene ninguna inscripción "
  	"y es de cristal.\n");
}

init(){
  ::init();

  add_action("fbeber","beber");
}

int fbeber(string str)
{
	if(str=="pocion" || str=="poción" || str=="pocion de colorines")
	{
		write("No consigues abrir el frasco de la poción.\n");
		return 1;
	}
	else
	{
		notify_fail("¿Beber <qué>?\n");
		return 0;
	}
}
