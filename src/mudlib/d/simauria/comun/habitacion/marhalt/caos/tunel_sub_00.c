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
  AddExit("arriba",CAOSHAB"lago_03");
  HideExit("arriba",1);
  AddExit("este",CAOSHAB"tunel_sub_01");
  SetLocate("Pasaje Acuatico");
}
