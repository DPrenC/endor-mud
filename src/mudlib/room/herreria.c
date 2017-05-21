/* SIMAURIA '/room/herreria.c'
   ===========================
   [w] Woo@simauria
   [n] Nemesis@simauria
   [t] Tagoras@simauria

   08-10-98 [w] La herreria es una tienda especial que ademas ofrece
                servicios para reparar y cambiar el tamanyo a armas
                y armaduras.
   13-10-98 [n] Inicia la traduccion.
   25-01-99 [w] Cambia los textos al castellano y ahora el herrero ya
                puede modificar armas a tamaño HUGE. GetResizePrice
                ahora también te cobra si la hace enorme.
                Aumentado el nivel del herrero estandar, ya que antes
                no funcionaba muy bien y tenia nivel 0 :)
                Quitado lo de 'comprar realmente' etc.. puesto que en
                Simauria no hay distintas monedas.
   11-03-99 [w] Cambiado SK_REPAIR por HAB_REPARAR.
   16-03-99 [t] Quito en la ayuda la referencia a las WIZFUNS
   18-04-99 [w] Ahora, siempre y cuando esté bastante dañada el arma o
                armadura, decrementa en 20 el ResetQuality. A partir de
                estos instantes van a saber los jugadores lo que es
                tener que cambiar de armas a menudo :) De paso he cambiado
                un for que habia por ahí suelto.
   20-04-99 [w] Implementada la especialización de las herrerias, es decir,
                solo puede arreglar objetos de materiales determinados.
                Si no se determina ninguno arreglaran todos.
   08-11-99 [w] Ahora además de decrementar el tamaño decrementa el peso.
   02-12-99 [w] Modificado algun que otro texto y puesto que tambien
                se pueda tratar con QuerySpecialWeapon().
   23-11-00 [n] A petición de Kintups (aunque el no lo sepa) retocada
                para que sea un poco más caro cambiar el tamaño. Además,
                un cambio de tamaño supone una reducción de la calidad
                del arma en 5 puntos.
   01-12-00 [n] Retocada la castellanización.
   22-11-01 [n] Menos mal que nadie la usa... Había un bug del tamaño de
                un tren expreso: si ponías SetWeaponDecay(), cada vez que
                se reparaba el arma, el WPperQP (o dureza) aumentaba,
                por lo que el arma cada vez era mejor. Pasaba lo mismo
                con el ArmourDecay...
   07-03-09 [t] Arreglo los factores multiplicativos del do_resize para
                que sean simétricos peso * reducir * agrandar = peso
*/

//----------------------------------------------------------------------------

#include <config.h>
#include <money.h>
#include <properties.h>
#include <rooms.h>
#include <skills.h>
#include <wizlevels.h>
#include <materials.h>

//----------------------------------------------------------------------------

inherit SHOP;

//----------------------------------------------------------------------------

#define LSF(x) symbol_function(x,TO)
#define SHOPKEEPER_ID "Soy el tendero"

//----------------------------------------------------------------------------

private static string Pverb_fix;
private static string Pverb_resize;

private static int     Psmithy;
private static int     Pno_shop;
private static int     Prepair_factor;
private static int     Presize_factor;
private static int     Pmax_repair;
private static int     Pmax_quality;
private static int     Pweapon_decay;
private static int     Parmour_decay;
private static mixed  *PFixMaterial;

//----------------------------------------------------------------------------

int SetNoShop(int i)
{
    if (i)
        RemoveExit("almacen");
    else
        SetStore();
    return Pno_shop=i;
}

int QueryNoShop() { return Pno_shop; }

string SetFix(string verb) { return Pverb_fix=verb; }
string QueryFix() { return Pverb_fix; }

mixed *QueryFixMaterial()
{
 return PFixMaterial || ({});
}

