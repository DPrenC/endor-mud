/* calle42s. Parada de la diligencia a Ishtria
  3/5/2002      Articman Castellanización y retoques         */

#include <properties.h>
#include "./path.h"

inherit STAGECOACH_STOP;

create () {
    ::create();

    SetIntShort("la plaza de Nandor");
    SetIntLong("Ésta es la plaza del pueblo. Este terreno está muy pisado por pies "
        "humanos y ruedas de diligencias, como lo prueban las marcas que han quedado en"
        " la tierra, y que son visibles a pesar de los guijarros que cubren el suelo.\n"
        "  En este lugar tienen su parada algunas diligencias que cubren parte "
        "del territorio de Simauria.\n Al norte se ve una gran encina y debajo, algunos bancos de piedra."
        "\n  Al oeste se divisa el pozo al que las mujeres van a buscar agua. \n");
  SetLocate("Aldea de Nandor");
    SetIndoors(0);
    SetClimateServer(SERVER);
    AddDetail(({"encina","arbol","árbol"}),
        "Es un árbol enorme. Sus ramas deben dar una buena sombra.\n");
    AddDetail(({"pozo"}),
        "Es un simple pozo al que la gente va a por agua.\n");
    AddDetail(({"mujeres"}),
        "Las hay de todas las edades. Parece que el pozo es el centro de reunión y "
        "un lugar perfecto para el cotilleo, ya que todas charlan y ríen animadamente.\n");
    AddDetail("cartel","Es un cartel de madera de pino, prueba a leerlo.\n");
    AddDetail("huellas", "Son huellas de pies humanos, pero sobre todo de ruedas de las "
        "diligencias que pasan por aquí.\n");
    AddDetail("poste", "Se trata de un poste clavado en el suelo, que parece haber "
        "resistido los embates de vientos y tormentas durante varios años. Sin embargo"
        " se mantiene erguido y firme. En él puedes ver un cartel de madera con "
        "información sobre las diligencias que cubren esta parte de Simauria.\n");

    AddExit("norte", "calle42n");
    AddExit("sur","./calle5");
    AddExit("oeste", "./calle41s");
    AddDiligencia(ZEPAR("zepar"));
    AddDiligencia(MASHER("masher"));
    AddDiligencia(PORHALT("porhalt"));
    SetNombreParada("nandor");
    SetKeeper(PNJ("diligencia/taquillero"));
}
