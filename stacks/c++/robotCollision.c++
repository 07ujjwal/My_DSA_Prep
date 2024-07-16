#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions){
        int n = positions.size();
        vector<tuple<int, int, char, int>> robots;
        
        // Combine positions, healths, and directions into a single tuple and add an index
        for (int i = 0; i < n; i++) {
            robots.emplace_back(positions[i], healths[i], directions[i], i);
        }

        // Sort the robots based on their positions
        sort(robots.begin(), robots.end());

        // Stack to keep track of robots moving to the right
        stack<pair<int, int>> st;

        vector<int> ans(n, -1);

        for (const auto& m : robots) {
            if (get<2>(m) == 'R') {
                st.push(make_pair(get<1>(m), get<3>(m))); // Push the health and original index
            } else {
                int current_health = get<1>(m);
                int current_index = get<3>(m);
                while (!st.empty() && current_health > 0) {
                    auto prev_st = st.top();
                    st.pop();

                    if (prev_st.first > current_health) {
                        prev_st.first -= 1;
                        st.push(prev_st);
                        current_health = 0;
                    } else if (prev_st.first == current_health) {
                        current_health = 0;
                    } else {
                        current_health -= 1;
                    }
                }
                
                if (current_health > 0) {
                    ans[current_index] = current_health;
                }
            }
        }

        // Remaining robots in the stack survived without collision
        while (!st.empty()) {
            auto survivor = st.top();
            st.pop();
            ans[survivor.second] = survivor.first;
        }

        // Filter out the robots with health -1 (which did not survive)
        vector<int> result;
        for (int health : ans) {
            if (health != -1) {
                result.push_back(health);
            }
        }

        return result;
    }
};


int main() {
    // Example input
    vector<int> positions = {1, 3, 5, 7};
    vector<int> healths = {10, 10, 10, 10};
    string directions = "RLRL";

    // Create a Solution object
    Solution solution;

    // Get the result
    vector<int> result = solution.survivedRobotsHealths(positions, healths, directions);

    // Print the result
    cout << "Surviving robots' healths: ";
    for (int health : result) {
        cout << health << " ";
    }
    cout << endl;

    return 0;
}
