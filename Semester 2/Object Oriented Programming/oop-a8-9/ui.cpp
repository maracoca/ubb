//
// Created by mara on 3/24/2024.
//

#include <iostream>
#include "ui.h"
#include "Movie.h"
#include "Service.h"
#include "csvWL.h"
#include "HTMLwl.h"
#include "Exceptions.h"

using namespace std;

UI::UI(): service("Movies.txt"){
   // this->service = Service("Movies.txt");
//    this->service.generate10RandomMovies();
}

UI::~UI(){}


void UI::initialMenu(){
    string title, genre, trailer, year, likes, userOption;

    bool choiceMade = false;
    while(!choiceMade) {
        std::cout << "Choose the type of file you want to use for the watchlist (CSV/ HTML)" << std::endl;
        std::string choice;
        std::cin >> choice;
        if (choice == "CSV") {
            this->service.setTypeOfWatchList(new CSVWatchList{"CSVWatchList.csv"});
            choiceMade= true;
        } else if (choice == "HTML") {
            this->service.setTypeOfWatchList(new HTMLWatchList{"HTMLWatchList.html"});
            choiceMade= true;
        } else
            std::cout << "Invalid choice!" <<endl;
    }

    cout << "0. Exit" << endl;
    cout << "1. Administrator mode" << endl;
    cout << "2. User mode" << endl;
    cout << "Please enter your choice:" << endl;
}

