# A Vim Story
_A ncurses based game for learning Vim_



### Overview

There are a lot of problems faced by beginners to [Vim](http://www.vim.org/)
(like getting used to not using arrow keys for example). Although there are a
lot of resources for learning Vim, they can get tedious and time consuming.  

The project aims to make a game played by using the shortcuts and key mappings
in Vim to ease into the famous learning curve of Vim. The idea is to make a
retro console game (like bomber-man and the likes) which is controlled solely
by Vim key mappings and shortcuts.  

Inspired by [Vim Adventures](https://vim-adventures.com/) and open sourced.



### Compiling
Assuming you have _libncurses_, _CMake_ and _Make_ installed.

```bash
mkdir build && cd build

cmake ..
cmake -DCMAKE_INSTALL_PREFIX=/usr ..  # to install in /usr

make                # build
make install        # to install (might want to use 'sudo')

./bin/a-vim-story   # to run (while in build)
a-vim-story         # to run (after install)
```



### Documentation
For documentation, a configuration file for _Doxygen_ is provided. Assuming you
have _doxygen_ installed, issue these commands:

```bash
doxygen doxygen.conf
```



### Author
[Utkarsh Maheshwari](https://github.com/UtkarshMe)



### License
[GPL version 3](https://github.com/UtkarshMe/a-vim-story/blob/master/LICENSE)
