#include<iostream>
#include<cstring>
using namespace std;
string set; //input given by the user
string elmnt; //element pulled out of input
int elmntN=0; //locationg where elements will be stored in array
string Subset(int subLength,int elmntN,int dist, string array[]);
int main(){
   cout<<"Enter the set of elements: ";
   cin>>set;
   string elmntArray[set.length()];			//element array
   for(int i=0; i<=set.length()+1;i++){			//runs through everycharacter in set string
    if(set[i]!=','){					//runs if the character is not a comma
     elmnt+=set[i];					//adds characters from element into a string
       if(set[i+1]=='\0'){				//runs if it is the end of the string
         elmntArray[elmntN]=elmnt;			//adds element into element array
          //  cout<<"Elmnt array: "<<elmntArray[elmntN]<<endl;
          // cout<<"Elmnt number: "<<elmntN<<endl;
          break;
	 elmnt="";					//clears element string for next element
       } 
    }else if(set[i]==','){				//runs if there is a comma 
      elmntArray[elmntN]=elmnt;				//adds element into element array	
      // cout<<"Elmnt array: "<<elmntArray[elmntN]<<endl;
      // cout<<"N: "<<elmntN<<endl;
      elmntN++;						//goes to next locations in array for next element
      elmnt="";						//clears element string for next element

    }//end of if statement
  }//end of for loop
  int subLength=elmntN+1;
  int dist=0; 
  int max=elmntN;
  string subset;
  cout<<"empty set"<<endl;
  for( int i=1;i<=subLength;i++){				//for loop that goes through all lengths of sub set 
    for(int j=0;j<=elmntN;j++){
       dist=1;
	if(i==1){
	  cout<<" { "<<Subset(i,j,dist,elmntArray)<<" }"<<endl;    
        }else{
          while(dist+j<=max){
           // cout<<" I: "<<i<<" J: "<<j<<" Subset:"<<elmntArray[j]<<endl;
	    cout<<" { "<<Subset(i,j,dist,elmntArray)<<" }"<<endl;    
          // cout<<"Dist: "<<dist<<" Max: "<<max<<endl;
           dist++; 
          }
          
        } 
        
    }
  }

}

string Subset(int subLength, int elmnt,int dist, string elmntArray[]){
  string subset;
  if(subLength==1){
   elmntArray[elmnt];
   //cout<<"Less than 1: "<<" I: "<<subLength<<" J: "<<elmnt<<" Subset:"<<subset<<endl;
   return elmntArray[elmnt];
  }else if(elmntArray[elmnt+1]!="\0"){
 
   subset+=elmntArray[elmnt];
   subset+=",";
   subset+=Subset(subLength-1,elmnt+dist,dist,elmntArray);  
   
   //cout<<"Inside subset: "<<" I: "<<subLength-1<<" J: "<<elmnt<<" Subset:"<<subset<<endl;
   return subset;
 
  }
}
