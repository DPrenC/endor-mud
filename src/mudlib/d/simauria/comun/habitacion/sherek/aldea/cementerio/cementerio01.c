/* Archivo        cementerio01.c
   Autor:         Yalin y Lug
   Fecha:         08/05/2006
   Descripción:   Cementerio de la aldea (proyecto)
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
        "el resto. Pero por lo demás no encuentras nada fuera de lo común "
        "que no exista en cualquier otro cementerio de Simauria.\n"
        "Al nordeste de aquí ves dos grandes cipreses y hacia el este está "
        "la parte central del cementerio.\n");
    SetIntNoise("Puedes escuchar el zumbido de algún insecto, pero aquí la "
        "quietud es casi absoluta, como en tantos otros cementerios.\n");
    SetIntSmell("Huele a flores marchitas y a resina de ciprés.\n");
    AddDetail(({"cipres", "ciprés", "cipreses", "nordeste"}), "Se trata de "
        "dos grandes cipreses que crecen a ambos lados de la entrada del "
        "cementerio, cuya sombra alcanza a gran parte del mismo.\n");
    AddDetail(({"suelo"}), "Está cubierto de grava en la callejuela que se "
        "forma entre ambos panteones.\n");
    AddDetail(({"panteones", "panteon", "panteón"}), "Son un par de "
        "panteones que parecen desentonar aquí con el resto del cementerio "
        "incluso, con el resto de la aldea. Están recubiertos totalmente de "
        "mmármol negro, pero algo en las lápidas te resulta del todo "
        "extraño dentro de este atípico lugar.\n");
    AddDetail(({"lapida", "lapidas", "lápida", "lápidas"}), "Las lápidas de "
        "ambos panteones son una gran lámina de mármol negro, con un "
        "bajorrelieve de la diosa Sherek decapitando a una serpiente "
        "enrrollada a su brazo con una gran daga. Pero lo que realmente te "
        "extraña del caso es que no tienen ningún tipo de escritura en ellas "
        "y, más aún, da la sensación que jamás han sido abiertas, por lo "
        "tanto, aun viéndose el paso del tiempo en ellas, nunca nadie parece "
        "haber sido enterrado aquí.\n");
    AddDetail(({"este", "cementerio"}), "desde aquí se ven al este las "
        "hileras de tumbas.\n");
    AddExit("este", SHERALD("cementerio/cementerio00"));
}
