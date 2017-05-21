#include "path.h"
#include <properties.h>
#include <spellmonster.h>
#include <guild.h>
#include <combat.h>
#include <moving.h>
#include <skills.h>
#include <sounds.h>
#include <wizlevels.h>
#include <effects.h>
inherit SPELLMONSTER;

#define AO  (TP->QueryGenderEndString())
#define OWNER QueryOwner()
#define ARMADO    ({"espada","hacha","maza"})
#define REINA   present(YALIN,environment())
 
//variables
static string pSpellName;
int callado, danyo, lucha;
private static object own;
object anillo;

//funciones
public status check_sp();
public string SetSpellName(string conj);
public string QuerySpellName();
public int magia();
void aviso();

// funciones chorras de adorno, para mi diversión personal
int n_besar(string str)
{
    if (!str) return 0;
    object ob=present(str,environment());
    if (!ob || ob->QueryRealName()!="ferny") return 0;
    if (TP->QueryRealName()=="yalin")
    {
        write("Besas a tu niño.\nEl niño te sonríe, y mimosamente, te besa con dulzura.\n");
        tell_room(environment(),"Yalin besa a su niño dulcemente.\nEl niño sonríe, y "
            "poniendo carita de mimo, le devuelve el beso.\n",({TP}));
        play_sound(environment(),SND_SUCESOS("beso"),0,100,2);
        return 1;
    }
    if (TP->QueryGender()==GENERO_FEMENINO)
        {
        write("Besas a Ferny.\nEl niño te sonríe dulcemente y, mimoso, te devuelve el beso.\n");
        tell_room(environment(),TNAME+" besa a Ferny con cariño.\nEl niño le sonríe, y "
            "con cara de mimo le devuelve el beso.\n",({TP}));
        play_sound(environment(),SND_SUCESOS("beso"),0,100,2);
        return 1;
    }
    write("El niño gira la cabeza esquivando tu beso mientras te "
        "dice: ¿Qué confianzas son ésas? A mí sólo me besan las chicas.\n");
    tell_room(environment(),TNAME+" intenta besar a Ferny, pero el niño gira la cabeza esquivando "
        "el beso diciendo: ¿Qué confianzas son ésas? A mí sólo me besan las chicas.\n",({TP}));
    return 1;
}

int dar_cmd(string str)
{
    if (!str) return 0;
    str=lower_case(str);
    if (str=="mano a niño" || str=="la mano a niño" || str=="mano a ferny" || 
        str=="la mano a ferny" || str=="mano al niño" || str=="la mano al niño")
    {
        if (TP->QueryGender()==GENERO_FEMENINO)
        {
            write("Tiendes tu mano hacia ferny, pero el niño no extiende la suya. Te sonríe "
                "pícaramente y te dice:\n¿La mano? ¿No me vas a dar un beso?.\n");
            tell_room(environment(),TNAME+" le da la mano a Ferny, pero el niño no la coge. Sonríe con "
                "malicia y dice:\n¿La mano? ¿No me vas a dar un beso?\n",({TP}));
            return 1;
        }
        write("Tiendes tu mano a Ferny, quien amablemente te ofrece la suya, y permite que la tomes, "
            "devolviéndote suave pero firmemente el apretón, mientras te sorprende la fuerza de esa "
            "manita infantil.\n");
        tell_room(environment(),TNAME+" da la mano a Ferny. El niño sonríe amablemente, le ofrece la "
            "suya, y permite que se la estreche.\n",({TP}));
        return 1;
    }
    return 0;
}

int noquiere(string str)
{
    if (!str) return 0;
    object ob=present(str,environment());
    if (!ob || ob->QueryRealName()!="ferny") return 0;
    if (TP->QueryRealName()=="yalin") return 0;
    if (TP->QueryGender()==GENERO_FEMENINO)
    {
        write("El niño aparta su cabeza esquivando tu intento, mientras te dice sonriendo: Me "
            "encantaría, pero eso es privilegio exclusivo de mi reina.\n");
        tell_room(environment(),TNAME+" trata de besar a Ferny con un exceso de pasión, pero el "
            "niño aparta la cabeza esquivando el intento, mientras le dice sonriendo: Me "
            "encantaría, pero eso es privilegio exclusivo de mi reina.\n",({TP}));
        return 1;
    }
    write("El niño gira bruscamente la cabeza esquivando tu intento, y con cara seria y voz "
        "cortante, te dice: ¿Pero quién te has creído que soy? Si no fuera porque no me gusta la "
        "violencia, te iba a enseñar a controlarte, ¡degenerado!\n");
    tell_room(environment(),TNAME+" Trata de dar un beso lujurioso a Ferni, pero el niño gira "
        "bruscamente la cabeza esquivando el intento, y con cara seria y voz cortante, le dice: "
        "¿Pero quién te has creído que soy? Si no fuera porque no me gusta la violencia, te iba a "
        "enseñar a controlarte, ¡degenerado!\n",({TP}));
    return 1;
}

