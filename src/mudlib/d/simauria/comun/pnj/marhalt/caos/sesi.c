/****************************************************************************
Fichero: sesi.c
Autor: Ratwor
Fecha: 15/08/2007
Descripci�n: El hijo peque�o del jefe Girlak.
****************************************************************************/

#include "./path.h"
#include <properties.h>
#include <gremios.h>

inherit CAOSPNJ"ogro_base";

create(){
    ::create();
    SetStandard("Sesi","ogro",([ GC_LUCHADOR:45+d6()]),GENERO_MASCULINO);

    SetShort("Sesi, un joven ogro");
    SetLong("   Un j�ven ogro peque�o para los est�ndares de su raza, puesto que tiene "
    "el tama�o de un humano adulto, aunque mas ancho y pesado. \n  Probablemente "
    "hijo de Girlak y una de sus hembras, de momento se le permite compartir la caverna "
    "con su madre, aunque pronto deber� abandonarla para unirse al grueso de la "
    "poblaci�n como un adulto mas, sopena de que su padre comience a desconfiar "
    "de sus intenciones y lo acabe devorando en alg�n acceso de furia repentina.\n"
    " Va desnudo a escepci�n de un taparrabos de lo que parece ser piel de jabal� y "
    "parece algo desnutrido. Tal vez sea por esto por lo que te mira con ojos �vidos "
    "siguiendo todos tus movimientos.\n");

        AddId(({"sesi","Sesi","adolescente","adolescente ogro","ogro","Ogro",
        "ogro de las cavernas", "hijo", "joven"}));
    SetAlign(-100);
    SetGoChance(80);
}
