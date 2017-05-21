/* ENDOR OROME asiento.c
Asiento base de donde deben de heredar cualquier cosa para sentarse.
el archivo que herede de este hay que ajustar en el create:
Set("name", "nombre del asiento"); (sin terminar en punto ni \n)
SetDescripcion("la descripción del asiento."); (sin \n,la primera parte del SetLong que se crea automaticamente.)
SetMaxPlazas(x); (x=cantidad de personas a sentarse)
SetWeight(x); (peso del asiento en gramos, imprescindible para calcular el peso máximo)
SetFirmeza(); usar los defines P_FIRMEZA_MUY_FRAGIL, P_FIRMEZA_FRAGIL, P_FIRMEZA_NORMAL, P_FIRMEZA_RESISTENTE O P_FIRMEZA_MUY_RESISTENTE incluyendo en el archivo materials.h
 SetSize();
 AddId(({})); los identificativos en array
 SetAds(({})); (los adjetivos)
 Set(P_GENDER, GENERO_MASCULINO);
    Set(P_NUMBER, NUMERO_SINGULAR);
 por defecto peso 5000, tamaño medium, plazas 1, firmeza normal, material madera, genero masculino y número singular
 también ajustar el valor, el material  y los SubDetail si se desea.
El short y el long se crean automaticamente con las funciones f_long y f_short añadiendo
a las propiedades de name y descripción la cantidad de ocupantes o el estado del asiento.
  */

#include <properties.h>
#include <combat.h>
#include <materials.h>
inherit THING;

string Descripcion,estado_long, estado_short;
int pers, roto,MaxPlazas, MaxPeso,PesoAcomulado, Firmeza = 0;
string *sent=({});
public int QueryMaxPlazas()          { return MaxPlazas; }
public int SetMaxPlazas(int i)       { return MaxPlazas = i; }
public string QueryDescripcion() { return Descripcion; }
public string SetDescripcion(string i) { return Descripcion = i; }
public int QueryFirmeza()   { return Firmeza; }
public int SetFirmeza(int i)       { return Firmeza = i; }
public int QueryMaxPeso()          {
    return MaxPeso= ((QueryWeight()*QuerySize()*QueryMaxPlazas())+(QueryFirmeza()*QueryMaxPlazas())); }
public int SetMaxPeso(int i)   { return MaxPeso = i; }
public int QueryPesoAcomulado()          { return PesoAcomulado; }
public int SetPesoAcomulado(int i)       { return PesoAcomulado = i; }

string f_long(){
    switch(roto){
        case 0:
        if (pers==0) estado_long="Ahora mismo está vací"+QueryGenderEndString()+".\n";
    else{
        if (pers==1) estado_long="Solamente está sentad"+TP->QueryGenderEndString()+" ";
        else estado_long=(capitalize(itoa(pers))+" personas están sentadas: ");
                }
                estado_long+=implode_list(sent);
        break;
    case 1:
        estado_long="Está completamente destrozad"+QueryGenderEndString()+", es imposible sentarse en "
        +(QueryGender()==GENERO_MASCULINO ? "él" : "ella")+".\n";
        break;
    }
    return QueryDescripcion()+
    (QueryMaxPlazas()==1 ? " Es para " : " Pueden sentarse hasta ")+
        (QueryMaxPlazas()==1 ? "una" : itoa(QueryMaxPlazas()))
        +" persona"+ (QueryMaxPlazas()==1 ? "" : "s")+".\n"+estado_long;
        }
public string f_short(){
    switch(roto){
        case 0:
        if (pers==0) estado_short=" (vací"+QueryGenderEndString()+")";
    else
         estado_short=" (ocupad"+QueryGenderEndString()+" por "+implode_list(sent)+")";
        break;
    case 1:
        estado_short=" (rot"+QueryGenderEndString()+")";
        break;
    }
    return Query("name")+estado_short;
}

