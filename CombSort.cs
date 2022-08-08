using System;

namespace CombSort
{
    class Program
    {
        
        static void Main(string[] args)
        {
            int[] array = { 12, 43, 2, 42, 43563, 212, 532, 543, 1234, 43 };
            Console.WriteLine("Source array: ");
            for (int i = 0; i < array.Length; i++)
            {
                Console.Write(array[i] + " ");
            }
            Console.WriteLine();

            #region CombSort
            double factor = 1.2473309;
            int step = array.Length - 1;
            while(step >= 1)
            {
                for (int i = 0; step + i < array.Length; i++)
                {
                    if(array[i] > array[i+step])
                    {
                        var t = array[i];
                        array[i] = array[i + step];
                        array[i + step] = t;
                    }    
                }
                step = (int)(step / factor);
            }
            #endregion

            Console.Write("Result:");
            for (int i = 0; i < array.Length; i++)
            {
                Console.Write(array[i] + " ");
            }
            Console.WriteLine();
        }
    }
}

