/*
DESCRIPCION  : esclavo de los campos de cultivo (caracteristicas aleatorias)
FICHERO      : /d/limbo/comun/pnj/esclavo.c
MODIFICACION : 07-10-98 [Angor@Simauria] Creacion
               30-06-99 [Angor@Simauria] Retoques
--------------------------------------------------------------------------------
*/

#include "./path.h"
#include <living.h>
#include <combat.h>
#include <properties.h>
inherit NPC;

#define AE      (TP->QueryGender()==GENDER_FEMALE?"a":"e")
#define AO      (TP->QueryGender()==GENDER_FEMALE?"a":"o")
#define A_      (TP->QueryGender()==GENDER_FEMALE?"a":"")
#define NOMBRE  (capitalize(TP->QueryName()))

#define A_2     (QueryGender()==GENDER_FEMALE?"a":"")
#define AO2     (QueryGender()==GENDER_FEMALE?"a":"o")

//nombres de los esclavos
#define N_MAS ({"Kuntar","Garun","Seren","Tak","Abn-Sun","Yashuf","Jim","Tao"}) //masculinos
#define N_FEM ({"Alisia","Lena","Sha-na","Tana","Genneve","Taris"}) //femeninos

static int auxilio; //guardia orco acudira(0)/no acudira(1) en su defensa

//crea el pnj de forma aleatoria
void inicializa(){
  int gender;
  string nombre, raza;

  //sexo y nombre del pnj
  gender = (random(100)>75)?GENDER_FEMALE:GENDER_MALE; //75% esclavos, 25% esclavas

  if (gender==GENDER_FEMALE) nombre=N_FEM[random(sizeof(N_FEM))];
  else nombre=N_MAS[random(sizeof(N_MAS))];

  //raza del pnj (50% humano, 25% elfo, 15% medio-elfo, 10% orco)
  switch (random(100)) {
    case 0..50:	 raza="humano";		break;
    case 51..75: raza="elfo";		break;
    case 76..90: raza="medio-elfo";	break;
    default: 	 raza="orco";		break;
  }
  SetStandard(nombre,raza,5,gender);
}


create() {
  ::create();
 inicializa();
  SetShort((QueryName()+(QueryGender()==GENDER_FEMALE?" la esclava":" el esclavo")));
  SetLong(
     QueryName()+" es un"+A_2+" "+QueryRace()+ " esclav"+AO2+" de los orcos que trabaja en los campos de "
     "cultivo del valle de Zarkam. Sus ropas estan hechas jirones y no esta en muy "
     "buen estado. Aunque parece resignad"+AO2+", por el brillo que aparece en sus ojos "
     "dirias que no le han arrebatado la esperanza de salir de aqui algun dia. Unas "
     "gruesas cadenas se encargan de evitar que "+QueryName()+" trate de escapar.\n");
  SetAlign(50);
  SetGoChance(0);
  SetIds(({QueryName(),QueryRace(),(QueryGender()==GENDER_FEMALE?"esclava":"esclavo")}));
  AddQuestion(({"trabajo"}),
    "El trabajo es duro y el clima es desagradable, pero nos dan de comer con "
    "regularidad.\n");
  auxilio=0;
  InitChats(10,({
      QueryName()+" trabaja la tierra con la azada.\n",
      QueryName()+" para un momento y se seca el sudor de la frente.\n",
      QueryName()+" bebe un poco de agua de un cantaro.\n",
      QueryName()+", agotad"+AO2+", descansa un momento.\n"}));
}

public varargs int DoDamage (int damage, int type, int gentle, mixed xtras) {
  object obj;
  if ( auxilio==0 ){
      say("Un guardia acude para proteger a "+QueryName()+".\n");
      obj=clone_object(PNJ("guardia_esclavos"));
      obj->move(environment(TP));
      obj->SetAggressive(1);
      obj->AddEnemies(TO->QueryEnemies());
      obj->SetGoChance(0);
      auxilio=1;
  }
  return ::DoDamage ( damage,  type,  gentle,  xtras);
}
