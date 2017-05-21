/*****************************************************************************
 AUTOR:		[t] Tyflos
 DETALLES:	Poblado Enanel
 *****************************************************************************/

#include "path.h"
#include <moving.h>

inherit SIM_ROOM;

public int IrCocina();

create() {
  ::create();

  SetIndoors(1);
  SetIntBright(10);
  SetLocate("Casa Fhainfos");
  SetIntShort("la despensa");
  SetIntLong(W("Estás en la enorme despensa de la casa de los Fhainfos. Multitud "
  "de barriles y cajas parecen contener diversos alimentos. Al norte está la "
  "puerta de salida.\n"));
  SetIntNoise("No escuchas nada fuera de lo normal.\n");
  SetIntSmell("Un leve aroma a manzanas se percibe por todas partes.\n");
  AddExit("norte",SF(IrCocina));
}

public int IrCocina(){
    object cocina=find_object(ENALHAB"poblado/casas/fhainfos/cocina");
    if(cocina->QueryDespensa()==1){
        TP->move(ENALHAB"poblado/casas/fhainfos/cocina",M_SPECIAL,
        ({" sale a la cocina",
	    " sale de la despensa",
	    "Sales a la cocina"}));
	    return 1;
	}else{
	    write("Intentas salir a la cocina, pero la puerta está cerrada y no puedes "
	    "abrirla.\n");
	    say(CAP(TNAME)+ " intenta salir de la despensa pero no puede porque la puerta "
	    "está cerrada.\n");
	    return 1;
	}
}
