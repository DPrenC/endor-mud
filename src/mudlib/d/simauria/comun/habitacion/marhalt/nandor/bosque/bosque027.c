/****************************************************************************
Fichero: bosque027.c
Autor: Ratwor
Fecha: 09/12/2006
Descripción: Dentro del río.
****************************************************************************/

#include "./path.h"
#include <skills.h>
#include <properties.h>
#include <combat.h>
#include <moving.h>
#include <sounds.h>

inherit SIM_ROOM;
#define AO       (this_player()->QueryGender()==GENDER_FEMALE ? "a" : "o")
private varargs string snd_ambiente(int newstate);
private string last_sound;
object llega;
// Las orillas del río hacia el oeste del salto de piedras.
object *orillas =
        ({MARH("nandor/bosque/bosque026"), MARH("nandor/bosque/bosque028"),
          MARH("nandor/bosque/bosque029"), MARH("nandor/bosque/bosque019"),
          MARH("nandor/bosque/bosque008"), MARH("nandor/bosque/bosque007"),
          MARH("nandor/bosque/bosque017"), MARH("nandor/bosque/bosque018"),
          MARH("nandor/bosque/bosque009"), MARH("nandor/bosque/bosque010")});

//Para que la corriente del río se lleve los objetos que entran en el agua.
public void notify_enter(mixed from, int method, mixed extra)
{
    ::notify_enter(from, method, extra);
    if (!PO) return;
    call_out("dejar",d2(), PO);
}

public string mirar_orilla_sur(){
    object sur = find_object(MARH("nandor/bosque/bosque030"));
    if (!sur)
    return "esa es la orilla del sur.\n";
    write(sur->QueryIntLong()+ sur->Content());
    return "";
}

public string mirar_orilla_norte(){
    object norte = find_object(MARH("nandor/bosque/bosque020"));
    if (!norte)
    return "Esa es la orilla norte.\n";
    write(norte->QueryIntLong()+ norte->Content());
    return "";
}

int f_orilla_sur(){
    if (TP->QueryTP()<1)
        return notify_fail("Observas la orilla sur y te la ves tan lejos, aunque "
        "antes no te lo parecía... te cuesta respirar.\n Por el esfuerzo realizado "
        "has agotado tus fuerzas y te encuentras fatigad"+AO+", deberías descansar "
            "un rato.\n");
    switch(TP->UseSkill(HAB_NADAR)){
        case -100.. -60:
            write("Intentas acercarte a la orilla sur, pero la corriente te entorpece la "
            "maniobra, tragas agua, braceas fuertemente...  y te cansas sin haber "
            "conseguido moverte practicamente nada.\n");
            say(CAP(TNAME)+" intenta salir del agua aproximandose a la orilla sur,"
            " pero se cansa por la fuerza de la corriente.\n");
            tell_room(MARH("nandor/bosque/bosque030"), CAP(TP->QueryName())+
            " intenta salir del agua nadando hacia esta orilla , pataleando y braceándo"
            ", pero la corriente puede más y se cansa sin apenas moverse.\n");
            tell_room(MARH("nandor/bosque/bosque020"), CAP(TP->QueryName())+
            " intenta salir del agua nadando hacia la orilla  del sur, pataleando y "
            "braceándo, pero la corriente puede más y se cansa sin apenas moverse.\n");
            TP->AddTP(-d4());
            TP->Defend(d4(),DT_NOAIR, DEFEND_F_NOLIV | DEFEND_F_NOMSG | DEFEND_NO_DEF_SK);
            return 1;
            break;
        case -59..24:
            TP->move(MARH("nandor/bosque/bosque030"),M_SPECIAL,
            ({" hace un gran esfuerzo braceando y pataleando por superar a la corriente,"
            " y por fin lo consigue pudiendo salir del río en su orilla sur",
            "consigue llegar a la orilla junto a ti tras un gran esfuerzo",
            "braceas y pataleas eufóricamente para alcanzar la orilla sur...\n Tragas un "
            "poco de agua...\n Y por fin consigues alcanzar la orilla y salir del río"}));
            tell_room(MARH("nandor/bosque/bosque020"), CAP(TP->QueryName())+
            " consigue llegar a la orilla sur tras un largo esfuerzo.\n");
            TP->AddTP(-d3());
            TP->Defend(d2(),DT_NOAIR, DEFEND_F_NOLIV | DEFEND_F_NOMSG | DEFEND_NO_DEF_SK);
            return 1;
            break;
        case 25..100:
            TP->move(MARH("nandor/bosque/bosque030"),M_SPECIAL,
            ({"nada vigorosamente hacia la orilla sur del río y sale sin problemas",
            "sale del río junto a ti sin problemas",
            "te acercas a la orilla sur del río y sales sin problemas"}));
            tell_room(MARH("nandor/bosque/bosque020"), CAP(TP->QueryName())+
            " consigue llegar a la orilla sur con gran maestría.\n");
        TP->AddTP(-d2());
            return 1;
            break;
    }
    return 0;
}

