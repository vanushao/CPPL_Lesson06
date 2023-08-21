#include <iostream>
#include <map>

int main(){
    std::string s = "Hello world!!";
    std::map<char,int> m_in;
    std::multimap<int, char> m_out;

    std::cout << "[IN]: " << s << std::endl;

    for (const auto c : s){
        if (m_in.count(c) == 0){
            m_in[c] = 1;
        }else{
            m_in[c] += 1;
        }
    }

    std::cout << "[OUT]: " << std::endl;
    // for(const auto [key, value] : m_in){
    //     m_out.insert({value, key});
    // }
    for (auto it = m_in.rbegin(); it != m_in.rend(); it++){
        m_out.insert({it->second, it->first});
    }

    for (auto it = m_out.rbegin(); it != m_out.rend(); ++it ){
        std::cout << it -> second << ": " << it -> first << std::endl;
    }

    return 0;
}
