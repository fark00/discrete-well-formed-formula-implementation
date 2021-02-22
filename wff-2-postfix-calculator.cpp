#include<iostream>
#include<vector>
#include<list>
#include<string>
#include<string.h>
#include<cmath>
using namespace std;
int main()
{
	string str;
	cin >> str;
	list<char> v;
	vector<int>n;
	for (int i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == ')')
		{
			for (int j = i - 1; j >= 0; j--)
			{
				if (str[j] == '+' || str[j] == '-' || str[j] == '/' || str[j] == '*' || str[j] == '^')
				{
					v.push_back(str[j]);
					str[j] = '@';
					break;
				}
			}
		}
	}
	char postfix[100];
	int k = 0;
	for (int i = 0; str[i] != '\0'; i++)
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			postfix[k] = str[i];
			//n.push_back(atoi((char*)str[i]));
			k++;
		}
		if (str[i] == ')')
		{
			postfix[k] = v.front();
			k++;
			v.pop_front();
		}
	}
	vector<string> m;
	postfix[k] = '\0';
	cout << postfix << endl;
	for (int i = 0; postfix[i] != '\0'; i++)
	{
		if (postfix[i] >= '0' && postfix[i] <= '9')
		{
			m.push_back(to_string(postfix[i]-48));
		}
		if (postfix[i] == '+')
		{
			m.push_back("+");
		}
		if (postfix[i] == '-')
		{
			m.push_back("-");
		}
		if (postfix[i] == '*')
		{
			m.push_back("*");
		}
		if (postfix[i] == '/')
		{
			m.push_back("/");
		}
		if (postfix[i] == '^')
		{
			m.push_back("^");
		}
	}
	vector<string>::iterator it;
	for (it = m.begin(); it != m.end(); it++)
	{
		if (*it == "+" || *it == "-" || *it == "/" || *it == "*" || *it == "^")
		{
			vector<string>::iterator it2;
			string first,second;
			for (it2 = it - 1; it2 >= m.begin(); it2--)
			{
				if (*it2 != "+" && *it2 != "-" && *it2 != "*" && *it2 != "/" && *it2 != "^" && *it2 != "@")
				{
					second = *it2;
					*it2 = "@";
					break;
				}
			}
			for (it2 = it - 1; it2 >= m.begin(); it2--)
			{
				if (*it2 != "+" && *it2 != "-" && *it2 != "*" && *it2 != "/" && *it2 != "^" && *it2 != "@")
				{
					first = *it2;
					*it2 = "@";
					break;
				}
			}
			if (*it == "+")
				*it = to_string(stoi(first) + stoi(second));
			if (*it == "-")
				*it = to_string(stoi(first) - stoi(second));
			if (*it == "*")
				*it = to_string(stoi(first) * stoi(second));
			if (*it == "/")
				*it = to_string(stoi(first) / stoi(second));
			if (*it == "^")
				*it =to_string(pow(stoi(first) , stoi(second)));
		}
	}
	cout << *(m.end() - 1)<<endl;
}