int f_orilla_norte(){
    if (TP->QueryTP()<1)
        return notify_fail("Observas la orilla norte y te la ves tan lejos, aunque "
        "antes no te lo parecía... te cuesta respirar.\n Por el esfuerzo realizado "
        "has agotado tus fuerzas y te encuentras fatigad"+AO+", deberías descansar "
        "un rato.\n");
    switch(TP->UseSkill(HAB_NADAR)){
        case -100.. -60:
            write("Intentas acercarte a la orilla norte, pero la corriente te entorpece la"
            " maniobra, tragas agua, braceas fuertemente...  y te cansas sin haber "
            "conseguido moverte practicamente nada.\n");
            say(CAP(TNAME)+" intenta salir del agua aproximandose a la orilla norte,"
            " pero se cansa por la fuerza de la corriente.\n");
            tell_room(MARH("nandor/bosque/bosque030"), CAP(TP->QueryName())+
            " intenta salir del agua nadando hacia la orilla  del norte, pataleando y "
            "braceándo, pero la corriente puede más y se cansa sin apenas moverse.\n");
            tell_room(MARH("nandor/bosque/bosque020"), CAP(TP->QueryName())+
            " intenta salir del agua nadando hacia esta orilla  pataleando y braceándo,"
            " pero la corriente puede más y se cansa sin apenas moverse.\n");
            TP->Defend(d4(),DT_NOAIR, DEFEND_F_NOLIV | DEFEND_F_NOMSG | DEFEND_NO_DEF_SK);
            TP->AddTP(-d4());
            return 1;
            break;
        case -59..24:
            TP->move(MARH("nandor/bosque/bosque020"),M_SPECIAL,
            ({" hace un gran esfuerzo braceando y pataleando por superar a la corriente,"
            " y por fin lo consigue pudiendo salir del río en su orilla norte",
            "consigue llegar a la orilla junto a ti tras un gran esfuerzo",
            "braceas y pataleas eufóricamente para alcanzar la orilla norte...\n Tragas un"
            " poco de agua...\n Y por fin consigues alcanzar la orilla y salir del río"}));
            tell_room(MARH("nandor/bosque/bosque030"), CAP(TP->QueryName())+
            " consigue llegar a la orilla norte tras un largo esfuerzo.\n");
            TP->AddTP(-d3());
            TP->Defend(d2(),DT_NOAIR, DEFEND_F_NOLIV | DEFEND_F_NOMSG | DEFEND_NO_DEF_SK);
            return 1;
            break;
        case 25..100:
            TP->move(MARH("nandor/bosque/bosque020"),M_SPECIAL,
            ({"nada vigorosamente hacia la orilla norte del río y sale sin problemas",
            "sale del río junto a ti sin problemas",
            "te acercas a la orilla norte del río y sales sin problemas"}));
            tell_room(MARH("nandor/bosque/bosque030"), CAP(TP->QueryName())+
            " consigue llegar a la orilla norte con gran maestría.\n");
            TP->AddTP(-d2());
            return 1;
            break;
    }
    return 0;
}

