/* SIMAURIA '/obj/candle.c'
==========================
*/

#include <config.h>
#include <combat.h>
#include <messages.h>
#include <lamp.h>
#include <properties.h>
#include <nightday.h>
#include <combat.h>

inherit "/std/lamp";

#define THIS TO

#define SUBID  (to_string(TO)+":subid")



/*----------------------------------------------------------------------------
** Initialize us
*/

create(){
    lamp::create();
    SetRechargeable(0); // no se puede rellenar.
    AddId (({"vela"}));
    SetShort("una vela");
    SetLong("Se trata de un tosco cilindro de cera, con un pabilo en su centro para poder encenderla.\n");
    SetWeights (4, 7);
    Set(P_GENDER, GENDER_FEMALE);

    SetValues (0, 5);              /* Base is worth 1, one unit 1 */
    SetFuelAmount (15+random(6));  /* 15..20 units a 5 minutes */
    SetBrightness (REL_STATE(ND_DAWN, MAX_SUNBRIGHT));
    SetLampMsg ( ({
        "La vela ya esta encendida.\n"
            ,"La vela no esta encendida.\n"
            ,"Con el trozo de vela que te queda, como intentes encenderla lo que vas a conseguir es quemarte los dedos.\n"
            ,"Acercas @@Lighter@@ al pabilo de la vela. Con unos golpecitos, consigues "
            "hacer saltar unas chispas que lo encienden rapidamente.\n"
            ,"@@Pl_Name@@ acerca @@Lighter@@ al pabilo de la vela. Tras golpearlo repetidamente, consigue "
            "hacer saltar una chispa, que prende en la mecha, encendiéndola.\n"
            ,"Soplas sobre la vela, apagándola.\n"
            ,"@@Pl_Name@@ sopla sobre una vela, apagándola.\n"
            ,"El pequeño trocito de vela que te queda te alcanza los dedos, quemándote. Rápidamente soplas para apagarla.\n"
            ,"@@Pl_Name@@ sopla el minúsculo trozo de vela que le quedaba, apagándola.\n",
            "No tienes nada con lo que encender la vela.\n",
            "Acercas @@Lighter@@ al pabilo de la vela, pero por más que intentas producir "
            "una chispa para encenderla, no lo consigues.\n",
            "@@Pl_Name@@ acerca @@Lighter@@ al pabilo de su vela, pero por más que intenta producir "
            "una chispa para encenderla, no lo consigue.\n"

    }));
}


mixed QueryNoBuy() { return QueryBurning(); }

/*----------------------------------------------------------------------------
** Description, Smell, Noise
*/

public string QueryShort()
{
    string sh;

    sh = ::QueryShort();
    if (extern_call()) return sh;
    if (QueryBurning()) sh = strip_article(sh)+" encendida";
    return sh;
}

public string QueryLong()
{
    string rc;
    int fuel, maxfuel;

    fuel = QueryFuel();
    maxfuel = QueryFuelMax();
    rc = ::QueryLong();
    if (extern_call()) return rc;

    if (QueryBurning())
    {
        if (rc[<1] == '\n') rc = rc[..<2];
        rc += " De su extremo superior, brota una pequeña llama que proporciona algo de luz a tu alrededor.\n";
    }

    if (fuel == maxfuel) rc += "Está practicamente nueva.\n";
    else if (fuel * 4 > maxfuel * 3) rc += "Apenas está gastada.\n";
    else if (fuel * 2 > maxfuel) rc += "Aproximadamente queda la mitad.\n";
    else if (fuel * 4 > maxfuel) rc += "Sólo queda un trocito de vela.\n";
    else if (fuel) rc += "Se acabará en cualquier momento.\n";
    else rc = "Se trata de un minúsculo trozo de cera, de lo que antes pudo ser una vela.\n";
    return rc;
}

public int SetFuel (int v) {
    int rc, old;
    old = QueryFuel();
    rc = ::SetFuel(v);
    if (rc <= 0 && old > 0)
    {
        SetShort("un minúsculo trozo de vela");
        AddId(({"trocillo de vela", "trocito de vela", "cera", "trocito de cera", "trocillo de cera", "trozo de cera", "trozo de vela", "trocillo de vela", "trocito de vela"}));
    }
    else if (rc > 0 && old < 0) RemoveId(({"trocillo de vela", "trocito de vela", "cera", "trocito de cera", "trocillo de cera", "trozo de cera"}));
    return rc;
}

public string QuerySmell() {
    int fuel, maxfuel;

    fuel = QueryFuel();
    maxfuel = QueryFuelMax();
    if (QueryBurning()) return "Huele a cera caliente, y al característico olor del pabilo ardiendo.\n";
    return "Huele a cera.\n";
}

public string QueryNoise() {
    if (QueryBurning()) return "Te acercas la vela a la oreja y estás apunto de quemarte. Quizá no haya sido buena idea escuchar como arde una vela.\n";
    return "No escuchas nada.\n";
}

public int BurnUp() {
    string msg, msge;
    object env, pl;
    int rc;

    if (!(rc=::BurnUp()))
    {
        TP->Defend(3, DT_FIRE, DEFEND_F_NOLIV | DEFEND_NO_DEF_SK | DEFEND_NOMSG);
        return rc;
    }
    switch(random(8))
    {
        case 0: msg  = "La llama de la vela oscila levemente.\n";
            msge = "La vela de "+Pl_Name()+" oscila levemente.\n";
            break;
        case 1: msg = "Una gota de cera quema tu mano.\n";
            msge = "";
            break;
        case 2:
            if (all_environment()[<1]->QueryIndoors())
            {
                msg = "Una ráfaga de viento hace que la vela esté a punto de apagarse.\n";
                msge = "Una ráfaga de viento hace que la vela de " + Pl_Name() + " esté a punto de apagarse.\n";
            }
            else
            {
                msg = "La llama de la vela parece hacerse más intensa por un momento.\n";
                msge = "La llama de " + Pl_Name() + " parece hacerse más fuerte por un instante.\n";
            }
            break;
        default: return 1;
    }
    pl = 0;
    if ((env=environment(THIS)) && interactive(env)) {
        pl = env;
        tell_object (pl, msg);
        env = environment(pl);
    }
    if (env && sizeof(msge)) tell_room (env, ({MSG_SEE, msge}), ({ pl }));
    
    return rc;
}

