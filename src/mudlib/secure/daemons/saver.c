/* SIMAURIA '/secure/daemons/saver.c'
   [m] maler@simauria
   23-06-03 [m] creacion
*/
#include <magicd.h>
#include <gremios.h>
#include <magia.h>
mapping guilds;
mapping escuela_db;

create(){
	int i,j;
	string *indices,*filelist, file;
	guilds=([]);
	restore_object(MAGICD_FILE);
	if (find_object("maler")) tell_object(find_object("maler"),sprintf("escuela_db=%O.\n",escuela_db));
	indices=m_indices(escuela_db);
	for(i=0;i<sizeof(indices);i++)
	{
		while(sizeof(filelist))
		{
			filelist=get_dir(MAGICD_SPELL_DIR+indices[i]);
			file=filelist[0];
			filelist-=({file});
			if (file[0] != '.')
			{
				file=MAGICD_SPELL_DIR+indices[i]+file;
				for(j=0;j<sizeof(GC_LEGALES);j++)
				{
					if(!guilds[GC_LEGALES[j]]) guilds[GC_LEGALES[j]]=({});
					if(file->QueryCastLevel(GC_LEGALES[j])!=NO_PUEDE)
					guilds[GC_LEGALES[j]]+=({file->QuerySpellName()});
				}
			}
		}
	}
	escuela_db=([]);
	save_object("/secure/daemons/spells");
	return 1;
}