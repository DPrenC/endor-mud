/*
DESCRIPCION  : En la superficie del lago Darum
FICHERO      : /d/akallab/comun/habitacion/akallab/azzor/gaddaro/lago.c
*/

#include "path.h"
#include <skills.h>
#include AK_MACRO
#include <moving.h>
#include <combat.h>
#include <properties.h>



inherit ROOM;

int ir_puerto(){
  int sk, tp;
  if (TP->QueryStatus() == STATUS_SLEEPING) return 0;

  if ((tp = TP->QueryTP()) <= 0)
  // está muy cansado para nadar al muelle
  {
    return notify_fail("Estás demasiado cansad" + AO + " para nadar hacia "
                       "el muelle.\n");
  }
  // nadamos hacia el muelle.
  // Si la habilidad es muy baja, se hunde y va hacia el fondo.
  sk = TP->UseSkill(HAB_NADAR);
  if (sk < -40)
  // desastroso desastroso
  {
    TP->move(GADDARO("lago_fondo"),M_SPECIAL,
             ({"comienza a nadar hacia el muelle del puerto. Sin embargo, "
             "parece que esto de nadar no se le da demasiado bien, y "
             "braceando y pataleando, ves como finalmente se hunde hacia "
             "las profundidades del lago",
             "llega buceando",
             "Comienzas a nadar hacia el muelle del puerto. Sin embargo, "
             "no consigues mantenerte a flote y por más que braceas y "
             "pataleas, terminas hundiéndote.."}));
    TP->Defend(5 + random(5),DT_NOAIR,
               DEFEND_F_NOLIV | DEFEND_F_NOMSG | DEFEND_NO_DEF_SK);
    return 1;
  }
  if (sk < 0)
  // aún no consigue nadar bien
  {
    TP->move(GADDARO("puerto"),M_SPECIAL,
             ({"intenta nadar hacia el muelle del puerto. A duras penas "
             "parece mantenerse a flote, y en algunos momentos ves como su "
             "cabeza se sumerge en las frías aguas. Finalmente, tosiendo y "
             "jadeando, consigue llegar al borde del muelle e izarse a "
             "tierra firme",
             "llega nadando desde el lago",
             "Intentas nadar hacia el muelle del lago, pero tu "
             "inexperiencia hace que empieces a hundirte irremisiblemente. "
             "Tragando agua y con los pulmones ardiéndote por la falta de "
             "aire, al fin consigues alcanzar el borde del muelle e izarte "
             "a tierra firme"}));
    TP->Defend(5 + random(3),DT_NOAIR,
               DEFEND_F_NOLIV | DEFEND_F_NOMSG | DEFEND_NO_DEF_SK);
    return 1;
  }

  // nada normalmente hacia el muelle
  TP->move(GADDARO("puerto"),M_SPECIAL,
           ({"nada hasta el muelle del puerto",
           "llega nadando desde el lago",
           "Comienzas a nadar hacia el muelle del puerto. Finalmente, alcanzas "
           "el borde y te izas a tierra"}));
  return 1;
}

int lago_fondo(){
  if (TP->QueryStatus() == STATUS_SLEEPING) return 0;
  TP->move(GADDARO("lago_fondo"),M_SPECIAL,
           ({"se sumerge y nada hacia el fondo del lago",
           "llega buceando",
           "Coges aire y te sumerges hacia el fondo del lago"}));
  return 1;
}


