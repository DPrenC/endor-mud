/********************
Fichero: gadline.c
Autor: Lug y Yalin.
Descripci�n: kisala exploradora que entregar� el pergamino de visi�n nocturna.
Fecha: 16/09/2007, 12:27
********************/
#include "path.h"
#include <spellmonster.h>
#include <guild.h>
#include <moving.h>
#include <messages.h>
#include <combat.h>
#include <magicd.h>
#include <properties.h>

inherit SPELLMONSTER;

#define ART(x)   (x->QueryGender()==GENDER_FEMALE?"a":"o")


//funciones
int cegando();

void recoger_(object vial, object pl)
{
    string nombre = vial->QueryShort();
    if (!pl) return;
    if (pl->QueryGender() == 1)
    {
        write("Gadline te mira burlona, y con voz despectiva dice: ");
        say("Gadline mira a "+capitalize(pl->QueryName())+", y con desprecio le dice: ",pl);
        say("No necesito nada de ti. No te he pedido nada. �Para que me das "+nombre+"? Todos "
            "los machos sois iguales, pens�is que pod�is conseguir lo que quer�is con una "
            "chucher�a.\nY alzando con rabia "+nombre+", lo arroja lejos.\n");
        vial->remove();
        if (vial) destruct(vial);
        return;
    }
// si no es la poci�n o no se la ha pedido
    if (!pl->QueryAttribute("p_gadline") || member(vial->QueryIds(),"pocion_gadline") <0)
    {
        write("Gadline te sonr�e dulcemente diciendo: ");
        say("Gadline le sonr�e dici�ndo: ",pl);
        say("Gracias, "+capitalize(pl->QueryName())+", pero no me interesa "+nombre+". Lo poco "
            "que un aventurero necesita, se puede encontrar por el mundo. Mejor gu�rdalo para "
            "mejor ocasi�n.\n");
        write("Y amablemente, te devuelve "+nombre+".\n");
        say("Y amablemente, le devuelve "+nombre+".\n",pl);
        if (!vial->move(pl)) vial->move(environment());
        return;
    }
    pl->RemoveAttribute("p_gadline");
    pl->SetAttribute("h_gadline",time());
    say("Los ojos de Gadline se llenan de ansiedad al ver el vial que tiene en las manos.\nSin "
        "perder un momento rompe un extremo y se bebe el contenido.\nCon un suspiro de "
        "satisfacci�n, arroja el tubo vac�o, y dice: Bien, "+capitalize(pl->QueryName())+". Lo "
        "prometido es deuda. Me has hecho un gran favor, as� que, aqu� tienes tu recompensa.\n");
    SetHP(QueryMaxHP());
    vial->remove();
    if (vial) destruct(vial);
    object perga=clone_object("/guilds/kisalas/pergamino/pergamino_vision_nocturna");
    if (!perga->move(pl)) perga->move(environment());
    write("Gadline te da un pergamino antiguo.\n");
    say("Gadline da un pergamino antiguo a "+capitalize(pl->QueryName())+".\n",pl);
    return;
}

string dialogo()
{
    foreach(object jug : all_inventory(environment()))
    {
        if (query_once_interactive(jug))
        {
            switch (d3())
            {
                case 1:
                    if (jug->QueryGuild() == GC_KISALA) tell_object(jug,"Gadline te pregunta: "
                        "�Has visto �ltimamente a la buena de Gaena? -Gadline se r�e "
                        "maliciosamente. �Sigue tan orgullosa y..., ejem..., brusca?\n");
                    else if (jug->QueryGender() == 2) tell_object(jug,"Gadline te pregunta: Y "
                        "dime, �Algo de inter�s por el mundo �ltimamente? Hace mucho que no "
                        "paro en una ciudad.\n");
                    else tell_object(jug,"Gadline te hace una mueca ir�nica mientras te dice: "
                        "�Y t� qu� haces por aqu�? �C�mo es que no est�s matando y bebiendo? "
                        "Eso es lo �nico que sab�is hacer los machos, �no?\n");
                break;
                case 2:
                    if (jug->QueryGender() == 1) tell_object(jug,"Gadline te apunta con el "
                        "dedo y te dice: Bueno, �piensas quedarte a vivir aqu�?\n");
                    else tell_object(jug,"Gadline sonr�e y te pregunta: �T� tambi�n est�s "
                        "explorando? Esta regi�n es muy interesante, �sabes?\n");
                break;
                case 3:
                    if (jug->QueryGender() == 1) tell_object(jug,"Gadline hace un gesto de "
                        "impaciencia dici�ndote: �Por qu� no sigues tu camino?\n");
                    else if (jug->QueryAttribute("h_gadline")) tell_object(jug,"Gadline te "
                        "sonr�e diciendo: Ah, "+capitalize(jug->QueryName())+". Me alegro de "
                        "ver que sigues viv"+ART(jug)+". yo, gracias a ti sigo mis aventuras.\n");
                    else if (jug->QueryAttribute("p_gadline")) tell_object(jug,"Gadline te "
                        "mira suplicante y dice: Por favor, date prisa, necesito esa poci�n.\n");
                    else tell_object(jug,"Gadline te mira fijamente y dice: �Sabes? Tengo un "
                        "peque�o problema. �Podr�as hacerme un favor? Te recompensar�a. Si "
                        "est�s interesada, preg�ntame.\n");
                break;
            }
        }
    }
    return 0;
}

