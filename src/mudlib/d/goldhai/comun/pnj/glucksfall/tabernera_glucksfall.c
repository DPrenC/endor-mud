        /****************************************************************************
Fichero: tabernera_glucksfall.c
Autor: Buh
Fecha: 30/08/2006
Descripción: La tabernera de la tabernna Mi hacha me acompaña.
****************************************************************************/


#include "./path.h"
#include <properties.h>
#include <gremios.h>
#include <combat.h>
#include <spellmonster.h>
#include <moving.h>
#define P_MIRAR_PECHOS "mirar_pechos_tabernera_glucksfall"


inherit SPELLMONSTER;

public string f_mirada_pechos();
public void acciones();
public status check_hp();
#define AO TP->QueryGenderEndString()

create(){
    ::create();
    AddId(({"medio elfa", "medioelfa", "semi elfa", "tabernera", "safil", "Shafil",
        "mujer", "chica", "joven"}));
    SetStandard("Shafil", "semi-elfo", ([GC_ASESINOS:45+d6()]), GENDER_FEMALE);
    SetShort("safil la tabernera");
    SetLong(
        "Ante ti tienes a Safil, una bella medio-elfa que hace algún tiempo decidió "
        "abandonar la dura vida de las mujeres de los muelles para establecerse en esta "
        "taberna.\n  Nadie sabe bien como logró obtenerla, pero se rumorea que sus artes "
        "amorosas tuvieron que ver mucho en el asunto.\n  En su rostro destacan unos "
        "grandes y almendrados ojos verdes y una sensual boca de carnosos labios. Su "
        "larga cabellera cobriza cae en tirabuzones sobre unos hombros desnudos tersos y "
        "bronceados, debido a las largas horas en el puerto.\n  Un ajustado corpiño "
        "apenas puede disimular la voluptuosidad y firmeza de sus senos, mientras que "
        "una amplia y llamativa falda le sirve para guardar todo aquello que quiere "
        "ocultar de miradas indiscretas, como su afilada daga, con la cual se granjeó una"
        " merecida fama de mujer peligrosa.\n");
    SetWeight(52000);
    SetAlign(-50);
    SetSmell("La estancia en la taberna le distorsiona el agradable olor a flores "
        "silvestres que le proporciona el elavorioso perfume que usa desde niña y, que "
        "tanto seduce a sus victimas masculinas, el cual se lo trae, expresamente de"
        " Lad-laurelin, uno de sus multiples amantes marinos.\n");
    AddSubDetail(({"senos", "pechos", "delantera", "mamas", "tetas", "corpiño"}), SF(f_mirada_pechos));
    AddSubDetail("falda", "Una abultada falda de tela y con vuelo le tapa ciertas cosas "
        "de valor, como algún arma y dinero, entre, uhm, otras... cuestiones  más personales.\n");
    AddSubDetail(({"pelo", "cabellera", "tirabuzones", "melena"}), "Una larga melena "
        "cobriza le tapa parte de los hombros.\n");
    InitAChats(10, ({"Shafil grita: maldición, ¿cómo te atreves a atacar a una mujer?.\n",
        "Con el movimiento del combate, los pechos de Shafil se mueven descontroladamente.\n",
        "Shafil intenta esquivar tus ataques.\n"}));

    InitChats(2, ({"Shafil se ajusta el corpiño.\n",
        "Shafil le quita el polvo a unas botellas.\n",
        "Shafil te mira dudosamente.\n",
        "Shafil se alisa unas arrugas que tiene en la falda.\n"}));
    AddQuestion(({"senos", "pechos", "delantera", "mamas", "tetas", "corpiño", "su pecho",
         "pecho", "sus senos", "sus tetas", "sus pechos"}),
        "Shafil te dice: ummm, ¿tú también te has fijado?, multitud de humanos y elfos "
        "se mueren de ganas por examinarme más detenidamente, tú ya me entiendes.\n", 1);
    AddQuestion(({"Goruck", "goruck", "ogro"}), "Shafil te dice: hace ya mucho tiempo que "
        "lo tengo pegado a mi culo constantemente, insiste en protegerme, pero hay veces "
        "que de tan pesado que se pone, molesta a los clientes y eso tampoco es bueno "
        "para mi negocio.\n", 1);
    AddQuestion(({"taberna", "negocio"}), "Shafil te dice: ya me ves aquí, en mi taberna, está"
        " claro que la clientela no es todo lo que a una le gustaría tener, pero mejor"
        " que la vida en el muelle si es.\n Además, ya que la vida me proporcionó la "
        "oportunidad de hacer un buen trato para adquirirla, con mis dotes de negociación"
        ", no iba a desaprovecharlo.\n", 1);
    SetShrugMsg("Shafil hace una mueca rara como si no entendiera.\n");

    SetCastChance(30);
    AddSpell("conjuros",
    ([
    S_CHECKFUN:SF(check_hp),
    S_FUN:SF(acciones), S_SP:2,
    S_CHANCE:30,
    S_VICTIMS:1,
    ]));

    AddItem(ARMA("daga_negra"), REFRESH_REMOVE, SF(wieldme));
}

