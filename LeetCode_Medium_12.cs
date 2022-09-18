int num = 0;
num = int.Parse(Console.ReadLine());
// I - 0
// X - 2
// C - 4k
string[] letters = new string[] { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };
int[] values = new int[] { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };
string result = "";

for (int i = 0; i < letters.Length; i++)
{
    while(num >= values[i])
    {
        result += letters[i];
        num -= values[i];
    }
}

Console.WriteLine(result);
Console.ReadLine();