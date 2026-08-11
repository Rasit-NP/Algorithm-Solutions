select t.name as 'Department', Employee.name as 'Employee', salary as 'Salary'
from Employee
left join (
    select d.id, d.name, max(salary) as 'max'
    from Department d
    left join Employee e
    on d.id = e.departmentId
    group by d.id
) t
on t.id = departmentId
where salary = t.max;