CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  RETURN (
      select if(count(salary) >= N && N>0, min(salary), null)
      from (
        select salary
        from Employee
        group by salary
        order by salary desc
        limit N
      ) s
  );
END
