#include <iostream>
#include <stack>
#include <queue>

using namespace std;

int n;
stack<int> s;
queue<int> q;

bool is_nice()
{
    int s0, q0;
    for (int i = 0; i < n; i++)
    {
        if (s.empty()) s0 = -1;
        else s0 = s.top();
        if (q.empty()) q0 = -1;
        else q0 = q.front();

        if (q0 == i + 1)
        {
            q.pop();
        }
        else if (s0 == i + 1)
        {
            s.pop();
        }
        else
        {
            if (q.empty()) return false;

            s.push(q0);
            q.pop();
            i--;
        }
    }
    return true;
}

int main()
{
    int tmp;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        q.push(tmp);
    }

    cout << (is_nice() ? "Nice" : "Sad");
    return 0;
}
