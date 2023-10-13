# Write your MySQL query statement below
SELECT name FROM Employee WHERE id in(
  SELECT managerId from Employee
  GROUP BY managerId HAVING COUNT(id)>=5
)