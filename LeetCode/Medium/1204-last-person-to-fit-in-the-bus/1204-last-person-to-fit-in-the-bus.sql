select person_name
from (
    select *, sum(weight) over(order by turn) as total
    from Queue
) q
where total <= 1000
order by turn desc
limit 1
;