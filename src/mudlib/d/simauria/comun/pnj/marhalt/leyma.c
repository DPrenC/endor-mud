// leyma.c
//
// [n] Nemesis
// [z] Zomax
//
// Tendera de Nandor. Hasta ahora era "virtual" en la tienda.
// Desde ahora será un pnj como los otros.
//
// Creación: [n] Abr'02
// Modificado: [z] Añado el Defend para que no puedan usar el
//                 truco de la magia como ataque. De paso
//                 traslado el add_action de matar de su tienda
//                 a ella en persona y las acciones que le tocan
//                 no sea que se escape por lo que sea.
//             [n] Zomax: te agradecería encarecidamente que pusieras acentos.
//                 Lo digo más que nada porque últimamente mi hacha rúnica
//                 se aburre bastante... ¿ok?
//             [z] Vale chavalín, oído cocina :) Añado acento a última,
//             [z] Ochee... cambio cositas para que no la puedan acuchillar ni
//                 cortar gargantas los asesinos, por eso que es pnj de quest
//                 "teóricamente" inmortal.
//	       [z] Pongo QueryOwner en la parte del quest del sobrino.
//
// Créditos: Cajun sugirió lo de que no proyecta sombra como
//           'pista' de que tiene conexiones no del todo
//           claras con el 'otro lado'.



#include <living.h>
#include <properties.h>
#include "path.h"
#include <moving.h>
#include <door.h>

inherit NPC;

create()
{
    ::create();
   SetStandard("Leyma","humano",11,GENDER_FEMALE);
    SetShort("Leyma, la tendera");
    SetLong(
        "Leyma es la dueña de la tienda. Es una joven humana que atiende solícita "
        "a los clientes. Sin embargo, hay algo que te llama la atención en ella. "
        "Es como si detrás de su encantadora sonrisa se ocultase algo más.\n");
    AddQuestion(({"bebe","bebé","sobrino","niño","ninyo","problema"}),
        "Leyma solloza: 'Mi sobrino se ha perdido. Mi hermana me matará si no lo "
        "encuentro. \n  Un viajero me ha traido un mensaje del guardabosques del "
        "bosque de Marhalt que dice que ha encontrado a mi sobrino...\n No se porque no "
        "me lo trae, estoy desesperada. Yo no puedo ir a buscarlo, ¿me puedes "
        "ayudar?'.\n",1);
    AddQuestion("guardabosques", "Leyma te dice: No se nada de ese guardabosques"
    ", ni se su nombre ni donde vive, aunque el viajero me ha comentado que su "
    "cabaña está sobre un roble al sur del bosque.\n",1);
    AddQuestion("bosque", "Leyma te dice: es el bosque de Marhalt, está en dirección "
    "sur saliendo de la aldea.\n",1);
    AddId(({"humana", "mujer", "tendera"}));
    Set(P_CANT_LURE,1);
}

init(){
  ::init();

  add_action("matar_","matar");
  add_action("matar_","acuchillar");
  add_action("matar_","cortar");
  add_action("matar_","cegar");
  add_action("fdar","dar");
}

// Lo meto a piñón aquí, porque no me mola andar toqueteando la mudlib.
// Por otro lado, no sé por qué esto se quitó en su momento, con el juego
// que puede dar...

public varargs string ExaLong (string what) {
 return
    W("Fijándote bien, te das cuenta de qué es lo que te llamaba la "
     "atención: Leyma no proyecta sombra de ninguna clase. De repente, "
     "notas que sus ojos se clavan en ti y sientes que te traspasan. "
     "Apartas la mirada y decides largarte en cuanto hayas realizado "
     "tus compras...\n");
}

int matar_(string str)
{
    if (!str || present(str, environment(TP)) != TO) return 0;
    object puerta = environment()->FindDoor("sur");
    int abri_puerta;
    TP->StopAttack();
    TO->StopAttack();
    write("\nLeyma te dice: ¡'¡Pero bueno!! ¿No sabes que no tolero la violencia en mi tienda?'\n");
          say("\nLeyma dice: '¡¡"+TNAME+", si quieres matar a alguien, hazlo en la calle!!'\n",TP);
    if (puerta && puerta->QueryDoorState() == DOOR_CLOSED)
    {
        abri_puerta = 1;
        if (!command_me("abrir sur")) puerta->SetDoorState(DOOR_OPENED);
    }
    write("Leyma te agarra y te pega tal patada que sales rodando a la calle.\n");
    say("Leyma agarra a "+TNAME+" y le echa de la tienda de un puntapié.\n",TP);
    tell_room("/d/simauria/comun/habitacion/marhalt/nandor/calle2",TNAME+" sale "
           "rodando de la tienda mientras la enfadada Leyma\nsigue gritando no se sabe qué...\n");
    TP->move("/d/simauria/comun/habitacion/marhalt/nandor/calle2", M_SILENT);
    TP->LookAfterMove();
    if (abri_puerta) call_out("cierro_puerta", 4);
    return 1;
}

