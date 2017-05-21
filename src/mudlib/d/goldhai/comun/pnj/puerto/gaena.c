/*=============================================================*
 |            << GOLDHAI.Puerto [w] Woo@simauria >>            |
 *=============================================================*
 |               Creacion.............. 15-05-99               |
 |               Ultima Modificacion... 29-05-99               |
 |                                                             |
 *=============================================================*/

#include "path.h"
#include <properties.h>
#include <wizlevels.h>
#include <moving.h>
#include <messages.h>
#include <guild.h>
#include <spellmonster.h>
#include <combat.h> // Para AT_CLOAK
#include <magicd.h>

inherit SPELLMONSTER;

int cegando();

void recoger_(object cnt, object pl)
{
    if (!pl) return;
    if (pl->QueryGender() == GENERO_MASCULINO)
    {
        write("Gaena clava su mirada furiosa en ti, y con voz tomada por la ira grita: ¿Por "
            "quién me has tomado, arrogante presuntuoso? ¿Piensas que puedes seducirme "
            "haciéndome regalos?\nActo seguido, te propina una sonora bofetada, y con un gesto "
            "de rabia, arroja "+cnt->QueryShort()+" al mar.\n");
        say("Gaena clava su mirada furiosa en "+capitalize(pl->QueryName())+", y con voz "
            "tomada por la ira grita: ¿Por quién me has tomado, arrogante presuntuoso? "
            "¿Piensas que puedes seducirme haciéndome regalos?\nActo seguido, le propina una "
            "sonora bofetada, y con un gesto de rabia, arroja "+cnt->QueryShort()+" al mar.\n",pl);
        cnt->remove();
        return;
    }
    if (pl->QueryGuild() != "kisala")
    {
        write("Gaena mueve la cabeza y te dice con voz pausada: Lo siento, yo sólo hago "
            "favores a las chicas de mi gremio. No acepto regalos ni sobornos.\nY acto "
            "seguido, te devuelve "+cnt->QueryShort()+".\n");
        say("Gaena mueve la cabeza y dice a "+capitalize(pl->QueryName())+" con voz pausada: "
            "Lo siento, yo sólo hago favores a las chicas de mi gremio. No acepto regalos ni "
            "sobornos.\nY acto seguido, le devuelve "+cnt->QueryShort()+".\n",pl);
        cnt->move(pl,M_SILENT);
        return;
    }
    if ((!pl->QueryAttribute("aceptadogaena")) || (cnt->id("cinturon_gaena") < 0))
    {
        write("Gaena te sonríe dulcemente, y devolviéndote "+cnt->QueryShort()+" con un gesto "
            "negativo de cabeza te dice: Gracias, pero no necesito "+cnt->QueryShort()+
            ". Guárdalo para mejor ocasión, yo tengo todo cuanto preciso para vivir.\n");
        say("Gaena sonríe dulcemente a "+capitalize(pl->QueryName())+", y devolviéndole "+
            cnt->QueryShort()+" con un gesto negativo de cabeza le dice: Gracias, pero no "
            "necesito "+cnt->QueryShort()+". Guárdalo para mejor ocasión, yo tengo todo cuanto "
            "preciso para vivir.\n",pl);
        cnt->move(pl,M_SILENT);
        return;
    }
    write("Los ojos de Gaena se iluminan con un brillo de satisfacción, y dándote un caluroso "
        "abrazo, dice: Sí, justo así era, es exactamente como el que tenía. Gracias, muchas "
        "gracias, amiga. Bien, lo prometido es deuda.\nA continuación, introduce la mano en su "
        "túnica, guardando el cinturón, y saca un pergamino que te entrega.\n");
    say(capitalize(pl->QueryName())+" da algo a Gaena. Ésta lo mira con mirada satisfecha, y "
        "tras abrazarla, saca de su túnica algo que entrega a "+capitalize(pl->QueryName())+".\n",pl);
    cnt->remove();
    object pergamino = clone_object("/guilds/kisalas/pergamino/pergamino_luz_cegadora");
    if (!pergamino->move(pl)) pergamino->move(environment(TO));
    pl->RemoveAttribute("aceptadogaena");
    return;
}

