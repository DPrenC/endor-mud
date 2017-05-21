/*****************************************************************************************
 ARCHIVO:       robledal01.c
 AUTOR:         Ztico
 FECHA:         03-05-2005
 DESCRIPCI�N:   Sendero a trav�s del robledal.
 COMENTARIOS:
*****************************************************************************************/

#include "./path.h"
#include <colours.h>

inherit BASE_ISLA;

public string leer_letrero();

create()
{
    if(::create()) return 1;

    SetIntShort("un peque�o sendero");
    SetIntLong("Est�s en el sendero que une el muelle con la posada 'El unicornio azul'. "
        "Todo est� envuelto en una bruma espesa, apenas se ve nada y se oye a�n menos, "
        "como si hasta los peque�os animales del bosque, si es que hay, se paralizaran "
        "por el velo de la sombra. Hacia el norte vislumbras la entrada de la posada, y "
        "encima de la puerta reconoces, a duras penas, un oxidado letrero.\n");
    AddDetail(({"bruma", "bruma espesa"}), "No puedes ver practicamente nada a trav�s de "
        "ella.\n");
    AddDetail(({"entrada", "posada", "p�rtico"}), "La entrada de la posada est� abierta, "
        "y una tenue luz proviene del interior.\n");
    AddDetail("puerta", "Est� abierta de par en par.\n");
    AddDetail("suelo", "A duras penas alcanzas a ver algo del sendero. A ambos lados "
        "crecen peque�os mont�culos de hierba.\n");
    AddDetail(({"mont�culos", "monticulos", "hierba"}), "Delimitan el sendero.\n");
    AddDetail(({"cartel", "letrero", "oxidado letrero"}), "Es de piedra. En el centro "
        "tiene talladas unas letras borrosas que puedes leer.\n");
    AddReadMsg(({"letrero", "cartel"}), SF(leer_letrero));

    SetIntNoise("Un profundo silencio cubre el lugar.\n");

    AddExit("norte", HAB_BOSQUE_ISLA("posada01_vestib.c"));
    AddExit("noroeste", HAB_BOSQUE_ISLA("robledal05.c"));
    AddExit("este", HAB_BOSQUE_ISLA("robledal02.c"));
    AddExit("oeste", HAB_BOSQUE_ISLA("robledal00.c"));
}

public string leer_letrero()
{
    if(TP->QueryTiflo())
        return "\n 'EL UNICORNIO AZUL' \n\n";
    else
        return "\n" TC_CYAN "             \\                            \n"
                            "             _\\,, EL UNICORNIO AZUL       \n"
                            "             \"-=\\~     _                 \n"
                            "                \\\\~___( ~                \n"
                            "               _|/---\\\\_                 \n"
                            "               \\        \\ " TC_NORMAL "\n\n";

}