int f_contracorriente(){
    if (TP->QueryTP()<1)
        return notify_fail("Te encuentras agotad"+AO+" por el esfuerzo, deberías "
        "descansar.\n");
    TP->UseSkill(HAB_NADAR);
    write("Nadas fuertemente hacia el este avanzando unos metros, pero te cansas y "
        "vuelves al mismo sitio arrastrad"+AO+" por la corriente de las aguas.\n");
    say (CAP(TP->QueryName())+ " intenta nadar hacia el este, pero se cansa por la "
        "fuerza de la contracorriente y no se mueve del sitio.\n");
    tell_room(MARH("nandor/bosque/bosque020"), CAP(TP->QueryName())+
        " todavía sigue en el agua y ahora intenta nadar contracorriente hacia "
        "el este, pero se cansa enseguida sin haberse movido del sitio.\n");
    tell_room(MARH("nandor/bosque/bosque030"), CAP(TP->QueryName())+
        " todavía sigue en el agua y ahora intenta nadar contracorriente hacia "
        "el este, pero se cansa enseguida sin haberse movido del sitio.\n");
    TP->AddTP(-d4(2));
    return 1;
}

int f_arrastrado(){
    llega = orillas[random(sizeof(orillas))];
    TP->UseSkill(HAB_NADAR);
    TP->move(llega, M_SPECIAL,
        ({"es arrastrad"+AO+" por la corriente hacia el oeste",
        "llega hasta esta orilla arrastrad"+AO+" por la corriente del río desde el este "
        "y sale rapidamente del agua magullad"+AO+" y agotad"+AO,
        "nadas hacia el oeste y la corriente te facilita tanto las cosas que eres "
        "arrastrad"+AO+" energicamente sin poder evitarlo...\n Pasan unos segundos "
        "en los que no consigues hacerte con el control de tu cuerpo. Sientes que la "
        "corriente te arrastra a trompicones haciéndote chocar con distintas rocas,"
        " hasta que consigues agarrarte en un saliente de alguna de las orillas, algo"
        " más al oeste de donde caíste al agua.\n Consigues reunir fuerzas y sales "
        "del agua magullad"+AO+" y agotad"+AO}));
    tell_room(MARH("nandor/bosque/bosque020"), CAP(TP->QueryName())+
        " es arrastrad"+AO+" por la corriente río abajo hacia el oeste.\n");
    tell_room(MARH("nandor/bosque/bosque030"), CAP(TP->QueryName())+
        " es arrastrad"+AO+" por la corriente río abajo hacia el oeste.\n");
    TP->AddTP(-d4(3));
    TP->Defend(d6(4),DT_NOAIR, DEFEND_F_NOLIV | DEFEND_F_NOMSG | DEFEND_NO_DEF_SK);
    return 1;
}

