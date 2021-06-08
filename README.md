# Tetris clone made with SFML
## Usage
Download SFML library, rename the directory to "SFML" and place it in the main directory containing "assets" and "src" folders.
Run the cmake project:

```
  cmake .
  make run
```


## How to play:
Move and rotate pieces to fill the rows on the board. When you fill a row it gets cleared and you get points. Survive as long as you can!

|             Key            |             Action           |
|----------------------------|------------------------------|
| Left and right<br />arrows |      Move current piece      |
|         Down arrow         |      Accelerate falling      |
|            Space           |  Piece falls to the bottom   |
|              X             |       Rotate clockwise       |
|              Z             |   Rotate counterclockwise    |
|              C             | Hold current piece for later |
|            Enter           |   Restart after game over    |
