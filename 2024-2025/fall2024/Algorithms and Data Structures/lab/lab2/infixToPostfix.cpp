/*
 * Name: Jonathan Tucker
 * Date Submitted: 09/23/24
 * Lab Section: 001
 * Assignment Name: Lab 2: Infix to Postfix Conversion
 */

#include <iostream>
#include <string>
#include <stack>

using namespace std;

int getPrecedence(string inString)
{
	char setStringToChar = inString[0];

	switch(setStringToChar)
	{
		case '(': case ')':
			return 3;
		case '/': case '*': case '%':
			return 2;
		case '+': case '-':
			return 1;
		default:
			return 0;
	}

	return 0;
}


//Converts an infix arithmetic expression into postfix
//The function takes 3 parameters
//First parameter: array of strings for infix expression
//    each string is either an integer number or operator symbol
//Second parameter: number of strings in infix expression
//Third parameter: array of strings for postfix expression
//    generated by function, same format as first parameter
//    assumes that postfix is at least the size of postfix
//Return value: int, number of strings in postfix expression
//    Returns 0 if an error is encountered when converting expression
//    An error occurs with a mismatched parenthesis, e.g. ( ( ) or ( ) ) etc.
//Operator symbols:
// ( : left parenthesis, all operations between this and ")" take place first
// ) : right parenthesis, all op.s back to previous "(" take place first
// * : multiplication, higher precedence - takes place before "+" and "-"
// / : division, higher precedence - takes place before "+" and "-"
// % : remainder, higher precedence - takes place before "+" and "-"
// + : addition, lower precedence - takes place after "*" , "/" , "%"
// - : subtraction, lower precedence - takes place after "*" , "/" , "%"
//The function is not specified to work with any other operator symbols
//Any string in infix may be assumed to be an integer operand if none
// of the above symbols
int infixToPostfix(string infix[], int length, string postfix[])
{
	stack<string> operatorStack;
	int fEmptyIndex = 0;
	int leftParentheses = 0;
	int rightParentheses = 0;

	for (int i = 0; i < length; i++)
	{
		if (infix[i] == "(")
		{
			leftParentheses++;
		}

		if (infix[i] == ")")
		{
			rightParentheses++;
			
			if (rightParentheses > leftParentheses)
			{
				return 0;
			}
		}

		if (getPrecedence(infix[i]) != 0 && getPrecedence(infix[i]) != 3)
		{
			if (getPrecedence(infix[i - 1]) != 0 && getPrecedence(infix[i - 1]) != 3)
			{
				return 3;
			}
		}

		if (getPrecedence(infix[i]) == 0)
		{
			postfix[fEmptyIndex] = infix[i];
			fEmptyIndex++;
		}
		else if (infix[i] == "(")
		{
			operatorStack.push(infix[i]);
		}
		else if (infix[i] == ")")
		{
			while (operatorStack.top() != "(")
			{
				postfix[fEmptyIndex] = operatorStack.top();
				operatorStack.pop();
				fEmptyIndex++;
			}

			operatorStack.pop();
		}
		else
		{
			while (operatorStack.size() > 0 && getPrecedence(infix[i]) 
					<= getPrecedence(operatorStack.top()) && operatorStack.top() != "(")
			{
				postfix[fEmptyIndex] = operatorStack.top();
				operatorStack.pop();
                                fEmptyIndex++;
			}
		
			operatorStack.push(infix[i]);
		}
	}

	if (leftParentheses != rightParentheses)
	{
		return 0;
	}

	while (!operatorStack.empty())
	{
		postfix[fEmptyIndex] = operatorStack.top();
		fEmptyIndex++;
		operatorStack.pop();
	}

	return fEmptyIndex;

}

//Main function to test infixToPostfix()
//Should convert 2 + 3 * 4 + ( 5 - 6 + 7 ) * 8
//            to 2 3 4 * + 5 6 - 7 + 8 * +
/*
int main()
{
    	string infixExp[] = {"2", "+", "3", "*", "4", "+", "(",
                         "5", "-", "6", "+", "7", ")", "*",
                         "8"};
    	string postfixExp[15];
    	int postfixLength;

    	cout << "Infix expression: ";
    	for (int i=0; i<15; i++)
    	{
        	cout << infixExp[i] << " ";
    	}
    	cout << endl;
    	cout << "Length: 15" << endl << endl;

    	postfixLength = infixToPostfix(infixExp, 15, postfixExp);

    	cout << "Postfix expression: ";
    	for (int i=0; i<postfixLength; i++)
    	{
        	cout << postfixExp[i] << " ";
    	}
    	cout << endl;
    	cout << "Length: " << postfixLength << endl;
    
    return 0;
}
*/