create(){
    ::create();
    SetIntShort("medio de las aguas del río Kandal");
    SetIntLong("Dentro de las frías aguas del río, la corriente pasa rauda de este a"
        " oeste,  entre las tres rocas que sobresalen y las cuales se podrían utilizar"
        " para cruzarlo saltando sobre ellas.\n Ambas orillas, tanto al sur como"
        " al norte, se encuentran relativamente próximas facilitando la salida del "
        "río en cualquiera de las dos direcciones.\n Debido a la poca produndidad del "
        "Kandal en esta parte, de tan sólo un metro y medio, cualquier raza de medio "
        "tamaño puede mantenerse sin ser arrastrado por la corriente.\n");
    SetIndoors(0);
    SetSoundEnvironment(SF(snd_ambiente), 65);
    AddDetail(({"suelo", "arena", "tierra"}),"El suelo aquí es simplemente arena "
        "mojada. El agua es tan clara, y hay tan poca profundidad en esta parte,  que "
        "te permite ver el fondo. Por distintas partes observas algunos pozos dejados "
        "por la corriente al replegarse en algunas zonas. Es la misma arena fina y "
        "limpia que se insinuaba ya en las cercanías de las orillas.\n");
    AddDetail(({"bosque", "árboles", "arboles", "vegetacion", "vegetación"}),
        "Todo el bosque, con sus correspondientes árboles rodea el río en toda su "
        "extensión, tanto hacia el norte como al sur.\n");
    AddDetail(({"rio","río", "río kandal", "rio kandal", "rio Kandal", "río Kandal",
        "agua", "corriente", "kandal", "Kandal", "aguas"}),
        "Las aguas del río Kandal discurren de este a oeste, dirección a la costa "
        "de Simauria.\n Parece que a los pececillos no les molestan tu presencia, pues "
        "nadan cerca de tus pies tranquilamente.\n En esta parte del río la profundidad"
        " es de apenas un metro y medio, y sus dos orillas están relativamente "
        "próximas.\n");
    AddDetail(({"pez", "peces", "pececillos", "pececillo", "pececito", "pececitos"}),
        "Albunos más grandes que otros, unos más bonitos, otros más normales, pero "
        "todos nadan tranquilamente en las frías aguas.\n");
    AddDetail("rocas", "Son tres grandes rocas puestas en medio de las aguas del "
        "Kandal por la naturaleza, y las cuales permiten cruzar el río de una orilla "
        "a otra.\n");
    ForbidAllMagic("Intentas concentrarte, pero estando dentro del agua no lo consigues"
        " y la magia se te escapa pensando en la humedad que están cogiendo tus "
        "huesos.\n");
    AddRoomCmd("pescar", "cmd_pescar");
    AddRoomCmd("gritar", "cmd_gritar");
    AddRoomCmd("rodar","cmd_rodar");
    AddRoomCmd("beber", "cmd_beber");
    AddRoomCmd("dormir","cmd_dormir");
    AddRoomCmd("encender", "cmd_encender");
    AddRoomCmd("coger", "cmd_coger");
    AddRoomCmd(({"acostarse", "tumbarse", "sentarse", "levantarse", "descansar"}),
        "cmd_acciones");
    AddRoomCmd("nadar", "cmd_nadar");
    AddRoomCmd("bañarse", "cmd_bañarse");
    AddRoomCmd("barrer", "cmd_barrer");
    AddDetail(({"orilla norte", "norte", "orilla del norte"}), SF(mirar_orilla_norte));
    AddDetail(({"orilla sur", "orilla del sur", "sur"}), SF(mirar_orilla_sur));
    AddExit("norte", SF(f_orilla_norte));
    AddExit("sur",SF(f_orilla_sur));
    AddExit("oeste", SF(f_arrastrado));
    AddExit("este", SF(f_contracorriente));
    HideExit("este",1);
    HideExit("oeste",1);

}

init(){
    ::init();
    call_out("agua",1);
}

public void agua(){
    object ob = TP ||PO;
    foreach(object inv:all_inventory(ob))
    {
        if (inv->QueryBurning())
        {
            tell_object(ob, "A "+ inv->QueryShort() + " le ha entrado agua y se apaga.\n");
            inv->SetBurning(0);
        }
    }
}

int cmd_encender(string str){
    if (str=="lampara" || str=="lámpara" || str=="antorcha") {
        write("Dentro del río no conseguirás encenderla.\n");
        return 1;
    }
    write("¿Qué quieres encender?.\n");
    return 1;
}

int cmd_rodar(){
    write("Con esta corriente no es muy aconsejable ponerse a hacer piruetas, ¿no "
        "crees?.\n");
    return 1;
}

