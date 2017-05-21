/* Archivo: /d/simauria/comun/pnj/abadia/tabur.c
* Descripci�n: Tabernero de Sloch.
* autor Lug y Yalin.
*/

#include "path.h"
#include <properties.h>
inherit PNJ("sherek/aldea/base");

string informa()
{
    if (!present("marath",environment())) return "Tabur refunfu�a enfadado: "
        "�Y yo qu� s�? Bastante tengo con aguantarle aqu�, para preocuparme "
        "de �l cuando decide dejarme en paz.\n";
    if (QUESTMASTER->QueryQuestSolved("DarylQuest",TP)) return "Tabur te "
        "dice: '�Es que no lo ves? Ah� le tienes, comiendo y gritando, "
        "como si fuese el amo de la taberna.\n";
    if (!TP->QueryAttribute("sabemarath"))
    {
        TP->SetAttribute("sabemarath",time());
        return("Tabur te dice: Ver�s. Hace tiempo se cometi� un asesinato "
            "en la ciudad de Berat, en la regi�n de Simauria.\nCuentan que "
            "el criminal rob� una importante cantidad de dinero a un "
            "ciudadano noble, tras asesinarle, y luego desapareci�.\nCasualmente, "
            "unos d�as despu�s, apareci� Marath por aqu�. Nunca habla con nadie, "
            "nadie sabe d�nde va cuando sale de aqu�..., que por cierto, es "
            "muy rara vez, casi hay que echarle para poder cerrar...\nPor "
            "eso, muchos sospechamos que �l es el asesino que buscan en "
            "Simauria, pero si quieres saber algo m�s concreto, ser� mejor "
            "que vayas a ver a Daryl, el jefe de la guardia.\n");
    }
    return("Tabur te dice: Ya te cont� todo lo que s�, estoy muy "
        "ocupado.\nSi quieres saber m�s sobre eso, te dije que hablaras "
        "con Daryl.\n");
}

public string informa2()
{
    if (QUESTMASTER->QueryQuestSolved("DarylQuest",TP)) return "Tabur te "
        "dice: Ni que fueras nuevo aqu�. D�jate de preguntas tontas, que no "
        "tengo tiempo para perderlo con bromistas.\n";
    if (!TP->QueryAttribute("sabeprueba")) return("Tabur te dice: Daryl es "
        "el jefe de los guardias. Tiene su sala en la casa grande, la que "
        "est� en la granja.\n");
    return "Tabur te dice: Ya has estado hablando con �l. En "
        "esta aldehuela todo se sabe. D�jame trabajar, que voy retrasado.\n";
}

string dialogo()
{
    foreach(object ob:all_inventory(environment()))
    {
        if (query_once_interactive(ob))
        {
            switch (d6())
            {
                case 1:
                    if (!ob->QueryInvis()) tell_object(ob,"Tabur te pregunta: �Quer�as algo, "
                        "foraster"+(ob->QueryGenderEndString())+"?\n");
                    return "";
                break;
                case 2:
                    tell_object(ob,"Tabur protesta: �Quer�is hacer el favor de "
                        "no gritar tanto?\n");
                    return "";
                break;
                case 3:
                    if (!ob->QueryInvis()) tell_object(ob,"Tabur te susurra: Si necesitas algo "
                        "para el camino, al fondo tenemos una tiendecita. Mi mujer te "
                        "atender� encantada.\n");
                    return "";
                break;
                case 4:
                    tell_object(ob,"Tabur limpia el mostrador con el trapo.\n");
                    return "";
                break;
                case 5:
                    tell_object(ob,"Tabur murmura: �Qu� asco de sitio! "
                        "Borrachos, asesinos y muertos de hambre. \n�Por qu� "
                        "no me quedar�a en Nandor con mi primo Uthur? Mira "
                        "que me lo advirtieron.\n");
                    return "";
                break;
                case 6:
                    if (!present("marath",environment())) return "";
                    if (QUESTMASTER->QueryQuestSolved("DarylQuest",ob))
                    {
                        tell_object(ob,"Tabur grita: �Eh, Marath!�No te han "
                            "ense�ado modales en las mazmorras de Simauria?\n");
                        return "";
                    }
                    if (ob->QueryAttribute("sabemarath"))
                    {
                        tell_object(ob,"Tabur mira a marath, y rezonga: �Qu� "
                            "poco te queda! Daryl est� sobre tu pista, seg�n dicen.\n");
                        return "";
                    }
                    tell_object(ob,"Tabur refunfu�a entre dientes: Maldito "
                        "Marath. �Crees que no sabemos qui�n eres? Alg�n d�a "
                        "pasar� un guardia de Simauria por aqu�, y tendremos "
                        "bronca.\n");
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
    SetStandard("Tabur","humano",30,GENERO_MASCULINO);
    SetName("Tabur");
    SetShort("Tabur, el tabernero");
    SetLong("Tabur es un humano bajo y rollizo.\nTiene el pelo muy corto y "
        "una cara siempre avinagrada. Se rumorea por el pueblo que est� amargado "
        "porque pensaba hacer negocio aqu�, pero la gente de este lugar es "
        "muy pobre, y ahora se pasa la vida gru�endo y lament�ndose.\n");
    AddId(({"tabur","Tabur","tabernero","tendero","humano"}));
    SetHP(QueryMaxHP());
    Set(P_CANT_LURE,1);
    AddQuestion(({"marath","Marath","Asesino","asesino"}),SF(informa),1);
    AddQuestion(({"Daryl","daryl","jefe","jefe de la guardia"}),SF(informa2),1);
    AddItem(ARMAS("cuchillo"), REFRESH_REMOVE, SF(wieldme));
    InitChats(10,SF(dialogo));
}
