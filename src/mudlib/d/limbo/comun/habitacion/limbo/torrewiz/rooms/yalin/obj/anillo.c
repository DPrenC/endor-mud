#include "path.h"
#include <properties.h>
#include <materials.h>
#include <combat.h>
#include <moving.h>
#include <sounds.h>
inherit ARMOUR;

object nene, aenv, nenv;

void SetNene(object ob)
{
    nene=ob;
    if (nene) nenv=environment(nene);
    return;
}

object QueryNene() { return nene; }

int CreateNene(string str)
{
    if (!YALIN || environment()!=YALIN || str!="niño") return 0;
    if (nene && living(nene)) 
    {
        dtell("yalin","El nene ya existe.\n");
    }
    else
    {
        object casa, *item, obj;
        if (!casa=find_object(TORRE("rooms/yalin/workroom"))) casa=load_object(TORRE("rooms/yalin/workroom"));
        if ((!item=casa->QueryItems()[0]) || (!obj=item[RITEM_OBJECT]))
        {
            dtell("yalin","Creando al nene.\n");
            obj=clone_object(TORRE("rooms/yalin/obj/ninyo"));
            obj->move(casa);
        }
        else dtell("yalin","Reajustando al nene.\n");
        SetNene(obj);
    }
    dtell("yalin","Nene listo.\n");
    return 1;
}

int BuscarNene(string str)
{
    if ((TP != YALIN) || (str!="niño")) return 0;
    if (!nene)
    {
        dtell("yalin","no hay nenes.\n");
        return 0;
    }
    if (!living(nene))
    {
        dtell("yalin","El niño está muerto.\n");
        return 0;
    }
    dtell("yalin","Nene encontrado.\n");
    if (!environment(nene)) dtell("yalin","No sé dónde está.\n");
    else
    {
        dtell("yalin",environment(nene)->QueryIntShort()+".\n");
        nenv=environment(nene);
    }
    return 1;
}

public int n_traer(string str)
{
    if ((TP != YALIN) || (str!="niño")) return 0;
    if (environment() != YALIN)
    {
        write("Rozas el anillo con los dedos.\nLa piedra comienza a brillar, te hace un guiño "
            "y se apaga.\n");
        say(CAP(TNAME)+" toca el anillo, que se ilumina por un momento, "
        "pero no ocurre nada.\n",TP);
        return 1;
    }
    if (!BuscarNene(str)) CreateNene(str);
    aenv=environment(YALIN);
    tell_room(aenv,"Yalin da unos golpecitos en la piedra del anillo...\nAl momento, una "
        "ligera nube de humo azul surge de ella.\n",({YALIN}));
    if (nenv == aenv)
    {
        write("El niño te dice: Pero cariño, si estoy aquí.\n");
        tell_room(aenv,"El niño mira a Yalin sonriendo y dice: Mi reina, ¿No me ves? Ya estoy "
            "aquí, no necesitabas llamarme.\n",({YALIN}));
        return 1;
    }
    tell_room(nenv,"El niño se yergue de repente, como si hubiera oído algo, y fija su mirada "
        "en la piedra de su anillo, la cuál brilla un momento y se apaga.\nEl niño sonríe "
        "y dice: Tengo que irme, mi reina me llama.\n");
    if (nene->move(aenv, M_TELEPORT))
    {
        write("Tu niño viene a tu encuentro.\n");
        return 1;
    }
    write("algo debe ir mal. Tu niño no viene.\n");
    tell_room(aenv,"Algo va mal, la nube de humo se disuelve sin que ocurra nada.\n",({YALIN}));
    tell_room(nenv,"El niño mueve la cabeza diciendo: ¡Qué raro, no puedo moverme! Algo va mal.\n");
    return 1;
}
           
n_llama(object pl)
{
    dtell("yalin","Tu niño te habla en el anillo: Cariño, "+pl->QueryName()+" te está buscando.\n");
    play_sound(YALIN,SND_SUCESOS("beep"));
    return;
}

reset()
{
    if ((YALIN && environment()==YALIN) && !nene) CreateNene("niño");
}
        
create()
{
    ::create();
    SetStandard(AT_ANILLO,0,P_SIZE_MEDIUM,M_ORO);
    SetShort("un anillo de oro");
    SetLong("Es un grueso anillo de oro. Lleva engarzada una gran amatista, donde se ha "
        "grabado el sello de la reina de las hadas: una varita mágica cruzada con una espada.\n");
    AddId(({"anillo","comunicator"}));
    AddAdjective(({"grueso","de oro"}));
    Set(P_GENDER,GENERO_MASCULINO);
    Set(P_NUMBER,NUMERO_SINGULAR);
    SetWeight(100);
    Set(P_CANT_STEAL,1);
    Set(P_NOSELL,"No podrás venderlo, nadie quiere problemas con los inmortales...\n");
}

init()
{
    ::init();
    add_action("n_traer","llamar");
    add_action("BuscarNene","buscar");
    add_action("CreateNene","crear");
}
    
public varargs int move(mixed dest, int method, mixed extra)
{
	  if (method == M_GET && TP->QueryRealName() != "yalin")
	  {
	      write("Te dispones a cogerlo, pero de pronto recuerdas que jamás has visto a nadie "
    	      "llevar un anillo como ése, sólo a Yalin y su niño. Entonces te llama la atención "
    	      "el grabado de la piedra, y decides no arriesgarte a tener problemas con los dioses.\n");
	      return ME_NO_GET;
	  }
	  return ::move(dest, method, extra);
}
    