/****************************************************************************
Fichero: /d/simauria/comun/quest/sherek/ninyo.c
Autor: Lug y Yalin
Fecha: 16/08/2006
Descripción: Niño nadando en el río.
****************************************************************************/

#include "path.h"
#include <properties.h>
#include <moving.h>
inherit PNJ("sherek/aldea/base");

private int NoLucho();
void venganza();

void recoger_(object pdr, object pl)
{
    if (!pl) return;
    int uno = pl->QueryAttribute("sabepiedra");
    int dos = pl->QueryAttribute("tienepiedra");
    if (member(pdr->QueryIds(),"quest_piedra_ninyo") >= 0)
    {
        if ((QUESTMASTER->QueryQuestSolved("DarylQuest",pl)) || (!uno))
        {
            write("El niño dice: 'Gracias, se la daré a mi padre, seguro que "
                "sacará para comer carne fresca 2 o 3 meses.\n");
            say(CAP(pl->QueryName())+" le da algo al niño, quien le "
                "sonríe, y dándole las gracias, se lo guarda.\n",pl);
            pdr->remove();
            if (pdr) destruct(pdr);
            return;
        }
        if (!dos)
        {
            write("El niño mira sorprendido la piedra, y con una mirada "
                "aterrorizada te dice: 'Ya me han advertido de eso. ¿Así que "
                "me haces un regalo valioso para pedirme que haga..., cosas, "
                "verdad? Ahora verás.'\n");
            say(CAP(pl->QueryName())+" le da algo al niño.\nEl niño mira "
                "a "+CAP(pl->QueryName())+" con cara horrorizada, sollozando "
                "mientras le dice algo que no logras entender.\n",pl);
            pdr->remove();
            if (pdr) destruct(pdr);
            venganza();
            return remove(),0;
        }
        write("El niño mira el topacio, y con una amplia sonrisa te dice: "
            "'¡Gracias, muchas gracias! Voy en seguida a llevársela al "
            "granjero. Ah, es verdad, ahora vengo.'\nEl niño se viste a toda "
            "prisa, se va corriendo, y al rato vuelve con una llave que te "
            "entrega.\n");
        say(CAP(pl->QueryName())+" le da algo al niño, quien sonríe "
            "satisfecho, se viste rápidamente, sale corriendo, y vuelve al "
            "poco rato con un objeto pequeño que entrega a "+CAP(pl->QueryName())+".\n",pl);
        pdr->remove();
        if (pdr) destruct(pdr);
        object obj=clone_object(QUEST+"sherek/llave");
        obj->SetOwner(TP->QueryRealName());
        if (!obj->move(pl)) obj->move(environment(TO));
        pl->RemoveAttribute("sabepiedra");
        pl->RemoveAttribute("tienepiedra");
        pl->SetAttribute("tienellave",time());
        return;
    }
    return;
}

string informa_()
{
    int uno, dos, tres, cuatro;
    uno=TP->QueryAttribute("sabellave");
    dos=TP->QueryAttribute("tienellave");
    tres=TP->QueryAttribute("sabelibro");
    cuatro = TP->QueryAttribute("sabecofre");
    if (QUESTMASTER->QueryQuestSolved("DarylQuest",TP)) return "El niño te "
        "dice: '¿No lo recuerdas? Ya te la di, no he encontrado ninguna otra.'\n";
    if (!tres) return "El niño te dice: ¿Llave? No sé, a mí no me dejan "
        "todavía la llave de casa, soy muy pequeño.\n";
        if ((!uno) && (cuatro))
    {
        TP->SetAttribute("sabellave",time());
        return "El niño te dice: 'La encontré en el río, ¿sabes? "
            "Estaba buscando por si encontraba una piedra preciosa.\nSi "
            "tú me dieras una, te daría la llave.\n¿Sabes? Uno de los "
            "granjeros tiene un caballito pequeño, y me ha dicho que lo "
            "quiere vender. Si tuviera una piedra preciosa  podría "
            "comprarlo.'\n";
    }
    if (!dos) return "El niño te dice: 'Sí, la tengo yo, ya te lo dije. "
        "¿Me has traído la piedra?'\n";
    if (!present("quest_llave_cofre",TP))
    {
        object llave=clone_object(QUEST+"sherek/llave");
        llave->move(TP);
        return"El niño te dice: '¡Ah! Se te cayó cuando te fuiste, y la "
            "recogí. Tómala.'\n";
        }
    return "El niño te dice: '¡Pero si la tienes ahí! ¿Es que no sabes "
        "ni lo que llevas contigo?'\n";
}

