/***************************************************************************************
 ARCHIVO:	carcelero.c
 AUTOR:		[z] Zomax
 FECHA:		01-12-2001
 COMENTARIOS:	El carcelero de Koek.
 MODIFICACION:  17-04-2003 A�ado AddQuestion para el quest de Draego.
                20-04-2003 Ahora las respuestas solo se las da al player que pregunta.
 ***************************************************************************************/

#include "path.h"
#include <gremios.h>
#include <properties.h>

inherit NPC;

create(){
  ::create();
  SetStandard("el carcelero","humano",40,GENERO_MASCULINO,GC_LUCHADOR);
  SetWhimpy(0);
  SetAlign(250);
  SetAggressive(0);
  SetIds(({"carcelero","humano"}));
  SetShort("el carcelero");
  SetLong(W("Es el carcelero, el que cuida de que los presos no escapen mientras "
  	"cumplen condena.\n"));
  AddQuestion(({"preso","presos","presa","presas"}),W("El carcelero te dice: Pues ahora mismo "
  	"de los comunes tengo en el calabozo 2 a Syrnam, que se pas� mucho con la botella "
  	"la �ltima vez y mejor que pase aqu� la noche. En el de al lado tengo a los tres "
  	"'magn�ficos'. Parece mentira que su maestro fuera el mejor ladr�n de la zona, "
  	"nunca pude atraparle con las manos en la masa, sin embargo estos cuatro son la cosa "
  	"m�s patosa que existe. En fin, m�s trabajo para mi.\n"),1);

  InitChats(8,({"El carcelero dice: Si has hecho algo malo deber�as confesar cuanto antes.\n",
  		 "El carcelero dice: Um... se me est�n escapando muchos presos.\n",
		 "El carcelero se echa una siestecilla.\n",
		 "El carcelero lee el registro de entrada.\n"}));
  InitAChats(10,"[52m�Hombre mira!, �Un voluntario para probar nuestra c�rcel!.[0m\n");
}
