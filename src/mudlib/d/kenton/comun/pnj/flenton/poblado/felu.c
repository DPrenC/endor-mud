/****************************************************************************
Fichero: Felu.c
Autor: Ratwor
Fecha: 17/07/2006
Descripci�n: un kender trilero  para jugar al t�pico juego de los dedales escondiendo el guisante
****************************************************************************/

#include "./path.h"
#include <properties.h>
#include <money.h>
#include <moving.h>
#include <guild.h>
inherit NPC;
int tiene_pergamino=1;
public string ofrece_pergamino()
{
    foreach(object jug : all_inventory(environment()))
    {
        if (query_once_interactive(jug))
        {
            if (!TO->Fighting() && jug->QueryGuild()=="conjurador" && 
                tiene_pergamino==1) tell_object(jug, "Felu te dice: Estoy buscando a un "
                    "conjurador para hacer un trueque. Necesito el pergamino de oscuridad, a "
                    "cambio le dar�a el pergamino de enjambre que a m� no me hace falta.\n");
            else tell_object(jug, "Felu te mira y te sonr�e con picard�a.\n");
        }
    }
    return 0;
}

public string pregunta_trueque(){
    if (tiene_pergamino==1 && TP->QueryGuild()=="conjurador")
    return "Felu te dice: necesito hacer un trueque con unos pergaminos, me gustar�a "
    "hacer unas bromitas y para ello precisar�a utilizar el conjuro de oscuridad.\n"
    " Si me traes el pergamino para ese conjuro, yo te dar� a cambio el pergamino "
    "para el conjuro de enjambre.\n";
    return "Felu te dice: yo necesitaba hacer un trueque con unos pergaminos, pero "
    "en este momento no va a poder ser.\n";
}

public int cmd_apostar(string str){
    int jugada, apuesta;
    string *pagar;
    if (!str)
        return notify_fail("Felu te dice: apuesta por el dedal 1, por el dedal 2 o por "
        "el dedal 3.\n");
    if (str == "por el 1" || str == "por 1" || str == "1" || str == "por el dedal 1"
        || str == "por dedal 1") apuesta = 1;
    if (str == "por el 2" || str == "por 2" || str == "2" || str == "por el dedal 2"
        || str == "por dedal 2") apuesta = 2;
    if (str == "por el 3" || str == "por 3" || str == "3" || str == "por el dedal 3"
        || str == "por dedal 3") apuesta = 3;

    if (MONEY_LIB->QuerySomeonesValue(TP) < 2000){
        write ("Felu te dice: si no llevas dinerito, no descubro el guisantito.\n");
        say (CAP(TP->QueryRealName()) + " quiere apostar, pero Felu le dice que "
        "sin dinero no puede jugar.\n", TP);
        return 1;
    }
    else if (apuesta == 1 || apuesta == 2 || apuesta == 3){
        jugada = d3();

        write ("Decides apostar...\n Felu mueve los dedales entusiasmadamente "
            "dici�ndote: muy bien "+CAP(TNAME)+", muevo los dedales, muevo por aqu�,"
            " muevo por all�, a ver si adivinas d�nde he escondido el guisante...\n "
            "Elijes el dedal "+apuesta+" para tu apuesta...\n");
        say("Felu mueve los dedales animadamente, "+CAP(TNAME)+ " decide jugar "
            "apostando por el dedal " + apuesta +"...\n",TP);
        if (jugada==apuesta){
            write("Felu lo levanta con mala cara porque el guisante s� est� debajo "
            "y, resign�ndose, te paga 2 platinos por haber acertado la apuesta.\n");
            say(" y el trilero  lo levanta con mala cara porque el guisante s� est� "
            "debajo.\n  No de buena gana,  le paga 2 platinos, a "+CAP(TNAME)+
            ", por acertar la apuesta.\n", TP);
            object dinero;
            dinero = MONEY_LIB->QueryMoneyObject(TP);
            if (!dinero) { dinero = clone_object("/obj/money"); dinero->move(TP); }
            dinero->AdjustMoney((["platino":2]));
            tell_room(environment(), "\n El trilero vuelve a ocultar el guisante con el "
            "dedal y los mueve con entusiasmo para una nueva apuesta.\n\n Felu vocea:"
            " �Vamos se�ores y se�oras juguemos de nuevo a ver si aciertan d�nde "
            "escondo el guisante!, muevo por aqu�, muevo por all�, ��d�nde estar�, "
            "d�nde estar�?!\n");
            return 1;
        }else{
            write ("Felu lo levanta sonriente porque debajo no hay nada.\n El "
            "trilero te dice: �has perdido!, mira, el guisante se encontraba escondido"
            " por el dedal " + jugada + ".\n");
            say ("Felu lo levanta  sonriente y observas como est� vac�o, seguidamente "
            "muestra que el guisante se encontraba debajo del dedal "+jugada+".\n", TP);
            pagar = MONEY_LIB->PayValueString2(TP, 2000, 0, "por perder la apuesta");
            write (pagar[0]);
            say (pagar[1], TP);
            tell_room(environment(), "\n  M�s animadamente, el trilero comienza otra vez"
            " a mover los 3 dedales con la esperanza de seguir jugando.\n\n Felu vocea:"
            " �venga se�ores, que estoy de racha!, muevo y muevo los dedales para "
            "que sigan apostando, �donde estar� el guisantito, donde estar�?\n");
            return 1;
        }
    }
    return notify_fail("Felu te dice: apuesta por el dedal 1, por el dedal 2 o por "
        "el dedal 3.\n");
}

