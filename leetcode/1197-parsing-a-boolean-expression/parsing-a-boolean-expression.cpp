class Solution {
public:
    bool eval(const string &expression, int &i) {
        if (expression[i] == 't') {
            i++;         // Move past 't'
            return true; // Return true for 't'
        }
        if (expression[i] == 'f') {
            i++;          // Move past 'f'
            return false; // Return false for 'f'
        }

        // The character is one of the operators: !, &, |
        char operatorSign = expression[i];
        i += 2; // Move past the operator and the opening '('

        vector<bool> results;

        // Evaluate each sub-expression within the parentheses
        while (expression[i] != ')') {
            if (expression[i] == ',') {
                i++; // Skip commas
            } else {
                results.push_back(eval(expression, i));
            }
        }
        i++; // Move past the closing ')'

        // Evaluate based on the operator
        if (operatorSign == '!') {
            return !results[0];
        } else if (operatorSign == '&') {
            for (bool result : results) {
                if (!result)
                    return false; // AND: If any result is false, return false
            }
            return true;
        } else if (operatorSign == '|') {
            for (bool result : results) {
                if (result)
                    return true; // OR: If any result is true, return true
            }
            return false;
        }

        return false; // This line should not be reached
    }
    bool parseBoolExpr(string expression) {
         int i = 0;
        return eval(expression, i);
    }
};