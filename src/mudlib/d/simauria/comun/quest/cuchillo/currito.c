/*
DESCRIPCION : alba�il en la casa de Malmabet, mero informativo
FICHERO     : /d/simauria/comun/pnj/simauria/berat/malmabet.c
MODIFICACION: 2-6-00[Maler]creaci�n
--------------------------------------------------------------------------------
*/
#include "./path.h"
#include <properties.h>
inherit NPC;

create() {
    ::create();

    SetStandard("un alba�il", "humano", 12, GENDER_MALE);
    SetShort("un alba�il");
    SetLong("Es un alba�il de los de toda la vida. Tiene un aspecto "
    "totalmente desarrapado, y est� pululando por ah� haciendo "
    "que trabaja, pero sin trabajar.\n");
    AddId(({"alba�il","currito","humano"}));
    SetCitizenship("berat");
    AddQuestion(({"cuchillo","cuchillo para curtir"}),
    "El alba�il te dice: �El cuchillo de la jefa? S�, me lo encontr� tirado aqu� esta "
    "ma�ana. Para que no se perdiera, lo he metido en una caja de madera y la he cerrado."
    " Necesitar�s mi palanca para abrirla.\n");
    AddQuestion("palanca",
    "El alba�il te dice: S�, bueno, mi palanca, te la dejar�a si la tuviera, pero hace unas horas "
    "vino Thalan y me la pidi� prestada.\n"
    "Entre tu y yo, Thalan esta perdidamente enamorado de la jefa, pero no se lo digas, bastante tiene "
    "ya la pobre.\n");
    AddQuestion(({"caja de madera", "caja"}),
    "El alba�il dice: no s� de quien es la caja, ya estaba por aqu�, met� el cuchillo "
    "de la jefa para que no se perdiera.\n");
InitChats(3,({"El alba�il dice: La jefa no sabe donde tiene la cabeza, lo pierde todo\n",
    "El alba�il dice: Vaya, precisamente ahora necesito mi palanca\n",
"El alba�il dice: Hoy me he levantado sin ganas de trabajar.\n"}));
}


