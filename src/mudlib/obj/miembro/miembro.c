/*
DESCRIPCION  : Miembro desmembrado
FICHERO      : /obj/miembro.c
MODIFICACION : 17-07-98 [Angor@Simauria] Creacion.
               29-07-98 [Angor@Simauria] Ahora los miembros ya se pudren.
	       Mar'99 [Nemesis@Simauria] Castellanizado.
	       Nota: Angor, como te faltas!!!
--------------------------------------------------------------------------------
1. Comandos disponibles:

comer    - Utilidad obvia. Su 'efecto' se aplica al jugador

cocinar  - Aumenta su 'poder' en funcion de la destreza del cocinero
         - Solo se puede cocinar una vez
         - Para poder cocinar algo hace falta el objeto ?????

-------------------------------------------------------------------------------
2. Efectos de los miembros al ser comidos

NOTA: el efecto que deberia usarse casi siempre es o 'ninguno' o 'saciante',
quedando el resto para casos especiales (ej: pata de tarantula->venenosa)

ninguno     : obvio, no?
curativo    : Da puntos de vida (HP)
magico      : Da puntos de magia (SP)
saciante    : Comida (quita parte del hambre) (FOOD)
venenoso    : Quita puntos de vida (HP)

-------------------------------------------------------------------------------
3. Funciones disponibles:

SetTipo(), QueryTipo()           clase de miembro (ej: cabeza, cuerno)
SetRaza(), QueryRaza()           raza (ej: orco, lagarto)
QueryEfecto(), SetEfecto()       efecto al comerselo;
SetComible(), QueryComible()     se puede comer? (0 no, 1 si)
SetCocinable(), QueryCocinable() se puede cocinar? (0 no, 1 si)
SetVendible(), QueryVendible()   se puede vender? (0 no, 1 si)
QueryPudrible(), SetPudrible()   se puede pudrir? (0 no, 1 si)
QueryGenero(), SetGenero()       genero gramatical (0 neutro, 1 masculino,
                                 2 femenino)
QueryValue(), SetValue()         valor monetario
QueryPoder(), SetPoder()         poder del efecto al comerselo
QueryVomitar(), SetVomitar()     probabilidad de vomitar

QueryEnergiaTxt()                descripcion textual de cuanto alimenta
QueryMiembroTxt()                descripcion textual actualizada del miembro

SetComestiblePor()               lista de razas que pueden comerlo
QueryComestiblePor()             lista de razas que pueden comerlo
SetComerMSG()                    mensajes para cuando se come
--------------------------------------------------------------------------------
*/

inherit "std/thing";
#include <properties.h>
//#include "/players/angor/miembro.h"
#include "/sys/miembro.h"

#define NOMBRE capitalize(TP->QueryName())
#define GEN    (TP->QueryGenderEndString())

//--variables------------------------------------------------------------------
string tipo;     //que clase de miembro es (ej: cabeza, cuerno)
string raza;     //raza del ser al que pertenecio (ej: orco, lagarto)
string efecto;   //que pasa cuando te lo comes?

string comerMSG1; //mensaje para uno cuando se come
string comerMSG2; //mensaje para el resto cuando se come

int    comible;   //0 no, 1 si
int    cocinable; //0 no, 1 si
int    cocinado;  //0 no, 1 si
int    vendible;  //0 no, 1 si
int    pudrible;  //0 no, 1 si

int    genero;  //genero gramtical: 0 neutro, 1 masculino, 2 femenino
int    poder;   //valor del efecto al comerselo
int    valor;   //valor al vender el objeto
int    vomitar; //% de que se vomite y no se coma (0 no, 100 siempre)

string *ComestiblePor; //razas que pueden comerselo

int duracion;           //duracion del miembro hasta pudrirse por completo
int vida;               //cuanto le queda al miembro hasta pudrirse
int ritmo_putrefaccion; //cada cuantos heart-beat se decrementa la vida
int contador;
int umbral;

//--definicion de algunas funciones declaradas despues------------------------
public Actualiza();

//--funciones de configuracion-----------------------------------------------
string QueryTipo(){return tipo;}
void   SetTipo(string t){tipo=t;AddId(t);Actualiza();}

string QueryRaza(){return raza;}
void   SetRaza(string r){TO->SetRace(r);}
string QueryRace(){return raza;}               //por compatibilidad del body.c
void   SetRace(string r){raza=r;Actualiza();}//por compatibilidad del body.c

string QueryEfecto(){return efecto;}
void   SetEfecto(string s){efecto=s;}

