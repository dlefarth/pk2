using System;

namespace _12
{
    class Program
    {
        static void Main(string[] args)
        {
            Fuhrpark fuhrpark = new Fuhrpark();
            fuhrpark.Aufnehmen(new Auto("Audi", 10));
            fuhrpark.Aufnehmen(new Auto("Porsche", 5));
            fuhrpark.Inventur();
            Console.WriteLine(fuhrpark.BerechneFlottenalter());
        }
    }
}
