/**
 * SIMAURIA '/std/player/soul.c'
 */

#include <config.h>
#include <properties.h>
#include <wizlevels.h>
#include <sounds.h>

private nosave mapping verbos;

static varargs mixed *accion(string v, string str);
static int ver_acciones();

public varargs mixed QueryAttr(string aname, int sc);

string QueryName();
string QueryPronoun();
string QueryPossessive();
string QueryObjective();
string QueryGhost();
string QueryFrog();
int SetFrog(int f);
string QueryRace();

/* Este procedimiento se llama desde move_player_to_start4()
   desde /std/player.c */
void config_soul() {
  if (!mappingp(verbos)) verbos = ([]);

  add_action("hacer","",1);
  add_action("ver_acciones","acciones");
}

qv() {
  if (member(inherit_list(PO),"/std/player/soul.c") >= 0) return verbos;
  return 0;
}

/* ------------------------------------------------------
   LUGAR DONDE VAN SITUADAS LAS FUNCIONES DE LAS ACCIONES
   Deben llamarse todas void ac_<accion>(object JUG, object OBJ)
   asi como estar ordenadas alfabeticamente.
--------------------------------------------------------- */

#define ES_JUG(x)       x->QueryIsPlayer()
#define ES_PNJ(x)       (x->QueryIsNPC() || x->QueryIsPet())
#define EXISTE(x)       interactive(x)
#define PRESENTE(x,y)   present(x,environment(y))
//#define ATACAR(x,y)     x->Kill(y)
#define ATACAR(x,y)     x->DoAttack(y)
#define NOMBRE(x)       (ES_PNJ(x)?x->QueryName():capitalize(x->QueryRealName()))
#define CNOMBRE(x)      (ES_PNJ(x)?capitalize(x->QueryName()):capitalize(x->QueryRealName()))
#define FANTASMA(x)     x->QueryGhost()

// [w] Los pnjs te atacan si les abofeteas.
void ac_abofetear(object JUG, object OBJ)
{
 if (ES_PNJ(OBJ) && PRESENTE(JUG,OBJ) && !FANTASMA(OBJ))
 {
  write(CNOMBRE(OBJ)+" se cabrea ante tu bofetada.\n");
  ATACAR(OBJ,JUG);
 }
  return;
}

void ac_apedrear(object JUG, object OBJ)
{
 if (ES_PNJ(OBJ) && PRESENTE(JUG,OBJ) && !FANTASMA(OBJ))
 {
  write(CNOMBRE(OBJ)+" se lanza a por tí.\n");
  ATACAR(OBJ,JUG);
 }
  return;
}

void ac_aplastar(object JUG, object OBJ)
{
 if (ES_PNJ(OBJ) && PRESENTE(JUG,OBJ) && !FANTASMA(OBJ))
 {
  write(CNOMBRE(OBJ)+" te mira de forma rara y te empieza a atacar.\n");
  ATACAR(OBJ,JUG);
 }
  return;
}

void ac_azotar(object JUG, object OBJ)
{
 if (ES_PNJ(OBJ) && PRESENTE(JUG,OBJ) && !FANTASMA(OBJ))
 {
  write(CNOMBRE(OBJ)+" se enfada ante tus azotes.\n");
  ATACAR(OBJ,JUG);
 }
  return;
}

void ac_capon(object JUG, object OBJ)
{
 if (ES_PNJ(OBJ) && PRESENTE(JUG,OBJ) && !FANTASMA(OBJ))
 {
  write(CNOMBRE(OBJ)+" te comienza a atacar tras tu capón.\n");
  ATACAR(OBJ,JUG);
 }
  return;
}

void ac_colleja(object JUG, object OBJ)
{
 if (ES_PNJ(OBJ) && PRESENTE(JUG,OBJ) && !FANTASMA(OBJ))
 {
  write(CNOMBRE(OBJ)+" suelta unos ruidos raros y te empieza a atacar.\n");
  ATACAR(OBJ,JUG);
 }
  return;
}

void ac_escupir(object JUG, object OBJ)
{
 if (ES_PNJ(OBJ) && PRESENTE(JUG,OBJ) && !FANTASMA(OBJ))
 {
  write(CNOMBRE(OBJ)+" se limpia tu escupitajo y te golpea.\n");
  ATACAR(OBJ,JUG);
 }
  return;
}

