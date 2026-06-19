-- Write your PostgreSQL query statement below
select name as "Employee" from Employee as A
where salary > (select salary from Employee as B where id = A.managerId);