class Solution {
public:
    string decodeString(string s) {
        stack<int> countStack;
        stack<string> stringStack;
        string currString = "";
        int currCount = 0;
        
        for (char c : s) {
            if (isdigit(c)) {
                currCount = currCount * 10 + (c - '0');
            } else if (isalpha(c)) {
                currString += c;
            } else if (c == '[') {
                countStack.push(currCount);
                stringStack.push(currString);
                currCount = 0;
                currString = "";
            } else { // c == ']'
                int count = countStack.top();
                countStack.pop();
                string temp = "";
                for (int i = 0; i < count; i++) {
                    temp += currString;
                }
                currString = stringStack.top() + temp;
                stringStack.pop();
            }
        }
        
        return currString;
    }
};
