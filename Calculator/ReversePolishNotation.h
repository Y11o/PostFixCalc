#pragma once
#include<iostream>
#include<stack>
#include<vector>
#include<string>

using namespace std;

int priorityPass(char a)  //operation priority
{
	if (a == '^')
		return 4;
	else
		if (a == '*' || a == '/')
			return 3;
		else
			if (a == '+' || a == '-')
				return 2;
			else
				if (a == '(' || a == ')')
					return 1;
				else
					return 0;
}

int calculate(double a, double b, char c)  //simple calculations
{
	switch (c)
	{
	case '+': return a + b; break;
	case '-': return a - b; break;
	case '*': return a * b; break;
	case '/': return a / b; break;
	case '^': return pow(a, b); break;
	}
}

string cos(string expression) {
	return to_string(cos(stod(expression)));
}

string sin(string expression) {
	return to_string(sin(stod(expression)));
}

string tan(string expression) {
	return to_string(double(sin(stod(expression)) / cos(stod(expression))));
}

string ctan(string expression) {
	return to_string(double(cos(stod(expression)) / sin(stod(expression))));
}

string ln(string expression) {
	return to_string(log(stod(expression)));
}

string logten(string expression) {
	return to_string(log10(stod(expression)));
}

string sqrt(string expression) {
	return to_string(sqrt(stod(expression)));
}

string asin(string expression) {
	return to_string(asin(stod(expression)));
}

