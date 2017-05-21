/****************************************************************************
Fichero: /d/simauria/comun/habitacion/sherek/aldea/pradera/pradera61.c
Autor: Lug y Yalin
Fecha: 19/08/2006
Descripci�n: A la orilla del r�o, al sur de la pradera.
****************************************************************************/

#include "path.h"
#include <sounds.h>
inherit SHERALD("pradera/pradera");

create()
{
    ::create();
    SetIntShort("la orilla del r�o Kandal");
    SetIntLong("La pradera, que se extiende hacia el norte, termina aqu� en "
        "una especie de playa, en la ribera del Kandal.\nEl terreno es aqu� "
        "m�s llano, por lo que el curso del r�o se vuelve m�s tranquilo.\nEn "
        "esta parte, el r�o apenas alcanza 1 metro 20 de profundidad, lo que "
        "hace que sea un buen sitio para darse un ba�ito.\nAl sur, el r�o te "
        "cierra el paso. En las dem�s direcciones se extiende la pradera.\n");
    SetIntSmell("Huele a humedad, algas y hierba.\n");
    AddDetail(({"playa","arena"}), "Arena fresca, fina y blanca.\n");
    AddDetail(({"rio","r�o","curso","cauce","agua"}), "El r�o discurre "
        "tranquilo y susurrante, y su agua est� muy limpia.\n");
    AddExit("norte", SHERALD("pradera/pradera51"));
    AddExit("este", SHERALD("pradera/pradera60"));
    AddExit("oeste", SHERALD("pradera/pradera62"));
    int hora = QueryServer()->QueryState();
    if ((hora >= ND_PRENOON) && (hora <= ND_FALL)) AddItem(QUEST+"sherek/ninyo",REFRESH_DESTRUCT,1);
    poner_pnj();
    SetSoundEnvironment(SND_AMBIENTES("rio_bosque"));
}
