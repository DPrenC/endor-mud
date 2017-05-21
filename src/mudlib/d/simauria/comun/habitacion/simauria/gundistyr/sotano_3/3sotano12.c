/* *********************************************************************** */
/* *                                                                     * */
/* *      ARCHIVO: 3sotano12.c                                           * */
/* *      AUTOR: [a] Articman                                            * */
/* *      MODIFICADO: 23/1/02 [a] Creación                               * */
/* *                                                                     * */
/* *********************************************************************** */

#include "./path.h"

inherit SIM_ROOM;

create(){
    ::create();
    SetIntShort("la base kobold");
    SetIntLong("Estás al final de un pasillo que se extiende al este. Hacia el "
    "oeste hay un agujero cubierto por una vieja puerta de madera podrida por el ambiente.\n"
    "Un par de antorchas cuelgan de las ennegrecidas paredes .\n");

    AddDetail(({"pasillo","pasillo piedra","pasillo de piedra"}),"Estás en un "
    "pequeño pasillo rodeado de piedra.\n");

    AddDetail(({"suelo","suelos"}),"Puedes pisar el suelo con bastante firmeza"
    "sin correr el riesgo de caerte. Por esta zona parece que está más liso.\n");

    AddDetail(({"pared","paredes"}),"Las paredes de dura roca están negras a "
    "causa del humo de las antorchas y la falta de una salida de aire.\n");

    AddDetail(({"techo","techos"}),"Sobre tu cabeza ves algunos maderos que "
    "apuntalan los techos para evitar desprendimientos. Es sin lugar a dudas "
    "una señal de vida cercana.\n");

    AddDetail(({"antorcha", "antorchas","antorcha de pared","antorcha pared",
        "antorchas de pared"}),
    "Unas antorchas encendidas están a ambos lados de la pared de piedra. "
    "Desprenden un humo muy negro.\n");

    SetIntSmell("Aspiras el aire y te llega un olor nauseabúndo.\n");
    SetIntNoise("Unos chillidos retumban por las paredes de la cueva.\n");
    SetIntBright(20);

    AddExit("este","3sotano13");
    AddExit("oeste", "./3sotano11");
    AddDoor("oeste", "una puerta destartalada",
    "Es una vieja puerta podrida por el tiempo y la humedad del lugar.\n",
    ({"puerta", "puerta vieja", "vieja puerta", "puerta destartalada", "puerta del oeste"}));
    AddItem(PNJGD("gkob"),REFRESH_REMOVE,2);
    AddItem(PNJGD("kob"),REFRESH_REMOVE,d4());

}
int cmd_gritar(string str) {
    write("Te dispones a gritar, pero de pronto piensas que eso podría atraer a gran "
    "multitud de seres con lo que desechas la idea.\n");
    say(CAP(TNAME)+" parece que va a hacer algo pero se "
    "hecha atrás.\n");
    return 1;
}

init(){
    ::init();
    add_action("cmd_gritar","gritar");
}
