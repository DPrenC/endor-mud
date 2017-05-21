/****************************************************************************
Fichero: /d/simauria/comun/habitacion/sherek/aldea/pradera/pradera60.c
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
        "esta parte, una depresi�n forma una hoya de unos 2 o 3 metros de "
        "profundidad, lo que hace que sea un buen lugar para pescar.\nAl "
        "este, el muro de la granja, y el r�o al sur, te cierran el paso. En "
        "las dem�s direcciones se extiende la pradera.\n");
    SetIntSmell("Huele a humedad, algas y hierba.\n");
    AddDetail(({"playa","arena"}), "Arena fresca, fina y blanca.\n");
    AddDetail(({"rio","r�o","curso","cauce","agua"}), "El r�o discurre "
        "tranquilo y susurrante, y su agua est� muy limpia.\n");
    AddDetail(({"muro","tapia","pared"}), "Es la pared trasera de las "
        "dependencias de la granja.\n");
    int hora = QueryServer()->QueryState();
    if ((hora >= ND_PRENOON) && (hora <= ND_FALL)) AddItem(QUEST+"sherek/abuelo",REFRESH_DESTRUCT,1);
    AddExit("norte", SHERALD("pradera/pradera50"));
    AddExit("oeste", SHERALD("pradera/pradera61"));
    poner_pnj();
    SetSoundEnvironment(SND_AMBIENTES("rio_bosque"));
}
