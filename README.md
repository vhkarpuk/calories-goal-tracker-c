# Calories Goal Tracker (C)

A menu-driven C console app that logs **steps**, **direct calories**, and **distance** (with intensity levels), validates input, tracks **progress toward a daily calories goal**, and prints a **final summary**.

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
