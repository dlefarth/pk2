using System;
using fh.pk2.rc;
using fh.pk2.commands;
using fh.pk2.devices;

namespace fh.pk2
{
    class Program
    {
        static void Main(string[] args)
        {
            CdPlayer cd = new CdPlayer();
            Garagentor g = new Garagentor();

            RemoteControl rc = new RemoteControl(2);
            rc.SetCommand(0, new CdStart(cd), new CdStop(cd));
            rc.SetCommand(1, new GaragentorHoch(g), new GaragentorRunter(g));

            rc.PressOn(0);
            rc.PressOn(1);

            rc.PressOff(0);
            rc.PressOn(1);
        }
    }
}
