/*****************************************************************************************
 ARCHIVO:       bosque36.c
 AUTOR:         Ztico
 FECHA:         26-04-2005
 DESCRIPCI�N:   Bosque de las Hadas.
 COMENTARIOS:
*****************************************************************************************/

#include "./path.h"

inherit BASE_HADAS;

create()
{
    if(::create()) return 1;

    SetIntShort("la antec�mara");
    SetIntLong("Est�s en un peque�o habit�culo brillante por el que pululan todo tipo "
        "de criaturas de m�ltiples tama�os, entrando y saliendo de la habitaci�n sin "
        "percatarse de tu presencia; las m�s grandes est�n acompa�adas por diminutas "
        "r�plicas de s� mismas, por lo que deduces que pudieran ser sus reto�os. Hay "
        "montones de almohadones de aspecto sedoso tirados en el suelo, restos "
        "consumidos de velas arom�ticas, y junto a la pared, un mont�n de balas de "
        "algod�n apiladas.\n");
    AddDetail(({"criaturas", "criatura"}), "Los hay de todos los tipos y tama�os. Ves "
        "algunos seres con la mitad del cuerpo de un hombrecillo y la otra mitad de "
        "un saltamontes, otros con patas de gallina y cuernos de chivo. Corretean de "
        "un lado para otro sin parar.\n");
    AddDetail("almohadones", "Hay tantos y de tan diversos colores que te es "
        "practicamente imposible ver el suelo.\n");
    AddDetail(({"restos", "restos consumidos", "velas", "velas arom�ticas"}), "A�n "
        "puedes observar hojitas y p�talos entre la cera derretida.\n");
    AddDetail(({"balas", "algod�n", "algodon", "balas algod�n"}), "Seguramente "
        "servir�n para reponer los mullidos colchones y cojines de las alcobas.\n");
    SetIndoors(1);
    SetIntBright(30);

    AddExit("norte", HAB_BOSQUE_HADAS("bosque39.c"));
    AddExit("noreste", HAB_BOSQUE_HADAS("bosque40.c"));

    AddItem(PNJ_VALMAR("hada_sirviente.c"), REFRESH_DESTRUCT, random(3));
}
