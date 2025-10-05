//COMSC 210 | Lab 19| Toma Dimov
//TODO
//read review comments from external file
//main() container of movie objects. can be array ,vector, linked list.
//write a driver/demo program that will have at least 4 movie objs with at least 3 reviews.

#include <iostream>
#include <vector>
using namespace std;

struct Review{
    float rating;
    string comment;
    Review* next;
//constructors
    Review(){}
    Review(float rating,string comment){this->rating=rating;this->comment=comment;next=nullptr;}
};
//prototype functions
Review * promptData();
void output(Review*);

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
        promptReviews(reviews);    //new movie created, prompt user to input reviews on construction.
    }
//output reviews
    void outputReviews(){
        cout<<"Movie Title: "<<getTitle();
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
    void promptReviews(Review *& R){
        float rating;
        string comment;
        char yesno;
        R = nullptr;
        Review* ReviewPtr = R;
        while(true){
            cout<<"Enter review rating 0-5: ";
            cin>> rating;
            if(rating<0)
                rating=0;
            if(rating>5)
                rating=5;
            cout<<"Enter review comments: ";
            cin.ignore();
            getline(cin, comment);
            Review * N = new Review(rating,comment);
            if(!R){
                R=N;
                N->next=nullptr;
                ReviewPtr=N;
            }
            else{
                N->next = R;
                R=N;
            }
            cout<<"Enter another review? Y/N: ";
            cin>>yesno;
            if(tolower(yesno) == 'y')
                continue;    
            return;
        }
    }
};


int main(){
    vector<Movie *> movies; 
    //tempcode, replace with data reader from file.
    for(int i=0;i<2;i++){
        cout<<"Input title of Movie #"<<i+1<<": ";
        string title;
        getline(cin,title);
        movies.push_back(new Movie(title)); //this will prompt review entry
    }
    return 0;
}