public string informa()
{
    if (TP->QueryGender() == 1) return"Gadline te dice: No es asunto tuyo. Sigue tu camino y no "
        "molestes.\n";
    if (TP->QueryAttribute("h_gadline")) return "Gadline te sonr�e dulcemente diciendo: No "
        "necesito nada ya. Gracias a ti puedo seguir explorando el mundo. �Sabes? Es lo que "
        "m�s me gusta, la aventura.\n";
    if (TP->QueryAttribute("p_gadline")) return "gadline suspira y dice: Ya te lo he dicho, "
        "�Qu� m�s quieres saber? S�lo necesito eso, por favor ve a buscarlo.\n";
    object obj=clone_object(OTRO("papel_g"));
    obj->SetOwner(TP->QueryRealName());
    if (!obj->move(TP)) obj->move(environment());
    TP->SetAttribute("p_gadline",time());
    say("Gadline le da un papel con algo escrito.\n",TP);
    return"Gadline te dice: Ver�s, he tenido una pelea con un par de individuos y estoy herida. "
        "En la vecina ciudad de Zarkam hay un curandero experto en pociones curativas, pero en "
        "mi estado no me atrevo a ir hasta all�. Si fueras tan amable de ir a buscarme una "
        "poci�n, te lo agradecer�a, y te recompensar�a. En este papel te pongo lo que necesito, "
        "el curandero sabr� lo que quiero.\nGadline te da un papel con algo escrito.\n";
}

reset()
{
    ::reset();
    SetHP(QueryMaxHP()-100);
}

create()
{
    ::create();
    SetStandard("Gadline","humano",([ GC_KISALA:30+d8() ]),GENERO_FEMENINO);
    SetName("Gadline");
    AddId(({"Gadline","gadline","humana","kisala","exploradora","exploradora kisala","kisala exploradora"}));
    SetShort("Gadline, la exploradora");
    SetLong("Gadline es una aguerrida kisala que un d�a sinti� la llamada del gran mundo, y se "
        "lanz� a la aventura, a conocer cada rinc�n, a explorar la tierra y descubrir sus "
        "secretos.\nEs una humana de ojos negros y mirada penetrante, de pelo ensortijado y "
        "casta�o y un semblante risue�o, aunque curtido y atemperado por las muchas cosas que "
        "ha visto, los muchos lugares y climas que ha vivido, conocido y soportado, y las mil "
        "aventuras pasadas.\n");
    SetHP(QueryMaxHP()-100);
    SetWhimpy(30); //es valiente, no est�pida, m�s bien astuta.
    SetSpellChance(1000);
    AddSpell("luz cegadora",
        ([
            S_FUN: SF(cegando),
            S_SP:2,
            S_CHANCE: 1000,
            S_VICTIMS: 1,
        ]));
    AddQuestion(({"problema","favor"}),SF(informa),1);
    AddQuestion(({"curandero"}),"Gadline te dice: El �nico curandero que yo conozco vive en "
        "Zarkam, ahora no recuerdo d�nde, hace mucho tiempo que visit� la ciudad, pero no debe "
        "ser dif�cil encontrarle.\n");
    SetShrugMsg("Gadline dice: Ufs, ni idea.\n");
    SetGoChance(20);
    AddWalkZones("/d/akallab/comun/habitacion/akallab/zarkam/bosque");
    AddItem("/guilds/conjuradores/obj/vara_metal",REFRESH_REMOVE,SF(wieldme));
    InitChats(10,
        ({"Gadline mueve la cabeza diciendo: No s� d�nde ir ahora, aqu� ya lo he visto todo.\n",
        "Gadline hace un gesto de asentimiento y dice: Tal vez visite Sherek, aunque dicen que "
            "no es gran cosa...\n",
        "Gadline te mira de arriba a abajo y frunce el ce�o.\n",
        SF(dialogo)
    }));
}

// [Nyh] Hago una superchapuza para que funcione el hechizo de luz
// Por dios, que NADIE lo copie pensando que esto mola, porque es una mierda
public int HasSpell(string name) {
  if (name == "luz cegadora") return 1;
  return 0;
}

public varargs UseSpell(string name) {
  if (name == "luz cegadora") return 1;
  return 0;
}

int cegando()
{
  object *adversarios, pSpellTo;
  string fichero;

  if (!sizeof(adversarios = QueryEnemies())) return 0;

  if (!sizeof(fichero = MAGICD->QueryFileSpell("luz cegadora"))) return 0;

  pSpellTo = adversarios[random(sizeof(adversarios))];

  fichero->main(TO, "contra "+pSpellTo->QueryName());

  return 0;
}

public int QueryGadline() { return 1; }

void notify_enter(mixed from,int method,mixed extra)
{
	  if (method == M_GIVE) call_out("recoger_",1,PO,from);
}
