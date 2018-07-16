class TicTacToe {
public:
    /** Initialize your data structure here. */
    vector<int> rx;
    vector<int> cx;
    int dlx;
    int drx;
    int c;            
    vector<int> ro;
    vector<int> co;
    int dlo;
    int dro;
    
    TicTacToe(int n) : rx(n),cx(n),ro(n),co(n),dlo(0),dro(0),dlx(0),drx(0){
        c = n;
        
    }
    
    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    int move(int row, int col, int player) {
        
        if(player == 1)
        {
            rx[row]++;;
            cx[col]++;
            if(row == col)
            {
                dlx++;
                if(row == (c >> 1) && c&1)
                    drx++;
            }
            else if(row+col == c-1)
                drx++;
            if(rx[row] == c || cx[col] == c || dlx == c || drx == c)
                return 1;
            else
                return 0;
        }
        
        else
        {
            ro[row]++;
            co[col]++;
            
            if(row == col)
            {
                dlo++;
                if(row == (c>>1) && c&1)
                    dro++;
            }
            else if(row+col == c-1)
                dro++;
            
            if(ro[row] == c || co[col] == c || dlo == c || dro == c)
                return 2;
            else
                return 0;
        }
        
        
    }
};
