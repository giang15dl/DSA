#include <iostream>
using namespace std;
    
const int TEST_CASES = 10;
const int MAX_STRING = 300;

const char L[4] = {'{','(','[','<'};
const char R[4] = {'}',')',']','>'};

bool check(char str[], int length);

int main(){
    //FILE *stream;
    //freopen_s(&stream, "p-matching_test_input.txt", "r", stdin);

    for (int i = 0; i < TEST_CASES; i++){
        int length;
        cin >> length;

        char str[MAX_STRING];

        cin >> str;
        
        cout << "#" << i+1 << " " << check(str, length) << endl;
    }
    return 0;
}

bool check(char str[], int length){
    for (int i = 0; i < length; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                if (str[i] == L[j])
                {
                    bool flag = false;
                    for (int k = i+1; k < length; k++)
                    {
                        if(str[k] == R[j])
                        {
                            str[i] = ' ';
                            str[k] = ' ';
                            flag = true;
                            break;
                        }
                    }
                    if(flag == false)
                        return false;
                }
            }
        }
    return true;
}