public varargs int Defend(int dam, int dam_type, mixed flags, string *xtras)
{
    if (TP) matar_("leyma");
    return 0;
}

public void cierro_puerta() { command_me("cerrar sur"); }


int fdar(string str)
{
    object dinero,sob;

    if (!str) return 0;
    str=lower_case(str);
    if (str=="bebe a leyma" || str=="bebé a leyma" || str=="niño a leyma" || str=="sobrino a leyma")
    {
        if (sob=present("sobrino de leyma",TP))
        {
            if (living(sob))
            {
                if (TP->QueryAttribute("Alimentar_sobrino_Leyma") && sob->QueryOwner() && sob->QueryOwner()==TP->QueryRealName())
                {
                    sob->remove();
                    write(W("Leyma dice: 'Muchas gracias, al final mi "
                        "hermana no acabará con mi vida, te debo un "
                        "gran favor. Toma este obsequio por haberme "
                        "ayudado.'\n"));
                    say(W(TP->QueryName()+" le devuelve su sobrino a "
                    "Leyma, que le recompensa feliz.\n"),TP);
                    dinero=clone_object("/obj/money");
                    dinero->AdjustMoney(1,"mithril");
                    dinero->move(TP,M_SILENT);
                    write("Leyma te da algo de dinero.\n");
                    TP->RemoveAttribute("Alimentar_sobrino_Leyma");
                    QUESTMASTER->SetPlayerQuest("Sobrino_Leyma",TP);
                    QUESTMASTER->InformSolution("¡¡Leyma ha encontrado a su sobrino gracias a "+
                        CAP(TP->QueryName())+"!!\n");
                    tell_object(TP,"¡Felicidades, has resuelto el quest del Sobrino de Leyma!\n");
                    write_file(LOGS "SOBRINO",ctime(time())+" "+TP->QueryRealName()+" ["+
                    TP->QueryLevel()+"] ha encontrado al sobrino de leyma.\n");
                    return 1;
                }
                else
                {
                    sob->remove();
                    write("Leyma dice: 'Gracias por traerme a mi sobrino...' "
                    "\nEl sobrino de Leyma se escapa gateando más rápido de "
                    "lo que tus ojos pueden creer...\nLeyma dice: '¡Otra vez no! "
                    "¡Mi hermana me matará!, ¡Seguro que no te cercioraste "
                    "de que había comido bien!... ¿Le diste personalmente "
                    "de comer?'\n");
                    say(TP->QueryName()+" le devuelve su sobrino a "
                    "Leyma, pero justo antes se le escapa de entre las "
                    "manos y vuelve a irse gateando como una flecha.\n",TP);
                    return 1;
                }
            }
            else
            {
                sob->remove();
                write("Leyma coge el cadáver de su pequeño sobrino entre "
                "sus brazos y tras derramar una pequeña lágrima levanta su "
                "mirada furiosa contra ti mientras grita: '¡ASESINO!'\nRápidamente "
                "te coge un mechón de pelo y lo coloca en un pequeño muñeco "
                "al que clava vilmente infinidad de agujas. Sientes cómo "
                "algo se retuerce en tu interior.\n");
                say(TP->QueryName()+" le muestra con cierto recochineo "
                "el cadáver del sobrino de Leyma a ésta, que tras coger un "
                "mechón de su pelo y atarlo a un pequeño muñeco se dedica a "
                "clavarle infinidad de agujas mientras que "+TP->QueryName()+" "
                "se retuerce de dolor.\n",TP);
                TP->SetFood(0);
                TP->SetDrink(0);
                TP->SetHP(1);
                TP->SetSP(1);
                TP->SetCon(TP->QueryCon()-2);
                TP->SetStr(TP->QueryStr()-2);
                TP->SetDex(TP->QueryDex()-2);
                TP->SetInt(TP->QueryInt()-2);
                return 1;
            }
        }
        else return 0;
    }
    return 0;
}
