/*
DESCRIPCION  : Zona 'tipo' de el edificio de suministros
FICHERO      : /d/limbo/comun/habitacion/limbo/templo/suministros.c
MODIFICACION :

25-09-98 [Angor@Simauria] Creacion.
12-10-98 [Angor@Simauria] Anyadida la opcion 'amedida'
23-10-98 [Theuzifan] Corrige un bug. Si ponias coger gollomoso y gollomoso no
         existia, petaba. Ahora comprueba que exista.
12-11-98 [Angor@Simauria] Corregidos un par de bugs: el que confundia 'uva'
         con 'uvas' y el que te permitia coger mas peso de la cuenta.
13-11-98 [Theuzifan] MUEVE el objeto al inventario... que eso no se hace solo!
10-10-99 [Woo] Toqueteado...
18-03-05: [Kastwey]: Retoqueteado...
--------------------------------------------------------------------------------
*/

#include "./path.h"
#include <moving.h>
#include <properties.h>
#define AO      (TP->QueryGenderEndString())
#define NOMBRE  (capitalize(TP->QueryName()))
#define P_PROD_ALM_LIMBO "prod_almacen_limbo"

inherit ROOM;


public  string tipo;       // comida, armas, objetos magicos etc..
public  string *productos; // productos que contiene la estanter�a (nombre de fichero)
public  string *prod_fich; // path individual de los ficheros de productos
public  string path;       // path comun a los ficheros de los productos
private int    cont;       // contador de productos cogidos
private object *retirar = ({}); // objetos a retirar si un player tira al suelo

public  int    amedida;    // 0=no, 1=si, se proporciona un objeto a medida al PJ
public void retirar_objetos();
public string enumerar(string *arr);

string lista();

public create()
{
  ::create();
  SetIntShort("la secci�n de "+tipo);
  SetIntLong(W("Te encuentras en la secci�n de "+tipo+" en el almac�n de "
               "suministros.\n" //
               "A tu alrededor se extiende este almac�n en el que observas "
               "multitud de estanter�as repletas de los m�s variados "
               "productos que los dioses han puesto a disposici�n de los "
               "principiantes. Si miras la estanter�a que tienes frente a ti "
               "podr�s saber que productos tienes disponibles en esta "
               "secci�n del almac�n.\n" + lista()));

  AddDetail(({"estanterias"}),
            W("El almac�n est� lleno de estanter�as que contienen los m�s "
              "diversos productos y que los siervos de los dioses se "
              "encargan de reponer peri�dicamente. Si miras la estanter�a que "
              "tienes delante podr�s ver que productos puedes coger de "
              "ella.\n"));

  AddDetail(({"estanteria","estanter�a","estanterias","estanter�as"}),SF(lista));

  AddDetail(({"almacen","almac�n"}),
            W("La planta baja del edificio de los siervos de los dioses "
              "constituye el almac�n de suministros. Los dioses decidieron "
              "que ayudar�an a los principiantes en este mundo permiti�ndoles "
              "coger sin cargo alguno los m�ltiples tipos de objetos que "
              "se encuentran en este almac�n. Las �nicas limitaciones son  "
              "el peso de los objetos con los que puedes cargar y que dichos "
              "objetos no son de gran calidad.\n"));

  SetIntNoise("Oyes el ajetreo t�pico de un almac�n.\n");
  SetIntSmell("Los olores de los distintos productos se mezclan entre s�.\n");
  SetLocate("isla Limbo");
  SetIndoors(1);
  SetIntBright(50);
  AddRoomCmd("coger","coger_cmd");
  cont=0;
  amedida=0;
  SetSafe(1);
}

string    *SetProductos(string *lista){return productos = lista; }
string *QueryProductos(){return productos;}
int    QueryVerProductos(){write(lista());return 1;}

string lista()
{
  if (!sizeof(productos)) return "La estanter�a est� vac�a.\n";
  return W("En la estanter�a puedes ver productos de los siguientes "
           "tipos:\n" + enumerar(productos) + ".\n");
}



