/***********************************************************
*    Nombre: cueva08.c			                   *
*    Localizacion: Cueva de los Trolls                     *
*    Realizada por : Cajun, el ejecutor                    *
*    Creado : 29-11-99                                     *
*    Modificado: 14-12-99  -> Funcion de caida             *
*                24-03-00  -> Rebajar la hab. de saltar    *
************************************************************/


#include "./path.h"
#include <skills.h>
#include <moving.h>
#include <combat.h>
#include <properties.h>

inherit MARHCUEVA("cueva_base");


int caida(){
    int perc;
    if (TP->QueryWeight() > 40000) {
        write("El suelo empieza a crujir y comienzas a caer por una trampa.\n");
        perc=TP->UseSkill(HAB_SALTAR, 10);

        if (perc < -80) {
            write("Intentas saltar, pero tu pie se engancha en la trampa y caes de cabeza.\n");
            say(TP->QueryName()+" se cae de cabeza por una abertura en el suelo.\n");
            tell_room(MARH("cueva/foso2"),TP->QueryName()+ " cae desde el techo de "
            "cabeza encima de los pinchos.\n");
            write("Caes encima de unos pinchos que te hacen daño.\n");
            TP->Defend(30,DT_PIERCE,DEFEND_NOMSG);
        }
        else if (perc < -19) {
            write("Intentas saltar, pero no lo consigues.\n");
            say(TP->QueryName()+" se cae por una abertura en el suelo.\n");
            tell_room(MARH("cueva/foso2"),TP->QueryName()+ " cae desde el techo encima "
            "de los pinchos.\n");
            write("Caes encima de unos pinchos que te hacen daño.\n");
            TP->move(MARH("cueva/foso2"),M_SILENT);
            TP->Defend(20,DT_PIERCE,DEFEND_NOMSG);
        }
        else if (perc < 60) {
            write("Intentas saltar y lo consigues con algunas dificultades y te golpeas "
            "contra un saliente.\n");
            say(TP->QueryName()+" salta mientras se caía por el foso y se pega contra "
            "un saliente.\n");
            tell_room(MARH("cueva/cueva07"),TP->QueryName()+ " consigue llegar a "
            "terreno firme aunque se pega contra un saliente.\n");
            write("Caes encima de unos pinchos que te hacen daño.\n");
            TP->move(MARH("cueva/cueva07"),M_SILENT);
            TP->Defend(5,DT_PIERCE,DEFEND_NOMSG);
        }else {
            write("Consigues saltar al otro lado de la trampa.\n");
            say(TP->QueryName()+" salta mientras se caía por el foso.\n");
            tell_room(MARH("cueva/cueva07"),TP->QueryName()+ " consigue llegar a "
            "terreno firme.\n");
            TP->move(MARH("cueva/cueva07"),M_SILENT);
        }
        return 1;
    }else {
        write("El suelo cruje bajo tus pies y parece que va a ceder, pero aguanta tu peso.\n");
        TP->move(MARH("cueva/cueva07"),M_GO);
        return 1;
    }
}

create () {
    ::create();
    SetIntShort("Un tramo de cueva");
    SetIntLong("La cueva se hace ligeramente más ancha en este tramo. El suelo deja de "
        "ser de piedra para convertirse en tierra durante unos pocos metros hacia el "
        "sudeste.\n");
    SetIntSmell("Un olor pestilente llega a tus narices.\n");
    AddExit("sudeste", SF(caida));
    AddExit("noroeste", "./cueva09");
}
