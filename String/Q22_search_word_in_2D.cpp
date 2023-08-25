#include<iostream>
using namespace std;

class ques22
{

    private:

    int solve(char arr[6][6],string word,int n,int index,int i,int j)
    {
        int found=0;

        if(i>=0 && j>=0 && i<6 && j<6 && word[index]==arr[i][j])
        {
            char temp=word[index];

            //make 0 in 2d array
            arr[i][j]=0;
            
            //now search next char of word
            index++;

            if(index==n)
            found = 1;

            else
            {
                //search in 4 directions
                found = found + solve(arr,word,n,index,i+1,j);
                found = found + solve(arr,word,n,index,i-1,j);
                found = found + solve(arr,word,n,index,i,j+1);
                found = found + solve(arr,word,n,index,i,j-1);
            }
            //Backtrack
            arr[i][j]=temp;
        }
        return found;
    }

    public: 
    int search_Word(char arr[6][6],string word,int row,int col)
    {

        int n=word.length();
        int count=0;

        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                // n->word length,,i=row index,j=col index,0->word first index
                count= count + solve(arr,word,n,0,i,j);
            }
        }
        return count;
    }
};



int main()
{

    string word="MAGIC" ;

   char arr[6][6]= 
        {
            {'B','B','M','B','B','B'},
            {'C','B','A','B','B','B'},
            {'I','B','G','B','B','B'},
            {'G','B','I','B','B','B'},
            {'A','B','C','B','B','B'},
            {'M','C','I','G','A','M'}
        };

        int row=sizeof(arr);
        int col=sizeof(arr[0]);


    ques22 q;
    cout<<q.search_Word(arr,word,row,col);

    return 0;
}