void ac_golpear(object JUG, object OBJ)
{
 if (ES_PNJ(OBJ) && PRESENTE(JUG,OBJ) && !FANTASMA(OBJ))
 {
  write(CNOMBRE(OBJ)+" te golpea también.\n");
  ATACAR(OBJ,JUG);
 }
  return;
}

void ac_patear(object JUG, object OBJ)
{
 if (ES_PNJ(OBJ) && PRESENTE(JUG,OBJ) && !FANTASMA(OBJ))
 {
  write(CNOMBRE(OBJ)+" salta a por ti y te golpea.\n");
  ATACAR(OBJ,JUG);
 }
  return;
}

void ac_pisotear(object JUG, object OBJ)
{
 if (ES_PNJ(OBJ) && PRESENTE(JUG,OBJ) && !FANTASMA(OBJ))
 {
  write(CNOMBRE(OBJ)+" te pisa el pie.\n");
  ATACAR(OBJ,JUG);
 }
  return;
}

void ac_vomitar(object JUG, object OBJ)
{
 if (ES_PNJ(OBJ) && PRESENTE(JUG,OBJ) && !FANTASMA(OBJ))
 {
  write(CNOMBRE(OBJ)+" se limpia y te ataca.\n");
  ATACAR(OBJ,JUG);
 }
  return;
}


/* ---------------
   CREATE
   --------------- */

