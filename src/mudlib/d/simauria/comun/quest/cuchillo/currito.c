/*
DESCRIPCION : albañil en la casa de Malmabet, mero informativo
FICHERO     : /d/simauria/comun/pnj/simauria/berat/malmabet.c
MODIFICACION: 2-6-00[Maler]creación
--------------------------------------------------------------------------------
*/
#include "./path.h"
#include <properties.h>
inherit NPC;

create() {
    ::create();

    SetStandard("un albañil", "humano", 12, GENDER_MALE);
    SetShort("un albañil");
    SetLong("Es un albañil de los de toda la vida. Tiene un aspecto "
    "totalmente desarrapado, y está pululando por ahí haciendo "
    "que trabaja, pero sin trabajar.\n");
    AddId(({"albañil","currito","humano"}));
    SetCitizenship("berat");
    AddQuestion(({"cuchillo","cuchillo para curtir"}),
    "El albañil te dice: ¿El cuchillo de la jefa? Sí, me lo encontré tirado aquí esta "
    "mañana. Para que no se perdiera, lo he metido en una caja de madera y la he cerrado."
    " Necesitarás mi palanca para abrirla.\n");
    AddQuestion("palanca",
    "El albañil te dice: Sí, bueno, mi palanca, te la dejaría si la tuviera, pero hace unas horas "
    "vino Thalan y me la pidió prestada.\n"
    "Entre tu y yo, Thalan esta perdidamente enamorado de la jefa, pero no se lo digas, bastante tiene "
    "ya la pobre.\n");
    AddQuestion(({"caja de madera", "caja"}),
    "El albañil dice: no sé de quien es la caja, ya estaba por aquí, metí el cuchillo "
    "de la jefa para que no se perdiera.\n");
InitChats(3,({"El albañil dice: La jefa no sabe donde tiene la cabeza, lo pierde todo\n",
    "El albañil dice: Vaya, precisamente ahora necesito mi palanca\n",
"El albañil dice: Hoy me he levantado sin ganas de trabajar.\n"}));
}


