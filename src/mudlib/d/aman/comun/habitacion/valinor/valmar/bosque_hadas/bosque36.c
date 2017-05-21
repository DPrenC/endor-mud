/*****************************************************************************************
 ARCHIVO:       bosque36.c
 AUTOR:         Ztico
 FECHA:         26-04-2005
 DESCRIPCIÓN:   Bosque de las Hadas.
 COMENTARIOS:
*****************************************************************************************/

#include "./path.h"

inherit BASE_HADAS;

create()
{
    if(::create()) return 1;

    SetIntShort("la antecámara");
    SetIntLong("Estás en un pequeño habitáculo brillante por el que pululan todo tipo "
        "de criaturas de múltiples tamaños, entrando y saliendo de la habitación sin "
        "percatarse de tu presencia; las más grandes están acompañadas por diminutas "
        "réplicas de sí mismas, por lo que deduces que pudieran ser sus retoños. Hay "
        "montones de almohadones de aspecto sedoso tirados en el suelo, restos "
        "consumidos de velas aromáticas, y junto a la pared, un montón de balas de "
        "algodón apiladas.\n");
    AddDetail(({"criaturas", "criatura"}), "Los hay de todos los tipos y tamaños. Ves "
        "algunos seres con la mitad del cuerpo de un hombrecillo y la otra mitad de "
        "un saltamontes, otros con patas de gallina y cuernos de chivo. Corretean de "
        "un lado para otro sin parar.\n");
    AddDetail("almohadones", "Hay tantos y de tan diversos colores que te es "
        "practicamente imposible ver el suelo.\n");
    AddDetail(({"restos", "restos consumidos", "velas", "velas aromáticas"}), "Aún "
        "puedes observar hojitas y pétalos entre la cera derretida.\n");
    AddDetail(({"balas", "algodón", "algodon", "balas algodón"}), "Seguramente "
        "servirán para reponer los mullidos colchones y cojines de las alcobas.\n");
    SetIndoors(1);
    SetIntBright(30);

    AddExit("norte", HAB_BOSQUE_HADAS("bosque39.c"));
    AddExit("noreste", HAB_BOSQUE_HADAS("bosque40.c"));

    AddItem(PNJ_VALMAR("hada_sirviente.c"), REFRESH_DESTRUCT, random(3));
}
