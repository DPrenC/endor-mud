#include <properties.h>
#include <combat.h>
inherit ARMOUR;
create()
{
    ::create();
    SetStandard(AT_CORAZA, 5, P_SIZE_LARGE, M_HIERRO);
    SetShort("una cota de malla");
    SetLong("Ésta cota de malla es una holgada camisola hecha de pequeños anillos de "
    "hierro entrelazados entre sí, que cubre el cuerpo hasta las rodillas, y  la parte "
    "superior de los brazos hasta aproximadamente el codo con unas mangas amplias que "
    "facilitan los movimientos. Normalmente se cierra y ajusta al cuerpo con un cinturón "
    "de cuero de donde se cuelgan las armas. Algunas de las anillas están ligeramente "
    "oxidadas, mal ajustadas o dejan huecos excesivamente amplios por los cuales podría "
    "deslizarse un arma penetrante, por lo que se deduce que no es una armadura de gran "
    "calidad.\n "
    "Ésta cota en particular va cubierta por un burdo tabardo de tela vasta en el que "
    "aparece bordada una flor de Lis,  el símbolo heráldico del señor de Nandor.\n");
    AddId(({"cota de malla", "cota", "malla", "mallas", "armadura"}));
    Set(P_GENDER, GENDER_FEMALE);
    SetWeight(8850);
    SetQuality(95);

}
