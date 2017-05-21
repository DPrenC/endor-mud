/*
DESCRIPCION  : Hueso
FICHERO      : /obj/hueso.c
BASADO       : sdtbone.c thragor@nightfall
MODIFICACION : 13-02-97 [angor] Creacion.
--------------------------------------------------------------------------------
Un hueso es un tipo de arma muy rustica.

Funciones disponibles:

QueryTipoHueso()                  obtiene el tipo de hueso
SetTipoHueso(string t)            establece el tipo de hueso
SetSexo(s)                        establece el genero gramatical del hueso
QuerySexo()                       obtiene el genero gramatical del hueso
SetAdjetivo(a)                    establece el adjetivo del hueso
QueryAdjetivo()                   obtiene el adjetivo del hueso
QueryRazaHueso()                  establece la raza a la que pertece el hueso
SetRazaHueso(string r)            obtiene la raza a la que pertece el hueso
GetRandRazaHueso()                obtiene una raza aleatoria para el hueso
SetValorHueso(int valor,int rand) calcula y establece el valor del hueso
QueryValorHueso()                 obtiene el valor del hueso
SetPesoHueso(int peso,int rand)   calcula y establece el peso del hueso
QueryPesoHueso()                  obtiene el peso del hueso

--------------------------------------------------------------------------------
*/

#include <combat.h>
#include "./raza_hueso.h"

inherit WEAPON;

//Variables globales
private static string tipo, raza, adj;
private int sexo;
private static mapping razas;

//Declaracion de las funciones
public int QuerySexo();
public void SetSexo(int s);



//Definicion de las funciones
protected void up_short()
{
    SetShort((QuerySexo()==2?"una ":"un ")+tipo+" "+adj+" de "+raza);
}

public string QueryTipoHueso() {return tipo;}
public void SetTipoHueso(string t)
{
    AddId(t);
    tipo = t;
    up_short();
}

public void   SetSexo(int s){sexo=s;}
public int    QuerySexo(){return sexo;}

public void SetAdjetivo(string a){adj=a; AddAdjective(a);}
public string QueryAdjetivo(){return adj;}

public string QueryRazaHueso() {return raza;}
public void SetRazaHueso(string r)
{
  AddId(tipo+" de "+r);
  raza = r;
  up_short();
}

public string GetRandRazaHueso()
{return m_indices(razas)[random(sizeof(razas))];}

public int GetValue(string raza)
{
    return razas[raza];
}

public int QueryValorHueso()
{
    return QueryValue();
}
public varargs SetValorHueso(int valor,int rand)
{
    return SetValue((valor+random(rand))*GetValue(QueryRazaHueso()));
}

public int QueryPesoHueso()
{
    return QueryWeight();
}
public varargs SetPesoHueso(int peso,int rand)
{
    return SetWeight((peso+random(rand))*GetValue(QueryRazaHueso()));
}


public create()
{
  ::create();
  //SetStandard(WT_CLUB,2+random(10));
  SetStandard(WT_MAZA,2+random(10));
  SetShort("un hueso");
  SetSexo(1);
  SetAdjetivo("blanco");
  SetTipoHueso("hueso");
  razas = RAZA_HUESO;
  SetWPperQP(1);
  SetResetQuality(80);
  SetRazaHueso(GetRandRazaHueso());
  SetLong(QueryShort()+".\n");
}
