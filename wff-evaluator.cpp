#include<iostream>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<string>
#include<vector>
using namespace std;
#pragma warning(disable:4996)
struct node
{
	char ch[5];
	char* s;
	//string s;
	//vector<char> s;
	struct node* next;
};
struct node* head = NULL, * tail, * temp, * current, * right_, * left_;
char charac[33];
string charstar(string str/*char* str*/)
{
	int flag, j = 0;////??????
	
	//string charac;
	for (int i = 0; str[i] != '\0'; i++)
	{
		if (str[i] >= 97 && str[i] <= 122 && str[i] != 'T' && str[i] != 'F')
		{
			flag = 0;
			for (int r = 0; r < j; r++)
			{
				if (str[i] == charac[r])
				{
					flag = 1;
					break;
				}
			}
			if (flag == 0)
				charac[j++] = str[i];
		}
	}
	charac[j] = '\0';
	string f=charac;
	return f;
}
char g = 'a';
node* linking(string s1, string str, int p)
{
	char* m, * mm;
	int cc = 0;
	
	while (1)
	{
		if (str.find("->") != NULL)
		{

		}
		if (strstr(str.c_str(), "/\\") != NULL || strstr(str.c_str(), "\\/") != NULL || strstr(str.c_str(), "->") != NULL || strstr(str.c_str(), "~") != NULL)
		//if(str.find("/\\")!=0 || str.find("\\/") != 0 || str.find("->") != 0 || str.find("~") != 0)
		{
			char sm[100];
			strcpy(sm, str.c_str());
			m = strchr(sm, ')');
			//m = str.find_first_of(')');
			cc = 0;
			while (1)
			{
				cc++;
				m--;
				if (m[0] == '(')
					break;
			}
			mm = m;
			m++;
			//cc += 1;
			cc--;
			char sss[100];
			int l;
			for (l = 0; l < cc; l++)
			{
				sss[l] = m[0];
				m++;
			}
			m++;
			int k = m - mm;
			sss[l] = '\0';
			char string_[20];
			int y, c_y;
			y = 0;
			c_y = 0;
			while (sss[y] != '\0')
			{
				if (sss[y] >= 97 && sss[y] <= 122)
				{
					string_[c_y] = sss[y];
					y++;
					c_y++;
				}
				else if (sss[y] == 'T' || sss[y] == 'F')
				{
					string_[c_y] = sss[y];
					y++;
					c_y++;
				}
				else if (sss[y] == '*')
				{
					y++;
					//c_y++;
				}
				else
					break;
			}
			string_[c_y] = '\0';
			current = head;
			while (current != NULL)
			{
				if (strcmp(current->ch, string_) == 0)
				{
					left_ = current;
					break;
				}
				current = current->next;
			}
			int x = y;
			c_y = 0;
			while (sss[x] != '\0')
			{
				if (sss[x] >= 97 && sss[x] <= 122)
				{
					string_[c_y] = sss[x];
					x++;
					c_y++;
				}
				else if (sss[x] == 'T' || sss[x] == 'F')
				{
					string_[c_y] = sss[x];
					x++;
					c_y++;
				}
				else
				{
					x++;
				}
			}
			string_[c_y] = '\0';
			current = head;
			while (current != NULL)
			{
				if (strcmp(current->ch, string_) == 0)
				{
					right_ = current;
					break;
				}
				current = current->next;
			}
			temp = new struct node;
			temp->next = NULL;
			char ccc[4];
			if (g > 122)
			{
				g = 97;
				ccc[0] = g;
				ccc[1] = g;
				ccc[2] = g;
				ccc[3] = '\0';
			}
			else
			{
				ccc[0] = g;
				ccc[1] = g;
				ccc[2] = '\0';
			}
			g++;
			strcpy(temp->ch, ccc);
			temp->s = new char[(int)p];
			if (strstr(sss, "/\\") != NULL)
			{
				for (int i = 0; i < p; i++)
				{
					if (right_->s[i] == '1' && left_->s[i] == '1')
						temp->s[i] = '1';//temp->s.push_back('1');
					else
						temp->s[i] = '0';//temp->s.push_back('0');
				}
				temp->s[(int)p] = '\0';
			}
			else if (strstr(sss, "\\/") != NULL)
			{
				for (int i = 0; i < p; i++)
				{
					if (right_->s[i] == '0' && left_->s[i] == '0')
						temp->s[i] = '0';//temp->s.push_back('0');
					else
						temp->s[i] = '1';//temp->s.push_back('1');
				}
				temp->s[(int)p] = '\0';
			}
			else if (strstr(sss, "<->") != NULL)
			{
				for (int i = 0; i < p; i++)
				{
					if (right_->s[i] == left_->s[i])
						temp->s[i] = '1';//temp->s.push_back('1');
					else
						temp->s[i] = '0';//temp->s.push_back('0');
				}
				temp->s[(int)p] = '\0';
			}
			else if (strstr(sss, "->") != NULL)
			{
				for (int i = 0; i < p; i++)
				{
					if (right_->s[i] == '0' && left_->s[i] == '1')
						temp->s[i] = '0';//temp->s.push_back('0');
					else
						temp->s[i] = '1';//temp->s.push_back('1');
				}
				temp->s[(int)p] = '\0';
			}
			else if (strstr(sss, "~") != NULL)
			{
				for (int i = 0; i < p; i++)
					if (right_->s[i] == '1')
						temp->s[i] = '0';
					else if(right_->s[i] != '1')
						temp->s[i] = '1';
				temp->s[(int)p] = '\0';
			}
			tail->next = temp;
			tail = temp;
			int v = strlen(temp->ch);
			int b;
			for (b = 0; b < k - v; b++)
				mm[b] = '*';
			for (int y = 0; y < v; y++)
			{
				mm[b + y] = temp->ch[y];
			}
			right_ = NULL;
			left_ = NULL;
			str = sm;
			/*if (strchr(str, ')') == NULL)
			{
				char ssss[2] = ")";
				strcat(str, ssss);

			}
			if (strchr(str, '(') == NULL)
			{
				char ssss[400] = "(";
				strcat(ssss, str);
				strcpy(str, ssss);
			}*/
		}
		else
		{
			/*current = head;
			int q = 0;
			for (int u = 0; u < nono; u++)
			{
				printf("%s\t", current->ch);
				current = current->next;
			}
			printf("%s\n", nonono);
			printf("--------------------------------------------------------------------------------------------\n");
			for (q = 0; q < p; q++)
			{
				current = head;
				for (int w = 0; w < nono; w++)
				{
					printf("%c\t", current->s[q]);
				}
				printf("%c\n", tail->s[q]);
			}
			return 0;*/
			//break;
			return tail;
		}
	}
}
int main()
{
	/*char s1[50], s2[50];

	char str[1000];
	cin.getline(str, 1000);
	char* fff, * nnn;
	fff = strtok(str, " ");
	nnn = strtok(NULL, " ");*/

	string str1, str2;
	cin>>str1;
	cin >> str2;

	string s1, s2;
	s1 = charstar(str1);
	s2 = charstar(str2);

	

	/*char sss[1000];
	cin.getline(sss, 1000);*/

	/*strcpy(s1, charstar(fff));
	strcpy(s2, charstar(nnn));*/

	int flag_str;
	int counter = 0;
	for (int i = 0; s1[i] != '\0'; i++)
	{
		counter++;
		flag_str = 0;
		for (int j = 0; s2[j] != '\0'; j++)
		{
			if (s1[i] == s2[j])
			{
				flag_str = 1;
				s2[j] = 'A';
				break;
			}
		}
		if (flag_str == 0)
		{
			cout << "0";
			return 0;
		}
	}
	for (int i = 0; s2[i] != '\0'; i++)
		if (s2[i] != 'A')
		{
			cout << "0";
			return 0;
		}

	double p = pow(2, (double)counter);
	int x = (int)p / 2;
	int count = 1;
	char c = '1';

	temp = new struct node;
	temp->next = NULL;
	strcpy(temp->ch, "T");
	temp->s = new char[(int)p];
	for (int i = 0; i < (int)p; i++)
		temp->s[i] = '1';//temp->s.push_back('1');
	temp->s[(int)p] = '\0';//temp->s[(int)p - 1] = '\0';
	head = temp;
	tail = temp;

	temp = new struct node;
	temp->next = NULL;
	strcpy(temp->ch, "F");
	temp->s = new char[(int)p];
	for (int i = 0; i < (int)p; i++)
		temp->s[i] = '0';//temp->s.push_back('0');
	temp->s[(int)p] = '\0';//temp->s[(int)p - 1] = '\0';
	tail->next = temp;
	tail = temp;

	for (int i = 0; i < counter; i++)
	{
		temp = new struct node;
		temp->next = NULL;
		char ccc[2];
		ccc[0] = s1[i];
		ccc[1] = '\0';
		strcpy(temp->ch, ccc);
		temp->s = new char[(int)p];
		int r;
		for (r = 0; r < (int)p; r++)
		{
			if (count > x)
			{
				count = 1;
				if (c == '1')
					c = '0';
				else
					c = '1';
			}
			temp->s[r] = c;
			count++;
		}
		temp->s[r] = '\0';
		x = x / 2;
		if (head == NULL)
		{
			head = temp;
			tail = temp;
		}
		else
		{
			tail->next = temp;
			tail = temp;
		}
	}
	
	int flag = 0;
	struct node* t1, *t2;
	t1 = linking(s1, str1, p);
	t2 = linking(s2, str2, p);
	for (int i = 0; i < (int)p; i++)
	{
		if (t1->s[i] == t2->s[i])
			flag = 1;
		else
		{
			flag = 0;
			break;
		}
	}
	//if (*(t1->s)==*(t2->s))
	if(flag==1)
		cout << "1";
	else
		cout << "0";

	return 0;

}