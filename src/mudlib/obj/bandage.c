/********************
Fichero: /obj/bandage.c
Autor: Yalin
Fecha: 28/10/2007 23:54:41
Descripcion: Venda para los guerreros, rehecho de nuevo.
********************/

#include <config.h>
#include <properties.h>
#include <combat.h>
#include <skills.h>
#include <moving.h>
#include <equipment.h>
#include <messages.h>

inherit ARMOUR;

int nvendas; //contador de usos

private void SetDesc()
{
    if (nvendas <=0)
    {
        write("Has gastado todo el rollo de venda.\n");
        TO->remove();
        return ;
    }
    SetValue(nvendas*20);
    SetWeight(nvendas*50);
    SetShort("un rollo de venda, para "+nvendas+" curas");
    SetLong("Es una larga faja de tela de unos 10 centímetros de anchura, cuidadosamente "
        "enrollada. Sirve para vendar las heridas, facilitando una cura rápida.\nQueda venda "
        "para "+nvendas+" curas.\n");
    return;
}

public nomask int Defend (object enemy, int damage, int dam_type) {return 0;} // no ofrece ninguna protecci^Sn

public int cmd_bandage(string str)
{
    object venda,herido;
    int guerrero,habil;
    string obra,obj,nombre;
    // si el player no ve, (noche o sitio oscuro sin lámpara o similares)
    if (TP->CantSee()) return notify_fail("No ves lo que haces.\n",
        NOTIFY_NOT_VALID);
    // Si no es un guerrero no sabe vendar
    if (TP->QueryGuild()!="guerrero") return notify_fail("No sabes cómo hacerlo.\n",
        NOTIFY_NOT_VALID);
    // si no se especifica objetivo se asume al propio guerrero
    if (!str) str = getuid(TP);
    herido=present(str,environment(TP));
    guerrero=(herido==TP);
    nombre=NNAME(TP);
    // comprobamos si nombre==string , si no nombre == "alguien"
    if(!stringp(nombre)) nombre="Alguien";
    // se comprueba que el objetivo está presente y vivo
    if (!guerrero)
    {
        if (!herido) return notify_fail("No ves "+str+" por aquí.\n",
            NOTIFY_NOT_VALID);
        if (!living(herido)) return notify_fail("¿Y para qué querrías vendar a "+
            (herido->Short()||str)+"?.\n",NOTIFY_NOT_VALID);
    }
    obj=NNAME(herido);
    // si está cansado no puede vendar
    if (TP->QueryTP()<5) return notify_fail("Estás demasiado cansado para hacer eso.\n",
        NOTIFY_NOT_VALID);
    // si está paralizado, no puede vendar
    if (TP->QueryCombatDelay()) return notify_fail(TP->QueryCombatDelayMsg()||"Ahora no puedes "
        "hacer eso.\n",NOTIFY_NOT_VALID);
    // se comprueba que el objetivo no está luchando
    if (herido->Fighting()) return notify_fail((guerrero?"Tienes que concentrarte en la "
        "lucha.\n":CAP(obj)+" está ocupado luchando.\n"),NOTIFY_NOT_VALID);
    // se comprueba que el objetivo no esté ya vendado
    if (present("wbandage",herido)) return notify_fail((guerrero?"Ya tienes una venda puesta.\n" : 
        CAP(obj)+" ya tiene una venda puesta.\n"),NOTIFY_NOT_VALID);
    // si no está herido, ¿para qué vendar?
    if (herido->QueryHP() == herido->QueryMaxHP()) return notify_fail("No es necesario curar a "
        "quien está bien sano.\n",NOTIFY_NOT_VALID);
    if (!herido->MayAddIntWeight(QueryWeight())) return notify_fail((guerrero?"No puedes " : 
        CAP(obj)+" no puede ")+"llevar la venda.\n",NOTIFY_NOT_VALID);
    habil=TP->UseSkill(HAB_VENDAJE,TP->QueryDex());
    if (habil<=0)
    {
        write("No has podido vendar"+(guerrero?"te.\n":" a "+CAP(obj)+".\n"));
        say(CAP(nombre)+" intenta vendar"+(guerrero?"te":" a "+CAP(obj))+", pero falla.\n",
            (guerrero?({TP}):({herido,TP})));
        if (!guerrero) tell_object(herido,CAP(nombre)+" intenta vendarte, pero falla.\n");
        if (habil<-30)
        {
            venda=clone_object("obj/rbandage");
            if (venda) venda->move(TP,M_SILENT);
            write("La venda se ha estropeado. No puede ser ya utilizada.\n");
            nvendas--;
            SetDesc();
        }
        return 1;
    }
    if (habil > 100) habil=100;
    switch(habil)
    {
        case 100:
            obra="a obra de arte ";
        break;
        case 95..99:
            obra="a maravilla ";
        break;
        case 88..94:
            obra="a filigrana ";
        break;
        case 80..87:
            obra=" trabajo excelente ";
        break;
        case 70..79:
            obra=" trabajo muy bueno ";
        break;
        case 60..69:
            obra=" buen trabajo ";
        break;
        case 50..59:
            obra=" trabajo aceptable ";
        break;
        case 40..49:
            obra="trabajo regular ";
        break;
        case 30..39:
            obra=" trabajo mediocre ";
        break;
        case 20..29:
            obra=" mal trabajo ";
        break;
        case 15..19:
            obra=" trabajo muy malo ";
        break;
        case 10..14:
            obra=" trabajo pésimo ";
        break;
        case 0..9:
            obra="a chapuza ";
        break;
    }
    venda=clone_object("/obj/wbandage");
    if (venda) venda->move(herido,M_SILENT);
    write("Haces un"+obra+(guerrero?"vendándote.\n":"vendando a "+CAP(obj)+".\n"));
    say(nombre+" hace un"+obra+(guerrero?"vendándose.\n":"vendando a "+CAP(obj)+".\n"),
        (guerrero?({TP}):({herido,TP})));
    if (!guerrero) tell_object(herido,"vendándote.\n");
    if (venda->Equip(herido,EWF_SILENT) != EQ_OK)
    {
        tell_room(environment(herido),"Por desgracia la venda no se sostiene.\n");
        venda->remove();
        nvendas--;
        SetDesc();
        return 1;
    }
    herido->HealHP(1+habil/3);
    venda->SetPercent(habil);
    venda->SetCount(habil/20+2);
    nvendas--;
    SetDesc();
    return 1;
}

create()
{
    ::create();
    nvendas = 5;
    SetDesc();
    Set(P_GENDER, GENERO_MASCULINO);
    AddId(({"venda","vendas","rollo","rollo de venda","rollo de vendas"}));
    AddAdjective(({"limpia","limpias","limpio"}));
    RemoveClassId("armadura");
    RemoveId("casco");
}

public void init()
{
  (::init());
  add_action("cmd_bandage","vendar");
}
