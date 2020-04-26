using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Algs
{
    class Program
    {
        //Сложность O(n) Память O(n+1)
        static long Fib(long n)
        {
            long[] output = new long[n+1];
            output[0] = 0;
            output[1] = 1;
            output[2] = 1;
            for (long i = 3; i <= n; i++)
            {
                output[i] = output[i - 1] + output[i - 2];
            }
            return output[n];
        }
        //Сложность O(n) Память O(n+1)
        static long Fact(long n)
        {
            long[] output = new long[n + 1];
            output[0] = 1;
            for (long i = 1; i <= n; i++)
            {
                output[i] = output[i - 1] * i;
            }
            return output[n];
        }
        static void Main(string[] args)
        {
            Console.WriteLine(Fact(5));
        }
    }
}
