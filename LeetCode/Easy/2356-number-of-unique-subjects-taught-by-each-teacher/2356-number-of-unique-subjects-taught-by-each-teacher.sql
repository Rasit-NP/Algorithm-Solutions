select teacher_id, count(t.subject_id) as cnt
from (
    select teacher_id, subject_id
    from Teacher
    group by teacher_id, subject_id
) as t
group by teacher_id
;