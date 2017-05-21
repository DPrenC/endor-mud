/***************************************************************************************
 ARCHIVO:	pocion.c
 AUTOR:		[k] Korsario
 FECHA:		10-02-1999
 COMENTARIOS:	Una poci�n
 ***************************************************************************************/

#include "path.h"
#include <properties.h>

inherit THING;

create(){
  ::create();
  Set(P_GENDER,GENERO_FEMENINO);
  Set(P_NUMBER,NUMERO_SINGULAR);
  SetIds(({"pocion","poci�n","poci�n shaman"}));
  SetValue(10);
  SetWeight(10);

  SetShort("una poci�n de colorines");
  SetLong("Ves un frasco de cristal que contiene un l�quido que cambia de "
  	"color a cada instante. Es muy bonito. No tiene ninguna inscripci�n "
  	"y es de cristal.\n");
}

init(){
  ::init();

  add_action("fbeber","beber");
}

int fbeber(string str)
{
	if(str=="pocion" || str=="poci�n" || str=="pocion de colorines")
	{
		write("No consigues abrir el frasco de la poci�n.\n");
		return 1;
	}
	else
	{
		notify_fail("�Beber <qu�>?\n");
		return 0;
	}
}