mixed *SetFixMaterial(mixed *material)
{
 int i;
 string mat;

 if (!material) return PFixMaterial=({});
 PFixMaterial = ({});
 if (pointerp(material))

  for(i=0;i<sizeof(material);i++)
  {
   if( intp( material[i] ) )
      if( mat=M_MAPPING[material[i]] )
      {
         if (member(PFixMaterial,mat) == -1)
          PFixMaterial += ({ mat });
      }
      else
      {
         if (member(PFixMaterial,M_DESCONOCIDO_TXT)== -1)
          PFixMaterial += ({ M_DESCONOCIDO_TXT });
      }
   else if( stringp( material[i] ) ) PFixMaterial += ({ material[i] });
  }

 return PFixMaterial;
}

string SetResize(string verb) { return Pverb_resize=verb; }
string QueryResize() {  return Pverb_resize;  }

string QueryBuy()
{
    if(QueryNoShop())
        return 0;
    else
        return ::QueryBuy();
}

string QuerySell()
{
    if(QueryNoShop())
        return 0;
    else
        return ::QuerySell();
}

string QueryList()
{
    if(QueryNoShop())
        return 0;
    else
        return ::QueryList();
}

string QueryShow()
{
    if(QueryNoShop())
        return 0;
    else
        return ::QueryShow();
}

string QueryAppraise()
{
    if( QuerySell() || QueryFix() || QueryResize() )
        return ::QueryAppraise();
    else
        return 0;
}

int SetRepairFactor(int factor) { return Prepair_factor = factor; }
int QueryRepairFactor() { return Prepair_factor; }

int SetResizeFactor(int factor) { return Presize_factor = factor; }
int QueryResizeFactor() { return Presize_factor; }

int SetMaxRepair(int percent)
{
    if (percent > 100)
        percent = 100;
    if (percent < 1)
        percent = 1;
    return Pmax_repair = percent;
}

int QueryMaxRepair() { return Pmax_repair; }

int SetMaxQuality(int percent)
{
    if (percent > 100)
        percent = 100;
    if (percent < 0)
        percent = 0;
    return Pmax_quality = percent;
}

int QueryMaxQuality() { return Pmax_quality; }

int SetWeaponDecay(int decay) { return Pweapon_decay=decay; }
int QueryWeaponDecay() { return Pweapon_decay; }

int SetArmourDecay(int decay) { return Parmour_decay=decay; }
int QueryArmourDecay() { return Parmour_decay; }

int SetSmithy(int i)
{
    if (i)
        AddDetail(({"martillo","yunque"}),
            "Hay un martillo colocado encima de un yunque.\n");
    else
        RemoveDetail(({"martillo","yunque"}));
    return Psmithy=i;
}

int QuerySmithy() { return Psmithy; }

int IsSmithy() { return QuerySmithy(); }

int cmd_repair(string str)
{
    if( !QuerySmithy() )
        return 0;
    if( TP && TP->HasSkill(HAB_REPARAR) )  // [w] Por si metemos el skill de reparar.
        return 0;
    if( str && QueryFix() && sk_in_shop() )
    {
        notify_fail(W("\n No sabes reparar ese objeto, tendrás que requerir los "
        "servicios del herrero del lugar.\n\n"));
        return 0;
    }
    notify_fail(W("\n No sabes reparar objetos, deberás recurrir al herrero local.\n\n"));
    return 0;
}

varargs int GetRepairPrice(object ob,int force)
{
    mixed price;
    int percent,quality,max_quality;
    if (!ob)
        return 0;
    quality=ob->QueryQuality();
    max_quality=QueryMaxQuality();
    if (max_quality==0)
        max_quality = (ob->QueryResetQuality() || 100);
    if (!quality)
        return 0;
    if( (percent=max_quality-quality) > QueryMaxRepair() )
        percent=QueryMaxRepair();
    if (percent <= 0)
        return 0;
    price=ob->QueryValue(1);
    price=(price*percent)/100;
    price=ModifyPrice(ob,price,"fix");
    price=(price*QueryRepairFactor())/100;
    if (force)
        price=2*price;
    if (price<=0)
        price=1;
    else
        price=(round_value(price)||1);
    return price;
}

