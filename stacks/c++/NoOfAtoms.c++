#include <iostream>
#include <map>
#include <stack>
#include<vector>
#include <string>
#include <cctype>
#include <algorithm>
using namespace std;

class Solution {
public:
    string countOfAtoms(string formula) {
       int n = formula.size();
        stack<map<string, int>> stk;
        map<string, int> current;

        for (int i = 0; i < n; ) {
            if (formula[i] == '(') {
                stk.push(current);
                current.clear();
                i++;
            } else if (formula[i] == ')') {
                i++;
                int start = i;
                while (i < n && isdigit(formula[i])) i++;
                int multiplier = (start < i) ? stoi(formula.substr(start, i - start)) : 1;

                if (!stk.empty()) {
                    map<string, int> temp = current;
                    current = stk.top();
                    stk.pop();
                    for (auto &[element, count] : temp) {
                        current[element] += count * multiplier;
                    }
                }
            } else {
                int start = i;
                i++;
                while (i < n && islower(formula[i])) i++;
                string element = formula.substr(start, i - start);
                start = i;
                while (i < n && isdigit(formula[i])) i++;
                int count = (start < i) ? stoi(formula.substr(start, i - start)) : 1;
                current[element] += count;
            }
        }

        // Create the final result string
        vector<pair<string, int>> elements(current.begin(), current.end());
        sort(elements.begin(), elements.end());

        string result;
        for (auto &[element, count] : elements) {
            result += element;
            if (count > 1) {
                result += to_string(count);
            }
        }

        return result;
    }
};

int main() {
    Solution solution;
    string formula1 = "H2O";
    string formula2 = "Mg(OH)2";
    string formula3 = "K4(ON(SO3)2)2";

    cout << "Formula: " << formula1 << ", Output: " << solution.countOfAtoms(formula1) << endl;
    cout << "Formula: " << formula2 << ", Output: " << solution.countOfAtoms(formula2) << endl;
    cout << "Formula: " << formula3 << ", Output: " << solution.countOfAtoms(formula3) << endl;

    return 0;
}
