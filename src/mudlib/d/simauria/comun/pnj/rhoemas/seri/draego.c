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
            return W("Draego te dice: Muchas gracias por ayudarme, no se qu� habr�a "
            "hecho sin t�.\n");
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
            "algunos d�as me encomendaron la custodia de la "
            "copa favorita de Kaleband que usa en la ceremonia "
            "anual de los peregrinos. La ceremonia se celebrar� "
            "dentro de poco y no la encuentro por ninguna parte. "
            "No se qu� voy a hacer... me degradar�n por esto.\n");

        case "libro": return W("Draego te mira fijamente y dice: Lo he "
            "perdido, lo he perdido. El libro ceremonial de Kaleband, "
            "ya no est�, creo que me lo han robado. Necesito con "
            "urgencia que alguien lo encuentre o al menos uno igual. "
            "��Por favor, ay�dame!!\n");

        case "punyal":	return W("Draego te mira fijamente y dice: Este es "
            "mi fin. El otro dia estaba practicando con el pu�al "
            "ceremonial y se me parti� la hoja en dos. No puedo "
            "llevar este trozo de metal inservible a la m�s prestigiosa "
            "ceremonia de nuestro templo. Si al menos pudiera salir del "
            "templo para encargar uno igual... pero ahora estamos en "
            "periodo de reflexi�n. Necesito que me ayudes.\n");

        case "tunica":	return W("Draego te mira fijamente y dice: Estoy desesperado. "
            "Dej� la t�nica ceremonial entre mis cosas y un aprendiz la "
            "lav� junto con el resto. �La ha hecho jirones!. Pero las "
            "culpas me las llevar� yo por ser el encargado de su seguridad. "
            "Necesito otra t�nica igual. Por favor, cons�guemela.\n");
            break;
    }
    return W("Draego est� demasiado preocupado como para "
             "hacerte caso.\n");
}

public string fcopa(void)
{
  mapping quest=TP->QueryAttribute("DraegoQuest");

  if (QUESTMASTER->QueryQuestSolved("DraegoQuest",TP))
  {
    TP->SetAttribute("DraegoQuest",0);
    return W("Draego te dice: Muchas gracias por ayudarme, no se qu� habr�a "
    "hecho sin t�, no te olvidar� jam�s.\n");
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
    return W("Draego te dice: Muchas gracias por ayudarme, no se qu� habr�a "
    "hecho sin t�, no te olvidar� jam�s.\n");
  }
  if (quest && member(quest,"libro"))
  {
    return W("Draego te dice: �C�mo pude perder el libro m�s sagrado del templo?, "
    "si Kaleband se entera estar� haciendo la colada el resto de mi vida. Por favor, "
    "encu�ntralo, como sea...\n");
  }
  else return "Draego se encoge de hombros.\n";
}

