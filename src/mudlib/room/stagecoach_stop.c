/**
 * SIMAURIA '/room/stagecoach_stop.c'
 */

#include <config.h>
#include <properties.h>
#include <colours.h>
#include <keeper.h>
#include <moving.h>
#include <sounds.h>
#include <money.h>

inherit ROOM;
inherit STR;
inherit KEEPER;

public string _cartel(); // forward
string tmp,tmpdil;
string NombreParada;
string *paradas;   // Archivo de las diligencias que paran.
int num_paradas;   // Numero de diligencias que paran
string Cartel;     // Texto del cartel de ayuda.
int Descuento;

public int _itinerario(string str);

public void create()
{
  ::create();
  SetIntShort("una parada");
  SetIntLong("La parada de una diligencia.\n");
  SetIndoors(0); // Las paradas tienen que estar al aire libre.
  AddDetail("cartel", "Quizás debieras leer el cartel.\n");
  AddDetail("poste", "Es un poste de madera con un cartel colgado.\n");
  AddReadMsg("cartel", SF(_cartel));
  num_paradas=0;
  paradas=({});
}

QueryIntLong()
{
 return ::QueryIntLong()+"Ves un cartel colgado de un poste.\n";
}

init()
{
 (::init());
 add_action("_itinerario","itinerarios");
 add_action("_comprar","comprar");
 add_action("_precios","precios");
}


public int QueryParada()    { return 1; }

public string SetNombreParada(string str)
{
 return NombreParada = str || "parada-sin-nombre";
}

public string QueryNombreParada()
{
 return NombreParada || "parada-sin-nombre";
}

public AddDiligencia(string str)
{
 num_paradas++;
 paradas=paradas+({str});
 str->iniciar();
 return 1;
}

// [w] Devuelve un numero entre 0 y 100 con el descuento de esta parada.
//     Se puede modificar para que descuente segun raza, sexo, edad, etc.
public int QueryDescuento()
{
 return 0; // A no ser que se modifique devolvera siempre 0.
}

public int SetDescEconomico(int desc)
{
 if(desc<0 && desc>100)
 return Descuento = 0;
 return Descuento = desc || 0;
}

public int QueryDescEconomico()
{
 return Descuento || 0;
}

public string SetCartel(string str)
{

 return Cartel = str;
}

public string QueryCartel()
{
 if (Cartel) return Cartel;
 return " RED DE DILIGENCIAS DE SIMAURIA\n"
        " ==============================\n"
        "   itinerarios ......... Te muestra todas las diligencias que hacen\n"
        "                         parada aquí con sus respectivos recorridos.\n"
        "   precios <nombre> .... Visualiza los distintos precios de la diligencia\n"
        "                         llamada <nombre>.\n"
        "   comprar pasaje ...... Te permite comprar un pasaje para viajar con\n"
        "                         cualquiera de las diligencias que hacen parada\n"
        "                         en este lugar.\n"
        "\n";
}

public string _cartel()
{
 return QueryCartel();
}

public int _itinerario(string str)
{
 string *itinerario,destinos,salida;
 int i;

 if (!num_paradas)
 {
  write("Lo siento, esta parada está fuera de servicio.\n");
  return 1;
 }

 salida="";
 salida+=cadjust("==================================",76)+"\n";
 salida+=cadjust("| ITINERARIOS DE LAS DILIGENCIAS |",76)+"\n";
 salida+=cadjust("==================================",76)+"\n\n";
 for(i=0;i<num_paradas;i++)
 {
  itinerario=paradas[i]->QueryDestinos();
  destinos=implode(itinerario," -- ");
  salida+=" "+TC_BOLD+
//     funcall("/players/woo/diligencias/xpress"->QueryDnombre())
     funcall(capitalize(paradas[i]->QueryDnombre()))
     +":"TC_NORMAL+"\n";
  salida+="   "+wrap(destinos,70,3)+"\n\n";
 }
 write(salida);
 return 1;
}


leer_destino(string str)
{
 int enc,i,precio,dinero_jugador;
 string *destinos;
 mixed cparadas;
 object pasaje;


 if(str=="")
 {
  write("Debes escribir el lugar al que quieres ir: ");
  input_to("leer_destino");
  return 1;
 }
 if (str=="p")
 {
  _precios(tmpdil);
  write("\n" + KeeperName(K_CAP) + " te dice: ¿A dónde quieres ir? Esta diligencia para en " +
      implode_list(_destinos(tmpdil)) + " (Escribe 'p' para ver una lista de precios): ");
  input_to("leer_destino");
  return 1;
 }
 enc=0;
 if(lower_case(str)==lower_case(funcall(QueryNombreParada())))
 {
  KeeperTell("Ya te encuentras en ese lugar.\n");
  return 1;
 }
 destinos=funcall(tmp->QueryDestinos());
 cparadas=funcall(tmp->QueryParadas());
  if(!sizeof(destinos))
 {
  KeeperTell("Esa diligencia está fuera de servicio.\n");
  return 1;
 }
 for(i=0;i<sizeof(destinos);i++)
 {
  if (lower_case(str)==lower_case(destinos[i]))
  {
   precio=coste(QueryNombreParada(),str,destinos,cparadas);
   if (!Pay(TP, precio, "por un pasaje hacia " + CAP(str)))
   {
    return write(KeeperName(K_CAP) + " te dice: No tienes suficiente dinero.\n"), 1;
   }
   play_sound(TO, SND_SUCESOS("dinero"));
   pasaje=clone_object("/obj/transporte/tierra/pasaje");
//   pasaje->SetCaducidad(30);
   pasaje->SetDestino(str);
   pasaje->SetOrigen(QueryNombreParada());
   pasaje->SetIDdiligencia(funcall(tmp->QueryDnombre()));
   if (pasaje->move(TP) != ME_OK)
   {
     write("El pasaje se te cae al suelo.\n");
     pasaje->move(TO);
   }
   return 1;
  }
 }
 KeeperTell("Lo siento, esa diligencia no para aquí.\n");
 return 1;
}

