//COMSC 210 | Lab 19| Toma Dimov
//TODO
//read review comments from external file
//write a driver/demo program that will have at least 4 movie objs with at least 3 reviews.

#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

struct Review{
    float rating;
    string comment;
    Review* next;
//constructors
    Review(){}
    Review(float rating,string comment){this->rating=rating;this->comment=comment;next=nullptr;}
};

class Movie{
    string title;
    Review * reviews;

    public:
//setters & getters
    void setTitle(string t){title=t;}
    string getTitle(){return title;}
//constructors
    Movie(string title){
        setTitle(title);
    }
//output reviews
    void output(){
        cout<<"Movie Title: "<<getTitle()<<endl;
        if(!reviews){
            cout<<"\tNo reviews currently.\n\n";
            return;
        }
        int count = 1;
        float sum = 0;
        Review *ReviewPtr = reviews;
        while(ReviewPtr){
            cout<<"\tReview #"<<count<<": "<<ReviewPtr->rating<<" :   \""<<ReviewPtr->comment<<"\"\n";
            sum+=ReviewPtr->rating;
            ReviewPtr=ReviewPtr->next;
            count++;
        }
        cout<<"\t\tAverage: "<<  sum/(count-1)<<"\n\n"; 
    }
//input reviews:
    void inputReview(float rating, string comment){
        Review * N = new Review(rating,comment);
        if(!reviews){ //empty head
            reviews = N;
        }
        else{
            N->next = reviews;
            reviews = N; 
        }
    }
};

void outputAll(vector<Movie*> mVect); //calls output on all movie objects in vector.
void parseRawInput(vector<string>, vector<Movie*>&); //takes string values from data reading in main. Creates movie instances with reviews then stores it into the move array by reference.

int main(){
    vector<Movie *> movies; 
    ifstream file;
    vector<string> inputVect; //vector stores raw string data, manipulated by parseRawInput() later in main to create movie instances.
    file.open("data.txt");
    if(file.good()){
        string line;
        while (getline(file,line))
            inputVect.push_back(line); //store directly into vector to be parsed later.          
        file.close();
    }
    else
        cout<<"File not found.\n";

    parseRawInput(inputVect, movies);
    outputAll(movies);
    return 0;
}

void parseRawInput(vector<string>inputVect, vector<Movie*>& moVect ){
    for(int i=0;i<inputVect.size();i++){
        Movie * M = new Movie(inputVect[i]);
        i++;
        while(inputVect[i]!="-"){
           float rating = stof(inputVect[i]);
           i++;
           M->inputReview(rating,inputVect[i]);
           i++;
        }
        moVect.push_back(M);
    }
}

void outputAll(vector<Movie*> mVect){
    for(Movie * M : mVect){
        M->output();
    }
}