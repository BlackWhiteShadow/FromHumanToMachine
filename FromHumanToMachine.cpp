/* 
FromHumanToMachine.cpp : Replace the numbers in a string with their binary form.

replaceNums("I have 2 sheep.") ➞ "I have 10 sheep."
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

string bin(int num)
{
    string s;
    while (num)
    {
        s += num % 2 == 0 ? '0' : '1';
        num /= 2;
    }

    reverse(s.begin(), s.end());
    return s;
}

string replaceNums(string str) 
{
    string s, pom = "";
    vector<char> arr;
    copy(str.begin(), str.end(), back_inserter(arr));
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] >= '0' && arr[i] <= '9')
        {
            pom += arr[i];
            s += bin(stoi(pom));
        }
        else
            s += arr[i];

        pom.clear();
    }

    return s;
}

int main()
{
    string str;
    cout << "Enter sentence to transform (press Enter to finish): ";
    cin >> str;

    cout << "Transformed sentence: " << replaceNums(str);
}

