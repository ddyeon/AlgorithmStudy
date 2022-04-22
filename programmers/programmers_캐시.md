## 프로그래머스 2018 kakao 캐시

&nbsp;
### 🧐문제
지도개발팀에서 근무하는 제이지는 지도에서 도시 이름을 검색하면 해당 도시와 관련된 맛집 게시물들을 데이터베이스에서 읽어 보여주는 서비스를 개발하고 있다.
이 프로그램의 테스팅 업무를 담당하고 있는 어피치는 서비스를 오픈하기 전 각 로직에 대한 성능 측정을 수행하였는데, 제이지가 작성한 부분 중 데이터베이스에서 게시물을 가져오는 부분의 실행시간이 너무 오래 걸린다는 것을 알게 되었다.
어피치는 제이지에게 해당 로직을 개선하라고 닦달하기 시작하였고, 제이지는 DB 캐시를 적용하여 성능 개선을 시도하고 있지만 캐시 크기를 얼마로 해야 효율적인지 몰라 난감한 상황이다.

어피치에게 시달리는 제이지를 도와, DB 캐시를 적용할 때 캐시 크기에 따른 실행시간 측정 프로그램을 작성하시오.


&nbsp;

>입력 
    
    캐시 크기(cacheSize)와 도시이름 배열(cities)을 입력받는다 .cacheSize는 정수이며, 범위는 0 ≦ cacheSize ≦ 30 이다.
    cities는 도시 이름으로 이뤄진 문자열 배열로, 최대 도시 수는 100,000개이다.  
    각 도시 이름은 공백, 숫자, 특수문자 등이 없는 영문자로 구성되며,   대소문자 구분을 하지 않는다. 도시 이름은 최대 20자로 이루어져 있다. 

>출력

    입력된 도시이름 배열을 순서대로 처리할 때, "총 실행시간"을 출력한다.

>조건

    캐시 교체 알고리즘은 LRU(Least Recently Used)를 사용한다.  
    cache hit일 경우 실행시간은 1이다.  
    cache miss일 경우 실행시간은 5이다.

***
&nbsp;
### 코드
```cpp
#include <string>
#include <vector>
#include <deque>
using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    deque <string> dq;

    for(int i = 0; i < cities.size(); i++) {
        string city = cities[i];
        bool hit = false; //hit인지 miss인지 파악
        
        for (int j = 0; j < city.length(); j++) {
            city[j] = tolower(city[j]);
        }
        
        int idx = 0;
        for(idx=0; idx < dq.size(); idx++) {
            if(dq[idx] == city) {
                hit = true;
                break;
            }
        }
        dq.push_back(city);
        
        //기존에 있다면 
        if(hit) {
            dq.erase(dq.begin() + idx);
            answer+=1;      
        }
        else {
            if(dq.size() > cacheSize) dq.pop_front();
            answer += 5;
        }
    }
    
    return answer;
}
```
***

&nbsp;

### 👩🏻‍💻풀이 방식
LRU 알고리즘 방식으로 캐시되기 때문에 LRU에 대한 지식이 있어야 한다.  
LRU알고리즘이란?
- 가장 오랫동안 참조되지 않은 페이지를 교체하는 방법이다. 
`deque`를 이용해서 문제를 풀었다. 
우선 **Hit**인지 **miss**인지에 따라 점수가 달라지기 때문에 이를 구분해줘야 한다.
1. 현재의 city를 deque에 넣어주는데, 이떄 `이미 존재하는지 없는지` 확인해준다.  
2. 만약 `있다면` 현재 city를 맨 뒤에 넣어주고 기존에 있던 데이터를 삭제한다.  
3. 만약 `없다면` 두가지 경우로 나뉘어진다. 캐시의 크기가 `꽉 차있는 경우`와 `아직 차지 않은 경우`이다.    
4. `꽉찬경우` 라면, 맨 앞에 있는 데이터가 가장 오랫동안 참조되지 않은 데이터이므로 pop_font()해주고, 맨 뒤에 현재 city값을 삽입한다.  
5. `공간이 있다면`, 맨 뒤에 넣어준다.  



### 🕶회고
LRU알고리즘을 공부하고 문제를 접근하니 쉽게 접근할 수 있었다.
Deque랑 좀 더 친해지기~!

[캐시](https://programmers.co.kr/learn/courses/30/lessons/17680, "programmers")
