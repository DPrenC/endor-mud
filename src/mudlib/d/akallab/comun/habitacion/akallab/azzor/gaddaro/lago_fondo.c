/*
DESCRIPCION  : En el fondo del lago Darum
FICHERO      : /d/akallab/comun/habitacion/akallab/azzor/gaddaro/lago_fondo.c
MODIFICACION : 01-03-99 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
#include AK_MACRO
#include <messages.h>
#include <moving.h>
#include <combat.h>
#include <properties.h>




inherit ROOM;

public void notify_enter(mixed from, int method, mixed extra)
{
    ::notify_enter(from, method, extra);
    call_out("apagar_objetos",1);
}

public void init()
{
    ::init();
    if (TP) call_out("ahogar",5);
}








void apagar_objetos()
{
    object ob = TP ||PO;
    foreach(object b : all_inventory(ob))
    {
        if (b->QueryBurning())
        {
            tell_object(ob,b->QueryShort() + " se apaga al contacto con el agua.\n");
            b->SetBurning(0);
        }
    }
}


int asfixiar(object ob)
{
    string *msg;
    if (!ob || !living(ob)) return 0;

    msg =(({"Sientes que te estás ahogando!!!.\n",
           "Sientes que tus pulmones están a punto de estallar!!!\n",
           "No puedes aguantar mas aquí abajo.\n",
           "Te falta el aire, necesitas subir a la superficie!!!\n",
           "Te estas ahogando...\n",
           "Aire, aire! necesitas respirar!!!\n"}));

    tell_object(ob, msg[random(sizeof(msg))]);
    tell_room(TO,({MSG_SEE, CAP(ob->QueryName()) + " pone cara de estar "
                            "ahogándose.\n"}), ({ob}));
    ob->Defend(4,DT_NOAIR,
               DEFEND_F_NOLIV | DEFEND_F_NOMSG | DEFEND_NO_DEF_SK);

    return 1;
}


void ahogar()
{
    object *inv;
    SetDieMsg("#jug# murió ahogad" + AO + " en el lago del puerto de Gaddaro.\n");
    inv = filter(all_inventory(), SF(asfixiar));
    if (sizeof(inv)) call_out("ahogar",5);
    else while (remove_call_out("ahogar") != -1);
}


int superficie()
{
    if (TP->QueryStatus() == STATUS_SLEEPING) return 0;
    TP->move(GADDARO("lago"),M_SPECIAL,
             ({"se impulsa con brazos y piernas y asciende hacia la superficie",
               "asoma la cabeza del agua y respira ansios" + AO,
               "Comienzas a bracear y a patalear hasta que consigues ascender a "
               "la superficie"}));
    return 1;
}


create()
{
 ::create();
 SetIntShort("el fondo del lago");
 SetIntLong("Te encuentras buceando en el fondo del lago Darum. Parece que "
            "aquí el agua es más fría que en la superficie. A tu alrededor "
            "puedes ver gran variedad de algas. Más vale que te "
            "des prisa en hacer lo que sea que haces aquí, si no quieres ahogarte.\n");

 AddDetail(({"vegetacion","algas"}),"El fondo del lago esta cubierto de algas.\n");
 AddDetail("agua", "El agua esta bastante fria.\n");

 AddDetail(({"lago","darum","Darum","lago Darum"}),
 "Es un lago de tamayo medio formado por el embalse de las aguas del río "
   "Daraii que se halla al noroeste del valle de Azzor. En su orilla este se "
   "encuentra el pueblo de Gaddaro.\n");

 SetIntNoise("Oyes multitud de sonidos sordos y extraños.\n");
 SetIntSmell("Tienes la nariz tapada al nadar...\n");
 SetLocate("valle de Azzor");
 SetIndoors(1);
 SetIntBright(30);

 AddExit("arriba",SF(superficie));

 AddRoomCmd("coger", "coger_cmd");
 AddRoomCmd("beber", "beber_cmd");
 AddRoomCmd("rodar","cmd_rodar");

 call_out("ahogar",5);
}


int cmd_rodar(string str)
{
    write("¿Rodar? ¿Te estás ahogando y quieres rodar? Desde luego...\n");
    return 1;
}

int beber_cmd(string str) {
  if (str!="agua") return 0;
  TP->AddDrink(5);
  if (TP->QueryDrink() == TP->QueryMaxDrink())
  {
    return notify_fail("Te es imposible beber más.\n",NOTIFY_NOT_VALID);
  }
  write("Bebes un poco de la fría agua del lago.\n");
  say(TP->QueryName()+" bebe un poco de agua del lago.\n",TP);
  return 1;
}


int coger_cmd(string str)
{
  object ob;
  if (str!="algas") return 0;
  ob=present("algas",TP);
  if (ob)
  {
    return notify_fail("Para que? Ya tienes un puñado.\n",NOTIFY_NOT_VALID);
  }
  write("Arrancas un puñado de las algas que crecen en el fondo del lago.\n");
     tell_room(TO, ({ MSG_SEE, NOMBRE+" arranca un puñado de algas del fondo del "
                               "lago.\n"}), ({ TP }));
  ob=clone_object(QUEST+"curandera/algas");
  if (ob->move(TP) != ME_OK)
  {
      write("Las algas se te escurren.\n");
  }

  return 1;
}
