/***************************************************************************************
 ARCHIVO:	kionix.c
 AUTOR:		[k] Korsario
 FECHA:		21-10-1998
 COMENTARIOS:	Kionix el shaman
 ***************************************************************************************/

#include <properties.h>
#include <moving.h>
#include <gremios.h>
#include "path.h"
#include <health.h>
#include "quest.h"

#define FLENVAR "/d/kenton/comun/objeto/otro/flenton/"
inherit NPC;

public int QueryShamanFlenton() { return 1; }

object poc;
int pocion;

reset(){
  ::reset();
  pocion=1;
}

create(){
  ::create();
  SetStandard("Kionix el shamán","kender",([GC_HECHICERO:10]),GENERO_MASCULINO);
  SetName("Kionix");
  SetIds(({"chaman","shaman","shamán","kender","kionix"}));
  pocion=1;

  SetShort("Kionix, el shamán");
  SetLong(W("Kionix, el shamán de Flenton. Es un kender muy peculiar. Dice "
  	"haber estudiado con los magos mas poderosos, y haber luchado con "
  	"monstruos gigantescos. Lo curioso es que nunca ha salido de los "
  	"alrededores de Flenton, salvo en una ocasión en que aseguro que "
  	"lo habian raptado unas hadas. Aunque son muchos los que piensan "
  	"que dicho incidente esta relacionado con la desaparición de un "
  	"barril de aguardiente en la taberna de Pikarus.\n"));
  AddQuestion(({"vino", "buen vino","el mejor vino"}),
              "Kionix te sonríe y te dice: 'El mejor vino es el que producen "
              "en Nandor, digan lo que digan los demás.\n");
  AddQuestion(({"pocion","poción"}),W("Yo tenía que darle una poción a alguien... "
  	"pero no me acuerdo a quién. Si quieres que te la de solo tienes que pedírmela.\n"));

  InitChats(5,({
  	"Kionix comienza a murmurar un cantico en voz baja.\n",
	"Kionix te dice: ¡Hola! ¿Qué deseas? ¿Acaso alguna poción magica?\n",
	W("Kionix comienza a mezclar el contenido de varios recipientes en "
		"un cuenco.\nDel cuenco sale una pequeña nube de humo de "
		"colorines...\nKionix exclama: ¡¡¡WoW!!! ¡¡Qué bonito!! ¡¡¡Me pregunto "
		"cómo lo habré hecho!!!\n"),
	W("Kionix se va hacia la estantería donde estan todos los frascos "
		"y comienza a contarlos.\n"),
	W("Kionix murmura: ¿Cómo demonios era esa poción? Un poco del frasco "
		"azúl, otro poco de este otro... ¿o era de este? ¡Bah! ¡De este "
		"mismo!\n"),
	W("Kionix dice: este Kendarg, me encargo una poción hace semanas y "
		"aún no ha venido por ella. ¡Ojalá recordase para qué era! Hmmm...\n")}));
  InitAChats(10,({
  	"Kionix grita: ¡¡Bien!! ¡¡Un combate!! ¡Cuanto tiempo sin divertirme!\n",
	"Kionix dice: ¿Es todo lo mejor que puedes hacerlo?\n"}));
}

init(){
  ::init();

  add_action("fpedir","pedir");
}

int fpedir(string str)
{
	if(!str)
	{
		notify_fail("¿Pedir <qué>?\n");
		return 0;
	}
	else if(str=="pocion" || str=="pocion para kendarg" || str=="poción" || str=="poción para kendarg")
	{
		if(!pocion)
		{
			write(W("Kionix dice: lo siento, alguien se la ha ido a "
				"llevar a Kendarg.\n"));
			return 1;
		}
		else
		{
			write(W("Kionix dice: asi que vienes a por la poción para "
				"Kendarg, genial!\n"));
			poc=clone_object(FLENVAR+"pocion");
			poc->move(TP,M_SILENT);
			write("El shamán te da una poción.\n");
			write("Kionix dice: dile a Kendarg que tenga cuidado con ella!\n");
			pocion=0;
			return 1;
		}
	}
	else
	{
		notify_fail("El shamán no sabe muy bien que le pides.\n");
		return 0;
	}
}

/*
move(dest,method,stuff)
{
	if(method==M_GO && dest->QueryLocate()!="flenton")
		return ME_NO_ENTER;
	return:: move(dest,method,stuff);
}
*/

