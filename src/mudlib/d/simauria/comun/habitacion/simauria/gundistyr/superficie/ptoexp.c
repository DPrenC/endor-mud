/* ******************************************* */
/* *                                         * */
/* *         ARCHIVO:ptoexp.c                * */
/* *                                         * */
/* * [t] 24-2-03 ¿por que leñe usáis formatos raros para la cabecera? así no hay* */
/* *		diox que se aclare... bueno, cambio un poco la descripción para */
/*		que la peña no se vuelva lerda poniendo "mirar oeste". */
/* ******************************************* */
#include "path.h"
#include <colours.h>
inherit SIM_ROOM;

string m_hor()
{
    TP->SetExplored();
    return "Desde el punto en el que estás puedes divisar gran parte del reino humano de "
        "Simauria. Divisas con claridad hacia el oeste el pueblo de Nandor, así como la "
        "fortaleza del bandido Cored y el bosque que lo rodea. Hacia allí tu mirada queda "
        "bloqueada por las majestuosas montañas de Itare. Aspiras el aire puro y te sientes "
        "bien ante una vista tan majestuosa.\n";
}

create()
{
    ::create();
    SetIntShort("las ruinas de Gundistyr");
    SetIntLong("Has llegado a un saliente de roca de las montañas. Conforme pisas el dulce "
        "césped te rodea una gran sensación de tranquilidad cuerpo sientas un leve cosquilleo "
        "que te recorre toda la columna pero que te hace sentir realmente bien. Dejas vagar tu "
        "mirada y observas con claridad el horizonte.\n");
    AddDetail(({"horizonte"}),SF(m_hor));
    SetIntNoise("Únicamente escuchas una suave brisa.\n");
    SetIntSmell("Respiras profundamente y te llega el agradable olor de la hierba.\n");
    AddExit("suroeste","2torre03");
}
