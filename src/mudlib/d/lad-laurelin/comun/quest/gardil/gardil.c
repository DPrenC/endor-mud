/*
DESCRIPCION : La bruja gardil
FICHERO     : /d/lad-laurelin/comun/quest/bruja/gardil.c
*/

#include "./path.h"
#include <properties.h>
#include <moving.h>
#include "quest.h"

inherit NPC;


public int QueryGardil() { return 1; }

string dialogo()
{
    switch(random(10))
    {
        case 0..4:
             filter(all_inventory(environment()),
                    (:   query_once_interactive($1)
                      && !QUESTMASTER->QueryQuestSolved(TQUEST, $1)
                      && ESTADO_QUEST($1) == SIN_HACER ?
                      tell_object($1,"Gardil te dice: Si quieres ayudarme, "
                                      "pregúntame sobre mi problema.\n"):
                      0 :));
             break;
        case 5..9:
              filter(all_inventory(environment()),
                (: query_once_interactive($1) && !QUESTMASTER->QueryQuestSolved(TQUEST, $1)?tell_object($1,"Gardil tose sonoramente.\n"):0 :));
            break;
      }
    return "";
}

private string explicar_enfermedad()
{
    if (QUESTMASTER->QueryQuestSolved(TQUEST, TP))
    {
        return "Gardil te dice: '¿Enfermedad? Gracias a tu inestimable ayuda ahora "
               "estoy mejor que nunca. De verdad, nunca me cansaré de darte "
               "las gracias.' Gardil te sonríe.\n";
    }
    if (ESTADO_QUEST(TP) > SIN_HACER)
    {
        return "Gardil te dice: Pues sigo igual que la última vez que me preguntaste. "
               "¿Has conseguido algún remedio para mí?\n";
    }
    return "Gardil te mira con ojos tristes mientras te dice con voz apagada: "
           "'Finalmente, la edad y la dureza de mi trabajo han conseguido "
           "mermar mi salud y sumirme en una enfermedad que, o mucho me equivoco, "
           "o acabará conmigo si no consigo la ayuda de alguien que domine las "
           "complejas artes de la curación.'\n";
}

private string preguntar_curandero()
{
    string msg;
    object carta;
    int perdio_la_carta;

    if (QUESTMASTER->QueryQuestSolved(TQUEST, TP))
    {
        return "Gardil te dice: 'Desde que conseguiste que Kionix me "
               "ayudara, ya he recibido varias cartas de él pidiéndome que vaya a "
               "visitarlo... Dice que quiere demostrar a los habitantes de su "
               "pueblo que es capaz de obrar aún pociones poderosas... La verdad "
               "es que después de lo que ha hecho por mí no puedo negarme. Quizás me acerque por Flenton algún día.'\n";
    }
    msg = "Gardil dice: 'Hace tiempo, conocí a un kender que decía ser un "
          "reconocido shamán, capaz de hacer las pociones más sorprendentes. "
          "Si te soy sincera, ni recuerdo como se llama ni dónde vive en "
          "la actualidad, pero imagino que vivirá en algún lugar junto con "
          "los de su raza.\n"
          "Si quisieras ayudarme te estaré eternamente agradecida. ";
    if (ESTADO_QUEST(TP) > CON_CARTA)
    {
        msg += "Bueno, después de hacerme repetir la historia del shamán... ¿tienes "
               "alguna buena noticia que darme? ¿Lo encontraste? ¿Te dio la poción "
               "que le pedí en mi carta?\n";
    }
    else if (ESTADO_QUEST(TP) == CON_CARTA)
    {
        msg += "Uhm, pero ahora que lo pienso, creo que ya te conté esta "
               "historia antes, ¿No? ";
        if (   !sizeof(filter(deep_inventory(TP), (:$1->id("carta_quest_gardil"):)))
            && !(carta = present("carta_quest_gardil", environment())))
        {
            msg += "Uhm.... ¿No me digas que has perdido la carta? Bueno, "
                   "no te preocupes, escribí varias, por si acaso.\n";
            perdio_la_carta = 1;
        }
        else if (carta)
        {
            msg += "¿Y la carta que te di? ¡No me digas que la has perdido! "
                   "¡Ah! ¡Mírala! ¡pero si está en el suelo! Uhm... Debe "
                   "habérsete caído al dártela yo.\n";
        }
        else
        {
            msg += " Por favor, busca al shamán y dale la carta que te di, mi vida "
                   "depende de ti.\n";
        }
    }
    if (ESTADO_QUEST(TP) == SIN_HACER)
    {
        msg += "Aquí tienes una carta que escribí hace mucho al shamán, pero al que "
               "nadie ha querido ayudarme a encontrar hasta el momento. Tómala, y "
               "mucha suerte.\n";
    }

    if (!perdio_la_carta && ESTADO_QUEST(TP) != SIN_HACER) return msg;

    carta = clone_object(QUEST_GARDIL("carta_gardil"));
    carta->SetOwner(TNREAL);
    if (carta->move(TP) != ME_OK)
    {
        msg += "La carta se te escurre y cae al suelo.\n";
        say("Gardil le da una carta a " + CAP(TNAME) + ", pero se le cae al suelo.\n", TP);
        carta->move(environment());
    }
    else
    {
        say("Gardil le da una carta a " + CAP(TNAME) + ".\n",TP);
        msg += "Gardil te da una carta.\n";
    }
    TP->SetAttribute(ATR_QUEST, CON_CARTA);
    return msg;
}