void change(string& expression) {							//calculate functions
	for (unsigned int i = 0; i < expression.size(); i++) {
		if (expression[i] == 'c' && expression[i + 1] == 'o' && expression[i + 2] == 's' && expression[i + 3] == '(') {		//calc cos
			int toEraseFrom = i;
			i += 4;
			int symCount = 0;
			while (expression[i] != ')') {
				symCount++;
				i++;
			}
			if (symCount == 0)throw("Invalid arg at cos");
			int a = i - symCount;
			int b = symCount;
			string subs = expression.substr(a, b);
			expression.erase(toEraseFrom, (i - toEraseFrom + 1));
			if (stod(cos(subs)) < 0.0000000001) {
				expression.insert(toEraseFrom, ")");
				expression.insert(toEraseFrom, cos(subs));
				expression.insert(toEraseFrom, "(");
			}
			else
			{
				expression.insert(toEraseFrom, cos(subs));
			}
			i = toEraseFrom;
		}
		if (expression[i] == 's' && expression[i + 1] == 'i' && expression[i + 2] == 'n' && expression[i + 3] == '(') {		//calc sin
			int toEraseFrom = i;
			i += 4;
			int symCount = 0;
			while (expression[i] != ')') {
				symCount++;
				i++;
			}
			if (symCount == 0)throw("Invalid arg at sin");
			int a = i - symCount;
			int b = symCount;
			string subs = expression.substr(a, b);
			expression.erase(toEraseFrom, (i - toEraseFrom + 1));
			if (stod(sin(subs)) < 0.0000000001) {
				expression.insert(toEraseFrom, ")");
				expression.insert(toEraseFrom, sin(subs));
				expression.insert(toEraseFrom, "(");
			}
			else
			{
				expression.insert(toEraseFrom, sin(subs));
			}
			i = toEraseFrom;
		}
		if (expression[i] == 't' && expression[i + 1] == 'g' && expression[i + 2] == '(') {		//calc tg
			int toEraseFrom = i;
			i += 3;
			int symCount = 0;
			while (expression[i] != ')') {
				symCount++;
				i++;
			}
			if (symCount == 0)throw("Invalid arg at tg");
			int a = i - symCount;
			int b = symCount;
			string subs = expression.substr(a, b);
			expression.erase(toEraseFrom, (i - toEraseFrom + 1));
			if (stod(tan(subs)) < 0.0000000001) {
				expression.insert(toEraseFrom, ")");
				expression.insert(toEraseFrom, tan(subs));
				expression.insert(toEraseFrom, "(");
			}
			else
			{
				expression.insert(toEraseFrom, tan(subs));
			}
			i = toEraseFrom;
		}
		if (expression[i] == 'c' && expression[i + 1] == 't' && expression[i + 2] == 'g' && expression[i + 3] == '(') {		//calc ctg
			int toEraseFrom = i;
			i += 4;
			int symCount = 0;
			while (expression[i] != ')') {
				symCount++;
				i++;
			}
			if (symCount == 0)throw("Invalid arg at ctg");
			int a = i - symCount;
			int b = symCount;
			string subs = expression.substr(a, b);
			expression.erase(toEraseFrom, (i - toEraseFrom + 1));
			if (stod(ctan(subs)) < 0.0000000001) {
				expression.insert(toEraseFrom, ")");
				expression.insert(toEraseFrom, ctan(subs));
				expression.insert(toEraseFrom, "(");
			}
			else
			{
				expression.insert(toEraseFrom, ctan(subs));
			}
			i = toEraseFrom;
		}
		if (expression[i] == 'l' && expression[i + 1] == 'n' && expression[i + 2] == '(') {		//calc ln
			int toEraseFrom = i;
			i += 3;
			int symCount = 0;
			while (expression[i] != ')') {
				symCount++;
				i++;
			}
			if (symCount == 0)throw("Invalid arg at ln");
			int a = i - symCount;
			int b = symCount;
			string subs = expression.substr(a, b);
			expression.erase(toEraseFrom, (i - toEraseFrom + 1));
			if (stod(ln(subs)) < 0.0000000001) {
				expression.insert(toEraseFrom, ")");
				expression.insert(toEraseFrom, ln(subs));
				expression.insert(toEraseFrom, "(");
			}
			else
			{
				expression.insert(toEraseFrom,ln(subs));
			}
			i = toEraseFrom;
		}
		if (expression[i] == 'l' && expression[i + 1] == 'o' && expression[i + 2] == 'g' && expression[i + 3] == '(') {		//calc log10
			int toEraseFrom = i;
			i += 4;
			int symCount = 0;
			while (expression[i] != ')') {
				symCount++;
				i++;
			}
			if (symCount == 0)throw("Invalid arg at log");
			int a = i - symCount;
			int b = symCount;
			string subs = expression.substr(a, b);
			expression.erase(toEraseFrom, (i - toEraseFrom + 1));
			if (stod(logten(subs)) < 0.0000000001) {
				expression.insert(toEraseFrom, ")");
				expression.insert(toEraseFrom, logten(subs));
				expression.insert(toEraseFrom, "(");
			}
			else
			{
				expression.insert(toEraseFrom, logten(subs));
			}
			i = toEraseFrom;
		}
		if (expression[i] == 's' && expression[i + 1] == 'q' && expression[i + 2] == 'r' && expression[i + 3] == 't' && expression[i + 4] == '(') {		//calc sqrt
			int toEraseFrom = i;
			i += 5;
			int symCount = 0;
			while (expression[i] != ')') {
				symCount++;
				i++;
			}
			if (symCount == 0)throw("Invalid arg at sqrt");
			int a = i - symCount;
			int b = symCount;
			string subs = expression.substr(a, b);
			expression.erase(toEraseFrom, (i - toEraseFrom + 1));
			expression.insert(toEraseFrom, sqrt(subs));
			i = toEraseFrom;
		}
		if (expression[i] == 'a' && expression[i + 1] == 's' && expression[i + 2] == 'i' && expression[i + 3] == 'n' && expression[i + 4] == '(') {		//calc asin
			int toEraseFrom = i;
			i += 5;
			int symCount = 0;
			while (expression[i] != ')') {
				symCount++;
				i++;
			}
			if (symCount == 0)throw("Invalid arg at asin");
			int a = i - symCount;
			int b = symCount;
			string subs = expression.substr(a, b);
			expression.erase(toEraseFrom, (i - toEraseFrom + 1));
			if (stod(asin(subs)) < 0.0000000001) {
				expression.insert(toEraseFrom, ")");
				expression.insert(toEraseFrom, asin(subs));
				expression.insert(toEraseFrom, "(");
			}
			else
			{
				expression.insert(toEraseFrom, asin(subs));
			}
			i = toEraseFrom;
		}

	}
}

