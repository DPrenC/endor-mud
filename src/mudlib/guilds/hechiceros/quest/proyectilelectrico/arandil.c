/*
DESCRIPCION : el hechicero arandil
FICHERO     : /guilds/quest/proyectilelectrico/arandil.c
MODIFICACION: 22-10-00 [Maler] Creacion
              29-12-04 [Nyh] Peta que da gusto, lo arreglo.
                             Y de paso lo sangro y lo pongo legible y lo optimizo.
                             Creo q no esta arreglado, pero con ponerlo legible
                             he tenido suficiente por hoy. Q puto infierno.
              17/01/2005: [kastwey]. Nyh. contin�o el trabajo y me cargo el heart_beat.
              04/03/2005: [kastwey]: Le meto algunos hechizos
                             que la gente se lo carga que da gusto,
                             y encima da un huevo de XP.
--------------------------------------------------------------------------------
*/
#include "./path.h"
#include <guild.h>
#include <moving.h>
#include <spellmonster.h>
#include <colours.h>
#include <combat.h>
#include <properties.h>
#include <sounds.h>
inherit SPELLMONSTER;

static string pSpellName;
void aviso();
public string SetSpellName(string conj) { return pSpellName = conj; }
public string QuerySpellName() { return pSpellName; }
public status check_sp();
public int magia();
void devolver_objeto(object ob, object pl);
void comprobar_objeto(object ob, object pl);
string dialogo();
string preguntar_problema();
string preguntar_mapa();
string preguntar_forlafil();
string preguntar_sello();
object enemigo;

//Devuelve un long si le has ayudado y otro si no lo has hecho

public string change_long()
{
    string msg;

    msg = "Ves a Arandil, el hechicero. Va todo vestido de negro, y te sonr�e cuando "
        "pasas junto a �l.\nArandil no es muy conocido, pero es famoso por ser "
        "incre�blemente avaricioso.\n";

    //Compruebo gremio.
    if (!TP) return msg;

    if(TP->QueryGuild() != GC_HECHICERO)
        return  msg + "Realmente, no parece ser gran cosa, pero a veces las apariencias "
                      "enga�an.\n";

    //compruebo si le has ayudado o no
    if(    !(TP->QuerySpells()["proyectil electrico"])
        ||  TP->QuerySpells()["proyectil electrico", 1]<70)
        return msg + "Cuando te fijas, ves que te est� mirando, como si quisiera hacerte "
                     "una proposici�n.\n";
    return msg;
}

create()
{
    ::create();
    SetStandard("arandil", "elfo", ([GC_HECHICERO:40]), GENDER_MALE);
    SetShort("Arandil, el famoso hechicero");
    SetLong(SF(change_long));
    AddId("hechicero");

    AddQuestion(({"busqueda", "problema", "alteracion", "preocupacion"}),
        SF(preguntar_problema), 1);
    AddQuestion(({"mapa", "Mapa"}), SF(preguntar_mapa), 1);
    AddQuestion(({"forlafil", "Forlafil", "explorador"}), SF(preguntar_forlafil), 1);
    AddQuestion(({"sello", "Sello"}), SF(preguntar_sello), 1);

    SetCastChance(60);
    AddSpell("conjuros",
        ([
            S_CHECKFUN: SF(check_sp),
            S_FUN: SF(magia),
            S_SP: 2,
            S_CHANCE: 100,
            S_DELAY: 5,
            S_VICTIMS: 1,
        ]));
    InitChats(10, ({ SF(dialogo) }));
}

