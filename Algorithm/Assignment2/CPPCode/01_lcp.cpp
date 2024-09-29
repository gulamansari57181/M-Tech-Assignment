#include <iostream>


using namespace std;
string longestCommonPrefix(string words[],int len) {
        
        // Base case if no words in the string array
        if (len == 0) return "";

        // Initializing first word in the array of string as prefix
        string prefix = words[0];

        // Iterating over rest all the words in the array

        for( int word=1;word<len;word++){

            int ch=0;

            // To get common part of the our current word and comparing word
            while(ch<prefix.length() && ch<words[word].length() && prefix[ch]==words[word][ch] ){
                ch++;
            }

            //Updating our current prefix, as per common part

            prefix=prefix.substr(0,ch);

            // To check if prefix become empty then return ans as ""
            if (prefix==""){
                return "";
            } 
        }
 
        return prefix;
    }

int main() {

    int length;

// Initializing string of arrays and taking input 
    cout<<"Enter Number of strings : ";
    cin>>length;
    string words[length];

    for(int i =0; i<length;i++){
        
        cout<<"Enter "<<i+1<<" word :";
        cin>>words[i];
    }

   // Calling function to find longest common prefix
   string lcp=longestCommonPrefix(words,length);

   if (lcp==""){
    cout<<"Longest common prefix is empty string.";
   }
   else{
    cout<<"Longest common prefix : "<<lcp;
   }

    return 0; 
   
}