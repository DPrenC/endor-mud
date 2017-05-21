/* Archivo        plazoleta.c
   Autor:         Yalin y Lug
   Fecha:         04/05/2006
   Descripción:   Plaza central de la aldea (proyecto)
*/


#include "path.h"
#include <sounds.h>
inherit SHERALD("abroom");

create ()
{
    ::create();
    SetIntShort("la plazoleta central de la aldea de Sloch");
    SetIntLong("Te encuentras en una pequeña plaza que es el centro de la "
        "aldea de Sloch. aquí es donde la gente se reúne tras los cultos en "
        "el templo, para los mercados quincenales y para cualquier otra "
        "cuestión que lo requiera.\nA veces se reúnen algunas mujeres, que "
        "vienen aquí a coger agua para sus casas, de la única fuente que hay "
        "en muchas leguas a la redonda.\nEl suelo está empedrado con grandes "
        "lajas irregulares y sin pulir.\nHacia el norte entras en la calle "
        "principal, al este desemboca una callejuela y desde el este parte "
        "un camino. Al sur puedes ver el templo.\n");
    SetIntNoise("Oyes las voces de los aldeanos mientras hablan y el canto "
        "de los gorriones.\n");
    SetIntSmell("Huele a bosta de vaca.\n");
    AddDetail(({"templo", "iglesia", "sur"}), "Se trata de una edificación "
        "más grande que todas las demás de la aldea. Sus paredes gruesas, "
        "sus ventanas pequeñas  y su tejado aplanado le dan un aspecto "
        "achaparrado al edificio, pero sin duda no quitan la importancia que "
        "para los habitantes que habita la aldea tiene.\n");
    AddDetail(({"tejado"}), "Como en toda la aldea, está construído con "
        "pizarras.\n");
    AddDetail(({"ventana", "ventanas"}), "Son muy estrechas. Posiblemente "
        "demasiado pequeñas.\n");
    AddDetail(({"paredes", "muros"}), "Son de piedra. Posiblemente demasiado "
        "gruesos y poco elegantes.\n");
    AddDetail(({"suelo", "lajas", "piedras"}), "Son muchas lajas irregulares "
        "que le dan un aspecto extraño, pero evitan que durante las lluvias "
        "el barro y el agua lo invadan todo.\n");
    AddItem(OTRO("sherek/aldea/fuente"));
    AddExit("este", "caminogranja00");
    AddExit("oeste", "callejuela00");
    AddExit("norte", "calle04");
    AddExit("sur", SHERALD("casas/templo"));
    AddExit("noroeste",SHERALD("tiendas/banco"));
    AddItem(PNJ("sherek/aldea/guardian"), REFRESH_DESTRUCT,1);
    SetSoundEnvironment(SND_AMBIENTES("agua_fuente"));
}

