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
  SetStandard("Kionix el sham�n","kender",([GC_HECHICERO:10]),GENERO_MASCULINO);
  SetName("Kionix");
  SetIds(({"chaman","shaman","sham�n","kender","kionix"}));
  pocion=1;

  SetShort("Kionix, el sham�n");
  SetLong(W("Kionix, el sham�n de Flenton. Es un kender muy peculiar. Dice "
  	"haber estudiado con los magos mas poderosos, y haber luchado con "
  	"monstruos gigantescos. Lo curioso es que nunca ha salido de los "
  	"alrededores de Flenton, salvo en una ocasi�n en que aseguro que "
  	"lo habian raptado unas hadas. Aunque son muchos los que piensan "
  	"que dicho incidente esta relacionado con la desaparici�n de un "
  	"barril de aguardiente en la taberna de Pikarus.\n"));
  AddQuestion(({"vino", "buen vino","el mejor vino"}),
              "Kionix te sonr�e y te dice: 'El mejor vino es el que producen "
              "en Nandor, digan lo que digan los dem�s.\n");
  AddQuestion(({"pocion","poci�n"}),W("Yo ten�a que darle una poci�n a alguien... "
  	"pero no me acuerdo a qui�n. Si quieres que te la de solo tienes que ped�rmela.\n"));

  InitChats(5,({
  	"Kionix comienza a murmurar un cantico en voz baja.\n",
	"Kionix te dice: �Hola! �Qu� deseas? �Acaso alguna poci�n magica?\n",
	W("Kionix comienza a mezclar el contenido de varios recipientes en "
		"un cuenco.\nDel cuenco sale una peque�a nube de humo de "
		"colorines...\nKionix exclama: ���WoW!!! ��Qu� bonito!! ���Me pregunto "
		"c�mo lo habr� hecho!!!\n"),
	W("Kionix se va hacia la estanter�a donde estan todos los frascos "
		"y comienza a contarlos.\n"),
	W("Kionix murmura: �C�mo demonios era esa poci�n? Un poco del frasco "
		"az�l, otro poco de este otro... �o era de este? �Bah! �De este "
		"mismo!\n"),
	W("Kionix dice: este Kendarg, me encargo una poci�n hace semanas y "
		"a�n no ha venido por ella. �Ojal� recordase para qu� era! Hmmm...\n")}));
  InitAChats(10,({
  	"Kionix grita: ��Bien!! ��Un combate!! �Cuanto tiempo sin divertirme!\n",
	"Kionix dice: �Es todo lo mejor que puedes hacerlo?\n"}));
}

init(){
  ::init();

  add_action("fpedir","pedir");
}

