using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace DoubleSearch
{
    class Program
    {
        static Int64[] mass = new Int64[100000000];
        static long search(long[] arr, long val)
        {
            long m = 0;
            long l = -1;
            long r = arr.Length;
            while (l < r - 1)
            {
                m = l + (r - l) / 2;
                if (val > mass[m])
                {
                    l = m;
                }
                else
                {
                    r = m;
                }
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
            Int64 adr = search(mass, 100000000 - 2);
            s.Stop();
            Console.WriteLine(adr);
            Console.WriteLine(s.ElapsedTicks);
            Console.ReadLine();
        }
    }
}
