#include<iostream>
#include<limits.h>
using namespace std;
# define NO_OF_CHARS 256


class ques24
{

    private:

    void badCharHeuristic( string str, int size,int badchar[NO_OF_CHARS])
    {
        int i;
 
        // Initialize all occurrences as -1
        for (i = 0; i < NO_OF_CHARS; i++)
        badchar[i] = -1;
 
        // Fill the actual value of last occurrence
        // of a character
        for (i = 0; i < size; i++)
        badchar[(int) str[i]] = i;
    }

    public:
    void boyer_moore_algo(string text,string pattern)
    {
        int m = pattern.size();
        int n = text.size();
 
        int badchar[NO_OF_CHARS];
 
        badCharHeuristic(pattern, m, badchar);
 
        int s = 0; // s is shift of the pattern with
                    // respect to text
        while(s <= (n - m))
        {   
            int j = m - 1;
 
            while(j >= 0 && pattern[j] == text[s + j])
            j--;

            if (j < 0)
            {
                cout << "pattern occurs at shift = " <<  s << endl;
                s += (s + m < n)? m-badchar[text[s + m]] : 1;
            }

            else
            s += max(1, j - badchar[text[s + j]]);
        }
    }
};


int main()
{

    string text= "ABAAABCD";
    string pattern = "ABC";

    ques24 q;

    q.boyer_moore_algo(text, pattern);


    return 0;
}