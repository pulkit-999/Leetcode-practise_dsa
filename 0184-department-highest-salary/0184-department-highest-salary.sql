# Write your MySQL query statement below
SELECT department.name as Department,employee.name as Employee,salary from Employee JOIN Department 
on Employee.departmentId=Department.id 
where (departmentId,salary) in (select departmentid,max(salary) as Salary from Employee group by departmentid) 