#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cstdlib>
#include <stdio.h>

using namespace std;
int tokenize(string list);
//int  size(input: node N);
//void update(int L, int j, int k);

class Tlist
{
private:
  struct Node
  {
    Node();
    string token;
    int number;
    Node * next;
    Node * down;
  };
private:
  Node * first;
  Node * last;
  int size;
};

int tokenize(string list)
{
  vector<string> Ret;
  string in;
  
  for (int i = 0; i < list.length(); i++)
    {
      
      if (isdigit(list[i]))
	{
	  in += list[i];

	  if (list[i+1] == ',' || list[i+1] == ']'){
	    Ret.push_back(in);
	    in.clear();
	  }
	}
      /*
  
      if (list[i+1] == ',' || list[i+1] == ']'){
	Ret.push_back(in);
	in.clear();
	if (list[i] == ']')
	  {	     
	    in+=']';
	  }
	if (list[i] == '[')
	  {
	    in+='[';   
	  }
      */      
}
  
    
  int j = 0;
  
  //cout << "[";
  for (int i = 0; i < Ret.size()-1; i++)
    {
      cout << Ret[i] << ' ';
      j = i;
    }
  cout << Ret[j+1] << endl;// << "]" << endl;
  
  int line;
  cout << "Search: " << endl;
  cin >>  line;
	cout << Ret[line-1] << endl;
  for (int i = 0; i < Ret.size(); i++)
    {
    }
  
  return 0;
}

int main()
{
  string input;
  
  cout << "Please enter your generalized list: " << endl;
  getline (cin, input);
 

  tokenize(input);

  return 0;
}


/*
int size(input: node N)
{
  if (N is empty)
    return 0;
  else if (N contains a key)
    return 1;
  else
    return size(N->down) + size(N->next);
}

void update(int L, int j, int k) {
  // inputs: list L, integers j and k. Output: updated list L
  if (L is empty) {
    print appropriate error message (e.g. not valid to update empty list) return } // end if
  else if(L is a leaf){
    change the key to k; return;}
  else {
    s = size(L->down)
      if (j <= s) update(L->down, j, k)
	else
	  update(L->next, j – s, k)
	    } // end else } // end update
*/