private string hablo()
{
    if (callado==1) return "";
    string msg;
    switch (d6())
    {
        case 1:
            if (REINA) msg="El niño apoya con mimo su cabeza en el brazo de Yalin un "
                "momento, luego se yergue y sonríe.\n";
            else msg="El niño dice: ¿Dónde estará mi reina?\n";
        break;
        case 2:
            if (REINA) msg="El niño mira a Yalin y dice: Quiero ir a casa a jugar. ¿Nos vamos ya?\n";
            else msg="El niño dice: ¿Por qué tarda tanto? Espero que no le haya ocurrido nada.\n";
        break;
        case 3:
            if (REINA) msg="Yalin tira suavemente al niño de la nariz. El niño se ríe.\n";
            else msg="El niño dice: No me gusta quedarme solo.\n";
        break;
        case 4:
            msg="El niño te mira con suspicacia.\n";
        break;
        case 5:
            msg="El niño bosteza.\n";
        break;
        case 6:
            msg="El niño mira inquisitivamente a su alrededor.\n";
        break;
    }
    return msg;
}

public string i_yalin()
{
    string msg;
    if (IS_LEARNER(TP))
    {
        msg="El niño se inclina respetuosamente y te dice: ¿Qué queréis que os diga, ¡oh "
            "inmortal!, que vos no podáis saber de ella?\n";
        if (YALIN && !REINA) msg+="No obstante, si lo deseáis, pedidme que la avise, y le comunicaré que "
            "vos la buscáis.\n";
    else if (YALIN && REINA) msg+="Pero vuestras muchas ocupaciones os deben tener absorvid"+AO+
        ". Mi reina se halla en vuestra presencia.\n";
    }
    else
    {
        if (!YALIN || YALIN->QueryInvis()==1) msg="El niño te mira seriamente y dice con un "
            "suspiro: La reina no se encuentra en el mundo en este momento.\n";
        else
        {
            if (REINA) msg="El niño te mira extrañado diciendo: ¡Pero "
                "si la tienes delante! ¿Es que no ves?\n";
            else msg="El niño dice: Pues no está, me ha dejado solo y no me dijo dónde iba. "
                "¿Quieres que la avise? Si quieres, pídemelo.\n";
        }
    }
    return msg;
}
    
int avisando(string str)
{
    if (!str) return 0;
    str=lower_case(str);
    if (str=="yalin" || str=="a yalin" || str=="reina" || str=="a reina" || str=="la reina" ||
        str=="a la reina" || str=="tu reina" || str=="a tu reina")
    {
        if (!YALIN || (!IS_LEARNER(TP) && YALIN->QueryInvis()==1)) return notify_fail("El niño "
            "te dice: Lo siento, la reina no está en el mundo ahora.\n",NOTIFY_NOT_VALID);
        anillo=present("comunicator",TO);
        if (anillo)
        {
            write("El niño dice: Vale, ya la llamo.\nActo seguido, gira el anillo en su dedo, "
                "se lo acerca a los labios y musita unas palabras en un lenguaje que no "
                "comprendes. Luego te mira y dice: ");
            if (present("comunicator",YALIN))
            {
                anillo->n_llama(TP);
                write ("Bien, ya está avisada. Ahora ella sabrá qué hacer.\n");
                return 1;
            }
        else write("Lo siento, no consigo comunicar con ella. Creo que ha perdido su anillo.\n");
            }
        else write("¡Oh, no! ¡He perdido mi anillo! Lo siento, no puedo avisarla.\n");
    }
    return 1;
}
            
public object QueryOwner()
{
    return own || 0;
}

