select class
from (select class, count(class)
      from Courses
      group by class)
where count >= 5;