string informa2()
{
    int uno, dos, tres, cuatro;
    uno = TP->QueryAttribute("sabepiedra");
    dos = TP->QueryAttribute("tienepiedra");
    tres =TP->QueryAttribute("sabellave");
    cuatro = TP->QueryAttribute("tienellave");
    if ((QUESTMASTER->QueryQuestSolved("DarylQuest",TP)) || (cuatro)) return "El "
        "niño te dice: ¡Ah!, muchas gracias, ya tengo el caballito. Si pasas "
        "algún día por mi casa, te lo enseñaré.\n";
    object ob = present("quest_piedra_ninyo",TP);
    if (dos) return "el niño te dice: ¿Ya la has encontrado? Ya sabes lo que "
        "te prometí, ¿me la vas a dar?\n";
    if (uno) return "el niño te dice: Te he dicho lo que sé, yo soy muy "
        "pequeño para investigar por allí.\nSi me la traes, te daré lo "
        "prometido.\n";
    if (tres)
    {
        TP->SetAttribute("sabepiedra",time());
        TP->SetAttribute("sabeminas",time());
        return "el niño te dice: Bueno..., no sé..., sí, tal vez... Verás. "
            "Mi abuelito me ha contado que hace siglos los enanos tenían una "
            "mina de gemas en una montaña de por aquí cerca, pero nadie ha "
            "encontrado la entrada..., ni la salida. Quizá sólo sea un "
            "cuento para dormirme, pero si yo pudiera iría a buscar ese "
            "sitio. Seguramente, alguna piedra quedó por allí.\n";
    }
    return "el niño te dice: ¿Tú también buscas tesoros? Si quieres buscar, "
        "vete un poco más allá, aquí estoy buscando yo.\n";
}

string dialogo()
{
    foreach(object ob:all_inventory(environment()))
    {
        if (query_once_interactive(ob))
        {
            int uno, dos, tres, cuatro, cinco, seis, siete;
            uno=ob->QueryAttribute("sabelibro");
            dos=ob->QueryAttribute("sabellave");
            tres=ob->QueryAttribute("sabepiedra");
            cuatro=ob->QueryAttribute("tienepiedra");
            cinco=ob->QueryAttribute("tienellave");
            seis=ob->QueryAttribute("tienelibro");
            siete = ob->QueryAttribute("sabecofre");
            switch (d4())
            {
                case 1:
                    tell_object(ob,"El niño te sonríe y dice: ¿Quieres darte un "
                        "baño? El agua está algo fría, pero quita la fatiga.\n");
                    return "";
                break;
                case 2:
                    tell_object(ob,"El niño se quita el agua de la cara, te mira "
                        "y dice: Nunca te he visto. ¿De dónde eres?\n");
                    return "";
                    break;
                case 3:
                    tell_object(ob,"El niño se hunde, sale filtrando un puñado de "
                        "arena y dice: A veces se encuentran cosas en el fondo. ");
                    if ((QUESTMASTER->QueryQuestSolved("DarylQuest",ob)) || (seis))
                    {
                        tell_object(ob,"¿Recuerdas la llave que te di?\n");
                        return "";
                    }
                    if (cinco)
                    {
                        tell_object(ob,"Por cierto, ¿Has descubierto de dónde "
                            "era la llave que te di?\n");
                        return "";
                    }
                    if (dos)
                    {
                        tell_object(ob,"¿Sabes? Todavía tengo la llave que "
                            "encontré. No sé para qué servirá, por aquí no hay "
                            "nada que se pueda abrir con ella.\n");
                        return "";
                    }
                    if ((uno) && (siete))
                    {
                        tell_object(ob,"El otro día encontré una llave de algún "
                            "cofre...\n");
                        return "";
                    }
                    tell_object(ob,"Quizá encuentre algo interesante alguna vez.\n");
                    return "";
                    break;
                case 4:
                    if ((QUESTMASTER->QueryQuestSolved("DarylQuest",ob)) || (cinco))
                    {
                        tell_object(ob,"El niño te sonríe y dice: Estoy "
                            "aprendiendo a montar a caballo. ¿Sabes? Mi "
                            "caballito es muy dócil.\n");
                        return "";
                    }
                    if (cuatro)
                    {
                        tell_object(ob,"El niño te mira emocionado y te pregunta: "
                            "¿Has encontrado la piedra? ¿Me la has traído?\n");
                        return "";
                    }
                    if (tres)
                    {
                        tell_object(ob,"El niño suspira y dice: Ojalá pudiera ir "
                            "a buscar las minas. Seguro que allí quedan todavía "
                            "algunas gemas.\n");
                        return "";
                    }
                    if (dos)
                    {
                        tell_object(ob,"El niño mueve la cabeza y susurra: Si "
                            "encontrara una piedra preciosa, quizá podría "
                            "comprarme un caballito.\n");
                        return "";
                    }
                    tell_object(ob,"El niño mira el río y murmura: A lo mejor "
                        "encuentro oro o joyas algún día.\n");
                    return "";
                    break;
            }
        }
    }
    return "";
}

