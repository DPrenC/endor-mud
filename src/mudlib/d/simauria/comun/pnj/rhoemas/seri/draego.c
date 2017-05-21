/***************************************************************************************
 ARCHIVO:	draego.c
 AUTOR:		[z] Zomax
 FECHA:		14-02-2004
 COMENTARIOS:	Draego, maestro de Seri-Solderteg.
 MODIFICACION:	20-04-2003 Ahora es SpellMonster.
            11-05-2003 Bajo su nivel.
            12-06-2003 Bajo HP y SP al Standard.
            12-06-2003 [Nyh] Retoco muchas cosas
 ***************************************************************************************/

#include "path.h"
#include <gremios.h>
#include <properties.h>
#include <colours.h>

inherit RHOEPNJ("seri/superior_base");
inherit GUARD;

public string fquest(void){
    if (QUESTMASTER->QueryQuestSolved("DraegoQuest",TP)){
            TP->SetAttribute("DraegoQuest",0);
            return W("Draego te dice: Muchas gracias por ayudarme, no se qué habría "
            "hecho sin tí.\n");
    }
    if (!TP->QueryAttribute("DraegoQuest") || !mappingp(TP->QueryAttribute("DraegoQuest"))){
        switch(random(30)) {
                case 0..9: TP->SetAttribute("DraegoQuest",(["copa":	0]));  break;
                case 10..19: TP->SetAttribute("DraegoQuest",(["libro":	0]));  break;
                //case 2: TP->SetAttribute("DraegoQuest",(["punyal":0]));  break;
                default:TP->SetAttribute("DraegoQuest",(["tunica":0]));  break;
        }
    }
    switch(m_indices(TP->QueryAttribute("DraegoQuest"))[0]) {
        case "copa": return W("Draego te mira fijamente y dice: Hace "
            "algunos días me encomendaron la custodia de la "
            "copa favorita de Kaleband que usa en la ceremonia "
            "anual de los peregrinos. La ceremonia se celebrará "
            "dentro de poco y no la encuentro por ninguna parte. "
            "No se qué voy a hacer... me degradarán por esto.\n");

        case "libro": return W("Draego te mira fijamente y dice: Lo he "
            "perdido, lo he perdido. El libro ceremonial de Kaleband, "
            "ya no está, creo que me lo han robado. Necesito con "
            "urgencia que alguien lo encuentre o al menos uno igual. "
            "¡¡Por favor, ayúdame!!\n");

        case "punyal":	return W("Draego te mira fijamente y dice: Este es "
            "mi fin. El otro dia estaba practicando con el puñal "
            "ceremonial y se me partió la hoja en dos. No puedo "
            "llevar este trozo de metal inservible a la más prestigiosa "
            "ceremonia de nuestro templo. Si al menos pudiera salir del "
            "templo para encargar uno igual... pero ahora estamos en "
            "periodo de reflexión. Necesito que me ayudes.\n");

        case "tunica":	return W("Draego te mira fijamente y dice: Estoy desesperado. "
            "Dejé la túnica ceremonial entre mis cosas y un aprendiz la "
            "lavó junto con el resto. ¡La ha hecho jirones!. Pero las "
            "culpas me las llevaré yo por ser el encargado de su seguridad. "
            "Necesito otra túnica igual. Por favor, consíguemela.\n");
            break;
    }
    return W("Draego está demasiado preocupado como para "
             "hacerte caso.\n");
}

public string fcopa(void)
{
  mapping quest=TP->QueryAttribute("DraegoQuest");

  if (QUESTMASTER->QueryQuestSolved("DraegoQuest",TP))
  {
    TP->SetAttribute("DraegoQuest",0);
    return W("Draego te dice: Muchas gracias por ayudarme, no se qué habría "
    "hecho sin tí, no te olvidaré jamás.\n");
  }
  if (quest && member(quest,"copa"))
  {
    return W("Draego te dice: Como te dije antes he perdido la copa que "
    "usa Kaleband en la ceremonia anual de los peregrinos, por favor no malgastes "
    "el poco tiempo que me queda para encontrarla.\n");
  }
  else return "Draego se encoge de hombros.\n";
}

public string flibro(void)
{
  mapping quest=TP->QueryAttribute("DraegoQuest");

  if (QUESTMASTER->QueryQuestSolved("DraegoQuest",TP))
  {
    TP->SetAttribute("DraegoQuest",0);
    return W("Draego te dice: Muchas gracias por ayudarme, no se qué habría "
    "hecho sin tí, no te olvidaré jamás.\n");
  }
  if (quest && member(quest,"libro"))
  {
    return W("Draego te dice: ¿Cómo pude perder el libro más sagrado del templo?, "
    "si Kaleband se entera estaré haciendo la colada el resto de mi vida. Por favor, "
    "encuéntralo, como sea...\n");
  }
  else return "Draego se encoge de hombros.\n";
}

