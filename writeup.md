# PID Control Project #

This writeup adresses the two points of the project rubrics "Reflection".

## Effects of each of P,I,D component

- Effect of P component: Steering is **proportional** to the error CTE. The further the car is away from the middle of the lane, the harder it steers back. With increasing the factor `Kp` the car is oscillating strongly around middle of the lane.

- Effect of I component: Steering is proportional to the **integral** of the error CTE over time. If not reaching the middle of the lane for a longer time, the steering command back to the middle will increase. To not introduce unwanted oscillating around the middle of the lane, the factor `Ki` is relatively small compared to the other two components.

- Effect of D component: Steering is proportional to the **derivative** of the error CTE. If the error is reduced strongly, the D component takes care to not drastically overshoot the middle of the lane. In other words it damps the motion to the middle or oscillating around the middle of the lane.

## Process generating final hyperparameters

My final result for the three hyperparameters is:

`Kd = 0.2`
`Ki = 0.001`
`Kp = 4.0`

I have chosen it by the following procedure:

* Set all parameters to 0.0
* Start increasing `Kp`, so that the car is reasonably able to turn
* Increase `Kd` to damp overshooting
* Find ratio, that is working acceptable
* Increase `Kp` together with `Kp` so that sharp turns are handled well
* Start with very low `Ki` and increase
* Increase `Kd` a little further to compensate overshooting introducec by `Ki`
