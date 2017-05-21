/*****************************************************************************************
 ARCHIVO:       robledal15.c
 AUTOR:         Ztico
 FECHA:         03-05-2005
 DESCRIPCIÓN:   Robledal en la Isla de los druidas.
 COMENTARIOS:   Hacia el OESTE, ventana de la posada07_hab4.c
*****************************************************************************************/

#include "./path.h"

inherit BASE_ISLA;

create()
{
    if(::create()) return 1;

    SetIntShort("el robledal, cerca de la posada");
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

    AddExit("noroeste", HAB_BOSQUE_ISLA("robledal19.c"));
    AddExit("sur", HAB_BOSQUE_ISLA("robledal11.c"));
}
