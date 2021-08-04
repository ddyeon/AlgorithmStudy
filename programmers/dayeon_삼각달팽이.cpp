#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n)
{
    vector<int> answer;
    vector<vector<int>> v(n + 1, vector<int>(n + 1));

    int max_num = (n*(n+1)) / 2;
    int top = 1;
    int bottom = n;
    int left = 1;
    int right = 0;
    int num = 1;
    int state = 0;

    while (num <= max_num)
    {
        if(state == 0) // 맨 바깥쪽 위에서 아래
        {
            for(int i = top; i <= bottom; i++)
            {
                v[i][left] = num++;
            }
            top++;
            left++;
            state = 1;
        }
        else if(state == 1) //왼쪽에서 오른쪽
        {
            for(int i = left; i <= bottom-right; i++)
            {
                v[bottom][i] = num++;
            }
            bottom--;
            state = 2;
        }
        else if(state == 2) // 아래에서 위
        {
            for(int i = bottom; i >= top; i--)
            {
                v[i][i-right] = num++;
            }
            right++;
            top++;
            state = 0;
        }

    }

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j<= i; j++)
            answer.push_back(v[i][j]);
    }
    
    return answer;
}