string dialogo()
{
    foreach(object jug : all_inventory(environment()))
    {
        if (query_once_interactive(jug))
        {
            switch (d4())
            {
                case 1:
                    tell_object(jug,"Gaena te mira y sonríe.\n");
                break;
                case 2:
                    if (jug->QueryGender() == GENERO_FEMENINO)
                    {
                        if (jug->QueryGuild() == GC_KISALA) tell_object(jug,"Gaena "
                            "te sonríe y dice: ¿Qué tal va todo, colega? Un día "
                            "de estos tengo que ir al gremio, hace mucho que no "
                            "veo a Shilda.\n");
                        else tell_object(jug,"Gaena te dice: ¿Qué quieres, niña? "
                            "¿No te han dicho que es una descortesía mirar así a "
                            "la gente?\n");
                    }
                    else tell_object(jug,"Gaena te dice: ¿Por qué me miras? ¿qué "
                        "pasa? ¿te gusto?.\n");
                break;
                case 3:
                    object ob = present("vara",TO);
                    if (ob) tell_object(jug,"La kisala mueve su vara y empieza a "
                        "hacer malabares con ella.\n");
                    else tell_object(jug,"Gaena mueve las manos como si hiciese "
                        "malabares con una vara invisible.\n");
                break;
                case 4:
                    mapping Spells;
                    Spells=jug->QuerySpells() || ([]);
                    if (jug->QueryGuild() == GC_KISALA)
                    {
                        if (!Spells["luz cegadora"] || Spells["luz cegadora", 1]<70)
                        {
                            if (present("luz cegadora",jug))
                            {
                                tell_object(jug,"Gaena hace un "
                                    "gesto con la mano mientras te dice: Y bien, ¿no vas a "
                                    "memorizar el hechizo?, ¿no quieres controlar la luz ?.\n");
                                break;
                            }
                            if (jug->QueryAttribute("aceptadogaena"))
                            {
                                tell_object(jug,"Gaena te "
                                    "mira fijamente y te invita a irte con un gesto diciendo: "
                                    "Bueno, ¿vas a ir a buscar lo que te he pedido?\n");
                                    break;
                                }
                            if (!jug->QueryAttribute("habladogaena")) tell_object(jug,
                                "Gaena te observa y dice: Hmmm, pareces muy joven "
                                "para andar sola por el mundo... Hay fuerzas muy poderosas, "
                                "¿sabes? Por ejemplo, la luz... Sí, es muy útil, pero..., "
                                "bueno, a lo mejor no te interesa. Si quieres conocer el poder "
                                "de la luz, pregúntame sobre ella.\n");
                            else tell_object(jug,"Gaena te guiña un ojo y dice: Y "
                            "dime entonces, ¿No te interesa el pergamino del "
                            "hechizo?\n");
                        }
                        else tell_object(jug,"Gaena te mira fijamente y exclama: "
                            "¡Vaya! Ya veo que controlas la luz..., llegarás "
                            "lejos, aunque no basta con eso, no creas.\n");
                        break;
                    }
                    tell_object(jug,"Gaena te dice con impaciencia: ¿Y a ti "
                        "qué se te ha perdido por aquí? No estoy de humor para "
                        "compañía, ¿sabes?\n");
                break;
            }
        }
    }
    return 0;
}

string m_informa()
{
    if (TP->QueryGuild() == GC_KISALA)
    {
        mapping Spells;
        Spells=TP->QuerySpells() || ([]);
        if (!Spells["luz cegadora"] || Spells["luz cegadora", 1]<70)
        {
            if (!TP->QueryAttribute("habladogaena"))
            {
                TP->SetAttribute("habladogaena",time());
                return"Gaena te observa con dulzura, y habla sonriendo: La luz, sí. Todos la "
                    "necesitamos para ver, saber lo que nos rodea, poder distinguir a nuestros "
                    "enemigos, herir e impedir ser heridos. Sin embargo, un exceso de luz "
                    "puede ser..., es tan incapacitante como su falta.\nEs posible deslumbrar "
                    "a tu oponente y aprovecharte de ello, ¿sabes? nosotras, las kisalas, "
                    "podemos controlar la luz, y utilizarla contra otros, y así tenerlos a "
                    "nuestra merced. Existe un pergamino muy antiguo, que contiene "
                    "el hechizo de 'luz cegadora'. Yo podría..., bueno, "
                    "tal vez podría dártelo...\n";
            }
            else return "Gaena suspira pacientemente y te dice: Ya te lo he "
                "dicho, niña. Si quieres saber sobre el hechizo, pregunta.\n";
        }
        else return "Gaena te mira complacida, y con un gesto de "
            "suficiencia te dice: ¿Qué quieres que te diga, chica? tú ya "
            "sabes bastante sobre eso.\n";
    }
    return "Gaena se ríe en tus narices y te dice burlona: ¿La luz? ¿De veras quieres saberlo? "
        "No me hagas reír. Si sigues molestándome, yo te haré sentir su poder.\n";
}

