/*****************************************************************************************
 ARCHIVO:       Dildalh.c
 AUTOR:         Ztico
 FECHA:         08-04-2005
 COMENTARIOS:   Dildalh, posadera del Unicornio Azul.
 ****************************************************************************************/

#include "./path.h"
#include <colours.h>
#include <gremios.h>
#include <properties.h>
#define ATTE_RUNAS "quest_runas"
#define QUEST_KEY "santuario_druida_quest"

inherit NPC;

public int cmd_alquilar(string str);
public string f_preguntar_gleryn();

create()
{
    if(::create()) return 1;

    SetStandard("dildalh", "elfo", ([GC_HECHICERO: 45 + d6()]), GENERO_FEMENINO);
    SetShort("dildalh, la posadera");
    switch(d4())
    {
        case 1:
             SetLong("He aqu� a Dildalh, la elfa. Desempe�a la labor de posadera en "
                 "esta taberna, aunque por su aspecto bien podr�a ser la principal "
                 "atracci�n del lugar. Su cabello dorado, sus grandes ojos grises y su "
                 "delicado rostro no consiguen ocultar la picard�a que se advierte en su "
                 "mirada. Su atuendo es pr�ctico a la par que seductor, y su estilizada "
                 "figura atrae todas las miradas del local.\n");
             break;
        case 2:
             SetLong("Ante t� se halla Dildalh, la posadera del local. Es una elfa "
                 "rubia, con unos grandes ojos grises y un rostro delicado que combinan "
                 "a la perfecci�n con la estilizada figura que se adivina bajo sus ropas. "
                 "Podr�a ser la m�s bella criatura que han contemplado tus ojos, no "
                 "obstante, algo en su mirada y en su p�cara sonrisa sugieren que "
                 "debieras mantener a resguardo tu bolsillo.\n");
             break;
        case 3:
             SetLong("Esta bella criatura que te sonr�e es Dildalh, la elfa, posadera "
                 "de este local. Su larga melena rubia, sus preciosos ojos grises y su "
                 "delicada figura son la admiraci�n de toda la clientela. No obstante, "
                 "hay algo en el brillo de sus ojos que te hace pensar que no es tan "
                 "inocente como aparenta.\n");
             break;
        case 4:
             SetLong("Tienes ante ti a Dildalh, la hermosa posadera del local. Es una "
                 "elfa rubia, delicada y de grandes ojos grises, vestida con una "
                 "llamativa t�nica carmes� que acompa�a con elegancia el movimiento de "
                 "su cuerpo. Su aspecto es a la vez inocente y p�caro, y sientes la "
                 "tentaci�n de admirarla a la par que proteges tu bolsillo.\n");
             break;
    }
    AddId(({"elfa", "posadera", "posadero"}));
    AddQuestion(({"miembro", "antiguo miembro", "druida", "gleryn",
        "gleryn el hechicero", "hechicero"}), SF(f_preguntar_gleryn), 1);

    SetAttackChance(1000);
    SetWhimpy(50);
}

public int cmd_alquilar(string str)
{
    if(!str) return 0;
    if(str == "habitaci�n" || str == "habitacion" || str == "una habitaci�n" ||
       str == "una habitacion")
    {
        if(environment()->QueryIsInn())
        {
            tell_object(TP, TC_TEL_WHO "Dildalh dice:" TC_TEL_MSG " Lo siento pero "
                "las habitaciones de esta posada est�n reservadas para el uso exclusivo "
                "de los druidas. Quiz�s haya alguna habitaci�n libre en la posada de mi "
                "viejo amigo Engelbergt.\n" TC_NORMAL);
            say(CAP(TNAME) + " habla con la posadera.\n", TP);
            return 1;
        }
    }
    return 0;
}

public string f_preguntar_gleryn()
{
    if(QUESTMASTER->QueryQuestSolved(QUEST_KEY, TP))
    {
        return "Dildalh se encoge de hombros.\n";
    }
    else if(TP->QueryAttribute(ATTE_RUNAS))
    {
        return TC_TEL_WHO "Dildalh dice:" TC_TEL_MSG " Supongo que te refieres a ese "
               "elfo que merodea por la zona. Pues hace d�as que no le veo, parec�a un "
               "druida de la Orden, un poco demacrado. Alquil� una habitaci�n en la "
               "posada, pero se pasaba las horas en el sal�n de los druidas.\n" TC_NORMAL;
    }
    return "Dildalh se encoge de hombros.\n";
}

public varargs void init()
{
    ::init();

    add_action("cmd_alquilar", "alquilar");
}
