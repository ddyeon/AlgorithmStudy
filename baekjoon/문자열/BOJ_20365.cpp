#include <iostream>
#include <queue>
#include <vector>
#include <math.h>
#include <string.h>
#include <stack>
#include <string>
#include <utility>
#include <algorithm>

//블로그2
//https://www.acmicpc.net/problem/20365
//문제를원하는 색으로 칠하는법의 최소값

using namespace std;
int n;
string s;
int b,r;



int main()
{
   
   cin >> n >> s; //BBRBRBBR

   if(s[0] == 'B') b++;
   else r++;
    
    for(int i = 1; i< n; i++)
    {
        if(s[i] == 'B' && s[i-1] == 'R') // 현재는 b인데 그전과다ㅡㄹ면
            b++;
        else if(s[i] == 'R' && s[i-1] == 'B')
            r++;
    }

    if(r>=b)
        cout << b+1; //맨처음 칠하고 시작
    else
    {
        cout << r+1;
    }
    

   return 0;
}
