/*=============================================================*
 |            << GOLDHAI.Crowy [w] Woo@simauria >>             |
 *=============================================================*
 |               Creacion............. 02-11-97                |
 |               Ultima Modificacion.. 20-04-99                |
 |                                                             |
 | NOTA: En este archivo se controlan todas las estadisticas   |
 |       de los npcs muertos por jugadores en la ciudad de     |
 |       Crowy. Los datos los tienes en comun/logs/asesinos.o  |
 |                                                             |
 *=============================================================*/

/* ([nombre:cantidad_muertos;bebes;
            pequenyos;adultos;viejos;ancianos;mujeres;
            guerreros;borrachos;ultima_muerte]) */

#include <properties.h>

#define NDATOS 10
#define NDATOSL 1
#define DATOS DOMAINLOGPATH "goldhai/ASESINOS_CROWY"
#define PD  "/obj/player_dummy"

#define LI_PUNTOS 0

#define AS_MUERTOS 0
#define AS_BEBES 1
#define AS_PEQUENYOS 2
#define AS_ADULTOS 3
#define AS_VIEJOS 4
#define AS_ANCIANOS 5
#define AS_MUJERES 6
#define AS_GUERREROS 7
#define AS_BORRACHOS 8
#define AS_ULT_MUERTE 9

public varargs void CargarAsesinos();
private void CrearTablaAsesinos();

private static int TablaCargada;
private static int TablaCreada;
public mapping asesinos;
public mapping lista;


/* FUNCIONES */

create()
{
    seteuid(getuid());
    // si no, el save_object puede fallar si este objeto no se carga desde goldhai.
}
    public int peligrosidad(string jugador)
{
  int muertos, bebes, pequenyos, adultos, viejos;
  int ancianos, mujeres, guerreros, borrachos;

if(!TablaCargada)
 CargarAsesinos();
if(!TablaCreada)
 CrearTablaAsesinos();


/* Funcion que devuelve nivel de peligrosidad:
   ===========================================
   1.........50  Algo travieso
   51.......100  Travieso
   101......200  Algo peligroso
   201......400  Peligroso
   401......700  Muy peligroso
   701.....1000  Terrible
   1001....1500  Malvado
   1501....2500  Cruel
   2501....5000  Asesino psicopata
   ..... > 5000  Sanguinario
*/
muertos   = asesinos[jugador,AS_MUERTOS];
bebes     = asesinos[jugador,AS_BEBES];
pequenyos = asesinos[jugador,AS_PEQUENYOS];
adultos   = asesinos[jugador,AS_ADULTOS];
viejos    = asesinos[jugador,AS_VIEJOS];
ancianos  = asesinos[jugador,AS_ANCIANOS];
mujeres   = asesinos[jugador,AS_MUJERES];
guerreros = asesinos[jugador,AS_GUERREROS];
borrachos = asesinos[jugador,AS_BORRACHOS];
  return
   muertos+bebes*10+pequenyos*7+adultos*3+viejos*5+ancianos*8+mujeres*3+borrachos*2-guerreros;
}

public int PropSexo(string jugador)
{
 mapping props;

 if (props=PD->QueryProperties(jugador))
    return props[P_GENDER];
 else
    return 1;
}

#define ART(x)  (x==2?"a":"o")

public string str_peligrosidad(int peligro, int sexo)
{
 if (peligro<1) return "buen ciudadano";
 switch(peligro) {
  case          1..50: return "algo travies"+ART(sexo);
  case        51..100: return "travies"+ART(sexo);
  case       101..200: return "algo peligros"+ART(sexo);
  case       201..400: return "peligros"+ART(sexo);
  case       401..700: return "muy peligros"+ART(sexo);
  case      701..1000: return "terrible";
  case     1001..1500: return "malvad"+ART(sexo);
  case     1501..2500: return "cruel";
  case     2501..5000: return "asesin"+ART(sexo)+" psicopata";
 }
 return "sanguinari"+ART(sexo);
}

                                         /* Carga el archivo de Asesinos */
