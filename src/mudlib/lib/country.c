/* SIMAURIA '/lib/country.c'
   =========================
   Woo@simauria

   01-02-97 [w] Modificado ligeramente..
   10-04-98 [w] Bueno, os explico los cambios que he realizado. La forma
                de funcionar es sencilla, existe un archivo llamado
                /lib/ciudades.list en el que estan muchas direcciones
                ip con sus respectivas ciudades y pais. Con ese archivo
                se crea una tabla 'hash' desde donde se leeran los datos
                para averiguar el lugar desde el que alguien llama. Si no
                existe la tabla 'hash' muchas cosas NO funcionaran, asi
                que procurar no tocarla demasiado. Para crearla basta con
                un simple 'xcall /lib/country->create_hash_file()' y la
                escribira en /log/ciudades.hash, ese archivo si esta
                bien lo moveis a /lib/ y ya esta.
                Se podria guardar el archivo en /lib/ directamente pero
                lo he hecho asi por el simple motivo de que es un archivo
                bastante fundamental, y cualquier wiz podria andar creandolo
                e imaginaos que una de las veces hay un problema y se queda
                a mitad hacer, o yo que se.. inutilizamos parte del mud.
                Asi no prob.. solo gods y archs pueden machacar el antiguo
                ademas.. los wizs no pueden modificar el ciudades.list por
                lo tanto.. ?de que les sirve crear otra tabla hash igual?
                Mas cosas, ahora como muestra 'ciudad y pais' viene el
                problema de que en la lista de ips no estan todas, por lo
                tanto si entra alguno y veis 'Desconocida' pues le
                averiguais su ip, si es fija (universidades y centros) y
                desde que sitio llama, y lo anyadis a ciudades.list y
                volveis a crear la tabla hash.
                Si llama desde infovia (CTV, ARRAKIS, etc..) con lo cual
                la ip varia y ademas, esa ip puede ser de valencia, castellon
                o otro lugar,.. anyadirlo a la lista como 'Espanya'.
*/

#include "./german_country.h"
#define HASH_FILE "/lib/ciudades.hash"
#define LIST_FILE "/lib/ciudades.list"
#define HASH_SIZE 499

// Descomentar esta linea para logear las IPs no resueltas
// Aviso que genera cantidad de logs (y por ello se ha desactivado)
//#define LOG_UNRESOLVED_IPS

public varargs string country(mixed ip, int flag);

private mapping cache = ([]);

public void create() {
  seteuid(getuid());
}

private int hash(int x) {
  return (x & 0x7fffffff) % HASH_SIZE;
}

private int inet_addr(string ipnum) {
  int a, b, c, d;

  sscanf(ipnum, "%d.%d.%d.%d", a, b, c, d);
  return (a << 24) | (b << 16) | (c << 8) | d;
}

public int create_hash_file() {
  string *lfile, *hfile, ipnum, city, country;
  int s, h, addr;

  lfile = regexp(explode(read_file(LIST_FILE), "\n"), "^[^#].*: .*, .*");
  s = sizeof(lfile);
  hfile = map(allocate(HASH_SIZE), lambda(0, ""));
  while (s--) {
    sscanf(lfile[s], "%s: %s, %s", ipnum, city, country);
    h = hash(addr = inet_addr(ipnum));
    hfile[h] = sprintf("%s%08x:%s, %s#", hfile[h], addr, city, country);
  }

  return log_file("ciudades.hash", implode(hfile, "\n")),1;
}

private string get_name(string pre, string name)
{
  string tmp;

  if(!name)
    return 0;
  if(tmp = KNOWN_NAMES[name])
    return tmp;
  if(name[0..strlen(pre)-1] == pre)
    name = name[strlen(pre)..];
  else return 0;
  switch(name) {
    // Special kind of spelling
  case "frankfurt":
    name = "Frankfurt/Main";
  case "frankfurt-o":
    name = "Frankfurt/Oder";
  case "muenchen":
    name = "Munich";
  case "koeln":
    name = "Cologne";
  }
  return capitalize(name) + ", Alemania";
}

public string resolve_ip_name(string name)
{
  string *parts, *country, tmp;

  if(!name)
    return 0;
  name = lower_case(name);
  if(name == "localhost" || name == __HOST_NAME__)
    return "Valencia, España";
  if((parts = explode(name,"."))[<1] != "de")
    return 0;
  if(sizeof(parts) > 2 && parts[<2] == "netsurf")
    return capitalize(parts[<3]) + ", Germany";
  country = map(PREFIXES,SF(get_name),parts[<2]) - ({0});
  if(sizeof(country))
    return country[0];
  return "Desconocida";
}

public string resolve_ip_number(mixed ip) {
  int mask, pos, addr;
  string str, key;
  int cont;

  if(!ip)
    return "Desconocida";

  addr = inet_addr((objectp(ip) ? query_ip_number(ip) : ip) || "");

  if(!addr)
    return "Desconocida";

  mask = -1;
  do {
    if (str = cache[addr & mask])
      return str;
  } while (mask <<= 8);

  if(str)
    return cache[addr] = str;

  mask = -1;
  cont=0;
  do {
    cont++;
    str = read_file(HASH_FILE, hash(addr) + 1, 1);
    key = sprintf("%08x:", addr);
    if(!str) return "Desconocida";
    if ((pos = strstr(str, key)) >= 0) {
      pos += strlen(key);
      str = str[pos..member(str[pos..], '#') - 1 + pos];
      return cache[addr & mask] = str;
    }
  } while (addr &= (mask <<= 8));

#ifdef LOG_UNRESOLVED_IPS
  log_file("UNRESOLVED", ctime(time()) + " uid= " +
	   (objectp(ip) ? getuid(ip) : "?") + "\n" +
	   (objectp(ip) ? ("  ipname= " + query_ip_name(ip) +
			   " ipnumber= " + query_ip_number(ip)) :
	    "  ipnumber= " + ip) + "\n");
#endif

  return "Desconocida";
}


public varargs string country(mixed ip, int flag) {
  string str;

  if(!ip)
   return "Desconocida";

  str = (objectp(ip) ? query_ip_number(ip) : ip) || "";
  str = resolve_ip_number(ip);
  if (flag)
   sscanf(str, "%s, %s", str, str);
  return str;
}
