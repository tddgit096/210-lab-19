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
            cout<<"No reviews currently.\n";
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

void outputAll(vector<Movie*> mVect);

int main(){
    vector<Movie *> movies; 
    ifstream file;
    file.open("data.txt");
    if(file.good()){
        string line;
        while (getline(file,line)){
            getline(file,line);
            Movie * M = new Movie(line);
            getline(file,line);
            while(line!="-"){
                float rating = stof(line);
                getline(file,line);
                M->inputReview(rating,line);
            }
            movies.push_back(M);
        }           
        file.close();
    }
    else
        cout<<"File not found.\n";


        /**/


    /*
    //testcode, replace with data reader from file.
    for(int i=0;i<2;i++){
        cout<<"Input title of Movie #"<<i+1<<": ";
        string title;
        cin.ignore();
        getline(cin,title);
        movies.push_back(new Movie(title)); //this will prompt review entry
    }
    */
    
    outputAll(movies);
    return 0;
}

void outputAll(vector<Movie*> mVect){
    for(Movie * M : mVect){
        M->output();
    }
}