/****************************************************************************
Fichero: escudo_normal.c
Autor: Ratwor
Fecha: 09/12/2007
Descripción: un escudo para los hombres de armas del castillo.
****************************************************************************/

#include <properties.h>
#include <combat.h>
inherit ARMOUR;
create()
{
    ::create();
    SetStandard(AT_ESCUDO, 3, P_SIZE_GENERIC, M_HIERRO);
    SetShort("Un escudo");
    SetLong("Se trata de un escudo de tamaño medio que protege solamente el torso. Está "
    "constituido por un armazón de bandas de hierro y secciones de madera tachonada muy "
    "resistente. Este escudo en particular tiene forma cuadrada con el extremo inferior  "
    "acabado en un triángulo poco pronunciado que puede usarse para golpear al oponente.\n"
    "Es el escudo mas común entre la infantería, y compensa la poca protección ofrecida "
    "con una mayor manejabilidad y ligereza comparándolos con los grandes escudos. En "
    "la parte frontal suelen llevar los emblemas del guerrero que los porta, la ciudad "
    "o el señorío al que pertenece quien los lleva.\n");
    AddId(({"escudo", "armadura"}));
    Set(P_GENDER, GENDER_MALE);
    SetWeight(4500);
}
