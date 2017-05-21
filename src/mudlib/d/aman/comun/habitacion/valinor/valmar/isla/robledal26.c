/*****************************************************************************************
 ARCHIVO:       robledal26.c
 AUTOR:         Ztico
 FECHA:         03-05-2005
 DESCRIPCIÓN:   Gruta en la Isla de los druidas.
 COMENTARIOS:
*****************************************************************************************/

#include "./path.h"

inherit BASE_ISLA;

create()
{
    if(::create()) return 1;

    SetIntShort("un pequeño lago subterráneo");
    SetIntLong("Parece que te encuentras en el final de la cueva. A tus pies, enmarcado "
        "por inmensas losas de un color sorprendentemente claro y brillante, atisbas las "
        "aguas tranquilas de un pequeño lago. Hace frío y debido a ello seguramente la "
        "temperatura del mismo será muy baja. Quizá el levísimo oleaje te está avisando "
        "de algún ser extraño habita en las profundidades.\n");
    AddDetail(({"losas", "inmensas losas", "piedras"}), "Desprenden tenues rayos de luz "
        "que alcanzan a ilumninar toda la habitación.\n");
    AddDetail(({"aguas", "aguas tranquilas", "agua"}), "Lo que en un principio parecía "
        "agua es, en realidad, una sustancia bastante más espesa y viscosa.\n");
    AddDetail(({"lago", "pequeño lago"}), "Es muy oscuro y parece tremendamente "
        "profundo. Contrasta con la claridad de lo que le rodea.\n");
    AddDetail(({"oleaje", "borboteos"}), "A pesar de la tranquilidad de las aguas, en "
        "ciertas zonas aparece un movimiento casi imperceptible seguido de ligeros "
        "borboteos.\n");
    AddDetail("profundidades", "No hay forma de ver el fondo.\n");
    AddDetail("suelo", "Todo el suelo es terroso excepto las piedras que rodean al lago.\n");

    SetIndoors(1);
    SetIntBright(20);

    SetIntSmell("Huele a moho.\n");
    SetIntNoise("Escuchas un pequeño burbujeo.\n");

    AddExit("sureste", HAB_BOSQUE_ISLA("robledal22.c"));

    AddItem(PNJ_VALMAR("triton"), REFRESH_DESTRUCT);

//    SetExplorable(1);
}
