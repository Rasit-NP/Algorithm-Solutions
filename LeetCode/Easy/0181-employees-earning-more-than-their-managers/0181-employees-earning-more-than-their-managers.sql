-- Write your PostgreSQL query statement below
select E1.name "Employee"
from Employee E1
Join Employee E2 on E1.managerId = E2.id
where E1.salary > E2.salary;