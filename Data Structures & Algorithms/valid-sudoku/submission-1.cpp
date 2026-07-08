class Solution {
public:
    const char EMPTY = '.';
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0; i < 9; i++){
            if(!isValidRow(board, i)) return false;
            if(!isValidCol(board, i)) return false;
            if(!isValidSquare(board, i)) return false;
        }
        return true;
    }

    bool isValidRow(vector<vector<char>>& board, int row){
        vector<bool> visited(9, false);
        for(int i = 0; i < 9; i++){
            if(board[row][i] == EMPTY) continue;
            int num = (board[row][i]) - '0';
            if(visited[num-1] == false) visited[num-1] = true;
            else return false;
        }
        return true;
    }

    bool isValidCol(vector<vector<char>>& board, int col){
        vector<bool> visited(9, false);
        for(int i = 0; i < 9; i++){
            if(board[i][col] == EMPTY) continue;
            int num = (board[i][col]) - '0';
            if(visited[num-1] == false) visited[num-1] = true;
            else return false;
        }
        return true;
    }

    bool isValidSquare(vector<vector<char>>& board, int sq){
        
        vector<bool> visited(9,false);

        int startRow = (sq/3) * 3;
        int startCol = (sq%3) * 3;
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){

                if(board[startRow + i][startCol + j] == EMPTY) continue;

                int num = (board[startRow + i][startCol + j]) - '0';
                if(visited[num-1] == false) visited[num-1] = true;
                else return false;
            }            
            
        }

        return true;
        
        
    }
};
