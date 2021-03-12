using fh.pk2.devices;

namespace fh.pk2.commands
{
    public class GaragentorRunter: Command
    {
        private Garagentor garagentor;

        public GaragentorRunter(Garagentor garagentor)
        {
            this.garagentor = garagentor;
        }

        public override void execute()
        {
            garagentor.Runter();
        }
    }

    public class GaragentorHoch: Command
    {
        private Garagentor garagentor;

        public GaragentorHoch(Garagentor garagentor)
        {
            this.garagentor = garagentor;
        }

        public override void execute()
        {
            garagentor.Hoch();
        }
    }
}