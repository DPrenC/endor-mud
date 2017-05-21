/*****************************************************************************
 AUTOR:		[k] Kintups
 DETALLES:	Cavernas del Caos
            [Nyh] Muy modificado.
                  Creo la habitación base, corrijo mogollón de typos y más
*****************************************************************************/

#include "path.h"

inherit CAOSHAB "_caos_base_room";

public create() {
  ::create();

  SetIntShort("un túnel subacuático");
  SetIntLong("Estás en un túnel subacuático, el agua está en calma pero muy "
    "fría.\n");
  SetIntSmell("¿Es que pretendes ahogarte?\n");
  AddExit("noroeste",CAOSHAB"tunel_sub_04");
  AddExit("arriba",CAOSHAB"estatuas_02");
  HideExit("arriba",1);
  SetLocate("Pasaje Acuatico");
}