string p_informa()
{
    if (TP->QueryGender() == GENERO_MASCULINO) return "Gaena grita enfadada: "
        "¿Y a ti qué te importa, entrometido? Los asuntos de mi gremio no "
        "son para machos arrogantes.\n";
    if (TP->QueryGuild() != GC_KISALA) return "Gaena te dice cortésmente: Lo "
        "siento, chica, pero eso no es para ti. Cosas de mi gremio, ¿sabes?\n";
    mapping Spells;
    Spells=TP->QuerySpells() || ([]);
    if (!Spells["luz cegadora"] || Spells["luz cegadora", 1]<70)
    {
        if (TP->QueryAttribute("aceptadogaena")) return "Gaena te mira "
            "tranquilizadora y dice: Sí, sí. Lo tengo, no te preocupes por "
            "eso. ¿Me has traído lo que acordamos?\n";
        if (!TP->QueryAttribute("habladogaena")) return "Gaena susurra "
            "enigmática: Sí, un hechizo muy poderoso..., mucho.\n";
    return "La cara de la hechicera se ilumina, y con voz a un tiempo dulce "
        "y anhelante te dice: Bueno, hace tiempo vino a mis manos, no "
        "importa cómo, un ejemplar de ese pergamino. Son escritos muy "
        "antiguos y escasos. Te lo daré, pero a cambio tepediré un pequeño "
        "favor. Verás:\nHace tiempo yo tenía un precioso cinturón de piel de "
        "serpiente, piel de una serpiente no muy corriente, y un día, "
        "bañándome en la playa, un sujeto me lo robó. Excuso decirte que..., "
        "bueno, sirvió de comida a los cuervos, pero cuando le encontré, el "
        "muy cerdo ya lo había vendido. Consígueme uno, y te daré el "
        "pergamino. Creo que es justo, ¿no?\nSi estás de acuerdo con el "
        "trato, dime que aceptas.\n";
    }
    return "Gaena frunce el ceño y te dice: Bueno, tú ya sabes lo poderoso "
        "que es. Haz buen uso de él, lo cortés no quita lo valiente.\n";
}

public string c_informa()
{
    if (TP->QueryAttribute("aceptadogaena")) return "Gaena te dice: Ya te lo dije, sentí mucho "
        "su pérdida, y te agradezco tu ayuda. Ahora, ¿irás a buscarme uno igual?\n";
    if (TP->QueryAttribute("habladogaena")) return "gaena te dice: entonces, ¿vas a traérmelo? "
        "Si es así, dime que aceptas.\n";
    return QueryShrugMsg();
}

int trato()
{
    if (TP->QueryAttribute("aceptadogaena"))
    {
        write("Gaena mueve la cabeza mientras dice: Sí, sí, estamos de "
            "acuerdo. Ahora, ¿querrás irte ya a buscar lo que te he pedido?\n");
        return 1;
    }
    if (TP->QueryAttribute("habladogaena"))
    {
        write("La hechicera asiente con la cabeza, y te explica: De acuerdo entonces. Era un "
            "cinturón precioso, hecho con la piel de una pitón real, con una gama de colores "
            "exquisita, negro, crema, amarillo y blanco. Lo ví en casa de Theull, el artesano "
            "de Crowy, y..., bueno, a parte de eso, era un cinturón especial, muy especial "
            "para mí. Consígueme uno igual, y te daré el pergamino.\n");
        TP->SetAttribute("aceptadogaena",time());
        TP->RemoveAttribute("habladogaena");
        return 1;
    }
    return 0;
}

