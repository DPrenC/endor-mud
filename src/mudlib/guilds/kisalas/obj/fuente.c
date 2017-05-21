/****************************************************************************
Fichero: /guilds/kisalas/objeto/fuente.c
Autor: Lug y Yalin
Fecha: 08/05/2007
Descripci�n: Fuente para el gremio de Kisalas
****************************************************************************/
#include "path.h"

inherit "/obj/fountain";

create()
{
    ::create();
    SetShort("una fuente");
    SetLong("De un bajo pedestal octogonal, surge una columna, igualmente "
        "octogonal, que sostiene una copa en forma de pir�mide invertida, "
        "octogonal, para variar.\nSobre el borde de la copa, cada dos v�rtices, "
        "ves la figura de una mujer en posici�n de lucha, cuatro en total. "
        "Cada una porta un arma diferente: un arco con su flecha, una daga, "
        "una vara y una lanza.\nDe la punta de las armas, brota un chorro de "
        "agua.\nTodo el conjunto est� tallado en m�rmol blanco, con piedras "
        "verdes incrustadas en el pilar y la copa.\n");
    SetNoGet("Hmmmm, tienes algo de fiebre... �Has comido alguna hierba rara?\n");
}

