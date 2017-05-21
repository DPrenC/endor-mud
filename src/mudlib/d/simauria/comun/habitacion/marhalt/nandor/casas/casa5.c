/**************************************************************************/
/*                                                                        */
/*  [k] Kintups                                                           */
/*  [a] Articman                                                          */
/*  [k] Mon 13 Nov 2000 --- Revisados los textos y a�adidos los W()       */
/*  [a] 3/5/2002            Castellanizaci�n y retoques                   */
/**************************************************************************/

#include "./path.h"

inherit SIM_ROOM;
create () {
    ::create();
    SetLocate("Aldea de Nandor");
    SetIntShort("una caba�a");
    SetIntLong("Nada m�s entrar en esta caba�a, te sorprende un hedor a enfermedad y "
    "agon�a que te hace arrugar la nariz. Esta parece ser la casa de un "
    "moribundo, que pasa, solo y desamparado, sus �ltimas horas de vida. "
    "Quiz� deber�as alejarte y dejar al pobre viejo en paz.\n");
    SetIntBright(30);
    AddItem(PNJ("marhalt/moribun"),REFRESH_DESTRUCT,1);
    AddExit("oeste","../calle5");
    AddDoor("oeste");
}