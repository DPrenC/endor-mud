/****************************************************************************
Fichero: animales_bosque.c
Autor: Ratwor
Fecha: 04/02/2007
Descripción: Varios animales para el bosque de Marhalt.
****************************************************************************/

#include "./path.h"
#include <properties.h>
#include <combat.h>
#include <sounds.h>
#include <nightday.h>
inherit NPC;
public void snd_lechuza();
public void snd_aullido();
create(){
    ::create();
    switch(d8()){
        case 1:
            SetStandard("un águila", "aguila", 14+d3(), GENDER_MALE);
            AddId(({"aguila", "águila", "ave"}));
            SetShort("un águila");
            SetLong("Es un majestuoso aguila, con unas alas enormes y un precioso "
            "plumaje. Tiene un pico robusto y afilado con el que desgarra trozos de "
            "carne de sus presas a las que atrapa firmemente con sus poderosas garras.\n");
            SetWeight(10000);
            SetHands(({({"una garra", TD_APLASTAMIENTO,0}), ({"el pico", TD_CORTE,0})}));
            InitChats(4,({SF(snd_aullido),
            "El aguila vuela majestuosamente con sus grandes alas extendidas.\n",
            (:play_sound(environment(), SND_PNJS("aguila"),0, 50); return "Chiiiiii, chiiiiii!\n";:),
            "El aguila vuela en circulos observandolo todo desde las alturas.\n"
            "El aguila pasa cerca tuya en vuelo rasante.\n"}));
            InitAChats(5,({
            "El aguila pierde algunas plumas en el combate.\n",
            "El aguila se lanza hacia ti.\n", "El aguila clava sus ojos en ti.\n"}));
            SetMsgIn("viene volando");
            SetMsgOut("se va volando");
            SetGoChance(random(120));
            if (d6()==1) SetAggressive(1);
            break;
        case 2:
            SetStandard("un jabalí", "jabali", 8, GENDER_MALE);
            AddId(({"jabali", "jabalí"}));
            SetShort("un jabalí");
            SetWeight(70000);
            SetLong("Es un animal de tamaño mediano provisto de una cabeza "
                "grande y alargada, en la que destacan unos ojos muy pequeños. El "
                "cuello es grueso y las patas son muy cortas, lo que acentúa aún "
                "más su rechoncho cuerpo, en el que es mayor la altura de los cuartos "
                "delanteros que los traseros.\n");
            InitChats(4, ({"El jabalí se rasca el lomo en un árbol.\n",
                "El jabalí come unas raíces.\n", SF(snd_aullido),
                "El jabalí olfatea el suelo.\n"}));
            SetHands(({({"un mordisco", TD_CORTE,0})}));
            SetGoChance(random(110));
            break;
        case 3:
            SetStandard("un lobo", "lobo", 9+d3(), GENDER_MALE);
            AddId(({"lobo negro", "lobo"}));
            SetShort("un lobo negro");
            SetLong("Es un lobo negro con pinta de ser extremadamente peligroso, "
            "parece que tiene mucha hambre.\n");
            SetWeight(50000);
            SetAggressive(1);
            SetHands(({({"la pata delantera derecha", TD_APLASTAMIENTO,0}),
            ({"la dentadura", TD_APLASTAMIENTO,0})}));
            InitAChats(5,({"GRRRRR....GRRRRR.\n", "El lobo gruñe ferozmente.\n",
            "El lobo aúlla con fuerza.\n"}));
            SetGoChance(random(111));
            break;
        case 4..5:
            SetStandard("un ciervo", "ciervo", 9, GENDER_MALE);
            AddId("ciervo");
            SetShort("un ciervo");
            SetLong("Es un ciervo marrón en edad adulta. Una gran cornamenta le "
            "adorna la cabeza.\n");
            SetWeight(80000);
            SetHands(({({"la pata delantera derecha", TD_APLASTAMIENTO,0}),
		    ({"la pata delantera izquierda",TD_APLASTAMIENTO,0}),
		    ({"la cornamenta", TD_APLASTAMIENTO,5})}));
            InitChats(5, ({"El ciervo te mira curioso.\n", SF(snd_aullido),
            "El ciervo mueve las orejas.\n", "El ciervo come unos arbustos.\n"}));
            SetGoChance(random(70));
            break;
        case 6:
            mixed hora = (mixed *)NIGHTDAY->QueryState();
            if (hora==ND_NIGHT || hora==ND_PREDAWN || hora==ND_DAWN){
                SetStandard("una lechuza", "ave", 4, GENDER_FEMALE);
                AddId(({"lechuza", "ave"}));
                SetShort("una lechuza");
                SetLong("Se trata de un animal de plumas oscuras y mediano porte, que "
                "sin duda habita entre los árboles de este bosque y que deja oír su ulular,"
                " sobre todo por las noches.\n");
                SetWeight(10000);
                InitChats(4, ({"La lechuza te mira con sus enormes ojos.\n",
                SF(snd_aullido), SF(snd_lechuza), "La lechuza ulula.\n"}));
                SetHands(({({"el pico", TD_APLASTAMIENTO,0})}));
                SetMsgIn("viene volando");
                SetMsgOut("se va volando");
                SetGoChance(random(50));
            }else{
                SetStandard("una ardilla", "roedor", d3(), GENDER_FEMALE);
                AddId(({"ardilla", "roedor"}));
                SetShort("una ardilla");
                SetLong("Es una alegre ardilla que juega tranquilamente subiendo y bajando "
                "de los árboles.\n  Es un pequeño roedor pacífico que sólo se preocupa de "
                "buscar su comida y sobrevivir a sus depredadores.\n");
                SetWeight(1800);
                SetHands(({({"un mordisco", TD_CORTE,0})}));
                SetMsgIn("viene corriendo");
                SetMsgOut("se va corriendo");
                InitChats(5, ({"La ardilla corretea.\n",
                "La ardilla te mira con curiosidad.\n", SF(snd_aullido),
                "La ardilla mosdisquea unas raices.\n",
                "La ardilla mueve la cabeza graciosamente.\n"}));
                SetGoChance(random(100));
            }
            break;
        case 7:
            SetStandard("una liebre", "roedor", d3(), GENDER_FEMALE);
            AddId(({"conejo", "liebre"}));
            SetShort("una liebre");
            SetLong("Es una liebre salvaje típica de bosque, con sus largas orejas y su "
            "gracioso rabo. Un buen manjar para degustar.\n");
            SetGoChance(random(60));
            SetWeight(3400);
            InitChats(3, ({"La liebre mueve las orejas curiosa.\n",SF(snd_aullido),
            "La liebre da un largo salto alejándose de tí.\n",
            "La liebre olisquea unas hierbas.\n"}));
            SetHands(({({"un mordisco", TD_CORTE,0})}));
            break;
        case 8:
            SetStandard("un lince", "felino", 6+d2(), GENDER_MALE);
            AddId("lince");
            SetShort("un lince");
            SetLong("Es un bonito lince de color pardo, parece que va buscando algo "
            "de comida.\n Es posible que no sea peligroso, pero mejor mantenerse al "
            "margen por si acaso.\n");
            SetWeight(40000);
            SetHands(({({"la pata delantera derecha", TD_APLASTAMIENTO,0}),
            ({"la dentadura",TD_APLASTAMIENTO,0})}));
            InitChats(5,({"El lince olisquea cerca de tí.\n", SF(snd_aullido),
                "El lince te mira dudoso.\n"}));
            SetGoChance(random(111));
            break;
    }
    AddWalkZones(MARH("nandor/bosque/"));
    AddId("animal");
}

public void snd_lechuza(){
    play_sound(environment(), SND_PNJS("lechuza.wav"));
}

public void snd_aullido(){
    tell_room(environment(), "Escuchas el aullido de un lobo en la distancia.\n");
    play_sound(environment(), SND_PNJS("lobo_lejano"));
}

