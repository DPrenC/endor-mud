/*
DESCRIPCION  : Worthe, el banquero
FICHERO      : /d/limbo/comun/pnj/banquero.c
MODIFICACION : 02-10-98 [Angor@Simauria]Creacion
               29-10-99 [Woo] Modificado, ya que no le molaba un clone_object
                        de 0.
--------------------------------------------------------------------------------
*/

#include "./path.h"
#include <properties.h>
#include <combat.h>
inherit NPC;

#define AE      (TP->QueryGender()==GENDER_FEMALE?"a":"e")
#define AO      (TP->QueryGender()==GENDER_FEMALE?"a":"o")
#define A_      (TP->QueryGender()==GENDER_FEMALE?"a":"")
#define NOMBRE  (capitalize(TP->QueryName()))
#define LAEL    (TP->QueryGender()==GENDER_FEMALE?"la":"el")
#define PRON    (TP->QueryGender()==GENDER_FEMALE?"ella":"él")

//nombres de los banqueros
#define N_MAS ({"Tassadar","Gaoran","Farun","Akketon","Nagaoul","Jakko"}) //masculinos
#define N_FEM ({"Alikka","Lerona","Navette","Skara","Shiva","Norina"})    //femeninos

private int    guardias; //numero de guardias de proteccion
private string gfich;    //fichero del guardia

int SetGuardias(int n, string f)
{
    guardias=n;
    gfich=f;
    return 1;
}

//Crea aleatoriamente algunas caracteristicas del banquero
void inicializa()
{
    string bk, *nombres;
    int i, genero;
    //sexo y nombre del pnj
    i=d2();
    if (i==1) genero=GENDER_FEMALE;
    else genero = GENDER_MALE; //50% banqueros/as
    if (genero == GENDER_FEMALE) nombres=N_FEM;
    else nombres=N_MAS;
    bk=nombres[random(sizeof(nombres))];
    SetStandard(bk,"orco",7+d3(),genero);
    SetName(CAP(bk));
    SetShort(CAP(bk)+", "+(genero == GENDER_FEMALE ? "la banquera":"el banquero"));
    SetLong(CAP(bk)+" es "+LAEL+" banquer"+AO+" de este banco. Su tarea es llevar la "
        "sucursal local de la Hermandad de los Banqueros. "+CAP(bk)+" es un"+A_+" orc"+AO+
        " sec"+AO+" y no muy hablador"+A_+" que pasa el día entregad"+AO+" a su trabajo. Su "
        "mirada es fría y distante. Sabes que con "+PRON+" tu dinero estará a salvo.\n");
    AddId(({CAP(bk),bk,"orc"+AO,"banquer"+AO}));
    return;
}

create()
{
    ::create();
    inicializa();
    SetAlign(-1000);
    Set(P_NOGET,QueryName()+" te da un manotazo y dice: 'No me molestes'.\n");
    SetGuardias(0,"");
    InitChats(10,({
        QueryName()+" mira el libro de cuentas y anota alguna cosa en él.\n",
        QueryName()+" comenta para sí: 'Vaya, éste parece que se está haciendo rico'.\n",
        QueryName()+" te dice: 'En los folletos de la caja encontrarás las condiciones del "
            "banco. Yo que tu, cogería uno y lo leería'.\n",
        QueryName()+" murmura: 'Otro préstamo vencido, habrá que tomar medidas'.\n",
        QueryName()+" te mira y te pregunta: '¿Querías alguna cosa?'\n"}) );
}

init()
{
    ::init();
    add_action("matar_cmd","matar");
}


int matar_cmd(){
  object obj;
  int i;
  if (!gfich) return 0;
  if (guardias>0){
     write(QueryName()+" grita pidiendo auxilio: '¡Socorro! ¡A mí la guardia!' "
           "Al momento acuden "+guardias+" en ayuda de "+QueryName()+"\n");
     say(NOMBRE+" ataca a "+QueryName()+" y ést"+AE+" grita pidiendo auxilio. "
         "La guardia acude en su ayuda.\n",TP);

     i=guardias;
     do{
         if(obj=clone_object(PNJ(gfich))) {
          obj->SetAgressive(1);
          obj->SetGoChance(0);
          obj->move(environment(TP));
         }
         i--;
         }while (i>0);
     }
  else{
     write(QueryName()+" grita pidiendo auxilio.\n");
     say(NOMBRE+" ataca a "+QueryName()+" y ést"+AE+" grita pidiendo auxilio.\n",TP);
     };

  return 0;
}
