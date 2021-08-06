#include <string>
#include <vector>

using namespace std;

int solution(vector<int> a, vector<int> b)
{
    int answer = 1234567890;

    int value = 0;
    for(int i = 0; i <a.size(); i++)
    {
        value += a[i]*b[i];
    }

    answer = value;
    return answer;
}