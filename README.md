CPU Scheduling Algorithms Simulator in C
📌 Project Overview

This project is a menu-driven CPU Scheduling Simulator implemented in C, designed to demonstrate and compare fundamental CPU scheduling algorithms used in Operating Systems.

The simulator allows users to input process details and execute multiple scheduling strategies while computing key performance metrics such as:

Waiting Time (WT)

Turnaround Time (TAT)

Completion Time (CT)

Average Waiting Time

Average Turnaround Time

This project is suitable for:

Operating Systems laboratory

GATE CS preparation

Academic projects

Resume and interview demonstrations

⚙️ Features

Supports multiple scheduling algorithms

Handles arrival time, burst time, and priority

Computes process-wise and average performance metrics

Modular and well-structured C code

Menu-driven user interaction

🧩 Implemented Scheduling Algorithms

First Come First Serve (FCFS)

Shortest Job First (SJF – Non-Preemptive)

Priority Scheduling (Non-Preemptive)

Round Robin (Preemptive)

🏗️ Program Structure
Data Structure Used
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


Each process stores all attributes required for scheduling and performance evaluation.

📥 Input Parameters

For each process:

Arrival Time (AT) – Time when the process enters the ready queue

Burst Time (BT) – CPU time required by the process

Priority – Lower value means higher priority

Time Quantum (only for Round Robin)

📊 Performance Metrics

Turnaround Time (TAT)

TAT = Completion Time − Arrival Time


Waiting Time (WT)

WT = Turnaround Time − Burst Time

🔹 Algorithm Explanations
1️⃣ First Come First Serve (FCFS)
Description

FCFS is the simplest CPU scheduling algorithm.
Processes are executed in the order of their arrival.

Characteristics

Non-preemptive

Simple to implement

Can cause convoy effect

Poor average waiting time for mixed workloads

Working Principle

CPU is allocated to the process that arrives first

Execution continues until completion

Advantages

Easy implementation

No starvation

Disadvantages

High waiting time

Not suitable for time-sharing systems

2️⃣ Shortest Job First (SJF) – Non-Preemptive
Description

SJF selects the process with the smallest burst time among the available processes.

Characteristics

Non-preemptive

Optimal for minimizing average waiting time

Requires burst time prediction

Working Principle

At every decision point, choose the shortest job that has arrived

Process runs to completion once selected

Advantages

Minimum average waiting time

Efficient for batch systems

Disadvantages

Starvation possible for long processes

Burst time estimation required

3️⃣ Priority Scheduling (Non-Preemptive)
Description

Each process is assigned a priority.
The CPU is allocated to the highest-priority process (lowest priority number).

Characteristics

Non-preemptive

Priority-based decision making

Can cause starvation

Working Principle

Among arrived processes, select the one with highest priority

Execute until completion

Advantages

Important tasks can be prioritized

Useful in real-time systems

Disadvantages

Starvation of low-priority processes

Priority inversion problem (not handled here)

4️⃣ Round Robin (RR)
Description

Round Robin is a preemptive scheduling algorithm designed for time-sharing systems.

Characteristics

Preemptive

Uses time quantum

Fair scheduling

Working Principle

Each process gets CPU for a fixed time quantum

If not completed, it goes back to the ready queue

Continues until all processes finish

Advantages

No starvation

Suitable for interactive systems

Disadvantages

Context switching overhead

Performance depends on time quantum size

🖥️ Sample Menu Output
CPU Scheduling Algorithms
1. FCFS
2. SJF (Non-Preemptive)
3. Priority Scheduling
4. Round Robin
5. Exit
Enter choice:

🧪 Example Output Table
PID   AT   BT   WT   TAT
P1    0    5    0    5
P2    1    3    4    7
P3    2    8    6    14

Average Waiting Time = 3.33
Average Turnaround Time = 8.67

🛠️ How to Compile and Run
gcc cpu_scheduling.c -o cpu_scheduling
./cpu_scheduling
