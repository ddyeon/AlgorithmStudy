#include <iostream>
#include <queue>
#include <vector>
#include <math.h>
#include <string.h>
#include <stack>
#include <string>
#include <utility>
#include <algorithm>
//�ĵ��� ����
//https://www.acmicpc.net/problem/9461
//��Ģ �ۼ��غ��� dp[n-2] + dp[n-3] �߰�
//int�� ����, long long�����ؾ���

using namespace std;

int t;
long long dp[101];

long long sum(long long n)
{
    if(n<=1)
        return n;
    else if(dp[n])
        return dp[n];
    else
    {
        return dp[n] = sum(n-2) + sum(n-3);
    }
    
}

int main()
{
    cin >> t;
    
    dp[1]=1;
    dp[2]=1;

    while(t--)
    {
        long long n;
        cin >> n;
        cout << sum(n) << endl;
    }

    return 0;
}
