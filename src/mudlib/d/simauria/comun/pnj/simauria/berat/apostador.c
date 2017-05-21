/****************************************************************************
Fichero: apostador.c
Autor: Ratwor
Fecha: 01/07/2007
Descripci�n: Un conjurador que se apuesta el pergamino de invocar victima.
****************************************************************************/
#include "./path.h"
#include <spellmonster.h>
#include <properties.h>
#include <gremios.h>
#include <combat.h>
#include <money.h>
#include <moving.h>
#include <sounds.h>
inherit SPELLMONSTER;
void aviso();
int ha_informado, tiene_pergamino;
public status check_sp();
public int magia();
public string ofrece_pergamino();
object enemigo;

string f_pregunta_pergamino(){
    if (!tiene_pergamino) return "B�stol te dice: No tengo ning�n pergamino,\n"
        " siento no poder ayudarte.\n";
    if (!ha_informado) {
        write("B�stol te mira de arriba a abajo...\nTras la inspecci�n f�sica te "
        "dice: quiz� te pueda interesar, llevo ya cierto tiempo con un pergamino encima,"
        " se trata, ni m�s ni menos, del pergamino para el conjuro 'Invocar Victima'.\n"
        "Hacemos una cosa, si te interesa el pergamino podemos apost�rnoslo. "
        "A mi me gustan las apuestas y jugar un rato, as� que si lo quieres tendr�s que "
        "apost�rtelo conmigo.\n Te explico el juego: usaremos el conjuro de invocar "
        "v�ctima, t� apostar�s por el animalito que se va a invocar al hacer el conjuro,"
        " si aciertas te doy el pergamino, si fallas me pagas 2 monedas de platino.\n"
        " Si te parece bien el trato apuesta por el animal que creas que voy a "
        "invocar.\n");
        say(CAP(TNAME)+" comenta algo con B�stol sobre una apuesta y un pergamino.\n",TP);
        ha_informado=1;
        return "B�stol te sonr�e.\n";
    }else{
        write("B�stol te dice: Si te interesa el pergamino del conjuro 'Invocar Victima',"
        " apuesta por el animal que voy a convocar al hacer el conjuro y te lo dar�.\n");
        say(CAP(TNAME)+" y B�stol concretan algo sobre un pergamino y una apuesta.\n",TP);
        return "B�stol te sonr�e.\n";
    }
}

string f_pregunta_apuesta(){
    if (!ha_informado)
        return "B�stol te dice: �A t� te gusta apostar?, a m� s�,  pero no "
        "te veo pinta de interesarte nada de lo que llevo.\n";
    return "B�stol te dice: La apuesta es simple, t� me dices que animal va a ser "
        "invocado del conjuro 'Invocar Victima'  y si aciertas te doy el pergamino, "
        "si fallas me pagas 2 platinos.\n";
}