void comprobar_objeto(object ob, object player)
{
    int i;
    mapping spells;
    if (!environment()) return;
    if (!player || !present(player,environment()))
    // el player se ha largao
    {
        tell_room(environment(), "Arandil mira hacia todos lados buscando a quien le ha "
            "dado " + SHORT(ob) + ". Extra�ado, pone cara de disgusto y suelta " +
            SHORT(ob) + ".\n");
        ob->move(environment());
        return;
    }

    if (player->QueryGuild() != GC_HECHICERO ||
        member(ob->QueryIds(),"spell_proyectil_arandil") < 0)
    {
        tell_object(player, "Arandil te dice: Oh " + CAP(NNAME(player)) + ". �Un regalo? "
            "Lo siento, pero no puedo aceptarlo.\n");
        say("Arandil le dice algo a " + CAP(NNAME(player)) + ".\n", player);
        devolver_objeto(ob, player);
        return;
    }

    spells = player->QuerySpells();
    if(!spells["proyectil electrico"] || spells["proyectil electrico", 1] < 70)
    // no lo tiene, o lo tiene a nivel < 70 as� que se lo ense�a
    {
        tell_object(player, "Arandil te dice: ��Lo has conseguido!! Vaya, no me esperaba "
            "esta ayuda, ahora podr� continuar mi b�squeda.\n\n"
            "Arandil te mira y te dice: Pero creo que voy a recompensarte por tus "
            "esfuerzos.\n"
            "Arandil te ense�a el hechizo 'proyectil el�ctrico', hasta que llegas a "
            "dominarlo en su base.\n");
            TP->AddPlayerSpell("proyectil electrico", random(5)+1, 70, P_INT);
    }
    else
    // ya tiene un nivel aceptable de conjuro
    // as� que es porque ya le ha dado el mapa
    {
        write("Arandil te dice: Gracias, amig" + (player->QueryGender() == 2?"a":"o") + ", "
            "pero.... ya me hab�as dado el mapa.\nArandil sonr�e.\n");
        return;
    }
    ob->remove();
    return;
}


void notify_enter(mixed from,int method,mixed extra)
{
    if (from && query_once_interactive(from) && method == M_GIVE) call_out("comprobar_objeto", 1, PO, from);
    return ::notify_enter(from, method, extra);
}

void devolver_objeto(object ob, object pl)
{
    tell_object(pl, "Arandil te devuelve " + SHORT(ob) + ".\n");
    say("Arandil le devuelve " + SHORT(ob) + " a " + CAP(NNAME(pl)) + ".\n", pl);
    if (ob->move(pl) != ME_OK)
    {
        tell_object(pl, "Sin poder evitarlo, " + SHORT(ob) + " se te cae al suelo.\n");
        say("Sin poder evitarlo, a " + CAP(NNAME(pl)) + " se le cae " + SHORT(ob) +
            " al suelo.\n", pl);
        ob->move(environment());
    }
}

string dialogo()
{
    string mensaje;

    if (!environment()) return 0;
    switch(random(2))
    {
        case 0: mensaje = "Arandil te pregunta: Estoy buscando un Mapa, �no habr�s visto "
        	                "alguno en tus viajes?.\n";
        	      break;
        case 1: mensaje = "Arandil comienza a decir frases inconexas sobre 'el Mapa'.\n";
        	      break;
    }

    foreach(object ob: all_inventory(environment())) {
      if (   query_once_interactive(ob)
          && ob->QueryGuild() == GC_HECHICERO
          && (  !ob->QuerySpells()["proyectil electrico"]
              || ob->QuerySpells()["proyectil electrico", 1] < 70)
         )
      {
        tell_object(ob, mensaje);
      }
    }

    return 0; // [Nyh] Para evitar el warning de no return
}

public int QueryArandil() { return 1; }

string preguntar_problema()
{
    if (!query_once_interactive(TP)) return "";
    if (TP->QueryGuild() != GC_HECHICERO)
        return "Oh " + CAP(TNAME) + ". S� que tengo un problema, pero solo puede "
               "solucion�rmelo un hechicero. �Conoces alguno?\n";
    else if (!(TP->QuerySpells() || ([]))["proyectil electrico"] ||
              (TP->QuerySpells() || ([]))["proyectil electrico", 1] < 70)
    {
        return "Arandil te dice: En el gremio me mandaron una b�squeda a cambio de las "
               "ense�anzas que all� me imparten, encontrar el anillo de Erkil. Erkil el "
               "herrero fue el m�s grande luchador del bien, y tambi�n del mal, y muri� "
               "con su anillo colgado al cuello, y con �l, seg�n la leyenda, fue "
               "enterrado.\nEl anillo es un artefacto de gran poder, que contiene ambos "
               "reinos, el del bien, que fue su origen, y el del mal, que fue su fin. "
               "Debo encontrarlo lo antes posible. He oido de la existencia de un mapa "
               "con la posici�n del t�mulo que podr�a ayudarme.\nArandil sonr�e "
               "nervioso.\nHace tiempo envi� a Forlafil, un explorador, a buscar el "
               "mapa.\nA estas alturas deber�a haberlo encontrado ya, tendr�s que buscar "
               "mi sello para identificarte ante �l.\n";
    }
    return "Arandil te dice: �Problema? �Oh No! Desde que me diste el mapa estoy "
           "haciendo grandes progresos en mi b�squeda.\n";
}