create() {
  if (clonep()) {
    verbos = PLAYER->qv();
    return;
  }
  if (object_name(TO) != PLAYER) return;

/* ---------------------------------------------------------------------
 $ equivale al texto que se va a poner
 @ donde iria el nombre del jugador objetivo
 0 no puede haber jugador objetivo
 1 si que puede haber
 2 si que puede haber pero tiene que estar en la misma habitacion
 3 tiene que haber jugador objetivo
 4 tiene que haber jugador objetivo y estar en la misma habitacion

 Solo los casos 1,2,3,4 en el caso de que hubiera jugador objetivo pueden
 contener una funcion especial. Esta funcion 'solo' se ejecutaria si
 existe un objetivo y tendria que ser de la forma:
       nombre_funcion(object jugador, object objetivo);
 pudiendo ser <objetivo> un PNJ o un jugador.
 Si fuera del caso 0 llevaria obligatoriamente "" en el nombre de la
 funcion, asi como en todos los casos donde no se desee.
--------------------------------------------------------------------- */
  verbos =
  ([

    "abofetear"
         :({"","","levantas la mano y le asestas una soberana bofetada a@$","levanta su mano y te asesta una soberana bofetada$","levanta su mano y le asesta una soberana bofetada a@$",4,"ac_abofetear"}),
    "abrazar"
         :({"","","le das un fuerte abrazo a@$","te da un fuerte abrazo$","le da un fuerte abrazo a@$",4,""}),
    "abrigar"
         :({"","","coges a@ entre tus brazos y le abrigas","te coge entre sus brazos para abrigarte","coge a@ entre sus brazos y le abriga",4,""}),
    "abroncar"
         :({"","","abroncas a@$","te da una bronca$","le da una bronca a@$",3,""}),
    "aburrirse"
         :({"El aburrimiento te abruma","parece aburrirse","","","",0,""}),
    "tumbarse"
         :({"te tumbas en el suelo$","se tumba en el suelo$","","","",0,""}),
    "acusar"
         :({"","","acusas a@$","te acusa$","acusa a@$",3,""}),
    "adornar"
         :({"","","adornas a@ con florecillas de todos los colores","te adorna con florecillas de todos los colores","adorna a@ con florecillas de todos los colores",3,""}),
    "adorar"
         :({"","","te pones de rodillas y empiezas a adorar a@$","se pone de rodillas y empieza a adorarte$","se pone de rodillas y empieza a adorar a@$",3,""}),
    "agacharse"
         :({"te agachas$","se agacha$","","","",0,""}),
    "amar"
         :({"","","amas a@$","te ama$","ama a@$",3,""}),
    "apedrear"
         :({"","","le tiras piedras a@$","te tira piedras$","le tira piedras a@$",3,"ac_apedrear"}),
    "aplastar"
         :({"","","saltas encima de@ y le aplastas$","salta encima tuyo y te aplasta$","salta encima de@ y le aplasta$",4,"ac_aplastar"}),
    "arrodillarse"
         :({"te arrodillas$","se arrodilla$","","","",0,""}),
    "avergonzarse"
         :({"te avergüenzas$","se avergüenza$","","","",0,""}),
    "azotar"
         :({"","","pones a@ sobre tus rodillas y comienzas a darle azotes$","te pone sobre sus rodillas y comienza a darte azotes$","pone a@ sobre sus piernas y comienza a darle azotes$",4,"ac_azotar"}),
    "bailar"
         :({"te pones a bailar$","se pone a bailar$","","","",0,""}),
    "bañarse"
         :({"abres un hueco en el suelo, lo llenas de agua y empiezas a bañarte$","abre un hueco en el suelo, lo llena de agua y empieza a bañarse$","","","",0,""}),
    "besar"
         :({"","","besas a@$","te besa$","besa a@$",3,"", SND_SUCESOS("beso")}),
    "bostezar"
         :({"bostezas$","bosteza$","","","",0,""}),
    "brindar"
         :({"sacas una copa y brindas$","saca una copa y brinda$","sacas una copa y brindas con@$","saca una copa y brinda contigo$","saca una copa y brinda con@$",2,""}),
    "capón"
         :({"","","le das un capón a@$","te da un capón$","le da un capón a@$",3,"ac_capon"}),
    "cagar"
         :({"te pones a cagar$","se pone a cagar$","","","",0,""}),
    "cavar"
         :({"te pones a hacer una zanja$","se pone a hacer una zanja$","","","",0,""}),
    "cantar"
         :({"comienzas a cantar$","comienza a cantar$","le cantas a@$","te canta$","canta a@$",1,""}),
    "carcajada"
         :({"te empiezas a reir y no puedes parar, JUAAJAJAJA...","se empieza a reir y no puede parar, JUAJAJAJA...","","","",0,""}),
    "chocar"
         :({"","","le das la mano a@$","te da la mano$","le da la mano a@$",3,""}),
    "colleja"
         :({"","","le das una colleja a@$","te da una colleja$","le da una colleja a@$",3,"ac_colleja"}),
    "consolar"
         :({"","","consuelas a@$","te consuela$","consuela a@$",3,""}),
    "coquetear"
         :({"empiezas a coquetear con todos$","empieza a coquetear con todos$","intentas coquetear con@$","intenta coquetear contigo$","intenta coquetear con@$",1,""}),
    "cortejar"
         :({"","","le dices a@ lo bonitos que son sus ojos y la hermosura de su pelo","te intenta cortejar diciendote lo bonitos que son tus ojos y la hermosura de tu pelo","intenta cortejar a@ diciendole lo bonitos que son sus ojos y la hermosura de su pelo",3,""}),
    "danzar"
         :({"te pones a danzar$","se pone a danzar$","","","",0,""}),
    "dardo"
         :({"","","le lanzas un dardo de madera a@ y le das en el ojo","te lanza un dardo de madera y te da en el ojo","le lanza un dardo de madera a@ y le da en el ojo",3,""}),
    "deprimir"
         :({"","","intentas deprimir a@$","te intenta deprimir$","intenta deprimir a@$",3,""}),
    "descansar"
         :({"te tumbas y descansas$","se tumba y descansa$","","","",0,""}),
    "desmayarse"
         :({"finges caer al suelo desmayándote$","finge caer al suelo desmayándose$","","","",0,""}),
    "despedir"
         :({"sacas un pañuelo y con lágrimas en los ojos te despides","saca un pañuelo y con lágrimas en los ojos se despide","te despides de@","se despide de ti","se despide de@",1,""}),
    "disimular"
         :({"disimulas$","disimula$","","","",0,""}),
    "donjuan"
         :({"","","susurras romanticamente al oido de@ 'te quiero, te adoro, porque tu eres mi lindo tesoro'","te susurra románticamente al oido 'te quiero, te adoro, porque tu eres mi lindo tesoro'","susurra románticamente al oido de@",3,""}),
//    "dormir"
//         :({"te tumbas en el suelo y entras en un profundo sueño","se tumba en el suelo y entra en un profundo sueño","","","",0,""}),
    "entusiasmo"
         :({"saltas y gritas: SI, SI.. VENGA, VENGA.. CHUPIIIIIII","salta y grita: SI, SI.. VENGA, VENGA.. CHUPIIIIIII","","","",0,""}),
    "eructar"
         :({"eructas$","eructa$","","","",0,""}),
    "escupir"
         :({"escupes$","escupe$","escupes a@$","te escupe$","escupe a@$",1,"ac_escupir"}),
    "espantar"
         :({"","","intentas espantar a@$","te intenta espantar$","intenta espantar a@$",3,""}),
    "excitar"
         :({"","","intentas excitar a@$","te intenta excitar$","intenta excitar a@$",3,""}),
    "fanfarronear"
         :({"Dices: Yo soy mucho más mejor que todos vosotros y además no cometo fallos","dice: Yo soy mucho más mejor que todos vosotros y además no cometo fallos","","","",0,""}),
    "felicitar"
    :({"", "", "felicitas a@$", "te felicita$", "felicita a@$", 3, ""}),
    "fijarse"
         :({"","","te fijas en@$","se fija en ti$","se fija en@$",3,""}),
    "flema"
         :({"arrrgjjjj.. zrrggg... sszzuupppp..","arrrgjjjj.. zrrggg... sszzuupppp... Tiras un flema del siete.","se 'aclara' la garganta y suelta una flema del siete que sale corriendo","","",0,""}),
    "francés"
         :({"","","coges a@ entre tus brazos y le das un beso de los que nunca se olvidan","te coge entre sus brazos y te da un beso de los que nunca se olvidan","coge a@ entre sus brazos y le da un beso de los que nunca se olvidan",3,""}),
    "fruncir"
         :({"frunces el ceño$","frunce el ceño$","le frunces el ceño a@$","te frunce el cenyo$","le frunce el ceño a@$",1,""}),
    "gatear"
         :({"empiezas a gatear$","empieza a gatear$","","","",0,""}),
    "golpear"
         :({"","","golpeas brutalmente a@$","te golpea brutalmente$","golpea brutalmente a@$",4,"ac_golpear"}),
    "gruñir"
         :({"gruñes, grrrrr..$","gruñe, grrrrr..$","gruñes a@ grrrrr..$","te gruñe grrrrr..$","gruñe a@ grrrrr..$",1,""}),
    "guiñar"
         :({"guiñas el ojo","guiña el ojo","guiñas el ojo a@","te guiña el ojo","guiña el ojo a@",1,""}),
    "lamer"
         :({"", "", "Lames a@$", "te lame$", "lame a @$", 3, ""}),
    "levantarse"
         :({"te levantas del suelo","se levanta del suelo","","","",0,""}),
    "ligar"
         :({"","","intentas ligar con@$","intenta ligar contigo$","intenta ligar con@$",3,""}),
    "llorar"
         :({"lloras: Buuaahhhhh!!!!$","llora: Buuaahhhhh!!!!$","lloras en los hombros de@: Buuaahhhhh!!!!$","llora en tus hombros: buuaahhhhh$","llora en los hombros de@: Buuaahhhhhh!!!!$",1,""}),
    "mear"
         :({"te pones a mear$","se pone a mear$","meas a@$","te mea$","mea a@$",1,""}),
    "morder"
         :({"", "", "Muerdes a@$", "te muerde$", "muerde a@$", 3, ""}),
    "morrear"
         :({"","","coges a@ entre tus brazos y le das un beso recorriendo con tu lengua su boca","te coge entre sus brazos y te da un beso recorriendo con su lengua tu boca","coge a@ entre sus brazos y le da un beso recorriendo con la lengua su boca",3,""}),
    "patear"
         :({"","","le das una patada a@$","te da una patada$","le da una patada a@$",4,"ac_patear"}),
    "pensar"
         :({"piensas$","piensa$","","","",0,""}),
    "pisotear"
         :({"","","pisas el pie de@$","te pisa el pie$","pisa el pie de @$",4,"ac_pisotear"}),
    "reir"
         :({"te ríes$","se ríe$","te ríes de@$","se ríe de tí$","se ríe de@$",1,""}),
    "reverencia"
         :({"haces una reverencia$","hace una reverencia$","haces una reverencia a@$","te hace una reverencia$","hace una reverencia a@$",2,""}),
    "rodar"
         :({"ruedas por el suelo mientras te ríes","rueda por el suelo mientras se ríe","","","",0,""}),
    "saludar"
         :({"levantas tu mano y saludas a todos","levanta su mano y saluda a todos","saludas a@","te saluda","saluda a@",1,""}),
    //"sentarse"
         //:({"te sientas$","se sienta$","","","",0,""}),
    "sonreir"
         :({"sonríes$","sonríe$","sonríes a@$","te sonríe$","sonríe a@$",1,""}),
    "sonrojarse"
         :({"te sonrojas$","se sonroja$","","","",0,""}),
    "temblar"
         :({"tiemblas$","tiembla$","","","",0,""}),
    "tontear"
         :({"empiezas a hacer tonterías","empieza a hacer tonterías","","","",0,""}),
    "voltereta"
         :({"das una voltereta$","da una voltereta$","","","",0,""}),
    "vomitar"
         :({"vomitas$","vomita$","vomitas a@$","te vomita$","vomita a@$",1,"ac_vomitar"})
  ]);

}

