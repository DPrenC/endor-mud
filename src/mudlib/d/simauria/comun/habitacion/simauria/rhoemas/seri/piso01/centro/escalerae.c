/***************************************************************************************
 ARCHIVO:	altare.c
 AUTOR:		[z] Zomax
 FECHA:		13-01-2002
 COMENTARIOS:	Escalera este
 ***************************************************************************************/

#include "path.h"

inherit SIM_ROOM;

create () {
  ::create();

  SetIndoors(1);
  SetIntBright(60);
  SetLocate("Seri-Solderteg, primer piso");
  SetIntShort("una escalera");
  SetIntSmell("Huele a incienso y otras hierbas que se queman en ofrendas por todo el templo.\n");
  SetIntNoise("Hay un silencio absoluto.\n");
  SetIntLong(W("Est�s en una bonita pero algo descuidada escalera de piedra gris en forma "
  	"de espiral que conecta los pisos de arriba y abajo. Tiene una min�scula barandilla "
  	"tambi�n de piedra algo descascarillada por que la puedes sujetarte, pero que no te "
  	"da gran confianza.\n"));
  
  AddDetail(({"escalera"}),W("La escalera es de piedra gris. Est� algo descuidada, que "
  	"sumado a su retorcido recorrido la hace muy poco atractiva a la vista del que "
  	"tenga que subir por ella.\n"));
  AddDetail(({"barandilla"}),W("Por si fuera poco alentador subir por aqu� parece que "
  	"la barandilla est� algo cuarteada por algunos trozos.\n"));
  AddExit("sur",RHOEHAB("seri/piso01/este/pasillo_00")); 
  AddExit("arriba",RHOEHAB("seri/piso02/centro/escalerae"));
  AddExit("abajo",RHOEHAB("seri/piso00/centro/escalerae"));
}
