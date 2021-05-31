#include<bits/stdc++.h>
using namespace std;

// case where 1*(2+3)
void case1(vector<char>&str,int start,int end)
{
	cout<<"case1"<<endl;
	char value=str[start-2];
	vector<char>add,ans;
	str.erase(str.begin()+start);
	str.erase(str.begin()+end-1);
	for(int i=start;i<end-1;i++)
	{
		ans.push_back(str[i]);
		if(str[i]=='+')ans.insert(ans.end(),{value,'*'});
	}
	str.erase(str.begin()+start,str.begin()+end-1);
	str.insert(str.begin()+start,ans.begin(),ans.end());

	for(int i=0;i<str.size();i++)cout<<str[i];
	cout<<endl;


}


// case where (1+2)*3
void case2(vector<char>&str,int start,int end)
{
	cout<<"case2"<<endl;
	char value=str[end+2];
	vector<char>add,ans;
	
	str.erase(str.begin()+start);
	str.erase(str.begin()+end-1);
	for(int i=start;i<end-1;i++)
	{
		ans.push_back(str[i]);
		if(str[i]=='+')ans.insert(ans.end()-1,{'*',value});
	}

	str.erase(str.begin()+start,str.begin()+end-1);
	str.insert(str.begin()+start,ans.begin(),ans.end());
	for(int i=0;i<str.size();i++)cout<<str[i];
	cout<<endl;


}


//case where (1+2)*(3+4)
void case3(vector<char>&str,int start,int end, int *count)
{
	cout<<"case3"<<endl;
	int start_2=end+2;
	int end_2=0;
	for(int i=start_2;i<str.size();i++)
	{
		if(str[i]==')')
		{
			end_2=i;
			break;
		}
	}
	vector<char>add,ans;
	for(int i=start_2-1;i<=end_2;i++)add.push_back(str[i]);
	str.erase(str.begin()+start);
	str.erase(str.begin()+end-1);
	for(int i=start;i<end-1;i++)
	{
		ans.push_back(str[i]);
		if(str[i]=='+')
		{
			ans.insert(ans.end()-1,add.begin(),add.end());
			*count=*count+1;
		}					
	}
	str.erase(str.begin()+start,str.begin()+end-1);
	str.insert(str.begin()+start,ans.begin(),ans.end());
	for(int i=0;i<str.size();i++)cout<<str[i];
	cout<<endl;

}

//case where 1*(2+3)*4
void case4(vector<char>&str,int start,int end)
{
	cout<<"case4"<<endl;
	char value=str[start-2];
	vector<char>add,ans;
	
	str.erase(str.begin()+start);
	for(int i=start;i<end-1;i++)
	{
		ans.push_back(str[i]);
		if(str[i]=='+')ans.insert(ans.end(),{value,'*'});
	}
	str.erase(str.begin()+start,str.begin()+end-1);
	str.insert(str.begin()+start,ans.begin(),ans.end());
	str.insert(str.begin(),{'('});
	for(int i=0;i<str.size();i++)cout<<str[i];
	cout<<endl;


}


int main()

{
	int N,start,end;
	int to, from;
	vector<char>str;
	string temp;
	int count=0,flag=0;
	cout<<"Give total number of stations: ";
	cin>>N;
	cin>>temp;
	vector<vector<int>>H(N,vector<int>(N,0));
	for(int i=0;i<temp.size();i++)
	{

		if(temp[i]!='S'&& temp[i]!='s')
		{
			str.push_back(temp[i]);
		}
		if(temp[i]=='(')count++;
	}
	while(count!=0)
	{
		flag=0;
		for(int i=0;i<str.size();i++)
		{
			if(str[i]=='(')start=i;
			if(str[i]==')')
			{
				end=i;
				if(str[i+1]=='*')flag=1;
				if(str[i+1]=='*'&& str[i+2]=='(')flag=2;
				if(str[start-1]=='*'&&str[i+1]=='*')flag=3;
				break;
				
			}
		}
		if(flag==0)
		{
			case1(str,start,end);
			count--;
		}
		if(flag==1)
		{
			case2(str,start,end);
			count--;
		}
		if(flag==2)
		{
			case3(str,start,end,&count);
			count--;
		}
		if(flag==3)
		{
			case4(str,start,end);
		}
	}
	for(int i=0;i<str.size();i++)
	{
		if(str[i]=='*')H[str[i-1]-'0'-1][str[i+1]-'0'-1]=1;
	}
	cout<<"Adjacency Matrix H: "<<endl;
	cout<<"    ";
	for(int i=0;i<N;i++)cout<<"S"<<i+1<<"  ";
	cout<<endl;
	for(int i=0;i<N;i++)
	{
		cout<<"S"<<i+1<<"   ";
		for(int j=0;j<N;j++)
		{
			cout<<H[i][j]<<"   ";
		}
		cout<<endl;
	}
}