create() {
 ::create();
 SetPreIntShort("en medio de");
 SetIntShort("el lago");
 SetIntLong(
 "Te encuentras nadando en la superficie del lago Darum no muy lejos "
   "del muelle del puerto del pueblo de Gaddaro. Las aguas del lago son "
   "aquí cristalinas y poco profundas, por lo que puedes ver la "
   "vegetación que crece en el fondo del mismo.\n");

 AddDetail(({"vegetación","vegetacion","algas"}),"El fondo del lago está cubierto de algas.\n");
 AddDetail(({"muelle"}),"Queda cerca de aquí, hacia el sudeste.\n");
 AddDetail(({"fondo del lago","fondo"}),"Está cubierto de algas.\n");
 AddDetail(({"pueblo","villa","Gaddaro","gaddaro"}),"Es el pueblo que ves al nordeste.\n");
 AddDetail("agua", "El agua esta bastante fría.\n");

 AddDetail(({"lago","darum","Darum","lago Darum"}),
 "Es un lago de tamaño medio formado por el embalse de las aguas del río "
   "Daraii que se halla al noroeste del valle de Azzor. En su orilla este se "
   "encuentra el pueblo de Gaddaro.\n");

 SetIntNoise("Sopla una suave brisa desde el este.\n");
 SetIntSmell("Hueles el fresco aroma del campo.\n");
 SetLocate("valle de Azzor");
 SetIndoors(0);

 AddExit("sudeste",SF(ir_puerto));
 AddExit("abajo",SF(lago_fondo));

 AddRoomCmd("beber", "beber_cmd");
 AddRoomCmd("coger","fcoger");
 AddRoomCmd("dormir","cmd_dormir");
 AddRoomCmd("despertar","cmd_despertar");
 AddRoomCmd("rodar","cmd_rodar");

}


int cmd_rodar(string str)
{
    if (TP->QueryStatus() != STATUS_NORMAL) return 0;
    write("Te tumbas de espaldas en el agua y empiezas a nadar, dando vueltas "
          "como loc" + AO + " mientras te ríes. De tanto reir, te entra agua "
          "en la nariz y comienzas a toser sonoramente.\n");
    say(CAP(TNAME) + " se echa de espaldas al agua y empieza a nadar, dando "
        "vueltas como loc" + AO + " mientras se ríe. De tanto reir, le entra "
        "agua en la nariz y comienza a toser sonoramente.\n");
    return 1;
}


void hundir()
{
    if (!TP ||TP->QueryStatus() == STATUS_SLEEPING) return;
    TP->move(GADDARO("lago_fondo"),M_SPECIAL,
             ({"se hunde léntamente en las aguas del lago",
               "llega",
               "Estás tan relajad" + AO + ", que sin poder evitarlo te hundes "
               "poco a poco.."}));
    write("Te entra agua por la nariz y la boca y te despiertas "
          "sobresaltad" + AO + ".\n");
    TP->SetStatus(STATUS_NORMAL);

}


int cmd_dormir()
{
    if (TP->QueryStatus() == STATUS_SLEEPING)
    {
        while (remove_call_out("hundir") != -1);
    }
    else call_out("hundir",11 + random(10));
    return 0;
}

int cmd_despertar()
{
    if (TP->QueryStatus() == STATUS_SLEEPING)
    {
        while (remove_call_out("hundir") != -1);
    }
    return 0;
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




int fcoger(string str)
{
    object ob, frasco;

    if (str != "agua") return 0;
    if (!(frasco = present("frasco_vacio",TP)))
    {
        write("No tienes nada con qué coger agua.\n");
        return 1;
    }
    if (TP->UseSkill(HAB_NADAR)<10)
    {
        write("Te dispones a coger un poco de agua con el frasco, pero de "
              "repente notas cómo poco a poco vas hundiéndote... En tu "
              "intento de mantenerte a flote, el frasco se te escurre y es "
              "arrastrado por la corriente. Tendrás que aprender a nadar "
              "mejor.\n");
        say(CAP(TNAME) + " intenta coger agua con el frasco, pero ves como "
            "su falta de experiencia le juega una mala pasada y comienza a "
            "hundirse. En un intento por no ahogarse, el frasco se le resbala "
            "y es arrastrado por la corriente.\n");
        frasco->remove();
        return 1;
    }
    write("Con mucho cuidado consigues coger un poco de agua con el frasco "
          "vacío y lo tapas cuidadosamente.\n");
    say(CAP(TNAME) + " consigue llenar un frasco con agua del lago.\n");
    frasco->remove();
    ob = clone_object(OTRO("frasco_agua"));
    if ( ob->move(TP,M_SILENT)!=ME_OK )
    {
        ob->move(environment(TP), M_SILENT);
        write("El frasco se te escurre y se queda flotando a tu lado.\n");
        say("Sin embargo, el frasco se le escurre y queda flotando en el "
              "agua.\n");
    }
    ob->SetOwner(TP->QueryRealName());
    return 1;
}

