/* *********************************************************************** */
/* *                                                                     * */
/* *      ARCHIVO: 3sotano11.c                                           * */
/* *      AUTOR: [a] Artic                                               * */
/* *      MODIFICADO: 23/1/02 [a] Creación                               * */
/* *                                                                     * */
/* *********************************************************************** */

#include "./path.h"

inherit SIM_ROOM;

create(){
    ::create();
    SetIntShort("la base kobold");
    SetIntLong("A tu alrededor observas gran cantidad de nichos, dispuestos de "
    "forma irregular, en la amplísima sala en la que te encuentras.\n Sobre algunos "
    "de ellos observas a kobolds durmiendo, pese a que toda la sala esté iluminada "
    "por las antorchas que prenden de la pared.\n");

    AddDetail(({"nicho","nichos","cama","camas"}),
    "No es más que un montón de paja cubierta por  una sucia manta.\n");

    AddDetail(({"suelo","suelos"}),
    "En esta parte el suelo parece más liso.\n");

    AddDetail(({"pared","paredes"}),"Las paredes de dura roca están negras a "
    "causa del humo de las antorchas y la falta de una salida de aire.\n");

    AddDetail(({"techo","techos"}),"Sobre tu cabeza ves algunos maderos que "
    "apuntalan los techos para evitar desprendimientos. Es sin lugar a dudas "
    "una señal de vida cercana.\n");

    AddDetail(({"antorchas","antorcha de pared","antorcha pared","antorchas de pared"}),
    "Unas antorchas encendidas están a ambos lados de la pared de piedra. "
    "Desprenden un humo muy negro.\n");

    SetIntSmell("Aspiras el aire y te llega un olor nauseabúndo.\n");
    SetIntNoise("Unos chillidos retumban por las paredes de la cueva.\n");
    SetIntBright(20);

    AddExit("oeste","./3sotano10");
    AddExit("norte","./3sotano07");
    AddExit("sur","./3sotano17");
    AddExit("noroeste","./3sotano06");
    AddExit("suroeste","./3sotano16");
    AddExit("este", "./3sotano12");
    AddDoor("este", "una puerta destartalada",
    "Es una vieja puerta podrida por el tiempo y la humedad del lugar.\n",
    ({"puerta", "puerta vieja", "vieja puerta", "puerta destartalada", "puerta del este"}));
    AddItem(PNJGD("kobduerme"),REFRESH_REMOVE);
}

int cmd_gritar(string str) {
    write("Te dispones a gritar, pero de pronto piensas que eso podría atraer a gran "
    "multitud de seres con lo que desechas la idea.\n");
    say(CAP(TNAME)+" parece que va a hacer algo, pero se "
    "hecha atrás.\n");
    return 1;
}

init(){
    ::init();
    add_action("cmd_gritar","gritar");
}
