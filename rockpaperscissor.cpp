#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;
int generaterandom(int value)
{
    srand(time(NULL));
    int answer = rand() % value; // returns a random value between 0 and value -1
    return answer;
}
int winner(char pturn, char cturn)


{
    if (pturn == 'r' && cturn == 'p')
    return 1;
    else if (pturn == 'p' && cturn == 'r')
    return 2;
    else if (pturn == 'p' && cturn == 's')
    return 2;
    else if (pturn == 's' && cturn == 'p')
    return 1;
    else if (pturn == 's' && cturn == 'r')
    return 2;
    else if (pturn == 'r' && cturn == 's')
    return 1;
    else if (pturn==cturn )
    return 0;
}
void result(int pscore, int cscore)
{
    if (pscore >cscore)
    cout << "Congratulations! You won ";
    else if (pscore <cscore)
    cout << "Oops, Better luck next time ";
    else cout << "It's a tie! ";
}
int main()
{
    char arr[] = {'r', 'p', 's'};
    char pturn, cturn;
    cout << "Welcome to Rock, Paper, Scissor ! " << endl;
    int turn = 3;
    int pscore = 0, cscore = 0;
    while (turn--)
    {
        cout << "Player's Turn : Choose rock, paper, or scissor " << endl;
        cout << "1 :Rock" << endl
             << "2 :Paper" << endl
             << "3 :Scissor" << endl;
        int temp;
        cin >> temp;
        pturn = arr[temp - 1];
        cturn = arr[generaterandom(3)];
        cout << cturn << endl ;
        int num=winner(pturn, cturn);
        if (num==1)
        pscore++;
        else if (num==0)
        {
            pscore++;
            cscore++;
        }
        else if (num==2)
        cscore++;
    }
    result (pscore,cscore);
}