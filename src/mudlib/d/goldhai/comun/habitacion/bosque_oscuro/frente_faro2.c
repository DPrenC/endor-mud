/*=============================================================*
 |            << GOLDHAI.Crowy [w] Woo@simauria >>             |
 *=============================================================*
 |               Creacion............. 06-01-98                |
 |               Ultima Modificacion.. 29-10-98                |
 |                                                             |
 *=============================================================*/

#include "./path.h"
inherit GBOSQUE;

create()
{
    ::create();
    SetPreIntShort("frente a");
    SetIntShort("el faro del Norte");
    SetIntLong("Un impresionante faro se alza ante ti destacando por encima de las copas de "
        "los árboles de este bosque. Al parecer siempre está encendido para evitar que los "
        "barcos se acerquen demasiado a la zona acantilada y encallen en ella. Puedes ver el "
        "mar desde aquí golpeando con fuerza las rocas. Si vas al Suroeste llegarás al puerto "
        "oeste de Goldhai, un sitio interesante y desde el cuál podrás salir de esta isla. Por "
        "el contrario, si vas en dirección este llegarás a la parte norte de la ciudad de "
        "Crowy.\n");
    AddExit("este",BOSCURO("alrededor_crowy18"));
    AddExit("suroeste",PUERTO("puerto5"));
    AddPnj();
    SetLocate("bosque oscuro de Goldhai");
}
