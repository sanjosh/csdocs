
# MPC vs Kalman filter

The MPC solver itself does not inherently contain a Kalman Filter. Instead, they are usually two separate components in a "control loop" that work together like a brain and its senses.

The Observer-MPC Architecture 

In a professional setup, we use what's called an Observer (most commonly a Kalman Filter) to "clean" the data before the MPC ever sees it.

The Kalman Filter (The Senses): It takes in noisy measurements ($y$) and the previous control action ($u$). It uses its own model to guess the "true" state, producing an estimated state $\hat{x}_k$.

The MPC (The Brain): It takes that clean estimate $\hat{x}_k$ as its starting point. It then runs the optimization to find the best future path.

# PID vs. MPC Comparison 



<img width="752" height="507" alt="Screenshot 2026-01-08 at 8 33 51 PM" src="https://github.com/user-attachments/assets/94132efc-75c3-4d45-b7db-8d8766d1fe3a" />


# car driving example


function decide_throttle_or_brake(
        distance_from_lane_center,
        current_speed,
        road_curvature):

    horizon_steps = 10
    time_step = 0.1   # seconds

    max_accelerate =  2.0    # m/s²
    max_brake      = -3.0    # m/s²

    lane_half_width = 1.75   # meters
    max_speed       = 30.0   # m/s

    smoothness_weight = 0.1  # how much we dislike jerky driving

    # What we will choose:
    throttle_or_brake[0 .. horizon_steps-1]

    predicted_lane_offset = distance_from_lane_center
    predicted_speed = current_speed

    total_badness = 0

    for t = 0 to horizon_steps-1:

        # Predict speed after throttle/brake
        predicted_speed += time_step * throttle_or_brake[t]

        # Predict how much we drift due to speed + curve
        predicted_lane_offset += (
            time_step * predicted_speed * road_curvature
        )

        # Penalize being far from lane center
        total_badness += predicted_lane_offset^2

        # Penalize harsh throttle or braking
        total_badness += smoothness_weight * throttle_or_brake[t]^2

        # Physical and safety limits
        enforce max_brake <= throttle_or_brake[t] <= max_accelerate
        enforce 0 <= predicted_speed <= max_speed
        enforce abs(predicted_lane_offset) <= lane_half_width

    # Find throttle/brake plan that minimizes total_badness
    best_throttle_plan = minimize(total_badness)

    return best_throttle_plan


while driving:

    lane_offset = measure_lane_position()
    speed = measure_vehicle_speed()
    curve = detect_road_curvature()

    pedal_plan = decide_throttle_or_brake(
                    lane_offset,
                    speed,
                    curve)

    apply_pedal(pedal_plan[0])   # only first action

    wait until next control cycle


# books

1. Rawlings & Mayne, Model Predictive Control: Theory and Design
2. Time-discretization of continuous delay systems
3. Stochastic approximation of speed variability

