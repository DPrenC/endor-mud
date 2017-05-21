/* ******************************************* */
/* *                                         * */
/* *         ARCHIVO:ptoexp.c                * */
/* *                                         * */
/* * [t] 24-2-03 �por que le�e us�is formatos raros para la cabecera? as� no hay* */
/* *		diox que se aclare... bueno, cambio un poco la descripci�n para */
/*		que la pe�a no se vuelva lerda poniendo "mirar oeste". */
/* ******************************************* */
#include "path.h"
#include <colours.h>
inherit SIM_ROOM;

string m_hor()
{
    TP->SetExplored();
    return "Desde el punto en el que est�s puedes divisar gran parte del reino humano de "
        "Simauria. Divisas con claridad hacia el oeste el pueblo de Nandor, as� como la "
        "fortaleza del bandido Cored y el bosque que lo rodea. Hacia all� tu mirada queda "
        "bloqueada por las majestuosas monta�as de Itare. Aspiras el aire puro y te sientes "
        "bien ante una vista tan majestuosa.\n";
}

create()
{
    ::create();
    SetIntShort("las ruinas de Gundistyr");
    SetIntLong("Has llegado a un saliente de roca de las monta�as. Conforme pisas el dulce "
        "c�sped te rodea una gran sensaci�n de tranquilidad cuerpo sientas un leve cosquilleo "
        "que te recorre toda la columna pero que te hace sentir realmente bien. Dejas vagar tu "
        "mirada y observas con claridad el horizonte.\n");
    AddDetail(({"horizonte"}),SF(m_hor));
    SetIntNoise("�nicamente escuchas una suave brisa.\n");
    SetIntSmell("Respiras profundamente y te llega el agradable olor de la hierba.\n");
    AddExit("suroeste","2torre03");
}
