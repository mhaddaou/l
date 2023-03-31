#include <string>
#include <iostream>
#include <stack>

using namespace std;

void check(stack<int> st,int i, string &s, int &found){
    // if (i + 2 < s.size() && (s[i] == 'A' && s[i + 1] == 'W' && s[i + 2] == 'S')){
    //     s.erase(i, 3);
    //     check()
    // }
    if (i - st.top() - (found * 3) == 2){
        if (s[i] == 'S' && s[i -1] == 'W' && s[i -2] == 'S')
            s.erase(i -3, 3);
        st.pop();        
    }
    else if (i - st.top() - (found * 3) == 1){
        if (s[i] == 'W' && )
    }

}

std::string getFinalString(std::string s) {
    std::stack<int> st;
    int found = 0;
    for (int i = 0; i < s.size(); i++){
        if (i + 1 < s.size() && (s[i] == 'A' && s[i + 1] != 'W'))
            st.push(i);
        else if (i + 2 < s.size() && (s[i] == 'A' && s[i + 1] == 'W' && s[i + 2] == 'S')){
            s.erase(i, 3);
            found++;
            check(st, i + 3, s, found);
        }


    }
    
    return s;
}

int main (){
    string s = "AWAWSSG";
    getFinalString(s);

}