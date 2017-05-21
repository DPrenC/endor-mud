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

// funciones chorras de adorno, para mi diversi�n personal
int n_besar(string str)
{
    if (!str) return 0;
    object ob=present(str,environment());
    if (!ob || ob->QueryRealName()!="ferny") return 0;
    if (TP->QueryRealName()=="yalin")
    {
        write("Besas a tu ni�o.\nEl ni�o te sonr�e, y mimosamente, te besa con dulzura.\n");
        tell_room(environment(),"Yalin besa a su ni�o dulcemente.\nEl ni�o sonr�e, y "
            "poniendo carita de mimo, le devuelve el beso.\n",({TP}));
        play_sound(environment(),SND_SUCESOS("beso"),0,100,2);
        return 1;
    }
    if (TP->QueryGender()==GENERO_FEMENINO)
        {
        write("Besas a Ferny.\nEl ni�o te sonr�e dulcemente y, mimoso, te devuelve el beso.\n");
        tell_room(environment(),TNAME+" besa a Ferny con cari�o.\nEl ni�o le sonr�e, y "
            "con cara de mimo le devuelve el beso.\n",({TP}));
        play_sound(environment(),SND_SUCESOS("beso"),0,100,2);
        return 1;
    }
    write("El ni�o gira la cabeza esquivando tu beso mientras te "
        "dice: �Qu� confianzas son �sas? A m� s�lo me besan las chicas.\n");
    tell_room(environment(),TNAME+" intenta besar a Ferny, pero el ni�o gira la cabeza esquivando "
        "el beso diciendo: �Qu� confianzas son �sas? A m� s�lo me besan las chicas.\n",({TP}));
    return 1;
}