int cmd_apostar(string str){
    string *pagar;
    string *animales = ({"ardilla", "mono", "halc�n", "cocodrilo", "tigre", "panda", "oso"});
    string invocado = animales[random(sizeof(animales))];

    if (!ha_informado || !tiene_pergamino)
        return notify_fail("B�stol te dice: �Quieres apostar?, umm me parece muy "
        "interesante, a mi me gusta mucho las apuestas, pero explicame antes de que "
        "se trata.\n");
    if (MONEY_LIB->QuerySomeonesValue(TP) < 2000)
        return notify_fail("B�stol te dice: El trato es que te apuestas 2 platinos a que"
        " aciertas la victima invocada, pero t� no llevas tanto dinero encima.\n");
    if (!str) return notify_fail("B�stol te dice: tienes que decirme el animal por el "
        "que quieres apostar seg�n pienses que voy a invocar con el conjuro.\n");
    if (str=="ardilla" || str=="mono" || str=="halc�n" || str=="cocodrilo"
        || str=="tigre" || str=="panda" || str=="oso"){
        say(CAP(TNAME)+ " quiere apostarse el pergamino con el conjurador y apuesta "
        "para que la victima invocada sea "+str+".\n",TP);
        tell_room(environment(), "B�stol procede a con jurar el conjuro Invocar "
        "Victima...\n Se agacha y escribe con el dedo runas en el suelo. A medida que "
        "acaba los trazos se van iluminando formando un c�rculo de luz.\n Al instante "
        "aparece de la nada la victima, con forma de "+invocado+", con la mirada "
        "perdida.\n Seguidamente el conjurador chasquea los dedos y la victima "
        "desaparece como si nunca hubiera existido.\n");
        play_sound(environment(TP), SND_MAGIA("conjuro"));
        if (str!=invocado){
            write("B�stol te dice animado: lo siento pero has perdido, t� dijiste que "
            "se invocar�a una victima con apariencia de "+str+" y se ha invocado con "
            "cuerpo de "+invocado+". As� que tendr�s que pagarme, pero puedes seguir "
            "apostando a ver si lo consigues.\n");
            pagar = MONEY_LIB->PayValueString2(TP, 2000, 0, "por perder la apuesta");
            write (pagar[0]);
            say (pagar[1], TP);
            return 1;
        }else{
            write("B�stol te dice sonriente: muy bien, apostaste que la victima ser�a "
            +str+" y has acertado as�  que aqu� tienes tu recompensa.\n El conjurador "
            "te entrega el pergamino.\n");
            say(CAP(TNAME)+ " ha ganado la apuesta y B�stol le entrega el pergamino.\n",TP);
            object pergamino = clone_object("/guilds/conjuradores/pergamino/pergamino_victima");
            if (pergamino->move(TP,M_SILENT)!=ME_OK ){
            tell_room(environment(), "El pergamino se cae al suelo.\n");}
            tiene_pergamino=0;
            ha_informado=0;
            return 1;
        }
    }
            return notify_fail("B�stol te dice: �no te sabes las distintas victimas que "
        "se invocan con el conjuro de 'Invocar Victima'?.\n");
}

create(){
    ::create();
   AddId(({"conjurador", "apostador", "juerguista", "bestol", "b�stol", "viajante",
        "viajero", "errante", "viejo", "anciano"}));
    SetStandard("B�stol", "humano", ([GC_MAGO:70+d6(3)]), GENDER_MALE);
    SetLong("B�stol es un viajero algo juerguista y bromista ya de edad un tanto "
        "avanzada. Se pasa sus d�as viajando y permaneciendo largas temporadas all� "
        "por donde va.\n De ojos grandes, pelo estropeado y cara arrugada se compone "
        "b�sicamente su identidad f�sica, pero ante todo no deja de sonreir, lo cual "
        "contrasta con la sensaci�n de poder y seguridad que demuestra su determinaci�n."
        " Quiz� su escasa corpulencia y su avanzzada edad s�lo sea una falsa apariencia.\n");
    SetShort("b�stol el errante");
    SetCitizenship("berat");
    AddItem("/obj/armas/baculo", REFRESH_REMOVE, SF(wieldme),
    ([P_LONG: "Es un fino b�culo de oscura madera ornamentado, en cuya parte superior "
    "hay sujeta una bola de cristal blanquecino.\n", P_WC:7]));
    AddItem(PROT("berat/tunica_bestol"), REFRESH_REMOVE,SF(wearme));
    AddItem(ARMOUR,REFRESH_REMOVE,SF(wearme),
        ([P_SHORT: "unas sandalias marrones",
        P_LONG:  "Son unas sandalias de cuero, algo usadas, pero perfectamente �tiles.\n",
        P_ARMOUR_TYPE:AT_BOOTS, P_GENDER:GENDER_FEMALE,
        P_IDS: ({"sandalias", "sandalias viejas"}), P_VALUE: 100,
        P_AC: 0, P_MATERIAL:M_CUERO,
        P_SIZE:P_SIZE_MEDIUM,
        P_RESET_QUALITY: 100, P_NUMBER: NUMBER_PLURAL,
        P_WEIGHT: 350]) );
    AddQuestion("pergamino", SF(f_pregunta_pergamino),1);
    AddQuestion(({"jugar", "juego", "apuesta", "apostar"}), SF(f_pregunta_apuesta),1);
    tiene_pergamino=1;
    InitChats(3,({"B�stol sonr�e.\n", "B�stol mira a su alrededor.\n",
        "B�stol te observa.\n", "B�stol se toca la nariz.\n",
        "B�stol te dice: tienes una mancha ah�.\n",
        "B�stol hace una mueca rara.\n", SF(ofrece_pergamino)}));
    InitAChats(7, ({"B�stol te dice: je, je, que gracioso eres!.\n",
    "B�stol se r�e de t�.\n"}));
    SetCastChance(20+d20());
    AddSpell("conjuros",
        ([
            S_CHECKFUN: SF(check_sp),
            S_FUN: SF(magia), S_SP:2,
            S_CHANCE: 40,
            S_VICTIMS: 1,
        ]));

}