public object SetOwner(object ob)
{
    return own=ob||0;
}

public void amo()
{
    if (TP == YALIN)
    {
        SetOwner(TP);
        SetFriendFunction("IsFriend", TP);
        TP->AddFollower(TO);
        heart_beat();
    }
    return;
}

public int micomando(string orden)
{
    if (TP != YALIN) return 0;
    switch (orden)
    {
        case "conmigo":
            if (lucha == 1) return 0;
            say("Yalin dice: conmigo nene\n",TP);
            write("El niño te sonríe, levanta su arma y te dice: Estoy listo, mi amor.\n");
            say("El niño dice: Estoy listo, mi reina.\nActo seguido, se yergue decidido, "
                "esgrime su arma y se dispone al combate.\n",TP);
            lucha = 1;
        break;
        case "quieto":
            if (lucha == 0) return 0;
            say("Yalin dice: quieto nene\n",TP);
            write("El niño asiente sonriendo, baja los brazos y dice: Vale, cariño, peleas tú sola.\n");
            say("El niño mira sonriendo a Yalin y dice: De acuerdo, mi reina, te dejo pelear a "
                "ti.\nY bajando los brazos, se relaja en posición de descanso.\n",TP);
            lucha = 0;
        break;
        case "espera":
            write("El niño te dice: Vale mi amorcito, te espero aquí.\n");
            say("Yalin dice: Espera nene.\nEl niño se pone en posición relajada y dice: Vale "
                "mi reina, te espero aquí. No me dejes solito mucho tiempo...\n",TP);
            TP->RemoveFollower(TO);
        break;
        case "vamos":
            write("El niño te dice: Claro mi amor, contigo donde me lleves.\n");
            say("Yalin dice: Vamos nene.\nEl niño se alisa la túnica diciendo: Vale, mi reina, "
                "cuando quieras nos vamos.\n",TP);
            amo();
        break;;
        case "calladito":
            write("El niño te dice: Vale mi amor, ya me callo.\n");
            say("Yalin dice: Niño, cállate un poco.\nEl niño sonríe y dice: Perdón, me callo.\n",TP);
            callado=1;
        break;
        case "habla":
            write("El niño te dice: Gracias mi amor.\n");
            say("Yalin sonríe al niño y dice: Vale nene, ya puedes hablar.\nEl niño suspira "
                "diciendo: Gracias, ya me aburría.\n",TP);
            callado=0;
        break;
        case "vete":
            write("El niño te dice: Vale, cariño, me voy a casa. Si me necesitas me llamas.\n");
            say("Yalin acaricia la cabeza del niño diciendo: Puedes irte, nene. No te necesito "
                "ahora.\nEl niño sonríe y dice: Vale mi reina, me voy a casa. Si necesitas "
                "algo me llamas.\n",TP);
            move("/d/limbo/comun/habitacion/limbo/torrewiz/rooms/yalin/workroom",M_TELEPORT);
        break;
        default: return 0; break;
    }
    return 1;
}
                
void ComprobarEnemigos()
{
    mixed enemigos;
    int i;
    if (!OWNER) return;
    if (environment(TO)!=environment(OWNER)) return;
    enemigos=OWNER->QueryEnemies();
    if (!enemigos) return;
    for (i=0;i<sizeof(enemigos);i++)
    if (lucha == 1) Kill(enemigos[i]);
    return;
}

heart_beat()
{
    ComprobarEnemigos();
    return ::heart_beat();
}

reset()
{
    ::reset();
    if (YALIN)
    {
        anillo=present("comunicator",YALIN);
        if (anillo && anillo->QueryNene()!=TO) anillo->SetNene(TO);
    }
}

