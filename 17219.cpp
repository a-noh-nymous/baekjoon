#include <iostream>
#include <unordered_map>
#include <string>

int main() {
    int N, M;
    std::cin >> N >> M;
    
    // 웹사이트 이름 -> 비밀번호 매핑
    std::unordered_map<std::string, std::string> password_map;
    
    // N개의 웹사이트 이름과 비밀번호를 입력받아 저장
    for (int i = 0; i < N; ++i) {
        std::string site, password;
        std::cin >> site >> password;
        password_map[site] = password;
    }
    
    // M개의 웹사이트 이름에 대해 비밀번호를 출력
    for (int i = 0; i < M; ++i) {
        std::string site;
        std::cin >> site;
        std::cout << password_map[site] << std::endl;
    }
    
    return 0;
}
