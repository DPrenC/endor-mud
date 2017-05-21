        /****************************************************************************
Fichero: tabernera_glucksfall.c
Autor: Buh
Fecha: 30/08/2006
Descripci�n: La tabernera de la tabernna Mi hacha me acompa�a.
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
        "Ante ti tienes a Safil, una bella medio-elfa que hace alg�n tiempo decidi� "
        "abandonar la dura vida de las mujeres de los muelles para establecerse en esta "
        "taberna.\n  Nadie sabe bien como logr� obtenerla, pero se rumorea que sus artes "
        "amorosas tuvieron que ver mucho en el asunto.\n  En su rostro destacan unos "
        "grandes y almendrados ojos verdes y una sensual boca de carnosos labios. Su "
        "larga cabellera cobriza cae en tirabuzones sobre unos hombros desnudos tersos y "
        "bronceados, debido a las largas horas en el puerto.\n  Un ajustado corpi�o "
        "apenas puede disimular la voluptuosidad y firmeza de sus senos, mientras que "
        "una amplia y llamativa falda le sirve para guardar todo aquello que quiere "
        "ocultar de miradas indiscretas, como su afilada daga, con la cual se granje� una"
        " merecida fama de mujer peligrosa.\n");
    SetWeight(52000);
    SetAlign(-50);
    SetSmell("La estancia en la taberna le distorsiona el agradable olor a flores "
        "silvestres que le proporciona el elavorioso perfume que usa desde ni�a y, que "
        "tanto seduce a sus victimas masculinas, el cual se lo trae, expresamente de"
        " Lad-laurelin, uno de sus multiples amantes marinos.\n");
    AddSubDetail(({"senos", "pechos", "delantera", "mamas", "tetas", "corpi�o"}), SF(f_mirada_pechos));
    AddSubDetail("falda", "Una abultada falda de tela y con vuelo le tapa ciertas cosas "
        "de valor, como alg�n arma y dinero, entre, uhm, otras... cuestiones  m�s personales.\n");
    AddSubDetail(({"pelo", "cabellera", "tirabuzones", "melena"}), "Una larga melena "
        "cobriza le tapa parte de los hombros.\n");
    InitAChats(10, ({"Shafil grita: maldici�n, �c�mo te atreves a atacar a una mujer?.\n",
        "Con el movimiento del combate, los pechos de Shafil se mueven descontroladamente.\n",
        "Shafil intenta esquivar tus ataques.\n"}));

    InitChats(2, ({"Shafil se ajusta el corpi�o.\n",
        "Shafil le quita el polvo a unas botellas.\n",
        "Shafil te mira dudosamente.\n",
        "Shafil se alisa unas arrugas que tiene en la falda.\n"}));
    AddQuestion(({"senos", "pechos", "delantera", "mamas", "tetas", "corpi�o", "su pecho",
         "pecho", "sus senos", "sus tetas", "sus pechos"}),
        "Shafil te dice: ummm, �t� tambi�n te has fijado?, multitud de humanos y elfos "
        "se mueren de ganas por examinarme m�s detenidamente, t� ya me entiendes.\n", 1);
    AddQuestion(({"Goruck", "goruck", "ogro"}), "Shafil te dice: hace ya mucho tiempo que "
        "lo tengo pegado a mi culo constantemente, insiste en protegerme, pero hay veces "
        "que de tan pesado que se pone, molesta a los clientes y eso tampoco es bueno "
        "para mi negocio.\n", 1);
    AddQuestion(({"taberna", "negocio"}), "Shafil te dice: ya me ves aqu�, en mi taberna, est�"
        " claro que la clientela no es todo lo que a una le gustar�a tener, pero mejor"
        " que la vida en el muelle si es.\n Adem�s, ya que la vida me proporcion� la "
        "oportunidad de hacer un buen trato para adquirirla, con mis dotes de negociaci�n"
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

    //buscamos al ogro y comprovamos si est� vivo.
    env = environment();
    ob = present("ogro",env);
    if (ob && living(ob))
    {
        if (TP->Query(P_MIRAR_PECHOS) !=1)
        {
            write("Te llama la atenci�n el volumen y la firmeza de los senos de Shafil, "
            "ciertamente dignos de ver y disfrutar.\n Goruck El Ogro se da cuenta de lo "
            "que est�s mirando y gru�e dici�ndote levantando la voz: �eeh!, maldit" +AO+
            " "+TP->QueryRace()+" �qu� es lo que est�s mirando?.\n �Si vuelves a "
            "echarle la vista encima te vas a acordar de mi!\n");
            say(CAP(TP->QueryName()) + " mira insistentemente los pechos de Shafil, pero"
            " Goruck El Ogro se da cuenta y le recrimina enfurecido su acci�n.\n", TP);
            TP->Set(P_MIRAR_PECHOS, 1);
            // el texto del return por no dejarlo vac�o.
            return "Parece que el ogro este tiene malas pulgas.\n";
        }
        else
        {
            write("Goruck El Ogro, propin�ndote un fuerte y doloroso golpe en la cabeza "
            "con el mango de su hacha, te grita: �a Shafil no se le mira de esa manera,"
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
        " exagerado, pero a su vez bien proporcionado.\n Tras el momento m�gico, levantas"
        " la vista hasta su rostro y te fijas que te est� mirando sonriente  y se ha "
        "dado cuenta de tu descarada mirada.\n Shafil se acerca a tu o�do y te dice: "
        "parece que te gusta lo que miras, no te extra�es, le ocurre a muchos de tu raza."
        +(TP->QueryGender() == GENDER_FEMALE ? " Lo que me sorprende es que tu no eres un hombre,"
        " pero me alaga gustarle tambi�n a las f�minas.\n" : "\n"));
        say (CAP(TP->QueryName()) + " le mira descaradamente los pechos a Shafil, "
        "ella se da cuenta y le sonr�e dici�ndole algo al o�do.\n", TP);
        TP->Set(P_MIRAR_PECHOS, 1);
        return "\n As� de cerca parece que son algo m�s sugerentes.\n";
    }
    else
    {
        write ("Le miras los pechos a Shafil y ella, mir�ndote sonriente, te dice: �eeh,"
        " no me las mires tanto que me las vas a desgastar!.\n");
        say (CAP(TP->QueryName()) + " le mira los pechos a Shafil y ella, sonriente, le "
        "dice que no abuse mir�ndola tanto.\n", TP);
        return "Menos mal que no est� el ogro...\n";
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
        tell_object(enemigo, "Shafil salta hacia adelante con la intenci�n de "
        "propinarte una feroz pu�alada, pero se enreda con su larga falda y "
        "trastabilla.\n");
        tell_room(environment(), "Shafil, con un movimiento fugaz, se lanza hacia "
        + CAP(enemigo->QueryName()) + " para acuchillarle, pero se enreda con su falda"
        " y se tropieza perdiendo la oportunidad.\n", ({enemigo, TO}));
        SetCombatDelay(1);
        AddSP(-10);
        break;
        case 3..8:
        tell_object(enemigo, "Sin poder evitarlo, con un movimiento fugaz y "
        "contundente, Shafil te acuchilla con maestr�a provoc�ndote serias heridas.\n");
        tell_room(environment(), "Shafil, con un movimiento fugaz, acuchilla a "
        + CAP(enemigo->QueryName()) + " sin que pueda evitarlo.\n", ({enemigo, TO}));
        enemigo->Defend(d6(20),DT_PIERCE, DEFEND_NOMSG);
        AddSP(-10);
        enemigo->AddTP(-d4());
        enemigo->SetCombatDelay(d2(), "Intentas recuperar la concentraci�n tras la pu�alada.\n");
        break;
        case 9..10:
        tell_object(enemigo,
        "Con el forcejeo del combate,\n  �uno de los pechos se le escapa del corpi�o a "
        "Shafil!.\n Tu mirada se desv�a a mirarlo dejando la atenci�n en la lucha y ella,"
        " antes de volv�rselo a tapar, te propina una patada en el est�mago que te "
        "deja sin respiraci�n.\n");
        tell_room(environment(),
        "En medio del combate,\n �se le escapa del ajustado corpi�o un pecho a Sahfil!.\n"
        " A "+ CAP(enemigo->QueryName()) + " se le desv�a la concentraci�n para "
        "mirarlo, y ella, antes de volv�rselo a tapar, le propina una patada en el "
        "est�mago que le deja sin respiraci�n.\n", ({enemigo, TO}));
        enemigo->Defend(d20(3),TD_APLASTAMIENTO, DEFEND_NOMSG);
        AddSP(-20);
        enemigo->SetCombatDelay(1,"El est�mago te duele terriblemente.\n");
        enemigo->AddTP(-d3());
        break;
    }
}

public varargs void Die(mixed silent) {
    object *adversarios, enemigo, daga;
    adversarios = QueryEnemies();
    if(!sizeof(adversarios)) return ::Die(silent);
    enemigo = adversarios[random(sizeof(adversarios))];
    tell_object(enemigo, "Shafil dice: �tr�gate mi daga y vete al infierno!.\n"
        "Shafil te lanza su daga clav�ndotela en el vientre antes de caer muerta al "
        "suelo.\n");
    tell_room(environment(), "Shafil dice: �tr�gate mi daga y vete al infierno!.\n"
        "Shafil, antes de caer muerta al suelo, le lanza su daga a "
        +CAP(enemigo->QueryName())+ " en el vientre.\n", ({enemigo}));
    enemigo->Defend(d6(10),DT_PIERCE, DEFEND_NOMSG);
    if ((daga = present("daga_negra_tabernera")) && daga->move(enemigo,M_SILENT)!=ME_OK ){
        tell_room(environment(), "La daga se cae al suelo.\n");
    }
    ::Die(silent);
}