create()
{
    ::create();
    seteuid(getuid());
    SetStandard("un niño","humano",10,GENERO_MASCULINO);
    SetChkFightFunction(SF(NoLucho));
    SetChkMagicFunction(SF(NoLucho));
    SetName("Un niño");
    SetShort("un niño bañándose");
    SetLong("Es un niño de unos 11 años, de semblante risueño y mirada "
        "despierta, que aprovecha el tiempo libre disfrutando de un baño en "
        "el río, que en esta parte está bastante claro.\nQuizá ya trabaje "
        "algo en la granja, pero ahora no parece que eso le importe.\n");
    AddId(({"niño","ninyo","to_delete"}));
    SetHP(QueryMaxHP());
    SetAlign(2000);
    SetNoGet("El niño dice: Soy muy pequeño aún. Si intentas hacerme cosas, "
        "llamaré a un guardia.\n");
    AddQuestion(({"llave","llave de cofre"}),SF(informa_),1);
    AddQuestion(({"piedra","piedra preciosa"}),SF(informa2),1);
    AddQuestion(({"cofre"}),"El niño te mira y dice: ¿Cofre? No sé, nunca he "
        "visto ninguno, en mi casa sólo hay armarios.\n");
    AddQuestion(({"abuelo","abuelito"}),"¿Mi abuelo? Está allí, pescando un "
        "poco al este de aquí.\n");
    InitChats(10,SF(dialogo));
}

void venganza(object agresor)
{
    object obj;
    obj = present("guardian",environment());
    if (!obj || !living(obj))
    {
        obj=clone_object(PNJ("sherek/aldea/guardian"));
        obj->move(environment());
        say("El niño grita: ¡Señor guardia! ¡señor guardia!\nAl momento un "
            "guardia llega corriendo a ver qué ocurre.\n");
    }
    write("El niño sale corriendo, y te deja que te apañes con el guardián.\n");
    say("El niño sale corriendo, dejando que "+capitalize(agresor->QueryName())+" se las "
        "componga con el guardián.\n",agresor);
    obj->Kill(agresor || PO);
    notify_fail("El guardia te grita: ¿Es que no tienes vergüenza? ¡Atacar a un niño! ¡Yo te "
        "enseñaré, cobarde! E inmediatamente carga contra ti.\n");
    return;
}
    
NoLucho(object agresor)
{
    if (agresor->QueryGuildLevel() <= 30) return notify_fail("El niño te mira con "
        "carita de pena, y con lágrimas en los ojos te dice: ¡No me pegues, "
        "por favor, no me pegueees!\nSientes como tu corazón se encoge, y "
        "decides dejarle y pedirle perdón.\n",NOTIFY_NOT_VALID);
    venganza(agresor);
    return remove(),0;
}

public int QueryNinyoDarylQuest() { return 1; }

void notify_enter(mixed from,int method,mixed extra)
{
	if (method == M_GIVE) call_out("recoger_",1,PO,from);
}
