/**
 * simauria /obj/oil_bottle.c
*/

#include <properties.h>
#include <search.h>

inherit THING;

private int pFuel, pMaxFuel, pBaseWeight, pFuelWeight;

public int SetFuel(int i)
{
    if (environment()) environment()->AddIntWeight(-((pFuel - i) * pFuelWeight));
    return pFuel = i;
}
public int QueryFuel() { return pFuel; }

public int SetMaxFuel(int i) { return pMaxFuel = i; }
public int QueryMaxFuel() { return pMaxFuel; }

public int SetBaseWeight(int i) { return pBaseWeight = i; }
public int QueryBaseWeight() { return pBaseWeight; }

public int SetFuelWeight(int i) { return pFuelWeight = i; }
public int QueryFuelWeight() { return pFuelWeight; }

public int QueryWeight() { return pBaseWeight + pFuelWeight * pFuel; }

public int SetValue(int i) { return ::SetValue(i); }
public int QueryValue() { return ::QueryValue() + (5 * pFuel); }




public int frefill(string str)
{
    string que, conque;
    mixed result;
    object lampara, botella;
    string lamp_ao, bot_ao, lamp_short, bot_short;

    if (!str || str == "")
    {
        return notify_fail("Rellenar qué con qué?", NOTIFY_ILL_ARG);
    }
    if (sscanf(str, "%s con %s", que, conque) != 2)
    {
        return notify_fail("¿Rellenar qué con qué?", NOTIFY_ILL_ARG);
    }
    if (!result = search(TP, que, SEARCH_INV))
    {
        return notify_fail("No encuentras " + que + " para llenar.\n", NOTIFY_NOT_OBJ);
    }
    lampara = result[0];
    lamp_ao = lampara->Query(P_GENDER) == GENDER_FEMALE ? "a" : "o";
    lamp_short = lampara->QueryShort() || "algo";
    if (!result = search(TP, conque, SEARCH_INV))
    {
        return notify_fail("No encuentras " + conque + " para rellenar " + lamp_short + ".\n", NOTIFY_NOT_OBJ);
    }
    botella = result[0];
    bot_ao = botella->Query(P_GENDER) == GENDER_FEMALE ? "a" : "o";
    bot_short = botella->QueryShort() || "algo";
    if (member(lampara->QueryClassIds(), "lamp") < 0 || !lampara->QueryRechargeable())
    {
        return notify_fail("¡Eso no puedes rellenarlo de aceite!\n", NOTIFY_NOT_VALID);
    }
    if (member(botella->QueryClassIds(), "oil_bottle") < 0)
    {
        return notify_fail("No puedes rellenar " + lamp_short +
                           " con " + bot_short + "!\n", NOTIFY_NOT_VALID);
    }
    if (lampara->QueryFuel() == lampara->QueryFuelMax())
    {
        return notify_fail(CAP(lamp_short) + " ya está completamente llen" +
                           lamp_ao + ".\n", NOTIFY_NOT_VALID);
    }
    if (!botella->QueryFuel())
    {
        return notify_fail(CAP(bot_short) + " está completamente vací" +
                           bot_ao + ".\n", NOTIFY_NOT_VALID);
    }
    if (lampara->QueryFuelMax() - lampara->QueryFuel() > botella->QueryFuel())
    {
        write("Viertes el resto de " + bot_short + " en el interior de " +
              lamp_short + ", pero no consigues llenarl" +
              lamp_ao + " por completo.\n");
        say(CAP(TNAME) + ", vierte el contenido de " + bot_short +
            "en " + lamp_short + ".\n");
        lampara->SetFuel(lampara->QueryFuel() + botella->QueryFuel());
        botella->SetFuel(0);
        return 1;
    }
    write("Viertes aceite en " + 
        lamp_short + " hasta llenarl" + lamp_ao + " por completo.\n");
    say(CAP(TNAME) + " vierte aceite de " + bot_short + " en " + lamp_short + ", hasta llenarl" +
        lamp_ao + " por completo.\n");
    botella->SetFuel(botella->QueryFuel() - (lampara->QueryFuelMax() - lampara->QueryFuel()));
    lampara->SetFuel(lampara->QueryFuelMax());
    return 1;
}

public string QueryLong()
{
    int porc = 100 * QueryFuel() / QueryMaxFuel();
    string bot_ao = Query(P_GENDER) == GENDER_FEMALE ? "a" : "o";
    string long, baselong = ::QueryLong() || "";
    
    if (extern_call()) return baselong;
    switch(porc)
    {
        case 0: long = "Está totalmente vací" + bot_ao; break;
        case 1..10: long = "Solo le quedan algunas gotas de aceite"; break;
        case 11..20: long = "Está casi vací" + bot_ao; break;
        case 21..30: long = "Le queda poco aceite"; break;
        case 31..45: long = "Le queda algo menos de la mitad del aceite."; break;
        case 46..55: long = "Dirías que está más o menos medio llen" + bot_ao; break;
        case 56..70: long = "Aún le queda más de la mitad del aceite"; break;
        case 71..90: long = "Está casi llen" + bot_ao; break;
        case 91..95: long = "Está llena"; break;
        case 96..100: long = "El aceite llega justo hasta el borde"; break;
    }
    return (baselong[<1] == '\n' ? baselong[..<2] : baselong) + " " + long + ".\n";
}



create()
{
    ::create();
    SetShort("una botella de aceite");
    SetLong("Es una botella de cristal, utilizada para transportar aceite. En su parte superior, tiene un "
            "tapón de corcho que se ajusta perfectamente a la boca, para poder transportarla sin "
            "que se derrame su contenido.\n");
    SetIds(({"botella", "botella de aceite", "botella con aceite"}));
    Set(P_GENDER, GENDER_FEMALE);
    SetValue(70);
    SetFuel(100);
    SetMaxFuel(100);
    SetBaseWeight(400);
    SetFuelWeight(40);
    AddClassId("oil_bottle");
}


init()
{
    ::init();
    add_action("frefill", "rellenar");
    add_action("frefill", "llenar");
}

