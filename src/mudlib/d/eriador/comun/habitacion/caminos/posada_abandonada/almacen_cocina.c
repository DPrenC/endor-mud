/*****************************************************************************
 AUTOR:		Orome
 DETALLES:	posada vieja
 *****************************************************************************/

#include "./path.h"
#include <moving.h>

inherit ROOM;

public int IrCocina();

create() {
  ::create();

  SetIndoors(1);
  SetIntBright(0);
  SetLocate("Una posada abandonada");
  SetIntShort("la despensa");
  SetIntLong(W("Est�s en la enorme despensa de la casa de los Fhainfos. Multitud "
  "de barriles y cajas parecen contener diversos alimentos. Al norte est� la "
  "puerta de salida.\n"));
  SetIntNoise("No escuchas nada fuera de lo normal.\n");
  SetIntSmell("Un leve aroma a manzanas se percibe por todas partes.\n");
  AddExit("norte",SF(IrCocina));
}

public int IrCocina(){
    object cocina=find_object(CAMINOS"posada_abandonada/cocina");
    if(cocina->QueryDespensa()==1){
        TP->move(CAMINOS"posada_abandonada/cocina",M_SPECIAL,
        ({" sale a la cocina",
	    " sale de la despensa",
	    "Sales a la cocina"}));
	    return 1;
	}else{
	    write("Intentas salir a la cocina, pero la puerta est� cerrada y no puedes "
	    "abrirla.\n");
	    say(CAP(TNAME)+ " intenta salir de la despensa pero no puede porque la puerta "
	    "est� cerrada.\n");
	    return 1;
	}
}
