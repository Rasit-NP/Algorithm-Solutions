(select name as results
from Users
left join (
    select user_id, count(rating) as cnt
    from MovieRating
    group by user_id
) mr
on Users.user_id = mr.user_id
order by mr.cnt desc, name
limit 1)

union all

(select title as results
from Movies
inner join (
    select movie_id, avg(rating) as average
    from (
        select * from MovieRating
        where created_at >= '2020-02-01' and created_at < '2020-03-01'
    ) inn
    group by movie_id
) mr
on Movies.movie_id = mr.movie_id
order by mr.average desc, title
limit 1)
;