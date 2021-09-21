
# N-queens

1. queens more likely on edge of board; use asymmetry to allocate queens by section
2. use entropy method

His key realization was that queens in an n-queens configuration were far more likely to occupy certain squares than others

Because queens in the middle of the board attack the most spaces, most configurations feature more queens on the side of the board than near the center

Simkin broke the n-by-n chessboard into sections, each made up of thousands of squares

Rather than putting queens down completely randomly, he chose spaces where there were more queens more often. This allowed him to determine a formula for the minimum number of valid configurations.


Simkin proved that this formula was more than just a minimum — that it was nearly an exact description — by using a strategy known as the entropy method.

Simkin was able to calculate a maximum number of configurations by tracking the number of spaces not under attack after the position of each additional new queen was revealed

https://www.quantamagazine.org/mathematician-answers-chess-problem-about-attacking-queens-20210921/

https://arxiv.org/pdf/2107.13460.pdf
