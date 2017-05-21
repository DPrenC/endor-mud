/*****************************************************************************************
 ARCHIVO:       robledal13.c
 AUTOR:         Ztico
 FECHA:         03-05-2005
 DESCRIPCIÓN:   Robledal en la Isla de los druidas.
 COMENTARIOS:
*****************************************************************************************/

#include "./path.h"

inherit BASE_ISLA;

create()
{
    if(::create()) return 1;

    SetIntShort("el robledal");
    SetIntLong("Continúas por un extenso bosque, los grandes robles dominan todo el "
        "paraje como grandes conquistadores del terreno, de tanto en tanto permiten "
        "en las pequeñas lomas que convivan escuálidos brezales, zarzas y alguna que "
        "otra florecilla silvestre.\n");
    AddDetail("lomas", "Dan un toque diferente al paisaje, ya que en esta parte la "
        "niebla ha escarpado.\n");
    AddDetail(({"brezales", "escuálidos brezales", "escualidos brezales"}), "Con sus "
        "preciosas flores blancas y malvas rompen la sobriedad de todo el bosque "
        "pareciendo un espejismo entre tanta maleza.\n");
    AddDetail(({"robles", "grandes robles"}), "Nunca habías visto antes unos robles "
        "tan altos y esbeltos como los de este bosque, la corteza de los troncos es "
        "blanquecina y están repletos de nudos.\n");
    AddDetail("zarzas", "Grandes zarzas trabadas, escaramujos, enebros y todo tipo de "
        "hiedras se descuelgan de las paredes de las lomas.\n");
    AddDetail(({"florecilla", "florecilla silvestre"}), "Están contantemente siendo "
        "removidas por la brisa, endulzando el ambiente con su penetrante "
        "perfume.\n");
    AddDetail("suelo", "Está cubierto por las hojas de los robles y otras más pequeñas "
        "procedentes de las zarzas.\n");

    SetIntNoise("No muy lejos de aquí se escucha el ruido de un chapoteo.\n");

    AddExit("norte", HAB_BOSQUE_ISLA("robledal18.c"));
    AddExit("sur", HAB_BOSQUE_ISLA("robledal09.c"));
    AddExit("este", HAB_BOSQUE_ISLA("robledal14.c"));
    AddExit("sureste", HAB_BOSQUE_ISLA("robledal10.c"));
}
