/*****************************************************************************
 AUTOR:		[k] Kintups
 DETALLES:	Cavernas del Caos
            [Nyh] Muy modificado.
                  Creo la habitaci�n base, corrijo mogoll�n de typos y m�s
*****************************************************************************/
#include "./path.h"

inherit CAOSHAB "_caos_base_room";

public create() {
    ::create();

    SetIntShort("el norte de los aposentos");
    SetIntLong("Est�s en la zona norte de los aposentos de alg�n tipo de "
    "criatura humanoide. Hay una pila de esteras amontonadas al este. "
    "Tambi�n hay algo de comida, harapos, huesos y todo tipo de basura "
    "por doquier.\n");
    SetIntSmell("No hueles nada destacable, salvo el mal olor que desprenden "
    "las basuras.\n");
    AddExit("oeste",CAOSHAB"apos_sur_01");
    AddExit("norte",CAOSHAB"apos_sur_02");
    AddItem(CAOSPNJ"ogro", REFRESH_DESTRUCT,2);
}
