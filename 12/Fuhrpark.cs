using System;

namespace _12
{
    public class Fuhrpark
    {
        LinkedList<Auto> fahrzeuge = new LinkedList<Auto>();

        public void Aufnehmen(Auto a)
        {
            fahrzeuge.Add(a);
        }

        public void Inventur()
        {
            Iterator<Auto> it = fahrzeuge.Iterator();

            while (it.HasNext())
            {
                Auto current = it.Next();
                Console.WriteLine(current.Baujahr + " " + current.Hersteller);
            }
        }

        public double BerechneFlottenalter()
        {
            Iterator<Auto> it = fahrzeuge.Iterator();
            int sum = 0;
            int count = 0;

            while (it.HasNext())
            {
                Auto current = it.Next();
                count++;
                sum += current.Baujahr;
            }

            return (double)sum / count;
        }
    }
}