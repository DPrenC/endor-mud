/* Archivo        cementerio00.c
   Autor:         Yalin y Lug
   Fecha:         08/05/2006
   Descripci�n:   Cementerio de la aldea (proyecto)
*/

#include "path.h"
inherit SHERALD("abroom");

create()
{
    ::create();
    SetIntShort("el cementerio de la aldea");
    SetIntLong("Te hayas dentro del cementerio donde son enterrados los "
        "muertos de este lugar. No es muy grande dado que la aldea no tiene "
        "muchos habitantes, pero s� lo suficiente como para darse un "
        "paseillo por �l\n La zona en la que te hayas ahora est� compuesta "
        "por tumbas  alineadas en el suelo. Junto a la puerta puedes ver dos "
        "grandes cipreses que ofrecen una sombra alargada sobre el "
        "cementerio. Hacia el oeste ves unos panteones y al este, todo "
        "parece estar muy descuidado.\n");
    SetIntNoise("Puedes escuchar el zumbido de alg�n insecto, pero aqu� la "
        "quietud es casi absoluta, como en tantos otros cementerios.\n");
    SetIntSmell("Podr�amos decir que huele a muerto, pero ser�a una broma "
        "muy burda trat�ndose de este lugar. En realidad huele a flores "
        "marchitas y a resina de cipr�s.\n");
    AddDetail(({"tumba", "tumbas"}), "Son tumbas excavadas en el suelo "
        "tapadas por grandes losas de m�rmol o de piedra caliza, dependiendo "
        "de la riqueza de cada muerto en vida.\n");
    AddDetail(({"losas", "losa"}), "Son grandes piedras rectangulares de "
        "m�rmol o de piedras calizas que se colocan sobre las tumbas "
        "enterradas en el suelo. Quiz�s los vivos tengan algo que temer de "
        "los muertos. Muchas de ellas est�n tan deterioradas que ya no se "
        "pueden leer las fechas ni los epitafios.\n");
    AddDetail(({"cipres", "cipr�s", "cipreses"}), "Se trata de dos grandes "
        "cipreses que crecen a ambos lados de la entrada del cementerio, "
        "cuya sombra alcanza a gran parte del mismo.\n");
    AddDetail(({"suelo"}), "Est� cubierto de grava en aquellos lugares donde "
        "no se excavaron tumbas, dando lugar a enrevesados senderuelos que "
        "serpentean entre ellas.\n");
    AddDetail(({"panteones", "panteon", "pante�n", "oeste"}), "Son un par de "
        "panteones que parecen desentonar aqu� con el resto del cementerio "
        "incluso, con el resto de la aldea, ya que parecen bastante lujosos "
        "para las capacidades econ�micas de unos simples labradores.\n");
    AddDetail(({"este"}), "desde aqu� esa zona del cementerio parece "
        "totalmente abandonada ya que desaparece entre malezas y arbustos.\n");
    AddDetail(({"maleza", "malezas", "arbustos"}), "casi ocultan a la vista "
        "por completo la parte este del cementerio.\n");
    AddExit("sur", SHERALD("calles/caminocem"));
    AddExit("oeste", SHERALD("cementerio/cementerio01"));
    AddExit("este", SHERALD("cementerio/cementerio02"));
}