init(){
    ::init();
    add_action("cmd_apostar", "apostar");
    add_action("cmd_apostar", "jugar");
}

void aviso(){
    tell_room(environment(), "B�stol se r�e a carcajada.\n");
}

mixed SetCombatDelay(int time , string s)
{
if (TP == PO) return ::SetCombatDelay(time, s);
    call_out("aviso", 1);
    return 1;
}

public status check_sp()
{
    return QuerySP()>0;
}

public int magia(){
    int pv, i;
    object *adversarios;
    adversarios = QueryEnemies();
    if(!sizeof(adversarios)) return 0;
    enemigo=adversarios[random(sizeof(adversarios))];
    switch (random(100)){
        case 0 .. 39: // lanza de �cido
            if (!TO->QuerySP() >= 10)
            break;
            TO->AddSP(-10);
            pv=QueryLevel() / 2 +d20();
            tell_room(environment(), "B�stol extiende un brazo y lo eleva por encima "
            "de su cabeza.\n Al instante, en su mano aparece una lanza de �cido que "
            "instant�neamente lanza contra " +CAP(enemigo->QueryName())+ ".\n",
            ({enemigo}));
            tell_object(enemigo, "B�stol eleva un brazo por encima de su cabeza.\n"
                "Al instante, en su mano aparece una lanza de �cido que te arroja.\n");
            enemigo->Defend(pv, DT_ACID, DEFEND_SPELL);
            play_sound(environment(TP), SND_MAGIA("lanzaacido"));
            break;
        case 40 .. 69: // meteorito.
            if (!TO->QuerySP() >= 20) break;
            tell_room(environment(), "B�stol cierra los ojos y se concentra.\n"
                "Al instante, crea una tromba de meteoritos que impactan en "
                +CAP(enemigo->QueryName()) + ".\n", ({enemigo}));
            tell_object(enemigo, "B�stol cierra los ojos y se concentra.\n"
                "Al instante, crea una tromba de meteoritos que impactan sobre ti.\n");
            pv=QueryLevel()+d20(2);
            enemigo->Defend(pv, DT_PIERCE, DEFEND_SPELL);
            TO->AddSP(-40);
            play_sound(environment(TP), SND_MAGIA("meteorito"));
            break;
        case 70 .. 99: // fr�o intenso
            if (TO->QueryHP()<15) break;
            tell_room(environment(),"B�stol levanta las manos y se concentra mirando a "
            +CAP(enemigo->QueryName()) +". Un fr�o intenso se apodera de "
            +CAP(enemigo->QueryName())+ " y ves como comienza a congelarse.\n",({enemigo}));
            tell_object(enemigo,"B�stol se concentra y notas como todos tus miembros "
            "se congelan r�pidamente.\n");
            enemigo->SetCombatDelay(d3(),"Est�s congelado.\n");
            play_sound(environment(TP), SND_MAGIA("conjuro"));
            break;
    }
    return 1;
}

public string ofrece_pergamino()
{
    foreach(object ob:all_inventory(environment()))
    {
        if (query_once_interactive(ob))
        {
            if (!Fighting() && ob->QueryGuild("conjurador") && tiene_pergamino==1 && !ha_informado)
            {
                tell_object(ob,"B�stol te dice: Tengo un pergamino para conjuradores "
                    "que quiz� pueda interesarte.\n");
                return "";
            }
        }
    }
    return "";
}