public void notify_enter(mixed from, int method, mixed extra)
{
    object ob = PO;
    object pl = TP;

    if (   !pl ||!ob || method != M_GIVE || !environment()->QueryTiendaShaman()
        || QUESTMASTER->QueryQuestSolved(TQUEST, pl))
    {
        return;
    }

    if (ob->id("carta_quest_gardil")) call_out("recoger_carta",1, pl, ob);
    else if (ob->QueryIsVial() == (SP | HP)) call_out("recoger_vial", 1, pl, ob);
    else if (member(ob->QueryIds() ||({}), "vino") >= 0) call_out("recoger_vino", 1, pl, ob);
}


private void dar_objeto(object pl, object ob)
{
    string short = CAP(ob->QueryShort() ||ob->QueryName());
    if (ob->move(pl) != ME_OK)
    {
        tell_object(pl, short + " se te cae al suelo.\n");
        tell_room(environment(), "A " + CAP(NNAME(pl)) + " se le cae " + short +
                                 " al suelo.\n", ({pl}));
        ob->move(environment());
    }
}


public void recoger_vial(object pl, object ob)
{
    object env;
    if (!pl || !ob) return;
    if (!present(pl, (env = environment())))
    {
        tell_room(env, "Kionix dice: 'Uhm... Sospechoso, cuanto menos... Me da "
                       "un vial y se va... Seguro que está envenenado o algo...'\n"
                       "A continuación, lo tira al suelo.\n");
        ob->move(env);
        return;
    }

    if (ESTADO_QUEST(pl) != BUSCANDO_VIAL)
    {
        tell_object(pl, "Kionix te mira con suspicacia y te dice: ");
        tell_room(env, "Kionix mira a " + CAP(NNAME(pl)) + " con suspicacia y le dice: ",
                  ({pl}));
        tell_room(env, "'No, no, gracias, tómatelo tú si quieres... Los shamanes "
                       "tenemos una norma... Nunca te tomes las pociones de otros "
                       "si no vienen de alguien de confianza...'\n");
        tell_object(pl, "Kionix te devuelve el vial.\n");
        tell_room(env, "Kionix le devuelve el vial a " + CAP(NNAME(pl)) + ".\n", ({pl}));
        dar_objeto(pl, ob);
        return;
    }

    if (ob->Query_Vessel_Volume() == ob->QueryFull())
    {
        tell_object(pl, "Kionix mira el vial y te dice: Uhm, necesito un vial "
                        "a medio llenar. Haz el favor de darle un trago para "
                        "que me quede espacio para el resto de ingredientes de la "
                        "poción.\n"
                        "Kionix te devuelve el vial.\n");
        tell_room(env, "Kionix le dice algo a " + CAP(NNAME(pl)) + " y luego le "
                       "devuelve el vial.\n", ({pl}));
        dar_objeto(pl, ob);
        return;
    }

    if (!ob->QueryFull())
    // el vial está vacío
    {
        tell_object(pl, "Kionix te mira con mala cara y te dice: 'Vamos a ver. "
                        "Si la memoria no me falla, yo te pedí un vial de "
                        "regeneración para poder mezclarlo con mi poción, pero tú me "
                        "traes un vial vacío... ¿Qué pretendes "
                        "que haga con esto?'\nA continuación te devuelve el vial.\n");
        tell_room(env, "Kionix le dice algo a " + CAP(NNAME(pl)) + " con mala cara.\n",
                  ({pl}));
        dar_objeto(pl, ob);
        return;
    }

    if (ob->Query_Vessel_Volume() > ob->QueryFull())
    {
        tell_object(pl, "Kionix mira el vial y rápidamente lo coloca sobre "
                        "una estantería. Se frota las manos mientras te dice: "
                        "'Bien, bien, ahora sólo me queda añadirle........'\n\n"
                        "Kionix se da un puñetazo en la cabeza mientras exclama: "
                        "'¡Maldita sea! ¡Siempre se me olvidan los ingredientes!\n"
                        "¡ah! ¡ya se! ¡Necesito una botella del mejor vino que "
                        "puedas encontrar! ¡Tráemela y podré acabar de terminar la "
                        "poción para tu amiga la hechicera.\n");
        tell_room(env, "Kionix guarda en una estantería el vial que le ha dado " +
                       CAP(NNAME(pl)) + ", y a continuación le dice algo "
                       "mientras se frota las manos.\n", ({pl}));
        ob->remove();
        pl->SetAttribute(ATR_QUEST, BUSCANDO_VINO);
    }
}


