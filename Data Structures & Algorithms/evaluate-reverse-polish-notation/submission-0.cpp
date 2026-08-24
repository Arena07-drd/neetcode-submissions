class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;

        for (string token : tokens) {
            if (token == "+" || token == "-" ||
                token == "*" || token == "/") {

                int n2 = stk.top();
                stk.pop();

                int n1 = stk.top();
                stk.pop();

                if (token == "+")
                    stk.push(n1 + n2);
                else if (token == "-")
                    stk.push(n1 - n2);
                else if (token == "*")
                    stk.push(n1 * n2);
                else
                    stk.push(n1 / n2);

            } else {
                stk.push(stoi(token));
            }
        }

        return stk.top();
    }
};