// [w] *****************************************************************
// [w] ***************** A PARTIR DE AQUI TODO NUEVO **********************

#define EXISTEVERBO(v) (verbos[v])

/* Devuelve el nombre junto con el presay */
static string yo() {
  if (TP->QueryInvis()) return "alguien";
  if (!sizeof(TP->QueryPresay())) return QueryName();
  else return (TP->QueryPresay() + QueryName());
}

/* Contiene las pocas irregularidades que pueden existir
   con respecto al juego de caracteres del jugador */
static string Sust_ac(string str)
{
 if(!str) return str;
 switch(str)
 {
  case "grunyir":   return "gruñir"; break;
  case "capon":     return "capón"; break;
  case "banyarse":  return "bañarse"; break;
  case "guinyar":   return "guiñar"; break;
  case "frances":   return "francés"; break;
 default: return str;
 }
 return str;
}

/* Adecua el texto de salida */
static string compl(string s)
{
 int c;

 c=s[<1];
 if (c!='.' && c!='!' && c!='?') s+=".";
 if (c!='\n') s+="\n";

 return capitalize(s);
}

/* Comprueba si la acción existe y le muestra los posibles mensajes
   que puede tener al jugador */
static int modo_ac(string Maccion)
{
 mixed *datos;
 string msg,tmp1,tmp2;

 Maccion = Sust_ac(Maccion);
 msg="";
 if(!(datos=EXISTEVERBO(Maccion))) return 0;

 msg+="Modo de uso:\n  "+Maccion;
 if (datos[5]==3 || datos[5]==4) msg+=" <objetivo>";
 if (datos[5]==1 || datos[5]==2) msg+=" [<objetivo>]";
 if (sscanf(datos[0],"%s$%s",tmp1,tmp2)==2 || sscanf(datos[2],"%s$%s",tmp1,tmp2)==2)
  msg+=" [<texto adicional>]";
 msg+="\n";

 if(datos[0]!="")
 {
  tmp1=datos[0];
  tmp1=STR->string_replace(tmp1,"@"," <objetivo>");
  tmp1=STR->string_replace(tmp1,"$"," <texto>");
  msg+="Sin Objetivo:\n";
  msg+="  "+capitalize(tmp1)+".\n";
 }
 if(datos[1]!="")
 {
  tmp1=datos[1];
  tmp1=STR->string_replace(tmp1,"@"," <objetivo>");
  tmp1=STR->string_replace(tmp1,"$"," <texto>");
  msg+="  <nick> "+tmp1+".\n";
 }
 if(datos[2]!="")
 {
  tmp1=datos[2];
  tmp1=STR->string_replace(tmp1,"@"," <objetivo>");
  tmp1=STR->string_replace(tmp1,"$"," <texto>");
  msg+="Con Objetivo:\n";
  msg+="  "+capitalize(tmp1)+".\n";
 }
 if(datos[3]!="")
 {
  tmp1=datos[3];
  tmp1=STR->string_replace(tmp1,"@"," <objetivo>");
  tmp1=STR->string_replace(tmp1,"$"," <texto>");
  msg+="  <nick> "+tmp1+".\n";
 }
 if(datos[4]!="")
 {
  tmp1=datos[4];
  tmp1=STR->string_replace(tmp1,"@"," <objetivo>");
  tmp1=STR->string_replace(tmp1,"$"," <texto>");
  msg+="  <nick> "+tmp1+".\n";
 }
 write(msg);
 return 1;
}


