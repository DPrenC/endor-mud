/*****************************************************************************************
 ARCHIVO:       cathrann.c
 AUTOR:         Ztico
 FECHA:         14-01-2006
 COMENTARIOS:   Cathrann, Gran Sacerdote de la Orden de los Druidas.
                Personaje principal para el quest del Santuario Druida.

                QUEST_KEY: santuario_druida_quest
*****************************************************************************************/

#include "./path.h"
#include "./runas_quest.h"
#include <gremios.h>
#include <properties.h>
#include <moving.h>

#define RUNAS ({"Cernunos", "Morgana", "Beli", "Belisama", "Balor"})

inherit NPC;

public string preguntar_problema();
public string preguntar_miembro();
public string preguntar_runas();
public string preguntar_lugar();
public void comprobar_runas(object ob, object pl);
public void devolver_runas(object ob, object pl);
public string dialogo();
public void dar_gracias(object pl);

public void create()
{
    if(::create()) return;

    SetStandard("cathrann", "elfo", ([GC_CONJURADOR: 80 + random(6)]), GENERO_MASCULINO);
    SetShort("Cathrann, el Druida");
    SetLong("Tienes ante tí la figura de Cathrann, el Sumo Sacerdote. Es un elfo alto, "
          "con unos profundos ojos marrones. Su tez es blanca y mortecina, aunque lleva "
          "varios tatuajes tanto en su frente como en los pómulos. Porta una celada de "
          "cuero verde con trabas de metal del mismo color, y de entre sus huecos "
          "aparece, trenzada, su rubia cabellera. Su ropaje es ceñido y de colores "
          "apagados. Lleva una capa sin vuelo y deja entrever una cenefa bordada en la "
          "coraza.\n");
    AddId(({"druida", "sacerdote"}));

    SetAggressive(0);
    SetAttackChance(1000);
    SetWhimpy(50);

    AddQuestion(({"problema", "ayuda", "preocupacion"}), SF(preguntar_problema), 1);
    AddQuestion(({"miembro", "antiguo miembro", "druida", "gleryn",
    	  "gleryn el hechicero", "hechicero"}), SF(preguntar_miembro), 1);
    AddQuestion(({"runa", "runas", "objetos"}), SF(preguntar_runas), 1);
    AddQuestion(({"lugar", "hechizo", "lugar diferente", "potente hechizo"}),
        SF(preguntar_lugar), 1);
    AddQuestion("santuario", "");

    InitChats(4, ({ SF(dialogo) }) );

}

public string preguntar_problema()
{
    string msg;

    //Si tiene hecho el quest...
    if(QUESTMASTER->QueryQuestSolved(QUEST_KEY, TP))
        return "Cathrann te mira profundamente y te dice: " + CAP(TNAME) + ", ya no "
               "necesito tu ayuda. Que el espíritu del Gran Roble esté contigo para "
               "siempre.\n";

    //Si no lo tiene hecho...
    else
    {
        msg = "'Malos tiempos acontecen con los trasgos apostados al oeste del bosque, "
              "en las montañas Cileryd. Gracias a extrañas coincidencias, los que aún "
              "habitamos en la isla estamos a salvo de su espíritu profanador. Sin "
              "embargo, recientemente, algo anda rondando por estos parajes. Las malas "
              "lenguas hablan de un antiguo miembro de la Orden de los Druidas.'";

        //Si ya ha preguntado con anterioridad...
        if(TP->QueryAttribute(ATTE_RUNAS))
            return "Cathrann te dice: " + msg + "\n";

        //"Activamos" el quest...
        TP->SetAttribute(ATTE_RUNAS, (["inic":1, "runas_dadas":({})]));
        return "Cathrann te dice: ¡Oh! Viajer" + AO + ", gracias por atenderme.\n" +
               msg + "\n";
    }
}

public string preguntar_miembro()
{
    //Si tiene hecho el quest...

    if(QUESTMASTER->QueryQuestSolved(QUEST_KEY, TP))
        return "Cathrann se encoge de hombros.\n";

    //Si no lo tiene hecho pero tiene "activado" el quest

    else if(TP->QueryAttribute(ATTE_RUNAS))
        return "Cathrann te dice: 'Hace casi medio siglo, desapareció de la isla la Hoz "
               "de oro con la que el oficiante, en el ritual de ofrendas, corta el "
               "muérdago de uno de los robles del Jardín de los deseos. Sin este objeto "
               "no se puede llevar a cabo tal acto, por lo que su pérdida causó una "
               "enorme conmoción entre los druidas de la Orden. Casi al mismo tiempo de "
               "notar la desaparición de la que te he hablado, el Druida Gleryn, fiel "
               "adorador de Balor, dios de las tinieblas, malo, cruel y despiadado, se "
               "desvaneció como por arte de magia. Poco tiempo después, se le encontró "
               "vagando por el pantano de Faeria y se descubrió que había robado la Hoz "
               "para fines que no nos atrevemos ni a imaginar. Tras la vuelta a la "
               "normalidad, fue expulsado de la Orden de los Druidas. La noticia de que "
               "pudiese haber regresado nos ha sorprendido ciertamente, y creemos que "
               "pudiera haber robado de nuevo. En esta ocasión los objetos afanados han "
               "sido cinco de las diez runas que forman parte del Santuario.'\n";
    else return "Cathrann se encoge de hombros.\n";
}

