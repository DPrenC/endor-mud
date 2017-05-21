/*****************************************************************************
 AUTOR:		[k] Kintups
 DETALLES:	Cavernas del Caos
            [Nyh] Muy modificado.
                  Creo la habitación base, corrijo mogollón de typos y más
*****************************************************************************/

#include "./path.h"

inherit CAOSHAB "_caos_base_room";

public create() {
    ::create();

    SetIntShort("el noreste de los aposentos");
    SetIntLong("Estás en la zona noreste de los aposentos de algun tipo de "
    "criatura humanoide. A tus pies hay una pila de esteras amontonadas. "
    "Tambien hay algo de comida, harapos, huesos y todo tipo de basura por "
    "doquier.\n");
    SetIntSmell("No hueles nada destacable, salvo el mal olor que desprenden "
    "las basuras.\n");
    AddExit("sur",CAOSHAB"apos_sur_03");
    AddExit("suroeste",CAOSHAB"apos_sur_01");
    AddItem(CAOSPNJ"heritik",REFRESH_DESTRUCT);
}
