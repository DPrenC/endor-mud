/*****************************************************************************************
 ARCHIVO:       robledal34.c
 AUTOR:         Ztico
 FECHA:         03-05-2005
 DESCRIPCI�N:   Robledal en la Isla de los druidas.
 COMENTARIOS:
*****************************************************************************************/

#include "./path.h"

inherit BASE_ISLA;

create()
{
    if(::create()) return 1;

    SetIntShort("la zona norte del bosque");
    SetIntLong("Un grupo de �rboles te rodea aunque no son muy apreciables debido a la "
        "espesa niebla que todo lo cubre. Los troncos que est�n esparcidos por el suelo "
        "tienen una verdosa capa de musgo y en torno a ellos, peque�as plantas y "
        "arbustos crecen a pesar de la continua ausencia de luz.\n");
    AddDetail(({"�rboles", "arboles"}), "No puedes distinguirlos con nitidez.\n");
    AddDetail("suelo", "En el suelo fangoso los arbustos escasean y proliferan "
        "multitud de plantas herbaceas.\n");
    AddDetail("arbustos", "Peque�os helechos salpican la base de los troncos.\n");
    AddDetail(({"plantas", "plantas herbaceas"}), "Hierbajos, tallos y ca�as se "
        "arremolinan en torno a la madera podrida.\n");
    AddDetail("niebla", "Todo est� envuelto en una neblina casi permanente.\n");
    AddDetail("troncos", "Est�n huecos y la mayor�a est�n podridos debido a la humedad "
        "y a la constante falta de luz.\n");

    SetIntSmell("Un olor dulz�n y penetrante, fruto de la descomposici�n de la materia "
        "vegetal, y del olor desprendido por los �rboles y plantas.\n");
    SetIntNoise("No muy lejos de aqu� se escucha el ruido de un chapoteo.\n");


    AddExit("este", HAB_BOSQUE_ISLA("robledal35.c"));
    AddExit("sureste", HAB_BOSQUE_ISLA("robledal31.c"));
    AddExit("suroeste", HAB_BOSQUE_ISLA("robledal29.c"));
}
