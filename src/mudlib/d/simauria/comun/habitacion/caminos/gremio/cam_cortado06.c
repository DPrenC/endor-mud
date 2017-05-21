/*   cam_cortado06.c
     Creado por : Nemesis
     Fecha :      06-04-01
     Descripcion: Camino que va hacia el Gremio de psiónicos.
     [Ratwor] Arreglo el sangrado del create, y heredo de su nuevo archivo base.
*/


#include "./path.h"
#include <skills.h>
#include <moving.h>
#include <properties.h>

#define A (TP->QueryGender() == GENDER_FEMALE ? "a" : "")
#define SEGUNDOS_OLVIDO 172800
#define ATR "entrada_psionics"
#define AO (TP->QueryGenderEndString())
#define TRAMPA 30

inherit CAMINOS "/gremio/cam_cortado_base";
public void notify_leave(mixed to, int method, mixed extra)
{
    ::notify_leave(to, method, extra);
    if (!TP) return;
    if (find_call_out("_rastrear") != -1)
    {
        write("Dejas de buscar entre la maleza.\n");
        while (remove_call_out("_rastrear") != -1);
        TP->remove_attribute("rastreando");
    }
}


public void notify_enter(mixed from, int method, mixed extra)
{
    object ob = TP ||PO;
    int tiempo;
    ::notify_enter(from, method, extra);
    if (!ob) return;
    if (!(tiempo = ob->QueryAttribute(ATR))) return;
    tiempo = time() - tiempo;
    if (tiempo >= SEGUNDOS_OLVIDO) ob->RemoveAttribute(ATR);
    else ob->SetAttribute(ATR,time());

}

int ir_noroeste()
{
    if (!TP->QueryAttribute(ATR))
    {
        return notify_fail("No hay salida hacia allí.\n");
    }
    TP->move(BET("psionics/camino07"),M_GO,"noroeste");
    return 1;
}

    int haz_oeste()
{
  return notify_fail("Las rocas te impiden el paso.\n");
}


int cmd_buscar()
{
  int atr;
  if (find_call_out("_rastrear") != -1)
  {
#ifdef TRAMPA
    if ((TP->SetAttribute("rastreando", TP->QueryAttribute("rastreando") + 1)) >= TRAMPA)
    {
        CHANNELMASTER->SendEmote("mud","Simauria ruega a " + CAP(TNAME) + " que "
                                  "quite el pisapapeles del intro y sea un "
                                  "poquito honest" + AO + "");
        TP->RemoveAttribute("rastreando");
        write_file(LOGS "trampas_rastreando",ctime(time()) + ", " + CAP(TNREAL) +
                 " ha intentado hacer trampas rastreando en el camino de "
                 "entrada a los psiónicos.\n");


    }
#endif

    return notify_fail("Aún estás rastreando. Espera a terminar para "
                       "empezar de nuevo.\n",NOTIFY_NOT_VALID);
  }

  write("comienzas a buscar por la maleza...\n");
  say(CAP(TNAME) + " comienza a buscar por la maleza...\n");
  call_out("_rastrear",2 + random(5));
  return 1;
}

int _rastrear()
{
  int atr = TP->QueryAttribute(ATR);
  TP->RemoveAttribute("rastreando");
  if (atr || TP->UseSkill(HAB_RASTREAR)>=25)
  {
    write("¡Vaya! Parece que sí hay un camino oculto entre la maleza que va "
          "hacia el noroeste.\n");
    if (!atr) TP->SetAttribute(ATR,time());
  }
  else
  {
    write("No encuentras nada.\n");
  }
  return 1;
}

create() {
    ::create();
    seteuid(getuid());
    SetIntShort("un lugar lleno de maleza");
    SetIntLong("  Aquí todo avance parece verse cortado por los altos y espesos "
    "matorrales que cierran el paso en todas direcciones, escepto al este donde "
    "comienza un desfiladero que penetra en la ominosa cordillera montañosa que "
    "se alza sobre ti.\n");

    AddDetail(({"montaña", "montañas"}),"El camino está excavado a través de ellas, "
    "pero parece que hacia el oeste y noroeste, a lo lejos, ya se acaban las formaciones"
    " rocosas.\n");
    AddDetail(({"camino","suelo"}),
    "El camino está notablemente cortado por abundancia de vegetación y maleza que te "
    "sobrepasa en altura.\n");
    AddDetail(({"desprendimiento","rocas"}),
        "No parece reciente. Esas rocas debieron caer siglos atrás. Tal vez esa "
        "sea la razón de que el camino parezca tan abandonado.\n");
    AddDetail(({"vegetacion", "vegetación","maleza", "matorrales", "matorral"}),
        (:"La maleza Rodea el camino por todas partes, ya que aquí las montañas se han "
            "separado dejando una amplia zona libre para la vegetación. " +
        (!TP->QueryAttribute(ATR) ? "Te preguntas si no habrá algún camino oculto "
        "entre tan tupida vegetación. En momentos como este, te gustaría ser un" + A +
        " rastreador" + A + " expert" + A + ".\n" : "Como viste anteriormente, un "
        "camino casi oculto se dirige hacia el noroeste.\n"):));
    AddExit("este", "./cam_cortado05");
    AddExit("noroeste",SF(ir_noroeste));
    HideExit("noroeste",1);
    AddExit("oeste",#'haz_oeste);
HideExit("oeste",1);
    AddRoomCmd("rastrear","cmd_buscar");

}
