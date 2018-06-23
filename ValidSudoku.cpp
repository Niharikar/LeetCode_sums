
bool isValidSudoku(vector< vector<char> >& board)
{
    vector<short> c(9,0);
    vector<short> b(9,0);
    
    for(int i = 0;i<9;i++)
    {
        int row = 0;
        for(int j = 0;j<9;j++)
        {
            int idx = 1 << (board[i][j]-'0');
            if(row & idx  ||  c[j] & idx  || b[(i/3)*3 + j/3])] & idx )
                return false;
                
            row = row | idx;
            c[j] = c[j] | idx;
            b[(i/3)*3 + j/3] |= idx;
        }
    }
    
    return true;
    
}
