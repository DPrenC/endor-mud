/* calle41n: Plaza de Nandor. Aqui hay una pequenya fuente.

   03/06/99 [Mirill@Simauria] Correcciones

*/

#include <properties.h>
#include "./path.h"
#include <sounds.h>
inherit SIM_ROOM;

create () {
    ::create();

    SetIntShort("la plaza de Nandor");
    SetIntLong("Estás en la plaza de Nandor. El terreno está cubierto de guijarros "
        "redondeados. En este lugar hay una fuente de piedra de la cual mana un "
        "refrescante chorro de agua clara y a la que los pueblerinos llegan para "
        "saciar su sed.\n  De tanto en tanto, alguna paloma se posa sobre la fuente o "
        "picotea algo del suelo.\n  Al norte ves el inicio de un pasaje.\n  Al sur, "
        "puedes ver el pozo al que las mujeres de la villa van a buscar el agua.\n"
        " Al oeste comienza la calle principal.\n");
    AddDetail("palomas", "Parece que han anidado en alguna parte cerca de aquí. Cada "
        "tanto se posan a beber agua de la fuente o buscan alguna migaja en el suelo,"
        " no demuestran tener miedo de los que pasan por su lado.\n");
    SetLocate("Villa de Nandor");
    SetIndoors(0);
    AddDetail(({"encina","arbol","árbol"}),
        "Es enorme. Sus ramas deben dar buena sombra.\n");
    AddDetail(({"pozo"}),
        "Es un pozo como otro cualquiera.\n");
    AddDetail(({"guijarros"}),
        "Pequeños guijarros redondeados. Es mejor que la tierra malamente apisonada que"
        "hay en el resto de la calle.\n");
    AddDetail(({"caño","canyo"}),"Es un simple tubo metálico que sale de la "
        "piedra.\n");
    AddDetail(({"brocal","pila"}),"Es un agujero cuadrado pavimentado, donde se "
        "recoge el agua que cae de la fuente.\n");
    AddItem(OTRO("marhalt/nandor/fuente"));
    SetSoundEnvironment(SND_AMBIENTES("agua_fuente"));


    AddItem(QUEST + "ghoul/viejo1",REFRESH_DESTRUCT,1);
    AddItem(PNJ("marhalt/viejo2"),REFRESH_DESTRUCT,1);
    AddItem(PNJ("marhalt/viejo3"),REFRESH_DESTRUCT,1);
    AddExit("este","calle42n");
    AddExit("oeste", "./calle3");
    AddExit("sur","./calle41s");
    AddExit("norte","./calle17");
}