public string fpunyal(void)
{
  mapping quest=TP->QueryAttribute("DraegoQuest");

  if (QUESTMASTER->QueryQuestSolved("DraegoQuest",TP))
  {
    TP->SetAttribute("DraegoQuest",0);
    return W("Draego te dice: Muchas gracias por ayudarme, no se qué habría "
    "hecho sin tí, no te olvidaré jamás.\n");
  }
  if (quest && member(quest,"punyal"))
  {
    return W("Draego te dice: En qué mala hora se me ocurrió poner mis "
    "indignas manos sobre el puñal. Ahora no es más que una simple pieza "
    "de metal inservible, necesito que me consigas uno igual, que alguien "
    "te lo forje.\n");
  }
  else return "Draego se encoge de hombros.\n";
}

public string ftunica(void)
{
  mapping quest=TP->QueryAttribute("DraegoQuest");

  if (QUESTMASTER->QueryQuestSolved("DraegoQuest",TP))
  {
    TP->SetAttribute("DraegoQuest",0);
    return W("Draego te dice: Muchas gracias por ayudarme, no se qué habría "
    "hecho sin tí, no te olvidaré jamás.\n");
  }
  if (quest && member(quest,"tunica"))
  {
    return W("Draego te dice: No se qué voy a hacer, este trozo de tela roto y "
    "destintado no puedo dárselo a Kaleband para la más prestigiosa ceremonia "
    "que oficiamos... necesito que alguien me haga una igual, por favor, te lo "
    "pido, ayúdame.\n");
  }
  else return "Draego se encoge de hombros.\n";
}

create(){
  "*"::create();

  SetStandard("Draego","humano",([GC_EXPERTO: 35]),GENERO_MASCULINO);
  SetAlign(0);
  SetWhimpy(0);
  SetGoChance(0);
  SetAggressive(0);
  SetCitizenship("seri");
  SetGuardDefendMsg("Draego grita uniéndose al combate:\n ¡No permitiré que "
    "se mancille el nombre de Saenetia derramando sangre en su morada!\n");
  SetIds(({"maestro","humano","draego","Draego"}));
  SetShort("Draego");
  SetLong(W("Ante ti está el maestro Draego, mano derecha de Kaleband y uno de sus más "
    "firmes sucesores. Tiene un aspecto gentil aunque su mirada refleja gran poder. "
    "Te mira de reojo sin perderte de vista mientras parece que intenta encontrar algo.\n"));
  InitChats(4,({"Draego dice: No es posible, no es posible.\n",
      "Draego dice: El tiempo se me echa encima... pronto será la ceremonia.\n",
    "Draego dice: Dios... ¿qué va a ser de mi ahora?\n",
    "Draego dice: Tengo que hacer algo.\n",
    "Draego dice: Kaleband se pondrá hecho una fiera...\n",
    "Draego suspira.\n"}));
/* [Nyh] menuda burrada!!!
  AddDefence(DT_BLUDGEON,   25);
  AddDefence(DT_PIERCE,   25);
  AddDefence(DT_SLASH,     25);
  AddDefence(DT_MAGIC,    25);
  AddDefence(DT_FIRE,     25);
*/
  GiveSuperiorSpells();

  AddQuestion(({"problema","quest","ceremonia"}),	SF(fquest),1);
  AddQuestion(({"copa","copa ceremonial"}),	SF(fcopa),1);
  AddQuestion(({"libro","libro ceremonial"}),	SF(flibro),1);
  AddQuestion(({"punyal","puñal","punyal ceremonial","puñal ceremonial"}),	SF(fpunyal),1);
  AddQuestion(({"tunica","túnica","tunica ceremonial","túnica ceremonial"}),	SF(ftunica),1);

  if (!random(3)) AddItem(RHOEVAR("seri/llave_cylin"),REFRESH_REMOVE);
  AddItem(RHOEARM("seri/maestro/sandalias"),REFRESH_REMOVE,	SF(wearme));
  AddItem(RHOEARM("seri/maestro/tunica"),REFRESH_REMOVE,	SF(wearme));
}

init(){
  ::init();

  add_action("fdar","dar");
}

