/****************************************************************************
Fichero: animales_bosque.c
Autor: Ratwor
Fecha: 18/08/2007
Descripción: Varios animales para los bosques de Goldhai.
****************************************************************************/

#include "./path.h"
#include <properties.h>
#include <combat.h>
inherit NPC;

create(){
    ::create();
    switch(d8()){
        case 1:
            AddId("golondrina");
            SetStandard("una golondrina", "ave", 4+d3(), GENDER_FEMALE);
            SetShort("una bonita golondrina");
            SetLong("Es la típica golondrina que vive cerca de la costa,  siempre vuela "
            "a gran velocidad y sin miedo por encima de las cabezas de la gente.\n");
            SetWeight(600);
            SetHands(({({"el pico",0,3})}));
            InitChats(4,({
            "la golondrina vuela alegremente.\n",
            "la golondrina vuela en circulos sobre tu cabeza.\n",
            "la golondrina pasa cerca tuya en vuelo rasante.\n"}));
            InitAChats(5,({
            "La golondrina se lanza hacia ti.\n", "La golondrina clava sus ojos en ti.\n"}));
            SetMsgIn("viene volando");
            SetMsgOut("se va volando");
            SetGoChance(random(120));
        break;
        case 2:
            AddId(({"ardilla", "roedor"}));
            SetStandard("una ardilla", "roedor", d3(), GENDER_FEMALE);
            SetShort("una ardilla");
            SetLong("Es una alegre ardilla que juega tranquilamente subiendo y bajando "
            "de los árboles.\n  Es un pequeño roedor pacífico que sólo se preocupa de "
            "buscar su comida y sobrevivir a sus depredadores.\n");
            SetWeight(800);
            SetHands(({({"un mordisco",0,1})}));
            SetMsgIn("viene corriendo");
            SetMsgOut("se va corriendo");
            InitChats(5, ({"La ardilla corretea.\n",
            "La ardilla te mira con curiosidad.\n",
            "La ardilla mordisquea unas raíces.\n",
            "La ardilla mueve la cabeza graciosamente.\n"}));
            SetGoChance(random(100));
        break;
        case 3:
            AddId(({"lobo", "lobo marrón", "lobo marron"}));
            SetStandard("un lobo", "lobo", 7+d3(), GENDER_MALE);
            SetShort("un lobo marrón");
            SetLong("Es un lobo marrón con pinta de ser extremadamente peligroso, "
            "parece que tiene mucha hambre.\n");
            SetWeight(50000);
            SetHands(({({"pata delantera derecha",0,10}),
            ({"boca",0,10})}));
            InitChats(5,({"GRRRRR....GRRRRR.\n", "El lobo gruñe ferozmente.\n",
            "El lobo aúlla con fuerza.\n"}));
            SetGoChance(random(111));
            if (d20()==1) SetAggressive(1);
        break;
        case 4..5:
            AddId("cabra");
            SetStandard("una ccabra", "cabra", 7, GENDER_FEMALE);
            SetShort("una cabra");
            SetLong("Es una cabra de color negro con algunas zonas blancas, unos "
            "pequeños cuernos le adornan graciosamente la cabeza.\n");
            SetWeight(45000);
            SetHands(({({"la pata delantera derecha",0,1}),
		    ({"los cuernos",0,3})}));
            InitChats(5, ({"La cabra te mira curiosa.\n",
            "la cabra mueve las orejas.\n", "La cabra come unos arbustos.\n"}));
            SetGoChance(random(70));
        break;
        case 6:
            AddId("buho");
            SetStandard("un buho", "ave", 6, GENDER_FEMALE);
            SetShort("un buho");
            SetLong("Se trata de un animal de plumas oscuras y mediano porte, que "
            "sin duda habita entre los árboles de este bosque y que deja oír su ulular,"
            " sobre todo por las noches.\n");
            SetWeight(5000);
            InitChats(3, ({"El buho te mira con sus enormes ojos.\n",
            "El buho ulula.\n"}));
            SetHands(({({"el pico",0,6})}));
            SetMsgIn("viene volando");
            SetMsgOut("se va volando");
            SetGoChance(random(50));
        break;
        case 7:
            AddId(({"conejo", "liebre"}));
            SetStandard("una liebre", "roedor", d3(), GENDER_FEMALE);
            SetShort("una liebre");
            SetLong("Es una liebre salvaje típica de bosque, con sus largas orejas y su "
            "gracioso rabo. Un buen manjar para degustar.\n");
            SetGoChance(random(100));
            SetWeight(1300);
            InitChats(3, ({"La liebre mueve las orejas curiosa.\n",
            "La liebre da un largo salto alejándose de tí.\n",
        "La liebre olisquea unas hierbas.\n"}));
            SetHands(({({"un mordisco",0,1})}));
        break;
        case 8:
            AddId("zorro");
            SetStandard("un zorro", "zorro", 5+d2(), GENDER_MALE);
            SetShort("un zorro");
            SetLong("Es un curioso zorro de color pardo, parece que va buscando algo "
            "de comida.\n Es posible que no sea peligroso, pero mejor mantenerse al "
            "margen por si acaso.\n");
            SetWeight(40000);
            SetHands(({({"pata delantera derecha",0,10}),
            ({"boca",0,10})}));
            InitChats(5,({"El zorro olisquea cerca de tí.\n",
                "El zorro te mira dudoso.\n"}));
            SetGoChance(random(111));
        break;
    }
    AddWalkZones(({BNORTE(""), BOSCURO(""), BWALD("")}));
    AddId("animal");
}