public void recoger_vino(object pl, object ob)
{
    object env;
    int vol, llenado;
    string msg_pl, msg_env;

    if (!ob || !pl) return;
    if (!present(pl, (env = environment())))
    {
        tell_room(env, "Kionix murmura: 'Uhmm... Realmente sospechoso... Me da " +
                       (ob->QueryShort() ||ob->QueryName()) + " y se "
                       "va corriendo... Mejor lo dejo, no sea que esté "
                       "envenenado o algo.\n");
        ob->move(env);
        return;
    }
    if (   ESTADO_QUEST(pl) != BUSCANDO_VINO
        || (   member(inherit_list(ob), (FOOD + ".c")) < 0
            && member(inherit_list(ob), (DRINK + ".c")) < 0))
    {
        tell_object(pl, "Kionix te dice: '¡Uhm! Gracias por el regalo!'\n"
                        "A continuación, guarda " +
                        (ob->QueryShort() || ob->QueryName()) + " en una de las "
                        "estanterías de la tienda.\n");
        tell_room(env, "Kionix agradece a " + CAP(NNAME(pl)) + " el regalo, y lo "
                       "guarda en una de las estanterías de la tienda.\n", ({pl}));
        return;
        ob->remove();
    }
    // comprobamos si es bebible, y en ese caso...
    if (!ob->id("vino_bodegas_nandor"))
    {
        tell_object(pl, "Kionix mira el vino y te sonríe encantado.\n"
                        "Sin perder un instante, le da un largo trago.\n");
        tell_room(env, "Kionix sonríe a " + CAP(NNAME(pl)) + " y le da un trago "
                       "al vino.\n", ({pl}));
        tell_room(env, "Con cara de asco, lo escupe al suelo mientras grita: \n"
                       "'¡Pero qué demonios es esto! ¡esto no es un "
                       "buen vino ni nada! Si es que hoy en día no tenéis "
                       "cultura vinícola... Todo el mundo sabe que los mejores "
                       "vinos están en Nandor, y tú me traes esta... esta... "
                       "bazofia de caldo.... Si es que...'\n");
        tell_object(pl, "Kionix te devuelve el vino.\n");
        tell_room(env, "Kionix le devuelve el vino a " + CAP(NNAME(pl)) + ".\n", ({pl}));
        dar_objeto(pl, ob);
        return;
    }
    // es de nandor.    // comprobamos si no está lleno
    if ((vol = ob->Query_Vessel_Volume()) > (llenado = ob->QueryFull()))
    // no está lleno
    {
        if (!llenado)
        // está vacío
        {
            tell_room(env, "Kionix mira la etiqueta del vino y luego sopesa la botella. "
                           "Con cara de fastidio tira la botella al suelo mientras "
                           "exclama: '¡Pero qué demonios es esto! ¡Yo te pedí una "
                           "botella de vino llena! ¿Para qué quiero yo una botella vacía? O "
                           "tienes la cabeza hueca o es que eso de prestar atención no se "
                           "te da bien... Maldita sea...'\n");
            ob->move(env);
            return;
        }
        // si queda algo de vino...
        msg_pl = "Kionix mira la botella que le has dado y sonríe con picardía "
                 "mientras te dice: '¡Qué! ¿echando un traguito por el camino? "
                 "Uhm.... Espero que quede suficiente...'\n";
        msg_env = "Kionix mira la botella que le ha dado " + CAP(NNAME(pl)) +
                  " y sonríe con picardía mientras le dice algo.\n";
    }
    if (!msg_pl) msg_pl = "Kionix mira la botella que le has dado y te sonríe.\n";
    if (!msg_env) msg_env = "Kionix mira la botella de vino y sonríe a " +
                                 CAP(NNAME(pl)) + ".\n";
    tell_object(pl, msg_pl);
    tell_room(env, msg_env, ({pl}));
    tell_room(env, "A continuación, echa la cabeza hacia atrás, y en un visto y no visto "
                   "se bebe todo el vino. Rápidamente, su cara toma un "
                   "saludable colorcillo rosado...\n");
    tell_object(pl, "Kionix exclama: '¡Oh! ¡Ya recuerdo los ingredientes que hacían "
                    "falta para la poción que necesitabas!'\n");
    tell_room(env, "Kionix le dice algo a " + CAP(NNAME(pl)) + ".\n", ({pl}));
    tell_room(env, "Con movimientos precisos, comienza a sacar frascos de las estanterías y "
                   "a mezclar su contenido en una marmita. Tras remover la mezcla y observar "
                   "el resultado, asiente satisfecho y vierte el extraño líquido en "
                   "el interior de un vial que coge de uno de los estantes.\n");
    tell_object(pl, "Kionix te da el vial con la poción mientras te dice: 'Aquí "
                    "tienes. Si todo ha salido bien, esto debería curar a la hechicera.'\n");
    tell_room(env, "Kionix le da el vial a " + CAP(NNAME(pl)) + ".\n", ({pl}));
    // le añadimos el alcohol del vino
    AddAlcohol(ob->Query_Vessel_Volume() * ob->QueryFoodAlc() / 100);
    ob->remove();

    // reutilizamos ob para la poción
    ob = clone_object(QUEST_GARDIL("pocion_gardil"));
    ob->SetOwner(NREAL(pl));
    pl->SetAttribute(ATR_QUEST, POCION_CONSEGUIDA);
    dar_objeto(pl, ob);
}


