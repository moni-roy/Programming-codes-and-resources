#include <bits/stdc++.h>
using namespace std;

int length_calculation(int a,int b);

int check[1000010];
int number,_index,_second_index,_temporary,_increment,_result,_input,length_first,length_second;
vector<int>_how_many_in_once[10000];

int main()
{
	cin>>number;
	_increment=1;
	for(_index=1; _index<=number; _index++)
	{
		cin>>_input;
		if(check[_input]==0)
		{
			check[_input]=_increment;
			_how_many_in_once[_increment].push_back(_index);
			_increment++;
		}
		else _how_many_in_once[check[_input]].push_back(_index);
	}
	_increment=_increment-1;
	_result=0;
	for(_index=1; _index <= _increment; _index++)
	{
		for(_second_index=1; _second_index <= _increment; _second_index++)
		{
			_result=max(_result,length_calculation(_index,_second_index));
		}
	}
	cout<<_result<<endl;
}

int length_calculation(int _first,int _second)
{
	if(_first == _second) return _how_many_in_once[_first].size();
	
	length_first=_how_many_in_once[_first].size();
	length_second=_how_many_in_once[_second].size();
	
	int fst=0,snd=0,_count=0,ch=0;
	
	while(fst < length_first && snd < length_second)
	{
		if(_how_many_in_once[_first][fst]<_how_many_in_once[_second][snd])
		{
			if(ch==0||ch==_second) 
			{
				_count++;
				ch=_first;
			}
			fst++;
		}
		else
		{
			if(ch==0||ch==_first) 
			{
				_count++;
				ch=_second;
			}
			snd++;
		}
	}
	if(fst==length_first && snd<length_second && ch==_first) _count++;
	else if(snd==length_second && fst<length_first && ch==_second) _count++;
	
	return _count;
}
		
