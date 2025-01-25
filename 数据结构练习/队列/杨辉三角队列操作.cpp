#include <iostream>
#include <queue>
#define N 8
using namespace std;

int main(int argc, char* argv[]) {
    queue<int> Q;
//    cout << "1" << endl;
//    Q.push(1);
    for (int i = 2; i <= N; i++) {
        int s1 = 0;
        for (int j = 1; j < i - 1; j++) {
            int s2 = Q.front();
            Q.pop();  // ³ö¶Ó
            int x = s1 + s2;
            cout << x << " ";
            Q.push(x);
            s1 = s2;
        }
        cout << "1" << endl;
        Q.push(1);
    }
    return 0;
}

