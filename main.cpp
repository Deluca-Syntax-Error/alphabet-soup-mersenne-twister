#include<iostream>
#include<string>
#include<random> //mt19937
using namespace std;

int prng(int a, int b) //prng using mersenne twister and random_device seed, in range of a(min number) + b(for max number)
{
	mt19937 mt{random_device{}()};
	int n = mt() % a + b; //get the number and covert it to the equivalent in the range of a + b

	return n;
}

int main()
{
	bool loop = 1;
	char op;
	int size; //size of array
	int cant; //nums of words
	cout<<"Choose the size of the Alphabetical soup\n1.20x20\n2.30x30"<<endl;
	while(loop)
	{
		cin>>op;
		switch(op)
		{
			case '1':
				size = 20;
				loop = 0;
				break;
			case '2':
				size = 30;
				loop = 0;
				break;
			default:
				cout<<"Incorrect option, only write the number(1 or 2)"<<endl;
		}
	}
	char soup[size][size]; //define soup
	do
	{
		cout<<"Insert the number of words, min of 7"<<endl;
		cin>>cant;
	}while(cant < 7);
	string words[cant];	//define words
	bool xIsOk=0;
	bool yIsOk=0;
	int posX[cant]; //position of word in x
	int posY[cant];	//position of word in y
	int dirX[cant];	//direction of words in x
	int dirY[cant]; //direction of words in y
	cout<<"Insert the words"<<endl;
	for(int i = 0; i < cant; i++)
	{
		do
		{
			cin>>words[i];
			if(words[i].length() > size)
			{
				cout<<"word length is more than size of soup"<<endl;
			}
		}while(words[i].length() > size);
	}
	for(int f = 0; f < size; f++)
	{
		for(int c = 0; c < size; c++)
		{
			soup[f][c] = prng(26,97);
			cout<<soup[f][c]<<' ';
		}
		cout<<endl;
	}
	for(int i=0; i < cant; i++)
	{
		do
		{
			if(!xIsOk)
			{
				posX[i]=prng(size,0);
				cout<<"posX of "<<i<<"="<<posX[i]<<endl;
				dirX[i]=prng(3,-1);
				cout<<"dirX of "<<i<<"="<<dirX[i]<<endl;
			}
			if(!yIsOk)
			{
				posY[i]=prng(size,0);
				cout<<"posY of "<<i<<"="<<posY[i]<<endl;
				dirY[i]=prng(3,-1);
				cout<<"dirY of "<<i<<"="<<dirY[i]<<endl;
			}
			if(dirX[i] != 0 || dirY[i] != 0)
			{
				if(posX[i] + words[i].length() * dirX[i] <= size && 
						posX[i] + words[i].length() * dirX[i] >=0)
				{
					xIsOk=1;
					cout<<"xOk of "<<i<<endl;
				}
 				if(posY[i] + words[i].length() * dirY[i] <= size && 
						posY[i] + words[i].length() * dirY[i] >=0)
				{
					yIsOk=1;
					cout<<"yOk of "<<i<<endl;
				}
			}	
		}while(!xIsOk || !yIsOk); 
		xIsOk=0;
		yIsOk=0;
		for(int c=0; c < words[i].length(); c++)
		{
			soup[posX[i]][posY[i]]=words[i][c];
			posX[i]+=dirX[i];
			posY[i]+=dirY[i];
		}
	}
		for(int f = 0; f < size; f++)
		{
			for(int c = 0; c < size; c++)
			{
				//soup[f][c] = prng(26,97);
				cout<<soup[f][c]<<' ';
			}
			cout<<endl;
		}
	return 0;
}
