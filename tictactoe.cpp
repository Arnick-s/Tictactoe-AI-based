#include<bits/stdc++.h>
#include<stdlib.h>
using namespace std;

bool iswon(vector<char>&vec);
//normal mode
int normalmove(vector<char>&vec)
{
    for(int i=0;i<9;i++)
    {
        //check win;
        if(vec[i]!='O'&&vec[i]!='X')
        {
            vec[i]='X';
            if(iswon(vec))
            return i;
            vec[i]='1'+i;
        }
    }
    for(int i=0;i<9;i++)
    {
        //check lose;
        if(vec[i]!='O'&&vec[i]!='X')
        {
            vec[i]='O';
            if(iswon(vec))
            return i;
            vec[i]='1'+i;
        }
    }
    //any void position;
    for(int i=0;i<9;i++)
    {
        if(vec[i]!='O'&&vec[i]!='X')
        return i;
    }
    cout<<"Internal Error in Normal mode!"<<endl;
    return 0;
}


int evaluate(vector<char>&vec,bool maxturn)
{
    if(iswon(vec))
    {
        return (maxturn)?-10:10;
    }
    return 0;
}

bool moveleft(vector<char>&vec)
{
    for(int i=0;i<9;i++)
    {
        if(vec[i]!='X'&&vec[i]!='O')
        return true;

    }
    return false;
}


int minimax(vector<char> &vec,bool maxturn)
{
    int score=evaluate(vec,maxturn);

    if(abs(score)==10)
    return score;

    if(moveleft(vec)==false)
    return 0;
    
    if(maxturn)
    {
        int best=-1000;
        
        for(int i=0;i<9;i++)
        {
            if(vec[i]!='X'&&vec[i]!='O')
            {
                vec[i]='X';
                best=max(best,minimax(vec,false));
                vec[i]=i+'1';
            }
        }
        return best;
    }
    else{
            int best=1000;
        for(int i=0;i<9;i++)
        {
            if(vec[i]!='X'&&vec[i]!='O')
            {
                vec[i]='O';
                best=min(best,minimax(vec,true));
                vec[i]=i+'1';
            }
        }
        return best;
    }
    return 0;

}

int nextbestmove(vector<char> &vec)
{
    int best_val=-100;
    int bestmoveidx;
    for(int i=0;i<9;i++)
    {
        if(vec[i]!='X'&&vec[i]!='O')
        {
            vec[i]='X';
            int move_val=minimax(vec,false);
           
            if(move_val>best_val)
            {
                best_val=move_val;
                bestmoveidx=i;
            }
            vec[i]=i+'1';
        }
    }
    return bestmoveidx;
}

void clearscreen(){
    system("cls");
}
bool iswon(vector<char>&vec)
{
    if((vec[0]==vec[1]&&vec[2]==vec[0])||(vec[3]==vec[4]&&vec[5]==vec[3])||(vec[6]==vec[7]&&vec[8]==vec[6])||(vec[0]==vec[3]&&vec[6]==vec[0])||(vec[1]==vec[4]&&vec[7]==vec[1])||(vec[2]==vec[5]&&vec[8]==vec[2])||(vec[0]==vec[4]&&vec[8]==vec[0])||(vec[2]==vec[4]&&vec[6]==vec[2]))
    return true;
    return false;
}
void printvecttt(vector<char> & vec)
{
    cout<<"       "<<"  "<<vec[0]<<" | "<<vec[1]<<" | "<<vec[2]<<" "<<endl;
    cout<<"       "<<" --- --- --- "<<endl<<"       "<<"  "<<vec[3]<<" | "<<vec[4]<<" | "<<vec[5]<<" "<<endl;
    cout<<"       "<<" --- --- --- "<<endl<<"       "<<"  "<<vec[6]<<" | "<<vec[7]<<" | "<<vec[8]<<" "<<endl;
    //cout<<" --- --- --- "<<endl;
}

