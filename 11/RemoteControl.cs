using System;
using fh.pk2.commands;

namespace fh.pk2.rc
{
    public class RemoteControl
    {
        private Tuple<Command, Command>[] commands;

        public RemoteControl(int keys)
        {
            commands = new Tuple<Command, Command>[keys];
        }

        public void SetCommand(int i, Command on, Command off)
        {
            commands[i] = new Tuple<Command, Command>(on, off);
        }

        public void PressOn(int i)
        {
            commands[i].Item1.execute();
        }

        public void PressOff(int i)
        {
            commands[i].Item2.execute();
        }
    }
}