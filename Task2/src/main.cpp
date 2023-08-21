#include <iostream>
#include <set>

int main(){
    std::set<int> out_set;
    int n;
    std::cout << "[IN]:" << std::endl;
    std::cin >> n;
    for (int i=0; i < n; ++i){
        int val;
        std::cin >> val;
        out_set.insert(val);
    }

    std::cout << "[OUT]:" << std::endl;
    for (auto it = out_set.rbegin(); it != out_set.rend(); ++it) {
        std::cout << *it << std::endl;
    }

    return 0;
}