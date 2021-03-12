using System;

namespace _12
{
    public class FuhrparkEventArgs : EventArgs
    {
        public Auto Auto { get; }

        public FuhrparkEventArgs(Auto auto)
        {
            this.Auto = auto;
        }
    }

    public delegate void FuhrparkEventHandler(Object sender, FuhrparkEventArgs args);

    public class Fuhrpark
    {
        public event FuhrparkEventHandler FuhrparkEvent;
        LinkedList<Auto> fahrzeuge = new LinkedList<Auto>();

        public void Aufnehmen(Auto a)
        {
            fahrzeuge.Add(a);
            FuhrparkEvent(this, new FuhrparkEventArgs(a));
        }

        public void Inventur()
        {
            Iterator<Auto> it = fahrzeuge.Iterator();

            while (it.HasNext())
            {
                Console.WriteLine(it.Next());
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