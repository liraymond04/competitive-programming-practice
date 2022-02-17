#include <iostream>
#include <string>
#include <vector>

using namespace std;


void hanoi(int n, const string& src, const string& dest, const string& aux) {
    if (n == 1) {
        cout << src << " -> " << dest << endl;
        return;
    }

    hanoi(n-1, src, aux, dest);
    cout << src << " -> " << dest << endl;
    hanoi(n-1, aux, dest, src);
}

int main()
{
    hanoi(3, "A", "C", "B");

    /*
A -> C
A -> B
C -> B
A -> C
B -> A
B -> C
A -> C
*/
    return 0;
}





