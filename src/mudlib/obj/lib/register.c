/**
 * /obj/lib/register
 *
 * Object to register different objects.
 * Just do SetSaveFile(<file>) in the create of this object.
 */

#include <config.h>

inherit STR;

#define MYNAME "/obj/lib/register"
#define P_LIST "RegisterList" // to temporary store the register list

private static string savefile;
private static string loaded;
private mapping register; // ([<filename>:({<creators>})])

protected string build_file(string s) {
  if (!s) s = savefile || "FOOBAR"; // Small and rough fix... Sique Sep 23 95
  if ( s && s[<2..]==".o") s = s[0..<3];
  if (sizeof(explode(s, "/")) == 1) s = REGISTERLOGPATH + s;
  return s;
}

public varargs void LoadRegister(string s) {
  seteuid(getuid());
  s = build_file(s);

  if (   (!register || loaded!=s)
      && file_size(s+".o")>0) {
      restore_object(s);
  }
  if (!register) register = ([]);
  loaded = s;
  seteuid(0);
}

public varargs void SaveRegister(string s) {
  seteuid(getuid());
  s = build_file(s);
  if (register) save_object(s);
  seteuid(0);
}

public string QueryLoaded() {
  return loaded;
}

public string SetSaveFile(string s) {
  if (object_name(TO) == MYNAME) return 0;
  return savefile = s;
}
public string QuerySaveFile() { return savefile; }

public varargs mapping SetRegister(mapping r, string s) {
  register = r;
  SaveRegister(s);
  return register;
}
public varargs mapping QueryRegister(string s) {
  LoadRegister(s);
  return register||([]);
}

public varargs void Register(mixed ob, string s) {
  status save;
  string creator,fn;

  if (objectp(ob)) {
      fn = object_name(ob);
      ob = blueprint(ob);
  }
  else if (stringp(ob)) {
      fn = ob;
      ob = blueprint(ob);
  }
  else {
      if (object_name(TO) == MYNAME) fn = object_name(PO);
      else fn = object_name(TO);
      ob = blueprint(fn);
  }
  LoadRegister(s);
  if (!member(register, ob)) {
      register[ob] = ({});
      save = 1;
  }
  if (   fn!=ob
      && member(register[ob], creator = blueprint(ob->QueryCreator())) == -1
      && !find_savefile(lower_case(creator[1..]))
      && creator != "/obj/tool/xtool")
  {
      register[ob]+=({creator});
      save = 1;
  }
  if (save) SaveRegister(s);
}

public varargs void RegisterCreator(mixed ob, string s) {
  status save;
  string creator,fn;

  if (objectp(ob)) {
      fn = object_name(ob);
      ob = blueprint(ob);
  }
  else if (stringp(ob)) {
      fn = ob;
      ob = blueprint(ob);
  }
  else {
      if (object_name(TO)==MYNAME)
        fn = object_name(PO);
      else
        fn = object_name(TO);
      ob = blueprint(fn);
  }
  LoadRegister(s);
  if (!member(register,ob)) {
      register[ob] = ({});
      save = 1;
  }
  if (   fn!=ob
      && member(register[ob],creator = blueprint(fn->QueryCreator()))==-1
      && !find_savefile(lower_case(creator[1..]))
      && creator!="/obj/tool/xtool")
  {
      register[ob]+=({creator});
      save = 1;
  }
  if (save) SaveRegister(s);
}

public void register(mixed ob) { // Compat.
  Register(ob);
}

public varargs void RemoveEntry(mixed ob, string s) {
  if (objectp(ob)) ob = blueprint(ob);
  if (!stringp(ob)) return;
  LoadRegister(s);
  m_delete(register,ob);
  SaveRegister(s);
}

public varargs string *ClearEntries(string s) {
  string *idx,*removed;
  int i;

  LoadRegister(s);
  i = sizeof(idx = m_indices(register));
  removed = ({});
  while(i--) if (file_size(idx[i]+".c")<0) {
    RemoveEntry(idx[i],s);
    removed+=({idx[i]});
  }
  return removed;
}

protected string list_strings(string *arr) {
  if (!sizeof(arr)) return "<none>";
  return implode(arr[0..<2],", ")+
         (sizeof(arr)>1?" and ":"")+arr[<1];
}

protected void message(string msg) {
  object pl;
  if (  !TP
      ||TP->QueryEarmuffs()
      ||TP->QueryNetdead())
    return;
  write(msg);
}

// copyfile taken from /std/player/filesys.c
protected int copyfile(string src, string dst) {
  int fpos, todo, chunk;
  string data;

  seteuid(getuid());
  todo = file_size(src);
  fpos = 0;
  while (todo > 0) {
      chunk = todo;
      if (chunk > 10000) chunk = 10000;
      data = read_bytes (src, fpos, chunk);
      fpos += chunk;
      todo -= chunk;
      if (!write_file(dst, data)) return 0;
  }
  seteuid(0);
  return 1;
}

protected string adjust_info(string str) {
  return implode(map(explode(str,"\n"),
    lambda(({SYM(s)}),({SF(+),"       ",SYM(s)}))),"\n");
}

public varargs void PrintList(string s, string file, closure fun,
                              mapping remaining, string *idx, int pos)
// Output may be redirected to <file>
// fun will be called to get additional info; if fun returns 0
//   the entry will be removed
// remaining is only for internal use
{
    status clones;
    if (!TP||TP->QueryNetdead()) return;
    if (!remaining) {
        LoadRegister(s);
        remaining = register;
        idx = sort_array(m_indices(remaining),SF(>));
        pos = 0;
    }
    clones = sizeof(m_values(remaining)-({({})}))>0;
    while(   get_eval_cost() > 100000
          && pos < sizeof(idx)
         )
    {
        string extrainfo,text;
        extrainfo = 0;
        if (file_size(idx[pos]+".c")<0) RemoveEntry(idx[pos],s);
        else if (fun) {
	      if (!extrainfo = funcall(fun,idx[pos],pos==sizeof(idx)-1))
                RemoveEntry(idx[pos],s);
	      else
	        extrainfo = adjust_info(extrainfo);
	    }
        else extrainfo = "";
        if (clones)
          text = wrap(radjust(to_string(pos+1),3)+". "+
                      idx[pos]+": "+list_strings(remaining[idx[pos]])+"\n",
                      0,strlen(idx[pos])+2)
	         +(extrainfo||"  (removed)")+"\n";
        else
          text = radjust(to_string(pos+1),3)+". "+idx[pos]+
                 (!extrainfo?": removed\n":"")+
                 (extrainfo?extrainfo==""?"\n":":\n"+extrainfo+"\n":"");
        if (file) {
          message(radjust(to_string(pos+1),3)+"/"+
                    radjust(to_string(sizeof(idx)),3)+" "+idx[pos]+"\n");
          seteuid(getuid());
	      write_file(file+"."+getuid(TP),text);
          seteuid(0);
	    }
        else write(text);
        pos++;
    }
    if (pos<sizeof(idx))
        call_out(SF(PrintList),2,s,file,fun,remaining,idx,pos);
    else {
        write("Register-action finished.\n");
        if (file) {
            seteuid(getuid());
      	  rm(file);
            seteuid(0);
	        copyfile(file+"."+getuid(TP),file);
            seteuid(getuid());
            rm(file+"."+getuid(TP));
            seteuid(0);
            write("Results can be found in "+file+".\n");
        }
    }

}

public void create() {
  if (clonep()) destruct(TO);
}
