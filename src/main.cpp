#include <iostream>
#include <string>

using namespace std;

template <typename Debug>

void Log(Debug log)
{
    cout << log << endl;
}

int main()
{
    
    int vetor[5];

    for(int i = 0 ; i < sizeof(vetor)/sizeof(vetor[0]) ; i++)
    {
        vetor[i]=i+1;
        Log(vetor[i]);
    }

    Log("exit");

    return 0;
    
}