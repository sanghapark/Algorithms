Greedy Choice
  * Refill at the closest gas station
  * Refill at the farthest reachable gas station
  * Go until there is no feul


  * Start at A
  * Refill at the farthest reachable gas station G
  * Make G the new A
  * Get from new A to B with minimum number of refills

Subproblem is a similar problem of smaller size.
ex) LargestNumber(3,9,5,9,7,1) =
  "9" + LargestNumber(3,5,9,7,1)

ex) Min number of refills from A to B = 
  first refill at G + min number of refills from G to B

Safe Move
  A greedy choice is called "safe move" if there is an optimal solution consistent with this first move.

Lemma 
  To refill at the farthest reschable gas station is a safe move.
