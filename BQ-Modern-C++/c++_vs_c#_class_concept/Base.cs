using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DemoNS
{
    public class Base
    {
        public int Number { get; set; } = 42;

        public void A()
        { Console.WriteLine("Base class A method"); }

        public virtual void B(int i)
        { Console.WriteLine($"Base class B method, {i}"); }
    }
}
