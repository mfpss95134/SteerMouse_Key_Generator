#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;




int main() {
    // ID Initialization
    string ID = "ABCDEF-HIJKLM-(A)";
    srand(time(NULL));
    for (int i = 0; i < 6; i++)
    {
        //srand(time(NULL));
        ID[i] = ('A' + rand()%26);
    }
    for (int i = 7; i < 13; i++)
    {
        //srand(time(NULL));
        ID[i] = ('A' + rand()%26);
    }
    ID[15] = ('A' + rand()%26);




    // Table Initialization
    int initial_table[20] = {0};
    for (int i = 0; i <= 16; i++)
    {
        initial_table[i] = ID[i];
    }
    initial_table[19] = 70;
    initial_table[18] = 85;




    // Reverse
    int reversed_table[20] = {0};
    for (int i = 0; i < 160; i++)
    {
        int tmp = initial_table[i/8];
        int bit = (tmp >> i%8) & 1;
        int idx = i % 20;
        reversed_table[idx] = reversed_table[idx] | (bit << i/20);
    }




    // Generate KEY
    string CODE = ""; //string CODE = "                    ";      //20 characters
    string AtoE = "ABCDE";
    int non_F_count = 0;
    for (int i = 0; i < 20; i++)
    {
        int upper_bound = reversed_table[i]/20;
        int lower_bound = reversed_table[i]%20;


        if (i%2==0 && i>0)
        {
            CODE += "-";
        }
        

        if (upper_bound==0 && non_F_count<4)
        {
            //srand(time(NULL));
            CODE += AtoE[rand()%5];
            non_F_count++;
        }
        else
        {
            CODE += upper_bound+70;
        }


        if (lower_bound==0 && non_F_count<4)
        {
            //srand(time(NULL));
            CODE += AtoE[rand()%5];
            non_F_count++;
        }
        else
        {
            CODE += lower_bound+70;
        }
    }


    cout << "ID: " << ID << endl;
    cout << "CODE: " << CODE << endl;


    return 0;
}