public void recoger_carta(object pl, object ob)
{
    object env;
    if (!pl || !ob) return;
    if (!present(pl, (env = environment())))
    {
        tell_room(env, "Kionix mira la carta y dice: 'Me da esta carta y "
                       "se va.... Qué cosa más rara. Uhm.... No me fío ni un "
                       "pelo... ¿Y si es una carta embrujada?'\nRápidamente, "
                       "acerca la carta al fuego de la marmita y ves como se "
                       "convierte en cenizas.\n"
                       "'Ya está... No hay maldición que pueda perdurar en "
                       "las cenizas.'\n");
        return;
    }
    tell_object(pl, "Kionix rompe el lacre, desdobla la carta mientras te mira, y "
                    "comienza a leerla.\n");
    tell_room(env, "Kionix desdobla la carta y comienza a leerla, mientras mira a " +
                   CAP(NNAME(pl)) + ".\n", ({pl}));
    if (ESTADO_QUEST(pl) > CON_CARTA)
    {
        tell_object(pl, "Kionix abre un cajón y guarda la carta mientras te dice: "
                        "¿Para qué me das una copia de la carta que me diste "
                        "con la petición de Gardil?\n");
        tell_room(env, "Kionix guarda la carta en un cajón mientras le dice algo "
                       "a " + CAP(NNAME(pl)) + ".\n", ({pl}));
        ob->remove();
        return;
    }
    if (ESTADO_QUEST(pl) < CON_CARTA || ob->QueryOwner() != NREAL(pl))
    {
        tell_object(pl, "Alarmad" + pl->QueryGenderEndString() + ", observas "
                        "como la cara del shamán se pone roja por la ira. Con ojos "
                        "llameantes te mira y te grita:\n");
    tell_room(env, "Con alarma, ves como la cara del shamán se vuelve "
                       "roja de ira, mientras mira a " + CAP(NNAME(pl)) + " con ojos "
                       "llameantes y le grita:\n", ({pl}));
        tell_room(env, "'¡Lárgate ahora mismo de mi vista si no quieres que te "
                       "lance una maldición aquí mismo! ¡¡¡¿Cómo te atreves a "
                       "escribirme una cosa así y a entregármela en mano?!!!\n"
                       "¡Laaaargate de mi vista! ¡Ya!\n");
        tell_object(pl, "El shamán te lanza la carta, que coges al vuelo.\n"
                        "Rápidamente, abandonas la tienda, no sea que el shamán "
                        "se arrepienta y te asesine aquí mismo.\n");
        tell_room(env, "El shamán, le lanza la carta a " + CAP(NNAME(pl)) +
                       ", quien la coge al vuelo, y abandona rápidamente el local.\n",
                       ({pl}));
        ob->remove();
        ob = clone_object(QUEST_GARDIL("carta_tramposo.c"));
        ob->SetOwner(NREAL(pl));
        dar_objeto(pl, ob);
        pl->GoAway();

        return;
    }

    tell_room(env, "Kionix le dice algo a " + CAP(NNAME(pl)) + ".\n", ({pl}));
    tell_object(pl, "'Vaya, vaya, una poción súmamente interesante y compleja... "
                    "Y súmamente cara, todo hay que decirlo. Sin embargo, envista de "
                    "que es una antigua conocida la que me la pide, no te la "
                    "cobraré. Eso sí, necesito que me traigas un vial de regeneración, para "
                    "mezclar con la poción que tengo que preparar.\n");
    pl->SetAttribute(ATR_QUEST, BUSCANDO_VIAL);
}
