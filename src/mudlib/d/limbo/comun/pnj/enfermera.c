/*
DESCRIPCION  : Enfermera de la habitacion de reposo
FICHERO      : /d/limbo/comun/pnj/enfermera.c
MODIFICACION : 30-09-98 [Angor@Simauria] Creacion.
               10-10-99 [Woo] SetStandard y toqueteada..
               16-11-01 [Theuzifan] Arreglado un fallo en el present(), que
               		aparec�a cuando no se pon�an argumentos en el "matar"
--------------------------------------------------------------------------------
*/

#include "./path.h"
#include <properties.h>
#include <messages.h>
#include <wizlevels.h>
inherit NPC;
#define AO      (TP->QueryGenderEndString())
#define AE      ((TP->QueryGender()==GENERO_FEMENINO)?"a":"e")
#define NOMBRE  (capitalize(TP->QueryName()))

int nolucho()
{
    tell_room(environment(),NOMBRE+" ataca a Silvailine, pero de repente queda paralizad"+AO+
        " por alguna fuerza invisible. Silvailine le dice a "+NOMBRE+" que es una maga "
        "poderosa y que no le obligue a hacerle da�o, para a continuaci�n liberarl"+AE+".\n",({TP}));
    return notify_fail("Cuando vas a atacar a Silvailine notas un fugaz brillo en sus ojos y de "
        "repente, sientes como alguna extra�a fuerza inmoviliza tus miembros, mientras un "
        "doloroso escalofr�o recorre todo tu cuerpo. Silvailine te dice:' No deber�as hacer "
        "eso. Recuerda que estoy aqu� para ayudar, en nombre de los dioses. Adem�s, soy elfa, "
        "y como muchos de los de mi raza soy maestra en el arte de la magia. No me obligues a "
        "hacerte da�o.\nSilvailine sonr�e, mientras la par�lisis que reten�a tu cuerpo "
        "desaparece.\n",NOTIFY_NOT_VALID);
}

int esquivo(string str)
{
    string a, b;
    object que, quien;
    if (!str) return notify_fail("�Lanzar qu� contra quien?\n");
    if ( (sscanf(str,"%s contra %s",a,b)!=2) && (sscanf(str,"%s a %s",a,b)!=2) && (sscanf(str,"%s %s",a,b)!=2) )
    return notify_fail("�Lanzar qu� contra quien?\n");
    if (TP->QueryStunned() || TP->QueryCombatDelay())
    return notify_fail("No puedes lanzar nada en estos instantes.\n");
    que = present(a, TP);
    quien = present(b, environment(TP));
    if (!que) return notify_fail("No tienes "+a+" que lanzar.\n",NOTIFY_NOT_VALID);
    if (!quien) return notify_fail("No ves a "+b+" por aq� para lanzarle nada.\n",
        NOTIFY_NOT_VALID);
    string nque=que->QueryShort();
    if (quien==TO)
    {
        tell_room(environment(),NOMBRE+" intenta lanzar "+nque+" a Silvailine, pero de repente " 
            "queda paralizad"+AO+" por alguna fuerza invisible. Silvailine le dice a "+NOMBRE+
            " que es una maga poderosa y que no le obligue a hacerle da�o, para a continuaci�n "
            "liberarl"+AE+".\n",({TP}));
        write("Intentas lanzarle "+nque+" a Silvailine. Notas un fugaz brillo en sus ojos y de "
            "repente, sientes como alguna extra�a fuerza inmoviliza tus miembros, mientras un "
            "doloroso escalofr�o recorre todo tu cuerpo. Silvailine te dice: No deber�as hacer "
            "eso. Recuerda que estoy aqu� para ayudar, en nombre de los dioses. Adem�s, soy "
            "elfa, y como muchos de los de mi raza soy maestra en el arte de la magia. No me "
            "obligues a hacerte da�o.\nSilvailine sonr�e, mientras la par�lisis que reten�a tu "
            "cuerpo desaparece.\n");
        return 1;
    }
    return 0;
}

string dialogo()
{
    foreach(object ob:all_inventory(environment()))
    {
        if (query_once_interactive(ob))
        {
            if (ob->QueryGhost() == 1 || !IS_BEGINNER(ob)) return"";
            switch(d2())
            {
                case 1:
                    tell_object(ob,"Silvailine te dice: En la planta baja de este edificio encontrar�s todo "
                        "tipo de objetos con los que equiparte.\n");
                break;
                case 2:
                    tell_object(ob,"Silvailine dice: Parece que est�s mejor, as� que no tienes por que "
                        "permanecer aqu� m�s tiempo. Sal y explora ese maravilloso mundo que te "
                        "espera ah� fuera.\n");
                break;
            }
        }
    }
    return"";
}

create()
{
    ::create();
   SetStandard("Silvailine","elfo",10,GENDER_FEMALE);
    SetChkFightFunction(SF(nolucho));
    SetChkMagicFunction(SF(nolucho));
    SetShort("Silvailine, la enfermera");
    SetLong("Silvailine es una de las elfas m�s bellas que has visto en tu vida. De rasgos delicados y movimientos estilizados, podrias perderte en sus ojos de mirada ausente y un color azul intenso. Silvailine trabaja para los dioses como enfermera atendiendo a los pacientes de Asthar tras su operaci�n. Va de un lado a otro de la habitaci�n siempre con cosas que hacer.\n");
    SetIds(({"elfo","elfa","sierva","silvailine","Silvailine","enfermera"}));
    SetAds(({"una","enfermera","bella","elfa"}));
    SetAlign(200);
    SetAC(3);
    SetMaxHP(200);
    SetHP(200);
    SetDex(15);
    SetStr(12);
    SetInt(15);
    SetCon(10);
    SetNoGet("Silvailine te dice: 'No molestes, tengo m�s pacientes a los que atender'.\n");
    SetWeight(60000);
    SetAggressive(0);
    InitChats(15,({
        "Silvailine va a ver un paciente al fondo de la habitaci�n.\n",
        "Silvailine coge algunas medicinas y ayuda a un paciente a tomarlas.\n",
        "Silvailine cambia las s�banas de una cama que ha quedado vac�a.\n",
        SF(dialogo)}));
    AddQuestion(({"asthar","Asthar","templo","templo de Asthar"}),
  "Si quieres ir al templo de Asthar deber�s salir de este edificio y una vez en "
  "la plaza ver�s que el templo es el gran edificio que queda al sur.\n");

  AddQuestion(({"playa","playa de levante","playa de Levante"}),
  "La playa de Levante queda al nordeste de esta isla.\n");

  AddQuestion(({"llaves","llaves del templo"}),
  "No se, supongo que las debe tener Asthar.\n");
    Set(P_CANT_LURE,1);
    Set(P_CANT_STEAL,1);
}

init()
{
    ::init();
    add_action("esquivo","lanzar");
}