public string preguntar_runas()
{
    string msg;

    //Si tiene hecho el quest...
    if(QUESTMASTER->QueryQuestSolved(QUEST_KEY, TP))
        return "Cathrann te dice: 'Gracias a tu ayuda, el santuario está completo y el "
               "paso de energía vuelve a estar abierto.'\n";

    //Si no lo tiene hecho...
    else
    {
        msg = "Parece ser que las runas que faltan en el altar del santuario fueron "
              "robadas por Gleryn, el Hechicero. Como puedes observar, los menhires "
              "afectados fueron los de: Cernunos, dios de los animales; Morgana, diosa "
              "de la Guerra; Beli, dios de las aguas; Belisama, diosa del fuego y el de "
              "Balor, señor de las tinieblas. Sin estas preciadas reliquias, el "
              "Santuario está incompleto y el paso de energía cerrado.\nAunque no puedo "
              "asegurarte que haya sido Gleryn el ladrón, hace unos días y con la ayuda "
              "de artilugios y métodos que no estoy dispuesto a desvelar, descubrí que "
              "cada runa fue enviada a un lugar diferente mediante un potente hechizo.";

        //Si ya ha preguntado con anterioridad...
        if(TP->QueryAttribute(ATTE_RUNAS))
            return "Cathrann te dice: " + msg + "\n";

        TP->SetAttribute(ATTE_RUNAS, (["inic":1, "runas_dadas":({})]));
        return "Cathrann te dice: " + msg + "\n";
    }
}

public string preguntar_lugar()
{
    //Si tiene hecho el quest...
    if(QUESTMASTER->QueryQuestSolved(QUEST_KEY, TP))
        return "Cathrann se encoge de hombros.\n";
    else return "Cathrann te dice: Por lo que pude interpretar en mis investigaciones, "
                "el hechizo transportó cada runa cerca del elemento del dios al que "
                "representan. Así, la runa de Cernunos se puede encontrar en las "
                "cercanías de koek, la de Morgana en un lugar relacionado con la guerra. "
                "Las runas de Beli y Belisama no pueden estar muy lejos de aquí, busca "
                "en Siempreunidos y en el Bosque de Faeria. De la runa de Balor, no "
                "percibí nada concreto. Quizás siga en poder de quien la robó, aunque "
                "tengo la sensación de que no anda muy lejos de este lugar.\nEso es todo "
                "lo que te puedo decir viajer" + AO + ". La responsabilidad que "
                "representa el Cargo de Gran Sacerdote no me permite salir a buscarlas. "
                "Así que suerte, y que la fuerza y sabiduría de la Diosa Madre esté "
                "contigo.\n";
}

public string dialogo()
{
    string mensaje;

    if (!environment()) return "";
    switch(random(3))
    {
        case 0: mensaje = "Cathrann dice: 'Esto no puede estar pasando.'\n";
                break;
        case 1: mensaje = "Cathrann dice: 'Necesito a alguien que me ayude.'\n";
                break;
        case 2: mensaje = "Cathrann dice: 'Tengo una responsabilidad para con la orden, "
                          "si yo muero, ¿quién va a ocupar mi lugar?.'\n";
                break;
    }
    filter(all_inventory(environment()),
      (:call_other($1, "QueryIsPlayer") &&
        !QUESTMASTER->QueryQuestSolved("santuario_druida_quest", $1)?
        tell_object($1,$2) : 0:), mensaje);
}

public void notify_enter(mixed from, int method, mixed extra)
{
    if(method == M_GIVE) call_out("comprobar_runas", 1, PO, from);
}

public void devolver_runas(object ob, object pl)
{
    tell_object(pl, "Cathrann te devuelve " + SHORT(ob) + ".\n");
    say("Cathrann le devuelve " + SHORT(ob) + " a " + CAP(NNAME(pl)) + ".\n", pl);
    if(ob->move(pl) != ME_OK)
    {
        tell_object(pl, "Sin poder evitarlo, " + SHORT(ob) + " se te cae al suelo.\n");
        say("Sin poder evitarlo, a " + CAP(NNAME(pl)) + " se le cae " + SHORT(ob) +
            " al suelo.\n", pl);
        ob->move(environment());
    }
}

