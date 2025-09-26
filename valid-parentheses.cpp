class Solution {
public:

    short convertCharacter(char ch) {
        if (ch == '(')
            return 1;
        else if (ch == ')')
            return -1;
        else if (ch == '[')
            return 2;
        else if (ch == ']')
            return -2;
        else if (ch == '{')
            return 3;
        else
            return -3;
    }

    bool isValid(string s) {
        stack <int> paranthesisStack;
        
        bool isValid;
        int i;

        isValid = 1;
        i = 0;
        while (i < s.size() && isValid) {
            int paranthesis = convertCharacter(s[i]);
            if (paranthesis > 0)
                paranthesisStack.push(paranthesis);
            else {
                if (paranthesisStack.empty())
                    isValid = 0;
                else {
                    int topStack = paranthesisStack.top();
                    paranthesisStack.pop();
                    isValid = ((topStack + paranthesis) == 0);
                }
            }

            i++;
        }

        if (isValid)
            isValid = paranthesisStack.empty();

        return isValid;
    }
};
