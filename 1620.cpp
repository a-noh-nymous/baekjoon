#include <iostream>
#include <unordered_map>
#include <cstdio>
#include <cstdlib>

int main() {
    int n, m;

    // scanf로 빠르게 입력 받기
    std::scanf("%d %d", &n, &m);
    
    // 포켓몬 번호 -> 이름 맵
    std::unordered_map<int, std::string> num_to_name;
    // 포켓몬 이름 -> 번호 맵
    std::unordered_map<std::string, int> name_to_num;
    
    // 포켓몬 정보 입력 받기
    for (int i = 1; i <= n; i++) {
        char name[21]; // 이름이 최대 20글자일 것이라고 가정
        std::scanf("%s", name);
        num_to_name[i] = name;
        name_to_num[name] = i;
    }
    
    // 질문 처리
    for (int i = 0; i < m; i++) {
        char query[21]; // 질문도 최대 20글자
        std::scanf("%s", query);
        
        if (query[0] >= '0' && query[0] <= '9') { // 번호로 입력
            int num = std::atoi(query); // 문자열을 정수로 변환
            std::printf("%s\n", num_to_name[num].c_str());
        } else { // 이름으로 입력
            std::printf("%d\n", name_to_num[query]);
        }
    }
    
    return 0;
}
