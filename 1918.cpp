#include <iostream>
#include <stack>

using namespace std;


string peelBracket(string str){
    stack<int> st;
    
    string newStr = str;
    for(int i = 0; i < str.size(); i++){
        if(str[i] == '('){
            st.push(i);
        } else if(str[i] == ')'){
            int ind = st.top();
            st.pop();
            if(ind == 0 && i == str.size()-1){
                newStr = str.substr(1, str.size() - 2);
                //cout << "newStr :" << newStr <<endl ;
            }
        }
    }
    if(newStr == str)
        return newStr;
    else
        return peelBracket(newStr);
}

void convertInfix(string prevstr){
    //cout << "coveret  {" << prevstr << "} ";
    int bracketCounter = 0;
    string str = peelBracket(prevstr);
    int operInd1 = -1;
    int operInd2 = -1;
    

    int i = 0;
    while(i < str.length()){

        if(str.length() == 1){ // operand
            cout << str;
            return;
        } else if(str[i] == '('){
            bracketCounter++;
        }else if(str[i] == ')'){
            bracketCounter--;
        }else if(bracketCounter == 0 ){ // operator
            if(str[i] == '+' || str[i] == '-')
                operInd1 = i;
            else if(str[i] == '*' || str[i] == '/')
                operInd2 = i;
        }
        i++;
    }

    if(operInd1 != -1){
        convertInfix(str.substr(0,operInd1));
        convertInfix(str.substr(operInd1+1, str.length()));
        cout << str[operInd1] ;
    } else if(operInd2 != -1){
        convertInfix(str.substr(0,operInd2));
        convertInfix(str.substr(operInd2+1, str.length()));
        cout << str[operInd2] ;
    }
}

int main()
{
    string str;
    cin >> str;
    
    convertInfix(str);
    return 0;
}