varargs int GetResizePrice(object ob,int size,int force)
{
    mixed price;
    if (!ob)
        return 0;
    if (ob->QuerySize()==P_SIZE_GENERIC)
        return 0;
    if (!size)
        return 0;
    price=ob->QueryValue(1);
    price=ModifyPrice(ob,price,"resize");
    // [n] Multiplicado por 2 el precio... espero no haberme pasao...
    price=(price*QueryResizeFactor()*2)/100;
    if (force)
        price=2*price;
    if (price<=0)
        price=1;
    else
        price=(round_value(price)||1);
    return price;
}

int do_fix(string str)
{
    mixed pay_result;
    object ob;
    string dummy;
    int price,force,repair;

    if (!TP)
        return 0;
    Say(CustomerName(1)+" pide  que le reparen "+(str||"algo")+".\n"
    "Los golpes del martillo resuenan sobre el yunque y la piedra de amolar chirría.\n",
        ({TP}),1);
    if (!sk_in_shop())
        return 0;
    if (!QueryFix())
    {
        notify_fail(lambda(0,
            ({SF(SkSay),"No arreglo nada.\n"})),NOTIFY_NOT_OBJ);
        return 0;
    }
    if (!str)
    {
        notify_fail(lambda(0,
            ({SF(SkSay),"Dime, ¿que quieres que te repare?\n"})),
            NOTIFY_NOT_VALID);
        return 0;
    }
    if (str=="dinero")
    {
        notify_fail(lambda(0,
           ({SF(SkSay),"Muy gracioso "+CustomerName(1)+", no pretenderás que solucione tus problemas economicos, ¿verdad?.\n"})),
             NOTIFY_NOT_VALID);
        return 0;
    }
    if (!ob=present(str,TP))
    {
        notify_fail(lambda(0,
           ({SF(SkSay), CustomerName(1)+",  no tienes nada llamado "
           +str+", así que déjame en paz, que tengo mucho trabajo y poco tiempo!\n"})),NOTIFY_NOT_VALID);
        return 0;
    }
    if((!CheckTrade(ob)) || (!CheckLivingTrade(ob)))
    {
        notify_fail(lambda(0,
           ({SF(SkSay),CustomerName()+", no te puedo reparar "
           +ob->Short()+".\n"})),NOTIFY_NOT_VALID);
        return 0;
    }
    if(member(QueryFixMaterial(),ob->QueryMaterial())==-1 && QueryFixMaterial()!=({}))
    {
        notify_fail(lambda(0,
           ({SF(SkSay),CustomerName()+", esto es una herrería, ¿cómo pretendes que te "
           	"repare algo hecho de "+ob->QueryMaterial()+".\n"})),NOTIFY_NOT_VALID);
        return 0;
    }
    if(ob->QueryQuality()>=100)
    {
        notify_fail(lambda(0,
           ({SF(SkSay),"eso no está en absoluto deteriorado, haz el favor de no hacerme perder el tiempo!\n"
           })),NOTIFY_NOT_VALID);
        return 0;
    }
    if(ob->QueryQuality()<=0)
    {
        notify_fail(lambda(0,
           ({SF(SkSay),capitalize(ob->Short())+" está demasiado deteriorado y no puedo hacer nada para repararlo.\n"
           })),NOTIFY_NOT_VALID);
        return 0;
    }
    if(ob->QueryQuality()>=(QueryMaxQuality()||ob->QueryResetQuality()))
    {
        notify_fail(lambda(0,
           ({SF(SkSay),
           ob->Short()+" no necesita de ninguna reparación. ¡no me entretengas con tonterías!\n"})),NOTIFY_NOT_VALID);
        return 0;
    }
    if(ob->QueryResetQuality()<20)
    {
        notify_fail(lambda(0,
           ({SF(SkSay),"Me temo que "+
           ob->Short()+" está tan deteriorado que no soportaría una sola reparación más.\n"})),NOTIFY_NOT_VALID);
        return 0;
    }
    price=GetRepairPrice(ob,force);
    pay_result=PayValue2(TP,price,QueryValuta());
    if (!pointerp(pay_result))
    {
        notify_fail(lambda(0,
            ({SF(SkSay),"Tendrás que pagarme "+MONEY_DEMON->QueryMoneyString(
            MONEY_DEMON->CreateMoney(price,QueryValuta()))+" si quieres que te repare "
            +ob->Short()+". ¡Necesito mantener el negocio en estos malos tiempos!\n"})),NOTIFY_ILL_ARG);
        return 0;
    }
    SkEmote("descuelga algunas herramientas que deja al alcance de la mano, empuña con "
    "firmeza su martillo y se pone a reparar "+ob->Short()+".\n"
    "El martillo golpea el yunque rítmicamente.\n\n");
    if (ob->QueryQuality()<ob->QueryResetQuality()-20)
     ob->SetResetQuality(ob->QueryResetQuality()-20);
    repair=ob->QueryResetQuality()-ob->QueryQuality();
    if (repair > QueryMaxRepair())
        repair = QueryMaxRepair();
    ob->SetQuality(ob->QueryQuality()+repair);
    if (ob->QueryWeaponType())
    {
        ob->Set(P_WP_PER_QP,ob->Query(P_WP_PER_QP)-QueryWeaponDecay());
        if (ob->Query(P_WP_PER_QP) < 1)
            ob->Set(P_WP_PER_QP,1);
    }
    if (ob->QueryArmourType())
    {
        ob->Set(P_AP_PER_QP,ob->Query(P_AP_PER_QP)-QueryArmourDecay());
        if (ob->Query(P_AP_PER_QP) < 1)
            ob->Set(P_AP_PER_QP,1);
    }
    SkSay("Bueno, "+CustomerName(1)+", aquí tienes,  lo he reparado lo mejor posible.\n");
    Write("Rebuscas en tu bolsa y sacas "+pay_result[0]+(pay_result[1]?" que arrojas sobre un banco de trabajo. Te devuelven "+
        pay_result[1]:"")+" y lo guardas a buen recaudo.\n");
    Say(CustomerName(1)+" echa mano de la bolsa y arroja sobre un banco de trabajo "+pay_result[0]+(pay_result[1]?" y se guarda "+
        pay_result[1]:"")+" que le devuelven.\n",({TP}),1);
    return 1;
}

