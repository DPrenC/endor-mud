/*****************************************************************************************
 ARCHIVO:       bosque38.c
 AUTOR:         Ztico
 FECHA:         26-04-2005
 DESCRIPCI�N:   Bosque de las Hadas.
 COMENTARIOS:   A�adir setas...
*****************************************************************************************/

#include "./path.h"

inherit BASE_HADAS;

create()
{
    if(::create()) return 1;

    SetIntShort("el Sal�n de oto�o");
    SetIntLong("Te encuentras en una peque�a habitaci�n de forma circular, tenuemente "
        "iluminada por varias velas colocadas en peque�as repisas excavadas en la "
        "pared. El ambiente aqu� es fresco y ligeramente h�medo, pero no obstante "
        "agradable. Un grueso manto de lo que parecen ser hojas marchitas cubre el "
        "suelo, y est� salpicado aqu� y all� por peque�os grupos de setas de color "
        "pardo. Las hojas, a pesar de secas, conservan un brillante colorido, una "
        "mezcla de tonos ocres, dorados y rojizos.\n");
    AddDetail(({"velas", "vela"}), "Una brisa practicamente imperceptible hace oscilar"
        "la llama de las velas en todas las direcciones.\n");
    AddDetail(({"repisa", "repisas"}), "Son cavidades del tama�o de naranjas, en cuyo "
        "interior arden velas amarillentas y anaranjadas.\n");
    AddDetail(({"pared", "paredes"}), "Las paredes no son muy altas en esta sala, "
        "y est�n iluminadas solamente por las velas.\n");
    AddDetail(({"manto", "hojas"}), "El suelo est� cubierto de hojas secas, aunque "
        "a tu alrededor no ves �rboles de los que puediran proceder.\n");
    AddDetail(({"grupos", "setas"}), "Tienen un aspecto delicioso.\n");
    SetIndoors(1);
    SetIntBright(30);

    SetIntSmell("Te llega una vaharada de olores diversos: un suave perfume como de "
        "hojas quemadas, el fresco aroma de las primeras lluvias oto�ales y un leve "
        "olor a moho y humedad.\n");
    SetIntNoise("Puedes oir alg�n suave crujido procedente de la alfombra de hojas, "
        "y el sonido del agua al gotear desde la pared de roca.\n");

    AddExit("oeste", HAB_BOSQUE_HADAS("bosque37.c"));
    AddExit("noreste", HAB_BOSQUE_HADAS("bosque42.c"));
}
