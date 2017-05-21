/* *********************************************************************** */
/* *                                                                     * */
/* *      ARCHIVO: 3sotano24.c                                           * */
/* *      AUTOR: [a] Articman                                            * */
/* *      MODIFICADO: 23/1/02 [a] Creación                               * */
/* *                                                                     * */
/* *********************************************************************** */

#include "./path.h"

inherit SIM_ROOM;

create(){
    ::create();
    SetIntShort("la base kobold");
    SetIntLong("Piedras, rocas y humedad. El paisaje de estas cuevas es muy "
    "aburrido, ninguna sala se diferencia de las demás, y las estrechas paredes "
    "dan una continua sensación de claustrofóbia.\n Pegadas a las paredes ves unas "
    "gruesas maderas que llegan hasta el techo, así como unas viejas antorchas "
    "que le dan una leve iluminación a la sala. El camino tiene 2 bifurcaciones, "
    "una al oeste y otra hacia el sur. Al nordeste de aquí ves una puerta.\n");

    AddDetail(({"suelo","suelos"}),"Puedes pisar el suelo con bastante firmeza"
    "sin correr el riesgo de caerte. Además parece que "
    "está más liso.\n");

    AddDetail(({"pared","paredes"}),"Las paredes de dura roca están negras a "
    "causa del humo de las antorchas y la falta de una salida de aire.\n");

    AddDetail(({"techo","techos"}),"Sobre tu cabeza ves algunos maderos que "
    "apuntalan los techos para evitar desprendimientos. Es sin lugar a dudas "
    "una señal de vida cercana.\n");

    AddDetail(({"antorchas", "antorcha", "antorcha de pared","antorcha pared","antorchas de pared"}),
    "Unas antorchas encendidas están a ambos lados de la pared de piedra. "
    "Desprenden un humo muy negro.\n");

    SetIntSmell("Aspiras el aire y te llega un olor nauseabúndo.\n");
    SetIntNoise("Unos chillidos retumban por las paredes de la cueva.\n");

    AddDetail(({"madera","maderas","gruesas maderas","maderas gruesas"}),"Unos "
    "gruesos maderos están pegados a la pared y ascienden hasta el techo, donde "
    "otro madero conecta las dos paredes . Sin duda alguien ha apuntalado este "
    "techo.\n");

    SetIntBright(20);

    AddExit("sur","3sotano28");
    AddExit("oeste","3sotano23");
    AddExit("nordeste", "./3sotano21");
    AddDoor("nordeste", "una vieja puerta",
    "Es una puerta tan vieja como el resto de maderas que te acompañan en todo momento.\n",
    ({"puerta", "puerta de madera", "vieja puerta", "puerta vieja", "puerta del nordeste"}));
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