create()
{
    ::create();
    SetStandard("el niño","humano",([ GC_EXPERTO:200 ]),GENERO_MASCULINO);
    callado=1;
    SetName("Ferny");
    AddId(({"Ferny","ferny","niño","ninyo","amante"}));
    AddAdjective(({"de Yalin","de yalin"}));
    SetShort("el niño de Yalin");
    SetLong("Ferny es un niño de unos 12 años, rubio, de cara sonriente y unos profundos y "
        "atentos ojos verdes.\nEs el amante de Yalin, por raro que pueda parecerte, pero..., "
        "bueno, Yalin es algo..., ¿especial?, ¿perversa?..., bueno, eso.\nAunque es todavía un "
        "niño, no te fíes demasiado. Por decisión expresa de la reina de las hadas, fué "
        "entrenado por los mejores en cada técnica: el mismísimo general drix en las armas, y "
        "los granndes maestros Kaleband, Valdemar, Melbius y la propia Yalin en las artes "
        "mágicas, así que..., cuidado, podría no ser lo que parece.\n");
    SetHP(QueryMaxHP());
    SetNoise("El niño no está hablando. Sólo oyes su pausada respiración.\n");
    SetSmell("De su cuerpecito emana un suave perfume de rosas y pachulí.\n");
    SetNoGet(0);
    SetNoDrop(0);
    Set(P_IS_PET, 1);
    Set(P_CANT_LURE,1);
    SetIVision(-150);
    SetUVision(150);
    SetMMsgIn("se posa suavemente, como si hubiera venido volando");
    SetMMsgOut("hace un gesto con su mano, y desaparece de tu vista");
    AddQuestion(({"anillo","piedra"}),"El niño pone una enigmática sonrisa mientras te dice: "
        "Mi reina lleva otro igual. Son mágicos, ¿sabes?, pero sólo ella y yo podemos "
        "utilizarlos. Nos sirven para estar en contacto o llamarnos desde la distancia.\n",1);
    AddQuestion(({"yalin","Yalin","reina","tu reina","amante","tu amante"}),SF(i_yalin),1);
    AddQuestion(({"wiz","wizs","wizard","wizards"}),"El niño te dice: Los wizards viven en la "
        "torre de la magia. Sson seres inmortales, a quienes los dioses encomendaron el "
        "cuidado, el gobierno y la prosperidad del mundo.\nSon muy poderosos, conocen y dominan "
        "fuerzas muy superiores a cualquiera otra de este mundo.\n Si alguna vez te encuentras "
        "con uno, muéstrale gratitud y respeto. No es prudente enojarlos.\n",1);
    AddQuestion(({"torre","torre de magia","torre de la magia"}),"El niño te dice: ¿La torre de "
        "los wizards? Está en el mar, al este de Limbo. Es donde residen y trabajan los wizards, "
        "y desde donde controlan el mundo.\nYo también vivo allí, ¿sabes?, con mi reina, que "
        "es una de ellos, pero comprenderás que no puedo decirte lo que hay o lo que  ocurre "
        "en su interior.\n",1);
    SetShrugMsg("El niño dice: Pues no sé, no estoy informado.\n");
    SetSpellChance(1000);
    AddSpell("conjuros",
        ([
            S_CHECKFUN: SF(check_sp),
            S_FUN: SF(magia),
            S_SP:2,
            S_CHANCE: 1000,
            S_VICTIMS: 1,
        ]));
    AddItem("anillo",REFRESH_REMOVE,1,SF(wearme));
    AddItem("tunica",REFRESH_REMOVE,1,SF(wearme));
    AddItem("zapatillas",REFRESH_REMOVE,1,SF(wearme));
    AddItem("espada",REFRESH_REMOVE,1,SF(wieldme));
    if (YALIN && anillo=present("comunicator",YALIN)) anillo->SetNene(TO);
    InitChats(5,SF(hablo));
    InitAChats(20,
        ({"El niño dice: No debiste hacerlo, yo no te he hecho nada.\n",
        "El niño dice: No me gusta matar, pero tengo que defenderme.\n",
        "El niño dice: No permitiré que nadie haga daño a mi reina, ni a mí, claro.\n"}));
}

init()
{
    ::init();
    add_action("dar_cmd","dar");
    add_action("dar_cmd","darle");
    add_action("n_besar","besar");
    add_action("noquiere","francés");
    add_action("noquiere","frances");
    add_action("noquiere","morrear");
    add_action("avisando","avisar");
    add_action("avisando","avisa");
    add_action("micomando","nene");
}

//magia
public status check_sp() { return QuerySP() > 0; }
public string SetSpellName(string conj) { return pSpellName = conj; }
public string QuerySpellName() { return pSpellName; }

