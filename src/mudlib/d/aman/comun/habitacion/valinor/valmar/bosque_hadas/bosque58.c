/*****************************************************************************************
 ARCHIVO:       bosque58.c
 AUTOR:         Ztico
 FECHA:         26-04-2005
 DESCRIPCI�N:   Bosque de las Hadas.
 COMENTARIOS:
*****************************************************************************************/

#include "./path.h"
#include <moving.h>
#define POZO ({"agujero", "pozo", "boca", "al pozo", "al agujero"})

inherit BASE_HADAS;

int cmd_saltar(string str);

create()
{
    if(::create()) return 1;

    SetIntShort("el corredor norte");
    SetIntLong("Ops, mala suerte, una enorme tela de ara�a te impide continuar el "
        "camino hacia el norte. Hay un misterioso agujero excavado en el suelo, "
        "similar a la boca de un pozo, y te llama la atenci�n un letrero de madera "
        "fijado a la pared, con unas l�neas trazadas en �l, por desgracia totalmente "
        "ilegibles para t�.\n");
    AddDetail(({"tela", "telara�a", "telaranya"}), "Su moradora debe ser por lo menos "
        "del tama�o de una oveja. Empieza a ser peligroso continuar en este "
        "corredor.\n");
    AddDetail(POZO, "Te asomas y no consigues distinguir el final, parece que es "
        "bastante profundo.\n");
    AddDetail("letrero", "Est� escrito en alg�n tipo de lenguaje indescifrable "
        "para t�.\n");
    AddDetail(({"lineas", "l�neas"}), "No hay forma de concebir lo que est� escrito, "
        "quiz�s sea algo relacionado con el pozo...\n");
    AddDetail("suelo", "");
    AddReadMsg(({"letrero", "l�neas", "lineas"}), "Ciertamente no entiendes nada de "
    "lo que pone, quiz� sea alguna indicaci�n sobre el pozo.\n");
    SetIndoors(1);
    SetIntBright(20);

    AddRoomCmd("saltar", "cmd_saltar");

    AddExit("sur", HAB_BOSQUE_HADAS("bosque53.c"));
}

int cmd_saltar(string str)
{
    object pl;

    if(!str || member(POZO, str) < 0)
        return notify_fail("�Saltar <d�nde>?\n", NOTIFY_NOT_OBJ);
    pl = TP;
    pl->SetHP((pl->QueryHP())/4); //Se hace pupita en la caida...
    pl->move(HAB_BOSQUE_HADAS("pozo.c"), M_SPECIAL,
        ({"da un salto hacia delante y ��Plof!! Desaparece",
          "cae desde las alturas",
          "Te acercas a la boca del agujero y sin pens�rtelo m�s veces das un "
          "salto\n y te tiras al pozo...\nTe das cuenta de que est�s descendiendo "
          "por una especie de rampa sinuosa....\nCaes en una sala oscura y todo "
          "tu cuerpo est� lleno de magulladuras"}));
    return 1;

}
