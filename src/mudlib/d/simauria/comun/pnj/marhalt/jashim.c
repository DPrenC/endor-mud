/********************
Fichero: /d/simauria/comun/pnj/marhalt/jashim.c
Autor: Lug y Yalin
Descripción: Ladrón prisionero en Nandor, hermano de Betky
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
            tell_object(inv,"Jashim hace un gesto rápido de manos, y para tu asombro, te arrebata "+
                coge+". Luego, viendo tu cara de desagrado, dice: Ja, ja, ja, no te enfades, "+
                CAP(inv->QueryName())+". sólo era una broma. Como comprenderás, aquí no "
                "necesito "+coge+". Ja, ja, ja, aquí está.\nY con sonrisa maliciosa, te devuelve "+
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
            tell_object($1,"Jashim te dice: Por favor, lleva la carta a mi hermana, estará "
                "asustada la pobre.\n");
            return "";
        }
        switch(d3())
        {
            case 1:
                tell_object($1,"Jashim suspira: ¡Pobre Betky, ni siquiera pude avisarla...\n");
            break;
            case 2:
                tell_object($1,"Jashim dice: Mi hermana no sabe dónde estoy, estará preocupada.\n");
            break;
            case 3:
                tell_object($1,"Jashim arruga la frente diciendo: Alguien debería decírselo a mi hermana...\n");
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
        "que cabe. Estará arreglando mi casa, supongo, pero al menos espero que ya esté "
        "tranquila, gracias a ti.\n";
    if (TP->QueryAttribute("carta_betky")) return"Jashim te mira incrédulo y dice: ¡Pero si te "
        "lo acabo de decir! Ya sabes dónde vive. Por favor, llévale mi mensaje, seguro que te "
        "recompensará.\n";
    write("Jashim suspira profundamente y te explica: Bueno, Betky es una mujer algo gruñona, "
        "pero es muy buena. Lleva años haciendo las faenas de mi casa, ¿sabes?, la casa "
        "frente a la herrería. Gruñe siempre, pero no me abandona.\nEl caso es que cuando..., "
        "esto..., me hospedaron aquí, no tuve tiempo de decirle nada, así que la pobre estará "
        "preocupada, yo sé que me quiere mucho.\nMira, tengo escrita una carta, tómala.\n");
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
    return"Jashim añade: Por favor, llévasela, seguro que te recompensa. En mi casa hay muchas "
        "cosillas de las que yo..., esto, ejem..., encuentro por ahí.\n";
}
             
create()
{
    ::create();
    SetStandard("Jashim","humano",5,GENERO_MASCULINO);
    SetName("jashim");
    AddId(({"Jashim","jashim","ladron","ladrón"}));
    SetShort("Jashim, el ladrón");
    SetLong("Jashim es un ladronzuelo de poca monta, algo estúpido para su afición a disponer "
        "de lo ajeno, de mano demasiado larga, pero con muy poco éxito. Es por eso que cada "
        "dos por tres viene a dar con sus huesos en alguna celda de esta prisión.\nEs un "
        "hombrecillo de cara pícara pero en parte inocente, de ojos negros e inquisitivos que "
        "no ocultan su excesivo candor para el oficio que..., intenta profesar.\nEs tan "
        "extrañamente cándido, que hasta en esta celda mira nerviosamente a todos lados, como "
        "si esperara aún aquí hallar algo de qué apropiarse. Tal vez convendría que vigilases "
        "tus pertenencias...\n");
    SetAlign(200); // en el fondo es un niño grande
    AddQuestion(({"hermana","Betky","betky"}),SF(informa),1);
    SetShrugMsg("Jashim se rasca la cabeza mientras dice: No sé..., nunca he oído hablar de eso.\n");
    InitChats(10,({
        "Jashim mueve la cabeza murmurando: Mi pobre hermana, siempre atendiéndome, y yo "
            "siempre dándole disgustos...\n",
        "Jashim te sonríe y dice: Yo no soy malo, ¿sabes? Lo que pasa es que la gente no me "
            "entiende.\n",
        SF(dialogo),
        SF(robo)
    }));
}
