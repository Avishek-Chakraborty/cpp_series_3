#include <iostream>
#include <unordered_map>

int main() {
    std::string s1 = "Amitkkk";
    std::string s2 = "Annik";
    std::unordered_map<char, int> map;

    for (int i = 0; i < s2.length(); i++) {
        char ch = s2[i];
        if (map.find(ch) != map.end()) {
            map[ch]++;
        } else {
            map[ch] = 1;
        }
    }

    int count = 0;

    for (int i = 0; i < s1.length(); i++) {
        char ch = s1[i];
        if (map.find(ch) != map.end()) {
            if (s2[i] == ch) {
                count += 2;
            } else {
                count += 1;
            }
            map[ch]--;
        }
    }

    std::cout << count << std::endl;

    return 0;
}
