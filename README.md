# Tictactoe-AI-based
C++ based game Tic-tac-toe (AI based) hard and easy mode while playing against computer
concept of minimax and evalution function is used

computer compute all possible moves and finds the best one out them by looking at the future( using backtracking )
there are two mode available - hard and easy 

hard is the best mode or god mode, which is impossible to win against... Either the game will come to a draw or the computer will win
and the normal is mode where the computer can see only one step future.

It also provide pvp mode (player vs player)
and all the edge cases are being handled.

now lets talk about the concept I worked on...
lets think it like ... we need to make a function which can come up with the best_next_move(game_board);
it will take the game_board (vector or arr) and look for the best move by computing all the possible situations in the future.
For making of next best move i did this -

best_next_move(vector<int> game_board)
  {
      for i to the last of board
          if i is available then 
              put computer mark and calculate the score of the board by that move
              remove the move and try other move
              store the best move
              if current move is better than the best move then
                  best move will be current move
  }
  
  for computing the score of the board we need to use another function
  which will look in the all kinds of future and come up with a value 
  like if we are going to be in a losing position then it will come up
  with some negative value but if we are in a winning situation then 
  it will show positive value.
  but if it is kind of drawish position then it will bring 0 ;
  
  There is a function name iswon()
  which is already clear what is does
  it tells use whether the player is winning or not 
  or you can say do we already have a winner by looking at the board
  because iswon() takes vector as argument;
  
  
  last but not the least 
  play and enjoy;
  