int dar_cmd(string str)
{
    if (!str) return 0;
    str=lower_case(str);
    if (str=="mano a ni�o" || str=="la mano a ni�o" || str=="mano a ferny" || 
        str=="la mano a ferny" || str=="mano al ni�o" || str=="la mano al ni�o")
    {
        if (TP->QueryGender()==GENERO_FEMENINO)
        {
            write("Tiendes tu mano hacia ferny, pero el ni�o no extiende la suya. Te sonr�e "
                "p�caramente y te dice:\n�La mano? �No me vas a dar un beso?.\n");
            tell_room(environment(),TNAME+" le da la mano a Ferny, pero el ni�o no la coge. Sonr�e con "
                "malicia y dice:\n�La mano? �No me vas a dar un beso?\n",({TP}));
            return 1;
        }
        write("Tiendes tu mano a Ferny, quien amablemente te ofrece la suya, y permite que la tomes, "
            "devolvi�ndote suave pero firmemente el apret�n, mientras te sorprende la fuerza de esa "
            "manita infantil.\n");
        tell_room(environment(),TNAME+" da la mano a Ferny. El ni�o sonr�e amablemente, le ofrece la "
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
        write("El ni�o aparta su cabeza esquivando tu intento, mientras te dice sonriendo: Me "
            "encantar�a, pero eso es privilegio exclusivo de mi reina.\n");
        tell_room(environment(),TNAME+" trata de besar a Ferny con un exceso de pasi�n, pero el "
            "ni�o aparta la cabeza esquivando el intento, mientras le dice sonriendo: Me "
            "encantar�a, pero eso es privilegio exclusivo de mi reina.\n",({TP}));
        return 1;
    }
    write("El ni�o gira bruscamente la cabeza esquivando tu intento, y con cara seria y voz "
        "cortante, te dice: �Pero qui�n te has cre�do que soy? Si no fuera porque no me gusta la "
        "violencia, te iba a ense�ar a controlarte, �degenerado!\n");
    tell_room(environment(),TNAME+" Trata de dar un beso lujurioso a Ferni, pero el ni�o gira "
        "bruscamente la cabeza esquivando el intento, y con cara seria y voz cortante, le dice: "
        "�Pero qui�n te has cre�do que soy? Si no fuera porque no me gusta la violencia, te iba a "
        "ense�ar a controlarte, �degenerado!\n",({TP}));
    return 1;
}

private string hablo()
{
    if (callado==1) return "";
    string msg;
    switch (d6())
    {
        case 1:
            if (REINA) msg="El ni�o apoya con mimo su cabeza en el brazo de Yalin un "
                "momento, luego se yergue y sonr�e.\n";
            else msg="El ni�o dice: �D�nde estar� mi reina?\n";
        break;
        case 2:
            if (REINA) msg="El ni�o mira a Yalin y dice: Quiero ir a casa a jugar. �Nos vamos ya?\n";
            else msg="El ni�o dice: �Por qu� tarda tanto? Espero que no le haya ocurrido nada.\n";
        break;
        case 3:
            if (REINA) msg="Yalin tira suavemente al ni�o de la nariz. El ni�o se r�e.\n";
            else msg="El ni�o dice: No me gusta quedarme solo.\n";
        break;
        case 4:
            msg="El ni�o te mira con suspicacia.\n";
        break;
        case 5:
            msg="El ni�o bosteza.\n";
        break;
        case 6:
            msg="El ni�o mira inquisitivamente a su alrededor.\n";
        break;
    }
    return msg;
}

public string i_yalin()
{
    string msg;
    if (IS_LEARNER(TP))
    {
        msg="El ni�o se inclina respetuosamente y te dice: �Qu� quer�is que os diga, �oh "
            "inmortal!, que vos no pod�is saber de ella?\n";
        if (YALIN && !REINA) msg+="No obstante, si lo dese�is, pedidme que la avise, y le comunicar� que "
            "vos la busc�is.\n";
    else if (YALIN && REINA) msg+="Pero vuestras muchas ocupaciones os deben tener absorvid"+AO+
        ". Mi reina se halla en vuestra presencia.\n";
    }
    else
    {
        if (!YALIN || YALIN->QueryInvis()==1) msg="El ni�o te mira seriamente y dice con un "
            "suspiro: La reina no se encuentra en el mundo en este momento.\n";
        else
        {
            if (REINA) msg="El ni�o te mira extra�ado diciendo: �Pero "
                "si la tienes delante! �Es que no ves?\n";
            else msg="El ni�o dice: Pues no est�, me ha dejado solo y no me dijo d�nde iba. "
                "�Quieres que la avise? Si quieres, p�demelo.\n";
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
        if (!YALIN || (!IS_LEARNER(TP) && YALIN->QueryInvis()==1)) return notify_fail("El ni�o "
            "te dice: Lo siento, la reina no est� en el mundo ahora.\n",NOTIFY_NOT_VALID);
        anillo=present("comunicator",TO);
        if (anillo)
        {
            write("El ni�o dice: Vale, ya la llamo.\nActo seguido, gira el anillo en su dedo, "
                "se lo acerca a los labios y musita unas palabras en un lenguaje que no "
                "comprendes. Luego te mira y dice: ");
            if (present("comunicator",YALIN))
            {
                anillo->n_llama(TP);
                write ("Bien, ya est� avisada. Ahora ella sabr� qu� hacer.\n");
                return 1;
            }
        else write("Lo siento, no consigo comunicar con ella. Creo que ha perdido su anillo.\n");
            }
        else write("�Oh, no! �He perdido mi anillo! Lo siento, no puedo avisarla.\n");
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
            write("El ni�o te sonr�e, levanta su arma y te dice: Estoy listo, mi amor.\n");
            say("El ni�o dice: Estoy listo, mi reina.\nActo seguido, se yergue decidido, "
                "esgrime su arma y se dispone al combate.\n",TP);
            lucha = 1;
        break;
        case "quieto":
            if (lucha == 0) return 0;
            say("Yalin dice: quieto nene\n",TP);
            write("El ni�o asiente sonriendo, baja los brazos y dice: Vale, cari�o, peleas t� sola.\n");
            say("El ni�o mira sonriendo a Yalin y dice: De acuerdo, mi reina, te dejo pelear a "
                "ti.\nY bajando los brazos, se relaja en posici�n de descanso.\n",TP);
            lucha = 0;
        break;
        case "espera":
            write("El ni�o te dice: Vale mi amorcito, te espero aqu�.\n");
            say("Yalin dice: Espera nene.\nEl ni�o se pone en posici�n relajada y dice: Vale "
                "mi reina, te espero aqu�. No me dejes solito mucho tiempo...\n",TP);
            TP->RemoveFollower(TO);
        break;
        case "vamos":
            write("El ni�o te dice: Claro mi amor, contigo donde me lleves.\n");
            say("Yalin dice: Vamos nene.\nEl ni�o se alisa la t�nica diciendo: Vale, mi reina, "
                "cuando quieras nos vamos.\n",TP);
            amo();
        break;;
        case "calladito":
            write("El ni�o te dice: Vale mi amor, ya me callo.\n");
            say("Yalin dice: Ni�o, c�llate un poco.\nEl ni�o sonr�e y dice: Perd�n, me callo.\n",TP);
            callado=1;
        break;
        case "habla":
            write("El ni�o te dice: Gracias mi amor.\n");
            say("Yalin sonr�e al ni�o y dice: Vale nene, ya puedes hablar.\nEl ni�o suspira "
                "diciendo: Gracias, ya me aburr�a.\n",TP);
            callado=0;
        break;
        case "vete":
            write("El ni�o te dice: Vale, cari�o, me voy a casa. Si me necesitas me llamas.\n");
            say("Yalin acaricia la cabeza del ni�o diciendo: Puedes irte, nene. No te necesito "
                "ahora.\nEl ni�o sonr�e y dice: Vale mi reina, me voy a casa. Si necesitas "
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
    SetStandard("el ni�o","humano",([ GC_EXPERTO:200 ]),GENERO_MASCULINO);
    callado=1;
    SetName("Ferny");
    AddId(({"Ferny","ferny","ni�o","ninyo","amante"}));
    AddAdjective(({"de Yalin","de yalin"}));
    SetShort("el ni�o de Yalin");
    SetLong("Ferny es un ni�o de unos 12 a�os, rubio, de cara sonriente y unos profundos y "
        "atentos ojos verdes.\nEs el amante de Yalin, por raro que pueda parecerte, pero..., "
        "bueno, Yalin es algo..., �especial?, �perversa?..., bueno, eso.\nAunque es todav�a un "
        "ni�o, no te f�es demasiado. Por decisi�n expresa de la reina de las hadas, fu� "
        "entrenado por los mejores en cada t�cnica: el mism�simo general drix en las armas, y "
        "los granndes maestros Kaleband, Valdemar, Melbius y la propia Yalin en las artes "
        "m�gicas, as� que..., cuidado, podr�a no ser lo que parece.\n");
    SetHP(QueryMaxHP());
    SetNoise("El ni�o no est� hablando. S�lo oyes su pausada respiraci�n.\n");
    SetSmell("De su cuerpecito emana un suave perfume de rosas y pachul�.\n");
    SetNoGet(0);
    SetNoDrop(0);
    Set(P_IS_PET, 1);
    Set(P_CANT_LURE,1);
    SetIVision(-150);
    SetUVision(150);
    SetMMsgIn("se posa suavemente, como si hubiera venido volando");
    SetMMsgOut("hace un gesto con su mano, y desaparece de tu vista");
    AddQuestion(({"anillo","piedra"}),"El ni�o pone una enigm�tica sonrisa mientras te dice: "
        "Mi reina lleva otro igual. Son m�gicos, �sabes?, pero s�lo ella y yo podemos "
        "utilizarlos. Nos sirven para estar en contacto o llamarnos desde la distancia.\n",1);
    AddQuestion(({"yalin","Yalin","reina","tu reina","amante","tu amante"}),SF(i_yalin),1);
    AddQuestion(({"wiz","wizs","wizard","wizards"}),"El ni�o te dice: Los wizards viven en la "
        "torre de la magia. Sson seres inmortales, a quienes los dioses encomendaron el "
        "cuidado, el gobierno y la prosperidad del mundo.\nSon muy poderosos, conocen y dominan "
        "fuerzas muy superiores a cualquiera otra de este mundo.\n Si alguna vez te encuentras "
        "con uno, mu�strale gratitud y respeto. No es prudente enojarlos.\n",1);
    AddQuestion(({"torre","torre de magia","torre de la magia"}),"El ni�o te dice: �La torre de "
        "los wizards? Est� en el mar, al este de Limbo. Es donde residen y trabajan los wizards, "
        "y desde donde controlan el mundo.\nYo tambi�n vivo all�, �sabes?, con mi reina, que "
        "es una de ellos, pero comprender�s que no puedo decirte lo que hay o lo que  ocurre "
        "en su interior.\n",1);
    SetShrugMsg("El ni�o dice: Pues no s�, no estoy informado.\n");
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
        ({"El ni�o dice: No debiste hacerlo, yo no te he hecho nada.\n",
        "El ni�o dice: No me gusta matar, pero tengo que defenderme.\n",
        "El ni�o dice: No permitir� que nadie haga da�o a mi reina, ni a m�, claro.\n"}));
}

init()
{
    ::init();
    add_action("dar_cmd","dar");
    add_action("dar_cmd","darle");
    add_action("n_besar","besar");
    add_action("noquiere","franc�s");
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
            tell_object(enemigo,"El ni�o invoca a Sherek contra tu alma.\nSientes que el poder "
                "de la diosa te hiere muy gravemente.\n");
            say("El ni�o invoca a Sherek contra el alma de "+capitalize(enemigo->QueryName())+
                ", y ves c�mo el poder de la diosa le hiere muy gravemente.\n",enemigo);
            SetSpellName("Herida Cr�tica");
            enemigo->Defend(danyo*5, DT_ZAP, DEFEND_SPELL);
            SetSpellName(0);
        break;
        case 2:
            if (QuerySP() <10) break;
            AddSP(-10);
            seteuid(getuid(TO));
            bola=clone_object(EFFECT_LUZ_CEGADORA);
            bola->SetInitChat("Los ojos  del ni�o te deslumbran.\n");
            bola->SetEndChat("Los ojos del ni�o dejan de deslumbrarte.\n");
            bola->SetEnvInitChat("El ni�o deslumbra a "+capitalize(enemigo->QueryName())+".\n",enemigo);
            bola->SetEnvEndChat("El ni�o deja de deslumbrar a "+capitalize(enemigo->QueryName())+".\n",
                enemigo);
            say("El ni�o se concentra y mira a "+capitalize(enemigo->QueryName())+". De sus "
                "ojos emana una potente luz.\n",enemigo);
            tell_object(enemigo,"El ni�o se concentra y fija su mirada en ti. De sus ojos "
                "emana una potente luz.\n");
            SetSpellName("Luz Cegadora");
            if (bola->Affect(enemigo,8)) play_sound(environment(),SND_MAGIA("luz_cegadora"));
            SetSpellName(0);
        break;
        case 3:
            if (QuerySP() < 25) break;
            AddSP(-25);
            say("El ni�o apunta su dedo �ndice hacia "+capitalize(enemigo->QueryName())+" y "
                "pronuncia unas palabras.\nEl ni�o dice: Creil Uz Tir�m.\nAl momento un rayo "
                "sale de su dedo hacia "+capitalize(enemigo->QueryName())+".\n",enemigo);
            tell_object(enemigo,"El ni�o apunta su dedo �ndice hacia ti y pronuncia unas "
                "palabras.\nEl ni�o dice: Creil Uz Tir�m.\nAl momento un rayo sale de su dedo "
                "y se dirige hacia ti.\n");
            SetSpellName("proyectil el�ctrico");
            int v=0;
            if (d3() ==1)
            {
                say("El ni�o crea un rayo bifurcado que impacta dos veces en "+
                    capitalize(enemigo->QueryName())+".\n",enemigo);
                tell_object(enemigo,"�El ni�o crea un rayo bifurcado!\n");
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
            tell_object(enemigo,"El ni�o extiende un brazo y lo eleva por encima de su cabeza, "
                "se concentra y aparece en su mano una lanza de �cido que instant�neamente te "
                "lanza con fuerza.\n");
            say("El ni�o extiende un brazo y lo eleva por encima de su cabeza, se concentra y "
                "aparece en su mano una lanza de �cido que instant�neamente lanza contra "+
                capitalize(enemigo->QueryName())+".\n",enemigo);
            play_sound(environment(),SND_MAGIA("lanzaacido"));
            SetSpellName("Lanza de �cido");
            enemigo->Defend(danyo, DT_ACID, DEFEND_SPELL);
            SetSpellName(0);
        break;
        case 5:
            if (QuerySP() <20) break;
            AddSP(-20);
            tell_object(enemigo,"El ni�o cierra los ojos y se concentra. Un intenso escalofr�o "
                "recorre tu cuerpo y el p�nico te paraliza.\n");
            say("El ni�o cierra los ojos y se concentra. De repente "+
                capitalize(enemigo->QueryName())+" comienza a temblar de p�nico.\n",enemigo);
            play_sound(environment(),SND_MAGIA("miedoparalizante"));
            SetSpellName("MiedoParalizante");
            enemigo->SetCombatDelay(10,"Est�s paralizad"+AO+" por el miedo.\n");
            SetSpellName(0);
        break;
        case 6:
            if (QuerySP() <40) break;
            AddSP(-40);
            tell_object(enemigo,"El ni�o cierra los ojos. Al instante crea una tromba de "
                "meteoritos que te dan de lleno ��CLOCK!!.\n");
            say("El ni�o cierra los ojos. Al instante crea una tromba de meteoritos que "
                "impactan en "+capitalize(enemigo->QueryName())+".\n",enemigo);
            play_sound(environment(),SND_MAGIA("meteorito"));
            SetSpellName("Meteorito");
            enemigo->Defend(danyo*4, DT_FIRE, DEFEND_SPELL);
            SetSpellName(0);
        break;
        case 7:
            if (QuerySP() <100) break;
            AddSP(-100);
            say("El ni�o entona un extra�o rezo a Sherek. Ves como el poder de la diosa le "
                "fortalece, devolvi�ndole toda su salud y fuerza de esp�ritu.\n");
            SetSpellName("Curar verdadero");
            SetHP(QueryMaxHP());
            SetSP(QueryMaxSP());
            SetSpellName(0);
        break;
        case 8:
            if (QuerySP() <30) break;
            AddSP(-30);
            tell_object(enemigo,"El ni�o clava la vista en ti y pronuncia unas palabras.\nEl "
                "ni�o dice: Creil shal dh�l.\nAl instante notas como algo invisible te golpea.\n");
            say("El ni�o clava la vista en "+capitalize(enemigo->QueryName())+" y pronuncia "
                "unas palabras.\nEl ni�o dice: Creil shal dh�l.\n"+
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
    write("El ni�o ve tu pobre intento de detenerle, y con una dulce sonrisa, te dice "
        "con su voz suave: No, no. Conmigo eso no te vale.\n");
    say("el ni�o ve el pobre intento de "+TNAME+" de detenerle, y le sonr�e "
        "dulcemente dici�ndole: No, no. Conmigo eso no te vale.\n",TP);
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
            tell_room(environment(TP),"Yalin se inclina hacia su ni�o y le tiende los brazos.\n",({TP}));
            command_me("desempu�ar armas");
            tell_room(environment(TP),"El ni�o pone cara de mimo, y se abandona complacido en los brazos de su amante "
                "protectora.\n",({TP}));
        }
        else
        {
            write("El ni�o sonr�e condescendiente mientras te esquiva y te dice: Eh, sin "
                "tocar. A m� s�lo me coge mi dulce reina.\n");
            return ME_NO_GET;
        }
    }
    if (method == M_DROP && pl && query_once_interactive(pl))
    {
        if (TP->QueryRealName() == "yalin")
        {
            tell_room(environment(TP),"Yalin se inclina, y besando a su ni�o con dulzura, le "
                "deposita suavemente en el suelo.\n",({TP}));
            command_me("empu�ar armas");
            tell_room(environment(TP),"El ni�o se yergue, y con elegancia, se alisa la t�nica. "
                "Acto seguido,  empu�a su arma.\n");
        }
    }   
    return ::move(dest, method, extra);
}
