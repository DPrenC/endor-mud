/* Archivo: /d/simauria/comun/quest/sherek/daryl.c
* Descripci�n: jefe del cuerpo de Guardianes de la aldea.
* Autor: Lug y Yalin.
*/
#include "path.h"
#include <guild.h>
#include <properties.h>
#include <combat.h>>
#include <moving.h>
#include <skills.h>
inherit PNJ("sherek/gbase");

void recoger_(object lib, object pl)
{
    if (!pl) return;
    int uno = pl->QueryAttribute("sabelibro");
    int dos = pl->QueryAttribute("tienelibro");
    if (member(lib->QueryIds(),"quest_libro_daryl") >= 0)
    {
        if ((QUESTMASTER->QueryQuestSolved("DarylQuest",pl)) || (!uno))
        {
            write("Daryl mira el libro que le acabas de dar, y con mala cara te "
                "dice: 'No tengo tiempo para lecturas.' Acto seguido, arroja el "
                "libro al fuego.\n");
            say(W(CAP(pl->QueryName())+" le da un libro a daryl, que con "
                "unos gru�idos de fastidio, lo tira al fuego.\n"),pl);
            lib->remove();
            if (lib) destruct(lib);
            return;
        }
        if (!dos)
        {
            write("En el mismo momento, ves un r�tulo en la cubierta: 'Sobre "
                "la perversi�n de los monjes y sus guardianes.'\nNo "
                "sabes qui�n lo ha escrito, pero sospechas que has metido la "
                "pata.\nDaryl hojea el libro, y con la cara desencajada, se "
                "levanta, te agarra por el cuello, y con la ayuda de sus "
                "guardianes, te propinan una fabulosa paliza, y te arrojan a la "
                "calle, donde tienes la impresi�n de que vas a morir.\n");
            say(CAP(pl->QueryName())+" le da algo a Daryl.\nEl guardia "
                "mira el objeto, y con un gesto de rabia, se levanta de su "
                "silla, agarra a "+CAP(pl->QueryName())+" por el cuello, y "
                "junto con sus guardias, le propina una paliza bestial, y le "
                "arrojan a la calle.\n",pl);
            lib->remove();
            if (lib) destruct(lib);
            pl->SetHP(1);
            pl->SetSP(1);
            pl->SetDrink(1);
            pl->SetFood(1);
            pl->move(SHERALD("granja/granja00"),M_SILENT);
            pl->LookAfterMove();
            return;
        }
        write("Daryl hojea el libro, y con una carcajada de satisfacci�n, se "
            "levanta, hace un gesto a los guardias, y se dirige con ellos a "
            "la taberna.\nAll�, rodean a Marath, le encadenan, y lo conducen "
            "al calabozo, en espera de entregarlo a la justicia de Simauria.\n");
        lib->remove();
        if (lib) destruct(lib);
        QUESTMASTER->SetPlayerQuest("DarylQuest",pl);
        QUESTMASTER->InformSolution("El peligroso asesino de Sloch, descansa "
            "en una celda de Simauria, gracias a "+CAP(pl->QueryName())+". ��Felicidades!!\n");
        object tab = find_object(SHERALD("tiendas/taberna"));
        object mar = present("marath",tab);
        if (mar)
        {
            if (!living(mar))
            {
                deep_inventory(mar)->remove();
                mar->remove();
            }
            tell_room(tab,"Daryl llega acompa�ado de sus guardias, gritando: "
                "�D�nde est� ese sinverg�enza de Marath?\nRecorre toda la "
                "taberna con su vista, y gru�e: �Vaya!, toda la vida en la "
                "taberna, y cuando se le busca, al se�or le ha dado por irse... "
                "Bueno, no habr� ido muy lejos.\nY sale corriendo con su "
                "gente, en persecuci�n de Marath.\n");
        }
        else tell_room(tab,"Daryl aparece acompa�ado de 4 guardias, rodean a "
            "Marath, y tras una dura lucha, logran reducirle y se lo llevan "
            "detenido.\n");
        object *mars = clones(QUEST+"sherek/marath");
        int i;
        for (i=sizeof(mars);i--;)
        {
            deep_inventory(mars[i])->remove();
            mars[i]->remove();
        }
        pl->RemoveAttribute("sabemarath");
        pl->RemoveAttribute("sabecofre");
        pl->RemoveAttribute("sabellave");
        pl->RemoveAttribute("tienellave");
        pl->RemoveAttribute("sabeminas");
        pl->RemoveAttribute("sabepiedra");
        pl->RemoveAttribute("tienepiedra");
        pl->RemoveAttribute("sabeprueba");
        pl->RemoveAttribute("sabelibro");
        pl->RemoveAttribute("tienelibro");
        pl->RemoveAttribute("hechoninyo");
        pl->RemoveAttribute("echoenano");
        pl->RemoveAttribute("hechoberat");
        pl->RemoveAttribute("hechodaryl");
        pl->RemoveAttribute("hechotabur");
        return;
    }
    return;
}

