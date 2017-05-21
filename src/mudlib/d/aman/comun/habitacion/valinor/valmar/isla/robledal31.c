/*****************************************************************************************
 ARCHIVO:       robledal31.c
 AUTOR:         Ztico
 FECHA:         03-05-2005
 DESCRIPCIÓN:   Robledal en la Isla de los druidas.
 COMENTARIOS:   noise...
*****************************************************************************************/

#include "./path.h"

inherit BASE_ISLA;

create()
{
    if(::create()) return 1;

    SetIntShort("el bosque");
    SetIntLong("A tus pies, se extiende una alfombra de agujas de abeto, salpicadas aquí "
        "y allá por diminutas bellotas rumoreando bajo las copas de los grandes "
        "robles. Se aprecia el abandono y la vetustez.\n");
    AddDetail(({"agujas", "alfombra", "alfombra de agujas"}), "Cubren la tierra con una "
        "capa de cinco pulgadas de espesor.\n");
    AddDetail("bellotas", "Ruedan ligeras sobre las agujas a causa de la brisa.\n");
    AddDetail(({"robles", "grandes robles"}), "Están inclinados, como haciendo una "
        "reverencia a todo aquel que se interna en estos rincones.\n");
    AddDetail("suelo", "Está saturado y totalmente cubierto.\n");

    SetIntSmell("El aroma de los abetos es muy fuerte, hasta sofocante.\n");

    AddExit("noroeste", HAB_BOSQUE_ISLA("robledal34.c"));
}