int UI::administrator(){
    string title, genre, trailer, year, likes, userOption;

    while (true) {
        cout<<"0. Back"<<endl;
        cout<<"1. Print all movies." <<endl;
        cout<<"2. Add a movie." <<endl;
        cout<<"3. Update a movie." <<endl;
        cout<<"4. Remove a movie." <<endl;
        cout<<"What do you want to do next?" <<endl;

        while (true) {
            cin >> userOption;

            try {
                stoi(userOption);
            }
            catch (const exception &caughtException) {
                cout << "Invalid choice! Try again." << endl;
                continue;
            }
            break;
        }
        int userOptionInt = stoi(userOption);

        if (userOptionInt == 1) {
//            for (int i = 0; i < this->service.getLengthService(); i++) {
//                Movie movie = this->service.getMovieOnPositionService(i);
            const auto& movies = service.getMoviesService();
            for (const auto& movie : movies){
                cout << "Title: " << movie.getTitle() << " genre: " << movie.getGenre() << " year: " << movie.getYear() <<" likes: " << movie.getLikes() << " trailer: " << movie.getTrailer() << endl;
            }
        }

        else if (userOptionInt == 2) {
            cin.ignore();
            cout << "Add a title." << endl;
            getline(cin, title);
            cout << "Add a genre." <<endl;
            getline(cin, genre);
            cout << "Add an year." <<endl;
            cin >> year;
            cin.ignore();
            cout << "Add the number of likes." <<endl;
            cin >> likes;
            cin.ignore();
            cout << "Add the trailer." <<endl;
            getline(cin, trailer);

            try{
                MovieExceptions::validateMovieIdentifiers(title, genre, year, trailer, likes);
            }
            catch (MovieExceptions &errorsCaught){
                for (const auto &errorCaught : errorsCaught.returnErrors())
                    std::cout << errorCaught.what() << endl;
                continue;
            }

            int year_int = stoi(year);
            int likes_int = stoi(likes);

            Movie movie = Movie(title, genre, year_int, likes_int, trailer);
            try{
                this->service.addService(movie);
            }
            catch (RepositoryException &caughtException)
            {
                std::cout << caughtException.what() << endl;
                continue;
            }
            cout << "Movie added." << endl;

//            try {
//                stoi(year);
//                stoi(likes);
//            }
//            catch (const std::exception &caughtException) {
//                cout << "Year and likes must be positive integers!" << endl;
//                continue;
//            }
//
//            int year_int = stoi(year);
//            int likes_int = stoi(likes);
//            Movie movie = Movie(title, genre, year_int, likes_int, trailer);
//
//            try {
//                movie.checkTitle(title);
//                movie.checkGenre(genre);
//                movie.checkYear(year_int);
//                movie.checkLikes(likes_int);
//                movie.checkTrailer(trailer);
//            }
//            catch (const exception &caughtException) {
//                cout << "Invalid movie!" << endl;
//                continue;
//            }
//
//            if (this->service.addService(movie) == 1) {
//                cout << "Movie added." << endl;
//            } else
//                cout << "Movie already added." << endl;
        }

        else if (userOptionInt == 3) {
//            for (int i = 0; i < this->service.getLengthService(); i++) {
//                Movie movie = this->service.getMovieOnPositionService(i);
            int i=0;
            const auto& movies = service.getMoviesService();
            for (const auto& movie : movies){
                cout << i+1 << " Title: " << movie.getTitle() << " genre: " << movie.getGenre() << " year: " << movie.getYear() <<" likes: " << movie.getLikes() << " trailer: " << movie.getTrailer() << endl;
                i++;
            }
            int position;
            cout << "Choose a movie (position) that you want to update." << endl;
            cin>>position;

            try{
                this->service.getMovieOnPositionService(position);
            }
            catch (PositionException &caughtException)
            {
                std::cout << caughtException.what() << "\n";
                continue;
            }

            cin.ignore();
            cout << "Add a title." << endl;
            getline(cin, title);
            cout << "Add a genre." <<endl;
            getline(cin, genre);
            cout << "Add an year." <<endl;
            cin >> year;
            cin.ignore();
            cout << "Add the number of likes." <<endl;
            cin >> likes;
            cin.ignore();
            cout << "Add the trailer." <<endl;
            getline(cin, trailer);

            try{
                MovieExceptions::validateMovieIdentifiers(title, genre, year, trailer, likes);
            }
            catch (MovieExceptions &errorsCaught){
                for (const auto &errorCaught : errorsCaught.returnErrors())
                    std::cout << errorCaught.what() << endl;
                continue;
            }

            int year_int = stoi(year);
            int likes_int = stoi(likes);

            Movie movie = Movie(title, genre, year_int, likes_int, trailer);
//            try{
            this->service.updateMovieService(position-1, movie);
//            }
//            catch (RepositoryException &caughtException)
//            {
//                std::cout << caughtException.what() << endl;
//                continue;
//            }


//            try {
//                    stoi(year);
//                    stoi(likes);
//            }
//            catch (const exception &caughtException)
//            {
//                cout << "Year and likes must be positive integers!" << endl;
//                continue;
//            }

//            int year_int = stoi(year);
//            int likes_int = stoi(likes);
//            Movie movie = Movie(title, genre, year_int, likes_int, trailer);

//            try
//            {
//                movie.checkTitle(title);
//                movie.checkGenre(genre);
//                movie.checkYear(year_int);
//                movie.checkLikes(likes_int);
//                movie.checkTrailer(trailer);
//            }
//            catch (const exception &caughtException)
//            {
//                cout << "Invalid movie!" << endl;
//                continue;
//            }
//            this->service.updateMovieService(position -1, movie);
        }

        else if (userOptionInt == 4){
            int userChoice;
//            cout << "Choose an option for removal." << endl;
//            cout << "Write the title, genre, year, number of likes and tutorial." << endl;
//            cout << "2. Remove by position." << endl;
//            cin >> userChoice;

//            if (userChoice == 1) {
//                for (int i = 0; i < this->service.getLengthService(); i++) {
//                    Movie movie = this->service.getMovieOnPositionService(i);
//                int i=0;
//                const auto& movies = service.getMoviesService();
//                for (const auto& movie : movies){
//                    cout << i + 1 << " Title: " << movie.getTitle() << " genre: " << movie.getGenre() << " year: " << movie.getYear() <<" likes: " << movie.getLikes() << " trailer: " << movie.getTrailer() << endl;
//                    i++;
//                }
//
//                cin.ignore();
//                cout << "Add a title." << endl;
//                getline(cin, title);
//                cout << "Add a genre." << endl;
//                getline(cin, genre);
//                cout << "Add an year." << endl;
//                cin >> year;
//                cin.ignore();
//                cout << "Add the number of likes." << endl;
//                cin >> likes;
//                cin.ignore();
//                cout << "Add the trailer." << endl;
//                getline(cin, trailer);
//
////                try {
////                    stoi(year);
////                    stoi(likes);
////                }
////                catch (const exception &caughtException) {
////                    cout << "Year and likes must be positive integers!" << endl;
////                    continue;
////                }
//
//                try{
//                    MovieExceptions::validateMovieIdentifiers(title, genre, year, trailer, likes);
//                }
//                catch (MovieExceptions &errorsCaught){
//                    for (const auto &errorCaught : errorsCaught.returnErrors())
//                        std::cout << errorCaught.what() << endl;
//                    continue;
//                }
//
//                int year_int = stoi(year);
//                int likes_int = stoi(likes);
//                Movie movie = Movie(title, genre, year_int, likes_int, trailer);
//
////                try {
////                    movie.checkTitle(title);
////                    movie.checkGenre(genre);
////                    movie.checkYear(year_int);
////                    movie.checkLikes(likes_int);
////                    movie.checkTrailer(trailer);
////                }
////                catch (const exception &caughtException) {
////                    cout << "Invalid movie!" << endl;
////                    continue;
////                }
//
//                if (this->service.removeService(movie) == 1) {
//                    cout << "Movie deleted." << endl;
//                } else
//                    cout << "Movie not in list." << endl;
//            }

//            else if (userChoice == 2){
                int i = 0;
                const auto& movies = service.getMoviesService();
                for (const auto& movie : movies){
                    cout << i + 1 << " Title: " << movie.getTitle() << " genre: " << movie.getGenre() << " year: " << movie.getYear() <<" likes: " << movie.getLikes() << " trailer: " << movie.getTrailer() << endl;
                    i++;
                }

                int position;
                cout << "Choose a movie (position) that you want to remove." << endl;
                cin>>position;

//                if (position > this->service.getLengthService()){
//                    cout<<"Invalid position."<<endl;
//                    continue;
//                }

                try{
                    this->service.getMovieOnPositionService(position);
                }
                catch (PositionException &caughtException)
                {
                    std::cout << caughtException.what() << "\n";
                    continue;
                }

                Movie movie = this->service.getMovieOnPositionService(position - 1);
                if (this->service.removeService(movie) == 1) {
                    cout << "Movie deleted." << endl;
                } else
                    cout << "Movie not in list." << endl;
            }
//        }

        else if(userOptionInt==0) {
            this->ui();
            break;
        }

        else
            cout<< "Invalid input!"<<endl;
    }
}