int do_resize(string str)
{
    mixed pay_result;
    object ob;
    string dummy;
    int size,price,force;

    if (!TP)
        return 0;
    Say(CustomerName(1)+" quiere que le modifiquen "+(str||"algo")+" "+
        (QueryResize()||"modificar")+"d.\n",
        ({TP}),1);
    if (!sk_in_shop())
        return 0;
    if (!QueryResize())
    {
        notify_fail(lambda(0,
            ({SF(SkSay),"Ya no modifico de tamaño ningún objeto.\n"})),NOTIFY_NOT_OBJ);
        return 0;
    }
    if (!str)
    {
        notify_fail(lambda(0,
            ({SF(SkSay),"¿Qué es lo que quieres modificar de tamaño?\n"})),
            NOTIFY_NOT_VALID);
        return 0;
    }
    if (sscanf(lower_case(str),"%s grande",dummy)==1)
    {
        size=P_SIZE_LARGE;
        str=dummy;
    }
    else if (sscanf(lower_case(str),"%s pequeño",dummy)==1 ||
             sscanf(lower_case(str),"%s pequenyo",dummy)==1)
    {
        size=P_SIZE_SMALL;
        str=dummy;
    }
    if (!ob=present(str,TP))
    {
        notify_fail(lambda(0,
           ({SF(SkSay),"Lo siento, "+CustomerName(1)+", pero no tienes ningun objeto llamado '"
           +str+"'.\n"})),NOTIFY_NOT_VALID);
        return 0;
    }
    if(member(QueryFixMaterial(),ob->QueryMaterial())==-1 && QueryFixMaterial()!=({}))
    {
        notify_fail(lambda(0,
           ({SF(SkSay),"Lo siento "+CustomerName()+", pero no modificamos objetos "
           "hechos de "+ob->QueryMaterial()+".\n"})),NOTIFY_NOT_VALID);
        return 0;
    }
    if((!CheckTrade(ob)) || (!CheckLivingTrade(ob)))
    {
        notify_fail(lambda(0,
           ({SF(SkSay),"Lo siento, "+CustomerName()+", pero no puedo "+QueryResize()+
           " "+ob->Short()+".\n"})),NOTIFY_NOT_VALID);
        return 0;
    }
    if(ob->QuerySize()==P_SIZE_GENERIC)
    {
        notify_fail(lambda(0,
           ({SF(SkSay),capitalize(ob->Short())+" vale para cualquier persona.\n"})),
           NOTIFY_NOT_VALID);
        return 0;
    }
    if(!size)
    {
        notify_fail(lambda(0,
            ({SF(SkSay),"Quieres que haga "+
            ob->Short()+", más pequeño o mas grande?\n"})),
            NOTIFY_NOT_VALID);
        return 0;
    }
    if((ob->QuerySize()==1 && size==P_SIZE_SMALL) ||
       (ob->QuerySize()==4 && size==P_SIZE_LARGE))
    {
        notify_fail(lambda(0,
           ({SF(SkSay),capitalize(ob->Short())+" ya es tan "+
           (size==P_SIZE_SMALL?"pequeñ"+(ob->Query(P_GENDER)==2?"a":"o"):"grande")
           +" como puede serlo.\n"})),NOTIFY_NOT_VALID);
        return 0;
    }
    price=GetResizePrice(ob,size,force);
    pay_result=PayValue2(TP,price,QueryValuta());
    if (!pointerp(pay_result))
    {
        notify_fail(lambda(0,
            ({SF(SkSay),"Te costará "+MONEY_DEMON->QueryMoneyString(
            MONEY_DEMON->CreateMoney(price,QueryValuta()))+" modificar de tamaño "
            +ob->Short()+".\n"})),NOTIFY_ILL_ARG);
        return 0;
    }
    SkEmote("se pone a trabajar con "+ob->Short()+".\n");
    if(size==P_SIZE_SMALL) {
        ob->SetSize(ob->QuerySize()-1);
        if (ob->QueryWeight()>10) ob->SetWeight(ob->QueryWeight()*(4/5));
    }
    else{
        ob->SetSize(ob->QuerySize()+1);
        if (ob->QueryWeight()>10) ob->SetWeight(ob->QueryWeight()*(5/4));
    }

    // [n] Ahora, cambiar el tamaño daña un poco el objeto
    ob->SetQuality(ob->QueryQuality()-5);
    ob->SetResetQuality(ob->QueryResetQuality()-5);

    SkSay("Aquí tienes lo que me has pedido que te modifique "+CustomerName(1)+".\n");
    Write("Pagas "+pay_result[0]+(pay_result[1]?" y te devuelven "+
        pay_result[1]:"")+".\n");
    Say(CustomerName(1)+" paga "+pay_result[0]+(pay_result[1]?" y le devuelven "+
        pay_result[1]:"")+".\n",({TP}),1);
    return 1;
}

