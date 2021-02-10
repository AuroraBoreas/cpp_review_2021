using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DemoNS
{
    public class Derived : Base
    {
        public new int Number { get; set; } = 12;

        public new void A()
        { Console.WriteLine("Derived class A method"); }

        public override void B(int i)
        => Console.WriteLine("Derived class B method, {0}", ++i);
    }
}