void UI::User() {
    string title, genre, trailer, year, likes, userOption;

    while (true) {
        cout << "0. Back"<<endl;
        cout << "1. Get movies by genre"<<endl;
        cout << "2. Delete a movie from the watchlist"<<endl;
        cout << "3. Display watchlist"<<endl;

        while (true) {
            cin >> userOption;

            try {
                stoi(userOption);
            }
            catch (const exception &caughtException) {
                cout << "Invalid choice! Try again." << endl;
                continue;
            }
            break;
        }
        int userOptionInt = stoi(userOption);

        if (userOptionInt == 1) {
            string genreInput;
            string nextMovie, addMovie;
            cin.ignore();
            cout << "Enter the genre of the movies you want to see: " << endl;
            getline(cin, genreInput);

            vector<Movie> movies = service.getMoviesByGenre(genreInput);
            if (movies.size() == 0)
                cout<<"No movies of this genre!"<<endl;
            int pos = 0;
            while (pos < movies.size()) {
                Movie movie = movies[pos];
                cout << "Title: " << movie.getTitle() << " genre: " << movie.getGenre() << " year: "
                     << movie.getYear() << " likes: " << movie.getLikes() << " trailer: " << movie.getTrailer() << endl;
                this->service.openTrailer(pos);

                //cin.ignore();
                cout << "Do you want to add this tutorial to your wishlist ? (yes/no)" << endl;
                cin >> addMovie;
                cin.ignore();
                if (addMovie == "yes") {
                    this->service.addMovieToWatchList(movie);
                    movies.erase(movies.begin()+pos);
                    if (movies.size() == 0) {
                        cout << "All movies added in watch list!" << endl;
                        break;
                    }
                }

                //cin.ignore();
                cout << "Do you want to see the next movie? (yes/no)" << endl;
                cin >> nextMovie;
                if (nextMovie == "no")
                    break;
                else if (nextMovie == "yes") {
                    if (addMovie != "yes")
                        pos++;
                    if (pos >= movies.size())
                        pos = 0;
                }
            }
        }
        else if (userOptionInt == 2){
            int pos;
            string likedMovie;
            int i = 0;
            vector<Movie> movies = service.getMoviesTheUserLikes();
            for (const auto& movie : movies) {
               // Movie movie = this->service.getMovieOnPositionWatchList(i);
                cout << i + 1 << " Title: " << movie.getTitle() << " genre: " << movie.getGenre() << " year: "
                     << movie.getYear() << " likes: " << movie.getLikes() << " trailer: " << movie.getTrailer() << endl;
                i++;
            }
            cout << "Enter the position of the movie you want to delete from your watchlist:"<<endl;
            cin >> pos;

//            if (pos > this->service.getLengthWatchlist()){
//                cout<<"Invalid position."<<endl;
//                continue;
//            }

            try{
                this->service.getMovieOnPositionWatchList(pos-1);
//                cout << "Did you like the movie? (y/n):"<<endl;
//                cin >> likedMovie;
//                //choiceOfUser = tolower(choiceOfUser);
//                if (likedMovie == "yes")
//                    this->service.increaseLikesOfMovie(pos-1);
//
//                this->service.removeWatchList(pos-1);
            }
            catch (PositionException &caughtException)
            {
                std::cout << caughtException.what() << "\n";
                continue;
            }

           // if (this->service.getMovieOnPositionWatchList(pos-1)>0) {
           if (pos-1 < this->service.getMoviesTheUserLikes().size()){
                cout << "Did you like the movie? (yes/no):" << endl;
                cin >> likedMovie;
                //choiceOfUser = tolower(choiceOfUser);
                if (likedMovie == "yes")
                    this->service.increaseLikesOfMovie(pos - 1);

                this->service.removeWatchList(pos - 1);
            }
        }

        else if (userOptionInt == 3) {
//            int i = 0;
//            vector<Movie> movies = service.getMoviesTheUserLikes();
//            for (const auto& movie : movies) {
//                //Movie movie = this->service.getMovieOnPositionWatchList(i);
//                cout << i + 1 << " Title: " << movie.getTitle() << " genre: " << movie.getGenre() << " year: "
//                     << movie.getYear() << " likes: " << movie.getLikes() << " trailer: " << movie.getTrailer() << endl;
//                i++;
//            }
            this->service.displayPlaylist();
        }

        else if(userOptionInt == 0){
            this->ui();
            break;
        }
        else
            cout<< "Invalid input!"<<endl;
    }
}

void UI::ui() {
    string userInput;
    this->initialMenu();

    while (true) {
        cin >> userInput;

        try {
            int userInputInt = stoi(userInput);
            if (userInputInt < 0 || userInputInt > 2) {
                throw invalid_argument("Invalid choice! Try again.");
            }
        }
        catch (const exception &caughtException) {
            cout << "Invalid choice! Try again." << endl;
            continue;
        }
        break;
    }

    int userInputInt = stoi(userInput);

    if (userInputInt == 1)
        this->service.setAdminCredentials(true);
    else if (userInputInt == 2)
        this->service.setAdminCredentials(false);
    else if (userInputInt == 0)
        return;

    if (userInputInt == 1 or userInputInt == 2) {
        if (this->service.getAdminCredentials())
            this->administrator();
        else
            this->User();
    }
}