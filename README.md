# 🎮 Hangman Game - Qt Implementation

## 🌟 Overview
A classic Hangman game built using Qt framework in C++ with a user-friendly GUI and immersive sound effects!

## ✨ Game Features
- 🔀 **Random Word Selection**: Picks words randomly from a file on each new game
- ❤️ **Limited Lives**: Only 3 lives—guess wisely!
- 🖌️ **Visual Feedback**: Watch the hangman being drawn with each wrong guess
- 🔊 **Sound Effects**: Fun audio cues for correct/incorrect guesses, wins, and losses
- 🖥️ **Qt GUI**: Clean, modern interface with intuitive controls

## 🎮 How to Play
1. ▶️ **Launch** the game
2. 🔠 A **random word** is selected (shows as blanks: `_ _ _ _`)
3. ⌨️ **Guess letters** by clicking buttons or typing
4. ✅ **Correct guess?** The letter appears in its position(s)
5. ❌ **Wrong guess?**
   - ➖ Lose a life ❤️
   - 🎨 Part of the hangman is drawn
   - 🔊 Error sound plays
6. 🏆 **Win** by guessing the word before the hangman is complete
7. 💀 **Lose** after 3 wrong guesses

## ⚙️ Technical Details
- 💻 **Language**: C++
- 🖼️ **Framework**: Qt 5/6
- 🛠️ **Key Components**:
  - `QMainWindow` (main game window)
  - `QPushButton` (letter selection)
  - `QGraphicsScene` (hangman drawing)
  - `QSoundEffect` / `QMediaPlayer` (sound effects)
  - File I/O (word list handling)

## 📥 Installation
```bash
git clone https://github.com/your-repo/hangman-qt.git
cd hangman-qt
qmake Hangman.pro
make
./Hangman
