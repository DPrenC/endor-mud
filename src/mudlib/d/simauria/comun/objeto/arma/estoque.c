/****************************************************************************
Fichero: estoque.c
Autor: Ratwor
Fecha: 20/04/2008
Descripci�n: un arma para asesinos
****************************************************************************/

#include <properties.h>
#include <combat.h>
inherit WEAPON;
create()
{
    ::create();
    SetStandard(WT_ESGRIMA, 7, P_SIZE_MEDIUM, M_ACERO);
    SetShort("Un estoque negro");
    SetLong("El estoque es una espada desarrollada para usarla mas de punta que de "
    "corte, desliz�ndo su hoja entre las secciones de armadura del oponente. La "
    "empu�adura posee una cazoleta oval de metal dorado muy trabajado de la que surge "
    "una estrecha hoja de acero oscuro que se va estrechando para terminar en una "
    "afilad�sima punta.\n"
    "A pesar de su aspecto aparentemente fr�gil, el m�todo de forjado usado en estas "
    "armas las hace resistentes, muy fiables y en manos de alguien ducho  en esgrima "
    "pueden llegar a ser temibles por su 		ligereza y maniobrabilidad, junto con la "
    "facilidad para causar heridas profundas.\n");
    AddId(({"estoque", "espada"}));
    Set(P_GENDER, GENDER_MALE);
    SetWeight(1900);
    SetNumberHands(1);
}
