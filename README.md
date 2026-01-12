# CPU Scheduling Algorithms Simulator in C

## 📌 Project Overview

This project is a **menu-driven CPU Scheduling Simulator** implemented in **C**, designed to demonstrate and compare fundamental **CPU scheduling algorithms** used in Operating Systems.

The simulator allows users to input process details and execute multiple scheduling strategies while computing key performance metrics such as:

- Waiting Time (WT)
- Turnaround Time (TAT)
- Completion Time (CT)
- Average Waiting Time
- Average Turnaround Time

This project is suitable for:
- Operating Systems laboratory
- GATE CS preparation
- Academic projects
- Resume and interview demonstrations

---

## ⚙️ Features

- Supports multiple scheduling algorithms  
- Handles arrival time, burst time, and priority  
- Computes process-wise and average performance metrics  
- Modular and well-structured C code  
- Menu-driven user interaction  

---

## 🧩 Implemented Scheduling Algorithms

- First Come First Serve (FCFS)
- Shortest Job First (SJF – Non-Preemptive)
- Priority Scheduling (Non-Preemptive)
- Round Robin (Preemptive)

---

## 🏗️ Program Structure

### Data Structure Used

```c
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




## 📥 Input Parameters

For each process, the following inputs are required:

- **Arrival Time (AT)** – Time at which the process enters the ready queue  
- **Burst Time (BT)** – Total CPU time required by the process  
- **Priority** – Lower value indicates higher priority  
- **Time Quantum** – Applicable only for Round Robin scheduling  

---


---

## 🔹 Algorithm Explanations

---

## 1️⃣ First Come First Serve (FCFS)

### Description
FCFS is the simplest CPU scheduling algorithm.  
Processes are executed strictly in the order of their arrival.

### Characteristics
- Non-preemptive  
- Simple to implement  
- Can cause convoy effect  
- Poor average waiting time for mixed workloads  

### Working Principle
- CPU is allocated to the process that arrives first  
- Execution continues until the process completes  

### Advantages
- Easy to implement  
- No starvation  

### Disadvantages
- High waiting time  
- Not suitable for time-sharing systems  

---

## 2️⃣ Shortest Job First (SJF) – Non-Preemptive

### Description
SJF selects the process with the smallest burst time among all available processes.

### Characteristics
- Non-preemptive  
- Optimal for minimizing average waiting time  
- Requires burst time prediction  

### Working Principle
- At each scheduling decision, the shortest available job is selected  
- Once selected, the process runs until completion  

### Advantages
- Minimum average waiting time  
- Efficient for batch systems  

### Disadvantages
- Starvation possible for long processes  
- Accurate burst time estimation required  

---

## 3️⃣ Priority Scheduling – Non-Preemptive

### Description
Each process is assigned a priority.  
The CPU is allocated to the process with the highest priority (lowest priority number).

### Characteristics
- Non-preemptive  
- Priority-based decision making  
- Can cause starvation  

### Working Principle
- Among arrived processes, select the one with highest priority  
- Execute the process until completion  

### Advantages
- Important tasks can be prioritized  
- Useful in real-time systems  

### Disadvantages
- Starvation of low-priority processes  
- Priority inversion problem (not handled)  

---

## 4️⃣ Round Robin (RR)

### Description
Round Robin is a preemptive CPU scheduling algorithm designed for time-sharing systems.

### Characteristics
- Preemptive  
- Uses time quantum  
- Ensures fair CPU allocation  

### Working Principle
- Each process is assigned a fixed time quantum  
- If the process does not complete, it is moved back to the ready queue  
- The cycle continues until all processes finish execution  

### Advantages
- No starvation  
- Suitable for interactive systems  

### Disadvantages
- Context switching overhead  
- Performance depends on the size of the time quantum  

