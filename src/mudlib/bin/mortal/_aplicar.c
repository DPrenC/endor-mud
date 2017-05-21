/****************************************************************************
Fichero: /byn/mortal/_aplicar.c
-Descripción: Habilidad "aplicar bálsamo".
****************************************************************************/
#include <config.h>
#include <properties.h>
#include <guild.h>
#include <skills.h>
#include <moving.h>
#define AQUI    environment(TP)

int main(string str)
{
    int yo, hab, efecto, cont, cant, grado, tiempo;
    string nom, que, quien, modo;
    object vial, herido, balsamo;
    //Si no es guardabosque o kisala, o no tiene la habilidad, comando desconocido.
    if (((TP->QueryGuild()!=GC_KISALA) && (TP->QueryGuild()!=GC_GUARDABOSQUE)) ||
        (!TP->HasSkill(HAB_BALSAMO))) return 0;
    //Si no especifica qué aplicar, y/o a quién, se le pregunta.
    if (!str || ((sscanf(str,"%s a %s",que,quien)!=2) && (sscanf(str,"%s %s",que,quien)!=2)) ||
        ((que!="bálsamo") && (que!="balsamo"))) return notify_fail("¿Qué quieres aplicar, y a quién?\n",
        NOTIFY_NOT_VALID);
    //Si no tiene bálsamo, se le advierte.
    if (((!vial=present("balsamo_vial",TP))) || (!vial->QueryContent())) return notify_fail(
        "No tienes ninguna cosa que pueda aplicarse.\n",NOTIFY_NOT_VALID);
    //Si no ve, no puede aplicar nada.
    if (!TP->CanSee()) return notify_fail("No puedes aplicar nada si no cuentas con más luz que te permita ver lo que haces.\n",NOTIFY_NOT_VALID);
    herido=present(quien,AQUI);
    yo=(herido==TP);
    //Se comprueba que el objetivo está presente y vivo.
    if (!yo)
    {
        if (!herido) return notify_fail(""+quien+" no está presente.\n",NOTIFY_NOT_VALID);
        if (!living(herido)) return notify_fail("No está tan herido como para que necesite que se le apliquen curaciones.\n",
            NOTIFY_NOT_VALID);
    }
    // si está cansado no puede hacerlo.
    if (TP->QueryTP()<5) return notify_fail("No tienes suficientes energías para aplicar nada.\n",
        NOTIFY_NOT_VALID);
    // si está paralizado, no puede hacerlo.
    if (TP->QueryCombatDelay()) return notify_fail(TP->QueryCombatDelayMsg()||"No puedes moverte.\n",NOTIFY_NOT_VALID);
    nom=CAP(herido->QueryRealName());
    // se comprueba que el herido no está luchando
    if (herido->Fighting()) return notify_fail((yo?"Estás luchando y necesitas dedicar "
    	"toda tu concentración al combate.\n":nom+" está luchando y no puedes aplicarle nada.\n"),NOTIFY_NOT_VALID);
    //Comprobamos que el herido necesita realmente ser curado.
    if (herido->QueryHealth()>=98) return notify_fail((yo?"No necesitas ":nom+
        " no necesita ")+" curar ninguna herida.\n",NOTIFY_NOT_VALID);
    grado=((100-herido->QueryHealth())/17)+1;
    cont=vial->QueryContent();
    if (cont>=grado) cant=grado;
    else
    {
        tell_object(TP,"Tratas de sacar el máximo partido al poco bálsamo que te queda.\n");
        cant=cont;
    }
    hab=TP->UseSkill(HAB_BALSAMO,TP->QueryDex());
    tell_object(TP,"Aplicas  el bálsamo para curar"+(yo?"te.\n":" a "+nom+".\n"));
    if (!yo) tell_object(herido,TNREAL+" aplica un bálsamo sobre tus heridas, curándote.\n");
    if (TP->QueryInvis()<1) tell_room(AQUI,TNREAL+" usa un bálsamo para curar"+(yo?"se.\n":" a "+nom+".\n"),(yo?({TP}):({herido,TP})));
    if (hab<=0)
    {
        tell_object(TP,"Por falta de práctica, exgtiendes torpemente el bálsamo ");
        if (TP->QueryInvis()<1) tell_room(AQUI,"Por falta de práctica extiende con gran torpeza el bálsamo , ",({TP}));
        if (hab<=-30)
        {
            tell_object(TP," desperdiciándolo de forma absurda.\n");
            if (TP->QueryInvis()<1) tell_room(AQUI," y lo desperdicia en gran parte.\n",({TP}));
            vial->SetContent(cont-cant);
            if (!vial->QueryContent()) tell_object(TP,"El bálsamo se ha terminado.\n");
            return 1;
        }
        tell_object(TP,"pero conservas la mayor parte del bálsamo.\n");
        if (TP->QueryInvis()<1) tell_room(AQUI,"aunque logra impedir que el bálsamo se "
            "desperdicie.\n",({TP}));
        return 1;
    }
    vial->SetContent(cont-cant);
    if (!vial->QueryContent()) tell_object(TP,"El bálsamo se ha terminado.\n");
    efecto=(vial->QueryPotencia()*((6*herido->QueryMaxHP())/100)*cant)/grado;
    tiempo=hab/16+1;
    if (hab > 100) hab=100;
    switch(hab)
    {
        case 1..16:
            modo="gran torpeza.\n";
        break;
        case 17..32:
            modo="torpeza.\n";
        break;
        case 33..48:
            modo="alguna dificultad.\n";
        break;
        case 49..64:
            modo="destreza.\n";
        break;
        case 65..80:
            modo="gran destreza.\n";
        break;
        case 81..100:
            modo="total maestría.\n";
        break;
    }
    seteuid(getuid());
    balsamo=clone_object("/obj/balsamo");
    if (balsamo->move(herido,M_SILENT)!=ME_OK)
    {
        tell_object(TP,"No consigues aplicar el bálsamo. "+(yo?"Deberías":"debería")+" soltar algo de equipo.\n");
            if (!yo) tell_object(herido,"No consigue aplicar correctamente el bálsamo. Deberías dejar algo de equipo.\n");
                if (TP->QueryInvis()!=1) tell_room(AQUI,"No consigue aplicar correctamente el bálsamo.\n",(yo?({TP}):({herido,TP})));
                    return balsamo->remove(),1;
    }
    tell_object(TP,"Tomas cierta cantidad de bálsamo, y lo aplicas sobre "+(yo?"tus":"sus")+
        " heridas con "+modo);
    if (!yo) tell_object(herido,"Toma un poco de bálsamo, y lo aplica sobre tus heridas con "+
        modo);
    if (TP->QueryInvis()!=1) tell_room(AQUI,"toma algo de bálsamo, y lo aplica sobre sus "
        "heridas con "+modo,(yo?({TP}):({herido,TP})));
    herido->HealHP(efecto);
    balsamo->SetEfecto(efecto);
    balsamo->SetTiempo(tiempo);
    balsamo->start_heal(efecto);
    return 1;
}
          