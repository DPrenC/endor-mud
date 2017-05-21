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

    SetIntShort("los aposentos");
    SetIntLong("Estás en los aposentos de algún tipo de criatura humanoide. Hay "
    "una pila de esteras amontonadas en la parte nordeste de la sala. También "
    "hay algo de comida, harapos, huesos y todo tipo de basura por doquier.\n");
    SetIntSmell("No hueles nada destacable, salvo el mal olor que desprenden "
        "las basuras.\n");
    AddDetail(({"comida","harapos","huesos","basura"}),
    "No son más que los deshechos de los habitantes de las cavernas.\n");
    AddExit("suroeste",CAOSHAB"apos_sur_00");
    AddExit("este",CAOSHAB"apos_sur_03");
    AddExit("nordeste",CAOSHAB"apos_sur_02");

    AddItem(CAOSPNJ"menie",REFRESH_DESTRUCT);
    AddItem(CAOSPNJ"sesi",REFRESH_DESTRUCT);
}
