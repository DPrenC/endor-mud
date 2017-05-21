/*****************************************************************************************
 ARCHIVO:       robledal27.c
 AUTOR:         Ztico
 FECHA:         03-05-2005
 DESCRIPCIÓN:   Gruta en la Isla de los druidas.
 COMENTARIOS:
*****************************************************************************************/

#include "./path.h"
#include <moving.h>
#include <nightday.h>

inherit BASE_ISLA;

public int f_salir_cueva();

create()
{
    if(::create()) return 1;

    SetIntShort("la entrada de una pequeña gruta");
    SetIntLong("Las paredes que forman esta especie de vestíbulo son ásperas y de ellas "
        "sobresalen infinidad de protuberancias que podrían lastimarte. El suelo es un "
        "amasijo de hojas en descomposición y restos de pequeños animales.\nUn gran "
        "agujero, situado en una de las paredes, es lo único que proporciona algo de "
        "claridad a la habitación.\n");
    AddDetail("paredes" ,"Están húmedas y tienen un aspecto craso.\n");
    AddDetail(({"vestíbulo", "vestibulo", "cámara", "camara"}), "La cámara en la que te "
        "encuentras no es demasiado alta, apenas medirá cuatro metros. Al fondo, puedes "
        "ver la continuación de la gruta.\n");
    AddDetail("protuberancias", "Tienen un filo agudísimo, muchos de los animales, cuyos "
        "restos ves en el suelo, murieron al chocar contra ellas.\n");
    AddDetail("techo", "Está lleno de grietas y fisuras por las que se filtra el agua.\n");
    AddDetail("suelo", "Parece que está acolchado.\n");
    AddDetail(({"hojas", "restos", "amasijo"}), "Gracias al ambiente tan húmedo, todo lo "
        "que cae en la cueva se descompone rápidamente.\n");

    SetIntSmell("Percibes el olor dulzón de los restos en descomposición y de la "
        "humedad.\n");
    SetIntNoise("Oyes un goteo continuo.\n");

    SetIndoors(1);

    if(NIGHTDAY->QueryState() == ND_NIGHT)
        SetIntBright(ND_NOCHE);
    else SetIntBright(ND_PRENOCHE);

    AddExit("norte", HAB_BOSQUE_ISLA("robledal33.c"));
    AddExit("agujero", SF(f_salir_cueva));
}

public int f_salir_cueva()
{
    TP->move(HAB_BOSQUE_ISLA("robledal21.c"), M_SPECIAL,
        ({"desaparece a través del agujero",
          "llega de entre la maleza",
          "Atraviesas el agujero"}));
    return 1;
}