public int magia()
{
    danyo = (QueryLevel()+QueryInt())/5;
    object *adversarios, enemigo,bola;
    adversarios = QueryEnemies() || ({});
    if(!sizeof(adversarios)) return 0;
    enemigo = adversarios[random(sizeof(adversarios))];
    if (!present(enemigo, environment())) return 0;
    switch (d8())
    {
        case 1:
            if (QuerySP() <80) break;
            AddSP(-80);
            tell_object(enemigo,"El niño invoca a Sherek contra tu alma.\nSientes que el poder "
                "de la diosa te hiere muy gravemente.\n");
            say("El niño invoca a Sherek contra el alma de "+capitalize(enemigo->QueryName())+
                ", y ves cómo el poder de la diosa le hiere muy gravemente.\n",enemigo);
            SetSpellName("Herida Crítica");
            enemigo->Defend(danyo*5, DT_ZAP, DEFEND_SPELL);
            SetSpellName(0);
        break;
        case 2:
            if (QuerySP() <10) break;
            AddSP(-10);
            seteuid(getuid(TO));
            bola=clone_object(EFFECT_LUZ_CEGADORA);
            bola->SetInitChat("Los ojos  del niño te deslumbran.\n");
            bola->SetEndChat("Los ojos del niño dejan de deslumbrarte.\n");
            bola->SetEnvInitChat("El niño deslumbra a "+capitalize(enemigo->QueryName())+".\n",enemigo);
            bola->SetEnvEndChat("El niño deja de deslumbrar a "+capitalize(enemigo->QueryName())+".\n",
                enemigo);
            say("El niño se concentra y mira a "+capitalize(enemigo->QueryName())+". De sus "
                "ojos emana una potente luz.\n",enemigo);
            tell_object(enemigo,"El niño se concentra y fija su mirada en ti. De sus ojos "
                "emana una potente luz.\n");
            SetSpellName("Luz Cegadora");
            if (bola->Affect(enemigo,8)) play_sound(environment(),SND_MAGIA("luz_cegadora"));
            SetSpellName(0);
        break;
        case 3:
            if (QuerySP() < 25) break;
            AddSP(-25);
            say("El niño apunta su dedo índice hacia "+capitalize(enemigo->QueryName())+" y "
                "pronuncia unas palabras.\nEl niño dice: Creil Uz Tirôm.\nAl momento un rayo "
                "sale de su dedo hacia "+capitalize(enemigo->QueryName())+".\n",enemigo);
            tell_object(enemigo,"El niño apunta su dedo índice hacia ti y pronuncia unas "
                "palabras.\nEl niño dice: Creil Uz Tirôm.\nAl momento un rayo sale de su dedo "
                "y se dirige hacia ti.\n");
            SetSpellName("proyectil eléctrico");
            int v=0;
            if (d3() ==1)
            {
                say("El niño crea un rayo bifurcado que impacta dos veces en "+
                    capitalize(enemigo->QueryName())+".\n",enemigo);
                tell_object(enemigo,"¡El niño crea un rayo bifurcado!\n");
                enemigo->Defend(danyo*2,TD_ELECTRICIDAD,DEFEND_SPELL);
                v=2;
            }
            play_sound(environment(),SND_MAGIA("proyectil"),0,100,v);
            enemigo->Defend(danyo*2,TD_ELECTRICIDAD,DEFEND_SPELL);
            SetSpellName(0);
        break;
        case 4:
            if (QuerySP() < 10) break;
            AddSP(-10);
            tell_object(enemigo,"El niño extiende un brazo y lo eleva por encima de su cabeza, "
                "se concentra y aparece en su mano una lanza de ácido que instantáneamente te "
                "lanza con fuerza.\n");
            say("El niño extiende un brazo y lo eleva por encima de su cabeza, se concentra y "
                "aparece en su mano una lanza de ácido que instantáneamente lanza contra "+
                capitalize(enemigo->QueryName())+".\n",enemigo);
            play_sound(environment(),SND_MAGIA("lanzaacido"));
            SetSpellName("Lanza de Ácido");
            enemigo->Defend(danyo, DT_ACID, DEFEND_SPELL);
            SetSpellName(0);
        break;
        case 5:
            if (QuerySP() <20) break;
            AddSP(-20);
            tell_object(enemigo,"El niño cierra los ojos y se concentra. Un intenso escalofrío "
                "recorre tu cuerpo y el pánico te paraliza.\n");
            say("El niño cierra los ojos y se concentra. De repente "+
                capitalize(enemigo->QueryName())+" comienza a temblar de pánico.\n",enemigo);
            play_sound(environment(),SND_MAGIA("miedoparalizante"));
            SetSpellName("MiedoParalizante");
            enemigo->SetCombatDelay(10,"Estás paralizad"+AO+" por el miedo.\n");
            SetSpellName(0);
        break;
        case 6:
            if (QuerySP() <40) break;
            AddSP(-40);
            tell_object(enemigo,"El niño cierra los ojos. Al instante crea una tromba de "
                "meteoritos que te dan de lleno ¡¡CLOCK!!.\n");
            say("El niño cierra los ojos. Al instante crea una tromba de meteoritos que "
                "impactan en "+capitalize(enemigo->QueryName())+".\n",enemigo);
            play_sound(environment(),SND_MAGIA("meteorito"));
            SetSpellName("Meteorito");
            enemigo->Defend(danyo*4, DT_FIRE, DEFEND_SPELL);
            SetSpellName(0);
        break;
        case 7:
            if (QuerySP() <100) break;
            AddSP(-100);
            say("El niño entona un extraño rezo a Sherek. Ves como el poder de la diosa le "
                "fortalece, devolviéndole toda su salud y fuerza de espíritu.\n");
            SetSpellName("Curar verdadero");
            SetHP(QueryMaxHP());
            SetSP(QueryMaxSP());
            SetSpellName(0);
        break;
        case 8:
            if (QuerySP() <30) break;
            AddSP(-30);
            tell_object(enemigo,"El niño clava la vista en ti y pronuncia unas palabras.\nEl "
                "niño dice: Creil shal dhûl.\nAl instante notas como algo invisible te golpea.\n");
            say("El niño clava la vista en "+capitalize(enemigo->QueryName())+" y pronuncia "
                "unas palabras.\nEl niño dice: Creil shal dhûl.\n"+
                capitalize(enemigo->QueryName())+" retrocede como si hubiese sido golpeado por "
                "algo invisible.\n",enemigo);
            play_sound(environment(),SND_MAGIA("golpedescarga"));
            SetSpellName("Golpe de Descarga");
            enemigo->Defend(danyo*3, DT_BLUDGEON, DEFEND_SPELL);
            SetSpellName(0);
        break;
    }
    return 0;
}

