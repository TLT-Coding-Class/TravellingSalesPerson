// TicTacToe.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <ratio>
#include <chrono>
using namespace std;
using namespace std::chrono;
const int BOARD_SIZE = 3;
char board[9] = { '1', '2', '3', '4', '5', '6', '7', '8', '9' };

string inputname(int num) {
    string name;
    string strnum = to_string(num);
    cout << "Input Player " << strnum << "'s name : ";
    getline(cin, name);
    return name;
}

char inputsym(int num) {
    char sym;
    string strnum = to_string(num);
    cout << "Input Player " << strnum << "'s symbol : ";
    cin >> sym;
    return sym;
}

void gethistory() {
    ifstream TimeFile("Time.txt");
    string Time;
    cout << "History : " << endl;
    for (int z = 0; z < 10; z++) {
        TimeFile >> Time;
        cout << "Time : " << Time << endl;
    }
    TimeFile.close();
}

void printSeparator() {
    cout << "-----------" << endl;
}

void printBoardEachLine(int noOfLine) {
    cout << " " << board[(noOfLine * BOARD_SIZE) + 0] << " | " << board[(noOfLine * BOARD_SIZE) + 1] << " | " << board[(noOfLine * BOARD_SIZE) + 2] << " " << endl;
    // use a for loop to only  cout once.

}

// TLT :Simplify to only 2 lines
void display(string board) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        printBoardEachLine(i);
        printSeparator();
    }
}

