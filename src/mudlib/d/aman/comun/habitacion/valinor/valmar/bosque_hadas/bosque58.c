/*****************************************************************************************
 ARCHIVO:       bosque58.c
 AUTOR:         Ztico
 FECHA:         26-04-2005
 DESCRIPCIÓN:   Bosque de las Hadas.
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
    SetIntLong("Ops, mala suerte, una enorme tela de araña te impide continuar el "
        "camino hacia el norte. Hay un misterioso agujero excavado en el suelo, "
        "similar a la boca de un pozo, y te llama la atención un letrero de madera "
        "fijado a la pared, con unas líneas trazadas en él, por desgracia totalmente "
        "ilegibles para tí.\n");
    AddDetail(({"tela", "telaraña", "telaranya"}), "Su moradora debe ser por lo menos "
        "del tamaño de una oveja. Empieza a ser peligroso continuar en este "
        "corredor.\n");
    AddDetail(POZO, "Te asomas y no consigues distinguir el final, parece que es "
        "bastante profundo.\n");
    AddDetail("letrero", "Está escrito en algún tipo de lenguaje indescifrable "
        "para tí.\n");
    AddDetail(({"lineas", "líneas"}), "No hay forma de concebir lo que está escrito, "
        "quizás sea algo relacionado con el pozo...\n");
    AddDetail("suelo", "");
    AddReadMsg(({"letrero", "líneas", "lineas"}), "Ciertamente no entiendes nada de "
    "lo que pone, quizá sea alguna indicación sobre el pozo.\n");
    SetIndoors(1);
    SetIntBright(20);

    AddRoomCmd("saltar", "cmd_saltar");

    AddExit("sur", HAB_BOSQUE_HADAS("bosque53.c"));
}

int cmd_saltar(string str)
{
    object pl;

    if(!str || member(POZO, str) < 0)
        return notify_fail("¿Saltar <dónde>?\n", NOTIFY_NOT_OBJ);
    pl = TP;
    pl->SetHP((pl->QueryHP())/4); //Se hace pupita en la caida...
    pl->move(HAB_BOSQUE_HADAS("pozo.c"), M_SPECIAL,
        ({"da un salto hacia delante y ¡¡Plof!! Desaparece",
          "cae desde las alturas",
          "Te acercas a la boca del agujero y sin pensártelo más veces das un "
          "salto\n y te tiras al pozo...\nTe das cuenta de que estás descendiendo "
          "por una especie de rampa sinuosa....\nCaes en una sala oscura y todo "
          "tu cuerpo está lleno de magulladuras"}));
    return 1;

}
