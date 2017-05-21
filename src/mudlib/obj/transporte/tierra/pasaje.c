/* SIMAURIA '/obj/transporte/tierra/pasaje.c'
   ==========================================
   [w] Woo@simauria

   NOTA: Este será el pasaje basico en las diligencias de Simauria
   16-04-98 [w] Creacion de este archivo.
   24-06-98 [w] El pasaje ya tiene implementeadas todas las funciones
                necesarias y esta totalmente operativo.
   26-06-98 [w] Anyadida la funcion QueryCaducado() que devuelve un 1
                en caso de que este caducado y 0 en caso contrario.
                No se pueden cambiar las descripciones de Short y Long
                ya que van variando segun el estado del billete.
   07-08-98 [w] Anyadida la funcion SetEnUso() y QueryEnUso() de
                utilizacion meramente interna con el objeto de saber
                que pasaje o billete es el que se esta utilizando
                a la hora de viajar y asi poder tener mas de 1 pasaje
                en tu inventario.
   10-12-98 [w] Añadida la propiedad AutoObject().
   15-03-99 [w] Quitada la propiedad AutoObject() además ahora pierdes
                el pasaje si se rebootea el mud (aunque se haya guardado
                el objeto se te destruye nada más entrar). Ahora por
                defecto todos los pasajes NO son economicos ya que se
                ha eliminado esta característica.
*/

inherit "/std/thing";

#include <properties.h>

int comprado;
int caducidad;
int economico;
int enuso;

string origen;
string destino;
string diligencia;

create()
{
 ::create();
 Set(P_NOSELL, "Lo siento, no puedes vender los pasajes.\n");
 Set(P_NOGIVE, "Este pasaje es personal e intransferible, deberias conservarlo.\n");
 SetIds(({"pasaje","ticket","billete"}));
 SetCaducidad(7200); // Por defecto tendra una duracion de 2 horas
 SetEconomico(0);
 comprado=time();
}

init() {
::init();
}

QueryNoDrop()
{
 if(QueryCaducado() || QueryDestino()=="")
  return 0;
 return "Este pasaje es personal e intransferible, deberias conservarlo.\n";
}

// [w] En segundos.
public int SetCaducidad(int caduc)
{
 if(intp(caduc))
  return caducidad = caduc;
 return caducidad = caducidad;
}

public string SetIDdiligencia(string str)
{
 return diligencia = str || "";
}

public string QueryIDdiligencia()
{
 return diligencia || "";
}

public string SetOrigen(string str)
{
 return origen=str || "";
}

public string SetDestino(string str)
{
 return destino=str || "";
}

public string QueryOrigen()
{
 return origen || "";
}

public string QueryDestino()
{
 return destino || "";
}

public int QueryCaducidad()
{
 return caducidad;
}

public int QueryBfecha()
{
 return comprado;
}

public int SetEnUso(int i)
{
 return enuso = i || 0;
}

public int QueryEnUso()
{
 return enuso || 0;
}

public int QueryCaducado()
{
 if(time()-comprado>caducidad && !QueryEnUso())
  return 1;
 return 0;
}

public int SetEconomico(int eco)
{
 return economico = eco || 0;
}

public int QueryEconomico()
{
 return economico || 0;
}

public int QueryPasaje()
{
 return 1;
}

QueryShort()
{
// Elimina el objeto después de un reiniciar o reboot.
 if (QueryDestino()=="" || !QueryDestino())
 return call_out("remove"),"";

 if(QueryCaducado())
  return "un pasaje hasta "
         +(QueryDestino()!=""?capitalize(QueryDestino()):"no se donde")
         +" (caducado)";
 return "un pasaje hasta "
         +(QueryDestino()!=""?capitalize(QueryDestino()):"no se donde");
}

QueryLong()
{
 if(QueryDestino()=="" || QueryOrigen()=="")
  return funcall(W("Se trata de un simple pasaje "
   "de diligencia sin destino, por lo tanto no te sirve "
"para nada."))+"\n";

 if(!QueryCaducado())
  return funcall(W("Se trata de un pasaje "
  +(QueryEconomico()?"economico ":"")
  +"de la diligencia '"+capitalize(QueryIDdiligencia())+"' que te permitira "
"ir desde "+capitalize(QueryOrigen())+" hasta "+capitalize(QueryDestino())+"."
))+"\n";

  return funcall(W("Se trata de un pasaje caducado "
   "de la diligencia '"+capitalize(QueryIDdiligencia())+"' que te permitia "
"ir desde "+capitalize(QueryOrigen())+" hasta "+capitalize(QueryDestino())+"."
))+"\n";
}

//mixed QueryAutoObject() { return 1; }