int cmd_dormir(){
    write("Te colocas boca arriba flotando en las aguas del río Kandal y cierras los "
        "ojos intentando coger el sueño, pero la corriente te mueve demasiado y "
        "desistes del empeño de dormir sobre el agua, posiblemente no sea muy "
        "recomendable.\n");
    say(CAP(TP->QueryName())+" se coloca boca arriba intentando flotar sobre las "
        "aguas, pero se zarandea demasiado y vuelve a tomar posición normal.\n");
    tell_room(MARH("nandor/bosque/bosque020"), CAP(TP->QueryName())+
            " intenta flotar boca arriba sobre las aguas del río, no lo consigue y se "
            "cansa enseguida volviendo a su postura normal.\n");
    tell_room(MARH("nandor/bosque/bosque030"), CAP(TP->QueryName())+
            " intenta flotar boca arriba sobre las aguas del río, no lo consigue y se "
            "cansa enseguida volviendo a su postura normal.\n");
    return 1;
}

int cmd_beber(string str) {
    if (!str || str=="agua"){
        if (TP->QueryDrink() >= TP->QueryMaxDrink()){
            return notify_fail("Ya estás llen"+AO+" de agua, no puedes beber más.\n",
            NOTIFY_NOT_VALID);
        }
        TP->AddDrink(5);
     write("Coges un poco de agua del río con las manos y te la bebes.\n");
        say(TP->QueryName()+" coge un poco de agua del río con sus manos y se la bebe.\n",TP);
        return 1;
    }
    return notify_fail("Tienes abundante abua para beber, aprovecha.\n",NOTIFY_NOT_VALID);
}

int cmd_coger(string str){
if (str=="pez" || str=="peces" || str=="pececito" || str=="pececitos" || str=="pececillo"
        || str=="pececillos"){
        write("Intentas coger un pez de los que nadan tranquilamente entre tus pies, "
            "pero se te escurren, sin una caña va a ser complejo.\n");
        say(CAP(TP->QueryName())+ " hace unos movimientos raros debajo del agua, "
            "parece que esté peleando con los peces.\n");
    tell_room(MARH("nandor/bosque/bosque020"), CAP(TP->QueryName())+
        " hace unos movimientos raros debajo del agua con las manos.\n");
    tell_room(MARH("nandor/bosque/bosque030"), CAP(TP->QueryName())+
        " hace unos movimientos raros debajo del agua con las manos.\n");
        return 1;
    }
    return 0;
}

int cmd_pescar(){
    write("Normalmente se pesca fuera del agua, mejor hazlo desde la orilla.\n");
    return 1;
}

int cmd_acciones(){
    write("Eso mejor hazlo fuera del agua.\n");
    return 1;
}

int cmd_nadar(){
    TP->UseSkill(HAB_NADAR);
    if (TP->QueryTP()>2){
        write("Decides nadar un ratito aprovechando tu estancia en remojo...\n Braceas"
        " un poquito por aquí, haces una pirueta por allá...\n Te cansas un poco, mejor "
        "tómatelo con calma y no te muevas mucho.\n");
        say(CAP(TP->QueryName())+ " se pone a nadar un poco de un lado para otro sin "
        "moverse mucho.\n");
        tell_room(MARH("nandor/bosque/bosque020"),CAP(TP->QueryName())+
        " sigue en el agua y aprovecha para nadar un ratito, pero sin moverse mucho.\n");
        tell_room(MARH("nandor/bosque/bosque030"),CAP(TP->QueryName())+
        " sigue en el agua y aprovecha para nadar un ratito, pero sin moverse mucho.\n");
        TP->AddTP(-d4());
        return 1;
    }else{
        write("Te sientes agotad"+AO+", intenta descansar un rato.\n");
        return 1;
    }
    return 0;
}

int cmd_bañarse(){
    write("Ya estás en remojo, ¿no te es suficiente?.\n");
    return 1;
}

