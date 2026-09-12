select count(cnt) as 'count'
from (
    select name, count(name) as cnt
    from animal_ins
    group by name
    having name is not null
) t
;