create()
{
    ::create();
    SetStandard("felu", "kender",([GC_NINGUNO:11]), GENDER_MALE);
    SetShort("Felu el trilero");
    SetLong("Felu es un kender algo tru�n y tramposo que se gana la vida haciendo de "
    "trilero, entre otras cosas m�s oscuras.\n  Lleva 3 dedales con un guisante.\n"
    " Su cara de traviesillo confirma su fama de p�caro que tiene entre sus semejantes,"
    " pues tiende a hacer ciertas bromas un tanto ingenuas.\n");
    AddId(({"Felu","trilero","felu el trilero","tramposo","truan","tru�n","travieso"}));
    SetWeight(45000);
    InitChats(8, ({"Felu mueve los dedales rapidamente de un lado a otro entren�ndose "
        "esperando a que  le digas algo.\n",
    "Felu mueve r�pidamente los dedales y dice en voz alta: busca el guisante, busca "
    "el guisante, es muy f�cil!\n", SF(ofrece_pergamino),
    "Felu dice: quieres jugar conmigo?, podemos hacer unas apuestas.\n",
    "Felu te mira con cara inquietante.\n", SF(ofrece_pergamino)}));
    AddQuestion(({"pergamino", "pergaminos", "pergamino de oscuridad",
        "pergamino de enjambre", "trueque"}), SF(pregunta_trueque),1);
    AddQuestion("guisante", "Felu te dice: yo escondo el guisante con los dedales y"
    " t� me dices d�nde lo he escondido, as� funciona el juego.\n",1);
    AddQuestion(({"dedal", "dedales"}), "Felu te dice: ya ves, s�lo son 3 dedales de "
    "madera, les tengo mucho cari�o, me hacen ganar dinerito.\n",1);
    AddQuestion(({"precio", "apuesta", "dinero"}),
        "Felu te dice: por tan solo 2 platinos puedes jugar conmigo.\n", 1);
    AddQuestion(({"juego", "jugar"}), "Felu te dice: podemos jugar a esconder el "
    "guisante con los dedales, yo los muevo rapidamente con el guisante escondido debajo "
    "de uno de ellos y t� tienes que adivinar cual es el que lo oculta escribiendo: "
    "apostar por el dedal 1, apostar por el dedal 2 o apostar por el dedal 3.\n",1);
    SetSmell("No huele mal, pero podr�a oler mejor.\n");
    SetShrugMsg("Felu dice: pos no s�.\n");
    AddSubDetail(({"dedales", "dedal", "guisante"}), "Felu lleva 3 dedales de madera y "
        "un guisante que casi debe de estar podrido.\n");
}

public void init()
{
    ::init();
    add_action("cmd_apostar", "jugar");
    add_action("cmd_apostar", "apostar");
}

public void notify_enter(mixed from,int method,mixed extra){
  if (!PO) return;
  call_out("trueque",1,PO);
}

void trueque(object ob){
    if (!ob) return;
    if (ob->id("oscuridad") && tiene_pergamino==1){
        write("Felu observa entusiasmado el pergamino y la picard�a de su cara "
        "resalta notablemente.\n Tras el an�lisssis del pergamino te dice con los "
        "ojos brillantes:\n bien, justo lo que necesitaba, aqu� tienes el pergamino de "
        "enjambre que a m� no me hace falta. \n El trilero te da un pergamino.\n");
        say(CAP(TNAME)+" y el trilero hacen un intercambio de pergaminos.\n",TP);
        object pergamino = clone_object("/guilds/conjuradores/pergamino/pergamino_enjambre");
        if (pergamino->move(TP,M_SILENT)!=ME_OK ){
            tell_room(environment(), "El pergamino se cae al suelo.\n");}
        tiene_pergamino=0;
        if (ob) destruct(ob);
        return;
    }else{
        write("Felu te dice: �me das un regalo?, que alegr�a me das, me encantan "
        "los regalos.\n No se muy bien que voy a hacer con "+ob->QueryShort()+
        ", pero lo guardar� con cari�o, muchas gracias.\n");
        say("Felu le da las gracias a "+CAP(TNAME)+" por hacerle un regalo.\n",TP);
    }
}