create()
{
  ::create();
  if (!clonep()) return;

    seteuid(getuid());
    SetStandard("Gaena", "elfo", ([GC_KISALAS: 50]), GENERO_FEMENINO);
    SetIds(({"Gaena","gaena","kisala","amazona","elfa","hechicera","hechicera kisala"}));
    SetShort("Gaena, la hechicera kisala");
    SetLong("Gaena es una elfa de piel pálida y larga cabellera negra, que "
        "cae libre por su espalda hasta llegar a su cintura. Porta una "
        "túnica color celeste, que descansa sobre su esbelto cuerpo y "
        "termina algo más arriba de sus rodillas. Sus ojos, de un negro "
        "intenso, te producen una sensación de seguridad en sí misma, mas "
        "sin expresar arrogancia ni superioridad.\n");
    SetAlign(100);
    SetWhimpy(20);
    AddQuestion(({"luz"}),SF(m_informa),1);
    AddQuestion(({"hechizo","pergamino de hechizo","luz cegadora",
        "pergamino de luz cegadora","hechizo de luz cegadora"}),SF(p_informa),1);
    AddQuestion(({"pergamino","pergaminos"}),"Gaena te mira con desdén y "
        "dice: Vaya pregunta, un pergamino es una hoja de papel que se usa "
        "para escribir. Cualquier niño lo sabe.\n");
    AddQuestion(({"cinturon","cinturón","cinturon de piel","cinturón de piel"}),SF(c_informa),1);
    AddQuestion(({"serpiente"}),"Gaena te mira burlona y dice: Pues, por lo que yo sé, son "
        "unos bichos fríos, alargados y sin patas, que se arrastran por ahí...\n");
    AddQuestion(({"piton","pitón","piton real","pitón real","serpiente piton","serpiente pitón"}),
        "Gaena reflexiona un momento y te dice: Bueno, es una especie muy rara, aunque..., sí, "
        "he oído decir que se han visto algunas por esta isla.\n");
    SetShrugMsg("Gaena pone cara de extrañeza y dice: No sé de qué me hablas.\n");
    SetCastChance(20);
    SetSpellChance(1000);
    AddSpell("luz cegadora",
    ([
        S_FUN:SF(cegando),
        S_SP:2,
        S_CHANCE:1000,
        S_VICTIMS:1,
    ]));
    AddItem("/obj/armas/vara", REFRESH_REMOVE,
        ([P_LONG: "Es una vara de madera de ébano. A lo largo de toda su "
            "superficie puedes observar gran cantidad de símbolos tallados.\n",
        P_NUMBER_HANDS: 2,
        P_SIZE: P_SIZE_MEDIUM,
        P_SUB_DETAILS:(["simbolos":"Son unos símbolos tallados a lo largo de "
            "toda la vara.\n",
            "símbolos":"Son unos símbolos tallados a lo largo de "
                "toda la vara.\n",
            "runas":"Son unos símbolos tallados a lo largo de "
                "toda la vara.\n"])]),SF(wieldme));
    AddItem("/std/armour", REFRESH_REMOVE,
        ([ P_LONG: "Se trata de una túnica de color azul celeste que tapa la "
            "mitad del tronco y parte de los muslos. En el pecho observas un "
            "símbolo consistente en una K y una S entrelazadas.\n",
        P_SUB_DETAILS: ([ "simbolo": "Es un símbolo consistente en una K y "
                "una S entrelazadas.\n",
            "símbolo": "Es un símbolo consistente en una K y una S "
                "entrelazadas.\n"]),
        P_SHORT: "una túnica azul celeste",
        P_IDS: ({ "tunica", "túnica", "túnica azul", "tunica azul",
            "túnica azul celeste", "tunica azul celeste"}),
        P_MATERIAL: M_TELA,
        P_GENDER:   GENDER_FEMALE,
        P_SIZE:     P_SIZE_MEDIUM,
        P_WEIGHT:   750, // gramos
        P_AC:       4,
        P_ARMOUR_TYPE: AT_CLOAK,]), SF(wearme));
    InitChats(15,SF(dialogo));
}

init()
{
    object folleto;
    ::init();
    add_action("trato","acepto");
    if (   !query_once_interactive(TP) || query_wiz_level(TP)
        || TP->QueryGuild() == "kisala" || TP->QueryGender() !=GENERO_FEMENINO)
    {
        return;
    }
    if (present("folleto_kisala",TP)) return;
    folleto=clone_object(OTRO("folleto_kisala"));
    if (folleto->move(TP) != ME_OK)
    {
        folleto->remove();
        return;
    }
    write("Gaena te dice: Hola, leete esto y nos conocerás mejor.\n");
    write("Gaena te da un folleto.\n");
    say("Gaena le da un folleto a "+TNAME+".\n",({TP}));
    return;
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

void notify_enter(mixed from,int method,mixed extra)
{
  	if (method == M_GIVE) call_out("recoger_",1,PO,from);
}
