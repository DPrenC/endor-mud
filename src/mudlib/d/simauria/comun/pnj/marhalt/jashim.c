/********************
Fichero: /d/simauria/comun/pnj/marhalt/jashim.c
Autor: Lug y Yalin
Descripci�n: Ladr�n prisionero en Nandor, hermano de Betky
Fecha: 24/09/2007 16:55:32
********************/

#include "path.h"
#include <properties.h>
#include <moving.h>
#include <messages.h>
#include <wizlevels.h>
inherit NPC;

string robo()
{
    foreach(object inv:all_inventory(environment()))
    {
        if (query_once_interactive(inv))
        {
            if (IS_LEARNER(inv)) return "";
            object *tiene, cosa;
            tiene=all_inventory(inv);
            tiene-=inv->QueryArmours();
            if (!sizeof(tiene)) return "";
            cosa=tiene[random(sizeof(tiene))];
            string coge=cosa->QueryShort();
            if (cosa->id("dinero")) coge = "el dinero";
            tell_object(inv,"Jashim hace un gesto r�pido de manos, y para tu asombro, te arrebata "+
                coge+". Luego, viendo tu cara de desagrado, dice: Ja, ja, ja, no te enfades, "+
                CAP(inv->QueryName())+". s�lo era una broma. Como comprender�s, aqu� no "
                "necesito "+coge+". Ja, ja, ja, aqu� est�.\nY con sonrisa maliciosa, te devuelve "+
                coge+".\n");
        }
    }
    return "";
}
                
string dialogo()
{
    filter(all_inventory(environment()),
    (:if (query_once_interactive($1))
    {
        if ($1->QueryAttribute("carta_betky"))
        {
            tell_object($1,"Jashim te dice: Por favor, lleva la carta a mi hermana, estar� "
                "asustada la pobre.\n");
            return "";
        }
        switch(d3())
        {
            case 1:
                tell_object($1,"Jashim suspira: �Pobre Betky, ni siquiera pude avisarla...\n");
            break;
            case 2:
                tell_object($1,"Jashim dice: Mi hermana no sabe d�nde estoy, estar� preocupada.\n");
            break;
            case 3:
                tell_object($1,"Jashim arruga la frente diciendo: Alguien deber�a dec�rselo a mi hermana...\n");
            break;
        }
        return "";
    }
    :));
    return"";
}
        
string informa()
{
    if (TP->QueryAttribute("lanzaacido")) return"Jashim dice: Pues bueno, bien, dentro de lo "
        "que cabe. Estar� arreglando mi casa, supongo, pero al menos espero que ya est� "
        "tranquila, gracias a ti.\n";
    if (TP->QueryAttribute("carta_betky")) return"Jashim te mira incr�dulo y dice: �Pero si te "
        "lo acabo de decir! Ya sabes d�nde vive. Por favor, ll�vale mi mensaje, seguro que te "
        "recompensar�.\n";
    write("Jashim suspira profundamente y te explica: Bueno, Betky es una mujer algo gru�ona, "
        "pero es muy buena. Lleva a�os haciendo las faenas de mi casa, �sabes?, la casa "
        "frente a la herrer�a. Gru�e siempre, pero no me abandona.\nEl caso es que cuando..., "
        "esto..., me hospedaron aqu�, no tuve tiempo de decirle nada, as� que la pobre estar� "
        "preocupada, yo s� que me quiere mucho.\nMira, tengo escrita una carta, t�mala.\n");
    object carta = clone_object(OTRO("marhalt/nandor/carta_betky"));
    carta->SetOwner(TP->QueryRealName());
    TP->SetAttribute("carta_betky",1);
    write("Jashim te da una carta.\n");
    if (!carta->move(TP))
    {
        carta->move(environment());
        write("Sin que puedas evitarlo, la carta se te cae al suelo.\n");
        say("A "+capitalize(TP->QueryName())+" se le cae una carta de las manos.\n",TP);
    }
    return"Jashim a�ade: Por favor, ll�vasela, seguro que te recompensa. En mi casa hay muchas "
        "cosillas de las que yo..., esto, ejem..., encuentro por ah�.\n";
}
             
create()
{
    ::create();
    SetStandard("Jashim","humano",5,GENERO_MASCULINO);
    SetName("jashim");
    AddId(({"Jashim","jashim","ladron","ladr�n"}));
    SetShort("Jashim, el ladr�n");
    SetLong("Jashim es un ladronzuelo de poca monta, algo est�pido para su afici�n a disponer "
        "de lo ajeno, de mano demasiado larga, pero con muy poco �xito. Es por eso que cada "
        "dos por tres viene a dar con sus huesos en alguna celda de esta prisi�n.\nEs un "
        "hombrecillo de cara p�cara pero en parte inocente, de ojos negros e inquisitivos que "
        "no ocultan su excesivo candor para el oficio que..., intenta profesar.\nEs tan "
        "extra�amente c�ndido, que hasta en esta celda mira nerviosamente a todos lados, como "
        "si esperara a�n aqu� hallar algo de qu� apropiarse. Tal vez convendr�a que vigilases "
        "tus pertenencias...\n");
    SetAlign(200); // en el fondo es un ni�o grande
    AddQuestion(({"hermana","Betky","betky"}),SF(informa),1);
    SetShrugMsg("Jashim se rasca la cabeza mientras dice: No s�..., nunca he o�do hablar de eso.\n");
    InitChats(10,({
        "Jashim mueve la cabeza murmurando: Mi pobre hermana, siempre atendi�ndome, y yo "
            "siempre d�ndole disgustos...\n",
        "Jashim te sonr�e y dice: Yo no soy malo, �sabes? Lo que pasa es que la gente no me "
            "entiende.\n",
        SF(dialogo),
        SF(robo)
    }));
}
