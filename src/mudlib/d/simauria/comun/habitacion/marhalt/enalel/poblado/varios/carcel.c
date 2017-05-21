/*

    Nombre      : carcelEnalel
    Zona        : Poblado de Enalel
    Autor       : Tyflos
    Fecha       : 17/01/2005
    Descripci�n : Habitaci�n principal de la carcel de Enalel

*/

#include "path.h"

inherit SIM_ROOM;

int IrCelda();
int AbrirCelda(string str);

create() {
  ::create();

  SetIndoors(1);
  SetIntBright(20);
  SetLocate("Poblado de Enalel");
  SetIntShort("la c�rcel");
  SetIntLong(W("Est�s en una l�gubre habitaci�n de paredes h�medas que comunica las "
  "distintas celdas Con la sala de guardia. La escalera asciende saliendo de este "
  "l�grube lugar.\n"));
  SetIntNoise("No escuchas nada fuera de lo normal.\n");
  SetIntSmell("El olor a humedad y sudor inunda el lugar.\n");
  AddDetail(({"celda","celdas"}),"son unas peque�as celdas donde los que cometen "
  "alg�n delito son encarcelados.\n");
  AddExit("arriba",ENALHAB"poblado/varios/sala_guardia");
  AddExit("norte",SF(IrCelda));
  AddExit("sur",SF(IrCelda));
  AddExit("este",SF(IrCelda));
  AddExit("oeste",SF(IrCelda));
  AddRoomCmd("abrir","AbrirCelda");
}

int IrCelda(){
  write("La puerta est� cerrada.\n");
  return 1;
}

int AbrirCelda(string str){
  if (!str) return notify_fail("�Qu� quieres abrir?\n"),0;
  str = lower_case(str);

  if (str=="puerta" || str=="celda" || str=="celdas"){
  	write("Todas las celdas est�n cerradas con llave.\n");
        return 1;
  }
}