double postFix(string expression = "0", int flag = 0) {
	string currExpression;
	if (!flag) {										//for unit tests
		cout << "Input your expression:" << endl;
		getline(cin, currExpression);
	}
	else
	{
		currExpression = expression;
	}
	for (unsigned int i = 0; i < currExpression.size(); i++)			//insert PI, exp and change commas to dots
	{
		if ((currExpression[i] == 'P' || currExpression[i] == 'p') && (currExpression[i + 1] == 'I' || currExpression[i + 1] == 'i')) {
			currExpression.erase(i, 2);
			currExpression.insert(i, "3.14159265");
		}
		if (currExpression[i] == 'e' || currExpression[i] == 'E') {
			currExpression.erase(i, 1);
			currExpression.insert(i, "2.718");
		}
		if (currExpression[i] == ',') {
			currExpression.erase(i, 1);
			currExpression.insert(i, ".");
		}
	}
	change(currExpression);
	double currNum = 0;
	char x = '1';
	int i = 0;
	stack<char> operationStack;
	vector<double> numVector;
	stack<double> calculationStack;
	vector<char> output;
	while (currExpression.size() != i) //string traversal
	{
		x = currExpression[i];
		if ((currExpression[i] < 58 && currExpression[i] > 47) || (currExpression[i] == '(' && currExpression[i + 1] == '-')) {   //if x - number or uno '-' operation
			int startNum;
			bool uno;
			if (currExpression[i] == '(') {
				uno = true;
				i += 2;
				startNum = i;
			}
			else {
				uno = false;
				startNum = i;
			}
			int endNum = 0;
			while ((currExpression[i] < 58 && currExpression[i] > 47) || currExpression[i] == '.') {
				endNum = i;
				i++;
			}
			if (uno) {
				int from = startNum - 1;
				int to = endNum + 2 - startNum;
				currNum = stod(currExpression.substr(from, to));
				numVector.push_back(currNum);    //add to num vector
				output.push_back('1');           //mark that we have a number
				i++;
				x = currExpression[i];
			}
			else
			{
				int from = startNum;
				int to = endNum + 1 - startNum;
				currNum = stod(currExpression.substr(from, to));
				numVector.push_back(currNum);		//add to num vector
				output.push_back('1');				//mark that we have a number
				i--;
			}
		}
		if (x == '*' || x == '/' || x == '+' || x == '-' || x == '(' || x == '^')		//if x is operatioon we add it in operation stack
		{
			while (!operationStack.empty() && priorityPass(x) <= priorityPass(operationStack.top()) && x != '(')
			{
				output.push_back(operationStack.top());									//and in outstream by priority
				operationStack.pop();
			}
			operationStack.push(x);
		}
		if (x == ')')																	//brackets balance
		{
			while (operationStack.top() != '(')
			{
				output.push_back(operationStack.top());
				operationStack.pop();
			}
			operationStack.pop();
		}
		i++;
	}
	while (!operationStack.empty())						//add remaining operations from operation stack to outstream
	{
		output.push_back(operationStack.top());
		operationStack.pop();
	}
	cout << endl;
	cout << "Reverse Polish Notation: ";
	char v;												//var to check if we have a num or operation in outstream
	int j = 0;											//var to move in num vector
	for (int i = 0; i < output.size(); i++)
	{
		v = output[i];
		if (v == '1') {								//if we have a num in outstream, we push it to the calc stack from num vect
			calculationStack.push(numVector[j]);
			cout << numVector[j] << ' ';
			j++;
		}
		else										//if we have an operation, we pull out 2 nums from the top of calc stack and calculate them
		{
			cout << output[i] << ' ';
			double k = calculationStack.top();
			calculationStack.pop();
			double b = calculationStack.top();
			calculationStack.pop();
			if (v == '/' && k == 0) {
				cout << "Division by 0";
				system("PAUSE");
				exit(1);
			}
			calculationStack.push(calculate(b, k, v));
		}
	}
	cout << endl;
	cout << "The answer is " << calculationStack.top() << endl;  //the remaining num is the answer
	return calculationStack.top();
}
