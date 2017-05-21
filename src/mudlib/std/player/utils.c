/*
 * SIMAURIA '/std/player/utils.c'
 * ==============================
 */

#include <wizlevels.h>

//#define MODO_PRUEBA // [w] Para que aparezcan mensajes de testeo

#define MAX_HIST 15 // [w] Numero maximo de comandos que contendra el historico

/* ------------------------------------------------------------------
 * VARIABLES
 * ------------------------------------------------------------------
 */

private mixed aliases = ({({}),({})}); // Los alias; en el futuro convertir a mapping

private nosave string *historico;

//-----------------------------------------------------------------------------
// Query / Set
//-----------------------------------------------------------------------------
public mixed *ResetAliases()   { return aliases = ({({}),({})}); }

public mixed *QueryAliases() { return copy(aliases); }
public mixed *SetAliases(mixed *als) {
    ResetAliases();
    if (als && pointerp(als) && sizeof(aliases) == 2)
        aliases = order_alist(als);
    return aliases;
}

public string QueryAlias(string str) {
    int i;
    if ((i=member(aliases[0], str))>-1) {
        return aliases[1][i];
    }
    return 0;

}
public int AddAlias(string str, string cmd) {
    aliases = insert_alist(str, cmd, aliases);
    return 1;
}
public int RemoveAlias(string str) {
    int i, tam;

    if ((i = member(aliases[0], str)) == -1) return 0;
    tam = sizeof(aliases[0]);
    aliases[0] = aliases[0][0..i-1] + aliases[0][i+1..tam];
    aliases[1] = aliases[1][0..i-1] + aliases[1][i+1..tam];
    aliases = order_alist(aliases);
    return 1;
}
public int HasAlias(string str) {
    return member(aliases[0], str)>-1;
}

//-----------------------------------------------------------------------------

public string *QueryHistorico() { return copy(historico); }

/* ------------------------------------------------------------------
 * FUNCIONES SECUNDARIAS
 * ------------------------------------------------------------------
 */

static string HacerAlias (string verbo, string arg)
{
 int i,s,f;
 string cmd, *args, tmp;
 i=0;

 if (!verbo) return 0;

 if ((i=member(aliases[0], verbo))==-1) return 0;
 cmd=aliases[1][i];
 if(arg&&(args=explode(arg, " "))) {
    s=sizeof(args);
    i=s--;
    if(f=sizeof(regexp(({cmd}),"![0-9]*\\*")))
      cmd=STR->string_replace(cmd, "!*", arg);
      arg="";
      while(i--) {
	tmp=cmd;
	if(f) cmd=STR->string_replace(cmd, "!"+(i+1)+"*",implode(args[i..s]," "));
	cmd=STR->string_replace(cmd, "!"+(i+1), args[i]);
	if(!f&&tmp==cmd) arg=" "+args[i]+arg;
    }
      cmd+=arg;
 }
 return cmd;
}

private string HacerHistorico(string verbo, string arg)
{
 int i;
 string s,s2;

 if(!verbo) return 0;
 if((verbo=="historico")||(verbo=="hist")||(verbo=="histórico")) return 0;

#ifdef MODO_PRUEBA
 write("HISTORICO -verbo: #"+verbo+"#  -str: #"+arg+"#\n");
#endif

 if(verbo=="%")
  if (!sizeof(historico)) return 0; // Si no has ejecutado ningun cmd antes
  else return historico[0];
 if(sscanf(verbo,"%%%d",i)!=1) // Si no es algo que sea %<num> inserta el cmd.
 {
  if(sscanf(verbo,"%%%s",s)!=1)
  {
   historico = ({verbo+(arg?" "+arg:"")}) + historico;
   if (sizeof(historico) > MAX_HIST) historico = historico [0..MAX_HIST-1];
   return 0;
  } else
  {
   for(i==0;i<sizeof(historico);i++)
   {
    if(strlen(s)<=strlen(historico[i]))
    {
     s2 = historico[i];
     if(s==s2[0..strlen(s)-1])
      return historico[i];
    }
   }
   return 0;
  }
 }
 if(i<1||i>sizeof(historico)) return 0; // No esta ese numero en el historico, no graba
 return historico[i-1];
}

/* ------------------------------------------------------------------
 * FUNCIONES PRINCIPALES: create
 * ------------------------------------------------------------------
 */

/* ------ CREATE() ------ */
create() {
    historico = ({});
    aliases = aliases ? order_alist(aliases) : ({({}),({})});
}

public string parse_scan(string verbo, string str)
{
 string comando, temp, tmp1, tmp2;

#ifdef MODO_PRUEBA
 write("SCAN -verbo: #"+verbo+"#  -str: #"+str+"#\n");
#endif

 if(!(comando = HacerAlias(verbo,str)))
  if(!(comando = HacerHistorico(verbo,str)))
    comando = verbo+(str?" "+str:"");
  else
  {
   sscanf(comando,"%s %s",tmp1,tmp2);
   if(temp = HacerAlias(tmp1,tmp2))
    comando = temp;
  }
 else
  HacerHistorico(verbo,str);

 return comando;
}
