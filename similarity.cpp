//ben kissiouer imane
#include <iostream>
#include <fstream>
#include <string.h>
#include <sstream>
#include <map>
#include <cmath>
#include <vector>


using namespace std;
vector<int> wordsCount(string str){

      int count = 1;
      //key value pair map
      //key = word, value = count
      std::map<string,int> wordsMap;
      
	vector<int> v;

      //extract words and push in map
      istringstream wordStream(str);

      string word;
      //Extract each words and add to map
      //if it does not exist in map
	while(wordStream >> word){
	pair<map<string,int>::iterator,bool> retrunValue;
	//insert element
	retrunValue = wordsMap.insert( pair<string,int>(word,count));

            //Check if map contains value
            if (retrunValue.second==false)
            {
                  //Element already exists
                  ++retrunValue.first->second; 
            }     
       }//while

       //Iterate elements and print words 
       map<string,int>::iterator itr ;

       for (itr = wordsMap.begin(); itr != wordsMap.end(); ++itr){
		v.push_back(itr->second);

       }

return v;
}


double cosine_similarity(vector<int> v1,  vector<int> v2)
{
int s1=v1.size();
int s2=v2.size();

if (s1>s2 ) {
for (int i=0 ; i<s1-s2 ; i++){
v2.push_back(0);
}
}

else if (s2>s1 ){
for (int i=0 ; i<s2-s1 ; i++){
v1.push_back(0);
}
}


    double dot = 0.0, denom_a = 0.0, denom_b = 0.0 ;
     for(unsigned int i = 0u; i < v1.size(); ++i) {
        dot += v1[i] * v2[i] ;
        denom_a += v1[i] * v1[i] ;
        denom_b += v2[i] * v2[i] ;
    }




    return dot / (sqrt(denom_a) * sqrt(denom_b)) ;
}



string filetostring ( istream &file) {
stringstream buffer;
string content ;
buffer << file.rdbuf();
content=buffer.str();
return content;

} 


int main(int argc, char *argv[]) {

vector<int> v1,v2;

string file_content,file_content2;

string fn1=argv[1];
string fn2=argv[2];
ifstream file1(fn1);
ifstream file2(fn2);

file_content = filetostring(file1);
file_content2= filetostring(file2);



v1=wordsCount (file_content);
v2=wordsCount( file_content2);

double s =cosine_similarity(v1,v2);
cout << "files similarity is :" << s*100 << "%" ;



return 0;




}
