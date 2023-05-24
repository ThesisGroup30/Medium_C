#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        vector<int> result;
        int n = expression.length();

        for (int i = 0; i < n; i++) {
            char c = expression[i];

            if (c == '+' || c == '-' || c == '*') {
                string leftExp = expression.substr(0, i);
                string rightExp = expression.substr(i + 1);

                vector<int> leftResults = diffWaysToCompute(leftExp);
                vector<int> rightResults = diffWaysToCompute(rightExp);

                for (int leftNum : leftResults) {
                    for (int rightNum : rightResults) {
                        int currResult;
                        if (c == '+') {
                            currResult = leftNum + rightNum;
                        } else if (c == '-') {
                            currResult = leftNum - rightNum;
                        } else {
                            currResult = leftNum * rightNum;
                        }
                        result.push_back(currResult);
                    }
                }
            }
        }

        // If the expression is a single number
        if (result.empty()) {
            result.push_back(stoi(expression));
        }

        return result;
    }
};
