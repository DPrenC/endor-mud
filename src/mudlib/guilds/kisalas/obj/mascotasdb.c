/*=======================================================================*
 |                  <<   Gremio de las Kisalas   >>                      |
 *=======================================================================*
 | [w] Woo@simauria                                                      |
 | [a] Avengelyne@simauria                                               |
 |                                                                       |
 | 24-03-99 [w] Este archivo controlará el ranking de las mascotas. Solo |
 |              controla a las mascotas vivas, cuando muere se elimina   |
 |              de la base de datos. El contenido de la base de datos se |
 |              actualizará cada vez que una mascota grabe sus stats.    |
 *=======================================================================*/

#include "path.h"

#define MASCOTAS_DB    AMAZONA_SAVE("_mascotas")
#define DIR_SAVE       AMAZONA_SAVE("")

#define DB_DATOS       5
#define DB_MASCOTA     0
#define DB_NIVEL       1
#define DB_EDAD        2
#define DB_SEXO        3
#define DB_RAZA        4

mapping db;
// ([kisala:nombre_mascota;nivel;edad])

public void LoadDB()
{
 restore_object(MASCOTAS_DB);
}

public void SaveDB()
{
 save_object(MASCOTAS_DB);
}

public int ModifyDB(string kisala, string mascota, int nivel,
                    int edad, int sexo, string raza)
{
 if (!kisala || kisala=="" || !mascota || mascota=="" ||
     !nivel || !edad || !raza || raza=="")
   return 0;
 kisala=lower_case(kisala);
 if (file_size(DIR_SAVE+kisala+".o")<=0) return 0;
 if (!db) db=m_allocate(0,DB_DATOS);

 db[kisala,DB_MASCOTA]=mascota;
 db[kisala,DB_NIVEL]=nivel;
 db[kisala,DB_EDAD]=edad;
 db[kisala,DB_SEXO]=sexo;
 db[kisala,DB_RAZA]=raza;
 SaveDB();
 return 1;
}

public int DeleteDB(string kisala)
{
 if (!db) return 0;
 kisala=lower_case(kisala);
 m_delete(db,kisala);
 SaveDB();
 return 1;
}

public void create()
{
 if (clonep(TO))
 {
  destruct(TO);
  return;
 }
 seteuid(getuid());
 LoadDB();
}
