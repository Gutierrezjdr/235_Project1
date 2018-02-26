#include<iostream>
#include<cstring>
#include<string.h>
using namespace std;

string set; //set 
char *setPtr; //Where set string will be stored in to be used for string token
char *elmnt;
char *result; //where outputs of string token will be stored in
int elmntN=0; //Number of elements
int main(){
  cout<<"Enter a set of elements: ";
  cin>>set;
  cout<<set<<endl;
  setPtr=new char[set.length()+1];
  strcpy(setPtr,set.c_str()); //copies a pointer version of the input into the pointer array so that be may split it up with stirng token
  elmnt=new char[set.length()];
  result=strtok(setPtr,",");
//  strcpy(elmnt[elmntN],result);
  elmnt[elmntN]=result;
  while(result!=NULL){
    result=strtok(NULL,",");
    elmntN++;
    elmnt[elmntN]=result;
    //strcpy(elmnt[elmntN],result);
    cout<<elmnt[elmntN];

  }
  

}
