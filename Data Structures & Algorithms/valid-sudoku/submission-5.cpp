class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char> rowMap; 
        unordered_set<char> colMap; 
        map<pair<int, int>, unordered_set<int>> squareMap; 

        //["1","2",".",".","3",".",".",".","."]
        int n = board.size();

        // O(n sq)
        for (int i=0; i<n; i++){
            for (int j=0; j<n; j++){    
                // element found
                if (board[i][j] == '.') continue; 
                if(rowMap.find(board[i][j]) != rowMap.end()) return false;
                rowMap.insert(board[i][j]);
            }
            rowMap.clear();
        }

        // O(n sq)
        for (int i=0; i<n; i++){
         for (int j=0; j<n; j++){    
            // id duplicate element is found
            
            if (board[j][i] == '.') continue; 
            if(colMap.find(board[j][i]) != colMap.end()) return false;
                colMap.insert(board[j][i]);
            }
            colMap.clear();
        }

        for (int i=0; i<n; i++){
            for (int j=0; j<n; j++){  
                if(board[i][j] == '.' || board[i][j] == 0){
                    continue;
                }
                if(squareMap[{i/3, j/3}].count(board[i][j]))  {
                    return false;
                }else {
                    squareMap[{i/3, j/3}].insert(board[i][j]);
                }
            }
        }
        return true;
    }
};
