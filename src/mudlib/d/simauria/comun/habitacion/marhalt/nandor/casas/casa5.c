/**************************************************************************/
/*                                                                        */
/*  [k] Kintups                                                           */
/*  [a] Articman                                                          */
/*  [k] Mon 13 Nov 2000 --- Revisados los textos y añadidos los W()       */
/*  [a] 3/5/2002            Castellanización y retoques                   */
/**************************************************************************/

#include "./path.h"

inherit SIM_ROOM;
create () {
    ::create();
    SetLocate("Aldea de Nandor");
    SetIntShort("una cabaña");
    SetIntLong("Nada más entrar en esta cabaña, te sorprende un hedor a enfermedad y "
    "agonía que te hace arrugar la nariz. Esta parece ser la casa de un "
    "moribundo, que pasa, solo y desamparado, sus últimas horas de vida. "
    "Quizá deberías alejarte y dejar al pobre viejo en paz.\n");
    SetIntBright(30);
    AddItem(PNJ("marhalt/moribun"),REFRESH_DESTRUCT,1);
    AddExit("oeste","../calle5");
    AddDoor("oeste");
}