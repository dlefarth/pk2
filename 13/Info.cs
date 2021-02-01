using System;

namespace _12
{
    public class Info
    {
        public Info(Fuhrpark fuhrpark)
        {
            fuhrpark.FuhrparkEvent += Action;
        }

        void Action(Object sender, FuhrparkEventArgs e)
        {
            Console.WriteLine(e.Auto);
        }
    }

}