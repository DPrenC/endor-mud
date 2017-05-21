/*=============================================================*
 |                  << Atun cheto@simauria >>                  |
 *=============================================================*
 |               Ultima Modificacion.. 16-11-98                |
 |             adaptacion de la naranja de limbo               |
 |     Nemesis: Puesto size y weight a 0 pa que pueda ello     |
 *=============================================================*/

#include <properties.h>

inherit FOOD;

create() {
    ::create();
    SetFoodKind("food");
    SetFoodMsgs("Te comes un atun crudo\n");
    SetFoodStuff(10);
    SetFoodHeal(10);
    SetShort("un atún");
    SetLong("Es un atún, un sabroso pescado.\n");
    AddId(({"pescado", "atun", "comida", "qatun", "atún"}));
    SetSize(P_SIZE_SMALL);
    SetWeight(500);
    Set(P_NOSELL,1); //poke es necerario p'al quest
    Set(P_CANT_STEAL,1);
    SetNoDrop(1);
    Set(P_NOSELL,1);
}