int coger_cmd(string str)
{
  int i, n, cogido, mov;
  object ob;
  if (!str) return 0;
  n=sizeof(productos);
  cogido=0;
  if (!n)
  {
    return notify_fail("La estanter�a est� vac�a.\n",NOTIFY_NOT_VALID);
  }
  // [Kastwey]: me cargo el for y pongo un member.
  if ((i = member(productos,str)) < 0)
  // no existe el producto especificado
  {
    return notify_fail("Ese producto no est� en la "
                       "estanter�a.\n",NOTIFY_NOT_VALID);
  }
  //path comun o productos dispersos?
  if (path=="")
  {
    if (get_dir(prod_fich[i]+".c"))
    {
      ob=clone_object(prod_fich[i]);
    }
    else
    {
      return notify_fail("No encuentras "+str+" para coger.\n",NOTIFY_NOT_VALID);
    }
  }
  else
  {
    if (get_dir(path+str+".c"))
    {
      ob=clone_object(path+str+".c");
    }
    else
    {
      return notify_fail("No encuentras "+str+" para coger.\n",NOTIFY_NOT_VALID);
    }
  }

  //objeto a medida del usuario?
  if (amedida) ob->SetSize(TP->QuerySize());
  if (!ob) return notify_fail("Imposible crear el objeto.\nContacta con un wizard.\n");
  if ((mov = ob->move(TP,M_GET)) != ME_OK)
  {
    string err;
    switch(mov)
    {
      case ME_TOO_HEAVY:
        err = ob->QueryShort() + " es demasiado pesado. Quiz�s si soltases algo...\n";
        break;
      case ME_TOO_MANY:
        err = "Llevas demasiadas cosas en tu inventario para coger " + ob->QueryShort() + ".\n";
        break;
      case ME_TOO_BIG:
        err = "No tienes espacio suficiente para coger " + ob->QueryShort() + ".\n";
        break;
      default:
        err = "No puedes coger " + ob->QueryShort() + ".\n" + mov + ".\n";
    }
    return notify_fail(err, NOTIFY_NOT_VALID);
  }
  else
  {
    write("Coges " + ob->QueryShort() + (amedida?" de tu talla ":"")+ " de la estanter�a.\n");
    say(capitalize(TP->QueryName()) + " coge " + ob->QueryShort() + " de la estanter�a.\n");
    ob->Set(P_NOSELL,1);
    ob->Set(P_PROD_ALM_LIMBO,tipo);
    cont++;
    // escena de reponer?
    if (cont==5)
    {
      tell_room(TO,"Aparece un siervo de los dioses y repone el genero que faltaba.\n");
      cont=0;
    }
  }
  return 1;
}

public int allow_enter(int method, mixed extra)
{
  if (   !PO || !query_once_interactive(PO) || query_wiz_level(PO)
      || PO->QueryLevel() < 5)
  {
    return ::allow_enter(method, extra);
  }
  tell_object(PO,"Eres demasiado mayor para entrar aqu�.\n");
  return ME_NO_ENTER;
}


public void notify_enter(mixed from, int method, mixed extra)
{
  if (PO && PO->Query(P_PROD_ALM_LIMBO) && method == M_DROP)
  // es un producto del almac�n.
  {
    retirar += ({PO});
    if (find_call_out("retirar_objetos") < 0) call_out("retirar_objetos",1);
  }
}

