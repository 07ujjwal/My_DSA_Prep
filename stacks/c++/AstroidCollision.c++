#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;

        for (int &a : asteroids) {
            bool exploded = false;
            while (!st.empty() && a < 0 && st.top() > 0) {
                int top = st.top();
                if (top < -a) {
                    st.pop();
                } else if (top == -a) {
                    st.pop();
                    exploded = true;
                    break;
                } else {
                    exploded = true;
                    break;
                }
            }
            if (!exploded) {
                st.push(a);
            }
        }

        vector<int> result(st.size());
        for (int i = st.size() - 1; i >= 0; --i) {
            result[i] = st.top();
            st.pop();
        }

        return result;
    }
};

int main() {
    Solution solution;
    vector<int> asteroids = {5, 10, -5};
    vector<int> result = solution.asteroidCollision(asteroids);
    cout << "Result after collisions: ";
    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}
