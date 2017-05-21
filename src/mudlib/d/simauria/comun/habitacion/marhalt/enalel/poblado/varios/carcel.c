/*

    Nombre      : carcelEnalel
    Zona        : Poblado de Enalel
    Autor       : Tyflos
    Fecha       : 17/01/2005
    Descripción : Habitación principal de la carcel de Enalel

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
  SetIntShort("la cárcel");
  SetIntLong(W("Estás en una lúgubre habitación de paredes húmedas que comunica las "
  "distintas celdas Con la sala de guardia. La escalera asciende saliendo de este "
  "lúgrube lugar.\n"));
  SetIntNoise("No escuchas nada fuera de lo normal.\n");
  SetIntSmell("El olor a humedad y sudor inunda el lugar.\n");
  AddDetail(({"celda","celdas"}),"son unas pequeñas celdas donde los que cometen "
  "algún delito son encarcelados.\n");
  AddExit("arriba",ENALHAB"poblado/varios/sala_guardia");
  AddExit("norte",SF(IrCelda));
  AddExit("sur",SF(IrCelda));
  AddExit("este",SF(IrCelda));
  AddExit("oeste",SF(IrCelda));
  AddRoomCmd("abrir","AbrirCelda");
}

int IrCelda(){
  write("La puerta está cerrada.\n");
  return 1;
}

int AbrirCelda(string str){
  if (!str) return notify_fail("¿Qué quieres abrir?\n"),0;
  str = lower_case(str);

  if (str=="puerta" || str=="celda" || str=="celdas"){
  	write("Todas las celdas están cerradas con llave.\n");
        return 1;
  }
}