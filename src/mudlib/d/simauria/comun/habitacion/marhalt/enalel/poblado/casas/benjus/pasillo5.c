/*****************************************************************************
 AUTOR:		[t] Tyflos
 DETALLES:	Poblado Enanel
 *****************************************************************************/

#include "path.h"

inherit SIM_ROOM;

int puerta;
public string MirarPuerta();
public int IrAlmacen();

create() {
  ::create();

  SetIndoors(1);
  SetIntBright(50);
  SetLocate("Casa Benjus");
  SetIntShort("el pasillo");
  SetIntLong(W("Estás al final de un pasillo de paredes de madera. Una enorme "
  "puerta de metal forjado se encuentra hacia el oeste. El pasillo continúa "
  "hacia el norte.\n"));
  SetIntNoise("No escuchas nada fuera de lo normal.\n");
  SetIntSmell("Un leve aroma a manzanas se percibe por todas partes.\n");
  AddDetail(({"pared","paredes","pared de madera","paredes de madera"}),W("Las "
  "paredes de madera crean un ambiente confortable en este largo pasillo.\n"));
  AddDetail(({"puerta","enorme puerta"}),SF(MirarPuerta));

  AddExit("oeste",SF(IrAlmacen));
  AddExit("norte",ENALHAB"poblado/casas/benjus/pasillo4");
  puerta = 0;
}

public string MirarPuerta(){
  string cadena = "Es una enorme puerta de metal forjado.\nDebe proteger los "
  		  "secretos más preciados de la familia.\n";

  if (puerta) cadena += "La puerta está abierta.\n";
  else cadena += "La puerta está cerrada.\n";
  return cadena;
}

public int IrAlmacen(){
  if (!puerta) write("La puerta está cerrada.\n");
  return 1;
}
