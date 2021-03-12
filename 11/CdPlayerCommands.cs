using fh.pk2.devices;

namespace fh.pk2.commands
{
    public class CdStart : Command
    {
        private CdPlayer player;

        public CdStart(CdPlayer player)
        {
            this.player = player;
        }

        public override void execute()
        {
            player.Start();
        }
    }

    public class CdStop : Command
    {
        private CdPlayer player;

        public CdStop(CdPlayer player)
        {
            this.player = player;
        }

        public override void execute()
        {
            player.Start();
        }
    }
}