int fpedir(string str)
{
	if(!str)
	{
		notify_fail("�Pedir <qu�>?\n");
		return 0;
	}
	else if(str=="pocion" || str=="pocion para kendarg" || str=="poci�n" || str=="poci�n para kendarg")
	{
		if(!pocion)
		{
			write(W("Kionix dice: lo siento, alguien se la ha ido a "
				"llevar a Kendarg.\n"));
			return 1;
		}
		else
		{
			write(W("Kionix dice: asi que vienes a por la poci�n para "
				"Kendarg, genial!\n"));
			poc=clone_object(FLENVAR+"pocion");
			poc->move(TP,M_SILENT);
			write("El sham�n te da una poci�n.\n");
			write("Kionix dice: dile a Kendarg que tenga cuidado con ella!\n");
			pocion=0;
			return 1;
		}
	}
	else
	{
		notify_fail("El sham�n no sabe muy bien que le pides.\n");
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
                       "un vial y se va... Seguro que est� envenenado o algo...'\n"
                       "A continuaci�n, lo tira al suelo.\n");
        ob->move(env);
        return;
    }

    if (ESTADO_QUEST(pl) != BUSCANDO_VIAL)
    {
        tell_object(pl, "Kionix te mira con suspicacia y te dice: ");
        tell_room(env, "Kionix mira a " + CAP(NNAME(pl)) + " con suspicacia y le dice: ",
                  ({pl}));
        tell_room(env, "'No, no, gracias, t�matelo t� si quieres... Los shamanes "
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
                        "poci�n.\n"
                        "Kionix te devuelve el vial.\n");
        tell_room(env, "Kionix le dice algo a " + CAP(NNAME(pl)) + " y luego le "
                       "devuelve el vial.\n", ({pl}));
        dar_objeto(pl, ob);
        return;
    }

    if (!ob->QueryFull())
    // el vial est� vac�o
    {
        tell_object(pl, "Kionix te mira con mala cara y te dice: 'Vamos a ver. "
                        "Si la memoria no me falla, yo te ped� un vial de "
                        "regeneraci�n para poder mezclarlo con mi poci�n, pero t� me "
                        "traes un vial vac�o... �Qu� pretendes "
                        "que haga con esto?'\nA continuaci�n te devuelve el vial.\n");
        tell_room(env, "Kionix le dice algo a " + CAP(NNAME(pl)) + " con mala cara.\n",
                  ({pl}));
        dar_objeto(pl, ob);
        return;
    }

    if (ob->Query_Vessel_Volume() > ob->QueryFull())
    {
        tell_object(pl, "Kionix mira el vial y r�pidamente lo coloca sobre "
                        "una estanter�a. Se frota las manos mientras te dice: "
                        "'Bien, bien, ahora s�lo me queda a�adirle........'\n\n"
                        "Kionix se da un pu�etazo en la cabeza mientras exclama: "
                        "'�Maldita sea! �Siempre se me olvidan los ingredientes!\n"
                        "�ah! �ya se! �Necesito una botella del mejor vino que "
                        "puedas encontrar! �Tr�emela y podr� acabar de terminar la "
                        "poci�n para tu amiga la hechicera.\n");
        tell_room(env, "Kionix guarda en una estanter�a el vial que le ha dado " +
                       CAP(NNAME(pl)) + ", y a continuaci�n le dice algo "
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
                       "va corriendo... Mejor lo dejo, no sea que est� "
                       "envenenado o algo.\n");
        ob->move(env);
        return;
    }
    if (   ESTADO_QUEST(pl) != BUSCANDO_VINO
        || (   member(inherit_list(ob), (FOOD + ".c")) < 0
            && member(inherit_list(ob), (DRINK + ".c")) < 0))
    {
        tell_object(pl, "Kionix te dice: '�Uhm! Gracias por el regalo!'\n"
                        "A continuaci�n, guarda " +
                        (ob->QueryShort() || ob->QueryName()) + " en una de las "
                        "estanter�as de la tienda.\n");
        tell_room(env, "Kionix agradece a " + CAP(NNAME(pl)) + " el regalo, y lo "
                       "guarda en una de las estanter�as de la tienda.\n", ({pl}));
        return;
        ob->remove();
    }
    // comprobamos si es bebible, y en ese caso...
    if (!ob->id("vino_bodegas_nandor"))
    {
        tell_object(pl, "Kionix mira el vino y te sonr�e encantado.\n"
                        "Sin perder un instante, le da un largo trago.\n");
        tell_room(env, "Kionix sonr�e a " + CAP(NNAME(pl)) + " y le da un trago "
                       "al vino.\n", ({pl}));
        tell_room(env, "Con cara de asco, lo escupe al suelo mientras grita: \n"
                       "'�Pero qu� demonios es esto! �esto no es un "
                       "buen vino ni nada! Si es que hoy en d�a no ten�is "
                       "cultura vin�cola... Todo el mundo sabe que los mejores "
                       "vinos est�n en Nandor, y t� me traes esta... esta... "
                       "bazofia de caldo.... Si es que...'\n");
        tell_object(pl, "Kionix te devuelve el vino.\n");
        tell_room(env, "Kionix le devuelve el vino a " + CAP(NNAME(pl)) + ".\n", ({pl}));
        dar_objeto(pl, ob);
        return;
    }
    // es de nandor.    // comprobamos si no est� lleno
    if ((vol = ob->Query_Vessel_Volume()) > (llenado = ob->QueryFull()))
    // no est� lleno
    {
        if (!llenado)
        // est� vac�o
        {
            tell_room(env, "Kionix mira la etiqueta del vino y luego sopesa la botella. "
                           "Con cara de fastidio tira la botella al suelo mientras "
                           "exclama: '�Pero qu� demonios es esto! �Yo te ped� una "
                           "botella de vino llena! �Para qu� quiero yo una botella vac�a? O "
                           "tienes la cabeza hueca o es que eso de prestar atenci�n no se "
                           "te da bien... Maldita sea...'\n");
            ob->move(env);
            return;
        }
        // si queda algo de vino...
        msg_pl = "Kionix mira la botella que le has dado y sonr�e con picard�a "
                 "mientras te dice: '�Qu�! �echando un traguito por el camino? "
                 "Uhm.... Espero que quede suficiente...'\n";
        msg_env = "Kionix mira la botella que le ha dado " + CAP(NNAME(pl)) +
                  " y sonr�e con picard�a mientras le dice algo.\n";
    }
    if (!msg_pl) msg_pl = "Kionix mira la botella que le has dado y te sonr�e.\n";
    if (!msg_env) msg_env = "Kionix mira la botella de vino y sonr�e a " +
                                 CAP(NNAME(pl)) + ".\n";
    tell_object(pl, msg_pl);
    tell_room(env, msg_env, ({pl}));
    tell_room(env, "A continuaci�n, echa la cabeza hacia atr�s, y en un visto y no visto "
                   "se bebe todo el vino. R�pidamente, su cara toma un "
                   "saludable colorcillo rosado...\n");
    tell_object(pl, "Kionix exclama: '�Oh! �Ya recuerdo los ingredientes que hac�an "
                    "falta para la poci�n que necesitabas!'\n");
    tell_room(env, "Kionix le dice algo a " + CAP(NNAME(pl)) + ".\n", ({pl}));
    tell_room(env, "Con movimientos precisos, comienza a sacar frascos de las estanter�as y "
                   "a mezclar su contenido en una marmita. Tras remover la mezcla y observar "
                   "el resultado, asiente satisfecho y vierte el extra�o l�quido en "
                   "el interior de un vial que coge de uno de los estantes.\n");
    tell_object(pl, "Kionix te da el vial con la poci�n mientras te dice: 'Aqu� "
                    "tienes. Si todo ha salido bien, esto deber�a curar a la hechicera.'\n");
    tell_room(env, "Kionix le da el vial a " + CAP(NNAME(pl)) + ".\n", ({pl}));
    // le a�adimos el alcohol del vino
    AddAlcohol(ob->Query_Vessel_Volume() * ob->QueryFoodAlc() / 100);
    ob->remove();

    // reutilizamos ob para la poci�n
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
                       "se va.... Qu� cosa m�s rara. Uhm.... No me f�o ni un "
                       "pelo... �Y si es una carta embrujada?'\nR�pidamente, "
                       "acerca la carta al fuego de la marmita y ves como se "
                       "convierte en cenizas.\n"
                       "'Ya est�... No hay maldici�n que pueda perdurar en "
                       "las cenizas.'\n");
        return;
    }
    tell_object(pl, "Kionix rompe el lacre, desdobla la carta mientras te mira, y "
                    "comienza a leerla.\n");
    tell_room(env, "Kionix desdobla la carta y comienza a leerla, mientras mira a " +
                   CAP(NNAME(pl)) + ".\n", ({pl}));
    if (ESTADO_QUEST(pl) > CON_CARTA)
    {
        tell_object(pl, "Kionix abre un caj�n y guarda la carta mientras te dice: "
                        "�Para qu� me das una copia de la carta que me diste "
                        "con la petici�n de Gardil?\n");
        tell_room(env, "Kionix guarda la carta en un caj�n mientras le dice algo "
                       "a " + CAP(NNAME(pl)) + ".\n", ({pl}));
        ob->remove();
        return;
    }
    if (ESTADO_QUEST(pl) < CON_CARTA || ob->QueryOwner() != NREAL(pl))
    {
        tell_object(pl, "Alarmad" + pl->QueryGenderEndString() + ", observas "
                        "como la cara del sham�n se pone roja por la ira. Con ojos "
                        "llameantes te mira y te grita:\n");
    tell_room(env, "Con alarma, ves como la cara del sham�n se vuelve "
                       "roja de ira, mientras mira a " + CAP(NNAME(pl)) + " con ojos "
                       "llameantes y le grita:\n", ({pl}));
        tell_room(env, "'�L�rgate ahora mismo de mi vista si no quieres que te "
                       "lance una maldici�n aqu� mismo! ����C�mo te atreves a "
                       "escribirme una cosa as� y a entreg�rmela en mano?!!!\n"
                       "�Laaaargate de mi vista! �Ya!\n");
        tell_object(pl, "El sham�n te lanza la carta, que coges al vuelo.\n"
                        "R�pidamente, abandonas la tienda, no sea que el sham�n "
                        "se arrepienta y te asesine aqu� mismo.\n");
        tell_room(env, "El sham�n, le lanza la carta a " + CAP(NNAME(pl)) +
                       ", quien la coge al vuelo, y abandona r�pidamente el local.\n",
                       ({pl}));
        ob->remove();
        ob = clone_object(QUEST_GARDIL("carta_tramposo.c"));
        ob->SetOwner(NREAL(pl));
        dar_objeto(pl, ob);
        pl->GoAway();

        return;
    }

    tell_room(env, "Kionix le dice algo a " + CAP(NNAME(pl)) + ".\n", ({pl}));
    tell_object(pl, "'Vaya, vaya, una poci�n s�mamente interesante y compleja... "
                    "Y s�mamente cara, todo hay que decirlo. Sin embargo, envista de "
                    "que es una antigua conocida la que me la pide, no te la "
                    "cobrar�. Eso s�, necesito que me traigas un vial de regeneraci�n, para "
                    "mezclar con la poci�n que tengo que preparar.\n");
    pl->SetAttribute(ATR_QUEST, BUSCANDO_VIAL);
}
