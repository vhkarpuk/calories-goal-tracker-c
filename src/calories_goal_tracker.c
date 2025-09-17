#include <stdio.h>

int main(void) {
    // Base conversions
    const double KM_PER_STEP = 0.0008; // 1 step = 0.0008 km
    // Intensity calories-per-step
    const double CAL_L = 0.03, CAL_M = 0.04, CAL_H = 0.06;

    // --- Goal (validated) ---
    double dailyGoal = 0.0;
    while (1) {
        printf("Set your DAILY calories goal (>0): ");
        if (scanf("%lf", &dailyGoal) == 1 && dailyGoal > 0.0) break;
        printf("Invalid goal. Please enter a positive number.\n");
        // clear line
        int ch; while ((ch = getchar()) != '\n' && ch != EOF) {}
    }

    // Totals for session
    long long totalSteps = 0;
    double totalCaloriesFromSteps = 0.0;
    double totalDirectCalories = 0.0;
    double totalDistanceKm = 0.0;
    double totalCaloriesFromDistance = 0.0;

    while (1) {
        // --- Menu (validated) ---
        int choice = 0;
        while (1) {
            printf("\nWhich of these would you like to add to the record?\n");
            printf("1: Steps\n");
            printf("2: Calories\n");
            printf("3: Distance\n");
            printf("Enter your choice (1-3): ");
            if (scanf("%d", &choice) == 1 && choice >= 1 && choice <= 3) break;
            printf("Invalid choice. Please select 1, 2, or 3.\n");
            int ch; while ((ch = getchar()) != '\n' && ch != EOF) {}
        }

        if (choice == 1) {
            // --- STEPS ---
            // Intensity (validated)
            char inten;
            double calPerStep = CAL_M; // default
            while (1) {
                printf("Intensity (L=Low 0.03, M=Medium 0.04, H=High 0.06): ");
                if (scanf(" %c", &inten) != 1) { printf("Invalid input.\n"); return 1; }
                if (inten=='L'||inten=='l'){ calPerStep = CAL_L; break; }
                if (inten=='M'||inten=='m'){ calPerStep = CAL_M; break; }
                if (inten=='H'||inten=='h'){ calPerStep = CAL_H; break; }
                printf("Please enter L, M, or H.\n");
            }

            // Steps (validated, positive integer)
            int steps = 0;
            while (1) {
                printf("Enter the number of steps (>0): ");
                if (scanf("%d", &steps) == 1 && steps > 0) break;
                printf("Steps must be a positive integer.\n");
                int ch; while ((ch = getchar()) != '\n' && ch != EOF) {}
            }

            double cals = steps * calPerStep;
            totalSteps += steps;
            totalCaloriesFromSteps += cals;

            printf("%d steps added (%.2f calories at selected intensity).\n", steps, cals);

        } else if (choice == 2) {
            // --- CALORIES (direct add) ---
            double cals = 0.0;
            while (1) {
                printf("Enter the number of calories burned (>0): ");
                if (scanf("%lf", &cals) == 1 && cals > 0.0) break;
                printf("Calories must be a positive number.\n");
                int ch; while ((ch = getchar()) != '\n' && ch != EOF) {}
            }

            totalDirectCalories += cals;
            printf("%.2f calories were added to overall record.\n", cals);

        } else {
            // --- DISTANCE ---
            // Intensity (validated)
            char inten;
            double calPerStep = CAL_M; // default
            while (1) {
                printf("Intensity (L=Low 0.03, M=Medium 0.04, H=High 0.06): ");
                if (scanf(" %c", &inten) != 1) { printf("Invalid input.\n"); return 1; }
                if (inten=='L'||inten=='l'){ calPerStep = CAL_L; break; }
                if (inten=='M'||inten=='m'){ calPerStep = CAL_M; break; }
                if (inten=='H'||inten=='h'){ calPerStep = CAL_H; break; }
                printf("Please enter L, M, or H.\n");
            }

            // Distance (validated, positive)
            double km = 0.0;
            while (1) {
                printf("Enter the distance walked in km (>0): ");
                if (scanf("%lf", &km) == 1 && km > 0.0) break;
                printf("Distance must be a positive number.\n");
                int ch; while ((ch = getchar()) != '\n' && ch != EOF) {}
            }

            // stepsFromDistance = km / KM_PER_STEP
            double stepsFromDist = km / KM_PER_STEP;
            double cals = stepsFromDist * calPerStep;

            totalDistanceKm += km;
            totalCaloriesFromDistance += cals;

            printf("Whilst walking %.2f km, you have likely burned %.2f calories (at selected intensity).\n", km, cals);
        }

        // --- Progress after each entry ---
        double overall = totalCaloriesFromSteps + totalDirectCalories + totalCaloriesFromDistance;
        double progress = (overall / dailyGoal) * 100.0;
        if (progress < 0) progress = 0; // just in case
        printf("Daily goal progress: %.2f%% of %.2f calories.\n", progress, dailyGoal);
        if (overall >= dailyGoal) {
            printf("Great job! You've reached or exceeded your daily goal.\n");
        }

        // Continue?
        char again;
        while (1) {
            printf("Do you want to add another entry? (y/n): ");
            if (scanf(" %c", &again) != 1) { printf("Invalid input.\n"); return 1; }
            if (again=='y'||again=='Y'||again=='n'||again=='N') break;
            printf("Please enter 'y' or 'n'.\n");
        }
        if (again=='n' || again=='N') {
            // --- Final summary ---
            double overall = totalCaloriesFromSteps + totalDirectCalories + totalCaloriesFromDistance;
            printf("\nYou have entered in total:\n");
            printf("%lld steps (%.2f calories)\n", totalSteps, totalCaloriesFromSteps);
            printf("%.2f calories (direct)\n", totalDirectCalories);
            printf("%.2f km of distance walked (%.2f calories)\n", totalDistanceKm, totalCaloriesFromDistance);
            printf("Overall calories burned: %.2f calories\n", overall);
            break;
        }
    }

    return 0;
}
