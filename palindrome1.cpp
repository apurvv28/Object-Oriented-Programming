#include<iostream>
using namespace std;

void reverseString(string &str, int start, int end){
    if(start >= end){
        return;
    }
    swap(str[start], str[end]);
    reverseString(str, start+1, end-1);
}
void palindromeCheck(string str){
    string revStr = str;
    reverseString(revStr, 0, revStr.length()-1);
    if(str == revStr){
        cout << str << " is a palindrome." << endl;
    }else{
        cout << str << " is not a palindrome." << endl;
    }
}
int main(){
    string str;
    cout << "Enter a string: ";
    cin >> str;
    palindromeCheck(str);
    return 0;
}