/* SIMAURIA '/obj/transporte/tierra/diligencia.c'
   ==============================================
   [w] Woo@simauria
   [h] Nyh@simauria

   Este archivo se hereda por /obj/transporte/diligencia.c
   Si quieres obtener mas ayuda teclea 'man diligencia'

   30-12-97 [w] Creacion de este archivo.
   25-03-98 [w] Comienzo de nuevo ya que lo anterior se FLUSH.
   08-08-98 [w] Instalacion de la primera version de las
                diligencias para su testeo. Falta por terminar
                de implementar el sistema de ataque a la diligencia
                y la posibilidad de saltar de ella en marcha, debido
                a que aun no tengo muy decidido como hacerlo. Pero
                eso es ajeno a vosotros ya que las funciones para su
                uso ya estan implementadas y pueden ser usadas por
                vosotros.
   19-11-98 [w] Resueltos algun que otro bug que andaban pululando por
                este archivo como quien no quiere la cosa. El mas guay
                era que puse un Funcionando++; despues de una sentencia
                en vez de antes.. y lo ejecutaba dos veces.
   20-11-98 [w] Modificado el orden de un tell_object por el cual
                se iba primero la diligencia y luego el conductor
                cerraba las puertas.
   27-11-98 [t] Arregla posiblemente el bug de 'too long evaluation'. El
   		rollo esta en una funcion que hacia 'while (!i) {' y cuando
   		el bucle debia acabar, se hacia un return. Si mal no recuerdo
   		al hacer un bucle y salirse con return, el bucle sigue
   		haciendose hasta los fines, y me parece que me lo dijiste tu,
   		woo. O fue en practicas de Pascal? No macuerdo!!! El caso
   		es que pongo i a 1 y no lo da :I
   		Ahora que lo recuerdo, era en practicas, no se si de pascal,
   		pero el return dentro de un bucle no mola na de na.
   10-12-98 [w] Si te dejas un TP suelto pueden ocurrir locuras.
   15-03-99 [w] Aumentado el random del mensaje de que prosigue el camino.
   29-03-99 [w] Mejorado el código de leer el camino, ahora lo hace unas
                5 veces más rápido. De paso lo he castellanizado y he
                borrado un poquillo de basurita.
   XX-11-04 [h] Me penco los call_outs y lo hago por heart_beats.
                A veces me sorprendo de que el mud funcione.
*/

#include <moving.h>
#include <properties.h>

inherit THING;

/* ############### VARIABLES ############## */

private static string Dnombre;
  // Nombre de la diligencia

private static string Ddesc;
  // Descripcion de la diligencia

private static mixed Dmsg_entrar, Dmsg_salir;
  // Mensajes de entrada y salida de la diligencia
  // ({<mensaje jugador>,<mensaje habitacion>,<mensaje diligencia>})

private static string Dmsg_llega, Dmsg_seva;
  // Mensajes que aparecen en una habitacion cuando llega y se va.

private static string Dhabit;
  // Direccion de la habitacion de la diligencia para los pasajeros

private int Dnum_pasajeros;
  // Numero de pasajeros que pueden viajar (min 2)

private string Dconductor;
  // Path del archivo del conductor

private string NombreConductor;
  // Nombre del conductor

private object cond;
  // Objeto del conductor

private static mixed Dparadas;
  // ({({<habit1>,<tiempespera1>,<coste1>}),({<habit2>,<tiempespera2>,<coste2>}),..})

string destinos;
  // Los nombres de cada uno de los destinos

private string Inicio;

private string Recorrido;         // Contiene el archivo de recorrido.
private mixed NomRec;

private int Funcionando;          // Indica si la diligencia esta en marcha.
private int NumParada;            // Parada en la que esta o la ultima.
private int NumTrayecto;          // Situacion exacta mientras viaja.
private int EnParada;             // Indica si la diligencia esta parada o no.

private mapping Trayecto;
private mapping Atacantes;

private int IrParada();
private int PasajeUsado(object obj);
private int ComprobarViajeros();
_bajar(string str);
_entrar(string str);