public int fsentarse(){
    if(roto==1) return notify_fail(Query("name")+" está bien rot"+QueryGenderEndString()
        +", es imposible sentarse en "+(QueryGender()==GENERO_MASCULINO ? "él" : "ella")+".\n",
        NOTIFY_NOT_VALID);
        if(environment()==TP) return notify_fail("No podrás sentarte en "+Query("name")+
            " si lo dejas en el suelo "+(QueryGender()==GENERO_FEMENINO ? "ella" : "él")+".\n",
                 NOTIFY_NOT_VALID);
    if(QueryPesoAcomulado()+TP->QueryWeight()>QueryMaxPeso()){
        roto=1;
        write(Query("name")+" no aguanta tu peso y se parte y desmorona, "+(pers>0 ? "cayendo al suelo junto con "+implode_list(sent) : " cayendo al suelo y dándote un buen porrazo")+".\n");
    say(Query("name")+" se rompe por el exceso de peso al intentar sentarse "+TNAME+" que cae al suelo"+(pers>0 ? " junto con "+implode_list(sent) : "")+".\n");
    TP->Defend(d8(),TD_APLASTAMIENTO, DEFEND_NOMSG | DEFEND_NOLIV | DEFEND_NO_DEF_SK);
        TP->AddTP(-d4());
            filter(all_inventory(environment(TP)), (:if (living($1) && $1->SetStatusResting())
        {
            $1->SetStatusNormal();
        $1->RemoveAttribute("sentado");
        $1->Defend(d8(),TD_APLASTAMIENTO, DEFEND_NOMSG | DEFEND_NOLIV | DEFEND_NO_DEF_SK);
        $1->AddTP(-d4());
    }
    return 0;:));
            f_short();
            f_long();
        return 1;
    }else {
    if (pers<QueryMaxPlazas())
    {
        int sentado=TP->QueryAttribute("sentado");
        if (!sentado)
        {
            SetNoGet(1);
            pers++;
            sent+=({TNAME});
            TP->SetStatusResting();
            TP->SetAttribute("sentado",time());
            write("Te sientas en "+Query("name")+".\n");
            tell_room(environment(),TNAME+" se sienta en "+Query("name")+".\n",({TP}));
            SetPesoAcomulado(QueryPesoAcomulado()+TP->QueryWeight());
            f_long();
            f_short();
        }
        else write("Ya estás sentad"+TP->QueryGenderEndString()+".\n");
    }
    else
    {
        write("No queda espacio en "+Query("name")+" para tí.\n");
        tell_room(environment(),TNAME+" mira  "+Query("name")+" para sentarse, pero no le queda sitio.\n",({TP}));
    }
    return 1;
}
}

public int flevantarse()
{
    int sentado=TP->QueryAttribute("sentado");
    if (sentado)
    {
        pers--;
        SetPesoAcomulado(QueryPesoAcomulado()-TP->QueryWeight());
        if (pers<=0){ pers=0; SetNoGet(0); SetPesoAcomulado(0);}
        sent-=({TNAME});
        TP->SetStatusNormal();
        TP->RemoveAttribute("sentado");
                f_long();
                f_short();
        write("Te levantas de "+Query("name")+".\n");
        tell_room(environment(),TNAME+" se levanta de "+Query("name")+".\n",({TP}));
    return 1;
    }
    return 0;
}

create()
{
    ::create();
        SetMaxPlazas(1);
        Set("name", "un asiento");
    SetShort(SF(f_short));
    SetDescripcion("Un sencillo asiento de madera algo resistente.");
    SetLong(SF(f_long));
    AddId(({"asiento"}));
        Set(P_GENDER, GENERO_MASCULINO);
    Set(P_NUMBER, NUMERO_SINGULAR);
    SetMaterial(M_MADERA);
        SetWeight(7500);
        SetValue(1000);
    SetFirmeza(P_FIRMEZA_NORMAL);

}

init()
{
    ::init();
    add_action("flevantarse","levantarse");
    add_action("fsentarse","sentarse");
}

/*
    people = filter(all_inventory(),
                    (:if (living($1) && $1->Fighting()) $1->StopAttack();
    return (living($1) && $1 != $3 && (!$2 || !sizeof($2) || member($2, $1) < 0));:), ((items = QueryItems()) ? map(QueryItems(), (:$1[RITEM_OBJECT]:)) : 0), QuerySchedulerObject());
    */
    /*
    filter(all_inventory(abajo), (:if (living($1))
        {
        $1->Defend(20+d20(2),TD_APLASTAMIENTO, DEFEND_NOMSG | DEFEND_NOLIV | DEFEND_NO_DEF_SK);
        $1->AddTP(-d6());
    }
    return 0;:));
    */