// no se le paraliza
void aviso()
{
    write("El niño ve tu pobre intento de detenerle, y con una dulce sonrisa, te dice "
        "con su voz suave: No, no. Conmigo eso no te vale.\n");
    say("el niño ve el pobre intento de "+TNAME+" de detenerle, y le sonríe "
        "dulcemente diciéndole: No, no. Conmigo eso no te vale.\n",TP);
}

mixed SetCombatDelay(int time, string s)
{
    call_out("aviso", 0);
    return 1;
}

mixed SetStunned(int time, string s)
{
    call_out("aviso", 0);
    return 1;
}

// respuesta no standard a coger/dejar
public varargs int move(mixed dest, int method, mixed extra)
{
    object pl = PO;
    if (method == M_GET && pl && query_once_interactive(pl))
    {
        if (TP->QueryRealName() == "yalin")
        {
            tell_room(environment(TP),"Yalin se inclina hacia su niño y le tiende los brazos.\n",({TP}));
            command_me("desempuñar armas");
            tell_room(environment(TP),"El niño pone cara de mimo, y se abandona complacido en los brazos de su amante "
                "protectora.\n",({TP}));
        }
        else
        {
            write("El niño sonríe condescendiente mientras te esquiva y te dice: Eh, sin "
                "tocar. A mí sólo me coge mi dulce reina.\n");
            return ME_NO_GET;
        }
    }
    if (method == M_DROP && pl && query_once_interactive(pl))
    {
        if (TP->QueryRealName() == "yalin")
        {
            tell_room(environment(TP),"Yalin se inclina, y besando a su niño con dulzura, le "
                "deposita suavemente en el suelo.\n",({TP}));
            command_me("empuñar armas");
            tell_room(environment(TP),"El niño se yergue, y con elegancia, se alisa la túnica. "
                "Acto seguido,  empuña su arma.\n");
        }
    }   
    return ::move(dest, method, extra);
}
