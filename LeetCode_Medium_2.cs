using System;
namespace LeetCode_Medium_2
{
    using System.Linq;
    public class ListNode
    {
        public int val;
        public ListNode next;
        public ListNode(int val = 0, ListNode next = null)
        {
            this.val = val;
            this.next = next;
        }
    }
    public class TestNodes
    {
        public string Rev(string s)
        {
            string stmp = "";
            for (int i = s.Length - 1; i >= 0; i--)
            {
                stmp += s[i];
            }
            return stmp;
        }
        public string Sum(string first, string second)
        {
            //строки изначально перевернутые!!!
            string result = "";
            int next = 0;
            int ind = 0;
            while (ind < first.Length || ind < second.Length)
            {

                int a = 0, b = 0;
                if (ind < first.Length)
                    a = int.Parse(first[ind].ToString());
                if (ind < second.Length)
                    b = int.Parse(second[ind].ToString());

                int res = a + b + next;
                int ost = res % 10;
                next = res / 10;
                result += ost.ToString();
                ind++;
            }
            if (next != 0)
                result += next.ToString();
            return result;
        }
        public ListNode AddTwoNumbers(ListNode l1, ListNode l2)
        {
            #region Standart opinion
            //string first = "";
            //while (true)
            //{
            //    first += l1.val.ToString();
            //    if (l1.next == null)
            //        break;
            //    l1 = l1.next;

            //}
            //first = Rev(first);


            //string second = "";
            //while (true)
            //{
            //    second += l2.val.ToString();

            //    if (l2.next == null)
            //        break;
            //    l2 = l2.next;
            //}
            //second = Rev(second);

            //long res = int.Parse(first) + int.Parse(second);

            //string result = res.ToString();
            ////Console.WriteLine(result);

            //ListNode resultList = new(int.Parse(result[0].ToString()), null);
            //for (int i = 1; i < result.Length; i++)
            //{
            //    ListNode newNode = new();
            //    newNode.next = resultList;
            //    newNode.val = int.Parse(result[i].ToString());
            //    resultList = newNode;
            //}
            //return resultList;
            #endregion
            #region More Smart opinion
            string first = "";
            while (true)
            {
                first += l1.val.ToString();
                if (l1.next == null)
                    break;
                l1 = l1.next;

            }


            string second = "";
            while (true)
            {
                second += l2.val.ToString();

                if (l2.next == null)
                    break;
                l2 = l2.next;
            }

            string result = Rev(Sum(first, second));
            //Console.WriteLine(result);

            ListNode resultList = new(int.Parse(result[0].ToString()), null);
            for (int i = 1; i < result.Length; i++)
            {
                ListNode newNode = new();
                newNode.next = resultList;
                newNode.val = int.Parse(result[i].ToString());
                resultList = newNode;
            }
            return resultList;
            #endregion
        }
    }
}

