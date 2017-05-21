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
  SetLocate("Seri-Solderteg, segundo piso");
  SetIntShort("una escalera");
  SetIntSmell("Huele a incienso y otras hierbas que se queman en ofrendas por todo el templo.\n");
  SetIntNoise("Hay un silencio absoluto.\n");
  SetIntLong(W("Te encuentras en mitad de una escalera que lleva desde el �ltimo piso "
  	"del templo hasta la base, pasando por todos los dem�s. A pesar de no est�r en "
  	"muy buenas condiciones parece bastante s�lida, aunque a tu paso oyes algunos "
  	"crujidos. Ser� mejor que salgas cuanto antes, podr�as pasar algo malo.\n"));
  
  AddDetail(({"escalera"}),W("Es una escalera de caracol de piedra algo descascarillada "
  	"por muchos sitios. No inspira mucha confianza, pero es lo que hay.\n"));
  AddExit("sur",RHOEHAB("seri/piso02/este/pasillo_00")); 
  AddExit("arriba",RHOEHAB("seri/piso03/escalerae"));
  AddExit("abajo",RHOEHAB("seri/piso01/centro/escalerae"));
}
