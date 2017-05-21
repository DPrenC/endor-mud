/*
quemable.c
creado por orome 20/10/2014
DESCRIPCION  : objeto quemable para hogueras. heredar de este para distintos objetos de igual utilidad.
*/

#include <properties.h>

inherit THING;
int pQuemable,pCombustion;
string pTipoarbol="�rbol";
public int QueryQuemable()  {   return pQuemable; }
public int SetQuemable(int i)  {  return pQuemable = i;  }
public int QueryCombustion()  {  return pCombustion;  }
public int SetCombustion(int i)  {  return pCombustion = i; }
public string QueryTipoArbol()         { return pTipoarbol; }
public string SetTipoArbol(string str) { return pTipoarbol = str; }
create()
{
    ::create();
        seteuid(getuid(TO)); // Para poder cargar el objeto de f�rmula.
    SetTipoArbol("�rbol");
    SetShort("una rama de le�a");
    SetLong("Una peque�a rama de le�a seca que se puede utilizar para alimentar una hoguera.\n");
    SetIds(({"le�a","lenya","rama", "ramita","quemable"}));
    SetAds(({"seca","peque�a","pequenya"}));
    SetWeight(d100(3));
    SetValue(QueryWeight()/10);
    Set(P_GENDER,GENDER_FEMALE);
    Set(P_SIZE,P_SIZE_SMALL);
    SetQuemable(1);
    SetCombustion(QueryWeight());
            }


init()
{
    ::init();
    }

