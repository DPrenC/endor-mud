/*
DESCRIPCION  : comando que proporciona el peso
FICHERO      : /bin/mortal/_peso.c
MODIFICACION : 13-03-99 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include <config.h>            //por el NOTIFY
#include <properties.h>
#include "/secure/wizlevels.h" //para distinguir a los wizs

#define AO   (TP->QueryGender()==GENDER_FEMALE?"a":"o")

private int    EscribePeso(object ob);
private string QuePeso(int p);
private string CargaXtra();
private string QuePesoPJ();

int peso(string que)
{
int i, ok, primero;
object ob;
string str,str2;
string *ids;

ok=0;


//peso propio
if (!que) {write(QuePesoPJ()); return 1;}

//peso de los objetos de inventario
if (que=="inv")
  {
  write("\n");
  for(ob=first_inventory(TP);ob;ob=next_inventory(ob)) EscribePeso(ob);
  write("\n");
  return 1;
  }

//peso de un objeto dado
primero=1;
for(ob=first_inventory(TP);ob;ob=next_inventory(ob))
    {
    ids=ob->QueryIds();
    for(i=0;i<sizeof(ids);i++)
       if (ids[i]==que)
          {
          ok=1;
          if (primero==1)
             {
             write("En tu inventario:\n");
             primero=0;
             }
          EscribePeso(ob);
          i=sizeof(ids);
          }
    }
primero=1;
for(ob=first_inventory(environment(TP));ob;ob=next_inventory(ob))
    {
    ids=ob->QueryIds();
    for(i=0;i<sizeof(ids);i++)
       if (ids[i]==que)
          {
          ok=1;
          if (primero==1)
             {
             write("En enta habitacion:\n");
             primero=0;
             }
          EscribePeso(ob);
          i=sizeof(ids);
          }
    }

if (ok==0) return notify_fail("No ves ningun "+que+" por aqui.\n",NOTIFY_NOT_VALID)&&0;
return 1;
}


private int EscribePeso(object ob)
{
  string str, str2;
  int i;

  str=capitalize(ob->QueryShort());
  str2=STR->ladjcut(str+" ",65,".");
  i=ob->QueryWeight();
  str=(string)i;
  str2+=STR->radjust(str,7," ");
  write(str2+" g\n");
  return 1;
}


private string QuePeso(int p)
{
string s;

if IS_WIZARD(TP) s=(string)p;
else
   {
   switch (p) {
   case 0..100: s="casi nada";break;
   case 101..250: s="menos de un cuarto de kilo";break;
   case 251..500: s="al menos medio kilo";break;
   case 501..750: s="cerca de tres cuartos de kilo";break;
   case 751..1000: s="casi un kilo";break;
   case 1001..2000: s="un par de kilos al menos";break;
   case 2001..5000: s="algo menos de 5 kilos";break;
   case 5001..10000: s="entre 5 y 10 kilos";break;
   case 10001..15000: s="cerca de 15 kilos";break;
   case 15001..20000: s="bastante, al menos 20 kilos";break;
   case 20001..25000: s="al menos unos 25 kilos";break;
   case 25001..35000: s="bastante, quiza 30 o 35 kilos";break;
   case 35001..45000: s="bastante, tal vez 40 o 45 kilos";break;
   case 45001..55000: s="mucho, al menos unos 50 kilos";break;
   case 55001..75000: s="mucho, seguro que mas de 50 kilos";break;
   case 75001..100000: s="cerca de 100 kilos";break;
   case 100001..150000: s="demasiado, seguro que mas de 100 kilos";break;
   //default: s="ni idea de cuanto pesa";
  }
  //s=(string)p+" "+s;
 }
return s;
}

private string QuePesoPJ()
{
  string s;
  int mipeso,carga,maxcarga;

  mipeso=TP->QueryMaxWeight()-TP->QueryMaxContent();
  carga=TP->QueryWeight()-mipeso;
  maxcarga=TP->QueryMaxContent();

  if IS_WIZARD(TP)
     s="\nTu peso  : "+mipeso+" g.\nTu carga : "+carga+"/"+maxcarga+" g.\n";
  else
     {
     s="\nDebes pesar "+QuePeso(mipeso)+".\n"
       "Tu carga debe pesar "+QuePeso(carga)+"\n";

     switch (carga*100/maxcarga) {
       case 1..10: s+="Apenas llevas carga encima.\n";break;
       case 11..25: s+="Vas un poco cargad"+AO+".\n";break;
       case 26..50: s+="La carga que llevas empieza a ser pesada.\n";break;
       case 51..75: s+="Llevas bastante carga encima.\n";break;
       case 76..100: s+="Casi no puedes con toda la carga que llevas encima.\n";break;
       }
     }
  return s;
}


     