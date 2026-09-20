select s1.id, if (s2.student is null, s1.student, s2.student) as student
from Seat s1
left join (
    select id, student
    from Seat
) s2
on ((s1.id&1) != (s2.id&1)) and (floor((s1.id+1)/2) = floor((s2.id+1)/2))
;