public void dejar(object ob){
    object seguidor;
    llega = orillas[random(sizeof(orillas))];
    if (!ob) return;
    if (!ob->QueryIsPlayer() || (ob->IsPlayer() || (ob->QuerySize() <2))){
        if (seguidor=(present("esfera", TO)) || seguidor=(present("elemental", TO))
            || seguidor=(present("sombra", TO))){
            write("Pierdes la concentración y "+seguidor->QueryShort()+" se difumina "
            "hasta desaparecer.\n");
            say(CAP(seguidor->QueryShort())+" se difumina hasta que desaparece.\n");
            destruct(seguidor);
        }

        ob->move(llega);
        tell_object(ob,"A causa de tu pequeño tamaño no consigues hacer pie en las poco "
        "profundas aguas del río y eres arrastrad"+AO+" en dirección a la corriente.\n"
        " Das muchas vueltas bajo el agua, te sientes maread"+AO+", te golppeas "
        "varias veces con algunas rocas, y por fin consigues alcanzar una de las "
        "orillas del río y salir del agua con multitud de heridas.\n");
        tell_room(MARH("nandor/bosque/bosque027"), CAP(ob->QueryShort())+
        " es arrastrad" +(ob->QueryGenderEndString())+ " por la corriente del río "
            "hacia el oeste.\n");
        tell_room(MARH("nandor/bosque/bosque020"), CAP(ob->QueryShort())+
        " es arrastrad"+(ob->QueryGenderEndString())+" por la corriente del río "
            "hacia el oeste.\n");
        tell_room(MARH("nandor/bosque/bosque030"), CAP(ob->QueryShort())+
        " es arrastrad" +(ob->QueryGenderEndString())+ " por la corriente del río "
            "hacia el oeste.\n");
        tell_room(llega, CAP(ob->QueryShort())+ " llega hasta esta orilla tras "
        "haber sufrido el arrastre de la corriente del río.\n",({ob}));
        ob->AddTP(-d6(3));
        ob->Defend(d6(4),DT_NOAIR, DEFEND_F_NOLIV | DEFEND_F_NOMSG | DEFEND_NO_DEF_SK);
    }
}

public int cmd_gritar(string str){
    if (!str){
        tell_room(MARH("nandor/bosque/bosque020"), CAP(TNAME)+" grita desde dentro de "
        "las aguas del río.\n");
        tell_room(MARH("nandor/bosque/bosque030"), CAP(TNAME)+" grita desde dentro de "
        "las aguas del río.\n");
        return 0;
    }else{
        tell_room(MARH("nandor/bosque/bosque020"), CAP(TNAME)+" grita desde dentro de "
        "las aguas del río: '"+str+"'.\n");
        tell_room(MARH("nandor/bosque/bosque030"), CAP(TNAME)+" grita desde dentro de "
        "las aguas del río: '"+str+"'.\n");
        return 0;
    }
    return 0;
}

public string cmd_barrer(){
    write("No sé cómo vas a barrer aquí en medio de las aguas...\n");
    return "";
}

public void NotifyDayStateChange(mixed data, int newstate)
{
    ::NotifyDayStateChange(data, newstate);
    snd_ambiente(newstate);
}

private varargs string snd_ambiente(int newstate)
{
    int hora;
    string sonido;

    if (newstate) hora = newstate;
    else hora = QueryServer()->QueryState();
    if(hora==ND_NIGHT || hora==ND_PREDAWN || hora==ND_DAWN || hora==ND_PRENIGHT)
    {
        sonido = SND_AMBIENTES("rio_grillos");
    }
    else
    {
        sonido = SND_AMBIENTES("rio_bosque");
    }
    if (newstate && sonido != last_sound)
    {
        stop_sounds(TO);
        play_sound(TO, sonido, 0, 65, -1);
    }
    last_sound = sonido;
    return sonido;
}

