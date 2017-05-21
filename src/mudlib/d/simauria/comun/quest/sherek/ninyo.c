/****************************************************************************
Fichero: /d/simauria/comun/quest/sherek/ninyo.c
Autor: Lug y Yalin
Fecha: 16/08/2006
Descripci�n: Ni�o nadando en el r�o.
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
            write("El ni�o dice: 'Gracias, se la dar� a mi padre, seguro que "
                "sacar� para comer carne fresca 2 o 3 meses.\n");
            say(CAP(pl->QueryName())+" le da algo al ni�o, quien le "
                "sonr�e, y d�ndole las gracias, se lo guarda.\n",pl);
            pdr->remove();
            if (pdr) destruct(pdr);
            return;
        }
        if (!dos)
        {
            write("El ni�o mira sorprendido la piedra, y con una mirada "
                "aterrorizada te dice: 'Ya me han advertido de eso. �As� que "
                "me haces un regalo valioso para pedirme que haga..., cosas, "
                "verdad? Ahora ver�s.'\n");
            say(CAP(pl->QueryName())+" le da algo al ni�o.\nEl ni�o mira "
                "a "+CAP(pl->QueryName())+" con cara horrorizada, sollozando "
                "mientras le dice algo que no logras entender.\n",pl);
            pdr->remove();
            if (pdr) destruct(pdr);
            venganza();
            return remove(),0;
        }
        write("El ni�o mira el topacio, y con una amplia sonrisa te dice: "
            "'�Gracias, muchas gracias! Voy en seguida a llev�rsela al "
            "granjero. Ah, es verdad, ahora vengo.'\nEl ni�o se viste a toda "
            "prisa, se va corriendo, y al rato vuelve con una llave que te "
            "entrega.\n");
        say(CAP(pl->QueryName())+" le da algo al ni�o, quien sonr�e "
            "satisfecho, se viste r�pidamente, sale corriendo, y vuelve al "
            "poco rato con un objeto peque�o que entrega a "+CAP(pl->QueryName())+".\n",pl);
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
    if (QUESTMASTER->QueryQuestSolved("DarylQuest",TP)) return "El ni�o te "
        "dice: '�No lo recuerdas? Ya te la di, no he encontrado ninguna otra.'\n";
    if (!tres) return "El ni�o te dice: �Llave? No s�, a m� no me dejan "
        "todav�a la llave de casa, soy muy peque�o.\n";
        if ((!uno) && (cuatro))
    {
        TP->SetAttribute("sabellave",time());
        return "El ni�o te dice: 'La encontr� en el r�o, �sabes? "
            "Estaba buscando por si encontraba una piedra preciosa.\nSi "
            "t� me dieras una, te dar�a la llave.\n�Sabes? Uno de los "
            "granjeros tiene un caballito peque�o, y me ha dicho que lo "
            "quiere vender. Si tuviera una piedra preciosa  podr�a "
            "comprarlo.'\n";
    }
    if (!dos) return "El ni�o te dice: 'S�, la tengo yo, ya te lo dije. "
        "�Me has tra�do la piedra?'\n";
    if (!present("quest_llave_cofre",TP))
    {
        object llave=clone_object(QUEST+"sherek/llave");
        llave->move(TP);
        return"El ni�o te dice: '�Ah! Se te cay� cuando te fuiste, y la "
            "recog�. T�mala.'\n";
        }
    return "El ni�o te dice: '�Pero si la tienes ah�! �Es que no sabes "
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
        "ni�o te dice: �Ah!, muchas gracias, ya tengo el caballito. Si pasas "
        "alg�n d�a por mi casa, te lo ense�ar�.\n";
    object ob = present("quest_piedra_ninyo",TP);
    if (dos) return "el ni�o te dice: �Ya la has encontrado? Ya sabes lo que "
        "te promet�, �me la vas a dar?\n";
    if (uno) return "el ni�o te dice: Te he dicho lo que s�, yo soy muy "
        "peque�o para investigar por all�.\nSi me la traes, te dar� lo "
        "prometido.\n";
    if (tres)
    {
        TP->SetAttribute("sabepiedra",time());
        TP->SetAttribute("sabeminas",time());
        return "el ni�o te dice: Bueno..., no s�..., s�, tal vez... Ver�s. "
            "Mi abuelito me ha contado que hace siglos los enanos ten�an una "
            "mina de gemas en una monta�a de por aqu� cerca, pero nadie ha "
            "encontrado la entrada..., ni la salida. Quiz� s�lo sea un "
            "cuento para dormirme, pero si yo pudiera ir�a a buscar ese "
            "sitio. Seguramente, alguna piedra qued� por all�.\n";
    }
    return "el ni�o te dice: �T� tambi�n buscas tesoros? Si quieres buscar, "
        "vete un poco m�s all�, aqu� estoy buscando yo.\n";
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
                    tell_object(ob,"El ni�o te sonr�e y dice: �Quieres darte un "
                        "ba�o? El agua est� algo fr�a, pero quita la fatiga.\n");
                    return "";
                break;
                case 2:
                    tell_object(ob,"El ni�o se quita el agua de la cara, te mira "
                        "y dice: Nunca te he visto. �De d�nde eres?\n");
                    return "";
                    break;
                case 3:
                    tell_object(ob,"El ni�o se hunde, sale filtrando un pu�ado de "
                        "arena y dice: A veces se encuentran cosas en el fondo. ");
                    if ((QUESTMASTER->QueryQuestSolved("DarylQuest",ob)) || (seis))
                    {
                        tell_object(ob,"�Recuerdas la llave que te di?\n");
                        return "";
                    }
                    if (cinco)
                    {
                        tell_object(ob,"Por cierto, �Has descubierto de d�nde "
                            "era la llave que te di?\n");
                        return "";
                    }
                    if (dos)
                    {
                        tell_object(ob,"�Sabes? Todav�a tengo la llave que "
                            "encontr�. No s� para qu� servir�, por aqu� no hay "
                            "nada que se pueda abrir con ella.\n");
                        return "";
                    }
                    if ((uno) && (siete))
                    {
                        tell_object(ob,"El otro d�a encontr� una llave de alg�n "
                            "cofre...\n");
                        return "";
                    }
                    tell_object(ob,"Quiz� encuentre algo interesante alguna vez.\n");
                    return "";
                    break;
                case 4:
                    if ((QUESTMASTER->QueryQuestSolved("DarylQuest",ob)) || (cinco))
                    {
                        tell_object(ob,"El ni�o te sonr�e y dice: Estoy "
                            "aprendiendo a montar a caballo. �Sabes? Mi "
                            "caballito es muy d�cil.\n");
                        return "";
                    }
                    if (cuatro)
                    {
                        tell_object(ob,"El ni�o te mira emocionado y te pregunta: "
                            "�Has encontrado la piedra? �Me la has tra�do?\n");
                        return "";
                    }
                    if (tres)
                    {
                        tell_object(ob,"El ni�o suspira y dice: Ojal� pudiera ir "
                            "a buscar las minas. Seguro que all� quedan todav�a "
                            "algunas gemas.\n");
                        return "";
                    }
                    if (dos)
                    {
                        tell_object(ob,"El ni�o mueve la cabeza y susurra: Si "
                            "encontrara una piedra preciosa, quiz� podr�a "
                            "comprarme un caballito.\n");
                        return "";
                    }
                    tell_object(ob,"El ni�o mira el r�o y murmura: A lo mejor "
                        "encuentro oro o joyas alg�n d�a.\n");
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
    SetStandard("un ni�o","humano",10,GENERO_MASCULINO);
    SetChkFightFunction(SF(NoLucho));
    SetChkMagicFunction(SF(NoLucho));
    SetName("Un ni�o");
    SetShort("un ni�o ba��ndose");
    SetLong("Es un ni�o de unos 11 a�os, de semblante risue�o y mirada "
        "despierta, que aprovecha el tiempo libre disfrutando de un ba�o en "
        "el r�o, que en esta parte est� bastante claro.\nQuiz� ya trabaje "
        "algo en la granja, pero ahora no parece que eso le importe.\n");
    AddId(({"ni�o","ninyo","to_delete"}));
    SetHP(QueryMaxHP());
    SetAlign(2000);
    SetNoGet("El ni�o dice: Soy muy peque�o a�n. Si intentas hacerme cosas, "
        "llamar� a un guardia.\n");
    AddQuestion(({"llave","llave de cofre"}),SF(informa_),1);
    AddQuestion(({"piedra","piedra preciosa"}),SF(informa2),1);
    AddQuestion(({"cofre"}),"El ni�o te mira y dice: �Cofre? No s�, nunca he "
        "visto ninguno, en mi casa s�lo hay armarios.\n");
    AddQuestion(({"abuelo","abuelito"}),"�Mi abuelo? Est� all�, pescando un "
        "poco al este de aqu�.\n");
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
        say("El ni�o grita: �Se�or guardia! �se�or guardia!\nAl momento un "
            "guardia llega corriendo a ver qu� ocurre.\n");
    }
    write("El ni�o sale corriendo, y te deja que te apa�es con el guardi�n.\n");
    say("El ni�o sale corriendo, dejando que "+capitalize(agresor->QueryName())+" se las "
        "componga con el guardi�n.\n",agresor);
    obj->Kill(agresor || PO);
    notify_fail("El guardia te grita: �Es que no tienes verg�enza? �Atacar a un ni�o! �Yo te "
        "ense�ar�, cobarde! E inmediatamente carga contra ti.\n");
    return;
}
    
NoLucho(object agresor)
{
    if (agresor->QueryGuildLevel() <= 30) return notify_fail("El ni�o te mira con "
        "carita de pena, y con l�grimas en los ojos te dice: �No me pegues, "
        "por favor, no me pegueees!\nSientes como tu coraz�n se encoge, y "
        "decides dejarle y pedirle perd�n.\n",NOTIFY_NOT_VALID);
    venganza(agresor);
    return remove(),0;
}

public int QueryNinyoDarylQuest() { return 1; }

void notify_enter(mixed from,int method,mixed extra)
{
	if (method == M_GIVE) call_out("recoger_",1,PO,from);
}