/* ############### FUNCIONES SET Y QUERY ############## */

public mixed SetDmensajes_entrar(mixed msg)
// ({<mensaje jugador>,<mensaje habitacion>,<mensaje diligencia>})
{
 if (msg)
  if (stringp(msg))
    msg = ({"sube a la diligencia",
            "entra en la diligencia",
            "Subes a la diligencia"});
  else if( pointerp(msg) || sizeof(msg)<3)
    {
     msg += ({"sube a la diligencia",
              "entra en la diligencia",
              "Subes a la diligencia"})[sizeof(msg)..];
    }
 return Dmsg_entrar = msg;
}

public mixed QueryDmensajes_entrar()
{
 return Dmsg_entrar ||
        ({"sube a la diligencia",
          "entra en la diligencia",
          "Subes a la diligencia"});
}

public mixed SetDmensajes_salir(mixed msg)
// ({<mensaje jugador>,<mensaje habitacion>,<mensaje diligencia>})
{
 if (msg)
  if (stringp(msg))
    msg = ({"baja de la diligencia",
            "baja de la diligencia",
            "Bajas de la diligencia"});
  else if( pointerp(msg) || sizeof(msg)<3)
    {
     msg += ({"baja de la diligencia",
              "baja de la diligencia",
              "Bajas de la diligencia"})[sizeof(msg)..];
    }
 return Dmsg_salir = msg;
}

public mixed QueryDmensajes_salir()
{
 return Dmsg_salir ||
        ({"baja de la diligencia",
          "baja de la diligencia",
          "Bajas de la diligencia"});
}

public string SetDmensaje_llega(string str)
{
 if (str)
  return Dmsg_llega = str||"Llega una diligencia.\n";
}

public string QueryDmensaje_llega()
{
  return Dmsg_llega||"Llega una diligencia.\n";
}

public string SetDmensaje_seva(string str)
{
 if (str)
  return Dmsg_seva = str||"La diligencia sigue su camino y desaparece.\n";
}

public string QueryDmensaje_seva()
{
  return Dmsg_seva||"La diligencia sigue su camino y desaparece.\n";
}

public string SetDnombre(string str)
{
 if (!sizeof(str)) return 0;
 return Dnombre = str;
}

public string QueryDnombre()
{
 return Dnombre || "diligencia";
}

public int SetDnum_pasajeros(int num)
{
 if (num && num>2)
  return Dnum_pasajeros = num;
}

public int QueryDnum_pasajeros()
{
 return Dnum_pasajeros || 2; // Por defecto pueden viajar 2 pasajeros
}

public string QueryDhabitacion()
{
 return Dhabit || "/std/void";
}

public string SetDhabitacion(string habitacion)
{
 habitacion  = resolve_file(habitacion);
 return Dhabit = habitacion;
}

public string SetDestinos(string str)
{
 return destinos = str || "";
}

public string QueryDestinos()
{
 return destinos || "";
}

public string SetNombreConductor(string str)
{
 return NombreConductor = stringp(str)?str:(stringp(NombreConductor)?NombreConductor:"el conductor");
}

public string QueryNombreConductor()
{
 return NombreConductor;
}

public string SetDconductor(string str)
{
 return Dconductor = str || "";
}

public string QueryDconductor()
{
 return Dconductor || "";
}


/* [w] Devuelve los objetos de todos los 'jugadores' que estan dentro de la
 *     habitacion de la diligencia. Con un sizeof(QueryPasajeros()) se puede
 *     saber su numero exacto.
 */
public object *QueryPasajeros()
{
  object *pasajeros;

  pasajeros = ({});

  if (!find_object(Dhabit))
    if(!clone_object(Dhabit))
    {
      write("Error:");
      return 0;
    }

  pasajeros += filter(deep_inventory(find_object(Dhabit)),SF(query_once_interactive));

  return pasajeros;
}

public string SetRecorrido(string str)
{
  return Recorrido = str;
}

public string SetInicio(string str)
{
 return Inicio = str || "/std/void";
}

