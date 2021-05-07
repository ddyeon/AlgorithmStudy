#include <iostream>
#include <queue>
#include <vector>
#include <math.h>
#include <string.h>
#include <stack>
#include <string>
#include <utility>
#include <algorithm>
#include <set>

using namespace std;
// 문자열 추측 16925
int n;
char arr[200];
vector<string> v, vs;
string p, q;

int check(string s)
{
    vector<string> t;
    set<string> ps;

    //cout << "s" << s << endl;

    for (int i = 1; i < n; i++)
    {

        string pre = s.substr(0, i);
        string suffix = s.substr(n - i, i);
        ps.insert(pre);
        t.push_back(pre);
        t.push_back(suffix);
    } //접두사 접미사 넣기

    sort(t.begin(), t.end());
    if (t == vs)
    {
        cout << s << endl;
        for (int i = 0; i < v.size(); i++)
        {
            if (ps.count(v[i]))
            {
                cout << 'P';
                ps.erase(v[i]);
            }
            else
            {
                cout << 'S';
            }
        }
        return 1;
    }
    return 0;
}

int main()
{
    cin >> n;
    string s;

    for (int i = 0; i < 2 * n - 2; i++)
    {
        cin >> s;
        v.push_back(s);
        if (s.length() == n - 1) //가장긴 길이들의 문자열
        {
            if (p.length() > 0)
                q = s; //baba
            else
                p = s; //abab
        }
    }

    //cout << "p" << p << endl;
    //cout << "q" << q << endl;
    
    
    vs = v;
    sort(vs.begin(), vs.end());

   

    if (p.substr(1, n - 2) == q.substr(0, n - 2)) //한자리 적으니 그 끝 값 n-2
        if (check(p + q[n - 2]))
            return 0;

    check(q + p[n - 2]); //다르면 뒤쪽에 붙여서 확인
}

//set 원소 개수 반환 : s.count(i);
//삽입시 정렬된 위치에 삽입됨.