int    QueryComible(){return comible;}
void   SetComible(int c){comible=c;}
int    QueryCocinable(){return cocinable;}
void   SetCocinable(int c){cocinable=c;}
int    QueryVendible(){return vendible;}
void   SetVendible(int v){vendible=v;}
int    QueryPudrible(){return pudrible;}
void   SetPudrible(int i){pudrible=i; set_heart_beat(i);}

void   SetDuracion(int i){if (i>0) {duracion=i; vida=i;}}
int    QueryDuracion(){return duracion;}
int    QueryVida(){return vida;}
void   SetRitmoPutrefaccion(int i){ritmo_putrefaccion=i;}
int    QueryRitmoPutrefaccion(){return ritmo_putrefaccion;}

int    QueryGenero(){return genero;}
void   SetGenero(int i){TO->SetGender(i);}
int    QueryGender(){return genero;}              //por compatibilidad
void   SetGender(int i){genero=i; Actualiza();} //por compatibilidad

int    QueryValue(){return(vendible?valor:0);}
int   SetValue(int i){ return valor=i;}
int    QueryValor(){return QueryValue();}
void   SetValor(int i){SetValue(i);}
int    QueryPoder(){return poder;}
void   SetPoder(int i){poder=i;}
int    QueryVomitar(){return vomitar;}
void   SetVomitar(int i){vomitar=i;}

//void   SetComestiblePor(string *lista){ComestiblePor=map(lista,0);}
void   SetComestiblePor(string *lista){ComestiblePor=lista;}
string *QueryComestiblePor(){return ComestiblePor;}
void   SetComerMSG(string s1, string s2){comerMSG1=s1; comerMSG2=s2;}

//--funcion principal---------------------------------------------------------
create() {
  string *myname;
  ::create();
  SetShort("un miembro de algun ser");
  SetLong("Es un miembro desmembrado de algún ser. No sabrías decir qué es ni a qué\n"
          "tipo de ser perteneció alguna vez.\n");
  AddId("miembro");

  SetWeight(1000);

  SetTipo("miembro");
  SetRaza("un ser desconocido");
  SetEfecto("saciante");

  SetComible(0);
  SetCocinable(0);
  SetVendible(0);
  SetPudrible(1);

  SetGenero(1);
  SetPoder(0);
  SetValor(0);

  SetDuracion(3);
  SetRitmoPutrefaccion(20);

  //variables internas
  cocinado=0;
  contador=0;
  umbral=100;
}


void heart_beat()
{
 string s;
 int n;
 s=(QueryGenero()==2?"la ":"el ")+QueryTipo()+" de "+QueryRaza();

 if(contador>=ritmo_putrefaccion)
 {
  if (vida==0) {
      say(capitalize(s)+" se ha podrido por completo.\n");
      destruct(TO);
      }
  else{
      vida-=1;
      contador=0;
      n=100*vida/duracion;// porcentaje: 100% fresco, 0% podrido del todo

      if ((n<=25)&&(umbral>25)){
          say(capitalize(s)+" está podrid"+(QueryGenero()==2?"a":"o")+" casi por completo.\n");
          umbral=25;
          }
      else if ((n<=50)&&(umbral>50)){
          say(capitalize(s)+" está medio podrid"+(QueryGenero()==2?"a":"o")+".\n");
          umbral=50;
          }
      else if ((n<=75)&&(umbral>75)){
          say(capitalize(s)+" comienza a pasarse.\n");
          umbral=75;
          };
      }
  }
 else contador++;
 return;
}


//--funciones adicionales-----------------------------------------------------
Actualiza(){
  SetShort(QueryMiembroTxt());
}

string QueryEnergiaTxt() {
  string sufijo;
  sufijo=(QueryGenero()==2?"a":"o");

  switch (poder) {
     case 0:        return "no sirve como alimento";
     case 1..5:     return "alimenta muy poco";
     case 6..10:    return "no es que alimente mucho";
     case 11..50:   return "sirve de alimento";
     case 51..100:  return "te alimentará bien";
     case 101..150: return "te alimentará muy bien";
     case 151..170: return "bastante nutritiv"+sufijo;
     case 171..200: return "muy nutritiv"+sufijo;
  }
  return "demasiado fuerte";
}

string QueryMiembroTxt() {
   string s;
   s=(QueryGenero()==2?"una":"un")+" "+QueryTipo();
   if (cocinado==1) s=s+" cocinad"+(QueryGenero()==2?"a":"o");
   s=s+" de "+QueryRaza();
   return s;
 }

//--comandos asociados al objeto----------------------------------------------
init() {
  ::init();
  add_action("comer_cmd","comer");
  add_action("cocinar_cmd","cocinar");
  Actualiza();
}