public varargs void CargarAsesinos() {
 if(asesinos) return;
 restore_object(DATOS);
 TablaCargada=1;
}

                                     /* Actualiza el archivo de Asesinos */
public varargs void SalvarAsesinos() {
 save_object(DATOS);
}

                                 /* Crea la tabla de todos los Asesinos */
private void CrearTablaAsesinos() {
 if(asesinos) return;
 asesinos = m_allocate(0,NDATOS);
 TablaCreada=1;
}

                               /* Crea la tabla de la lista de Asesinos */
private void CrearTablaLista() {
 if(lista) return;
 lista = m_allocate(0,NDATOSL);
}


                          /* Comprueba que un Asesino esta en la Tabla */
public int AsesinoPresente(string jugador) {
if(!TablaCargada)
 CargarAsesinos();
if(!TablaCreada)
 CrearTablaAsesinos();
 return member(asesinos,jugador);
}

                /* Graba nuevos valores al producirse una nueva muerte */
public int SetAsesino
          (string jugador, int edad, int sexo, int borracho, int guerrero) {
 if(!jugador) return 0;

 if(!TablaCargada)
  CargarAsesinos();
 if(!TablaCreada)
  CrearTablaAsesinos();

 asesinos[jugador,AS_MUERTOS] = asesinos[jugador,AS_MUERTOS]+1;
 if (edad<5)
   asesinos[jugador,AS_BEBES+edad]=asesinos[jugador,AS_BEBES+edad]+1;
 if (guerrero==1)
   asesinos[jugador,AS_GUERREROS]=asesinos[jugador,AS_GUERREROS]+1;
 if (sexo==2)
   asesinos[jugador,AS_MUJERES]=asesinos[jugador,AS_MUJERES]+1;
 if (borracho==1)
   asesinos[jugador,AS_BORRACHOS]=asesinos[jugador,AS_BORRACHOS]+1;
 asesinos[jugador,AS_ULT_MUERTE]=time();
 SalvarAsesinos();
 return 1;
}

private string VerLista(mixed tmp, int num)
{
 string texto;
 int i;

  texto  ="\n";
  texto += STR->cadjust("ATENCION",78)+"\n";
  texto += STR->cadjust("Esta es la lista de las 10 personas más",78)+"\n";
  texto += STR->cadjust("buscadas de la ciudad de CROWY",78)+"\n";
  texto += STR->cadjust("------------------------------------------------------",78);
 if (num==0) {
  texto += "\n"+STR->cadjust("La lista está vacia, todos son personas respetables",78);
  return texto;
 }
 for(i=0;i<(num>10?10:num);i++)
  texto += "\n"+STR->cadjust("| "+STR->ladjust(tmp[i],13,".")+" "+
           STR->ladjust(str_peligrosidad(peligrosidad(tmp[i]),PropSexo(tmp[i])),20,".")+
           STR->radjust(" "+to_string(asesinos[tmp[i],0]),8,".")+" muertos |",78);
  texto += "\n";
  texto += STR->cadjust("------------------------------------------------------",78)+"\n";
  texto += STR->cadjust("Penaliza más matar a mujeres, bebes, ancianos y borrachos.",78);
  texto += "\n";
 return texto;
}

protected int comparar(string v1, string v2)
{
 int a,b;
 a = peligrosidad(v1);
 b = peligrosidad(v2);

 return (a!=b?(a<b?1:0):-1);
}

public int chequeo(string v1, string v2)
{
 int i;
 return ((i = comparar(v1,v2))!=-1)
        ?i
        :v1>v2;
}

public mixed ordenar(mixed tmp)
{
 return sort_array(tmp,SF(chequeo));
}

public varargs string Listar()
{
 mixed indices;
 int num_ind,i;

 CargarAsesinos();
 num_ind = sizeof(asesinos);
 indices = m_indices(asesinos || ([]));

 indices=ordenar(indices);
 lista=0;
 CrearTablaLista();
 for(i=0;i<(num_ind>10?10:num_ind);i++)
   lista[indices[i],0]=peligrosidad(indices[i]);
 SalvarAsesinos();
 return VerLista(indices,num_ind);
}
