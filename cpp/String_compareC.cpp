//http://myblog.opendocs.co.kr/archives/1343
#include <iostream>
#include <string>

using namespace std;
 
int main(void)
{
    char* strCStyle = "TEST STRING";
    string strCppStyle;
 
    // 바로 대입하여 사용가능하다.
    strCppStyle = strCStyle;
    cout << "strcpy : " << strCppStyle << "\n";
 
    // Cstyle과 같은 형태로 접근이 가능하다.
    strCppStyle[0] = 'A';
    cout << "strcpy : " << strCppStyle << "\n";
 
    // string 객체에는 문자열 + 기타 정보를 포함하고 있다.
    // 완전히 동일한 형태의 문자열값을 얻어오기 위해서는 c_str() 를 사용한다.
    const char* strTmp = NULL;
    strTmp = strCppStyle.c_str();
    cout << "strcpy : " << strTmp << "\n";
 
    // string 객체는 길이 제한이 없어 더욱 안정적이다.
    char cString[20];
    string cppString;
     
    // 19자 이상의 문자열을 입력하면 다른 메모리 영역을 덮어버려 심각한 문제가 발생한다.
    // - 악의적인 공격에 사용될 수 있다.
    cin >> cString;
    cout << "cin(C) : " << cString << "\n";
 
    // 길어도 상관없다.
    cin >> cppString;
    cout << "cin(CPP) : " << cppString << "\n";
 
     
    char cStringLine[20];
    string cppStringLine;
 
    // 메모리영역이 덮어지는 문제를 해결하려면 getline 함수를 사용하도록 하자.
    // - getline 함수는 입력된 문자를 20바이트가 넘지 않게 잘라서 저장한다.
    cin.getline(cStringLine, 20);
    cout << "getline(C) : " << cStringLine << "\n";
 
    getline(cin, cppStringLine);
    cout << "getline(CPP) : " << cppStringLine << "\n";
 
    return 0;
}