/* Dice un texto a todos los jugadores que se encuentran en una
   determinada habitacion, evitando decirselo a los pnjs y al
   jugador que realiza la accion */
static int xdecir(string str)
{
 object *obj;
 int i;

 obj = all_inventory(environment(TP));
 filter(obj, (:interactive($1) && $1 != TP && !$1->CheckIgnored(TNREAL) ? tell_object($1, $2) : 0:), str);
 return 1;
}



/* es como el say, pero evitando a los que ignoran a TP */
private varargs void xsay(string str, object exclude)
{
    filter(all_inventory(environment(TP)),
           (:$1 != TP && $1 != $3 && living($1) && (interactive($1) && !$1->CheckIgnored(TNREAL)) ?
           tell_object($1, $2) : 0:), str, exclude);
}

/* Funcion principal de soul.c, aqui se comprueban los comandos que
   ejecuta el jugador para ver si se trata de un emote y actua en
   consecuencia, devolviendo 0 si comprueba que no lo es */
static int hacer(string str) {
  string v,acc;
  mixed *salida;

  v = query_verb(); /* Todo lo que se introduce antes del primer espacio */

  if(v=="acción") v="accion"; // El member no funciona bien con acentos.
  if (-1!=member(({"accion","ac"}),v) || v[0]=='.')
  {
   /* Los fantasmas y las ranas no pueden hacer emotes de este tipo */
   if(TP->QueryGhost())
   {
    write("No puedes hacer nada en tu estado inmaterial.\n");
    return xdecir(compl(yo()+" flota en el ambiente mientras gime lastimeramente"));
   }
   if(TP->QueryFrog())
   {
    play_sound(environment(TP), SND_PNJS("rana"));
    write("Croakkk.. croakk...\n");
    return xdecir(compl(yo()+" salta y croa a la vez"));
   }

   if (v == "accion" || v == "ac")
   {
     if (!str||str=="?")
      return notify_fail("ac[cción] texto, y aparecerá <tu_nombre texto>.\n"),0;
     if (sscanf(str,"modo %s",acc)==1)
     {
      if (acc=="") return notify_fail("Uso: acción modo <acción>.\n"),0;
      if (!modo_ac(acc)) return notify_fail("Uso: acción modo <acción>.\n"),0;
      return 1;
     }
     else
     {
       write("Ok\n");
       return xdecir(compl(yo()+" "+str));
     }
   }


   if (v[0]=='.')
   {
    if (strlen(v)==1)
       if (!str) return 0;
       else {write("Ok\n"); return xdecir(compl(yo()+" "+str));}
    else {write("Ok\n"); return xdecir(compl(yo()+" "+v[1..<1]+(!str?"":" "+str)));}
   }
  }

  if(TP->QueryGhost())
  {
   write("No puedes hacer nada en tu estado inmaterial.\n");
   return xdecir(compl(yo()+" flota en el ambiente mientras gime lastimeramente"));
  }
  if(TP->QueryFrog())
  {
   play_sound(environment(TP), SND_PNJS("rana"));
   write("Croakkk.. croakk...\n");
   return xdecir(compl(yo()+" salta y croa a la vez"));
  }

  if(salida=accion(v,str))
  {
   if (salida[3])
   {
    if (salida[3]->CheckIgnored(TNREAL))
    // lo ignora
    {
     return notify_fail(NNAME(salida[3]) + " te está ignorando.\n");
    }
    if(!TP->QueryInvis() && !salida[3]->QueryInvis())
        xsay(compl(yo()+" "+salida[1]), salida[3]);
    if(!TP->QueryInvis())
     tell_object(salida[3],compl(yo()+" "+salida[2]));
    else
     tell_object(salida[3],compl("Alguien "+salida[2]));
   }
   else
     if(!TP->QueryInvis()) xsay(compl(yo()+" "+salida[1]));
     else xsay(compl("Alguien "+salida[1]));
   if (salida[4] && salida[4] != "")
   {
    play_sound(environment(TP), salida[4]);
    if (!present(salida[3], environment(TP))) play_sound(salida[3], salida[4]);
   }
   write(compl(salida[0]));
   return 1;
  }
  else return 0;
}

