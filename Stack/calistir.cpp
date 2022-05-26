#include <cstring>
#include <iostream>
using namespace std;
int main()
{
	string a="parrot,owl,sparrow,pigeon,crow";
    char str[50];
	for(int i=0;i<=a.size();i++)
		str[i]=a[i];
    char delim[] = ",";
    cout << "The tokens are:" << endl;
    char *token = strtok(str,delim);
    while (token)
    {
        cout << token << endl;
        token = strtok(NULL,delim);
    }
    return 0;
}