public string QueryInicio()
{
 return Inicio||"/std/void";
}

public mixed SetParadas(mixed paradas)
{
 return Dparadas = paradas || ({({})});
}

public mixed QueryParadas()
{
 return Dparadas || ({({})});
}

public mapping QueryTrayecto()
{
 return Trayecto||([]);
}

public mapping QueryAtacantes()
{
 return Atacantes||([]);
}

//-----------------------------------------------------------------------------
//
//-----------------------------------------------------------------------------

/* ############### OTRAS FUNCIONES ############## */

public mapping AddTrayecto(string rec, string dir, int espera)
{
  int i;

  if(!rec || !dir) return Trayecto||([]);

  if (!Trayecto) Trayecto = ([]);
  if (!member(Trayecto,rec))
  {
    if(!NomRec) NomRec=({rec});
    else NomRec=NomRec+({rec});
    Trayecto[rec] = m_allocate(0,2);
  }
  i = sizeof(Trayecto[rec]);

  Trayecto[rec][i,0] = dir;
  Trayecto[rec][i,1] = espera;

  return Trayecto;
}

public mapping AddAtacantes(string dir, int porcentaje, varargs string *atac)
{
  int i,j,num_map;

  if(!dir || !porcentaje || !atac) return Atacantes||([]);

  if (!Atacantes) Atacantes = ([]);
  num_map=sizeof(atac)+1;
  if (!member(Atacantes,dir)) Atacantes[dir] = m_allocate(0,num_map);
  i = sizeof(Atacantes[dir]);
  Atacantes[dir][i,0] = porcentaje;
  for(j=1;j<num_map;j++) Atacantes[dir][i,j] = atac[j-1];
  return Atacantes;
}

public LeerRecorrido()
{
 int i,espera;
 string tmp,rec,dir,*file;

 if(!Recorrido) return;
 i=0;
 if (!tmp=read_file(Recorrido)) return 1;
 file=explode(tmp,"\n");

 for(i=0;i<sizeof(file);i++)
 {
  tmp=file[i];
  if(tmp[0]!="#" && sscanf(tmp,"%s#%s#%d",dir,rec,espera)==3)
  {
   if(espera<=0) AddTrayecto(rec,dir,0);
   else AddTrayecto(rec,dir,espera);
  }
 }
}

int Viajando()
{
 if(random(50)>40) tell_room(Dhabit,"La diligencia sigue su camino.\n");

 NumTrayecto++;
 if(NumTrayecto-1>=sizeof(Trayecto[NomRec[NumParada]]))
 {
 if (NumTrayecto-2 >= 0)
  tell_room(Trayecto[NomRec[NumParada]][NumTrayecto-2,0],funcall(QueryDmensaje_seva()));
  NumParada++;
  EnParada++;
  IrParada();
  return 1;
 }

 move_object(TO,Trayecto[NomRec[NumParada]][NumTrayecto-1,0]);
 tell_room(Trayecto[NomRec[NumParada]][NumTrayecto-1,0],funcall(QueryDmensaje_llega()));
 if (NumTrayecto-2 >= 0)
   tell_room(Trayecto[NomRec[NumParada]][NumTrayecto-2,0],funcall(QueryDmensaje_seva()));
 if(Trayecto[NomRec[NumParada]][NumTrayecto,1]>0)
 {
  // lo comento, que ahora va por heart_beat
  //call_out("Viajando",Trayecto[NomRec[NumParada]][NumTrayecto,1]);
  return 1;
 }
 else
 {
  Viajando();//call_out("Viajando");
  return 1;
 }
 return 1;
}

