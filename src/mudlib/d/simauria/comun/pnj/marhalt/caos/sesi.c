/****************************************************************************
Fichero: sesi.c
Autor: Ratwor
Fecha: 15/08/2007
Descripción: El hijo pequeño del jefe Girlak.
****************************************************************************/

#include "./path.h"
#include <properties.h>
#include <gremios.h>

inherit CAOSPNJ"ogro_base";

create(){
    ::create();
    SetStandard("Sesi","ogro",([ GC_LUCHADOR:45+d6()]),GENERO_MASCULINO);

    SetShort("Sesi, un joven ogro");
    SetLong("   Un jóven ogro pequeño para los estándares de su raza, puesto que tiene "
    "el tamaño de un humano adulto, aunque mas ancho y pesado. \n  Probablemente "
    "hijo de Girlak y una de sus hembras, de momento se le permite compartir la caverna "
    "con su madre, aunque pronto deberá abandonarla para unirse al grueso de la "
    "población como un adulto mas, sopena de que su padre comience a desconfiar "
    "de sus intenciones y lo acabe devorando en algún acceso de furia repentina.\n"
    " Va desnudo a escepción de un taparrabos de lo que parece ser piel de jabalí y "
    "parece algo desnutrido. Tal vez sea por esto por lo que te mira con ojos ávidos "
    "siguiendo todos tus movimientos.\n");

        AddId(({"sesi","Sesi","adolescente","adolescente ogro","ogro","Ogro",
        "ogro de las cavernas", "hijo", "joven"}));
    SetAlign(-100);
    SetGoChance(80);
}
