/*
Given an integer n, using phone keypad find out all the possible strings that can be made using digits of input n.
Return empty string for numbers 0 and 1.
Note : The order of strings are not important.
Input Format :

Integer n

Output Format :

All possible strings in different lines

Constraints :
1 <= n <= 10^6
Sample Input:

23

Sample Output:

ad
ae
af
bd
be
bf
cd
ce
cf

*/


#include <string>
using namespace std;

int solution(int,string[],string[]);

int keypad(int num, string output[])
{
    /* Insert all the possible combinations of the integer number into the output string array. You do not need to
    print anything, just return the number of strings inserted into the array.
    */
    string s = "abcdefghijklmnopqrstuvwxyz";
    string alphabets[10];
    int j = 0;
    for(int i =2;i<10;i++)
    {
        if ( i != 7 && i!= 9)
        {
            alphabets[i] = s.substr(j,3);
            j += 3;
        }
        else
        {
            alphabets[i] = s.substr(j,4);
            j += 4;
        }
    }
     int ans = solution(num,output, alphabets);
     return ans;
}

int solution(int num, string output[],string letters[])
{
    if(num <=0)
    {
        return 1;
    }
    int smallsolution = solution(num/10,output,letters);
    int count = smallsolution;
    string s = letters[num%10];
    for(int i =0;i<s.length()-1;i++)
    {
        for(int j=0;j<smallsolution;j++)
        {
            output[count] = output[j];
            count++;
        }

    }
    int indx=0;
    for (int j = 0;j<s.length();j++)
    {
        for(int i = 0;i<smallsolution;i++)
        {
            output[indx ++] +=  s[j] ;
        }
    }
    return count;

}




//Another solution which doensn't store it 



#include <string>
using namespace std;

int solution(int,string[],string[]);

int keypad(int num, string output[])
{
    /* Insert all the possible combinations of the integer number into the output string array. You do not need to
    print anything, just return the number of strings inserted into the array.
    */
    string s = "abcdefghijklmnopqrstuvwxyz";
    string alphabets[10];
    int j = 0;
    for(int i =2;i<10;i++)
    {
        if ( i != 7 && i!= 9)
        {
            alphabets[i] = s.substr(j,3);
            j += 3;
        }
        else
        {
            alphabets[i] = s.substr(j,4);
            j += 4;
        }
    }
     int ans = solution(num,output, alphabets);
     return ans;
}

int solution(int num, string output[],string letters[])
{
    if(num <=0)
    {
        return 1;
    }
    int smallsolution = solution(num/10,output,letters);
    int count = smallsolution;
    string s = letters[num%10];
    for(int i =0;i<s.length()-1;i++)
    {
        for(int j=0;j<smallsolution;j++)
        {
            output[count] = output[j];
            count++;
        }

    }
    int indx=0;
    for (int j = 0;j<s.length();j++)
    {
        for(int i = 0;i<smallsolution;i++)
        {
            output[indx ++] +=  s[j] ;
        }
    }
    return count;

}