int EmpezarTrayecto()
{
 int proxpar;
 string *dst;

 if(NumParada+1>=sizeof(Dparadas)) proxpar=0;
 else proxpar= NumParada+1;
 dst=funcall(SF(QueryDestinos));

 tell_room(Dparadas[NumParada][0],
   capitalize(QueryNombreConductor())+" cierra las puertas de la diligencia.\n");
 tell_room(Dhabit,
   capitalize(QueryNombreConductor())+" cierra las puertas de la diligencia.\n");
 tell_room(Dhabit,
   capitalize(QueryNombreConductor())+" grita: Proxima parada "
   +capitalize(dst[proxpar])+".\n");
 tell_room(Dparadas[NumParada][0],funcall(QueryDmensaje_seva()));
  EnParada=0;
  NumTrayecto=0;
  set_heart_beat(1); //  Viajando();
  return 1;
}

private int IrParada()
{
 string *dst;

 set_heart_beat(0); // Nos paramos, quito el heart_beat

 dst=funcall(SF(QueryDestinos));
 if(NumParada>=sizeof(Dparadas)) NumParada=0;

 tell_room(Dhabit,
   capitalize(QueryNombreConductor())+" grita: Hemos llegado a "
   +capitalize(dst[NumParada])+".\n");
 tell_room(Dhabit,
   capitalize(QueryNombreConductor())+" abre las puertas de la diligencia.\n");
 tell_room(Dparadas[NumParada][0],funcall(QueryDmensaje_llega()));
 move_object(TO,Dparadas[NumParada][0]);
 ComprobarViajeros();

 call_out("EmpezarTrayecto",Dparadas[NumParada][1]);
 return 1;
}

public void iniciar()
{
 if(!Funcionando)
 {
  Funcionando=1;
  QueryDhabitacion()->AddExit("bajar",SF(_bajar));
  LeerRecorrido();
  move_object(TO,QueryInicio());
  EnParada=1;
  IrParada();
 }
 return;
}

void heart_beat() {
  Viajando();
}

private int ComprobarViajeros()
{
  int i;
  string *dst;
  object *viajeros,*inv;

  viajeros=funcall(QueryPasajeros());
  for(i=0;i<sizeof(viajeros);i++)
  {
    inv=({});
    inv+=filter(deep_inventory(viajeros[i]),SF(PasajeUsado));
    if(sizeof(inv))
    {
      if(    (inv[0]->QueryIDdiligencia()!=Dnombre)
          || (!member(QueryParadas(),inv[0]->QueryDestino())))
      {
        write(capitalize(QueryNombreConductor())+" te dice: ¡¡Hey.. este pasaje no es valido!! Sal de la diligencia.\n");
        inv[0]->remove();
        // command("bajar",viajeros[i]);
        viajeros[i]->move(Dparadas[NumParada][0],M_SPECIAL,funcall(QueryDmensajes_salir()));
      }
      else
      {
        dst=funcall(SF(QueryDestinos));
        if(capitalize(inv[0]->QueryDestino())==capitalize(dst[NumParada]))
        {
          inv[0]->remove(); // [w] Se acabo el viaje.
          write(capitalize(QueryNombreConductor())+" te dice: Ya hemos llegado a tu destino.\n");
          //command("bajar",viajeros[i]);
          viajeros[i]->move(Dparadas[NumParada][0],M_SPECIAL,funcall(QueryDmensajes_salir()));
        }
      }
    }
    else
    {
      write(capitalize(QueryNombreConductor())+" te dice: Hey.. ¿Dónde tienes el pasaje? Sal de la diligencia.\n");
      //command("bajar",TP);
      viajeros[i]->move(Dparadas[NumParada][0],M_SPECIAL,funcall(QueryDmensajes_salir()));
    }
  }
  return 1;
}

private int PasajeUsado(object obj)
{
  return obj->QueryEnUso()?1:0;
}