leer_diligencia(string str)
{
 int i;
 string objd;

 if(str=="")
 {
     write(KeeperName(K_CAP) + " te dice: Debes escribir el nombre de la diligencia: ");
  input_to("leer_diligencia");
  return 1;
 }

  for(i=0;i<num_paradas;i++)
 {
  if(lower_case(str)==lower_case(funcall(paradas[i]->QueryDnombre())))
  { objd = paradas[i]; break; }
 }
 if(!objd)
 {
     write(KeeperName(K_CAP) + " te dice: Losiento, esa diligencia no tiene parada aquí.\n");
  return 1;
 }
 tmpdil=str;
 tmp=objd;
 write("\n" + KeeperName(K_CAP) + " te dice: ¿A dónde quieres ir? Esta diligencia para en " +
     implode_list(_destinos(tmpdil)) + " (Escribe 'p' para ver una lista de precios): ");
 input_to("leer_destino");
 return 1;
}

public int _comprar(string str)
{
 if (CantAttend(K_NOTIFY)) return 0;
 if (!num_paradas)
     return notify_fail(KeeperName(K_CAP) + " te dice: Lo siento, esta parada está fuera de servicio.\n");

 if (!str)
  return notify_fail("¿Qué es lo que quieres comprar?\n");

 if (str!="pasaje")
    return notify_fail(KeeperName(K_CAP) + " te dice: Leete el cartel antes de pedirme nada.\n");

 write(KeeperName(K_CAP) + " te dice: Escribe el nombre de la diligencia: ");
 input_to("leer_diligencia");
 return 1;
}

private int coste(string de, string hasta, string *destinos, mixed paradas)
{
 int i,enc,inicio,fin,coste;

 if ((!de) || (!hasta) || (!destinos) || (!paradas))
  return 0;

 if(lower_case(de)==lower_case(hasta))
  return 0;

 enc=0;inicio=0;fin=0;coste=0;
 for(i=0;i<sizeof(destinos);i++)
 {
  if(lower_case(destinos[i])==lower_case(de)) {enc++;inicio=i;}
  if(lower_case(destinos[i])==lower_case(hasta)) {enc++;fin=i;}
 }
 if(enc!=2) return 0;

 i=inicio;
 while(i!=fin)
 {
//  if(i>=sizeof(destinos)) i=0;
  coste=coste+paradas[i][2];
  i++;
  if(i>=sizeof(destinos)) i=0;
 }
 if(!coste) return 0;

 if (QueryDescuento()>0 && QueryDescuento() <= 100)
  coste = coste - ((coste*QueryDescuento())/100);

 if(coste && coste>0) return coste;
 return 0;
}

private string *_destinos(string dil)
{
    string obdil;
    int i;

    if (!num_paradas ||!dil) return 0;
    for(i=0;i<num_paradas;i++)
    {
        if(lower_case(dil)==lower_case(funcall(paradas[i]->QueryDnombre())))
        {
            obdil = paradas[i]; break;
            break;
        }
    }
    if(!obdil) return 0;
    return obdil->QueryDestinos();
}


public int _precios(string str)
{
 string objd,*destinos,salida;
 int i;
 mixed cparadas;

 if (!num_paradas)
  return notify_fail("Lo siento, esta parada está fuera de servicio.\n"),0;

 if(!str)
  return notify_fail("¿De qué diligencia quieres saber los precios?\n"),0;

 for(i=0;i<num_paradas;i++)
 {
  if(lower_case(str)==lower_case(funcall(paradas[i]->QueryDnombre())))
  { objd = paradas[i]; break; }
 }
 if(!objd)
  return notify_fail("Esa diligencia no tiene parada aquí.\n"),0;

 cparadas=funcall(objd->QueryParadas());
 destinos=funcall(objd->QueryDestinos());

 salida="\n"+TC_BOLD+"Lista de precios de la diligencia "
        +funcall(objd->QueryDnombre())+":\n\n"+TC_NORMAL;

 for(i=0;i<sizeof(destinos);i++)
 {
  if(coste(QueryNombreParada(),destinos[i],destinos,cparadas))
   salida+="  "+ladjust("Hasta "+destinos[i],40,".")
+radjust(
MONEY_LIB->Value2String(coste(QueryNombreParada(),destinos[i],destinos,cparadas))
,9,".") + ".\n";
 }

 write(salida);

 return 1;
}