string preguntar_mapa()
{
    if (!query_once_interactive(TP)) return "";
    if (TP->QueryGuild() != GC_HECHICERO)
        return "Oh " + CAP(TNAME) + ". Estoy buscando un mapa, pero yo necesitar�a la "
               "ayuda de un hechicero. �Conoces alguno?\n";

    else if (!(TP->QuerySpells() || ([]))["proyectil electrico"] ||
              (TP->QuerySpells() || ([]))["proyectil electrico", 1] < 70)
    {
        return "Arandil te dice: El Mapa, creado por los propios dioses para "
               "proporcionar una posibilidad obligatoria para encontrar ese lugar "
               "imp�o.\nObligatoria, si, pues la tierra se corrompi� al enterrar a "
               "Erkil, y esa zona s�lo conoc�a el mal. Por ello los dioses la sellaron, "
               "y, para no atentar contra el equilibrio que rige toda la naturaleza, "
               "crearon el Mapa, que mostraba el �nico camino posible hasta el t�mulo, "
               "y que, adem�s, era la llave. �se es el mapa que necesito.\n";
    }
    return "Arandil te mira y te dice: �Mapa? �Claro! Desde que me lo diste, estoy "
           "haciendo notables progresos en mi b�squeda.\n";
}

string preguntar_forlafil()
{
    if (!query_once_interactive(TP)) return "";
    if (TP->QueryGuild() != GC_HECHICERO)
        return "Arandil te dice: �Forlafil? �Le has visto? Es un explorador que mand� en "
               "busca de un mapa y a�n no ha regresado con noticias.\n";

    else if (!(TP->QuerySpells() || ([]))["proyectil electrico"] ||
              (TP->QuerySpells() || ([]))["proyectil electrico", 1] < 70)
    {
        return "Arandil te dice: Forlafil es un explorador bastante bueno. Su habilidad "
               "innata no tiene igual en el mundo. Le envi� a la b�squeda del mapa, y le "
               "dije que mi mensajero, el que recoger�a el mapa, llevar�a mi sello para "
               "identificarse como tal. Sin el sello, Forlafil no te dar� el mapa.\n"
               "Forlafil suele moverse por el bosque de Talek, seguramente le "
               "encontrar�s all�.\n";
    }
    return "Arandil te dice: �Forlafil? Claro. Forlafil es el explorador que "
           "encontraste, y quien te di� el mapa.\n";
}

string preguntar_sello()
{
    if (!TP || !query_once_interactive(TP)) return "";
    if (TP->QueryGuild() != GC_HECHICERO)
        return "Arandil te dice: Es un sello que tengo, y que me identifica ante quien "
               "lo conozcan.\n";

    else if (!(TP->QuerySpells() || ([]))["proyectil electrico"] ||
              (TP->QuerySpells() || ([]))["proyectil electrico", 1] < 70)
    {
        return "Arandil te dice: Mi valioso sello. Mis contactos me han dicho que fue "
               "sustra�do a mi anterior mensajero por los ladrones de la fortaleza de "
               "Cored.\nB�scalo all�.\n";
    }
    return "Arandil te dice: �El sello? S�, es el que encontraste y mostraste a Forlafil "
           "a fin de conseguir mi mapa.\n";
}