private int PasajeValido(object obj)
{
 int pas,ori,des,i;
 string *dst;

 if(!obj->QueryPasaje()) return 0; // [w] No es un pasaje
 if(obj->QueryIDdiligencia()!=Dnombre) return 0; // [w] No es un pasaje de esta diligencia
 if(!member(QueryParadas(),obj->QueryDestino()))
 {
  obj->remove();
  return 0; // [w] El destino no es valido
 }
 dst=funcall(SF(QueryDestinos));
 if(capitalize(obj->QueryDestino())==capitalize(dst[NumParada]))
  return 0; // [w] Estas en el destino ya

 for(i=0;sizeof(dst)>i;i++)
 {
  if(capitalize(dst[i])==capitalize(funcall(obj->QueryOrigen())))
   ori=i;
  if(capitalize(dst[i])==capitalize(funcall(obj->QueryDestino())))
   des=i;
  pas=NumParada;
 }
 if(des<ori) des=des+sizeof(Dparadas);
 if(pas<ori) pas=pas+sizeof(Dparadas);

 if(pas>=ori && pas<des) return 1;

 return 0;
}

private int ComprobarPasaje()
{
 object *inv;
 object obj;

 inv=({});
 inv+=filter(deep_inventory(TP),SF(PasajeValido));
 if(sizeof(inv))
 {
  inv[0]->SetEnUso(1);
  return 1;
 }
 return 0;
}


/* ############### FUNCIONES DE COMANDOS ############## */

/* [w] Funcion principal para entrar dentro de la diligencia. Aqui se
 *     comprueba si tienes el pasaje, si es valido o si ya hay mucha
 *     gente dentro de la diligencia.
 */
_entrar(string str)
{

 if(!str || str=="diligencia")
  return notify_fail("A que diligencia quieres subir?\n");

 if((str!=Dnombre) && (str!="diligencia "+Dnombre) &&
    (str!="a la diligencia "+Dnombre) &&
    (str!="a "+Dnombre))
  return notify_fail("Esa diligencia no se encuentra en estos momentos aqui.\n");

 if(!ComprobarPasaje())
  return
    notify_fail(capitalize(QueryNombreConductor())+" te dice: No pretenderas subir sin pasaje, verdad?\n");

 if (sizeof(QueryPasajeros()) >= QueryDnum_pasajeros())
  return
    notify_fail(capitalize(QueryNombreConductor())+" te dice: La diligencia esta llena, tendras que esperar a la siguiente.\n");

 TP->move(QueryDhabitacion(),M_SPECIAL,funcall(QueryDmensajes_entrar()));
 return 1;
}


/* [w] Funcion principal para bajar de la diligencia.
 */
_bajar(string str)
{
 object *inv;

 if(!EnParada)
   return notify_fail("No puedes bajar con la diligencia en marcha, tendras que esperar a la\n"
                      "siguiente parada.\n");

 inv=({});
 inv+=filter(deep_inventory(TP),SF(PasajeUsado));
 if(sizeof(inv))
 {
   write(capitalize(QueryNombreConductor())+" te dice: Espera un momento!!\n");
   write(capitalize(QueryNombreConductor())+" te coge el pasaje y lo modifica.\n");
   write(capitalize(QueryNombreConductor())+" te dice: Gracias, ya puedes bajar.\n");
   inv[0]->SetOrigen(destinos[NumParada]);
   inv[0]->SetEnUso(0);
 }

 TP->move(Dparadas[NumParada][0],M_SPECIAL,funcall(QueryDmensajes_salir()));
 return 1;
}

//-----------------------------------------------------------------------------
// Init, Create
//-----------------------------------------------------------------------------
void init() {
  ::init();
  add_action("_entrar","subir");
}

void create()
{
  ::create();

  "/obj/lib/register"->Register(TO,"DILIGENCIAS");
  SetShort("una diligencia");
  SetLong("Una simple diligencia que recorre Simauria.\n");
  Set(P_NOGET, "No podrias coger eso ni aunque tuvieras la fuerza de 10 gigantes.\n");
  Set(P_NOSELL, "Jejeje.. ¿intentando vender una diligencia?\n");
  SetIds(({"diligencia"}));
  SetDnombre("diligencia");
  SetDhabitacion("/std/void");
  SetNombreConductor("el conductor");
}

// identificadores extra
public int id(string str)
{
    int res;
    if ((res = ::id(str))) return res;
    if (Dnombre && sizeof(str) && LOWER(str) == LOWER(Dnombre)) return 1;
    return 0;
}