public string fpunyal(void)
{
  mapping quest=TP->QueryAttribute("DraegoQuest");

  if (QUESTMASTER->QueryQuestSolved("DraegoQuest",TP))
  {
    TP->SetAttribute("DraegoQuest",0);
    return W("Draego te dice: Muchas gracias por ayudarme, no se qu� habr�a "
    "hecho sin t�, no te olvidar� jam�s.\n");
  }
  if (quest && member(quest,"punyal"))
  {
    return W("Draego te dice: En qu� mala hora se me ocurri� poner mis "
    "indignas manos sobre el pu�al. Ahora no es m�s que una simple pieza "
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
    return W("Draego te dice: Muchas gracias por ayudarme, no se qu� habr�a "
    "hecho sin t�, no te olvidar� jam�s.\n");
  }
  if (quest && member(quest,"tunica"))
  {
    return W("Draego te dice: No se qu� voy a hacer, este trozo de tela roto y "
    "destintado no puedo d�rselo a Kaleband para la m�s prestigiosa ceremonia "
    "que oficiamos... necesito que alguien me haga una igual, por favor, te lo "
    "pido, ay�dame.\n");
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
  SetGuardDefendMsg("Draego grita uni�ndose al combate:\n �No permitir� que "
    "se mancille el nombre de Saenetia derramando sangre en su morada!\n");
  SetIds(({"maestro","humano","draego","Draego"}));
  SetShort("Draego");
  SetLong(W("Ante ti est� el maestro Draego, mano derecha de Kaleband y uno de sus m�s "
    "firmes sucesores. Tiene un aspecto gentil aunque su mirada refleja gran poder. "
    "Te mira de reojo sin perderte de vista mientras parece que intenta encontrar algo.\n"));
  InitChats(4,({"Draego dice: No es posible, no es posible.\n",
      "Draego dice: El tiempo se me echa encima... pronto ser� la ceremonia.\n",
    "Draego dice: Dios... �qu� va a ser de mi ahora?\n",
    "Draego dice: Tengo que hacer algo.\n",
    "Draego dice: Kaleband se pondr� hecho una fiera...\n",
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
  AddQuestion(({"punyal","pu�al","punyal ceremonial","pu�al ceremonial"}),	SF(fpunyal),1);
  AddQuestion(({"tunica","t�nica","tunica ceremonial","t�nica ceremonial"}),	SF(ftunica),1);

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
          write(W(TC_BOLD+TC_BLUE+"Draego te dice entre l�grimas:	 �Muchas gracias!, no "
          "se qu� hubiera hecho sin t�, te recordar� mientras viva. �D�nde la habr�a puesto?, "
          "no importa, el caso es que me la has tra�do.\n"+TC_NORMAL));
          copa->remove();
          QUESTMASTER->InformSolution("La ceremonia de Seri-Solderteg se podr� oficiar gracias a "+CATP+".\n");
           QUESTMASTER->SetPlayerQuest("DraegoQuest",TP);
           write_file (LOGS "DRAEGO",ctime(time())+"   "+CATP+" ["+TP->QueryLevel()+"] ha encontrado la copa ceremonial.\n");
          TP->SetAttribute("DraegoQuest",0);
          return 1;
        }
        else if (libro && libro->id(que) && quest && member(quest,"libro") && quest["libro",0]==8)
        {
          write(W(TC_BOLD+TC_BLUE+"Draego te dice entre l�grimas:	 �Por Xaenetia!, �lo "
          "has encontrado!, �el libro ceremonial de Kaleband!. Si me doy prisa a�n podr�a "
          "volver a colocarlo en su lugar y Kaleband ni notar� que no ha estado ah� estos "
          "d�as. Gracias "+CATP+", nunca olvidar� este gesto.\n"+TC_NORMAL));
          libro->remove();
          QUESTMASTER->InformSolution("La ceremonia de Seri-Solderteg se podr� oficiar gracias a "+CATP+".\n");
           QUESTMASTER->SetPlayerQuest("DraegoQuest",TP);
           write_file (LOGS "DRAEGO",ctime(time())+"   "+CATP+" ["+TP->QueryLevel()+"] ha encontrado el libro ceremonial.\n");
          TP->SetAttribute("DraegoQuest",0);
          return 1;
        }
        else if (punyal && punyal->id(que) && quest && member(quest,"punyal") && quest["punyal",0]==8)
        {
          write(W(TC_BOLD+TC_BLUE+"Draego te dice asombrado:	 Una aut�ntica obra de arte, me "
          "has traido una maravilla, Kaleband creer� que lo he llevado a pulir y me recompensar� "
          "por esto. Mil gracias peregrin"+AO+", que Xaenetia gu�e tus pasos a partir de ahora."
          "\n"+TC_NORMAL));
          punyal->remove();
          QUESTMASTER->InformSolution("La ceremonia de Seri-Solderteg se podr� oficiar gracias a "+CATP+".\n");
           QUESTMASTER->SetPlayerQuest("DraegoQuest",TP);
           write_file (LOGS "DRAEGO",ctime(time())+"   "+CATP+" ["+TP->QueryLevel()+"] ha encontrado el punyal ceremonial.\n");
          TP->SetAttribute("DraegoQuest",0);
          return 1;
        }
        else if (tunica && tunica->id(que) && quest && member(quest,"tunica") && quest["tunica",0]==13)
        {
          write(W(TC_BOLD+TC_BLUE+"Draego te dice con asombro:	 �Por Xaenetia!, �es igual que "
          "la original!, �c�mo lo has conseguido?, �qui�n te ha hecho una igual?, le dar� todos "
          "los encargos del templo, es un aut�ntico maestro costurero... y a ti... te recordar� "
          "por el resto de mis d�as, ve en paz amig"+AO+".\n"+TC_NORMAL));
          tunica->remove();
          QUESTMASTER->InformSolution("La ceremonia de Seri-Solderteg se podr� oficiar gracias a "+CATP+".\n");
           QUESTMASTER->SetPlayerQuest("DraegoQuest",TP);
           write_file (LOGS "DRAEGO",ctime(time())+"   "+CATP+" ["+TP->QueryLevel()+"] ha encontrado la t�nica ceremonial.\n");
          TP->SetAttribute("DraegoQuest",0);
          return 1;
        }
}
