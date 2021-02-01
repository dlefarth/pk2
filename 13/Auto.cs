namespace _12
{
    public class Auto
    {
        public Auto(string hersteller, int alter)
        {
            this.Hersteller = hersteller;
            this.alter = alter;
        }

        private int alter;
        public string Hersteller { get; set; }
        public int Baujahr
        {
            get
            {
                return 2021 - alter;
            }
            set
            {
                alter = 2021 - value;
            }
        }

        public override string ToString()
        {
            return this.Baujahr + " " + this.Hersteller;
        }
    }
}