void aviso()
{
    write("Arandil sonr�e maliciosamente d�ndote a entender que tu intento de "
        "inmovilizarle fue in�til.\n");
    say("Arandil sonr�e maliciosamente a " + CAP(TNAME) + ", d�ndole a entender que su "
        "intento de inmovilizarlo fue in�til.\n", TP);
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

public int magia()
{
    int pv, i;
    object *adversarios;
    adversarios = QueryEnemies();
    if(!sizeof(adversarios)) return 0;
    enemigo=adversarios[random(sizeof(adversarios))];
    switch (random(100))
    // todos los conjuros que lanza.
    {
        case 0 .. 19:/*bola de fuego*/ //de 1 a 20 en masa

            if (!TO->QuerySP() >= 20)
                break;
            TO->AddSP(-20);
            pv = random(20) + 1;
            play_sound(environment(),SND_MAGIA("bolafuego"));
            tell_room(ENV(TO), TC_RED "Arandil hace un gesto con sus manos mientras "
                "pronuncia unas extra�as palabras: �Creil Ignem Spzereph!!!\n"
                "Al instante, aparece entre sus manos una gran bola de fuego que impulsa "
                "hacia delante impactando sobre todos sus adversarios.\n" TC_NORMAL);
            SetSpellName("bola de fuego");
            call_other(adversarios, "Defend", pv, TD_CALOR, DEFEND_SPELL);
            SetSpellName(0);
            break;

        case 21..30: // proyectil el�ctrico

            if (QuerySP() < 25)
                break;
            AddSP(-25);
            tell_room(ENV(TO), "Arandil apunta su dedo �ndice hacia " +
                CAP(NNAME(enemigo)) + "y pronuncia unas palabras.\nArandil dice: Creil "
                "Uz Tir�m.\nAl momento un rayo sale de su dedo hacia " +
                CAP(NNAME(enemigo)) + ".\n", ({enemigo}));
            tell_object(enemigo, "Arandil apunta su dedo �ndice hacia ti y pronuncia "
                "unas palabras.\nArandil dice: Creil Uz Tir�m.\nAl momento un rayo sale "
                "de su dedo y se dirige hacia ti.\n");
            pv = 30 + random(QueryInt() / 2);
            SetSpellName("proyectil el�ctrico");
            int v=1;

            if (QueryInt() + random(20) > 40)
            {
                tell_room(ENV(TO), "Arandil crea un rayo bifurcado que impacta dos veces "
                    "en " + CAP(NNAME(enemigo)) + ".\n", ({enemigo, TO}));
                tell_object(enemigo, "�Arandil crea un rayo bifurcado!\n");
                enemigo->Defend(pv, TD_ELECTRICIDAD, DEFEND_SPELL);
            v=2;
            }
            play_sound(environment(),SND_MAGIA("proyectil"),0,100,v);
            enemigo->Defend(pv, TD_ELECTRICIDAD, DEFEND_SPELL);
            SetSpellName(0);
            break;

        case 31..70: // lanza de fuego
            if (QuerySP() < 25)
                break;
            AddSP(-25);
            pv = 40 + random(QueryInt());
            tell_room(ENV(TO), "Arandil cierra los ojos. Al instante sientes un calor "
                "intenso en la habitaci�n y ves su fuente, una lanza de fuego que "
                "levita al lado de �l. Con un movimiento vertiginoso abre los ojos y la "
                "arroja sobre " + CAP(NNAME(enemigo)) + ".\n", ({enemigo, TO}));
            tell_object(enemigo, "Arandil cierra los ojos. Al instante sientes un calor "
                "intenso en la habitaci�n y ves su fuente, una lanza de fuego que levita "
                "al lado de �l. Con un movimiento vertiginoso abre los ojos y la arroja "
                "sobre ti.\n");
            play_sound(environment(),SND_MAGIA("lanza_fuego"));
            SetSpellName("lanza de fuego");
            enemigo->Defend(pv, TD_ACIDO, DEFEND_SPELL);
            SetSpellName(0);
            break;

        case 81..100: // golpe de descarga
            if(QuerySP() < 15)
                break;
            AddSP(-15);
            pv = 20 + random(QueryInt());
            tell_room(ENV(TO), "Arandil clava la vista en " + CAP(NNAME(enemigo)) + " y "
                "pronuncia unas palabras .\nArandil dice: Creil shal dh�l.\n" +
                CAP(NNAME(enemigo)) + " retrocede como si hubiese sido golpead" +
                (enemigo->QueryGender() == 2?"a":"o") + " por algo invisible.\n",
                ({enemigo,TO}));
            tell_object(enemigo, "Arandil clava la vista en ti y pronuncia unas palabras"
                ".\nArandil dice: Creil shal dh�l.\nAl instante notas como algo "
                "invisible te golpea.\n");
            play_sound(environment(),SND_MAGIA("golpedescarga"));
            SetSpellName("golpe de descarga");
            enemigo->Defend(pv, TD_APLASTAMIENTO, DEFEND_SPELL);
            SetSpellName(0);
        break;
    }
    return 1; // [Nyh] Para evitar el warning del no return
}
