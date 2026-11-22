<p align="center">
  <img src="assets/banner.png" alt="Guess The Number" width="600">
</p>

<h1 align="center">🎯 Guess The Number</h1>

<p align="center">
  A fun terminal-based number guessing game written in C with colored UI, sound effects, and a victory fanfare!
</p>

<p align="center">
  <a href="#-features">Features</a> •
  <a href="#-quick-start">Quick Start</a> •
  <a href="#%EF%B8%8F-build-from-source">Build</a> •
  <a href="#-how-to-play">How to Play</a> •
  <a href="#-license">License</a>
</p>

---

## ✨ Features

- 🎨 **Colorful Terminal UI** — ANSI escape codes for a polished console experience
- 🔊 **Sound Effects** — Victory fanfare (C→E→G→C major chord) and wrong-guess buzzer via Windows Beep
- 🏆 **Win Screen** — Box-drawn congratulations display with attempt count
- 🔁 **Play Again** — Instant replay without restarting the app
- ✅ **Input Validation** — Handles non-numeric and out-of-range input gracefully
- 📊 **Attempt Tracker** — Shows your current attempt on each guess

## 📸 Preview

```
  ╔══════════════════════════════════════════╗
  ║                                          ║
  ║      🎯  GUESS THE NUMBER  🎯            ║
  ║                                          ║
  ╚══════════════════════════════════════════╝

  I'm thinking of a number between 0 and 100...

  [Attempt 1] Enter your guess: 50

  📈  ┌─────────────────────────────┐
  📈  │  📈 Go HIGHER!              │
  📈  └─────────────────────────────┘

  [Attempt 2] Enter your guess: 75

  📉  ┌─────────────────────────────┐
  📉  │  📉 Go LOWER!               │
  📉  └─────────────────────────────┘

  [Attempt 3] Enter your guess: 63

  ╔══════════════════════════════════════════╗
  ║            🏆  YOU WON!  🏆              ║
  ╠══════════════════════════════════════════╣
  ║   🎉  Congratulations!  🎉              ║
  ║   The number was: 63                     ║
  ║   Attempts:       3                      ║
  ╚══════════════════════════════════════════╝
```

## 🚀 Quick Start

### Download & Run (Windows)

1. Go to the [**Releases**](../../releases) page
2. Download `GuessTheNum.exe`
3. Double-click it or run from terminal:
   ```powershell
   .\GuessTheNum.exe
   ```

> **Note:** Use **Windows Terminal** or **PowerShell** for the best colored output experience.

## 🛠️ Build from Source

### Prerequisites

- A C compiler: **GCC (MinGW)**, **MSVC**, or **Clang**

### Using GCC (MinGW)

```bash
gcc GuessTheNum.c -o GuessTheNum.exe
```

### Using MSVC (Developer Command Prompt)

```bash
cl GuessTheNum.c /Fe:GuessTheNum.exe
```

### Using the Build Script

```powershell
.\build.bat
```

## 🎮 How to Play

1. **Set the range** — Enter the maximum number (e.g., `100` for 0–100)
2. **Make a guess** — Type your number and press Enter
3. **Follow the hints:**
   - 📈 **Go HIGHER!** — Your guess is too low
   - 📉 **Go LOWER!** — Your guess is too high
4. **Win!** 🏆 — When you guess correctly, see your attempt count and hear the victory fanfare
5. **Play again** — Press `y` to start a new round

## 📁 Project Structure

```
GuessTheNumber/
├── GuessTheNum.c      # Main source code
├── build.bat          # Windows build script
├── Makefile           # Build with make
├── .gitignore         # Git ignore rules
├── LICENSE            # MIT License
└── README.md          # This file
```

## 🤝 Contributing

1. Fork the repo
2. Create a feature branch (`git checkout -b feature/cool-idea`)
3. Commit your changes (`git commit -m "Add cool idea"`)
4. Push to your branch (`git push origin feature/cool-idea`)
5. Open a Pull Request

## 📄 License

This project is licensed under the **MIT License** — see the [LICENSE](LICENSE) file for details.

---

<p align="center">
  Made with ❤️ and C
</p>