string informa()
{
    int uno, dos, tres;
    uno = TP->QueryAttribute("sabemarath");
    dos = TP->QueryAttribute("sabeprueba");
    tres = TP->QueryAttribute("sabelibro");
    if (QUESTMASTER->QueryQuestSolved("DarylQuest",TP)) return "Daryl te "
        "dice: �Marath? Pues la �ltima vez que le vi, se lo llevaban dos "
        "soldados de Simauria. Gracias a ti, se ha hecho justicia.\n";
    if (!uno) return "Daryl te dice: �Marath? Pues..., en la taberna, "
        "seguro. Si quieres hablar con �l, ve all� y no molestes. No tenemos "
        "tiempo para ch�charas.\n";
    if (tres) return "Daryl te dice: Ya te lo cont� todo. �Has encontrado "
        "la prueba que necesito? Si no es as�, ve a buscarla, y no me "
        "interrumpas.\n";
    if (dos) return "Daryl te dice: Escucha: ya te he dicho lo que s�, si "
        "me quieres ayudar, hazlo, si no, d�jame en paz, que bastante tengo "
        "con investigarlo por mi cuenta.\n";
    TP->SetAttribute("sabeprueba",time());
    TP->SetAttribute("hechodaryl", time());
    return "Daryl te dice: S�..., bueno..., tal vez t�... Bien, ver�s: hace "
        "tiempo, se cometi� un crimen en Berat, muy lejos, en Simauria, y "
        "justo por esas fechas coincidi� que Marath apareci� por aqu�, y las "
        "explicaciones que nos dio no parec�an muy convincentes. As� que, yo "
        "hice averiguaciones, y estoy seguro de que es el asesino, pero no "
        "tengo pruebas para proceder contra �l.\nEl caso es que yo no "
        "puedo ir tan lejos, no tengo quien me sustituya, y esto no se puede "
        "quedar sin jefe. Si me quisieras ayudar, podr�as ir a Berat, y "
        "hablar con las autoridades para descubrir alguna prueba. Te "
        "quedar�a muy agradecido.\n";
}

string dialogo()
{
    foreach(object ob:all_inventory(environment()))
    {
        if (query_once_interactive(ob))
        {
            switch (d4())
            {
                case 1:
                    tell_object(ob,"Daryl te mira con mala cara.\n");
                    return "";
                break;
                case 2:
                    tell_object(ob,"Daryl carraspea, d�ndote a entender que est� atento.\n");
                    return "";
                break;
                case 3:
                    tell_object(ob,"Daryl saca brillo a su coraza.\n");
                    return "";
                break;
                case 4:
                    if (QUESTMASTER->QueryQuestSolved("DarylQuest",ob))
                    {
                        tell_object(ob,"Daryl te hace un gesto condescendiente "
                            "con la mano y te dice: Te estoy muy agradecido por "
                            "tu ayuda, pero no puedes quedarte ah� molest�ndome.\n");
                        return "";
                    }
                    if ((ob->QueryAttribute("tienelibro")) || (ob->QueryAttribute("sabelibro")))
                    {
                        tell_object(ob,"Daryl te pregunta: �Has estado en Berat? "
                            "�Sabes si hay alguna prueba?\n");
                        return "";
                    }
                    if (ob->QueryAttribute("sabeprueba"))
                        {
                        tell_object(ob,"Daryl suspira: Berat est� muy lejos, no puedo dejar "
                            "esto solo. Alguien tendr�a que investigar all�.\n");
                        return "";
                    }
                    if (ob->QueryAttribute("sabemarath"))
                    {
                        tell_object(ob,"Daryl refunfu�a: Es �l, lo s�. Es �l. Si "
                            "tuviera una prueba firme...\n");
                        return "";
                    }
                    tell_object(ob,"Daryl refunfu�a: 'no tengo ganas de jaleos hoy.'\n");
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
    SetStandard("jefe guardi�n","humano",([ GC_LUCHADOR:70 ]), GENERO_MASCULINO);
    SetName("Daryl");
    SetShort("daryl, el jefe de la guardia");
    SetLong("Daryl es el jefe supremo de todos lo scuerpos de guardia de los dominios de "
        "Sherek.\nEs un humano grandote y fornido, como corresponde al m�s fuerte y bravo de "
        "los guerreros que defienden la regi�n.\nSus brazos desnudos y velludos muestran, as� "
        "como su rostro y cuello, numerosas cicatrices de cortes, estocadas y golpes, que "
        "exhibe orgulloso, como trofeos de tiempos gloriosos.\n");
    AddId(({"daryl","jefe","jefe guardian","jefe guardi�n","jefe de la guardia","jefe vigilante"}));
    SetCon(QueryCon()+5);
    SetHP(QueryMaxHP());
    SetStr(QueryStr()+5);
    SetNoGet("Daryl gru�e y dice: �Eh, con las manos nada de bromas!");
    AddQuestion(({"marath","Marath","asesino","prueba"}),SF(informa),1);
    Set(P_CANT_LURE,1);
    AddItem(ARMA("sherek/aldea/espada2"),REFRESH_REMOVE,2,SF(wieldme));
    AddItem(PROT("sherek/aldea/coraza"),REFRESH_REMOVE,1,SF(wearme));
    InitChats(5,SF(dialogo));
    InitAChats(5,({"Daryl ruge: �No debiste hacer eso, monigote!\n",
    "Daryl grita: �Vas a pagar por tu atrevimiento!\n"}));
}

public int QueryGuardiaDarylQuest() { return 1; }

void notify_enter(mixed from,int method,mixed extra)
{
	if (method == M_GIVE) call_out("recoger_",1,PO,from);
}

