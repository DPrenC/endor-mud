/* Archivo        cementerio02.c
   Autor:         Yalin y Lug
   Fecha:         08/05/2006
   Descripción:   Cementerio de la aldea (proyecto)
*/

#include "path.h"
#include <skills.h>
#include <moving.h>
#include <properties.h>

#define SEGUNDOS_OLVIDO 172800
#define ATR "tumba_sherek"

inherit SHERALD("abroom");

public void notify_leave(mixed to, int method, mixed extra)
{
    ::notify_leave(to, method, extra);
    if (!TP) return;
    if (find_call_out("_rastrear") != -1)
    {
        write("Dejas de inspeccionar el suelo.\n");
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

int ir_abajo()
{
    if (!TP->QueryAttribute(ATR))
    {
        return notify_fail("No hay salida hacia allí.\n",NOTIFY_NOT_VALID);
    }
    TP->SetFollowers(0);
    TP->move(SHERALD("cementerio/tumba"),M_GO,"abajo");
    return 1;
}

int cmd_buscar()
{
  int atr;
  if (find_call_out("_rastrear") != -1)
  {
    return notify_fail("Aún estás rastreando. Espera a terminar para "
        "empezar de nuevo.\n",NOTIFY_NOT_VALID);
    }
    write("comienzas a inspeccionar con atención por todas partes...\n");
    say(CAP(TNAME) + " comienza a inspeccionar detenidamente el entorno...\n");
    call_out("_rastrear",2 + d4());
    return 1;
}

int _rastrear()
{
    int atr = TP->QueryAttribute(ATR);
    TP->RemoveAttribute("rastreando");
    if (atr || (TP->UseSkill(HAB_RASTREAR)>=0 && d10() == 1))
    {
        write("¡Vaya! Pues resulta que había un agujero hacia abajo...\n");
        if (!atr) TP->SetAttribute(ATR,time());
    }
    else write("No encuentras nada.\n");
    return 1;
}

create()
{
    ::create();
    SetIntShort("el este del cementerio de la aldea");
    SetIntLong("Estás sobre la parte este del cementerio de la aldea de "
        "Sloch. Este lugar está mucho más descuidado que el resto, las "
        "malezas y arbustos lo invaden todo impidiendo que las cosas que "
        "puedan estar bajo ellos se vean con claridad. No obstante, en "
        "algunos lugares se vislumbran algunas lápidas en bastante mál "
        "estado, y también hay algunos cascotes y desperdicios amontonados "
        "en algunos lugares.\n Hacia el oeste puedes ver la parte central "
        "del cementerio y hacia el noroeste ves dos grandes cipreses.\n");
    SetIntSmell("Hmmmmmm ..., parece que huele a podrido. ¡Apesta aquí!\n");
    SetIntNoise("¡No se escucha nada!, la quietud aquí es impresionante y "
        "absoluta.\n");
    AddDetail(({"maleza", "malezas", "arbustos"}), "Son malas hierbas que "
        "invaden toda esta parte del cementerio, lo que te da a entender que "
        "poca gente se aventura por aquí.\n");
    AddDetail(({"suelo"}), "casi no lo puedes ver, la maleza y los "
        "desperdicios lo ocupan casi todo.\n Si quisieras ver algo tendrías "
        "que registrar todo esto palmo a palmo, aunque quizás tampoco "
        "valiese la pena..., o quizá sí... ¡Tú mismo!\n.");
    AddDetail(({"cascotes", "desperdicios"}), "Ves piedras, pedazos de "
        "lápidas y... hmmm.... ¡Partes de esqueletos!\n");
    AddDetail(({"esqueleto", "esqueletos", "huesos", "hueso", "partes de esqueletos"}),
        "Son huesos bastante deteriorados, se supone que de los muertos que "
        "algún día yacieron en las tumbas de esta parte del cementerio.\n");
    AddDetail(({"piedras", "piedra", "pedazos", "pedazos de lapidas", "pedazos de lápidas"}),
        "se trata de piedras arrancadas de alguna construcción y trozos de "
        "lápidas muy deteriorados.\n");
    AddDetail(({"lapida", "lapidas", "lápida", "lápidas"}), "Las lápidas que "
        "logras ver a través de la vegetación parecen estar en muy mal "
        "estado, desgastadas y rotas. Sin duda maltratadas por las "
        "inclemencias del tiempo y por el abandono.\n");
    AddDetail(({"noroeste", "cipres", "ciprés", "cipreses"}), "son dos "
        "grandes árboles que nacen a ambos lados de la entrada del "
        "cementerio, cuya sombra lo alcanza casi todo.\n");
    AddDetail(({"oeste"}), "Puedes ver la parte central con sus hileras de "
        "tumbas y, más lejos, dos panteones.\n");
    AddExit("oeste", SHERALD("cementerio/cementerio00"));
    AddExit("abajo",SF(ir_abajo));
    HideExit("abajo",1);
    AddRoomCmd("registrar","cmd_buscar");
    AddRoomCmd("rastrear","cmd_buscar");
}
