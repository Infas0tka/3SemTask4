#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{
    char stroka[200];
    ifstream fin("input.txt");
    fin.getline(stroka, 200);
    fin.close();
    string s;
    s = string (stroka);
    ofstream fout("output.txt");
    fout << s << endl;
    fout << endl;
    string::iterator it;





    int j = s.rfind(" ");                   //Find and delete all the same words as last
    string last = "";
    it = s.end() - 1;
    while (*it != ' ')
    {
        last = *it + last;
        it--;
    }
    int dlina = last.length();
    j = -1;
    while(s.find(last, j + 1) != string::npos)
    {
        j = s.find(last, j + 1);
        if ((j > 0) && (s[j - 1] == ' '))
        {
            if ((j < dlina + s.length()) && (s[j + dlina] == ' '))
                s.erase(j, dlina);
        }
        else if (j == 0)
        {
            if ((j < dlina + s.length()) && (s[j + dlina] == ' '))
                s.erase(j, dlina);
        }
    }
    it = s.begin();
    s.erase(s.length() - last.length(), last.length());
    fout << "Deleted all 'last' words:      " << s << endl;





    while(s.find("  ") != string::npos)       //No spaces
        s.erase(s.find("  "), 1);
    if(*(s.begin()) == ' ')
        s.erase(s.begin());
    if(*(s.end() - 1) == ' ')
        s.erase(s.end() - 1);
    fout << "No extra spaces:               " << s << endl;





    it = s.begin();               //Delete last letter
    while (it != s.end())
    {
        if (*it == ' ')
            s.erase(it - 1);
        else
        it++;
    }
    if (it == s.end())
        s.erase(it - 1);
    fout << "Deleted last letter:           " << s << endl;
    fout.close();
    return 0;
}
