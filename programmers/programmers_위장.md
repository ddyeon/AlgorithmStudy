## 프로그래머스 위장(해시)

&nbsp;
### 🧐문제
스파이들은 매일 다른 옷을 조합하여 입어 자신을 위장합니다.

예를 들어 스파이가 가진 옷이 아래와 같고 오늘 스파이가 동그란 안경, 긴 코트, 파란색 티셔츠를 입었다면 다음날은 청바지를 추가로 입거나 동그란 안경 대신 검정 선글라스를 착용하거나 해야 합니다.
&nbsp;

>입출력

    [["yellowhat", "headgear"], ["bluesunglasses", "eyewear"], ["green_turban", "headgear"]] ->	5
    [["crowmask", "face"], ["bluesunglasses", "face"], ["smoky_makeup", "face"]] ->	3


***
&nbsp;
### 코드
```cpp
#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    unordered_map <string,int> map;
    
    for(int i = 0; i < clothes.size(); i++) {
        map[clothes[i][1]]++;
    }
    
    for(auto it = map.begin(); it !=map.end(); it++) {
        answer *= (it->second+1);
    }
    answer--;
    
    return answer;
}

```
***

&nbsp;

### 👩🏻‍💻풀이 방식
같은 종류의 옷끼리 분류하고 가질 수 있는 조합의 수를 구하는 문제이다. 
`unordered_map`을 이용하여 [옷종류, 개수]를 저장하도록 하였다.
`map`을 사용해도 되지만 정렬이 필요없기 때문에 `unordered_map`을 사용! 
조합의 수를 구하는 방식은 각 종류의 개수+1(안입는 경우를 포함)를 해준 값을 곱하고 마지막에 -1(아무것도 안입는 경우)를 해준다.  
즉, 안경 - 파란안경, 노란 안경  
모자 - 노란 모자, 빨간 모자인 경우  
(2+1)(2+1) -1 를 하면 조합의 수를 구할 수 있다.


### 🕶회고
unordered_map 익숙해지기!!




[위장](https://programmers.co.kr/learn/courses/30/lessons/42578, "baekjoon")