void gameHelp(){
    clearscreen();
    cout<<endl;
    cout<<endl;
    cout<<"       -----------------------"<<endl;
    cout<<"       | TIC-TAC-TOE |  HELP |"<<endl;
    cout<<"       -----------------------"<<endl;
    cout<<endl;
    cout<<endl;
    cout<<"                _______________"<<endl;
    cout<<"       -----   /               \\ "<<endl;
    cout<<"       |0 0| < I Will Help You!|"<<endl;
    cout<<"        |=|    \\_______________/"<<endl<<endl;
    cout<<"1. The game is played on a grid that's 3 squares by 3 squares."<<endl;
    cout<<"2. You are 'O', your friend(or computer) is 'X'."<<endl;
    cout<<"3. Players take turns putting their marks in empty squares."<<endl;
    cout<<"4. The first player to get the three of his/her marks in a row (up, down,"<<endl;
    cout<<"   across,or diagonally) is the winner."<<endl;
    cout<<"5. When all 9 squares are full, the game is over. If no player has 3 marks"<<endl;
    cout<<"   in a row, the game ends in a tie."<<endl;
    cout<<endl;
}

void instruction(){
    cout<<endl;
    cout<<"------------------------------------------------------------------------------"<<endl<<endl;
    cout<<"       ---------------"<<endl;
    cout<<"       | TIC-TAC-TOE |"<<endl;
    cout<<"       ---------------"<<endl;
    cout<<endl;
    cout<<"INSTRUCTIONS : Valid number range -> [1,9], where all number are integers"<<endl;
    cout<<"             : Can't overwrite already occupied positions"<<endl;
    cout<<"             : Moves can't be undo"<<endl<<endl;
    cout<<"\n Enter 1 : Player vs Player!! \n       2 : Player vs Computer!! "<<endl;
    cout<<"       3 : Help :)"<<endl;
    cout<<"       4 : Exit :("<<endl<<endl;
    cout<<"I am Choosing ... ";
}
void tictactoe()
{
    clearscreen();
    cout<<endl;

    instruction();
    
    int ask;
    char ask_char;
    cin>>ask_char;
    ask=ask_char-'0';

    //pvp or cvp;
    bool pvp=false;
    bool cvp=false;
    switch (ask)
    {
        case 1:
        pvp=true;
        break;
        case 2:
        cvp=true;
        break;
        case 3:
        {
            gameHelp();
            break;
            
        }
        
        case 4:
        {
            cout<<endl<<"Bye Bye :( \n";
            return;
        }
        default:
        {
            cout<<endl<<"ENTER A VALID NUMBER!!"<<endl;
            tictactoe();
            return;
        }
    }
    //players vs players
    while(pvp)
    {
        
        //intializing tictactoe board
        vector<char> vec(9);
        for(int i=0;i<9;i++)
            vec[i]='1'+i;

        clearscreen();
        
        string player1,player2;
        //nameinput;
        cout<<"PLAYER 1 ENTER YOUR NAME (O) : ";
        cin>>player1;

        cout<<"PLAYER 2 ENTER YOUR NAME (X) : ";
        cin>>player2;

        //uppercasing the name;
        transform(player1.begin(),player1.end(),player1.begin(),::toupper);
        transform(player2.begin(),player2.end(),player2.begin(),::toupper);

        int test_cases=9;

        bool playeroneturn=true;

        cout<<endl;
        printvecttt(vec);
        cout<<endl;
        while(test_cases && !iswon(vec))
        {

            cout<<"IT'S YOUR TURN ";

            if(playeroneturn)
            {
                cout<<player1<<" : ";
            }
            else
            {
                cout<<player2<<" : ";
            }
            char uman_input;
            cin>>uman_input;
            int human_input=uman_input-'0';
            

            //edge case
            if(vec[human_input-1]=='X'||vec[human_input-1]=='O'||human_input>9)
            {
                cout<<"INVALID INPUT!!"<<endl;
                continue;
            }

            clearscreen();
            vec[human_input-1]=playeroneturn?'X':'O';
            playeroneturn=!playeroneturn;

            cout<<endl;
            printvecttt(vec);
            cout<<endl;
            test_cases--;
        }

        cout<<endl;

        if(iswon(vec))
        {
            cout<<"CONGRATULATIONS!! ";
            if(playeroneturn)
            {
                cout<<player2;
            }
            else
                 cout<<player1;
            cout<<" YOU WON"<<endl;
            
        }

        else
        {
            cout<<"DRAW!!...YOU BOTH PLAYED WELL"<<endl;
        }

        char rematch;
        cout<<"REMATCH (y/n) ? ";
        cin>>rematch;

        pvp=(rematch=='y')?true:false;

    }
    
    //computer vs player
    while(cvp)
    {
        char game_mode;
        cout<<"choose game mode HARD or EASY ? (h/e) ";
        cin>>game_mode;
        game_mode=tolower(game_mode);
       

        if(game_mode!='h' && game_mode!='e')
        {
            cout<<"INVALID INPUT!!"<<endl;
            continue;
        }
        clearscreen();
        cout<<endl;

        cout<<"Enter Your Name : ";
        string player_name;
        cin>>player_name;
        
        //changing playername to upper case;
        transform(player_name.begin(),player_name.end(),player_name.begin(),::toupper);

        //and the game begins;
        clearscreen();

        vector<char> vec(9);
        for(int i=0;i<9;i++)
            vec[i]='1'+i;

        char first_move;
        cout<<"First Move (y/n)? ";
        cin>>first_move;
        first_move=tolower(first_move);
        cout<<endl;

        if(first_move!='y'&& first_move!='n')
        {
            cout<<"INVALID INPUT!!"<<endl;
            continue;
        }

        bool computer_move;
        computer_move = (first_move=='y') ? false : true;

        int test_cases=9;

        printvecttt(vec);
        cout<<endl;
        while(test_cases && !iswon(vec)){

            if(computer_move)
            {
                //hard
                if(game_mode=='h')
                {
                    vec[nextbestmove(vec)]='X';
                }
                //easy
                else if(game_mode=='e')
                {
                    vec[normalmove(vec)]='X';
                }

                computer_move=false;

                cout<<endl<<"COMPUTER MOVE \n"<<endl;
                printvecttt(vec);
                cout<<endl;
                
            }
            //human move
            else if(!computer_move)
            {
                
                cout<<"ENTER YOUR MOVE "<<player_name<<" : ";

                char uman_move;
                cin>>uman_move;
                int human_move=uman_move-'0';

                if(vec[human_move-1]=='X'||vec[human_move-1]=='O'||human_move>9||human_move<0)
                {
                    cout<<"INVALID MOVE!!"<<endl;
                    continue;
                }

                clearscreen();

                vec[human_move-1]='O';

                cout<<endl;
                printvecttt(vec);

                computer_move=true;

            }

            test_cases--;

        }

        cout<<endl;

        if(iswon(vec))
        {
            if(computer_move)
            cout<<"CONGRATULATIONS!! "<<player_name<<" YOU WON!! "<<endl;
            else{
                cout<<"YOU LOSE :( ...BETTER MOVE NEXT TIME!! "<<player_name<<endl;
            }
        }
        else
        {
            cout<<"ITS A DRAW!! WELL PLAYED ... BUT BETTER MOVE NEXT TIME"<<endl;
        }

        char rematch;
        cout<<endl;
        cout<<"REMATCH (y/n) ? ";
        cin>>rematch;

        cvp=(rematch=='y')?true:false;

    }

    cout<<endl;

    char mainmenu;
    cout<<"RETURN TO MAINMENU (y/n)? ";
    cin>>mainmenu;

    if(mainmenu=='y')
    {
        tictactoe();
    }
    return;
    //exit;
}


int main()
{
    tictactoe();
    return 0;
}