public void retirar_objetos()
// funci�n para retirar los objetos que un player tire al suelo
// mantengamos limpios el almac�n, por favor, XDD
{
  mapping ret_este = ([]), ret_otro = ([]);
  // mapping que conttendr�n los objetos que se van a retirar del suelo.
  // ret_este para los de esta secci�n del almac�n, y
  // ret_otro para el resto
  object ob;
  string short, msg;
  int total, este, otro;
  string *cosas_este, *cosas_otro;
  // quitamos del array todos los objetos que ya no est�n en memoria
  retirar -= ({0});
  total = sizeof(retirar);
  if (!total) return;
  if (total == 1)
  // solo se ha tirado una cosa.
  {
    ob = retirar[0];
    if (ob->Query(P_PROD_ALM_LIMBO) == tipo)
    // el producto es del tipo de esta parte del almac�n
    {
      tell_room(TO,W("Llega un siervo de los dioses y coloca de nuevo " +
                     ob->QueryShort() + " en la estanter�a.\n"));
    }
    else
    {
      tell_room(TO,W("Llega un siervo de los dioses, coge " +
                     ob->QueryShort() + " del suelo y se marcha.\n"));
    }
    ob->remove();
    return;
  }
  // filtramos los objetos que no est�n en esta room
  // a saber... Puede uqe alguien los haya cogido antes de que se ejecutase
  // el call_out
  retirar = filter(retirar,(:present($1,TO):));

  while (sizeof(retirar))
  // vamos recorriendo todos los elementos del array de objetos tirados
  {
    ob = retirar[0]; // hago esta asignaci�n para no tener que estar a cada
                     // rato llamando al elemento de la colecci�n del array

    short = ob->QueryShort() || "algo";
    if (ob->Query(P_PROD_ALM_LIMBO) == tipo)
    // el producto es de esta secci�n del almac�n
    {
      m_add(ret_este,short,++ret_este[short]);
      este++;
    }
    else
    // si no, es de otra parte del almac�n
    {
      m_add(ret_otro,short,++ret_otro[short]);
      otro++;
    }
    retirar[0]->remove();
    retirar -= ({0});
  }
  cosas_este = m_indices(ret_este);
  cosas_otro = m_indices(ret_otro);
  cosas_este = map(cosas_este,(:$1 + ($2[$1] > 1?" [" + $2[$1] + "]":""):), ret_este);
  cosas_otro = map(cosas_otro,(:$1 + ($2[$1] > 1?" [" + $2[$1] + "]":""):), ret_otro);
  if (este)
  // hay cosas tiradas que van en esta estanter�a
  {
    if (este > 5)
    {
      msg = W("Llega un siervo de los dioses y mira con mueca de fastidio "
                "todo lo que hay tirado por el suelo.\n");
    }
    else
    {
      msg = "Aparece un siervo de los dioses.\n";
    }
    msg += W("R�pidamente coloca " + enumerar(cosas_este) + " en la "
             "estanter�a.\n");
  }
  if (!otro)
  // no hay nada que poner en otras estanter�as
  {
    tell_room(TO,msg);
    call_other(retirar,"remove");
    return;
  }
  if (!este)
  // no hay nada en el suelo que vaya en esta estanter�a
  // por lo tanto, no hab�a ning�n siervo presente seg�n el mensaje
  // que estamos construyendo.
  {
    if (otro > 5)
    {
      msg = W("Aparece un siervo de los dioses, que mira con cara de "
              "fastidio todo lo que hay por el suelo.\n");
    }
    else
    {
      msg = "Aparece un siervo de los dioses.\n";
    }
  }
  if (otro > 5)
  // qu� de cosas tiradas, por dios... :P
  {
    msg += W((este?"A continuaci�n s":"S") + "e agacha, y observas como con "
             "gran pericia, consigue coger " + enumerar(cosas_otro) + ", y "
             "con todo ello en equilibrio, se va con paso r�pido ");
  }
  else
  // va, no hay tantas cosas...
  {
    msg += W((este?"A continuaci�n, c":"C") + "oge " +
             enumerar(cosas_otro) + " y se va con paso r�pido ");
  }
  msg += W("mientras te dice: "
           "La pr�xima vez procura no tirar las cosas al suelo, que siempre "
           "me toca a mi quitarlas de enmedio...\n");
  tell_room(TO,msg);
  call_other(retirar,"remove");
}

public string enumerar(string *arr)
{
  return implode(arr[0..<2],", ")+(sizeof(arr[0..<2])?" y ":"")+arr[<1];
}
