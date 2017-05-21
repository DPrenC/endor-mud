/* SIMAURIA '/std/corpse.c'
   ========================
   [t] Theuzifan@Simauria
   [a] Angor@Simauria
   [w] Woo@simauria
   [n] Nemesis@simauria

   27-04-97 [t] Traducido y anyadido el modo eat-a-corpse.
	        Ver el archivo '/fixed.log/Theuzifan.log' para ver cambios.
   28-04-97 [t] Arreglado. No funcionaba. Recursividad. Y esas cosas!
   30-09-98 [t] Añadido el Id cuerpo al fijambre.
   03-10-98 [a] Soporte/comandos para desmembrar miembros del cadaver
   20-11-98 [t] Cambia lo de que el cadaver se pase contigo... :)
   26-01-99 [t] Quito el capitalize del SetName para el mensaje de verlo...
   02-02-99 [t] Castellanización.
   25-02-99 [t] Añado la función QueryWeight, ¡que no existia! Modifico la
   		SetWeight para que devuelva el parámetro de entrada, que
   		antes tenia 'string' de salida pero no devolvia nada. Ahora
   		devuelve un entero.
   11-03-99 [t] Añadido el nombre en el Id. Quitado todo el rollo de 'cocinar'
   		Eso va ahora en el /bin
   05-04-99 [w] Pasada la variable ListaMiembros a 'static'.
   10-12-99 [t] Arreglo un petillo.
   18-04-02 [n] Esto es simplemente una reflexión/comentario.
                Acabo de descubrir que, cuando mueren, los draconianos
		y los trolls se convierten en polvo o en piedra
		respectivamente, con el resultado de que el jugador
		pierde todo lo que llevaba. No sé si es un bug o una
		característica, pero por si es un bug, yo lo documento,
		y así se convierte mágicamente en característica :)
*/

#include <mud.h>
#include <races.h>
#include <messages.h>
inherit CONTAINER;

#undef ENV
#define ENV environment

//[a] añadido lo siguiente
#include <config.h>  // añadido por NOTIFY_NOT_CMD
#define NOMBRE capitalize(TP->QueryName())
#define AO    (TP->QueryGenderEndString())
#define AE    (TP->QueryGender()==2?"a":"e")

/*-------------------------------------------------------------------------*/

public void DoDecay (int justschedule);  // forward

/*-------------------------------------------------------------------------*/

private int pDecaytime;  // Time for one decaystep.
private int pDecay;      // State of decay (0 is 'fresh');
private string pName;    // The name of the former living
private string pRace;    // The race of the former living
private int pWeight; // peso del fiambre
private int WasCooked;   // ha sido cocinado?
private int f;       // valor energetico

/*-------------------------------------------------------------------------*/

public int SetDecayTime (int t)  { return pDecaytime = (t > 0) ? t : 120; }
public int QueryDecayTime ()     { return pDecaytime; }

public int SetDecay (int d)  { return pDecay = d; }
public int QueryDecay ()     { return pDecay; }

/*-------------------------------------------------------------------------*/

public string SetRace (string name)  {
  int tm, dc;
  pRace=name;

  switch (pRace) {
    case ELF: tm=3; dc=-1; break;
    case DARKELF: tm=3; dc=-1; break;
    case GNOME: tm=100; dc=-1; break;
    case DWARF: tm=150; dc=-1; break;
    case DEMON: tm=135; dc=-1; break;
    case DUENDE: tm=80; dc=-1; break;
    case GIANT: tm=200; dc=-1; break;
    case LOGATH: tm=150; dc=-1; break;
    case DRACO: tm=0; dc=2; break;
    case TROLL: tm=0; dc=2; break;
    default: tm=120; dc=-1; break;
  }
  SetDecayTime(tm);
  SetDecay(dc);

  return pRace;

}

public string QueryRace ()           { return pRace;}

public int QueryCooked() { return(WasCooked); }

public int QueryWeight() { return pWeight; }
public int SetWeight(int w)
{
  return pWeight=w;
}

public string SetName (string name2) {
  string name;

  name=lower_case(name2||"");
  if (!name || name=="") name="alguien";
  pName = name;
  SetShort("el cuerpo de "+name);
  SetLong("Este es el cuerpo de "+lower_case(name)+".\n"
  "Sus miembros están rígidos por la muerte y cada vez está más frío.\n");
  AddId("el cuerpo de "+name);
  AddId(name);
  AddId("cadáver");
  AddId("cadaver");
  AddId("cuerpo");
  
  SetDecay(0);
  SetSmell("¡Huele a muerte y parece que está comenzando a pudrirse.\n");
  return name;
}
public string QueryName () { return pName;}

/*-------------------------------------------------------------------------*/

