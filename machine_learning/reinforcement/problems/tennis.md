
two player game

state = your position, opponent position

how to learn weaker vs stronger position 

action select_next_action()
{
   select type of shot, velocity, angle of return 
     based on your position 
       - difficulty of interception, 
       - expertise level, 
       - speed of vertical, lateral, cross movement)
     based on opponent position
}

on_incoming_shot(angle)
{
   if shot cannot be intercepted from current position
     no action (fail)
   action = select_next_action()
   reward = env.step(action)
   reward is higher if next incoming shot is closer, if opponent has to move into weaker position
   q_value[state] = update
}
