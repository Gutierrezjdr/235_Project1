#include<iostream>
#include<cstring>
using namespace std;
string set; //input given by the user
string elmnt; //element pulled out of input
int elmntN=0; //locationg where elements will be stored in array
int main(){
   cout<<"Enter the set of elements: ";
   cin>>set;
   string elmntArray[set.length()];			//element array
   for(int i=0; i<set.length()+1;i++){			//runs through everycharacter in set string
    if(set[i]!=','){					//runs if the character is not a comma
     elmnt+=set[i];					//adds characters from element into a string
       if(set[i]=='\0'){				//runs if it is the end of the string
         elmntArray[elmntN]=elmnt;			//adds element into element array
         cout<<"Elmnt array: "<<elmntArray[elmntN]<<endl;
         elmntN++;					//goes to next location in array where next element will be stored
         elmnt="";					//clears element string for next element
        
    }else if(set[i]==','){				//runs if there is a comma 
      elmntArray[elmntN]=elmnt;				//adds element into element array	
      cout<<"Elmnt array: "<<elmntArray[elmntN]<<endl;
      elmntN++;						//goes to next locations in array for next element
      elmnt="";						//clears element string for next element

    }//end of if statement
  }//end of for loop



}
