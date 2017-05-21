/***************************************************************************************
 ARCHIVO:	centro.c
 AUTOR:		[z] Zomax
 FECHA:		14-01-2002
 COMENTARIOS:	Centro del templo
 ***************************************************************************************/

#include "path.h"
#include <properties.h>

inherit SIM_ROOM;

create () {
  ::create();

  SetIndoors(1);
  Set(P_TPORT,0);
  SetIntBright(60);
  SetLocate("Seri-Solderteg, primer piso");
  SetIntShort("un alargado hueco");
  SetIntSmell("Huele a incienso y otras hierbas que se queman en ofrendas por todo el templo.\n");
  SetIntNoise("Hay un silencio absoluto.\n");
  SetIntLong(W("Estás en un hueco colgando de una escalera de cuerda que sube o baja. "
  	"Tú decides. Por lo demás esto es muy estrecho y empiezas a tener algo de "
  	"claustrofobia. Las paredes de roca sucias dan la sensación de aprisionarte "
  	"hasta no dejarte respirar.\n"));

  AddDetail(({"pared","paredes"}),W("Son de roca gris, están muy sucias y demasiado pegadas "
  	"a tu cuerpo para tu gusto.\n"));
  AddDetail(({"telaraña","telaranya","telarañas","telaranyas","polvo"}),W("Hay "
  	"telarañas y polvo por todas partes, señal de que hace mucho que nadie "
  	"pasaba por aquí.\n"));
  AddRoomCmd("coger","fcoger");
  AddExit("arriba",RHOEHAB("seri/piso02/centro/centro"));
  AddExit("abajo",RHOEHAB("seri/piso00/centro/centro"));
}

int fcoger(string str)
{
	if (str=="polvo")
	{
		write(W("¿Para qué quieres coger polvo?, mejor lo dejas no sea que seas "
			"alérgic"+AO+".\n"));
		return 1;
	}
	else if (str=="telaranya" || str=="telaranyas" || str=="telaraña" || str=="telarañas")
	{
		write(W("No necesitas coger eso, y puedes llevarte un disgusto si viene "
			"su dueña. Quizás sea venenosa, así que decides no cogerlo.\n"));
		return 1;
	}
	else if (str=="escalera" || str=="escalera de cuerda")
	{
		write("Claro... y como sabes volar y todo... no digas tonterías.\n");
		return 1;
	}
}