/****************************************************************************
Fichero: patio10.c
Autor: Ratwor
Fecha: 28/12/2007
Descripci�n: El patio de armas del castillo.
****************************************************************************/

#include "./path.h"
#include <properties.h>
#include <skills.h>
#include <combat.h>
#include <sounds.h>
inherit CASTILLO("patio/patio_base");
create(){
    ::create();
    SetIntShort("el patio de armas, zona de entrenamiento");
    SetIntLong("En esta zona, un amplio rect�ngulo de patio carece del "
    "empedrado habitual, sustitu�do por una fina capa de arena sobre tierra apisonada, "
    "puesto que es aqu� donde los nobles Dhes-Bl�in practican el combate a caballo "
    "entre s� o contra el estafermo levantado en uno de los extremos del rect�ngulo que "
    "forma la liza.\n"
    "Al sur se iergue el muro de la torre del homenaje, algo hacia el este ves un pozo "
    "mientras que levantado contra la muralla occidental hay un achaparrado cobertizo.\n");
    AddDetail("muro", "Enormes bloques rectangulares de piedra gris forman la parte "
    "baja del muro de la torre del homenaje.\n");
    AddDetail("arena", "Una capa de arena algo apelmazada mezclada con excrementos equinos.\n");

    AddItem(THING, REFRESH_REMOVE, ([P_SHORT: "un estafermo",
        P_LONG:"Una figura similar a un espantap�jaros. El cuerpo vagamente "
    "humano est� hecho de mimbre entretejido, en vez de cabeza tiene una especie de "
    "embudo de mimbre donde se puede encajar un yelmo para dar mas realismo a la "
    "figura, y una gruesa vara que atraviesa la parte superior del cuerpo forma los "
    "brazos. Sujeto a uno de los extremos de la vara lleva un peque�o escudo y al otro "
    "una cadena con una pesada bola met�lica en el extremo. El conjunto gira sobre un "
    "eje vertical. El objetivo de estos sencillos ingenios es hacer que los jinetes, al "
    "pasar al galope acierten con su espada o lanza al peque�o escudo esquivando al "
    "mismo tiempo el duro golpe de la cadena cuando el estafermo, propulsado  por el "
    "golpe sobre el escudo, fustigue el aire con su cadena.\n",
    P_NOGET: "Est� bien clavado al suelo.\n", P_IDS:({"estafermo", "mu�eco", "figura"})]));
    AddExit("este", "./patio11");
    AddExit("oeste",  "./patio09");
    AddExit("norte", "./patio04");
    AddExit("nordeste", "./patio05");
    AddExit("noroeste", "./patio03");
    AddRoomCmd(({"golpear", "atacar"}), "cmd_golpear");
}

public int cmd_golpear(string str){
    if(!str) return notify_fail("�A qui�n o a qu�?\n");
    if(str=="mu�eco" || str=="estafermo" || str=="a mu�eco" || str=="a estafermo"
        || str=="escudo" || str=="escudo de estafermo" || str=="escudo de mu�eco"){
        if(TP->QuerySize()>P_SIZE_SMALL){
            if (TP->QueryTP()>1){
                write("Golpeas con fuerza en el escudo del estafermo...\n");
                say(CAP(TNAME)+" golpea con fuerza en el escudo del estafermo...\n");
                TP->AddTP(-d2());
                play_sound(TO, SND_SUCESOS("golpe_metalico"));
                if (!TP->HasSkill(HAB_ESQUIVAR) || TP->UseSkill(HAB_ESQUIVAR) < 0){
                    write("Intentas esquivar el golpe que te devuelve, pero eres demasiado "
                    "torpe y te acierta de lleno.\n");
                    say("Pero torpemente recibe el golpe que le devuelve por no saber "
                    "esquivarlo.\n");
                    TP->Defend(TP->QueryStr()*2,TD_APLASTAMIENTO,DEFEND_NOMSG);
                    play_sound(TO, SND_SUCESOS("caida_fuerte"));
                    return 1;
                }else{
                    write("Y consigues esquivar el golpe que te devuelve.\n");
                    say("Y consigue esquivar el golpe que le devuelve.\n");
                    return 1;
                }
            }
            return notify_fail("Has agotado tus fuerzas, descansa un rato.\n",NOTIFY_NOT_VALID);
        }
        return notify_fail("Tu tama�o es demasiado peque�o como para llegar al escudo "
        "del estafermo para golpearlo.\n", NOTIFY_NOT_VALID);
    }
    return 0;
}

