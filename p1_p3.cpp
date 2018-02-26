#include<iostream>
#include<string>
#include<sstream> 
using namespace std;
int x;
int n;
int inputN;
string container;
//char array[];
string arrayInput; 

string Set(int length, int max,int arrayMin, int arrayMax, string array[]);
int main(){
  cout<<"x= ";
  cin>>x; 
  cout<<"n= ";
  cin>>n;
  cout<<"A= ";
  cin>>arrayInput; 
  string input[arrayInput.length()];
  for(int i=0; i<=arrayInput.length();i++){			//runs through every character in set string
    if(arrayInput[i]!=','){					//runs if the character is not a comma therefore a number
     container+=arrayInput[i];					//adds characters from element into a string
       if(arrayInput[i+1]=='\0'){				//runs if the next position is the end of the string
        input[inputN]=container;			        //stores container input into he array
         break;                                                 //exits the for loop since it is the end of the string
	 container="";					        //clears element string just in case
        } 
    }else if(arrayInput[i]==','&& arrayInput[i+1]!='\0'){	//runs if there is a comma 
      input[inputN]=container;					//adds element into element array
      inputN++;							//goes to next locations in array for next element
      container="";						//clears element string for next element

    }//end of if statement
  }//end of for loop
  int inputStart=0;						//first number of array for function input
  cout<<Set(n,x,inputStart,inputN,input)<<endl; 
    
}
//does binary search until it finds a number ledd than the given maximum
string Set(int length, int max,int arrayMin, int arrayMax , string array[]){	//Creates sets according to given length and maximum
  string output;								//where ouput will be stores and added
  int arrayMid=0;								// variable for middle of array
  if(arrayMax!=0){								//will run if the maximum of the array is NOT 0	 
    if(stoi(array[arrayMid])>=max){						// runs if the number at the middle of the array is >= to maximum that was given
       arrayMid=(arrayMin+arrayMax)/2;						//finds the middle location of the array 
       arrayMax=arrayMid;							//makes the maximum equal to the middle if the number at that location is more than or equal to the max
       Set(length,max,arrayMin,arrayMax,array);					//calls set function again 
    }else if(stoi(array[arrayMid])<max){					//runs if the number at specified location is less than mazimum
         for(int j=0;j<arrayMax;j++){						//goes through the array from is starting position
            if(stoi(array[j])<max &&length!=0){					//prints out if number is less than max and length is not 0
                output+=array[j];		
                if(length!=1)   output+=",";					//only adds a comma if it is not the end of the set
                else output+=" ";
                length--;							//reduces legth until it is 0 so that it onyl prints the lengths worth fo numbers
            }else{
             break; 
            }
         }
       
        return output;

    }
  }else{							//runs if the array location is 0
     
         for(int j=0;j<arrayMax;j++){                          //same code as above
            if(stoi(array[j])<max &&length!=0){
                output+=array[j];
                if(length!=1)   output+=" , ";
                else output+=" ";
                length--;
            }else{
             break; 
            }
         }
   return output;
    
  }


}
