/*****************************************************************************
 AUTOR:		[t] Tyflos
 DETALLES:	Poblado Enanel
 *****************************************************************************/

#include "path.h"

inherit SIM_ROOM;

int PuenteEntrada;
public string MirarPuente();
public int IrPuente();

create() {
  ::create();

  SetIndoors(1);
  SetIntBright(50);
  SetLocate("Poblado de Enalel");
  SetIntShort("la entrada de la casa de la familia Silves");
  SetIntLong(W("Estás al comienzo del puente que sirve de entrada para la casa "
  "de la noble familia Silves. La casa, situada al oeste, parece un extraño "
  "edificio con forma de torreón. Al este está la calle de la empalizada.\n"));
  SetIntNoise("Los sonidos de la naturaleza inundan el lugar.\n");
  SetIntSmell("El aroma de las manzanas flota en el lugar.\n");
  AddDetail(({"edificio","torre","torreon","torreón"}),"Es un extraño y alto "
  "torreón de piedra clara.\n");
  AddDetail(({"puente"}),SF(MirarPuente));
  AddExit("este",ENALHAB"poblado/calles/calle12");
  AddExit("oeste",SF(IrPuente));
  PuenteEntrada=0;
}

public string MirarPuente(){
  string cadena = "Es un robusto puente de madera. Parece ser que es levadizo.\n";
  if (PuenteEntrada) cadena += "El puente está bajado, puedes pasar.\n";
  else	             cadena += "El puente está levantado. No puedes pasar.\n";
  return cadena;
}

public int IrPuente(){
  if (!PuenteEntrada) write("El puente está levantado. No puedes pasar.\n");
  return 1;
}