int do_appraise(string str)
{
    object ob;
    int price,maxprice;
    int repairprice,resizeprice;
    string text;

    Say(CustomerName(1)+" le pregunta  a "+(SkShort()||"alguien")+" cuanto puede valer "+
        (str||"algo")+".\n",({TP}));
    if (!sk_in_shop())
        return 0;
    if (!QueryAppraise())
    {
        notify_fail(lambda(0,
            ({SF(SkSay),"No tengo por costumbre opinar sobre lo que vale tal o cual cosa..\n"})),
            NOTIFY_NOT_OBJ);
        return 0;
    }
    if(!str)
    {
        notify_fail(lambda(0,
            ({SF(SkSay),"¿De qué quieres saber el valor?\n"})),
            NOTIFY_NOT_VALID);
        return 0;
    }
    if(!ob = present(str, TP))
    {
        notify_fail(lambda(0,
           ({SF(SkSay),"¿Pretendes burlarte de mí, "+CustomerName()+"? Sabes "
           	"perfectamente que no tienes ni "+str+" ni nada que se le parezca, así que, "
           	"¡déjame en paz!\n"})),NOTIFY_NOT_VALID);
        return 0;
    }
    if(blueprint(ob) == "/obj/money")
    {
        notify_fail(lambda(0,
            ({SF(SkSay),"Lo siento "+CustomerName()+", si quieres negociar con "
            "dinero tendrás que ir al banco.\n"})),NOTIFY_NOT_VALID);
        return 0;
    }
    price = (price = GetPrice(ob))>(maxprice = GetMaxPrice(ob))
        ?maxprice:price;
    if((!CheckTrade(ob)) || (!CheckLivingTrade(ob)))
    {
        SkSay("Mmm... me parece que "+ob->Short()+" podría venderse por algo así como "+
            MONEY_DEMON->QueryValueString(price,QueryValuta())+
            ", pero no comercio con ese tipo de cosas, así que no podría asegurarlo.\n");
        return 1;
    }
    repairprice = GetRepairPrice(ob);
    resizeprice = GetResizePrice(ob,ob->QuerySize()+1);
    text="";
    if(QuerySell())
        text+="\nPuedo pagarte "+MONEY_DEMON->QueryValueString(price,QueryValuta())+
            " por "+ob->Short()+". ";
    if(QueryFix() && ob->QueryQuality() && (ob->QueryQuality()<100))
        text+="\nTe "+QueryFix()+"e "+ob->Short()+" por "+
            MONEY_DEMON->QueryValueString(repairprice,QueryValuta())+".";
    if(QueryResize() && resizeprice)
        text+="\nTe "+QueryResize()+"e el tamaño de "+ob->Short()+" por "+
            MONEY_DEMON->QueryValueString(resizeprice,QueryValuta())+".";
    if((text=="") && (ob->QueryQuality()==100))
        text+=capitalize(ob->Short())+" está en perfectas condiciones.";
    if((text=="") && (ob->QuerySize()==P_SIZE_GENERIC))
        text+=capitalize(ob->Short())+" vale para todos los tamaños.";
    if(text=="")
        text+=capitalize(ob->Short())+" no vale ni una triste moneda de cobre.";
    SkSay(text+"\n");
    return 1;
}

