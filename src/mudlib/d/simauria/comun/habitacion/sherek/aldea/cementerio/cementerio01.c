/* Archivo        cementerio01.c
   Autor:         Yalin y Lug
   Fecha:         08/05/2006
   Descripci�n:   Cementerio de la aldea (proyecto)
*/

#include "path.h"
inherit SHERALD("abroom");

create()
{
    ::create();
    SetIntShort("la parte oeste del cementerio de la aldea");
    SetIntLong("Te encuentras ahora en la parte oeste del cementerio. "
        "Delante de ti puedes ver un par de panteones bastante grandes que "
        "ocupan toda esta zona del cementerio y que desentonan un poco con "
        "el resto. Pero por lo dem�s no encuentras nada fuera de lo com�n "
        "que no exista en cualquier otro cementerio de Simauria.\n"
        "Al nordeste de aqu� ves dos grandes cipreses y hacia el este est� "
        "la parte central del cementerio.\n");
    SetIntNoise("Puedes escuchar el zumbido de alg�n insecto, pero aqu� la "
        "quietud es casi absoluta, como en tantos otros cementerios.\n");
    SetIntSmell("Huele a flores marchitas y a resina de cipr�s.\n");
    AddDetail(({"cipres", "cipr�s", "cipreses", "nordeste"}), "Se trata de "
        "dos grandes cipreses que crecen a ambos lados de la entrada del "
        "cementerio, cuya sombra alcanza a gran parte del mismo.\n");
    AddDetail(({"suelo"}), "Est� cubierto de grava en la callejuela que se "
        "forma entre ambos panteones.\n");
    AddDetail(({"panteones", "panteon", "pante�n"}), "Son un par de "
        "panteones que parecen desentonar aqu� con el resto del cementerio "
        "incluso, con el resto de la aldea. Est�n recubiertos totalmente de "
        "mm�rmol negro, pero algo en las l�pidas te resulta del todo "
        "extra�o dentro de este at�pico lugar.\n");
    AddDetail(({"lapida", "lapidas", "l�pida", "l�pidas"}), "Las l�pidas de "
        "ambos panteones son una gran l�mina de m�rmol negro, con un "
        "bajorrelieve de la diosa Sherek decapitando a una serpiente "
        "enrrollada a su brazo con una gran daga. Pero lo que realmente te "
        "extra�a del caso es que no tienen ning�n tipo de escritura en ellas "
        "y, m�s a�n, da la sensaci�n que jam�s han sido abiertas, por lo "
        "tanto, aun vi�ndose el paso del tiempo en ellas, nunca nadie parece "
        "haber sido enterrado aqu�.\n");
    AddDetail(({"este", "cementerio"}), "desde aqu� se ven al este las "
        "hileras de tumbas.\n");
    AddExit("este", SHERALD("cementerio/cementerio00"));
}
