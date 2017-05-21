int main(string str)
{
object target;
object *follow;
   if(!str)
   {
      write("Despistar a quién?\n");
      return 1;
   }
   follow=TP->QueryFollowers();
   if(!sizeof(follow))
    {
      write("Nadie  te está siguiendo.\n");
      return 1;
   }
   if(!present(str,environment(TP)))
   {
      write(""+capitalize(str)+" no está aquí.\n");
      return 1;
   }
   target=present(str,environment(TP));
   if(!living(target))
   {
      write("Eso no te esta siguiendo. No se moverá jamás.\n");
      return 1;
   }
  if(target==TP)
  {
      write("Intentas despistarte a ti mismo, pero no lo consigues.\n");
      return 1;
  }
  if(member(follow, target) == -1)
  {
      write(capitalize(str)+" no te está siguiendo.\n");
      return 1;
  }
  write("Das esquinazo a "+capitalize(str)+".\n");
  tell_object(target,TP->QueryName()+" te ha dado esquinazo.\n");
  tell_room(environment(TP),TP->QueryName()+
            " da esquinazo a  "+target->QueryName()+".\n",
            ({target,TP}));
  TP->RemoveFollower(target);
  return 1;
}
