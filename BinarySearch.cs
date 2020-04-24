using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace DoubleSearch
{
    class Program
    {
        static Int64[] mass = new Int64[100000000];
        static Int64 search(Int64 val, Int64 l, Int64 r)
        {
            Int64 m = l + (r - l) / 2;
            if (val > mass[m])
            {
                return search(val, m, r);
            }
            if (val < mass[m])
            {
                return search(val, l, m);
            }
            return m;
        }
        static void Main(string[] args)
        {
            for (Int64 i = 0; i < mass.LongLength; i++)
            {
                mass[i] = i;
            }
            System.Diagnostics.Stopwatch s = new System.Diagnostics.Stopwatch();
            s.Start();
            Int64 adr = search(1, 0, mass.LongLength);
            s.Stop();
            Console.WriteLine(adr);
            Console.WriteLine(s.ElapsedTicks);
            Console.ReadLine();
        }
    }
}
