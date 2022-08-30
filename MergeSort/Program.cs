using System;

namespace MergeSort // Note: actual namespace depends on the project name.
{
    internal class Program
    {
        static int[] array = { 8, 7, 2222, 3, 4,55,54,32,365,2356,2135,2133,213 };

        static void Main(string[] args)
        { 
            Console.WriteLine("Merge Sort Alg Implementation");

            
            Console.Write("Source data:");
            for (int i = 0; i < array.Length; i++)
            {
                Console.Write(array[i] + " ");
            }
            Console.WriteLine();
            Console.WriteLine("Sorting...");

            #region Merge Sort

            RecursiveMergeSort recursiveMergeSort = new RecursiveMergeSort();
            array = recursiveMergeSort.MergeSort(array, 0, array.LongLength - 1);
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