using System;
namespace MergeSort
{
    public class RecursiveMergeSort
    {
        T[] Merge<T>(T[] left, T[] right) where T : IComparable<T>
        {
            ///Идея реализации:
            ///Берем два значения из первого и второго массива
            ///Меньшее скаладываем в массив-результат и двигаем индекс элемента массива, откуда взяли
            ///И так до момента, пока один из массивов не закончится
            ///Оставшиеся элементы второго массива просто закидываем в массив-результат

            T[] result = new T[left.LongLength + right.LongLength];//Создаем новый массив длинной в общее количество элементов предыдущих массивов
            Int64 leftInd = 0, rightInd = 0, resultInd = 0; // Индексы элементов массивов
            Int64 maxLeftInd = left.LongLength;
            Int64 maxRightInd = right.LongLength;

            while (leftInd < maxLeftInd && rightInd < maxRightInd)
            {
                if (left[leftInd].CompareTo(right[rightInd]) < 0) // left[i] < right[j] - условно говоря
                {
                    result[resultInd] = left[leftInd];
                    resultInd++;
                    leftInd++;
                }
                else
                {
                    result[resultInd] = right[rightInd];
                    resultInd++;
                    rightInd++;
                }
            }

            //Добиваем остатки элементов
            while (leftInd < maxLeftInd)
            {
                result[resultInd] = left[leftInd];
                resultInd++;
                leftInd++;
            }
            while (rightInd < maxRightInd)
            {
                result[resultInd] = right[rightInd];
                resultInd++;
                rightInd++;
            }

            return result;
        }

        public T[] MergeSort<T>(T[] array, Int64 l, Int64 r) where T : IComparable<T>
        {
            if (l == r)
            {
                //Границы сомкнулись - остался один элемент
                return new T[] { array[l] };
            }
            Int64 mid = (l + r) / 2;
            var left = MergeSort(array, l, mid);
            var right = MergeSort(array, mid + 1, r);
            return Merge(left, right);
        }
    }
}

