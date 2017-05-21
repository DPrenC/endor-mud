/*****************************************************************************
 AUTOR:		[k] Kintups
 DETALLES:	Cavernas del Caos
            [Nyh] Muy modificado.
                  Creo la habitaci�n base, corrijo mogoll�n de typos y m�s
*****************************************************************************/

#include "path.h"

inherit CAOSHAB "_caos_base_room";

public create() {
  ::create();

  SetIntShort("un t�nel subacu�tico");
  SetIntLong("Est�s en un t�nel subacu�tico, el agua est� en calma pero muy "
    "fr�a.\n");
  SetIntSmell("�Es que pretendes ahogarte?\n");
  AddExit("noroeste",CAOSHAB"tunel_sub_03");
  AddExit("sudeste",CAOSHAB"tunel_sub_05");
  SetLocate("Pasaje Acuatico");
}
