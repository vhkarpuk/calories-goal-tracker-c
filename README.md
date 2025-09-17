# 🍎 Calories Goal Tracker (C Project)

![C](https://img.shields.io/badge/language-C-blue)
![License: MIT](https://img.shields.io/badge/License-MIT-green.svg)
![Last Commit](https://img.shields.io/github/last-commit/vhkarpuk/calories-goal-tracker-c)

A **simple calorie tracking program in C** where users set a daily goal and log their food intake.  
Designed to practice **loops, arrays, conditionals, and console interaction**.

## Features
- **Daily goal** (validated, positive number) with live **progress %** after each entry
- **Three entry types**:
  - **Steps** → calories via intensity (`L=0.03`, `M=0.04`, `H=0.06` calories/step)
  - **Direct calories** → add exact calories burned
  - **Distance (km)** → converts to steps and then calories using intensity
- **Robust validation**: menu choice (1–3), positive values, `L/M/H` for intensity, `y/n` prompts
- **Clear summary** at exit: totals for steps (and their calories), direct calories, distance (and its calories), and overall calories

## Conversions & Assumptions
- `KM_PER_STEP = 0.0008` (≈ 1,250 steps per km)
- Intensity calories/step:
  - Low `CAL_L = 0.03`
  - Medium `CAL_M = 0.04`
  - High `CAL_H = 0.06`

## Build & Run

### Windows (MinGW-w64 / GCC)
```bash
gcc src/calories_goal_tracker.c -o calories_goal_tracker.exe -Wall -Wextra -O2
./calories_goal_tracker.exe