static varargs mixed *accion(string v, string str)
{
 mixed *datos;
 mixed *mensaje;
 int puede;
 string *s;
 string objetivo, NombreObjetivo;
 string str3,texto;
 object obj;
 string str1,str2;

// [w] Aquí se pondrán las ligeras excepciones

 v = Sust_ac(v);

 if(!(datos=EXISTEVERBO(v))) return 0;

 mensaje = allocate(5);

 mensaje[0] = ""; // Mensaje para el jugador
 mensaje[1] = ""; // Mensaje para la habitacion
 mensaje[2] = ""; // Mensaje para el objetivo
 // mensaje[3] es el nombre del jugador.
 if (sizeof(datos) >= 8 && datos[7]) mensaje[4] = datos[7];


 if (!datos[5]) // No puede tener jugador objetivo esa accion
 {
  if (sscanf(datos[0],"%s$%s",str1,str2)!=2) mensaje[0]=datos[0];
  else
    if(!str) mensaje[0]=str1+str2;
    else mensaje[0]=str1+" "+str+str2;

  if (sscanf(datos[1],"%s$%s",str1,str2)!=2) mensaje[1]=datos[1];
  else
    if(!str) mensaje[1]=str1+str2;
    else mensaje[1]=str1+" "+str+str2;
  return mensaje;
 }

 if (datos[5]==1||datos[5]==3)
 {
  if (!str)
  {
   if(datos[5]==3)
     return notify_fail(v+" [objetivo].\n"),0;
   if (sscanf(datos[0],"%s$%s",str1,str2)!=2) mensaje[0]=datos[0];
   else
    mensaje[0]=str1+str2;
   if (sscanf(datos[1],"%s$%s",str1,str2)!=2) mensaje[1]=datos[1];
   else
    mensaje[1]=str1+str2;
   return mensaje;
  }
  s = explode(str," ");
  objetivo = s[0];
  puede=0;

// Comprueba si es un jugador, o si es un npc que esta en la habitacion

  if (obj=find_object(lower_case(s[0])))
   {puede=1;mensaje[3]=obj;NombreObjetivo=capitalize(obj->QueryRealName());}
  else if (obj=present(s[0],environment(TP)))
     if (obj->QueryIsNPC() || obj->QueryIsPet())
      {puede=1;mensaje[3]=obj;NombreObjetivo=obj->QueryName();}

  if (   (obj && !TP->CanSeeObject(obj))
      || (datos[5]==3 && !puede) )
   return notify_fail("No existe nadie con ese nombre.\n"),0;

  if(puede)
  {
   if (sscanf(str,objetivo+" %s",texto)!=1) texto="";
   if (sscanf(datos[2],"%s$%s",str1,str2)!=2) // No permite incluir texto
   {
    if (sscanf(datos[2],"%s@%s",str1,str2)==2)
      mensaje[0]=str1+" "+NombreObjetivo+str2;

    mensaje[2]=datos[3];

    if (sscanf(datos[4],"%s@%s",str1,str2)==2)
      mensaje[1]=str1+" "+NombreObjetivo+str2;

    if(datos[6]!="") call_out(datos[6],2,TP,obj);
    return mensaje;
   }
   if (sscanf(datos[2],"%s@%s$%s",str1,str2,str3)==3)
     mensaje[0]=str1+" "+NombreObjetivo+str2+(texto==""?"":" "+texto)+str3;
   if (sscanf(datos[2],"%s$%s@%s",str1,str2,str3)==3)
     mensaje[0]=str1+(texto==""?"":" "+texto)+str2+" "+NombreObjetivo+str3;

   if (sscanf(datos[3],"%s$%s",str1,str2)==2)
     mensaje[2]=str1+(texto==""?"":" "+texto)+str2;

   if (sscanf(datos[4],"%s@%s$%s",str1,str2,str3)==3)
     mensaje[1]=str1+" "+NombreObjetivo+str2+(texto==""?"":" "+texto)+str3;
   if (sscanf(datos[4],"%s$%s@%s",str1,str2,str3)==3)
     mensaje[1]=str1+(texto==""?"":" "+texto)+str2+" "+NombreObjetivo+str3;

   if(datos[6]!="") call_out(datos[6],2,TP,obj);
   return mensaje;
  }
  if (sscanf(datos[0],"%s$%s",str1,str2)!=2) mensaje[0]=datos[0];
  else
    if(!str) mensaje[0]=str1+str2;
    else mensaje[0]=str1+" "+str+str2;

  if (sscanf(datos[1],"%s$%s",str1,str2)!=2) mensaje[1]=datos[1];
  else
    if(!str) mensaje[1]=str1+str2;
    else mensaje[1]=str1+" "+str+str2;
  return mensaje;
 }

 if (datos[5]==2||datos[5]==4) // Puede haber objetivo pero en la misma habitacion
 {
  if (!str)
  {
   if(datos[5]==4)
     return notify_fail(v+" [objetivo].\n"),0;
   if (sscanf(datos[0],"%s$%s",str1,str2)!=2) mensaje[0]=datos[0];
   else
    mensaje[0]=str1+str2;
   if (sscanf(datos[1],"%s$%s",str1,str2)!=2) mensaje[1]=datos[1];
   else
    mensaje[1]=str1+str2;
   return mensaje;
  }
  s = explode(str," ");
  objetivo = s[0];
  puede=0;

// Comprueba si es un jugador o si es un npc y esta en la habitacion
  if (obj=find_object(lower_case(s[0]))&&present(s[0],environment(TP)))
   {puede=1;mensaje[3]=obj;NombreObjetivo=capitalize(obj->QueryRealName());}
  else if (obj=present(s[0],environment(TP)))
   if (obj->QueryIsNPC() || obj->QueryIsPet())
   {puede=1;mensaje[3]=obj;NombreObjetivo=obj->QueryName();}

  if(datos[5]==4&&!puede)
   return notify_fail("No existe nadie con ese nombre a tu alrededor.\n"),0;

  if (find_object(lower_case(s[0]))&&!puede)
   return notify_fail("No puedes hacer eso si la otra persona no esta en este lugar.\n"),0;
  if(puede)
  {
   if (sscanf(str,objetivo+" %s",texto)!=1) texto="";

   if (sscanf(datos[2],"%s$%s",str1,str2)!=2)
   {
    if (sscanf(datos[2],"%s@%s",str1,str2)==2)
      mensaje[0]=str1+" "+NombreObjetivo+str2;

      mensaje[2]=datos[3];

    if (sscanf(datos[4],"%s@%s",str1,str2)==2)
      mensaje[1]=str1+" "+NombreObjetivo+str2;

    if(datos[6]!="") call_out(datos[6],2,TP,obj);
    return mensaje;
   }


   if (sscanf(datos[2],"%s@%s$%s",str1,str2,str3)==3)
     mensaje[0]=str1+" "+NombreObjetivo+str2+(texto==""?"":" "+texto)+str3;
   if (sscanf(datos[2],"%s$%s@%s",str1,str2,str3)==3)
     mensaje[0]=str1+(texto==""?"":" "+texto)+str2+" "+NombreObjetivo+str3;

   if (sscanf(datos[3],"%s$%s",str1,str2)==2)
     mensaje[2]=str1+(texto==""?"":" "+texto)+str2;

   if (sscanf(datos[4],"%s@%s$%s",str1,str2,str3)==3)
     mensaje[1]=str1+" "+NombreObjetivo+str2+(texto==""?"":" "+texto)+str3;
   if (sscanf(datos[4],"%s$%s@%s",str1,str2,str3)==3)
     mensaje[1]=str1+(texto==""?"":" "+texto)+str2+" "+NombreObjetivo+str3;

   if(datos[6]!="") call_out(datos[6],2,TP,obj);
   return mensaje;
  }
  if (sscanf(datos[0],"%s$%s",str1,str2)!=2) mensaje[0]=datos[0];
  else
    if(!str) mensaje[0]=str1+str2;
    else mensaje[0]=str1+" "+str+str2;

  if (sscanf(datos[1],"%s$%s",str1,str2)!=2) mensaje[1]=datos[1];
  else
    if(!str) mensaje[1]=str1+str2;
    else mensaje[1]=str1+" "+str+str2;
  return mensaje;
 }
 return mensaje;
}

static int ver_acciones()
{
 string *vis;

 vis = sort_array(m_indices(verbos),SF(>));
 write("Acciones que puedes realizar:\n");
 printf("%-78#s\n", implode(vis, "\n"));
 write("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n");
 write("Ademas, si escribes 'acción' 'ac' o '.' podrás hacer por ejemplo:\n");
 write("  acción se tira al suelo --> '<nombre> se tira al suelo'\n");
 write("Puedes ver el modo de uso de una acción poniendo 'acción modo <acción>'.\n");
 return 1;
}