cocinar_cmd(str){
   string descr1, descr2;
   descr1=(QueryGenero()==2?"una ":"un ")+QueryTipo()+" de "+QueryRaza();
   descr2=(QueryGenero()==2?"la ":"el ")+QueryTipo()+" de "+QueryRaza();

   if (!str) return;
   if (member(Query(P_IDS), str)<0) return;
   if (!present(TO, TP)) {
      notify_fail("No tienes "+descr1+" que cocinar.\n");
      return 0;
      }

   if (!cocinable){
      write("No hay forma de cocinar est"+(QueryGenero()==2?"a":"e")+" "+QueryTipo()+" de "+QueryRaza()+".\n");
      return 1;
      }
   else{
      if (cocinado){
           write(capitalize(descr2)+" ya estaba cocinad"+(QueryGenero()==2?"a":"o")+".\n");
           }
      else{
           write("Cocinas "+descr2+".\n");
           poder=poder+random((TP->QueryDex())*2);
           SetVomitar(QueryVomitar()/2);
           say(TP->QueryName()+" cocina "+descr1+".\n",TP);
           cocinado=1;
           Actualiza();
           }
      return 1;
      }
}

comer_cmd(str) {
   string descr1, descr2;
   int i;
   object vomito;

   descr1=(QueryGenero()==2?"una ":"un ")+QueryTipo()+" de "+QueryRaza();
   descr2=(QueryGenero()==2?"la ":"el ")+QueryTipo()+" de "+QueryRaza();

   if (!str) return;
   if (member(Query(P_IDS), str)<0) return;
   if (!present(TO, TP)) {
      notify_fail("No tienes "+descr1+" que comer.\n");
      return 0;
   }

   if (!comible){
   write(capitalize(descr2)+" no es algo que se pueda comer.\n");
   return 1;
   }

   //write("debug: arg1="+);

   if (member(ComestiblePor, TP->QueryRace())>=0){
   //if (member(Query(P_IDS), str)<0) return;
   //if (member(ComestiblePor,QueryRaza())){

      write("Te comes "+descr1+".\n");
      if (comerMSG1!="") write(comerMSG1);
      say(TP->QueryName()+" se come "+descr1+".\n",TP);
      if (comerMSG2!="") say(comerMSG2,TP);

      if (random(100)<vomitar) {

           write(
           "De repente sientes arcadas y unas terribles nauseas...\n"
           "Buaaaargh! Un líquido amargo, ácido y caliente sube por tu garganta...\n"
           "Has vomitado.\n");
           say("De repente, "+NOMBRE+" vomita justo delante de ti.\n", TP);

           vomito = clone_object(VOMITO);
           vomito->move(environment(TP));
           destruct(TO);
           return 1;
          }
      else{
          switch (efecto) {
            case "venenoso":      poison(); break;
            case "curativo":      heal(); break;
            case "magico":        magic(); break;
            case "saciante":      satiate(); break;
            default: write("Te sientes igual que antes.\n");
            }
            return 1;
          }
      }
   else{
      write(
     "Puede que lo necesites, pero el orgullo de los de tu raza te impide comer este\n"
     "tipo de cosas.\n");
      say(NOMBRE+
      " va a comerse "+descr1+", pero al final cambia de opinión.\n");
      return 1;
      }
}

poison() {
  write("Ohhhh! Argh! Te arde la garganta! Tu estómago comienza a hervir.\n");
  say("Argh!. "+TP->QueryName()+" se retuerce de dolor.\n",TP);
  TP->Defend(poder);
  destruct(TO);
  return 1;
}

heal() {
  write("El sabor es bastante agradable. Notas cómo tu cuerpo se recupera.\n");
  TP->SetHP(TP->QueryHP()+poder);
  if (TP->QueryHP() > TP->QueryMaxHP())
     TP->SetHP(TP->QueryMaxHP());
  destruct(TO);
  return 1;
}

satiate() {
  string suf;
  if ((TP->QueryGender())==2) suf="a";
     else suf="o";
  write("Te sientes menos hambrient"+suf+".\n");
  TP->SetFood(TP->QueryFood()+poder);
  destruct(TO);
  return 1;
}

magic() {
  write("Sientes cómo unos extraños poderes fluyen a traves de tu cuerpo!\n");
  TP->SetSP(TP->QuerySP()+poder);
  if (TP->QuerySP() > TP->QueryMaxSP())
     TP->SetSP(TP->QueryMaxSP());
  destruct(TO);
  return 1;
}
