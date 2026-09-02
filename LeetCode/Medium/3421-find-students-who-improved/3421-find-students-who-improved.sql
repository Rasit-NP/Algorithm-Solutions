select s1.student_id, s1.subject, score1 as first_score, score2 as latest_score
from (
    select student_id, subject, min(exam_date) as first_date, max(exam_date) as latest_date
    from Scores
    group by student_id, subject
) s1
cross join (
    select a.student_id, a.subject, a.exam_date as day1, b.exam_date as day2, a.score as score1, b.score as score2
    from Scores a
    cross join Scores b
    on a.student_id = b.student_id and a.subject = b.subject and a.exam_date != b.exam_date and a.exam_date < b.exam_date
) s2
on s1.student_id = s2.student_id and s1.subject = s2.subject and s1.first_date = s2.day1 and s1.latest_date = s2.day2
where score1 < score2
order by student_id, subject
;