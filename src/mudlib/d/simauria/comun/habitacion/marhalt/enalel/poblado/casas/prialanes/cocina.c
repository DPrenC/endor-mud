/*****************************************************************************
 AUTOR:		[t] Tyflos
 DETALLES:	Poblado Enanel
 *****************************************************************************/

#include "./path.h"

inherit SIM_ROOM;

int puerta;
public int IrLaboratorio();
public string MirarPuerta();

create() {
    ::create();

    SetIntBright(30);
    SetLocate("Casa Prialanes");
    SetIntShort("la cocina");
    SetIntLong("Estás en la cocina de la familia Prialane. Multitud de cacharros "
    "y utensilios de cocina están por todas partes en perfecto orden. Al este se "
    "encuentra el salón de la casa y hacia el sur una puerta comunica con el "
    "laboratorio de la casa.\n");
    SetIntSmell("Un leve aroma a manzanas se percibe por todas partes.\n");
    AddDetail(({"cacharro","cacharros","utensilio","utensilios"}),"Son diversos "
    "cacharros de cocina, todos colocados en perfecto orden.\n");
    AddDetail(({"puerta del laboratorio","puerta"}),SF(MirarPuerta));

    AddExit("este",ENALHAB"poblado/casas/prialanes/salon");
    AddExit("sur",SF(IrLaboratorio));
    puerta = 0;
    AddDoor("este", "la puerta del salón",
    "La puerta para salir de la cocina.\n",
    ({"puerta", "puerta del salón", "puerta del salon", "puerta del este"}));
}

public int IrLaboratorio(){
  if (!puerta) write("La puerta está cerrada.\n");
  return 1;
}

public string MirarPuerta(){
  string cadena = "Es una puerta de metal con cerradura.\n";

  if (!puerta) cadena += "Está cerrada.\n";
  else cadena += "Está abierta.\n";
  return cadena;
}