int CheckTrade(object ob)
{
    if( ob->QueryWeaponType() || ob->QueryArmourType() || ob->QuerySpecialWeapon())
        return 1;
}

varargs string format_sign(string cmd,string desc,string help)
{
  return
    W(STR->ladjust(cmd+" ",29,".")+ " "+desc)+"\n"
    +(help?W( STR->mkstr(30)+"Ejemplo: "+help)+"\n":"");
}

string detail_sign()
{
    string buy,sell,identify,appraise,list,vshow,fix,resize,result;

    if (buy = QuerySignDesc()) return buy;
    buy = QueryBuy();
    sell = QuerySell();
    identify = QueryIdentify();
    appraise = QueryAppraise();
    list = QueryList();
    vshow = QueryShow();
    fix = QueryFix();
    resize = QueryResize();

    if (!(buy||sell||identify||appraise||list||vshow||fix||resize))
    return "El herrero es estupido y no entiende ningún comando.\n";

    result = "";
    if (buy||sell)
        result+="Puedes "+(buy?buy+(sell?" o ":""):"")
            +(sell||"")+" cosas aqui.\n";
    result+="El herrero entiende los siguientes comandos:\n";
    result+=list?format_sign(list+" [<objeto>]",
        "Mostrar artículos de la tienda (todos/objeto).",
        list+", "+list+" arma"):"";
    result+=identify?format_sign(identify+" <que>",
        "Pedir informacion especial sobre un artículo"
        "que tengas. Te costará el 10% del valor "
        "del objeto.",identify+" espada"):"";
    result+=vshow?format_sign(vshow+" <que>",
        "Pedir al tendero  información sobre "
        "un artículo de la tienda.",
        vshow+" casco"):"";
    result+=appraise?format_sign(appraise+" <que>",
        "Pedir al herrero"+(sell?" el valor de uno de tus objetos"
        +(fix&&resize?",":(fix||resize?" y":"")):"")+
        (fix?" cuanto te costará "+fix+" el objeto"+
        (resize?" y":""):"")+(resize?" cuanto te costará "
        +resize+" el objeto":"")+".",
        appraise+" cuchillo"):"";
    if (!QueryMarket())
        result+=sell?format_sign(sell+" <que>",
            "Vender objetos que tengas.",
             sell+" todo, "+sell+" guantes en saco"):"";
    else
        result+=sell?format_sign(sell+" <que> [por <precio>]",
            "Vender objetos que tengas. Se te pagará (en tu "
            "cuenta bancaria) en cuanto alguien compre el objeto. "
            "Si quieres vender el objeto por un precio, "
            "dalo en monedas de cobre.",
            sell+" hacha por 300, "+sell+" cuchillo en saco"):"";
    result+=buy?format_sign(buy+" <que>",
        "Comprar artículos.",
         buy+" cota de malla, "+buy+" 3, "+buy+" guantes"):"";
    result+=fix?format_sign(fix+" <que>",
        "Pedir al herrero que arregle un artículo.",
        fix+" espada"):"";
    result+=resize?format_sign(resize+" <que> <tamaño>",
        "Pedir al herrero que cambie el tamaño de un artículo. <pequeño/grande> "
        "indica si quieres que sea un poco más grande o un poco más"
        " pequeño. El cambio de tamaño lo dañará un poco.",
        resize+" espada grande"):
        "";
/*
    result+=(TP&&IS_LEARNER(TP))?format_sign("tienda <comando>",
        "Comandos especiales para valar. "
        "Ver 'tienda ayuda' para más información."):"";
*/
    return result;
}

