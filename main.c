#include <stdio.h>

#define MAX 20

typedef struct {
    int pid;
    int arrival;
    int burst;
    int priority;
    int completion;
    int waiting;
    int turnaround;
    int remaining;
} Process;

Process p[MAX];
int n;

/* ================= UTILITY FUNCTIONS ================= */

void calculateTimes() {
    for (int i = 0; i < n; i++) {
        p[i].turnaround = p[i].completion - p[i].arrival;
        p[i].waiting = p[i].turnaround - p[i].burst;
    }
}

void printTable() {
    float avgWT = 0, avgTAT = 0;

    printf("\nPID\tAT\tBT\tWT\tTAT\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\n",
               p[i].pid, p[i].arrival, p[i].burst,
               p[i].waiting, p[i].turnaround);
        avgWT += p[i].waiting;
        avgTAT += p[i].turnaround;
    }

    printf("\nAverage Waiting Time = %.2f", avgWT / n);
    printf("\nAverage Turnaround Time = %.2f\n", avgTAT / n);
}

/* ================= INPUT ================= */

void inputProcesses() {
    printf("Enter number of processes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        p[i].pid = i + 1;
        printf("\nProcess P%d\n", p[i].pid);
        printf("Arrival Time: ");
        scanf("%d", &p[i].arrival);
        printf("Burst Time: ");
        scanf("%d", &p[i].burst);
        printf("Priority (lower number = higher priority): ");
        scanf("%d", &p[i].priority);
        p[i].remaining = p[i].burst;
    }
}

/* ================= FCFS ================= */

void fcfs() {
    int time = 0;

    for (int i = 0; i < n; i++) {
        if (time < p[i].arrival)
            time = p[i].arrival;
        time += p[i].burst;
        p[i].completion = time;
    }

    calculateTimes();
    printTable();
}

/* ================= SJF (NON-PREEMPTIVE) ================= */

void sjf() {
    int completed = 0, time = 0;
    int visited[MAX] = {0};

    while (completed < n) {
        int idx = -1, minBurst = 9999;

        for (int i = 0; i < n; i++) {
            if (!visited[i] && p[i].arrival <= time &&
                p[i].burst < minBurst) {
                minBurst = p[i].burst;
                idx = i;
            }
        }

        if (idx == -1) {
            time++;
            continue;
        }

        time += p[idx].burst;
        p[idx].completion = time;
        visited[idx] = 1;
        completed++;
    }

    calculateTimes();
    printTable();
}

/* ================= PRIORITY (NON-PREEMPTIVE) ================= */

void priorityScheduling() {
    int completed = 0, time = 0;
    int visited[MAX] = {0};

    while (completed < n) {
        int idx = -1, bestPriority = 9999;

        for (int i = 0; i < n; i++) {
            if (!visited[i] && p[i].arrival <= time &&
                p[i].priority < bestPriority) {
                bestPriority = p[i].priority;
                idx = i;
            }
        }

        if (idx == -1) {
            time++;
            continue;
        }

        time += p[idx].burst;
        p[idx].completion = time;
        visited[idx] = 1;
        completed++;
    }

    calculateTimes();
    printTable();
}

/* ================= ROUND ROBIN ================= */

void roundRobin() {
    int tq, time = 0, completed = 0;
    printf("Enter Time Quantum: ");
    scanf("%d", &tq);

    while (completed < n) {
        int executed = 0;

        for (int i = 0; i < n; i++) {
            if (p[i].remaining > 0 && p[i].arrival <= time) {
                executed = 1;

                if (p[i].remaining > tq) {
                    time += tq;
                    p[i].remaining -= tq;
                } else {
                    time += p[i].remaining;
                    p[i].remaining = 0;
                    p[i].completion = time;
                    completed++;
                }
            }
        }

        if (!executed)
            time++;
    }

    calculateTimes();
    printTable();
}

/* ================= MAIN ================= */

int main() {
    int choice;

    inputProcesses();

    while (1) {
        printf("\n\nCPU Scheduling Algorithms");
        printf("\n1. FCFS");
        printf("\n2. SJF (Non-Preemptive)");
        printf("\n3. Priority Scheduling");
        printf("\n4. Round Robin");
        printf("\n5. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: fcfs(); break;
            case 2: sjf(); break;
            case 3: priorityScheduling(); break;
            case 4: roundRobin(); break;
            case 5: return 0;
            default: printf("Invalid choice!\n");
        }
    }
}