public void dar_gracias(object pl)
{
    tell_object(pl, "El druida entra en la choza, se te acerca y te dice: Gracias por "
         "tu ayuda " + CAP(NNAME(pl)) + ". Que la bendición de los dioses caiga sobre "
         "ti.\n\n[QUEST] Has resuelto el quest del Santuario Druida.\n");
    say("El druida entra y habla con " + CAP(NNAME(pl)) + ".\n", pl);
}

public void comprobar_runas(object ob, object pl)
{
    mapping runas;
    string nRuna;

    if(!pl) return;

    //Si el player se ha ido...
    if(!present(pl, environment()))
    {
        say("Cathrann mira hacia todos lados para hablar con " + CAP(NNAME(pl)) + ". Al "
            "ver que no está, suelta " + SHORT(ob) + " en el suelo mientras murmura algo "
            "ininteligible.\n");
        ob->move(environment());
        return;
    }

    //Si el objeto es una runa...
    if(nRuna = ob->QueryRuna())
    {
        //Si ya ha resuelto el quest...
        if(QUESTMASTER->QueryQuestSolved(QUEST_KEY, pl))
        {
            tell_object(pl, "Cathrann mira la runa y te dice: ¡Ah! Es una de las runas "
                "que necesitaba... Te la puedes quedar como recuerdo.\n");
            say("Cathrann mira la runa que le ha dado " + CAP(NNAME(pl)) + ", y le dice "
                "algo.\n", pl);
            devolver_runas(ob, pl);
            return;
        }

        //Si no es el propietario de la runa...
        if(ob->QueryOwner() != NREAL(pl))
        {
            write("Cathrann coge la runa y tras mirarla, te dice: La runa no tiene "
                "grabado ningún símbolo.\n");
            say("Cathrann le dice algo a " + CAP(NNAME(pl)) + ".\n", pl);
            devolver_runas(ob, pl);
            return;
        }

        //No tiene resuelto el quest...
        else
        {
            runas = pl->QueryAttribute(ATTE_RUNAS);

            //Si aún no ha preguntado al druida por el quest...
            if(!runas)
            {
                tell_object(pl, "Carthrann te dice: Deberías informarte antes de qué es "
                    "lo que necesito.\n");
                say("Cathrann le dice algo a " + CAP(NNAME(pl)) + ".\n", pl);
                devolver_runas(ob, pl);
                return;
            }

            //Si ya me había dado la runa con anterioridad...
            if(member(runas["runas_dadas"], nRuna) >= 0)
            {
                tell_object(pl, "Cathrann te dice: Ya me has dado con aterioridad la "
                    "runa de " + nRuna + ".\n");
                say("Cathrann le dice algo a " + CAP(NNAME(pl)) + ".\n", pl);
                devolver_runas(ob, pl);
                return;
            }
             //Recoge las 4 primeras runas
            if(sizeof(runas["runas_dadas"]) < 4)
            {
                tell_object(pl, "Cathrann te dice: ¡Oh! Es la runa de " + nRuna + ". "
                    "Muchas gracias, viajer" + AO + ".\n");
                say("Cathrann le dice algo a " + CAP(NNAME(pl)) + ".\n", pl);

                //Añado la runa al mapping
                m_add(runas, "runas_dadas", runas["runas_dadas"] += ({nRuna}));
                destruct(ob);
                return;
            }

            tell_object(pl, "Cathrann coge la runa, y acto seguido se dirige hacia los "
                  "menhires y va colocando las runas en los huecos correspondientes.\n"
                  "Cathrann pronuncia unas palabras y un haz de rayos aparece en el "
                  "centro del santuario.\n");
            say("Cathrann sale de la choza, dice algo y de repente un haz de rayos "
                "aparece en el centro del santuario.\n", pl);
            call_out("dar_gracias", 1, pl);
            destruct(ob);

            QUESTMASTER->qshout("\n[QUEST] " + CAP(NNAME(pl)) + " ha resuelto el quest "
                "del Santuario Druida.\n\n");
            QUESTMASTER->SetPlayerQuest(QUEST_KEY, pl);
            write_file(LOGS "DRUIDA_QUEST", ctime(time()) + " " + TNREAL + " [" +
                       pl->QueryLevel() + "]   Ha resuelto el quest del Santuario "
                       "Druida.\n");
            pl->RemoveAttribute(ATTE_RUNAS);
            pl->RemoveAttribute("tiene_retrato");

            return;
        }
    }
    tell_object(pl, "Cathrann te dice: ¡Ah! Un regalo, te lo agradezco, pero no lo "
        "necesito.\n");
    say("Cathrann le dice algo a " + CAP(NNAME(pl)) + ".\n", pl);
    devolver_runas(ob, pl);
    return;
}