public void DoDecay (int justschedule) {
  while (remove_call_out("DoDecay") != -1);
  if (!justschedule)
  {
    pDecay++;
    if (pDecay == 1) {
      SetShort("el cuerpo de "+pName ligeramente deteriorado);
      SetLong("Es el cuerpo de "+pName+".\n"
      "Comienza a mostrar los primeros signos de podredumbre.\n");

      SetSmell("Desprende un leve hedor a podredumbre.\n");
      if (ENV())
        tell_room( ENV()
                 , ({ MSG_SEE
                    , "El cuerpo de "+pName+" comienza a pudrirse.\n"
                    , "El cadáver se está descomponiendo.\n" })
                 );
    }
    else if (pDecay > 1) {
      if (ENV())
        if (pRace == DRACO)
        {
          tell_room(ENV(), ({ MSG_SEE, "El cadáver de "+pName+" se convierte en polvo...\n",
                             pName+" se ha volatilizado.\n"}));
          AddId(({"monton", "montón", "montoncito", "polvo", "montón de polvo",
                "monton de polvo","montoncito de polvo"}));

         SetShort("un montoncito de polvo");
          SetLong("Un montoncito de polvo.\n");
        }
        else if (pRace == TROLL)
        {
          tell_room(ENV(), ({ MSG_SEE, "El cadáver de "+pName+" empieza a convertirse en piedra.\n",
                           pName+" se ha convertido en piedra...\n"}));
          AddId(({"estatua","estatua de piedra"}));
          SetShort("una estatua de "+pName);
          SetLong("Al morir, "+pName+" se convirtió en esta estatua de piedra.\n");
        }
        else
        {
          tell_room( ENV()
                 , ({ MSG_SEE
                    , "El cuerpo ya es tan solo un mugriento montón de podredumbre.\n"
                    , "Los últimos despojos de "+pName+" se pudren y desaparecen dejando un hedor dulzón a fruta pasada.\n" })
                 );
          remove();
        }
      return;
    }
  }
  if (pDecay >= 0)
    call_out("DoDecay", QueryDecayTime());
}

/*-------------------------------------------------------------------------*/

public void init() {
 (::init());

 //[a] comandos para desmembrar
 add_action("desmembrar_cmd",  "desmembrar");
 add_action("desmembrar_cmd",  "cortar");
}

public void create() {
  "container"::create();
  AddId("cadaver");
  AddId("restos");
  AddId("despojos");
  AddId("fiambre");
  AddId("cuerpo");

  SetDecayTime(120);
  SetDecay(0);
}


/*
--------------------------------------------------------------------------------
[a] Funciones relacionadas con el manejo de los miembros
--------------------------------------------------------------------------------
- void   SetDesmembrableEn(string *lista);
- string *QueryDesmembrableEn();
- void   QueryVerMiembros();
*/

private static string *ListaMiembros;

void SetDesmembrableEn(string *lista){ListaMiembros=lista;}
string *QueryDesmembrableEn(){return ListaMiembros;}

public varargs desmembrar_cmd (string arg)
{
  int n,yo,i,j,cortado,cont;
  string que,quien,tmp,str;
  object ob;
  string *nuevalista;

  que="";
  quien="";
  str="";

  if (!arg) return notify_fail("¿Desmembrar qué de quién?\n", NOTIFY_NOT_CMD);
  if (sscanf(arg,"%s de %s",que,quien)!=1){
    if ((que=="") && (quien=="")) return notify_fail("¿Desmembrar qué de quién?\n", NOTIFY_NOT_CMD);
    if ((que=="") && (quien!="")) return notify_fail("¿Desmembrar qué?\n", NOTIFY_NOT_CMD);
    if ((que!="") && (quien=="")) return notify_fail("¿Desmembrar de quién?\n", NOTIFY_NOT_CMD);
  }

  //¨es a mi?
  yo=0;
  if (quien==TO->QueryName()) yo=1;
  if (member(TO->QueryIds(),quien)!=-1) yo=1;
  //printf("que="+que+":quien="+quien+":yo="+(string)yo+"\n");
  if (!yo) return notify_fail("No encuentras "+que+" de "+quien+" que desmembrar.\n", NOTIFY_NOT_CMD);
  n=sizeof(ListaMiembros);
  if (n==0) return notify_fail("El cadáver de "+(TO->QueryShort())+" no tiene "+que+" que cortar.\n", NOTIFY_NOT_CMD);
  cortado=0;
  cont=0;
  if (n!=0) for(i=0;i<n;i++) {
    //printf("["+(string)i+"] "+ListaMiembros[i]+":"+que+":"+tmp+"\n");
    //printf("[sscanf:"+(string)sscanf(ListaMiembros[i],que,tmp)+"]\n");
    //printf("[strstr:"+(string)strstr(ListaMiembros[i],que,j)+"]\n");
    if ((strstr(ListaMiembros[i],que,j)!=-1)&&(cortado==0)) {
      ob=clone_object(ListaMiembros[i]);
      ob->SetRace(TO->QueryRace());
      ob->move(environment(TP));
      cortado=1;
      write("Cortas "+(ob->QueryArtDetString()+" ")+que+" del cadáver de "+(TO->QueryName())+".\n");
      say(NOMBRE+" le corta "+(ob->QueryArtDetString()+" ")+que+" al cadáver de "+(TO->QueryName())+".\n",TP);
      }
    else {
      if (cont!=0) str=str+" ";
      str=str+(string)ListaMiembros[i];
      cont+=1;
      };
  };
  if (cortado==0) return notify_fail("El cadáver de "+(TO->QueryName())+" no tiene "+que+" que cortar.\n", NOTIFY_NOT_CMD);
  nuevalista=explode(str," ");
  n=sizeof(nuevalista);
  //if (n!=0) for(i=0;i<n;i++) printf("["+(string)i+"] "+nuevalista[i]+"\n");
  if (cortado==1) ListaMiembros=nuevalista;
  return 1;
}

/* Para ver la lista de miembros por pantalla */
void QueryVerMiembros(){
  int n,i;
//  printf("Lista de miembros del pnj:\n");
  n=sizeof(ListaMiembros);
//  printf("Número de miembros:"+(string)n+"\n");
//  if (n!=0) for(i=0;i<n;i++) printf("["+(string)i+"] "+ListaMiembros[i]+"\n");
}

