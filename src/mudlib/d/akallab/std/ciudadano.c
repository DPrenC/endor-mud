/*
DESCRIPCION  : un ciudadano generico
FICHERO      : /d/akallab/std/ciudadano.c
MODIFICACION : 15-10-98 [Angor@Simauria]Creacion
--------------------------------------------------------------------------------
*/

#include "./path.h"
#include RAIZ "/sys/ciudadano.h"
#include <properties.h>

#include <living.h>
#include <combat.h>
inherit NPC;

//variables internas

public string ciudad;                   // ciudad a la que pertenece
private int edad;                       //tipo de edad del PNJ
private int cobre, plata, oro, platino; //dinero del PNJ
private int guerrero;                   //es guerrero? [0] no, [1] si
private int borracho;                   //esta borracho? [0] no, [1] si
public  string *raza;                   //({raza masculina, raza femenina})
private int *dinero;                    //dinero por nivel

//Macros utiles

#define AE      (TP->QueryGender()==GENDER_FEMALE?"a":"e")
#define AO      (TP->QueryGender()==GENDER_FEMALE?"a":"o")
#define A_      (TP->QueryGender()==GENDER_FEMALE?"a":"")
#define NOMBRE  (capitalize(TP->QueryName()))
#define LAEL    (TP->QueryGender()==GENDER_FEMALE?"la":"el")
#define PRON    (TP->QueryGender()==GENDER_FEMALE?"ella":"el")
#define UN_A    ("un"+A_)

public int Actualiza();

//funciones de consulta/establecimiento de parametros

//NOTA: no se por que cuando llamo a estas funciones tras el create en el
//      objeto heredado da los errores mas extranyos al ejecutar  Actualiza()
public int    SetRaza(string *s){raza=s; SetRace(raza[0]); Actualiza(); return 1;}
public string QueryRaza(){return (QueryGender()==GENDER_FEMALE?raza[1]:raza[0]);}
public int    QueryGuerrero(){return guerrero;}
public int    SetGuerrero(int i){guerrero=i; Actualiza(); return 1;}
public string QueryCiudad(){return ciudad;}
public int    SetCiudad(string c){ciudad=c; Actualiza(); return 1;}
public string QueryEdadTxt(){
  string *tmp;
  tmp=EDAD;
  return tmp[edad*2+(QueryGender()==GENDER_FEMALE?1:0)];
}
public int    QueryEdad(){return edad;}
public int    SetEdad(int i){
  RemoveId(QueryEdadTxt());
  edad=i;
  AddId(QueryEdadTxt());
  Actualiza();
  return 1;
}


//Actualiza las descripciones

public int Actualiza(){
  string str;

  //short
  str=QueryName()+" "+UN_A+" ";


  if (guerrero==1) {
     str+="guerrer"+AO+" ";
     AddId("guerrer"+AO);
     }
  else RemoveId("guerrer"+AO);

  str+=QueryRaza()+" "+QueryEdadTxt();
  if (borracho==1) {
     str+=" borrach"+AO;
     AddId("borrach"+AO);
     }
  else RemoveId("borrach"+AO);

  SetShort(str);

  //long
  str=QueryName()+" es "+UN_A+(guerrero==1?" guerrer"+AO:"")+" "+QueryRaza();
  str+=" "+QueryEdadTxt()+(borracho==1?" borrach"+AO:"");
  if (ciudad!="") str+=" que vive en la ciudad de "+ciudad;
  str+=".\n";
  SetLong(str);
  return 1;
}

create()
{
 string *nombres;
 int *max;
 int *min;
 int nivel;
 int *umbral;
 string str;
 int i;

 ::create();
 //sexo?
 switch(random(2)){
   case 0: SetGender(GENDER_MALE);   nombres=N_MAS; break;
   case 1: SetGender(GENDER_FEMALE); nombres=N_FEM; break;
   }

 //nombre?
 SetName(nombres[random(sizeof(nombres))]);
 SetIds(({QueryName(),lower_case(QueryName())}));

 //edad?
 umbral=UMBRAL;
 edad=0;
 i=random(100);
 do{edad++;
   }while (i>umbral[edad]);
 edad--;
 AddId(QueryEdadTxt());

 //guerrero/a?
 guerrero=0;
 if (((edad>=ES_ADOL)&&(edad<=ES_ADULTO))&&(random(100)<=PROB_GUERRERO)) guerrero=1;

 //nivel del PNJ
 min=NIVEL_MIN;
 max=NIVEL_MAX;
 nivel=min[edad]+random(max[edad]-min[edad]+1);
 if (QueryGender()==GENDER_FEMALE) nivel-=1;
 if (guerrero==1) nivel+=3;
 SetLevel(nivel);

 //borracho?
 borracho=0;
 if ((edad>=ES_ADOL)&&(random(100)<=PROB_BORRACHO+(QueryGender()==GENDER_MALE?5:0))) borracho=1;

 //raza? orco por defecto
 if (!raza) raza=({"orco","orca"});

 //ciudad? por defecto no hay
 //ciudad="";

 Actualiza();

 SetGoChance(0);

 SetLevel(nivel);
 SetAlign(0);
 SetWhimpy(QueryMaxHP()/4); // Que huya facilmente

 //dinero?
 dinero=DINERO;
 oro=dinero[edad*3+0];
 plata=dinero[edad*3+1];
 cobre=dinero[edad*3+2];
 // Si estas borracho tienes la mitad del dinero
 if(borracho) {cobre=cobre/2; plata=plata/2; oro=oro/2; platino=platino/2;}
 AddItem("/obj/money",REFRESH_REMOVE,
  (["Money":(["cobre":cobre,"plata":plata,"oro":oro,"platino":platino])]));

 //chats
 if (edad==ES_BEBE){
    InitChats(5,({QueryName()+" llora desconsoladamente.. buuaahhhhhh..\n"
    }));
    }
}


public int QueryCiudadano(string donde){
return (donde==ciudad?1:0);
}

/*
private int IsGuardian(object mon)
{
 if(mon->QueryGuardian())
  return 1;
 return 0;
}*/

/*
DoDamage(int dmg) // Si le atacan busca a los guardias para que le defiendan.
{
 int i;
 object *guardias;

 guardias = filter(deep_inventory(environment(TO)),SF(IsGuardian));

 if(sizeof(guardias))
  for(i=0;i<sizeof(guardias);i++)
   guardias[i]->Kill(TP || PO);

 return ::DoDamage(dmg);
}*/


private status existe_jugador(string jugador) {
 return find_savefile(jugador)||find_object(lower_case(jugador));
}

public varargs void Die(mixed silent) {
 object asesino;

 asesino=PO;
 if(!existe_jugador(asesino->QueryRealName())) {::Die(silent);}
 ASESINATO->SetAsesino(asesino->QueryRealName(),edad,QueryGender(),borracho,guerrero);
 ::Die(silent);
}
