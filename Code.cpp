#include<iostream>
using namespace std;

struct node{
	int var;
	int times = 1;
	node *next;
};

int N;
int max_time = 0;

node *add_new(node *root, int value)
{
	node *temp = new node();
	temp->var = value;
	root->next = temp;
	//cout<<temp->var<<" Added\n";
	return temp;
}

bool Entertain(int value, node *root)
{
	root=root->next;
	//cout<<"=> E\n";
	while(root != NULL)
	{
		if(value == root->var)
		{
			root->times = root->times + 1;
			if(max_time < root->times)
			{
				max_time = root->times;
			}
			return true;
		}
		root = root->next;
	}
	return false;
}

void Display(node *root, int time)
{
	root = root->next;
	while(root != NULL)
	{
		if(time == root->times)
		{
			for(int j=0; j<time; j++)
			{	
				cout<<root->var<<endl;
			}
		}
		root = root->next;
	}
}

//6 3 4 5
void Sort(node *root)
{
	node *r1 = root->next;
	node *r2 = root->next;
	
	while(r1 != NULL)
	{
		r2 = r1->next;
		while(r2 != NULL)
		{
			if(r1->var > r2->var)
			{
				int t = r1->var;
				r1->var = r2->var;
				r2->var = t;
				
				t = r1->times;
				r1->times = r2->times;
				r2->times = t;
			}
			r2 = r2->next;	
		}
		r1= r1->next;
	}
}

int main()
{
	node *root = new node();
	node *temp = root;
	cin>>N;
	
	
	for(int i=0;i<N; i++)
	{
		int t; 
		cin>>t;
		if(Entertain(t, root) == false)
		{
			temp = add_new(temp, t);
		}
	}
	 Sort(root);
	for(int i=1; i<=max_time; i++)
	{
		Display(root, i);
	}
}