// too long
// make it lest line
int check(string board, char p1sym) {
    if (board[0] == board[1] && board[1] == board[2]) {
        if (board[0] == p1sym) {
            return 1;
        }
        else {
            return 2;
        }
    }
    else {
        if (board[3] == board[4] && board[4] == board[5]) {
            if (board[3] == p1sym) {
                return 1;
            }
            else {
                return 2;
            }
        }
        else {
            if (board[6] == board[7] && board[7] == board[8]) {
                if (board[6] == p1sym) {
                    return 1;
                }
                else {
                    return 2;
                }
            }
            else {
                if (board[0] == board[3] && board[3] == board[6]) {
                    if (board[0] == p1sym) {
                        return 1;
                    }
                    else {
                        return 2;
                    }
                }
                else {
                    if (board[1] == board[4] && board[4] == board[7]) {
                        if (board[1] == p1sym) {
                            return 1;
                        }
                        else {
                            return 2;
                        }
                    }
                    else {
                        if (board[2] == board[5] && board[5] == board[8]) {
                            if (board[2] == p1sym) {
                                return 1;
                            }
                            else {
                                return 2;
                            }
                        }
                        else {
                            if (board[0] == board[4] && board[4] == board[8]) {
                                if (board[0] == p1sym)
                                    return 1;
                                else
                                    return 2;
                            }
                            else {
                                if (board[2] == board[4] && board[4] == board[6]) {
                                    if (board[2] == p1sym) {
                                        return 1;
                                    }
                                    else {
                                        return 2;
                                    }
                                }
                                else {
                                    if (board[0] == board[3] && board[3] == board[6]) {
                                        if (board[0] == p1sym) {
                                            return 1;
                                        }
                                        else {
                                            return 2;
                                        }
                                    }
                                    else {
                                        return 0;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

void whosturn(int num, string name) {
    cout << "\nPlayer " << num << "(" << name << ")'s turn\n" << endl;
    cout << "Please input your choice : ";
}


int main() {
    cout << "This is a Tic Toe Game (made by Sin Yee Hang, Lim Yu Ming and Lim Yu An)";
    string input;
    string p1name = inputname(1);
    string p2name = inputname(2);
    int p1win = 0;
    int p2win = 0;
    int gameCount = 1;
    char p1sym = inputsym(1);
    char p2sym = inputsym(2);
    gethistory();

    high_resolution_clock::time_point astart = high_resolution_clock::now();
    while (gameCount <= 5 && p1win < 3 && p2win < 3) {
        high_resolution_clock::time_point start = high_resolution_clock::now();
       
        int player1 = 1, player2 = 2;

        int box, result = 0, flag = 0;

        display(board);

        // index should start from 0 
        // create constant variable to store 5
        // use constant instead of number
        // 
        // for (int i = 0; i<5 ; i ++)
        for (int i = 1; i <= 5; i++) {
            whosturn(1, p1name);
            cin >> box;
            board[box - 1] = p1sym;
            display(board);
            result = check(board, p1sym);
            if (result == 1) {
                // create a function
                // reduntant to else if (result == 2)
                high_resolution_clock::time_point end = high_resolution_clock::now();
                cout << "\nCongratulations! Player 1 (" << p1name << ") has WON!!! " << endl;
                p1win += 1;
                flag = 1;
                cout << "Game count : " << gameCount << endl;
                cout << "Player 1 won " << p1win << " game(s)." << endl;
                cout << "Player 2 won " << p2win << " game(s)." << endl;
                duration<double> time = duration_cast<duration<double>>(end - start);
                std::cout << "Time used : " << time.count() << "s" << endl;
                break;
            }
            else if (result == 2) {
                high_resolution_clock::time_point end = high_resolution_clock::now();
                cout << "\nCongratulations! Player 2 (" << p2name << ") has WON!!! " << endl;
                p2win += 1;
                flag = 1;
                cout << "Game count : " << gameCount << endl;
                cout << "Player 1 won " << p1win << " game(s)." << endl;
                cout << "Player 2 won " << p2win << " game(s)." << endl;
                duration<double> time = duration_cast<duration<double>>(end - start);
                cout << "Time used : " << time.count() << "s" << endl;
                break;
            }
            if (i != 5) {
                cout << "\nPlayer 2 (" << p2name << ")'s turn\n" << endl;
                cout << "Please input your choice : ";
                cin >> box;
                if (player2 == 1) {
                    board[box - 1] = p1sym;
                }
                else {
                    board[box - 1] = p2sym;
                }

                display(board);

                result = check(board, p2sym);

                if (result == 1) {
                    // create a function
                    high_resolution_clock::time_point end = high_resolution_clock::now();
                    cout << "\nCongratulations! Player 1 (" << p1name << ") has WON!!! " << endl;
                    p1win += 1;
                    flag = 1;
                    cout << "Game count : " << gameCount << endl;
                    cout << "Player 1 won " << p1win << " game(s)." << endl;
                    cout << "Player 2 won " << p2win << " game(s)." << endl;
                    duration<double> time = duration_cast<duration<double>>(end - start);
                    std::cout << "Time used : " << time.count() << "s" << endl;
                    break;
                }
                else {
                    if (result == 2) {
                        high_resolution_clock::time_point end = high_resolution_clock::now();
                        cout << "\nCongratulations! Player 2 (" << p2name << ") has WON!!! " << endl;
                        p2win += 1;
                        flag = 1;
                        cout << "Game count : " << gameCount << endl;
                        cout << "Player 1 won " << p1win << " game(s)." << endl;
                        cout << "Player 2 won " << p2win << " game(s)." << endl;
                        duration<double> time = duration_cast<duration<double>>(end - start);
                        cout << "Time used : " << time.count() << "s" << endl;
                        break;
                    }
                }
            }
        }
        if (flag == 0) {
            // simplify it / use a function
            high_resolution_clock::time_point end = high_resolution_clock::now();
            cout << " \nSorry, the game is a draw. " << endl;
            cout << "Game count : " << gameCount << endl;
            cout << "Player 1 won " << p1win << " game(s)." << endl;
            cout << "Player 2 won " << p2win << " game(s)." << endl;
            duration<double> time = duration_cast<duration<double>>(end - start);
            std::cout << "Time used : " << time.count() << "s" << endl;

        }
        gameCount += 1;
    }
    cout << "\n";
    high_resolution_clock::time_point aend = high_resolution_clock::now();
    duration<double> atime = duration_cast<duration<double>>(aend - astart);
    if (p1win == 3) {
        cout << "PLAYER 1 (" << p1name << ") WON!!!" << endl;
    }
    else if (p2win == 3) {
        cout << "PLAYER 2 (" << p2name << ") WON!!!" << endl;
    }
    else {
        cout << "DRAW!!!" << endl;
    }
    cout << "Player 1 won " << p1win << " game(s)." << endl;
    cout << "Player 2 won " << p2win << " game(s)." << endl;
    cout << "Overall used time : " << atime.count() << " seconds." << endl;

    ifstream GetFile("Time.txt");
    string lis[9] = { "", "", "", "", "", "", "", "", "" };
    for (int i = 0; i < 9; i++) {
        string lisin;
        GetFile >> lisin;
        lis[i] = lisin;
    }
    string test = to_string(atime.count());
    ofstream OutFile("Time.txt");
    OutFile << test << endl;
    for (int i = 0; i < 9; i++) {
        OutFile << lis[i] << endl;
    }

    return 0;
}
