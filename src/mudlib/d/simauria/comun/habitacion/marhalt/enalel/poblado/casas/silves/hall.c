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
  SetIntLong(W("Est�s al comienzo del puente que sirve de entrada para la casa "
  "de la noble familia Silves. La casa, situada al oeste, parece un extra�o "
  "edificio con forma de torre�n. Al este est� la calle de la empalizada.\n"));
  SetIntNoise("Los sonidos de la naturaleza inundan el lugar.\n");
  SetIntSmell("El aroma de las manzanas flota en el lugar.\n");
  AddDetail(({"edificio","torre","torreon","torre�n"}),"Es un extra�o y alto "
  "torre�n de piedra clara.\n");
  AddDetail(({"puente"}),SF(MirarPuente));
  AddExit("este",ENALHAB"poblado/calles/calle12");
  AddExit("oeste",SF(IrPuente));
  PuenteEntrada=0;
}

public string MirarPuente(){
  string cadena = "Es un robusto puente de madera. Parece ser que es levadizo.\n";
  if (PuenteEntrada) cadena += "El puente est� bajado, puedes pasar.\n";
  else	             cadena += "El puente est� levantado. No puedes pasar.\n";
  return cadena;
}

public int IrPuente(){
  if (!PuenteEntrada) write("El puente est� levantado. No puedes pasar.\n");
  return 1;
}