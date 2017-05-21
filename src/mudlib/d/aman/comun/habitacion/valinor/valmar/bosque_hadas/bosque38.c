/*****************************************************************************************
 ARCHIVO:       bosque38.c
 AUTOR:         Ztico
 FECHA:         26-04-2005
 DESCRIPCIÓN:   Bosque de las Hadas.
 COMENTARIOS:   Añadir setas...
*****************************************************************************************/

#include "./path.h"

inherit BASE_HADAS;

create()
{
    if(::create()) return 1;

    SetIntShort("el Salón de otoño");
    SetIntLong("Te encuentras en una pequeña habitación de forma circular, tenuemente "
        "iluminada por varias velas colocadas en pequeñas repisas excavadas en la "
        "pared. El ambiente aquí es fresco y ligeramente húmedo, pero no obstante "
        "agradable. Un grueso manto de lo que parecen ser hojas marchitas cubre el "
        "suelo, y está salpicado aquí y allá por pequeños grupos de setas de color "
        "pardo. Las hojas, a pesar de secas, conservan un brillante colorido, una "
        "mezcla de tonos ocres, dorados y rojizos.\n");
    AddDetail(({"velas", "vela"}), "Una brisa practicamente imperceptible hace oscilar"
        "la llama de las velas en todas las direcciones.\n");
    AddDetail(({"repisa", "repisas"}), "Son cavidades del tamaño de naranjas, en cuyo "
        "interior arden velas amarillentas y anaranjadas.\n");
    AddDetail(({"pared", "paredes"}), "Las paredes no son muy altas en esta sala, "
        "y están iluminadas solamente por las velas.\n");
    AddDetail(({"manto", "hojas"}), "El suelo está cubierto de hojas secas, aunque "
        "a tu alrededor no ves árboles de los que puediran proceder.\n");
    AddDetail(({"grupos", "setas"}), "Tienen un aspecto delicioso.\n");
    SetIndoors(1);
    SetIntBright(30);

    SetIntSmell("Te llega una vaharada de olores diversos: un suave perfume como de "
        "hojas quemadas, el fresco aroma de las primeras lluvias otoñales y un leve "
        "olor a moho y humedad.\n");
    SetIntNoise("Puedes oir algún suave crujido procedente de la alfombra de hojas, "
        "y el sonido del agua al gotear desde la pared de roca.\n");

    AddExit("oeste", HAB_BOSQUE_HADAS("bosque37.c"));
    AddExit("noreste", HAB_BOSQUE_HADAS("bosque42.c"));
}
