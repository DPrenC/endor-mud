/****************************************************************************
Fichero: /d/simauria/comun/habitacion/sherek/aldea/pradera/pradera63.c
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
        "una especie de playa, en la ribera del Kandal.\nEl terreno vuelve a "
        "tomar aqu� pendiente hacia el oeste, siguiendo el desnivel de la "
        "monta�a, por lo que el curso del agua vuelve a acelerarse.\nUN muro "
        "al oeste, y el r�o al sur, te cierran el paso. En las dem�s "
        "direcciones se extiende la pradera.\n");
    SetIntSmell("Huele a humedad, algas y hierba.\n");
    AddDetail(({"playa","arena"}), "Arena fresca, fina y blanca.\n");
    AddDetail(({"rio","r�o","curso","cauce","agua"}), "El r�o discurre "
        "ahora m�s r�pido y revuelto, aunque su agua sigue limpia.\n");
    AddDetail(({"muro","tapia"}), "Es un muro de piedra que separa la "
        "pradera de los vi�edos.\n");
    AddExit("norte", SHERALD("pradera/pradera53"));
    AddExit("este", SHERALD("pradera/pradera62"));
    poner_pnj();
    SetSoundEnvironment(SND_AMBIENTES("rio_bosque"));
}