string detail_shopkeeper()
{
    if (QueryNoShopkeeper())
        return "Este es el herrero.\n";
    if (!QueryShopkeeper())
        return "No hay nadie.\n";
    return 0;
}

string QueryIntLong(string arg)
{
    if (arg)
        return ::QueryIntLong(arg);
    return ((::QueryIntLong(1))||"Estás en una herreria.\n")+
        "Hay un tablero colgado del muro.\n";
}

void SetShopkeeper(string file, mapping properties)
{
    RemoveShopkeeper();
    if(!file)
        TO->AddItem("/std/npc",REFRESH_HOME,({
            ([P_RACE:"enano",
              P_LEVEL:24,
              P_NAME:"un fornido herrero",
              P_IDS:({"tendero","herrero","forjador"}),
              P_SHORT:"el herrero",
              P_LONG:"Es el herrero propietario de esta herrería.\n",
              P_GENDER:(random(3)?GENDER_MALE:GENDER_FEMALE),
              P_ALIGN:-400+random(800),
              P_CON:30,
              P_STR:26,
              P_INT:14,
              P_UVISION: 200,
              P_IVISION: -200
            ]),
            properties})-({0}),
            LSF("shopkeeper_refresh"));
    else
        TO->AddItem(file,REFRESH_HOME,properties,LSF("shopkeeper_refresh"));
  TO->SetSchedulerID(SHOPKEEPER_ID);
}


create()
{
    ::create();
    SetIntShort("Una herreria");
    SetIdentify(0);
    SetFix("arreglar");
    SetResize("modificar");
    SetNoShop(0);
    SetSmithy(1);
    SetMaxRepair(100);
    SetMaxQuality(100);
    SetRepairFactor(150);
    SetResizeFactor(33);
    AddDetail(({"pared", "muro"}),
    "Hay un tablero con algo escrito colgado del muro.\n");
    AddDetail("tablero","Léelo si sabes leer.\n");
    RemoveDustbin();
    AddRoomCmd("reparar",SF(cmd_repair)); // [w] Solo si dispones el skill de reparar.
    AddReadMsg("nota",SF(detail_sign));
}

init()
{
    ::init();
    add_action("do_fix",QueryFix()||"arreglar");
    //add_action("do_resize",QueryResize()||"modificar");
}