public string desc_larga()
{
    if (QUESTMASTER->QueryQuestSolved(TQUEST, TP)) {
        return "Ves a Gardil, la hechicera. Después de que la ayudaras parece muy feliz.\n";
    }
    return W("Ves a Gardil, la elfa. Su fama de hechicera poderosa no conoce fronteras,"
             " aunque ahora no parece estar en su mejor momento. Mientras te mira "
             "con sus ojos sin vida te pregunta: 'Pareces interesado en mí, si quieres "
             "ayudarme pregúntame sobre mi problema'.\n");
}


create()
{
  ::create();
  SetStandard("Gardil","elfo",50,GENDER_FEMALE);

  SetShort("Gardil, la hechicera");
  SetLong(SF(desc_larga));
  AddId("hechicera");
  AddQuestion(({"problema", "enfermedad"}), SF(explicar_enfermedad), 1);
  AddQuestion(({"curandero", "sanador"}), SF(preguntar_curandero), 1);

  InitChats(20, ({ SF(dialogo) }) );
}


public void recoger_pocion(object pl, object ob)
{
    object env = environment();
    if (!ob || !pl) return;
    tell_object(pl, "Gardil te sonríe y te agradece que le hayas traido la poción.\n");
    tell_room(env, "Gardil sonríe a " + CAP(NNAME(pl)) + ".\n", ({pl}));
    tell_room(env, "De un trago, se toma el contenido del vial.\n");
    if (ESTADO_QUEST(pl) != POCION_CONSEGUIDA || ob->QueryOwner() != NREAL(pl))
    // ha hecho trampa, la poción no es del player
    {
        tell_room(env, "Súbitamente, se agarra la garganta y sus ojos se abren "
                       "desorbitados, con una expresión de miedo y dolor. Al instante, "
                       "cae fulminada al suelo...\n");
        tell_object(pl, "Parece ser que la poción que le has dado no era de fiar...\n");
        LeaveCorpse();
        remove();

        return;
    }
    tell_room(env, "De forma sorprendente, ves como el rostro enfermizo de la elfa "
                   "recupera un color saludable, y sus ojos, antes apagados, brillan "
                   "ahora con un vigor renovado.\n");
    tell_object(pl, "Con lágrimas en los ojos, la hechicera te abraza y te agradece "
                    "que le hayas ayudado a recuperar la salud.\n");
    tell_room(env, "Con lágrimas en los ojos, la hechicera abraza a " + CAP(NNAME(pl)) +
                   " y le agradece varias veces su ayuda.\n", ({pl}));
    QUESTMASTER->SetPlayerQuest(TQUEST, pl);
    pl->RemoveAttribute(ATR_QUEST);
    QUESTMASTER->InformSolution("Gardil ha sido curada por " + CAP(NNAME(pl)) + ".\n");
    ob->remove();
}


public void notify_enter(mixed from, int method, mixed extra)
{
    object ob = PO;
    object pl = to_object(from);

    if (   !pl ||!ob || method != M_GIVE || QUESTMASTER->QueryQuestSolved(TQUEST, pl)
        || ESTADO_QUEST(pl) < CON_CARTA || !ob->id("pocion_curar_gardil"))
    {
        return;
    }
    // lo que se le está dando es la poción
    call_out("recoger_pocion", 1, pl, ob);
}