public string f_mirada_pechos()
{
    object ob, env;
    if (Fighting()==1)
        return "Esas dos protuverancias varavillosas no paran de moverse con el "
        "movimiento del combate.\n";

    //buscamos al ogro y comprovamos si está vivo.
    env = environment();
    ob = present("ogro",env);
    if (ob && living(ob))
    {
        if (TP->Query(P_MIRAR_PECHOS) !=1)
        {
            write("Te llama la atención el volumen y la firmeza de los senos de Shafil, "
            "ciertamente dignos de ver y disfrutar.\n Goruck El Ogro se da cuenta de lo "
            "que estás mirando y gruñe diciéndote levantando la voz: ¡eeh!, maldit" +AO+
            " "+TP->QueryRace()+" ¿qué es lo que estás mirando?.\n ¡Si vuelves a "
            "echarle la vista encima te vas a acordar de mi!\n");
            say(CAP(TP->QueryName()) + " mira insistentemente los pechos de Shafil, pero"
            " Goruck El Ogro se da cuenta y le recrimina enfurecido su acción.\n", TP);
            TP->Set(P_MIRAR_PECHOS, 1);
            // el texto del return por no dejarlo vacío.
            return "Parece que el ogro este tiene malas pulgas.\n";
        }
        else
        {
            write("Goruck El Ogro, propinándote un fuerte y doloroso golpe en la cabeza "
            "con el mango de su hacha, te grita: ¡a Shafil no se le mira de esa manera,"
            " asqueros"+AO+" "+TP->QueryRace()+"!.\n");
            say(CAP(TP->QueryName()) + " mira incesantemente los pechos de Shafil"
            " y, Goruck El Ogro, muy enfurecido, le golpea salvajemente con el mango de "
            "su hacha en la cabeza.\n Eso ha tenido que doler...\n", TP);
            TP->Defend(d20(2),TD_APLASTAMIENTO, DEFEND_NOMSG);
            return "";
        }
    }
    if (TP->Query(P_MIRAR_PECHOS) != 1)
    {
        write ("Miras esas dos maravillas de la naturaleza que lleva Shafil en su "
        "delantera y quedas realmente sorprendid"+AO+", con esa firmeza y ese volumen tan"
        " exagerado, pero a su vez bien proporcionado.\n Tras el momento mágico, levantas"
        " la vista hasta su rostro y te fijas que te está mirando sonriente  y se ha "
        "dado cuenta de tu descarada mirada.\n Shafil se acerca a tu oído y te dice: "
        "parece que te gusta lo que miras, no te extrañes, le ocurre a muchos de tu raza."
        +(TP->QueryGender() == GENDER_FEMALE ? " Lo que me sorprende es que tu no eres un hombre,"
        " pero me alaga gustarle también a las féminas.\n" : "\n"));
        say (CAP(TP->QueryName()) + " le mira descaradamente los pechos a Shafil, "
        "ella se da cuenta y le sonríe diciéndole algo al oído.\n", TP);
        TP->Set(P_MIRAR_PECHOS, 1);
        return "\n Así de cerca parece que son algo más sugerentes.\n";
    }
    else
    {
        write ("Le miras los pechos a Shafil y ella, mirándote sonriente, te dice: ¡eeh,"
        " no me las mires tanto que me las vas a desgastar!.\n");
        say (CAP(TP->QueryName()) + " le mira los pechos a Shafil y ella, sonriente, le "
        "dice que no abuse mirándola tanto.\n", TP);
        return "Menos mal que no está el ogro...\n";
    }
}

