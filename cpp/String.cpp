//http://myblog.opendocs.co.kr/archives/1334

#include <iostream>
#include <string>
 
using namespace std;
 
int main(void)
{
    // 원본 문자열
    string orgString = "TEST STRING";
     
    cout << "STRING_LENGTH : " << orgString.size() << "\n";
 
    // 대상 문자열 & 복사
    string tarString = orgString;
 
    // 문자열 출력
    cout << "ORG_STRING : " << orgString << "\n";
    cout << "TAR_STRING : " << tarString << "\n";
 
    // 문자열 비교
    if (tarString == orgString){
        cout << "compare \"" << orgString << "\" :::: \"" << tarString << "\" indentical.\n";
    }
    else
    {
        cout << "compare \"" << orgString << "\" :::: \"" << tarString << "\" not indentical.\n";
    }
 
    // 문자열 결합
    string addString = "+ADD STRING";
    addString = orgString + addString;
    cout << "ADD_STRING : " << addString << "\n";
 
    // 문자열 찾기
    int stringIndex = addString.find("+ADD");
    // - 배열과 동일하게 생각하여 +ADD는 12번째 즉, 인덱스 11에 위치한다.
    cout << "FIND_STRING : " << stringIndex << "\n";
 
    // 문자열 자르기
    string cutString = addString.substr(12, 3);
    // - 대상 문자열의 12번째 부터 3자리의 글자를 읽어온다.
    cout << "CUT_STRING : " << cutString << "\n";
 
    return 0;
}