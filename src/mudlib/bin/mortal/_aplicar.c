/****************************************************************************
Fichero: /byn/mortal/_aplicar.c
-Descripci�n: Habilidad "aplicar b�lsamo".
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
    //Si no especifica qu� aplicar, y/o a qui�n, se le pregunta.
    if (!str || ((sscanf(str,"%s a %s",que,quien)!=2) && (sscanf(str,"%s %s",que,quien)!=2)) ||
        ((que!="b�lsamo") && (que!="balsamo"))) return notify_fail("�Qu� quieres aplicar, y a qui�n?\n",
        NOTIFY_NOT_VALID);
    //Si no tiene b�lsamo, se le advierte.
    if (((!vial=present("balsamo_vial",TP))) || (!vial->QueryContent())) return notify_fail(
        "No tienes ninguna cosa que pueda aplicarse.\n",NOTIFY_NOT_VALID);
    //Si no ve, no puede aplicar nada.
    if (!TP->CanSee()) return notify_fail("No puedes aplicar nada si no cuentas con m�s luz que te permita ver lo que haces.\n",NOTIFY_NOT_VALID);
    herido=present(quien,AQUI);
    yo=(herido==TP);
    //Se comprueba que el objetivo est� presente y vivo.
    if (!yo)
    {
        if (!herido) return notify_fail(""+quien+" no est� presente.\n",NOTIFY_NOT_VALID);
        if (!living(herido)) return notify_fail("No est� tan herido como para que necesite que se le apliquen curaciones.\n",
            NOTIFY_NOT_VALID);
    }
    // si est� cansado no puede hacerlo.
    if (TP->QueryTP()<5) return notify_fail("No tienes suficientes energ�as para aplicar nada.\n",
        NOTIFY_NOT_VALID);
    // si est� paralizado, no puede hacerlo.
    if (TP->QueryCombatDelay()) return notify_fail(TP->QueryCombatDelayMsg()||"No puedes moverte.\n",NOTIFY_NOT_VALID);
    nom=CAP(herido->QueryRealName());
    // se comprueba que el herido no est� luchando
    if (herido->Fighting()) return notify_fail((yo?"Est�s luchando y necesitas dedicar "
    	"toda tu concentraci�n al combate.\n":nom+" est� luchando y no puedes aplicarle nada.\n"),NOTIFY_NOT_VALID);
    //Comprobamos que el herido necesita realmente ser curado.
    if (herido->QueryHealth()>=98) return notify_fail((yo?"No necesitas ":nom+
        " no necesita ")+" curar ninguna herida.\n",NOTIFY_NOT_VALID);
    grado=((100-herido->QueryHealth())/17)+1;
    cont=vial->QueryContent();
    if (cont>=grado) cant=grado;
    else
    {
        tell_object(TP,"Tratas de sacar el m�ximo partido al poco b�lsamo que te queda.\n");
        cant=cont;
    }
    hab=TP->UseSkill(HAB_BALSAMO,TP->QueryDex());
    tell_object(TP,"Aplicas  el b�lsamo para curar"+(yo?"te.\n":" a "+nom+".\n"));
    if (!yo) tell_object(herido,TNREAL+" aplica un b�lsamo sobre tus heridas, cur�ndote.\n");
    if (TP->QueryInvis()<1) tell_room(AQUI,TNREAL+" usa un b�lsamo para curar"+(yo?"se.\n":" a "+nom+".\n"),(yo?({TP}):({herido,TP})));
    if (hab<=0)
    {
        tell_object(TP,"Por falta de pr�ctica, exgtiendes torpemente el b�lsamo ");
        if (TP->QueryInvis()<1) tell_room(AQUI,"Por falta de pr�ctica extiende con gran torpeza el b�lsamo , ",({TP}));
        if (hab<=-30)
        {
            tell_object(TP," desperdici�ndolo de forma absurda.\n");
            if (TP->QueryInvis()<1) tell_room(AQUI," y lo desperdicia en gran parte.\n",({TP}));
            vial->SetContent(cont-cant);
            if (!vial->QueryContent()) tell_object(TP,"El b�lsamo se ha terminado.\n");
            return 1;
        }
        tell_object(TP,"pero conservas la mayor parte del b�lsamo.\n");
        if (TP->QueryInvis()<1) tell_room(AQUI,"aunque logra impedir que el b�lsamo se "
            "desperdicie.\n",({TP}));
        return 1;
    }
    vial->SetContent(cont-cant);
    if (!vial->QueryContent()) tell_object(TP,"El b�lsamo se ha terminado.\n");
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
            modo="total maestr�a.\n";
        break;
    }
    seteuid(getuid());
    balsamo=clone_object("/obj/balsamo");
    if (balsamo->move(herido,M_SILENT)!=ME_OK)
    {
        tell_object(TP,"No consigues aplicar el b�lsamo. "+(yo?"Deber�as":"deber�a")+" soltar algo de equipo.\n");
            if (!yo) tell_object(herido,"No consigue aplicar correctamente el b�lsamo. Deber�as dejar algo de equipo.\n");
                if (TP->QueryInvis()!=1) tell_room(AQUI,"No consigue aplicar correctamente el b�lsamo.\n",(yo?({TP}):({herido,TP})));
                    return balsamo->remove(),1;
    }
    tell_object(TP,"Tomas cierta cantidad de b�lsamo, y lo aplicas sobre "+(yo?"tus":"sus")+
        " heridas con "+modo);
    if (!yo) tell_object(herido,"Toma un poco de b�lsamo, y lo aplica sobre tus heridas con "+
        modo);
    if (TP->QueryInvis()!=1) tell_room(AQUI,"toma algo de b�lsamo, y lo aplica sobre sus "
        "heridas con "+modo,(yo?({TP}):({herido,TP})));
    herido->HealHP(efecto);
    balsamo->SetEfecto(efecto);
    balsamo->SetTiempo(tiempo);
    balsamo->start_heal(efecto);
    return 1;
}
          