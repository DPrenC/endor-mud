/*****************************************************************************************
 ARCHIVO:       robledal27.c
 AUTOR:         Ztico
 FECHA:         03-05-2005
 DESCRIPCI�N:   Gruta en la Isla de los druidas.
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

    SetIntShort("la entrada de una peque�a gruta");
    SetIntLong("Las paredes que forman esta especie de vest�bulo son �speras y de ellas "
        "sobresalen infinidad de protuberancias que podr�an lastimarte. El suelo es un "
        "amasijo de hojas en descomposici�n y restos de peque�os animales.\nUn gran "
        "agujero, situado en una de las paredes, es lo �nico que proporciona algo de "
        "claridad a la habitaci�n.\n");
    AddDetail("paredes" ,"Est�n h�medas y tienen un aspecto craso.\n");
    AddDetail(({"vest�bulo", "vestibulo", "c�mara", "camara"}), "La c�mara en la que te "
        "encuentras no es demasiado alta, apenas medir� cuatro metros. Al fondo, puedes "
        "ver la continuaci�n de la gruta.\n");
    AddDetail("protuberancias", "Tienen un filo agud�simo, muchos de los animales, cuyos "
        "restos ves en el suelo, murieron al chocar contra ellas.\n");
    AddDetail("techo", "Est� lleno de grietas y fisuras por las que se filtra el agua.\n");
    AddDetail("suelo", "Parece que est� acolchado.\n");
    AddDetail(({"hojas", "restos", "amasijo"}), "Gracias al ambiente tan h�medo, todo lo "
        "que cae en la cueva se descompone r�pidamente.\n");

    SetIntSmell("Percibes el olor dulz�n de los restos en descomposici�n y de la "
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
        ({"desaparece a trav�s del agujero",
          "llega de entre la maleza",
          "Atraviesas el agujero"}));
    return 1;
}