public int fdar(string str)
{
  string que, quien;
  object copa=present("copa ceremonial",TP);
  object libro=present("libro ceremonial",TP);
  object tunica=present("tunica ceremonial",TP);
  object punyal=present("punyal ceremonial",TP);
  object draego=TO;
  mapping quest=TP->QueryAttribute("DraegoQuest");

  if (!str) return 0;
  else lower_case(str);

  if (sscanf(str,"%s a %s", que, quien) != 2) return 0;
  if (!draego || !living(draego) || !draego->id(quien)) return 0;
  if (copa && copa->id(que) && quest && member(quest,"copa") && quest["copa",0]==7)
        {
          write(W(TC_BOLD+TC_BLUE+"Draego te dice entre lágrimas:	 ¡Muchas gracias!, no "
          "se qué hubiera hecho sin tí, te recordaré mientras viva. ¿Dónde la habría puesto?, "
          "no importa, el caso es que me la has traído.\n"+TC_NORMAL));
          copa->remove();
          QUESTMASTER->InformSolution("La ceremonia de Seri-Solderteg se podrá oficiar gracias a "+CATP+".\n");
           QUESTMASTER->SetPlayerQuest("DraegoQuest",TP);
           write_file (LOGS "DRAEGO",ctime(time())+"   "+CATP+" ["+TP->QueryLevel()+"] ha encontrado la copa ceremonial.\n");
          TP->SetAttribute("DraegoQuest",0);
          return 1;
        }
        else if (libro && libro->id(que) && quest && member(quest,"libro") && quest["libro",0]==8)
        {
          write(W(TC_BOLD+TC_BLUE+"Draego te dice entre lágrimas:	 ¡Por Xaenetia!, ¡lo "
          "has encontrado!, ¡el libro ceremonial de Kaleband!. Si me doy prisa aún podría "
          "volver a colocarlo en su lugar y Kaleband ni notará que no ha estado ahí estos "
          "días. Gracias "+CATP+", nunca olvidaré este gesto.\n"+TC_NORMAL));
          libro->remove();
          QUESTMASTER->InformSolution("La ceremonia de Seri-Solderteg se podrá oficiar gracias a "+CATP+".\n");
           QUESTMASTER->SetPlayerQuest("DraegoQuest",TP);
           write_file (LOGS "DRAEGO",ctime(time())+"   "+CATP+" ["+TP->QueryLevel()+"] ha encontrado el libro ceremonial.\n");
          TP->SetAttribute("DraegoQuest",0);
          return 1;
        }
        else if (punyal && punyal->id(que) && quest && member(quest,"punyal") && quest["punyal",0]==8)
        {
          write(W(TC_BOLD+TC_BLUE+"Draego te dice asombrado:	 Una auténtica obra de arte, me "
          "has traido una maravilla, Kaleband creerá que lo he llevado a pulir y me recompensará "
          "por esto. Mil gracias peregrin"+AO+", que Xaenetia guíe tus pasos a partir de ahora."
          "\n"+TC_NORMAL));
          punyal->remove();
          QUESTMASTER->InformSolution("La ceremonia de Seri-Solderteg se podrá oficiar gracias a "+CATP+".\n");
           QUESTMASTER->SetPlayerQuest("DraegoQuest",TP);
           write_file (LOGS "DRAEGO",ctime(time())+"   "+CATP+" ["+TP->QueryLevel()+"] ha encontrado el punyal ceremonial.\n");
          TP->SetAttribute("DraegoQuest",0);
          return 1;
        }
        else if (tunica && tunica->id(que) && quest && member(quest,"tunica") && quest["tunica",0]==13)
        {
          write(W(TC_BOLD+TC_BLUE+"Draego te dice con asombro:	 ¡Por Xaenetia!, ¡es igual que "
          "la original!, ¿cómo lo has conseguido?, ¿quién te ha hecho una igual?, le daré todos "
          "los encargos del templo, es un auténtico maestro costurero... y a ti... te recordaré "
          "por el resto de mis días, ve en paz amig"+AO+".\n"+TC_NORMAL));
          tunica->remove();
          QUESTMASTER->InformSolution("La ceremonia de Seri-Solderteg se podrá oficiar gracias a "+CATP+".\n");
           QUESTMASTER->SetPlayerQuest("DraegoQuest",TP);
           write_file (LOGS "DRAEGO",ctime(time())+"   "+CATP+" ["+TP->QueryLevel()+"] ha encontrado la túnica ceremonial.\n");
          TP->SetAttribute("DraegoQuest",0);
          return 1;
        }
}
