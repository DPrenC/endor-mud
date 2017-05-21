/**
 * /obj/lib/mdtqs.c
 */

#include <properties.h>
#include <files.h>

#define NAME "mdtqs"
#define LONG_NAME "MIDNIGHT DOMAIN TOOL QUERYING SERVER (mdtqs)"
#define VERSION "2.0 RC1"

public string *GetDomains();

/**
 * IsMember(string/object wizard) devuelve 1 si es member de algun dominio
 * IsMember(string/object wizard, dominio) devuelve 1 si es member de dominio
 */
public varargs int IsMember(mixed wizard, string dominio) {
  if (objectp(wizard)) wizard=wizard->QueryRealName();

  if (dominio) {
    return file_size(REGISTERLOGPATH+DOMAINDIR+"/"+dominio+"/members/"+wizard)>0;
  }
  else {
    string *d = GetDomains();
    int i = sizeof(d);
    for (; i--; ) if (IsMember(wizard, d[i])) return 1;
  }

  return 0;
}

public varargs int IsVicelord(mixed wizard, string dominio) {
  if (objectp(wizard)) wizard=wizard->QueryRealName();

  if (dominio) {
    return file_size(REGISTERLOGPATH+DOMAINDIR+"/"+dominio+"/vicelords/"+wizard)>0;
  }
  else {
    string *d=GetDomains();
    int i = sizeof(d);
    for ( ; i--; ) if (IsVicelord(wizard, d[i])) return 1;
  }

  return 0;
}

public varargs int IsLord(mixed wizard, string dominio) {
  if (objectp(wizard)) wizard=wizard->QueryRealName();

  if (dominio) {
    return file_size(REGISTERLOGPATH+DOMAINDIR+"/"+dominio+"/lords/"+wizard)>0;
  }
  else {
    string *d=GetDomains();
    int i = sizeof(d);
    for ( ; i--; ) if (IsLord(wizard, d[i])) return 1;
  }

  return 0;
}

public varargs int IsSomething(mixed wizard, string dominio) {
  return  IsMember(wizard, dominio)
  	   || IsVicelord(wizard, dominio)
  	   || IsLord(wizard, dominio);
}

public int IsDomain(string dominio) {
  return file_size(REGISTERLOGPATH+DOMAINDIR+"/"+dominio)==FSIZE_DIR;
}

//devuelve un entero con el nivel de un wizard en un dominio
public int GetWizDomainLevel(string dominio, mixed wizard) {
  if (objectp(wizard)) wizard=wizard->QueryRealName();
  if (file_size(REGISTERLOGPATH+DOMAINDIR+"/"+dominio+"/lords/"+    lower_case(wizard||""))>0) return LORD;
  if (file_size(REGISTERLOGPATH+DOMAINDIR+"/"+dominio+"/vicelords/"+lower_case(wizard||""))>0) return VICELORD;
  if (file_size(REGISTERLOGPATH+DOMAINDIR+"/"+dominio+"/members/"+  lower_case(wizard||""))>0) return MEMBER;
  return NOTHING;
}

//devuelve los members de un dominio
public string *GetDomainMembers(string dominio) {
  string *files = get_dir(REGISTERLOGPATH+DOMAINDIR+"/"+dominio+"/members/*");
  return files ? files - ({".",".."}) : ({});
}

//devuelve los vicelords de un dominio
public string *GetDomainVicelords(string dominio) {
  string *files = get_dir(REGISTERLOGPATH+DOMAINDIR+"/"+dominio+"/vicelords/*");
  return files ? files - ({".",".."}) : ({});
}

//devuelve los lords de un dominio
public string *GetDomainLords(string dominio) {
  string *files = get_dir(REGISTERLOGPATH+DOMAINDIR+"/"+dominio+"/lords/*");
  return files ? files - ({".", ".."}) : ({});
  ;
}

//devuelve TODOS los miembros (members+vicelords+lords)
public string *GetDomainAllMembers(string dominio) {
  return GetDomainMembers(dominio)+
         GetDomainVicelords(dominio)+
         GetDomainLords(dominio);
}

//devuelve la información de un dominio
public string *GetDomainInfo(string dominio) {
  return explode(implode(get_dir(REGISTERLOGPATH+DOMAINDIR+"/"+dominio+"/members/*"),   " -"), " ")-({".","-.."})
       + explode(implode(get_dir(REGISTERLOGPATH+DOMAINDIR+"/"+dominio+"/vicelords/*"), " +"), " ")-({".","+.."})
       + explode(implode(get_dir(REGISTERLOGPATH+DOMAINDIR+"/"+dominio+"/lords/*"),     " *"), " ")-({".","*.."});
}

//devuelve todos los dominios
public string *GetDomains() {
  return get_dir(REGISTERLOGPATH+DOMAINDIR+"/*")-({".",".."});
}

//obtiene la información de un wizard en todos los dominios
public string *GetWizardInfo(mixed wizard) {
  string *d, *w;
  int i;

  w = ({});
  d = GetDomains();
  if (objectp(wizard)) wizard=wizard->QueryRealName();

  for (i=0; i<sizeof(d); i++) {
    if (member(GetDomainLords(d[i]),     wizard)!=-1) w+=({"*"+d[i]});
    if (member(GetDomainVicelords(d[i]), wizard)!=-1) w+=({"+"+d[i]});
    if (member(GetDomainMembers(d[i]),   wizard)!=-1) w+=({"-"+d[i]});
  }
  return w;
}
