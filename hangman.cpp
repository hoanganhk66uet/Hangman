#include<iostream>
#include<string>
#include<cstdlib>
#include <ctime>


using namespace std;
string chooseWord();
void reset(string& guessedWord,int& badGuessCount,string& secretWord);
void renderGame(string guessedWord,int badGuessCount);
char readAGuess();
bool contains(string secretWord,char guess);
string update(string guessedWord,string secretWord,char guess);
void result(string secretWord,string guessedWord);
bool again();
const MAX_BAD_GUESSES=7;
const string WORD_LIST[]={
"angle", "ant", "apple", "arch", "arm", "army",
 "baby", "bag", "ball", "band", "basin", "basket", "bath", "bed", "bee", "bell", "berry", "bird", "blade", "board", "boat", "bone", "book", "boot", "bottle", "box", "boy",
 "brain", "brake", "branch", "brick", "bridge", "brush", "bucket", "bulb", "button",
 "cake", "camera", "card", "cart", "carriage", "cat", "chain", "cheese", "chest",
 "chin", "church", "circle", "clock", "cloud", "coat", "collar", "comb", "cord",
 "cow", "cup", "curtain", "cushion",
 "dog", "door", "drain", "drawer", "dress", "drop", "ear", "egg", "engine", "eye",
 "face", "farm", "feather", "finger", "fish", "flag", "floor", "fly",
 "foot", "fork", "fowl", "frame", "garden", "girl", "glove", "goat", "gun",
 "hair", "hammer", "hand", "hat", "head", "heart", "hook", "horn", "horse",
 "hospital", "house", "island", "jewel", "kettle", "key", "knee", "knife", "knot",
 "leaf", "leg", "library", "line", "lip", "lock",
 "map", "match", "monkey", "moon", "mouth", "muscle",
 "nail", "neck", "needle", "nerve", "net", "nose", "nut"
    };

const int WORD_COUNT=sizeof(WORD_LIST)/sizeof(string);    

const string FIGURE[] = {
 " ------------- \n"
 " | \n"
 " | \n"
 " | \n"
 " | \n"
 " | \n"
 " ----- \n",

 " ------------- \n"
 " |    | \n"
 " | \n"
 " | \n"
 " | \n"
 " | \n"
 " ----- \n",

 " ------------- \n"
 " |    | \n"
 " |    O \n"
 " | \n"
 " | \n"
 " | \n"
 " ----- \n",

 " ------------- \n"
 " |    | \n"
 " |    O \n"
 " |    | \n"
 " | \n"
 " | \n"
 " ----- \n",

 " ------------- \n"
 " |    | \n"
 " |    O \n"
 " |   /| \n"
 " | \n"
 " | \n"
 " ----- \n",

 " ------------- \n"
 " |    | \n"
 " |    O \n"
 " |   /|\\ \n"
 " | \n"
 " | \n"
 " ----- \n",

 " ------------- \n"
 " |    | \n"
 " |    O \n"
 " |   /|\\ \n"
 " |   / \n"
 " | \n"
 " ----- \n",

 " ------------- \n"
 " |    | \n"
 " |    O \n"
 " |   /|\\ \n"
 " |   / \\ \n"
 " | \n"
 " ----- \n"

 };

int main(){
    string secretWord;
    string guessedWord;
    int badGuessCount;
    
    do{
        reset(guessedWord, badGuessCount,secretWord);
    
        do{
        renderGame(guessedWord,badGuessCount);
        char guess=readAGuess();
        if(contains(secretWord,guess))
            guessedWord=update(guessedWord,secretWord,guess);
        else badGuessCount++;    
        }while(badGuessCount<MAX_BAD_GUESSES&& secretWord!=guessedWord);
        result(secretWord, guessedWord);

    } while(true==again());
    
    system("pause");
    return 0;
}
string chooseWord(){
    srand(time(NULL));
    int randomIndex=rand()% WORD_COUNT;
    return WORD_LIST[randomIndex];
}
void reset(string& guessedWord,int& badGuessCount,string& secretWord){
    system("cls");
    secretWord=chooseWord();
    guessedWord=string(secretWord.length(),'-');
    badGuessCount=0;

}

void renderGame(string guessedWord,int badGuessCount){
    system("cls");
    cout<<FIGURE[badGuessCount]<<endl;
    cout<< guessedWord<<endl;
    cout<<"Number of wrong guesses: "<<badGuessCount<<endl;
    
    
}
char readAGuess(){
    char readWord;
    cin>>readWord;
    return readWord;
}
string update(string guessedWord,string secretWord,char guess){
    for(int i=0;i<secretWord.length();i++){
        if(secretWord[i]==guess) guessedWord[i]=guess;

    }
    return guessedWord;
}
bool contains(string secretWord,char guess){
    bool result=false;
    for(int i=0;i<secretWord.length();i++){
    if(secretWord[i]==guess) result=true;
    }
    return result;
    
}
void result(string secretWord,string guessedWord){
    system("cls");
    if(secretWord==guessedWord) cout<<secretWord<<endl<<"Congratulate you win!"<<endl;
    else {
        cout<<FIGURE[7];
        cout<<"SecretWord is "<<secretWord<<". You lose!"<<endl;}
}
bool again(){
    char answer;
    do{
        cout<<"Wanna try again? (y/n):";
        cin>>answer;
        if(answer=='y'||answer=='Y'){ return true;break;}
        if(answer=='n'||answer=='N'){ return false;break;}
    }while(1);
}


