
# MPC vs Kalman filter

The MPC solver itself does not inherently contain a Kalman Filter. Instead, they are usually two separate components in a "control loop" that work together like a brain and its senses.

The Observer-MPC Architecture 

In a professional setup, we use what's called an Observer (most commonly a Kalman Filter) to "clean" the data before the MPC ever sees it.

The Kalman Filter (The Senses): It takes in noisy measurements ($y$) and the previous control action ($u$). It uses its own model to guess the "true" state, producing an estimated state $\hat{x}_k$.

The MPC (The Brain): It takes that clean estimate $\hat{x}_k$ as its starting point. It then runs the optimization to find the best future path.

# PID vs. MPC Comparison 



<img width="752" height="507" alt="Screenshot 2026-01-08 at 8 33 51 PM" src="https://github.com/user-attachments/assets/94132efc-75c3-4d45-b7db-8d8766d1fe3a" />
