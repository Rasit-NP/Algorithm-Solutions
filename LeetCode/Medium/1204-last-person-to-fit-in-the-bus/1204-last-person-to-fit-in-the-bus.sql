select person_name
from Queue q1
where (
    select sum(weight)
    from Queue q2
    where q2.turn <= q1.turn
) <= 1000
order by turn desc
limit 1
;