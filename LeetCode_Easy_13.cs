///I - 1
///IV - 4
///V - 5
///IX - 9
///X - 10
///XL - 40
///L - 50
///XC - 90
///C - 100
///CD - 400
///D - 500
///CM - 900
///M - 1000
char[] letters = new char[] { 'I', 'V', 'X', 'L', 'C', 'D', 'M' };
int[] values = new int[] { 1, 5, 10, 50, 100, 500, 1000 };
string[] addonLetters = new string[] { "IV", "IX", "XL", "XC", "CD", "CM" };
int[] addonValues = new int[] { 4, 9, 40, 90, 400, 900 };
string s = Console.ReadLine();

///Парсим это говно
int result = 0;
char last = '1';
int repeatCounter = 0;
bool rev = false;
bool isNeedAdd = false;
if(s.Length == 1)
{
    isNeedAdd = true;
}
foreach (var item in s)
{
    if (last != '1')
    {
        //Если мы уже работали
        if (last != item)
        {
            if(repeatCounter!=0)
            {
                for (int i = 0; i < letters.Length; i++)
                {
                    if (last == letters[i])
                    {
                        result += (repeatCounter) * values[i];
                        break;
                    }
                }
                repeatCounter = 0;
                isNeedAdd = true;
            }
            if ((last == 'I' && (item == 'X' || item == 'V')) || (last == 'X' && (item == 'L' || item == 'C')) || (last == 'C' && (item == 'D' || item == 'M')))
            {
                //IX
                string tmp = last.ToString() + item.ToString();
                for (int i = 0; i < 6; i++)
                {
                    if (tmp == addonLetters[i])
                    {
                        result += addonValues[i];
                        rev = true;
                        break;
                    }
                }
                isNeedAdd = true;
            }
            else
            {
                //MX
                for (int i = 0; i < letters.Length; i++)
                {
                    if (last == letters[i])
                    {
                        result += values[i];
                        break;
                    }
                }
                isNeedAdd = true;
            }
        }
        else
        {
            //MMMM
            //XXXX
            repeatCounter++;
        }
    }
    if (rev)
    {
        last = '1';
        rev = false;
    }
    else
        last = item;
}
if (repeatCounter != 0)
{
    for (int i = 0; i < letters.Length; i++)
    {
        if (last == letters[i])
        {
            result += (repeatCounter+1) * values[i];
            break;
        }
    }
    repeatCounter = 0;
}
else if(isNeedAdd)
{
    for (int i = 0; i < letters.Length; i++)
    {
        if (last == letters[i])
        {
            result += values[i];
            break;
        }
    }
}
Console.WriteLine(result);
Console.ReadLine();