public varargs int Defend(int dam, int dam_type, mixed flags, string *xtras){
    object ogro;
 	  ogro = present("ogro");
    if (ogro && living(ogro)) ogro->Kill(TP);
    return ::Defend(dam, dam_type, flags, &xtras);
}

public status check_hp(){
    return QuerySP() >= 100;
}

public void acciones(){
    object *adversarios, enemigo;
    adversarios = QueryEnemies();
    if(!sizeof(adversarios)) return 0;
    enemigo = adversarios[random(sizeof(adversarios))];
    switch(d10()){
        case 1..2:
        tell_object(enemigo, "Shafil salta hacia adelante con la intención de "
        "propinarte una feroz puñalada, pero se enreda con su larga falda y "
        "trastabilla.\n");
        tell_room(environment(), "Shafil, con un movimiento fugaz, se lanza hacia "
        + CAP(enemigo->QueryName()) + " para acuchillarle, pero se enreda con su falda"
        " y se tropieza perdiendo la oportunidad.\n", ({enemigo, TO}));
        SetCombatDelay(1);
        AddSP(-10);
        break;
        case 3..8:
        tell_object(enemigo, "Sin poder evitarlo, con un movimiento fugaz y "
        "contundente, Shafil te acuchilla con maestría provocándote serias heridas.\n");
        tell_room(environment(), "Shafil, con un movimiento fugaz, acuchilla a "
        + CAP(enemigo->QueryName()) + " sin que pueda evitarlo.\n", ({enemigo, TO}));
        enemigo->Defend(d6(20),DT_PIERCE, DEFEND_NOMSG);
        AddSP(-10);
        enemigo->AddTP(-d4());
        enemigo->SetCombatDelay(d2(), "Intentas recuperar la concentración tras la puñalada.\n");
        break;
        case 9..10:
        tell_object(enemigo,
        "Con el forcejeo del combate,\n  ¡uno de los pechos se le escapa del corpiño a "
        "Shafil!.\n Tu mirada se desvía a mirarlo dejando la atención en la lucha y ella,"
        " antes de volvérselo a tapar, te propina una patada en el estómago que te "
        "deja sin respiración.\n");
        tell_room(environment(),
        "En medio del combate,\n ¡se le escapa del ajustado corpiño un pecho a Sahfil!.\n"
        " A "+ CAP(enemigo->QueryName()) + " se le desvía la concentración para "
        "mirarlo, y ella, antes de volvérselo a tapar, le propina una patada en el "
        "estómago que le deja sin respiración.\n", ({enemigo, TO}));
        enemigo->Defend(d20(3),TD_APLASTAMIENTO, DEFEND_NOMSG);
        AddSP(-20);
        enemigo->SetCombatDelay(1,"El estómago te duele terriblemente.\n");
        enemigo->AddTP(-d3());
        break;
    }
}

public varargs void Die(mixed silent) {
    object *adversarios, enemigo, daga;
    adversarios = QueryEnemies();
    if(!sizeof(adversarios)) return ::Die(silent);
    enemigo = adversarios[random(sizeof(adversarios))];
    tell_object(enemigo, "Shafil dice: ¡trágate mi daga y vete al infierno!.\n"
        "Shafil te lanza su daga clavándotela en el vientre antes de caer muerta al "
        "suelo.\n");
    tell_room(environment(), "Shafil dice: ¡trágate mi daga y vete al infierno!.\n"
        "Shafil, antes de caer muerta al suelo, le lanza su daga a "
        +CAP(enemigo->QueryName())+ " en el vientre.\n", ({enemigo}));
    enemigo->Defend(d6(10),DT_PIERCE, DEFEND_NOMSG);
    if ((daga = present("daga_negra_tabernera")) && daga->move(enemigo,M_SILENT)!=ME_OK ){
        tell_room(environment(), "La daga se cae al suelo.\n");
    }
    ::Die(silent);
}
