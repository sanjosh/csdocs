

PID vs. MPC Comparison 


\begin{table}[h]
\centering
\renewcommand{\arraystretch}{1.5}
\begin{tabular}{|p{3cm}|p{3cm}|p{8cm}|}
\hline
\textbf{PID Term} & \textbf{MPC Equivalent} & \textbf{How it works} \\ \hline
Proportional ($P$) & Cost Function Weight ($Q$) & This tells the MPC how "angry" to be about the current error. A high $Q$ value makes the controller react strongly to any gap between where you are and where you want to be. \\ \hline
Derivative ($D$) & Prediction Horizon ($N$) & While PID’s "$D$" term guesses the future based on the current slope, MPC actually simulates the future using its model. It’s like having a high-definition map instead of just guessing where the road turns. \\ \hline
Integral ($I$) & Disturbance Modeling & In MPC, we add a variable to the model representing an unknown force. When the model doesn't match reality, the MPC assumes there's a disturbance and corrects for it, eliminating steady-state error. \\ \hline
\end{tabular}
\caption{Conceptual mapping between PID and MPC.}
\end{table}

