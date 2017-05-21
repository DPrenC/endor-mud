/* *********************************************************************** */
/* *                                                                     * */
/* *      ARCHIVO: 3sotano21.c                                           * */
/* *      AUTOR: [a] Articman                                            * */
/* *      MODIFICADO: 26/01/02 [a] Creación                               * */
/* *                                                                     * */
/* *********************************************************************** */
#include "./path.h"
inherit SIM_ROOM;

create() {
    ::create();
    SetIntShort("la base kobold");
   SetIntLong("Estás en lo que parece una especie de almacén de armas. Aqui "
    "debe ser donde los kobolds dejan sus armas cuando no las llevan encima. "
    "Esto demuestra el poco valor de sus armas ya que nadie tiene una propia. "
    "Ves amontonados gran cantidad de armas en una estanteria y en el suelo, "
    "aunque no ves nada que te llame especialmente la atención. Al suroeste "
    "observas una puerta.\n");

    SetIntBright(20);
    SetIntSmell("Aspiras el aire y te llega un olor nauseabúndo.\n");
    SetIntNoise("Unos chillidos retumban por las paredes de la cueva.\n");

    AddDetail(({"estanteria","estante","estantes"}),"Son unas estanterías de madera "
    "podrida a causa del tiempo y la humedad.\n");
    AddItem(GOBJETO("arma/gundistyr/arma1"),random(5));
    AddItem(GOBJETO("arma/gundistyr/arma_guardias1"),d2());
    AddItem(GOBJETO("arma/gundistyr/misericordia"),1);
    AddExit("suroeste", "./3sotano24");
    AddDoor("suroeste", "una vieja puerta",
    "Es una puerta tan vieja como el resto de maderas que te acompañan en todo momento.\n",
    ({"puerta", "puerta de madera", "vieja puerta", "puerta vieja", "puerta del suroeste"}));
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
