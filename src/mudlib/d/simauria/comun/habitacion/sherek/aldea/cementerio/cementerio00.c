/* Archivo        cementerio00.c
   Autor:         Yalin y Lug
   Fecha:         08/05/2006
   Descripción:   Cementerio de la aldea (proyecto)
*/

#include "path.h"
inherit SHERALD("abroom");

create()
{
    ::create();
    SetIntShort("el cementerio de la aldea");
    SetIntLong("Te hayas dentro del cementerio donde son enterrados los "
        "muertos de este lugar. No es muy grande dado que la aldea no tiene "
        "muchos habitantes, pero sí lo suficiente como para darse un "
        "paseillo por él\n La zona en la que te hayas ahora está compuesta "
        "por tumbas  alineadas en el suelo. Junto a la puerta puedes ver dos "
        "grandes cipreses que ofrecen una sombra alargada sobre el "
        "cementerio. Hacia el oeste ves unos panteones y al este, todo "
        "parece estar muy descuidado.\n");
    SetIntNoise("Puedes escuchar el zumbido de algún insecto, pero aquí la "
        "quietud es casi absoluta, como en tantos otros cementerios.\n");
    SetIntSmell("Podríamos decir que huele a muerto, pero sería una broma "
        "muy burda tratándose de este lugar. En realidad huele a flores "
        "marchitas y a resina de ciprés.\n");
    AddDetail(({"tumba", "tumbas"}), "Son tumbas excavadas en el suelo "
        "tapadas por grandes losas de mármol o de piedra caliza, dependiendo "
        "de la riqueza de cada muerto en vida.\n");
    AddDetail(({"losas", "losa"}), "Son grandes piedras rectangulares de "
        "mármol o de piedras calizas que se colocan sobre las tumbas "
        "enterradas en el suelo. Quizás los vivos tengan algo que temer de "
        "los muertos. Muchas de ellas están tan deterioradas que ya no se "
        "pueden leer las fechas ni los epitafios.\n");
    AddDetail(({"cipres", "ciprés", "cipreses"}), "Se trata de dos grandes "
        "cipreses que crecen a ambos lados de la entrada del cementerio, "
        "cuya sombra alcanza a gran parte del mismo.\n");
    AddDetail(({"suelo"}), "Está cubierto de grava en aquellos lugares donde "
        "no se excavaron tumbas, dando lugar a enrevesados senderuelos que "
        "serpentean entre ellas.\n");
    AddDetail(({"panteones", "panteon", "panteón", "oeste"}), "Son un par de "
        "panteones que parecen desentonar aquí con el resto del cementerio "
        "incluso, con el resto de la aldea, ya que parecen bastante lujosos "
        "para las capacidades económicas de unos simples labradores.\n");
    AddDetail(({"este"}), "desde aquí esa zona del cementerio parece "
        "totalmente abandonada ya que desaparece entre malezas y arbustos.\n");
    AddDetail(({"maleza", "malezas", "arbustos"}), "casi ocultan a la vista "
        "por completo la parte este del cementerio.\n");
    AddExit("sur", SHERALD("calles/caminocem"));
    AddExit("oeste", SHERALD("cementerio/cementerio01"));
    AddExit("este", SHERALD("cementerio/cementerio02"));
}
